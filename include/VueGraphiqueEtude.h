//==============================================================================
// Name        : VueGraphiqueEtude.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.3.0 (07/08/2021)
// Description : Header file of the VueGraphiqueEtude class
//==============================================================================

#ifndef VUEGRAPHIQUEETUDE_H
#define VUEGRAPHIQUEETUDE_H

#include "Etude.h"
#include "Image.h"
#include "ParametresPoint.h"
#include "ParametresTrait.h"
#include "Point.h"
#include "Repere.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QList>
#include <QMouseEvent>
#include <QPointF>
#include <QWheelEvent>
#include <QWidget>

class VueGraphiqueEtude : public QGraphicsView
{
    Q_OBJECT

public:
    // Constructeurs et destructeurs
    explicit VueGraphiqueEtude(QWidget* parent);
    VueGraphiqueEtude(QGraphicsScene* scene, QWidget* parent);
    virtual ~VueGraphiqueEtude() override;

    // Getters

    // Setters

    // Méthodes génériques

    // Méthodes spécifiques
    void repositionner();
    void effacer();
    void dessiner(const Etude& etude);
    void dessinerImage(const Image& image);
    void dessinerRepere(const Repere& repere, const ParametresTrait& parametresAxes,
            const ParametresPoint& parametresPointsAxes);
    void dessinerCourbe(const Courbe& courbe, const ParametresTrait& parametresCourbes,
            const ParametresPoint& parametresPointsCourbes);
    void dessinerPointManuel(const Point& pointManuel,
            const ParametresPoint& parametresPointsManuels);
    void dessinerPoint(const Point& point, const ParametresPoint& parametresPoint);
    void dessinerTrait(const Point& point1, const Point& point2,
            const ParametresTrait& parametresTrait);
    void dessinerTraitContinu(const QList<Point>& listeDePoints,
            const ParametresTrait& parametresTrait);

protected:
    // Méthodes spécifiques
    void keyPressEvent(QKeyEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;

private:
    // Attributs de classe

    // Attributs de classe inaccessibles
    static constexpr double _facteurZoomIn { 1.25 };
    static constexpr double _facteurZoomOut { 0.8 };

signals:
    // Signaux spécifiques
    void mousePressEventSignal(const QPointF pointVueGraphique);
    void mouseMoveEventSignal(const QPointF pointVueGraphique);
};

#endif /* VUEGRAPHIQUEETUDE_H */
