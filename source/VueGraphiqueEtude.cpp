//==============================================================================
// Name        : VueGraphiqueEtude.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.3.0 (07/08/2021)
// Description : Source file of the VueGraphiqueEtude class
//==============================================================================

#include "VueGraphiqueEtude.h"
#include <cmath>
#include <QBrush>
#include <QColor>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QPainterPath>
#include <QPen>
#include <QPixmap>
#include <QPoint>
#include <QPolygon>
#include <QRgb>

constexpr double VueGraphiqueEtude::_facteurZoomIn;
constexpr double VueGraphiqueEtude::_facteurZoomOut;

VueGraphiqueEtude::VueGraphiqueEtude(QWidget* parent) :
        QGraphicsView(parent)
{
    QGraphicsScene* graphicsScene = new QGraphicsScene(parent);
    setScene(graphicsScene);
}

VueGraphiqueEtude::VueGraphiqueEtude(QGraphicsScene* scene, QWidget* parent) :
        QGraphicsView(scene, parent)
{
}

VueGraphiqueEtude::~VueGraphiqueEtude()
{
}

void VueGraphiqueEtude::repositionner()
{
    resetTransform();
}

void VueGraphiqueEtude::effacer()
{
    scene()->clear();
}

void VueGraphiqueEtude::dessiner(const Etude& etude)
{
    const Image& image = etude.getImage();
    const Repere& repere = etude.getRepere();
    const ParametresTrait& parametresAxes =
            etude.getParametres().getParametresAffichage().getParametresAxes();
    const ParametresTrait& parametresCourbes =
            etude.getParametres().getParametresAffichage().getParametresCourbes();
    const ParametresPoint& parametresPointsAxes =
            etude.getParametres().getParametresAffichage().getParametresPointsAxes();
    const ParametresPoint& parametresPointsCourbes =
            etude.getParametres().getParametresAffichage().getParametresPointsCourbes();
    const ParametresPoint& parametresPointsManuels =
            etude.getParametres().getParametresAffichage().getParametresPointsManuels();

    const QList<Courbe> listeDeCourbes = etude.getListeDeCourbes();
    const QList<Point> listeDePointsManuels = etude.getListeDePointsManuels();
    const int nombreDeCourbes = listeDeCourbes.count();
    const int nombreDePointsManuels = listeDePointsManuels.count();

    effacer();
    dessinerImage(image);
    dessinerRepere(repere, parametresAxes, parametresPointsAxes);
    for (int itCourbe = 0; itCourbe < nombreDeCourbes; itCourbe++)
    {
        const Courbe& courbe = listeDeCourbes.at(itCourbe);
        dessinerCourbe(courbe, parametresCourbes, parametresPointsCourbes);
    }
    for (int itPointManuel = 0; itPointManuel < nombreDePointsManuels; itPointManuel++)
    {
        const Point& pointManuel = listeDePointsManuels.at(itPointManuel);
        dessinerPointManuel(pointManuel, parametresPointsManuels);
    }
}

void VueGraphiqueEtude::dessinerImage(const Image& image)
{
    const QImage& imageConvertie = image.getImageConvertie();
    const int largeurImage = imageConvertie.width();
    const int hauteurImage = imageConvertie.height();
    QGraphicsPixmapItem* itemImage = new QGraphicsPixmapItem(QPixmap::fromImage(imageConvertie));
    scene()->addItem(itemImage);
    scene()->setSceneRect(0, 0, largeurImage, hauteurImage);
}

void VueGraphiqueEtude::dessinerRepere(const Repere& repere, const ParametresTrait& parametresAxes,
        const ParametresPoint& parametresPointsAxes)
{
    const Point& pointX0 = repere.getPointX0();
    const Point& pointX1 = repere.getPointX1();
    const Point& pointY0 = repere.getPointY0();
    const Point& pointY1 = repere.getPointY1();

    dessinerTrait(pointX0, pointX1, parametresAxes);
    dessinerTrait(pointY0, pointY1, parametresAxes);
    dessinerPoint(pointX0, parametresPointsAxes);
    dessinerPoint(pointX1, parametresPointsAxes);
    dessinerPoint(pointY0, parametresPointsAxes);
    dessinerPoint(pointY1, parametresPointsAxes);
}

void VueGraphiqueEtude::dessinerCourbe(const Courbe& courbe,
        const ParametresTrait& parametresCourbes, const ParametresPoint& parametresPointsCourbes)
{
    const int nombreDePointsCourbe = courbe.count();
    const Point& premierPoint = courbe.at(0);
    const Point& dernierPoint = courbe.at(nombreDePointsCourbe - 1);
    dessinerTraitContinu(courbe, parametresCourbes);
    dessinerPoint(premierPoint, parametresPointsCourbes);
    dessinerPoint(dernierPoint, parametresPointsCourbes);
}

