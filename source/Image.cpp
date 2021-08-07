//==============================================================================
// Name        : Image.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.3.0 (07/08/2021)
// Description : Source file of the Image class
//==============================================================================

#include "Image.h"
#include "ParametresConversion.h"
#include <cmath>
#include <QByteArray>
#include <QColor>

Image::Image(const QImage& imageSource, const QImage& imageConvertie) :
        _imageSource(imageSource), _imageConvertie(imageConvertie)
{
}

const QImage& Image::getImageSource() const
{
    return _imageSource;
}

const QImage& Image::getImageConvertie() const
{
    return _imageConvertie;
}

void Image::setImageSource(const QImage& imageSource)
{
    _imageSource = imageSource;
}

void Image::setImageConvertie(const QImage& imageConvertie)
{
    _imageConvertie = imageConvertie;
}

void Image::clear()
{
    *this = Image();
}

void Image::set(const QImage& imageSource, const QImage& imageConvertie)
{
    setImageSource(imageSource);
    setImageConvertie(imageConvertie);
}

void Image::fromString(const QString& fromString, const QChar& sep)
{
    // TODO void Image::fromString(const QString& fromString, const QChar& sep)
    Q_UNUSED(fromString)
    Q_UNUSED(sep)
}

const QString Image::toString(const QChar& sep) const
{
    QString toString;
    const QImage& imageSource = getImageSource();
    const QImage& imageConvertie = getImageConvertie();
    const QByteArray donneesImageSource = QByteArray(
            reinterpret_cast<const char*>(imageSource.bits()),
            static_cast<int>(imageSource.sizeInBytes()));
    const QByteArray donneesImageConvertie = QByteArray(
            reinterpret_cast<const char*>(imageConvertie.bits()),
            static_cast<int>(imageConvertie.sizeInBytes()));
    toString += QString("(%1)").arg(QString(donneesImageSource)) + sep;
    toString += QString("(%1)").arg(QString(donneesImageConvertie));
    return toString;
}

void Image::restaurerImage()
{
    setImageConvertie(getImageSource());
}

void Image::convertirImageNoirEtBlanc(const int& seuilNoirEtBlanc)
{
    convertirImage(ParametresConversion::NOIR_ET_BLANC, seuilNoirEtBlanc,
            ParametresConversion::nombreNiveauxDeGrisDefaut,
            ParametresConversion::nombreTeintesSatureesDefaut,
            ParametresConversion::seuilSaturationDefaut);
}

void Image::convertirImageNiveauxDeGris(const int& nombreNiveauxDeGris)
{
    convertirImage(ParametresConversion::NIVEAUX_DE_GRIS,
            ParametresConversion::seuilNoirEtBlancDefaut, nombreNiveauxDeGris,
            ParametresConversion::nombreTeintesSatureesDefaut,
            ParametresConversion::seuilSaturationDefaut);
}

void Image::convertirImageTeintesSaturees(const int& nombreNiveauxDeGris,
        const int& nombreTeintesSaturees, const int& seuilSaturation)
{
    convertirImage(ParametresConversion::TEINTES_SATUREES,
            ParametresConversion::seuilNoirEtBlancDefaut, nombreNiveauxDeGris,
            nombreTeintesSaturees, seuilSaturation);
}

bool Image::verifierPresencePixel(const QPoint& pointPixel) const
{
    const QImage& imageConvertie = getImageConvertie();
    const int largeurImage = imageConvertie.width();
    const int hauteurImage = imageConvertie.height();
    const int x = pointPixel.x();
    const int y = pointPixel.y();
    return (x >= 0 && x < largeurImage && y >= 0 && y < hauteurImage);
}

QRgb Image::recupererCouleurPixel(const QPoint& pointPixel) const
{
    const QImage& imageConvertie = getImageConvertie();
    const int x = pointPixel.x();
    const int y = pointPixel.y();
    return imageConvertie.pixel(x, y);
}

