//==============================================================================
// Name        : Point.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/01/2016)
// Description : Source file of the Point class
//==============================================================================

#include "Point.h"

Point::Point() :
        typePoint(INDEFINI)
{
    this->clear();
}

Point::Point(const QPoint& pointPixel, const QPointF& pointReel, const int& typePoint) :
        Point()
{
    this->initialize(pointPixel, pointReel, typePoint);
}

Point::Point(const int& pointPixelX, const int& pointPixelY, const double& pointReelX,
        const double& pointReelY, const int& typePoint) :
        Point()
{
    this->initialize(pointPixelX, pointPixelY, pointReelX, pointReelY, typePoint);
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
    this->initialize(QPoint(), QPointF(), INDEFINI);
}

void Point::initialize(const QPoint& pointPixel, const QPointF& pointReel, const int& typePoint)
{
    this->setPointPixel(pointPixel);
    this->setPointReel(pointReel);
    this->setTypePoint(typePoint);
}

void Point::initialize(const int& pointPixelX, const int& pointPixelY, const double& pointReelX,
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
    this->initialize(point.getPointPixel(), point.getPointReel(), point.getTypePoint());
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
    // TODO void Point::fromString(const QString& fromString, const char& sep)
}

const QString Point::toString(const char& sep) const
{
    // TODO const QString Point::toString(const char& sep) const
    return QString();
}

bool Point::operator==(const Point& point)
{
    return this->equals(point);
}
