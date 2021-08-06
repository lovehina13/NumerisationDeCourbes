//==============================================================================
// Name        : ParametresPoint.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Source file of the ParametresPoint class
//==============================================================================

#include "ParametresPoint.h"
#include "Outils.h"
#include <QColor>
#include <QStringList>

using StylePoint = ParametresPoint::StylePoint;

const StylePoint ParametresPoint::stylePointDefaut;
const int ParametresPoint::epaisseurPointDefaut;
const QRgb ParametresPoint::couleurPointDefaut;
const QRgb ParametresPoint::couleurPointAxeDefaut;
const QRgb ParametresPoint::couleurPointCourbeDefaut;
const QRgb ParametresPoint::couleurPointManuelDefaut;

const QMap<StylePoint, QString> ParametresPoint::_stylePointTexte = QMap<StylePoint, QString>( { {
        CARRE, QString::fromUtf8("Carré") }, { CERCLE, QString::fromUtf8("Cercle") } });

ParametresPoint::ParametresPoint(const StylePoint& stylePoint, const int& epaisseurPoint,
        const QRgb& couleurPoint) :
        _stylePoint(stylePoint), _epaisseurPoint(epaisseurPoint), _couleurPoint(couleurPoint)
{
}

const StylePoint& ParametresPoint::getStylePoint() const
{
    return _stylePoint;
}

const int& ParametresPoint::getEpaisseurPoint() const
{
    return _epaisseurPoint;
}

const QRgb& ParametresPoint::getCouleurPoint() const
{
    return _couleurPoint;
}

void ParametresPoint::setStylePoint(const StylePoint& stylePoint)
{
    _stylePoint = stylePoint;
}

void ParametresPoint::setEpaisseurPoint(const int& epaisseurPoint)
{
    _epaisseurPoint = epaisseurPoint;
}

void ParametresPoint::setCouleurPoint(const QRgb& couleurPoint)
{
    _couleurPoint = couleurPoint;
}

void ParametresPoint::clear()
{
    *this = ParametresPoint();
}

void ParametresPoint::set(const StylePoint& stylePoint, const int& epaisseurPoint,
        const QRgb& couleurPoint)
{
    setStylePoint(stylePoint);
    setEpaisseurPoint(epaisseurPoint);
    setCouleurPoint(couleurPoint);
}

void ParametresPoint::fromString(const QString& fromString, const QChar& sep)
{
    const QStringList fromStringList = listeSousElements(fromString, sep);
    setStylePoint(static_cast<StylePoint>(fromStringList.at(0).toInt()));
    setEpaisseurPoint(fromStringList.at(1).toInt());
    setCouleurPoint(QColor(fromStringList.at(2)).rgb());
}

const QString ParametresPoint::toString(const QChar& sep) const
{
    QString toString;
    toString += QString::number(getStylePoint()) + sep;
    toString += QString::number(getEpaisseurPoint()) + sep;
    toString += QColor(getCouleurPoint()).name();
    return toString;
}

const QString ParametresPoint::getStylePointTexte() const
{
    return _stylePointTexte.value(getStylePoint());
}

void ParametresPoint::setStylePointTexte(const QString& stylePointTexte)
{
    setStylePoint(_stylePointTexte.key(stylePointTexte));
}
