//==============================================================================
// Name        : VueGraphiqueEtude.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (29/07/2016)
// Description : Source file of the VueGraphiqueEtude class
//==============================================================================

#include "VueGraphiqueEtude.h"
#include <QBrush>
#include <QColor>
#include <QGraphicsPixmapItem>
#include <QPen>
#include <QPixmap>
#include <QRgb>

VueGraphiqueEtude::VueGraphiqueEtude(QWidget* parent) :
        QGraphicsView(parent)
{
    QGraphicsScene* graphicsScene = new QGraphicsScene(parent);
    this->setScene(graphicsScene);
    this->setMouseTracking(true);
}

VueGraphiqueEtude::VueGraphiqueEtude(QGraphicsScene* scene, QWidget* parent) :
        QGraphicsView(scene, parent)
{
}

VueGraphiqueEtude::~VueGraphiqueEtude()
{
}

void VueGraphiqueEtude::effacer()
{
    this->scene()->clear();
}

void VueGraphiqueEtude::dessiner(const Etude& etude)
{
    const Image& image = etude.getImage();
    const Repere& repere = etude.getRepere();
    const QList<Point>& listeDePoints = etude.getListeDePoints();
    const ParametresTrait& parametresAxes =
            etude.getParametres().getParametresAffichage().getParametresAxes();
    const ParametresTrait& parametresCourbes =
            etude.getParametres().getParametresAffichage().getParametresCourbes();
    const ParametresPoint& parametresPointsAxes =
            etude.getParametres().getParametresAffichage().getParametresPointsAxes();
    const ParametresPoint& parametresPointsCourbes =
            etude.getParametres().getParametresAffichage().getParametresPointsManuels();
    const ParametresPoint& parametresPointsManuels =
            etude.getParametres().getParametresAffichage().getParametresPointsManuels();

    this->effacer();
    this->dessinerImage(image);
    this->dessinerRepere(repere, parametresAxes, parametresPointsAxes);
    // TODO Utilisation de this->dessinerCourbes()
    // TODO Utilisation de this->dessinerPointManuel()
    Q_UNUSED(listeDePoints);
    Q_UNUSED(parametresCourbes);
    Q_UNUSED(parametresPointsCourbes);
    Q_UNUSED(parametresPointsManuels);
}

void VueGraphiqueEtude::dessinerImage(const Image& image)
{
    QGraphicsPixmapItem* itemImage = new QGraphicsPixmapItem(
            QPixmap::fromImage(image.getImageConvertie()));
    this->scene()->addItem(itemImage);
}

void VueGraphiqueEtude::dessinerRepere(const Repere& repere, const ParametresTrait& parametresAxes,
        const ParametresPoint& parametresPointsAxes)
{
    const Point& pointX0 = repere.getPointX0();
    const Point& pointX1 = repere.getPointX1();
    const Point& pointY0 = repere.getPointY0();
    const Point& pointY1 = repere.getPointY1();

    this->dessinerTrait(pointX0, pointX1, parametresAxes);
    this->dessinerTrait(pointY0, pointY1, parametresAxes);
    this->dessinerPoint(pointX0, parametresPointsAxes);
    this->dessinerPoint(pointX1, parametresPointsAxes);
    this->dessinerPoint(pointY0, parametresPointsAxes);
    this->dessinerPoint(pointY1, parametresPointsAxes);
}

void VueGraphiqueEtude::dessinerCourbe(const QList<Point> pointsCourbe,
        const ParametresTrait& parametresCourbes, const ParametresPoint& parametresPointsCourbes)
{
    // TODO void VueGraphiqueEtude::dessinerCourbe(const QList<Point> pointsCourbe, const ParametresTrait& parametresCourbes, const ParametresPoint& parametresPointsCourbes)
    Q_UNUSED(pointsCourbe);
    Q_UNUSED(parametresCourbes);
    Q_UNUSED(parametresPointsCourbes);
}

void VueGraphiqueEtude::dessinerPointManuel(const Point& pointManuel,
        const ParametresPoint& parametresPointsManuels)
{
    this->dessinerPoint(pointManuel, parametresPointsManuels);
}

void VueGraphiqueEtude::dessinerPoint(const Point& point, const ParametresPoint& parametresPoint)
{
    const int& stylePoint = parametresPoint.getStylePoint();
    const int& epaisseurPoint = parametresPoint.getEpaisseurPoint();
    const QRgb& couleurPoint = parametresPoint.getCouleurPoint();
    QBrush brossePoint = QBrush(QColor(couleurPoint), Qt::SolidPattern);
    QPen pinceauPoint = QPen(brossePoint, 0, Qt::SolidLine);

    const double ppx = (double) point.getPointPixelX();
    const double ppy = (double) point.getPointPixelY();
    const double ppx_edit = ppx - ((double) epaisseurPoint / 2.0);
    const double ppy_edit = ppy - ((double) epaisseurPoint / 2.0);

    if (stylePoint == ParametresPoint::CARRE)
    {
        this->scene()->addRect(ppx_edit, ppy_edit, epaisseurPoint, epaisseurPoint, pinceauPoint,
                brossePoint);
    }
    else if (stylePoint == ParametresPoint::CERCLE)
    {
        this->scene()->addEllipse(ppx_edit, ppy_edit, epaisseurPoint, epaisseurPoint, pinceauPoint,
                brossePoint);
    }
}

void VueGraphiqueEtude::dessinerTrait(const Point& point1, const Point& point2,
        const ParametresTrait& parametresTrait)
{
    const int& styleTrait = parametresTrait.getStyleTrait();
    const int& epaisseurTrait = parametresTrait.getEpaisseurTrait();
    const QRgb& couleurTrait = parametresTrait.getCouleurTrait();
    QBrush brosseTrait = QBrush(QColor(couleurTrait), Qt::SolidPattern);
    QPen pinceauTrait = QPen(brosseTrait, epaisseurTrait, (Qt::PenStyle) (styleTrait + 1));

    const double p1px = (double) point1.getPointPixelX();
    const double p1py = (double) point1.getPointPixelY();
    const double p2px = (double) point2.getPointPixelX();
    const double p2py = (double) point2.getPointPixelY();

    this->scene()->addLine(p1px, p1py, p2px, p2py, pinceauTrait);
}

void VueGraphiqueEtude::mouseMoveEvent(QMouseEvent* event)
{
    // TODO void VueGraphiqueEtude::mouseMoveEvent(QMouseEvent* event)
    Q_UNUSED(event);
}

void VueGraphiqueEtude::wheelEvent(QWheelEvent* event)
{
    // TODO void VueGraphiqueEtude::wheelEvent(QWheelEvent* event)
    Q_UNUSED(event);
}
