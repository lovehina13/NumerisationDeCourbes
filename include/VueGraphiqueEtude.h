//==============================================================================
// Name        : VueGraphiqueEtude.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (29/07/2016)
// Description : Header file of the VueGraphiqueEtude class
//==============================================================================

#ifndef VUEGRAPHIQUEETUDE_H_
#define VUEGRAPHIQUEETUDE_H_

#include "Etude.h"
#include "Image.h"
#include "ParametresPoint.h"
#include "ParametresTrait.h"
#include "Point.h"
#include "Repere.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>
#include <QWheelEvent>
#include <QWidget>

class VueGraphiqueEtude : public QGraphicsView
{
public:
    VueGraphiqueEtude(QWidget* parent);
    VueGraphiqueEtude(QGraphicsScene* scene, QWidget* parent);
    virtual ~VueGraphiqueEtude();

    // Getters

    // Setters

    // Méthodes génériques

    // Méthodes spécifiques
    void effacer();
    void dessiner(const Etude &etude);
    void dessinerImage(const Image& image);
    void dessinerRepere(const Repere& repere, const ParametresTrait& parametresAxes,
            const ParametresPoint& parametresPointsAxes);
    void dessinerPoint(const Point& point, const ParametresPoint& parametresPointsManuels);
    void dessinerCourbe(const QList<Point> listeDePoints, const ParametresTrait& parametresCourbes,
            const ParametresPoint& parametresPointsCourbes);

protected:
    // Méthodes spécifiques
    void wheelEvent(QWheelEvent* event);
};

#endif /* VUEGRAPHIQUEETUDE_H_ */
