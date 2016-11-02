//==============================================================================
// Name        : ParametresPoint.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (28/06/2016)
// Description : Source file of the ParametresPoint class
//==============================================================================

#include "ParametresPoint.h"
#include "Outils.h"
#include <QColor>
#include <QStringList>

const QRgb ParametresPoint::couleurPointDefaut = QColor(Qt::black).rgb();
const QRgb ParametresPoint::couleurPointAxeDefaut = QColor(Qt::red).rgb();
const QRgb ParametresPoint::couleurPointCourbeDefaut = QColor(Qt::blue).rgb();
const QRgb ParametresPoint::couleurPointManuelDefaut = QColor(Qt::green).rgb();

ParametresPoint::ParametresPoint() :
        stylePoint(stylePointDefaut), epaisseurPoint(epaisseurPointDefaut),
                couleurPoint(couleurPointDefaut)
{
    this->clear();
}

ParametresPoint::ParametresPoint(const int& stylePoint, const int& epaisseurPoint,
        const QRgb& couleurPoint) :
        ParametresPoint()
{
    this->set(stylePoint, epaisseurPoint, couleurPoint);
}

ParametresPoint::ParametresPoint(const ParametresPoint& parametresPoint) :
        ParametresPoint()
{
    this->copy(parametresPoint);
}

ParametresPoint::~ParametresPoint()
{
}

const int& ParametresPoint::getStylePoint() const
{
    return this->stylePoint;
}

const int& ParametresPoint::getEpaisseurPoint() const
{
    return this->epaisseurPoint;
}

const QRgb& ParametresPoint::getCouleurPoint() const
{
    return this->couleurPoint;
}

void ParametresPoint::setStylePoint(const int& stylePoint)
{
    this->stylePoint = stylePoint;
}

void ParametresPoint::setEpaisseurPoint(const int& epaisseurPoint)
{
    this->epaisseurPoint = epaisseurPoint;
}

void ParametresPoint::setCouleurPoint(const QRgb& couleurPoint)
{
    this->couleurPoint = couleurPoint;
}

void ParametresPoint::clear()
{
    this->set((int) stylePointDefaut, (int) epaisseurPointDefaut, (QRgb) couleurPointDefaut);
}

void ParametresPoint::set(const int& stylePoint, const int& epaisseurPoint,
        const QRgb& couleurPoint)
{
    this->setStylePoint(stylePoint);
    this->setEpaisseurPoint(epaisseurPoint);
    this->setCouleurPoint(couleurPoint);
}

void ParametresPoint::copy(const ParametresPoint& parametresPoint)
{
    this->set(parametresPoint.getStylePoint(), parametresPoint.getEpaisseurPoint(),
            parametresPoint.getCouleurPoint());
}

bool ParametresPoint::equals(const ParametresPoint& parametresPoint) const
{
    if (this->getStylePoint() != parametresPoint.getStylePoint())
        return false;
    if (this->getEpaisseurPoint() != parametresPoint.getEpaisseurPoint())
        return false;
    if (this->getCouleurPoint() != parametresPoint.getCouleurPoint())
        return false;
    return true;
}

void ParametresPoint::fromString(const QString& fromString, const char& sep)
{
    QStringList fromStringList = listeSousElements(fromString, sep);
    this->setStylePoint(fromStringList.at(0).toInt());
    this->setEpaisseurPoint(fromStringList.at(1).toInt());
    this->setCouleurPoint(QColor(fromStringList.at(2)).rgb());
}

const QString ParametresPoint::toString(const char& sep) const
{
    QString toString;
    toString += QString::number(this->getStylePoint()) + sep;
    toString += QString::number(this->getEpaisseurPoint()) + sep;
    toString += QColor(this->getCouleurPoint()).name();
    return toString;
}