void VueGraphiqueEtude::dessinerPointManuel(const Point& pointManuel,
        const ParametresPoint& parametresPointsManuels)
{
    dessinerPoint(pointManuel, parametresPointsManuels);
}

void VueGraphiqueEtude::dessinerPoint(const Point& point, const ParametresPoint& parametresPoint)
{
    const int& stylePoint = parametresPoint.getStylePoint();
    const int& epaisseurPoint = parametresPoint.getEpaisseurPoint();
    const QRgb& couleurPoint = parametresPoint.getCouleurPoint();
    const QBrush brossePoint = QBrush(QColor(couleurPoint), Qt::SolidPattern);
    const QPen pinceauPoint = QPen(brossePoint, 0, Qt::SolidLine);

    const double ppx = point.getPointPixelX();
    const double ppy = point.getPointPixelY();
    const double ppx_edit = ppx - floor(epaisseurPoint / 2.0);
    const double ppy_edit = ppy - floor(epaisseurPoint / 2.0);

    if (stylePoint == ParametresPoint::CARRE)
    {
        scene()->addRect(ppx_edit, ppy_edit, epaisseurPoint, epaisseurPoint, pinceauPoint,
                brossePoint);
    }
    else if (stylePoint == ParametresPoint::CERCLE)
    {
        scene()->addEllipse(ppx_edit, ppy_edit, epaisseurPoint, epaisseurPoint, pinceauPoint,
                brossePoint);
    }
}

void VueGraphiqueEtude::dessinerTrait(const Point& point1, const Point& point2,
        const ParametresTrait& parametresTrait)
{
    const int& styleTrait = parametresTrait.getStyleTrait();
    const int& epaisseurTrait = parametresTrait.getEpaisseurTrait();
    const QRgb& couleurTrait = parametresTrait.getCouleurTrait();
    const QBrush brosseTrait = QBrush(QColor(couleurTrait), Qt::SolidPattern);
    const QPen pinceauTrait = QPen(brosseTrait, epaisseurTrait,
            static_cast<Qt::PenStyle>(styleTrait + 1), Qt::RoundCap, Qt::RoundJoin);

    const double p1px = point1.getPointPixelX();
    const double p1py = point1.getPointPixelY();
    const double p2px = point2.getPointPixelX();
    const double p2py = point2.getPointPixelY();

    scene()->addLine(p1px, p1py, p2px, p2py, pinceauTrait);
}

void VueGraphiqueEtude::dessinerTraitContinu(const QList<Point>& listeDePoints,
        const ParametresTrait& parametresTrait)
{
    const int& styleTrait = parametresTrait.getStyleTrait();
    const int& epaisseurTrait = parametresTrait.getEpaisseurTrait();
    const QRgb& couleurTrait = parametresTrait.getCouleurTrait();
    const QBrush brosseTrait = QBrush(QColor(couleurTrait), Qt::SolidPattern);
    const QPen pinceauTrait = QPen(brosseTrait, epaisseurTrait,
            static_cast<Qt::PenStyle>(styleTrait + 1), Qt::RoundCap, Qt::RoundJoin);

    QPolygon polygone;
    const int nombreDePoints = listeDePoints.count();
    for (int itPoint = 0; itPoint < nombreDePoints; itPoint++)
    {
        const Point& pointCourant = listeDePoints.at(itPoint);
        const QPoint& pointPixelCourant = pointCourant.getPointPixel();
        polygone.append(pointPixelCourant);
    }
    QPainterPath chemin;
    chemin.addPolygon(polygone);

    scene()->addPath(chemin, pinceauTrait);
}

void VueGraphiqueEtude::keyPressEvent(QKeyEvent* event)
{
    QGraphicsView::keyPressEvent(event);

    if (event->key() == Qt::Key_Plus)
    {
        scale(_facteurZoomIn, _facteurZoomIn);
    }
    else if (event->key() == Qt::Key_Minus)
    {
        scale(_facteurZoomOut, _facteurZoomOut);
    }
    else if (event->key() == Qt::Key_0)
    {
        resetTransform();
    }
}

void VueGraphiqueEtude::mousePressEvent(QMouseEvent* event)
{
    QGraphicsView::mousePressEvent(event);

    if (event->button() == Qt::LeftButton)
    {
        emit mousePressEventSignal(mapToScene(event->pos()));
    }
}

void VueGraphiqueEtude::mouseMoveEvent(QMouseEvent* event)
{
    QGraphicsView::mouseMoveEvent(event);

    emit mouseMoveEventSignal(mapToScene(event->pos()));
}

void VueGraphiqueEtude::wheelEvent(QWheelEvent* event)
{
    QGraphicsView::wheelEvent(event);

    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    if (event->angleDelta().y() > 0)
    {
        scale(_facteurZoomIn, _facteurZoomIn);
    }
    else if (event->angleDelta().y() < 0)
    {
        scale(_facteurZoomOut, _facteurZoomOut);
    }
}
