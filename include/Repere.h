//==============================================================================
// Name        : Repere.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/01/2016)
// Description : Header file of the Repere class
//==============================================================================

#ifndef REPERE_H_
#define REPERE_H_

#include "Point.h"
#include <QString>

class Repere
{
public:
    // Constructeurs et destructeurs
    Repere();
    Repere(const Point& pointX0, const Point& pointX1, const Point& pointY0, const Point& pointY1);
    Repere(const Repere& repere);
    virtual ~Repere();

    // Getters
    const Point& getPointX0() const;
    const Point& getPointX1() const;
    const Point& getPointY0() const;
    const Point& getPointY1() const;

    // Setters
    void setPointX0(const Point& pointX0);
    void setPointX1(const Point& pointX1);
    void setPointY0(const Point& pointY0);
    void setPointY1(const Point& pointY1);

    // Méthodes génériques
    void clear();
    void initialize(const Point& pointX0, const Point& pointX1, const Point& pointY0,
            const Point& pointY1);
    void copy(const Repere& repere);
    bool equals(const Repere& repere) const;
    void fromString(const QString& fromString, const char& sep);
    const QString toString(const char& sep) const;

    // Méthodes spécifiques
    // TODO Méthodes spécifiques
    void pixelVersReel(const int& pointPixelX, const int& pointPixelY, double& pointReelX,
            double &pointReelY);

private:
    // Attributs de classe
    Point pointX0;
    Point pointX1;
    Point pointY0;
    Point pointY1;
};

#endif /* REPERE_H_ */
