//==============================================================================
// Name        : Point.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Source file of the Point class
//==============================================================================

#include "Point.h"
#include "Outils.h"
#include <QStringList>

const QMap<int, QString> Point::_typesPointsTexte = QMap<int, QString>(
        std::map<int, QString> { { INDEFINI, QString::fromUtf8("Indéfini") }, { REPERE,
                QString::fromUtf8("Repère") }, { MANUEL, QString::fromUtf8("Manuel") }, { COURBE,
                QString::fromUtf8("Courbe") },
                { COURBE_DEBUT, QString::fromUtf8("Début de courbe") }, { COURBE_FIN,
                        QString::fromUtf8("Fin de courbe") } });

Point::Point() :
        _typePoint(INDEFINI)
{
    clear();
}

Point::Point(const QPoint& pointPixel, const QPointF& pointReel, const int& typePoint) :
        Point()
{
    set(pointPixel, pointReel, typePoint);
}

Point::Point(const int& pointPixelX, const int& pointPixelY, const double& pointReelX,
        const double& pointReelY, const int& typePoint) :
        Point()
{
    set(pointPixelX, pointPixelY, pointReelX, pointReelY, typePoint);
}

Point::Point(const Point& point) :
        Point()
{
    copy(point);
}

Point::~Point()
{
}

Point& Point::operator=(const Point& point)
{
    copy(point);
    return *this;
}

bool Point::operator==(const Point& point) const
{
    return equals(point);
}

bool Point::operator!=(const Point& point) const
{
    return !equals(point);
}

const QPoint& Point::getPointPixel() const
{
    return _pointPixel;
}

const QPointF& Point::getPointReel() const
{
    return _pointReel;
}

const int& Point::getTypePoint() const
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

void Point::setTypePoint(const int& typePoint)
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
    set(QPoint(), QPointF(), INDEFINI);
}

void Point::set(const QPoint& pointPixel, const QPointF& pointReel, const int& typePoint)
{
    setPointPixel(pointPixel);
    setPointReel(pointReel);
    setTypePoint(typePoint);
}

void Point::set(const int& pointPixelX, const int& pointPixelY, const double& pointReelX,
        const double& pointReelY, const int& typePoint)
{
    setPointPixelX(pointPixelX);
    setPointPixelY(pointPixelY);
    setPointReelX(pointReelX);
    setPointReelY(pointReelY);
    setTypePoint(typePoint);
}

void Point::copy(const Point& point)
{
    set(point.getPointPixel(), point.getPointReel(), point.getTypePoint());
}

bool Point::equals(const Point& point) const
{
    if (getPointPixel() != point.getPointPixel())
        return false;
    if (getPointReel() != point.getPointReel())
        return false;
    if (getTypePoint() != point.getTypePoint())
        return false;
    return true;
}

void Point::fromString(const QString& fromString, const QChar& sep)
{
    const QStringList fromStringList = listeSousElements(fromString, sep);
    setPointPixelX(fromStringList.at(0).toInt());
    setPointPixelY(fromStringList.at(1).toInt());
    setPointReelX(fromStringList.at(2).toDouble());
    setPointReelY(fromStringList.at(3).toDouble());
    setTypePoint(fromStringList.at(4).toInt());
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
    return _typesPointsTexte.value(getTypePoint());
}

void Point::setTypePointTexte(const QString& typePointTexte)
{
    setTypePoint(_typesPointsTexte.key(typePointTexte));
}
