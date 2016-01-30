//==============================================================================
// Name        : Image.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/01/2016)
// Description : Source file of the Image class
//==============================================================================

#include "Image.h"
#include <cmath>
#include <QColor>

Image::Image()
{
    this->clear();
}

Image::Image(const QImage& imageSource, const QImage& imageConvertie) :
        Image()
{
    this->initialize(imageSource, imageConvertie);
}

Image::Image(const Image& image) :
        Image()
{
    this->copy(image);
}

Image::~Image()
{
}

const QImage& Image::getImageSource() const
{
    return this->imageSource;
}

const QImage& Image::getImageConvertie() const
{
    return this->imageConvertie;
}

void Image::setImageSource(const QImage& imageSource)
{
    this->imageSource = imageSource;
}

void Image::setImageConvertie(const QImage& imageConvertie)
{
    this->imageConvertie = imageConvertie;
}

void Image::clear()
{
    this->initialize(QImage(), QImage());
}

void Image::initialize(const QImage& imageSource, const QImage& imageConvertie)
{
    this->setImageSource(imageSource);
    this->setImageConvertie(imageConvertie);
}

void Image::copy(const Image& image)
{
    this->initialize(image.getImageSource(), image.getImageConvertie());
}

bool Image::equals(const Image& image) const
{
    if (this->getImageSource() != image.getImageSource())
        return false;
    if (this->getImageConvertie() != image.getImageConvertie())
        return false;
    return true;
}

void Image::fromString(const QString& fromString, const char& sep)
{
    // TODO void Image::fromString(const QString& fromString, const char& sep)
}

const QString Image::toString(const char& sep) const
{
    // TODO const QString Image::toString(const char& sep) const
    return QString();
}

void Image::restaurerImage()
{
    this->setImageConvertie(this->getImageSource());
}

void Image::convertirImage(const int& typeConversion, const int& seuilNoirEtBlanc,
        const int& nombreNiveauxDeGris, const int& nombreTeintesSaturees)
{
    this->restaurerImage();
    QImage imageConvertie = this->getImageConvertie();
    const int largeurImage = imageConvertie.width();
    const int hauteurImage = imageConvertie.height();
    const double pasNiveauxDeGris = this->getPasNiveauxDeGris(nombreNiveauxDeGris);
    const double pasTeintesSaturees = this->getPasTeintesSaturees(nombreTeintesSaturees);
    const QList<QRgb> listeNiveauxDeGris = this->getListeNiveauxDeGris(nombreNiveauxDeGris);
    const QList<QRgb> listeTeintesSaturees = this->getListeTeintesSaturees(nombreTeintesSaturees);
    for (int x = 0; x < largeurImage; x++)
    {
        for (int y = 0; y < hauteurImage; y++)
        {
            QRgb couleurConvertie = imageConvertie.pixel(x, y);
            if (typeConversion == NOIR_ET_BLANC)
            {
                couleurConvertie =
                        (qGray(couleurConvertie) <= seuilNoirEtBlanc) ? Qt::black : Qt::white;
            }
            else if (typeConversion == NIVEAUX_DE_GRIS)
            {
                // TODO Conversion en niveaux de gris (gestion des autres cas)
                couleurConvertie = listeNiveauxDeGris.at(
                        (int) round((double) qGray(couleurConvertie) / pasNiveauxDeGris));
            }
            else if (typeConversion == TEINTES_SATUREES)
            {
                // TODO Conversion en teintes saturées (gestion des autres cas)
                couleurConvertie = listeTeintesSaturees.at(
                        (int) round((double) QColor(couleurConvertie).hue() / pasTeintesSaturees));
            }
            imageConvertie.setPixel(x, y, couleurConvertie);
        }
    }
    this->setImageConvertie(imageConvertie);
}

double Image::getPasNiveauxDeGris(const int& nombreNiveauxDeGris)
{
    return 256.0 / (double) (nombreNiveauxDeGris - 1);
}

double Image::getPasTeintesSaturees(const int& nombreTeintesSaturees)
{
    return 360.0 / (double) nombreTeintesSaturees;
}

QList<QRgb> Image::getListeNiveauxDeGris(const int& nombreNiveauxDeGris)
{
    QList<QRgb> listeNiveauxDeGris;
    const double pasNiveauxDeGris = this->getPasNiveauxDeGris(nombreNiveauxDeGris);
    for (int itNiveauDeGris = 0; itNiveauDeGris < nombreNiveauxDeGris; itNiveauDeGris++)
    {
        const int valeurGris = (int) round((double) itNiveauDeGris * pasNiveauxDeGris);
        QRgb niveauDeGris = QColor::fromRgb(valeurGris, valeurGris, valeurGris).rgb();
        listeNiveauxDeGris.append(niveauDeGris);
    }
    return listeNiveauxDeGris;
}

QList<QRgb> Image::getListeTeintesSaturees(const int& nombreTeintesSaturees)
{
    QList<QRgb> listeTeintesSaturees;
    const double pasTeintesSaturees = this->getPasTeintesSaturees(nombreTeintesSaturees);
    for (int itTeinteSaturee = 0; itTeinteSaturee < nombreTeintesSaturees; itTeinteSaturee++)
    {
        const int valeurTeinte = (int) round((double) itTeinteSaturee * pasTeintesSaturees);
        QRgb teinteSaturee = QColor::fromHsv(valeurTeinte, 255, 255).rgb();
        listeTeintesSaturees.append(teinteSaturee);
    }
    return listeTeintesSaturees;
}
