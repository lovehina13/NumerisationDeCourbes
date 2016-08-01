//==============================================================================
// Name        : VueGraphiqueEtude.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (29/07/2016)
// Description : Source file of the VueGraphiqueEtude class
//==============================================================================

#include "VueGraphiqueEtude.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>

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
    // TODO void VueGraphiqueEtude::dessinerRepere(const Repere& repere, const ParametresTrait& parametresAxes, const ParametresPoint& parametresPointsAxes)
    Q_UNUSED(repere);
    Q_UNUSED(parametresAxes);
    Q_UNUSED(parametresPointsAxes);
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

void VueGraphiqueEtude::wheelEvent(QWheelEvent* event)
{
    // TODO void VueGraphiqueEtude::wheelEvent(QWheelEvent* event)
    Q_UNUSED(event);
}
