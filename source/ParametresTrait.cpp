//==============================================================================
// Name        : ParametresTrait.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Source file of the ParametresTrait class
//==============================================================================

#include "ParametresTrait.h"
#include "Outils.h"
#include <QColor>
#include <QStringList>

using StyleTrait = ParametresTrait::StyleTrait;

const StyleTrait ParametresTrait::styleTraitDefaut;
const int ParametresTrait::epaisseurTraitDefaut;
const QRgb ParametresTrait::couleurTraitDefaut;
const QRgb ParametresTrait::couleurTraitAxeDefaut;
const QRgb ParametresTrait::couleurTraitCourbeDefaut;

const QMap<StyleTrait, QString> ParametresTrait::_styleTraitTexte = QMap<StyleTrait, QString>( { {
        LIGNE, QString::fromUtf8("Ligne") }, { TIRETS, QString::fromUtf8("Tirets") }, { POINTILLES,
        QString::fromUtf8("Pointillés") } });

ParametresTrait::ParametresTrait(const StyleTrait& styleTrait, const int& epaisseurTrait,
        const QRgb& couleurTrait) :
        _styleTrait(styleTrait), _epaisseurTrait(epaisseurTrait), _couleurTrait(couleurTrait)
{
}

const StyleTrait& ParametresTrait::getStyleTrait() const
{
    return _styleTrait;
}

const int& ParametresTrait::getEpaisseurTrait() const
{
    return _epaisseurTrait;
}

const QRgb& ParametresTrait::getCouleurTrait() const
{
    return _couleurTrait;
}

void ParametresTrait::setStyleTrait(const StyleTrait& styleTrait)
{
    _styleTrait = styleTrait;
}

void ParametresTrait::setEpaisseurTrait(const int& epaisseurTrait)
{
    _epaisseurTrait = epaisseurTrait;
}

void ParametresTrait::setCouleurTrait(const QRgb& couleurTrait)
{
    _couleurTrait = couleurTrait;
}

void ParametresTrait::clear()
{
    *this = ParametresTrait();
}

void ParametresTrait::set(const StyleTrait& styleTrait, const int& epaisseurTrait,
        const QRgb& couleurTrait)
{
    setStyleTrait(styleTrait);
    setEpaisseurTrait(epaisseurTrait);
    setCouleurTrait(couleurTrait);
}

void ParametresTrait::fromString(const QString& fromString, const QChar& sep)
{
    const QStringList fromStringList = listeSousElements(fromString, sep);
    setStyleTrait(static_cast<StyleTrait>(fromStringList.at(0).toInt()));
    setEpaisseurTrait(fromStringList.at(1).toInt());
    setCouleurTrait(QColor(fromStringList.at(2)).rgb());
}

const QString ParametresTrait::toString(const QChar& sep) const
{
    QString toString;
    toString += QString::number(getStyleTrait()) + sep;
    toString += QString::number(getEpaisseurTrait()) + sep;
    toString += QColor(getCouleurTrait()).name();
    return toString;
}

const QString ParametresTrait::getStyleTraitTexte() const
{
    return _styleTraitTexte.value(getStyleTrait());
}

void ParametresTrait::setStyleTraitTexte(const QString& styleTraitTexte)
{
    setStyleTrait(_styleTraitTexte.key(styleTraitTexte));
}
