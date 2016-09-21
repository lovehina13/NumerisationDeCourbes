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
    // TODO Utilisation de this->dessinerPoint()
    // TODO Utilisation de this->dessinerCourbes()
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
    const double x0px = (double) repere.getPointX0().getPointPixelX();
    const double x0py = (double) repere.getPointX0().getPointPixelY();
    const double x1px = (double) repere.getPointX1().getPointPixelX();
    const double x1py = (double) repere.getPointX1().getPointPixelY();
    const double y0px = (double) repere.getPointY0().getPointPixelX();
    const double y0py = (double) repere.getPointY0().getPointPixelY();
    const double y1px = (double) repere.getPointY1().getPointPixelX();
    const double y1py = (double) repere.getPointY1().getPointPixelY();

    const int& styleAxes = parametresAxes.getStyleTrait();
    const int& epaisseurAxes = parametresAxes.getEpaisseurTrait();
    const QRgb& couleurAxes = parametresAxes.getCouleurTrait();
    const int& stylePointsAxes = parametresPointsAxes.getStylePoint();
    const int& epaisseurPointsAxes = parametresPointsAxes.getEpaisseurPoint();
    const QRgb& couleurPointsAxes = parametresPointsAxes.getCouleurPoint();

    const double x0px_edit = x0px - ((double) epaisseurPointsAxes / 2.0);
    const double x0py_edit = x0py - ((double) epaisseurPointsAxes / 2.0);
    const double x1px_edit = x1px - ((double) epaisseurPointsAxes / 2.0);
    const double x1py_edit = x1py - ((double) epaisseurPointsAxes / 2.0);
    const double y0px_edit = y0px - ((double) epaisseurPointsAxes / 2.0);
    const double y0py_edit = y0py - ((double) epaisseurPointsAxes / 2.0);
    const double y1px_edit = y1px - ((double) epaisseurPointsAxes / 2.0);
    const double y1py_edit = y1py - ((double) epaisseurPointsAxes / 2.0);

    QBrush brosseAxes = QBrush(QColor(couleurAxes), Qt::SolidPattern);
    QBrush brossePointsAxes = QBrush(QColor(couleurPointsAxes), Qt::SolidPattern);
    QPen pinceauAxes = QPen(brosseAxes, epaisseurAxes, (Qt::PenStyle) (styleAxes + 1));
    QPen pinceauPointsAxes = QPen(brossePointsAxes, 0, Qt::SolidLine);

    this->scene()->addLine(x0px, x0py, x1px, x1py, pinceauAxes);
    this->scene()->addLine(y0px, y0py, y1px, y1py, pinceauAxes);

    if (stylePointsAxes == ParametresPoint::CARRE)
    {
        this->scene()->addRect(x0px_edit, x0py_edit, epaisseurPointsAxes, epaisseurPointsAxes,
                pinceauPointsAxes, brossePointsAxes);
        this->scene()->addRect(x1px_edit, x1py_edit, epaisseurPointsAxes, epaisseurPointsAxes,
                pinceauPointsAxes, brossePointsAxes);
        this->scene()->addRect(y0px_edit, y0py_edit, epaisseurPointsAxes, epaisseurPointsAxes,
                pinceauPointsAxes, brossePointsAxes);
        this->scene()->addRect(y1px_edit, y1py_edit, epaisseurPointsAxes, epaisseurPointsAxes,
                pinceauPointsAxes, brossePointsAxes);
    }
    else if (stylePointsAxes == ParametresPoint::CERCLE)
    {
        this->scene()->addEllipse(x0px_edit, x0py_edit, epaisseurPointsAxes, epaisseurPointsAxes,
                pinceauPointsAxes, brossePointsAxes);
        this->scene()->addEllipse(x1px_edit, x1py_edit, epaisseurPointsAxes, epaisseurPointsAxes,
                pinceauPointsAxes, brossePointsAxes);
        this->scene()->addEllipse(y0px_edit, y0py_edit, epaisseurPointsAxes, epaisseurPointsAxes,
                pinceauPointsAxes, brossePointsAxes);
        this->scene()->addEllipse(y1px_edit, y1py_edit, epaisseurPointsAxes, epaisseurPointsAxes,
                pinceauPointsAxes, brossePointsAxes);
    }
}

void VueGraphiqueEtude::dessinerPoint(const Point& point,
        const ParametresPoint& parametresPointsManuels)
{
    // TODO void VueGraphiqueEtude::dessinerPoint(const Point& point, const ParametresPoint& parametresPointsManuels)
    Q_UNUSED(point);
    Q_UNUSED(parametresPointsManuels);
}

void VueGraphiqueEtude::dessinerCourbe(const QList<Point> listeDePoints,
        const ParametresTrait& parametresCourbes, const ParametresPoint& parametresPointsCourbes)
{
    // TODO void VueGraphiqueEtude::dessinerCourbe(const QList<Point> listeDePoints, const ParametresTrait& parametresCourbes, const ParametresPoint& parametresPointsCourbes)
    Q_UNUSED(listeDePoints);
    Q_UNUSED(parametresCourbes);
    Q_UNUSED(parametresPointsCourbes);
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
