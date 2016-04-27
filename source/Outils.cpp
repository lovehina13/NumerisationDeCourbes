//==============================================================================
// Name        : Outils.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (27/04/2016)
// Description : Source file of the Outils elements
//==============================================================================

#include "Outils.h"
#include <QColor>
#include <QImage>

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
