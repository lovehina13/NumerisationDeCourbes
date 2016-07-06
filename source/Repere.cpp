//==============================================================================
// Name        : Repere.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/01/2016)
// Description : Source file of the Repere class
//==============================================================================

#include "Repere.h"

Repere::Repere()
{
    this->clear();
}

Repere::Repere(const Point& pointX0, const Point& pointX1, const Point& pointY0,
        const Point& pointY1) :
        Repere()
{
    this->set(pointX0, pointX1, pointY0, pointY1);
}

Repere::Repere(const Repere& repere) :
        Repere()
{
    this->copy(repere);
}

Repere::~Repere()
{
}

const Point& Repere::getPointX0() const
{
    return this->pointX0;
}

const Point& Repere::getPointX1() const
{
    return this->pointX1;
}

const Point& Repere::getPointY0() const
{
    return this->pointY0;
}

const Point& Repere::getPointY1() const
{
    return this->pointY1;
}

void Repere::setPointX0(const Point& pointX0)
{
    this->pointX0 = pointX0;
}

void Repere::setPointX1(const Point& pointX1)
{
    this->pointX1 = pointX1;
}

void Repere::setPointY0(const Point& pointY0)
{
    this->pointY0 = pointY0;
}

void Repere::setPointY1(const Point& pointY1)
{
    this->pointY1 = pointY1;
}

void Repere::clear()
{
    this->set(Point(), Point(), Point(), Point());
}

void Repere::set(const Point& pointX0, const Point& pointX1, const Point& pointY0,
        const Point& pointY1)
{
    this->setPointX0(pointX0);
    this->setPointX1(pointX1);
    this->setPointY0(pointY0);
    this->setPointY1(pointY1);
}

void Repere::copy(const Repere& repere)
{
    this->set(repere.getPointX0(), repere.getPointX1(), repere.getPointY0(), repere.getPointY1());
}

bool Repere::equals(const Repere& repere) const
{
    if (!this->getPointX0().equals(repere.getPointX0()))
        return false;
    if (!this->getPointX1().equals(repere.getPointX1()))
        return false;
    if (!this->getPointY0().equals(repere.getPointY0()))
        return false;
    if (!this->getPointY1().equals(repere.getPointY1()))
        return false;
    return true;
}

void Repere::fromString(const QString& fromString, const char& sep)
{
    // TODO void Repere::fromString(const QString& fromString, const char& sep)
    Q_UNUSED(fromString);
    Q_UNUSED(sep);
}

const QString Repere::toString(const char& sep) const
{
    // TODO const QString Repere::toString(const char& sep) const
    Q_UNUSED(sep);
    return QString();
}

void Repere::pixelVersReel(const int& pointPixelX, const int& pointPixelY, double& pointReelX,
        double &pointReelY) const
{
    const double x0px = (double) this->getPointX0().getPointPixelX();
    const double x0py = (double) this->getPointX0().getPointPixelY();
    const double x1px = (double) this->getPointX1().getPointPixelX();
    const double x1py = (double) this->getPointX1().getPointPixelY();
    const double y0px = (double) this->getPointY0().getPointPixelX();
    const double y0py = (double) this->getPointY0().getPointPixelY();
    const double y1px = (double) this->getPointY1().getPointPixelX();
    const double y1py = (double) this->getPointY1().getPointPixelY();

    const double x0rx = this->getPointX0().getPointReelX();
    const double x1rx = this->getPointX1().getPointReelX();
    const double y0ry = this->getPointY0().getPointReelY();
    const double y1ry = this->getPointY1().getPointReelY();

    const double x21 = x1px - x0px;
    const double y21 = x1py - x0py;
    const double x43 = y1px - y0px;
    const double y43 = y1py - y0py;

    const double penteX = ((x0px - (double) pointPixelX)
            - (x0py - (double) pointPixelY) * (x43 / y43)) / (x21 - ((y21 * x43) / y43));
    const double penteY = ((y0py - (double) pointPixelY)
            - (y0px - (double) pointPixelX) * (y21 / x21)) / (y43 - ((x43 * y21) / x21));

    pointReelX = -penteX * (x1rx - x0rx) + x0rx;
    pointReelY = -penteY * (y1ry - y0ry) + y0ry;
}

void Repere::pixelVersReel(Point& point) const
{
    const int pointPixelX = point.getPointPixelX();
    const int pointPixelY = point.getPointPixelY();
    double pointReelX = 0.0;
    double pointReelY = 0.0;
    this->pixelVersReel(pointPixelX, pointPixelY, pointReelX, pointReelY);
    point.setPointReelX(pointReelX);
    point.setPointReelY(pointReelY);
}

void Repere::interpolationNumerique(const double& pointReelX1, const double& pointReelY1,
        const double& pointReelX2, const double& pointReelY2, const double& pointReelX,
        double& pointReelY) const
{
    const double pente = (pointReelY2 - pointReelY1) / (pointReelX2 - pointReelX1);

    pointReelY = pente * (pointReelX - pointReelX1) + pointReelY1;
}

void Repere::interpolationNumerique(const Point& point1, const Point& point2, Point& point) const
{
    // TODO Modification du Y pixel ?
    const double pointReelX1 = point1.getPointReelX();
    const double pointReelY1 = point1.getPointReelY();
    const double pointReelX2 = point2.getPointReelX();
    const double pointReelY2 = point2.getPointReelY();
    const double pointReelX = point.getPointReelX();
    double pointReelY = 0.0;
    this->interpolationNumerique(pointReelX1, pointReelY1, pointReelX2, pointReelY2, pointReelX,
            pointReelY);
    point.setPointReelY(pointReelY);
}
