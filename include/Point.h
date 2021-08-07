//==============================================================================
// Name        : Point.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.3.0 (07/08/2021)
// Description : Header file of the Point class
//==============================================================================

#ifndef POINT_H
#define POINT_H

#include <QChar>
#include <QList>
#include <QMap>
#include <QPoint>
#include <QPointF>
#include <QString>

class Point
{
public:
    // Enumération des types de points
    enum TypePoint
    {
        INDEFINI, REPERE, MANUEL, COURBE, COURBE_DEBUT, COURBE_FIN
    };

    // Constructeurs et destructeurs
    Point() = default;
    Point(const QPoint& pointPixel, const QPointF& pointReel, const TypePoint& typePoint);
    Point(const int& pointPixelX, const int& pointPixelY, const double& pointReelX,
            const double& pointReelY, const TypePoint& typePoint);
    explicit Point(const TypePoint& typePoint);

    // Opérateurs
    bool operator==(const Point& point) const = default;
    bool operator!=(const Point& point) const = default;

    // Getters
    const QPoint& getPointPixel() const;
    const QPointF& getPointReel() const;
    const TypePoint& getTypePoint() const;
    int getPointPixelX() const;
    int getPointPixelY() const;
    double getPointReelX() const;
    double getPointReelY() const;

    // Setters
    void setPointPixel(const QPoint& pointPixel);
    void setPointReel(const QPointF& pointReel);
    void setTypePoint(const TypePoint& typePoint);
    void setPointPixelX(const int& pointPixelX);
    void setPointPixelY(const int& pointPixelY);
    void setPointReelX(const double& pointReelX);
    void setPointReelY(const double& pointReelY);

    // Méthodes génériques
    void clear();
    void set(const QPoint& pointPixel, const QPointF& pointReel, const TypePoint& typePoint);
    void set(const int& pointPixelX, const int& pointPixelY, const double& pointReelX,
            const double& pointReelY, const TypePoint& typePoint);
    void fromString(const QString& fromString, const QChar& sep);
    const QString toString(const QChar& sep) const;

    // Méthodes spécifiques
    const QString getTypePointTexte() const;
    void setTypePointTexte(const QString& typePointTexte);

private:
    // Attributs de classe
    QPoint _pointPixel;
    QPointF _pointReel;
    TypePoint _typePoint { INDEFINI };

    // Définition des correspondances
    static const QMap<TypePoint, QString> _typePointTexte;
};

typedef QList<Point> Courbe;

#endif /* POINT_H */
