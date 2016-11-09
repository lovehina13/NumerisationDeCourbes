//==============================================================================
// Name        : Point.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/01/2016)
// Description : Source file of the Point class
//==============================================================================

#include "Point.h"
#include "Outils.h"
#include <QStringList>

const QMap<int, QString> Point::typesPointsTexte = { }; // TODO

Point::Point() :
        typePoint(INDEFINI)
{
    this->clear();
}

Point::Point(const QPoint& pointPixel, const QPointF& pointReel, const int& typePoint) :
        Point()
{
    this->set(pointPixel, pointReel, typePoint);
}

Point::Point(const int& pointPixelX, const int& pointPixelY, const double& pointReelX,
        const double& pointReelY, const int& typePoint) :
        Point()
{
    this->set(pointPixelX, pointPixelY, pointReelX, pointReelY, typePoint);
}

Point::Point(const Point& point) :
        Point()
{
    this->copy(point);
}

Point::~Point()
{
}

const QPoint& Point::getPointPixel() const
{
    return this->pointPixel;
}

const QPointF& Point::getPointReel() const
{
    return this->pointReel;
}

const int& Point::getTypePoint() const
{
    return this->typePoint;
}

int Point::getPointPixelX() const
{
    return this->pointPixel.x();
}

int Point::getPointPixelY() const
{
    return this->pointPixel.y();
}

double Point::getPointReelX() const
{
    return this->pointReel.x();
}

double Point::getPointReelY() const
{
    return this->pointReel.y();
}

void Point::setPointPixel(const QPoint& pointPixel)
{
    this->pointPixel = pointPixel;
}

void Point::setPointReel(const QPointF& pointReel)
{
    this->pointReel = pointReel;
}

void Point::setTypePoint(const int& typePoint)
{
    this->typePoint = typePoint;
}

void Point::setPointPixelX(const int& pointPixelX)
{
    this->pointPixel.setX(pointPixelX);
}

void Point::setPointPixelY(const int& pointPixelY)
{
    this->pointPixel.setY(pointPixelY);
}

void Point::setPointReelX(const double& pointReelX)
{
    this->pointReel.setX(pointReelX);
}

void Point::setPointReelY(const double& pointReelY)
{
    this->pointReel.setY(pointReelY);
}

void Point::clear()
{
    this->set(QPoint(), QPointF(), INDEFINI);
}

void Point::set(const QPoint& pointPixel, const QPointF& pointReel, const int& typePoint)
{
    this->setPointPixel(pointPixel);
    this->setPointReel(pointReel);
    this->setTypePoint(typePoint);
}

void Point::set(const int& pointPixelX, const int& pointPixelY, const double& pointReelX,
        const double& pointReelY, const int& typePoint)
{
    this->setPointPixelX(pointPixelX);
    this->setPointPixelY(pointPixelY);
    this->setPointReelX(pointReelX);
    this->setPointReelY(pointReelY);
    this->setTypePoint(typePoint);
}

void Point::copy(const Point& point)
{
    this->set(point.getPointPixel(), point.getPointReel(), point.getTypePoint());
}

bool Point::equals(const Point& point) const
{
    if (this->getPointPixel() != point.getPointPixel())
        return false;
    if (this->getPointReel() != point.getPointReel())
        return false;
    if (this->getTypePoint() != point.getTypePoint())
        return false;
    return true;
}

void Point::fromString(const QString& fromString, const char& sep)
{
    QStringList fromStringList = listeSousElements(fromString, sep);
    this->setPointPixelX(fromStringList.at(0).toInt());
    this->setPointPixelY(fromStringList.at(1).toInt());
    this->setPointReelX(fromStringList.at(2).toDouble());
    this->setPointReelY(fromStringList.at(3).toDouble());
    this->setTypePoint(fromStringList.at(4).toInt());
}

const QString Point::toString(const char& sep) const
{
    QString toString;
    toString += QString::number(this->getPointPixelX()) + sep;
    toString += QString::number(this->getPointPixelY()) + sep;
    toString += QString::number(this->getPointReelX()) + sep;
    toString += QString::number(this->getPointReelY()) + sep;
    toString += QString::number(this->getTypePoint());
    return toString;
}

QString Point::getTypePointTexte() const
{
    return typesPointsTexte.value(this->getTypePoint());
}

void Point::setTypePointTexte(const QString& typePointTexte)
{
    this->setTypePoint(typesPointsTexte.key(typePointTexte));
}

bool Point::operator==(const Point& point) const
{
    return this->equals(point);
}
