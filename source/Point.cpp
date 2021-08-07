//==============================================================================
// Name        : Point.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.3.0 (07/08/2021)
// Description : Source file of the Point class
//==============================================================================

#include "Point.h"
#include "Outils.h"
#include <QStringList>

using TypePoint = Point::TypePoint;

const QMap<TypePoint, QString> Point::_typePointTexte = QMap<TypePoint, QString>(
        { { INDEFINI, QString::fromUtf8("Indéfini") }, { REPERE, QString::fromUtf8("Repère") }, {
                MANUEL, QString::fromUtf8("Manuel") }, { COURBE, QString::fromUtf8("Courbe") }, {
                COURBE_DEBUT, QString::fromUtf8("Début de courbe") }, { COURBE_FIN,
                QString::fromUtf8("Fin de courbe") } });

Point::Point(const QPoint& pointPixel, const QPointF& pointReel, const TypePoint& typePoint) :
        _pointPixel(pointPixel), _pointReel(pointReel), _typePoint(typePoint)
{
}

Point::Point(const int& pointPixelX, const int& pointPixelY, const double& pointReelX,
        const double& pointReelY, const TypePoint& typePoint) :
        _pointPixel(pointPixelX, pointPixelY), _pointReel(pointReelX, pointReelY),
                _typePoint(typePoint)
{
}

Point::Point(const TypePoint& typePoint) :
        _typePoint(typePoint)
{
}

const QPoint& Point::getPointPixel() const
{
    return _pointPixel;
}

const QPointF& Point::getPointReel() const
{
    return _pointReel;
}

const TypePoint& Point::getTypePoint() const
{
    return _typePoint;
}

int Point::getPointPixelX() const
{
    return _pointPixel.x();
}

int Point::getPointPixelY() const
{
    return _pointPixel.y();
}

double Point::getPointReelX() const
{
    return _pointReel.x();
}

double Point::getPointReelY() const
{
    return _pointReel.y();
}

void Point::setPointPixel(const QPoint& pointPixel)
{
    _pointPixel = pointPixel;
}

void Point::setPointReel(const QPointF& pointReel)
{
    _pointReel = pointReel;
}

void Point::setTypePoint(const TypePoint& typePoint)
{
    _typePoint = typePoint;
}

void Point::setPointPixelX(const int& pointPixelX)
{
    _pointPixel.setX(pointPixelX);
}

void Point::setPointPixelY(const int& pointPixelY)
{
    _pointPixel.setY(pointPixelY);
}

void Point::setPointReelX(const double& pointReelX)
{
    _pointReel.setX(pointReelX);
}

void Point::setPointReelY(const double& pointReelY)
{
    _pointReel.setY(pointReelY);
}

void Point::clear()
{
    *this = Point();
}

void Point::set(const QPoint& pointPixel, const QPointF& pointReel, const TypePoint& typePoint)
{
    setPointPixel(pointPixel);
    setPointReel(pointReel);
    setTypePoint(typePoint);
}

void Point::set(const int& pointPixelX, const int& pointPixelY, const double& pointReelX,
        const double& pointReelY, const TypePoint& typePoint)
{
    setPointPixelX(pointPixelX);
    setPointPixelY(pointPixelY);
    setPointReelX(pointReelX);
    setPointReelY(pointReelY);
    setTypePoint(typePoint);
}

void Point::fromString(const QString& fromString, const QChar& sep)
{
    const QStringList fromStringList = listeSousElements(fromString, sep);
    setPointPixelX(fromStringList.at(0).toInt());
    setPointPixelY(fromStringList.at(1).toInt());
    setPointReelX(fromStringList.at(2).toDouble());
    setPointReelY(fromStringList.at(3).toDouble());
    setTypePoint(static_cast<TypePoint>(fromStringList.at(4).toInt()));
}

const QString Point::toString(const QChar& sep) const
{
    QString toString;
    toString += QString::number(getPointPixelX()) + sep;
    toString += QString::number(getPointPixelY()) + sep;
    toString += QString::number(getPointReelX()) + sep;
    toString += QString::number(getPointReelY()) + sep;
    toString += QString::number(getTypePoint());
    return toString;
}

const QString Point::getTypePointTexte() const
{
    return _typePointTexte.value(getTypePoint());
}

void Point::setTypePointTexte(const QString& typePointTexte)
{
    setTypePoint(_typePointTexte.key(typePointTexte));
}
