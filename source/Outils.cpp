//==============================================================================
// Name        : Outils.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (27/04/2016)
// Description : Source file of the Outils elements
//==============================================================================

#include "Outils.h"
#include "Image.h"
#include <cmath>
#include <QColor>
#include <QImage>

QStringList listeSousElements(const QString& chaineElements, const char& sep)
{
    QStringList listeSousElements;
    QString elementCourant;
    int compteurParentheses = 0;
    const int nombreChaineElements = chaineElements.count();
    for (int itChaineElements = 0; itChaineElements < nombreChaineElements; itChaineElements++)
    {
        QChar caractereCourant = chaineElements.at(itChaineElements);
        if (caractereCourant == '(')
        {
            compteurParentheses++;
        }
        else if (caractereCourant == ')')
        {
            compteurParentheses--;
        }
        if (caractereCourant == sep && compteurParentheses == 0)
        {
            listeSousElements.append(elementCourant);
            elementCourant.clear();
        }
        else if (!(caractereCourant == '(' && compteurParentheses == 1)
                && !(caractereCourant == ')' && compteurParentheses == 0))
        {
            elementCourant += caractereCourant;
        }
    }
    listeSousElements.append(elementCourant);
    return listeSousElements;
}

void interpolationNumerique(const double& x1, const double& y1, const double& x2, const double& y2,
        const double& x, double& y)
{
    const double pente = (y2 - y1) / (x2 - x1);
    y = pente * (x - x1) + y1;
}

void interpolationNumerique(const Point& point1, const Point& point2, Point& point)
{
    const double p1px = (double) point1.getPointPixelX();
    const double p1py = (double) point1.getPointPixelY();
    const double p2px = (double) point2.getPointPixelX();
    const double p2py = (double) point2.getPointPixelY();
    const double p1rx = point1.getPointReelX();
    const double p1ry = point1.getPointReelY();
    const double p2rx = point2.getPointReelX();
    const double p2ry = point2.getPointReelY();

    const double ppx = (double) point.getPointPixelX();
    const double prx = point.getPointReelX();
    double ppy = 0.0;
    double pry = 0.0;
    interpolationNumerique(p1px, p1py, p2px, p2py, ppx, ppy);
    interpolationNumerique(p1rx, p1ry, p2rx, p2ry, prx, pry);
    point.setPointPixelY((int) round(ppy));
    point.setPointReelY(pry);
}

QList<Point> interpolationNumerique(const QList<Point>& listeDePoints,
        const double& seuilInterpolationNumerique)
{
    // TODO QList<Point> interpolationNumerique(const QList<Point>& listeDePoints, const double& seuilInterpolationNumerique)
    Q_UNUSED(listeDePoints);
    Q_UNUSED(seuilInterpolationNumerique);
    return QList<Point>();
}

void genererImageTest()
{
    // Définition de l'image de test
    QImage imageTest(640, 480, QImage::Format_RGB32);
    const int largeurSpectre = 600;
    const int hauteurSpectre = 50;
    const int hauteurSpectreTeinte = 230;

    // Fond blanc
    QColor couleurBlanc = Qt::white;
    for (int x = 0; x < imageTest.width(); x++)
    {
        for (int y = 0; y < imageTest.height(); y++)
        {
            imageTest.setPixel(x, y, couleurBlanc.rgb());
        }
    }

    // Spectre de gris
    QColor couleurGris = Qt::black;
    for (int x = 0; x < largeurSpectre; x++)
    {
        for (int y = 0; y < hauteurSpectre; y++)
        {
            int valeurGris = (int) round(x * (256.0 / largeurSpectre));
            valeurGris = (valeurGris < 0) ? 0 : (valeurGris > 255) ? 255 : valeurGris;
            couleurGris.setRgb(valeurGris, valeurGris, valeurGris);
            imageTest.setPixel(x + 20, y + 20, couleurGris.rgb());
        }
    }

    // Spectre de saturation
    QColor couleurSaturation = Qt::red;
    for (int x = 0; x < largeurSpectre; x++)
    {
        for (int y = 0; y < hauteurSpectre; y++)
        {
            int valeurSaturation = (int) round(x * (256.0 / largeurSpectre));
            valeurSaturation = (valeurSaturation < 0) ? 0 :
                               (valeurSaturation > 255) ? 255 : valeurSaturation;
            couleurSaturation = QColor::fromHsv(couleurSaturation.hue(), valeurSaturation, 255);
            imageTest.setPixel(x + 20, y + 90, couleurSaturation.rgb());
        }
    }

    // Spectre de brillance
    QColor couleurBrillance = Qt::red;
    for (int x = 0; x < largeurSpectre; x++)
    {
        for (int y = 0; y < hauteurSpectre; y++)
        {
            int valeurBrillance = (int) round(x * (256.0 / largeurSpectre));
            valeurBrillance = (valeurBrillance < 0) ? 0 :
                              (valeurBrillance > 255) ? 255 : valeurBrillance;
            couleurBrillance = QColor::fromHsv(couleurBrillance.hue(), 255, valeurBrillance);
            imageTest.setPixel(x + 20, y + 160, couleurBrillance.rgb());
        }
    }

    // Spectre de teinte
    QColor couleurTeinte = Qt::black;
    for (int x = 0; x < largeurSpectre; x++)
    {
        for (int y = 0; y < hauteurSpectreTeinte; y++)
        {
            int valeurTeinte = (int) round(x * (360.0 / largeurSpectre)) % 360;
            couleurTeinte = QColor::fromHsv(valeurTeinte, 255, 255);
            imageTest.setPixel(x + 20, y + 230, couleurTeinte.rgb());
        }
    }

    imageTest.save("ImageTest.png");
}

void testerConversionNoirEtBlanc(const int& seuilNoirEtBlanc)
{
    genererImageTest();
    Image imageTest(QImage("ImageTest.png"), QImage());
    imageTest.convertirImageNoirEtBlanc(seuilNoirEtBlanc);
    imageTest.getImageConvertie().save("ImageTestConversionNoirEtBlanc.png");
}

void testerConversionNiveauxDeGris(const int& nombreNiveauxDeGris)
{
    genererImageTest();
    Image imageTest(QImage("ImageTest.png"), QImage());
    imageTest.convertirImageNiveauxDeGris(nombreNiveauxDeGris);
    imageTest.getImageConvertie().save("ImageTestConversionNiveauxDeGris.png");
}

void testerConversionTeintesSaturees(const int& nombreNiveauxDeGris,
        const int& nombreTeintesSaturees, const int& seuilSaturation)
{
    genererImageTest();
    Image imageTest(QImage("ImageTest.png"), QImage());
    imageTest.convertirImageTeintesSaturees(nombreNiveauxDeGris, nombreTeintesSaturees,
            seuilSaturation);
    imageTest.getImageConvertie().save("ImageTestConversionTeintesSaturees.png");
}