void Image::convertirImage(const int& methodeConversion, const int& seuilNoirEtBlanc,
        const int& nombreNiveauxDeGris, const int& nombreTeintesSaturees,
        const int& seuilSaturation)
{
    restaurerImage();
    QImage imageConvertie = getImageConvertie();
    const int largeurImage = imageConvertie.width();
    const int hauteurImage = imageConvertie.height();
    const double pasNiveauxDeGris = getPasNiveauxDeGris(nombreNiveauxDeGris);
    const double pasTeintesSaturees = getPasTeintesSaturees(nombreTeintesSaturees);
    const QList<QRgb> listeNiveauxDeGris = getListeNiveauxDeGris(nombreNiveauxDeGris);
    const QList<QRgb> listeTeintesSaturees = getListeTeintesSaturees(nombreTeintesSaturees);
    for (int x = 0; x < largeurImage; x++)
    {
        for (int y = 0; y < hauteurImage; y++)
        {
            QRgb couleurConvertie = imageConvertie.pixel(x, y);
            if (methodeConversion == ParametresConversion::NOIR_ET_BLANC)
            {
                couleurConvertie =
                        (qGray(couleurConvertie) <= seuilNoirEtBlanc) ?
                                QColor(Qt::black).rgb() : QColor(Qt::white).rgb();
            }
            else if (methodeConversion == ParametresConversion::NIVEAUX_DE_GRIS)
            {
                couleurConvertie = listeNiveauxDeGris.at(
                        static_cast<int>(round(qGray(couleurConvertie) / pasNiveauxDeGris)));
            }
            else if (methodeConversion == ParametresConversion::TEINTES_SATUREES)
            {
                const int teinteCouleurConvertie = QColor(couleurConvertie).hue();
                const int saturationCouleurConvertie = QColor(couleurConvertie).saturation();
                if (teinteCouleurConvertie == -1 || saturationCouleurConvertie <= seuilSaturation)
                {
                    couleurConvertie = listeNiveauxDeGris.at(
                            static_cast<int>(round(qGray(couleurConvertie) / pasNiveauxDeGris)));
                }
                else
                {
                    couleurConvertie = listeTeintesSaturees.at(
                            static_cast<int>(round(teinteCouleurConvertie / pasTeintesSaturees))
                                    % nombreTeintesSaturees);
                }
            }
            imageConvertie.setPixel(x, y, couleurConvertie);
        }
    }
    setImageConvertie(imageConvertie);
}

double Image::getPasNiveauxDeGris(const int& nombreNiveauxDeGris) const
{
    return 255.0 / (nombreNiveauxDeGris - 1);
}

double Image::getPasTeintesSaturees(const int& nombreTeintesSaturees) const
{
    return 360.0 / nombreTeintesSaturees;
}

const QList<QRgb> Image::getListeNiveauxDeGris(const int& nombreNiveauxDeGris) const
{
    QList<QRgb> listeNiveauxDeGris;
    const double pasNiveauxDeGris = getPasNiveauxDeGris(nombreNiveauxDeGris);
    for (int itNiveauDeGris = 0; itNiveauDeGris < nombreNiveauxDeGris; itNiveauDeGris++)
    {
        const int valeurGris = static_cast<int>(round(itNiveauDeGris * pasNiveauxDeGris));
        const QRgb niveauDeGris = QColor::fromRgb(valeurGris, valeurGris, valeurGris).rgb();
        listeNiveauxDeGris.append(niveauDeGris);
    }
    return listeNiveauxDeGris;
}

const QList<QRgb> Image::getListeTeintesSaturees(const int& nombreTeintesSaturees) const
{
    QList<QRgb> listeTeintesSaturees;
    const double pasTeintesSaturees = getPasTeintesSaturees(nombreTeintesSaturees);
    for (int itTeinteSaturee = 0; itTeinteSaturee < nombreTeintesSaturees; itTeinteSaturee++)
    {
        const int valeurTeinte = static_cast<int>(round(itTeinteSaturee * pasTeintesSaturees));
        const QRgb teinteSaturee = QColor::fromHsv(valeurTeinte, 255, 255).rgb();
        listeTeintesSaturees.append(teinteSaturee);
    }
    return listeTeintesSaturees;
}
