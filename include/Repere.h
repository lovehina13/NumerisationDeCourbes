//==============================================================================
// Name        : Repere.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Header file of the Repere class
//==============================================================================

#ifndef REPERE_H
#define REPERE_H

#include "Point.h"
#include <QChar>
#include <QString>

class Repere
{
public:
    // Constructeurs et destructeurs
    Repere() = default;
    Repere(const Point& pointX0, const Point& pointX1, const Point& pointY0, const Point& pointY1);

    // Opérateurs
    bool operator==(const Repere& repere) const = default;
    bool operator!=(const Repere& repere) const = default;

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
    void set(const Point& pointX0, const Point& pointX1, const Point& pointY0,
            const Point& pointY1);
    void fromString(const QString& fromString, const QChar& sep);
    const QString toString(const QChar& sep) const;

    // Méthodes spécifiques
    void pixelVersReel(Point& point) const;
    void pixelVersReel(const int& pointPixelX, const int& pointPixelY, double& pointReelX,
            double& pointReelY) const;

private:
    // Attributs de classe
    Point _pointX0 { Point::REPERE };
    Point _pointX1 { Point::REPERE };
    Point _pointY0 { Point::REPERE };
    Point _pointY1 { Point::REPERE };
};

#endif /* REPERE_H */
