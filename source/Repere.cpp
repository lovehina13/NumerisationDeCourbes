//==============================================================================
// Name        : Repere.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Source file of the Repere class
//==============================================================================

#include "Repere.h"
#include "Outils.h"
#include <QStringList>

Repere::Repere(const Point& pointX0, const Point& pointX1, const Point& pointY0,
        const Point& pointY1) :
        _pointX0(pointX0), _pointX1(pointX1), _pointY0(pointY0), _pointY1(pointY1)
{
}

const Point& Repere::getPointX0() const
{
    return _pointX0;
}

const Point& Repere::getPointX1() const
{
    return _pointX1;
}

const Point& Repere::getPointY0() const
{
    return _pointY0;
}

const Point& Repere::getPointY1() const
{
    return _pointY1;
}

void Repere::setPointX0(const Point& pointX0)
{
    _pointX0 = pointX0;
}

void Repere::setPointX1(const Point& pointX1)
{
    _pointX1 = pointX1;
}

void Repere::setPointY0(const Point& pointY0)
{
    _pointY0 = pointY0;
}

void Repere::setPointY1(const Point& pointY1)
{
    _pointY1 = pointY1;
}

void Repere::clear()
{
    *this = Repere();
}

void Repere::set(const Point& pointX0, const Point& pointX1, const Point& pointY0,
        const Point& pointY1)
{
    setPointX0(pointX0);
    setPointX1(pointX1);
    setPointY0(pointY0);
    setPointY1(pointY1);
}

void Repere::fromString(const QString& fromString, const QChar& sep)
{
    const QStringList fromStringList = listeSousElements(fromString, sep);
    Point pointX0 = getPointX0();
    Point pointX1 = getPointX1();
    Point pointY0 = getPointY0();
    Point pointY1 = getPointY1();
    pointX0.fromString(fromStringList.at(0), sep);
    pointX1.fromString(fromStringList.at(1), sep);
    pointY0.fromString(fromStringList.at(2), sep);
    pointY1.fromString(fromStringList.at(3), sep);
    setPointX0(pointX0);
    setPointX1(pointX1);
    setPointY0(pointY0);
    setPointY1(pointY1);
}

const QString Repere::toString(const QChar& sep) const
{
    QString toString;
    toString += QString("(%1)").arg(getPointX0().toString(sep)) + sep;
    toString += QString("(%1)").arg(getPointX1().toString(sep)) + sep;
    toString += QString("(%1)").arg(getPointY0().toString(sep)) + sep;
    toString += QString("(%1)").arg(getPointY1().toString(sep));
    return toString;
}

void Repere::pixelVersReel(Point& point) const
{
    const int pointPixelX = point.getPointPixelX();
    const int pointPixelY = point.getPointPixelY();
    double pointReelX = 0.0;
    double pointReelY = 0.0;
    pixelVersReel(pointPixelX, pointPixelY, pointReelX, pointReelY);
    point.setPointReelX(pointReelX);
    point.setPointReelY(pointReelY);
}

void Repere::pixelVersReel(const int& pointPixelX, const int& pointPixelY, double& pointReelX,
        double& pointReelY) const
{
    const Point& pointX0 = getPointX0();
    const Point& pointX1 = getPointX1();
    const Point& pointY0 = getPointY0();
    const Point& pointY1 = getPointY1();

    const double x0px = pointX0.getPointPixelX();
    const double x0py = pointX0.getPointPixelY();
    const double x1px = pointX1.getPointPixelX();
    const double x1py = pointX1.getPointPixelY();
    const double y0px = pointY0.getPointPixelX();
    const double y0py = pointY0.getPointPixelY();
    const double y1px = pointY1.getPointPixelX();
    const double y1py = pointY1.getPointPixelY();

    const double x0rx = pointX0.getPointReelX();
    const double x1rx = pointX1.getPointReelX();
    const double y0ry = pointY0.getPointReelY();
    const double y1ry = pointY1.getPointReelY();

    const double x21 = x1px - x0px;
    const double y21 = x1py - x0py;
    const double x43 = y1px - y0px;
    const double y43 = y1py - y0py;

    const double penteX = ((x0px - pointPixelX) - (x0py - pointPixelY) * (x43 / y43))
            / (x21 - y21 * (x43 / y43));
    const double penteY = ((y0py - pointPixelY) - (y0px - pointPixelX) * (y21 / x21))
            / (y43 - x43 * (y21 / x21));

    pointReelX = -penteX * (x1rx - x0rx) + x0rx;
    pointReelY = -penteY * (y1ry - y0ry) + y0ry;
}
