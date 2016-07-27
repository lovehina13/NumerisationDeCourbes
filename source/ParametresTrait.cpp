//==============================================================================
// Name        : ParametresTrait.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (28/06/2016)
// Description : Source file of the ParametresTrait class
//==============================================================================

#include "ParametresTrait.h"
#include <QColor>

const QRgb ParametresTrait::couleurTraitDefaut = QColor(Qt::black).rgb();
const QRgb ParametresTrait::couleurTraitAxeDefaut = QColor(Qt::red).rgb();
const QRgb ParametresTrait::couleurTraitCourbeDefaut = QColor(Qt::blue).rgb();

ParametresTrait::ParametresTrait() :
        styleTrait(styleTraitDefaut), epaisseurTrait(epaisseurTraitDefaut),
                couleurTrait(couleurTraitDefaut)
{
    this->clear();
}

ParametresTrait::ParametresTrait(const int& styleTrait, const int& epaisseurTrait,
        const QRgb& couleurTrait) :
        ParametresTrait()
{
    this->set(styleTrait, epaisseurTrait, couleurTrait);
}

ParametresTrait::ParametresTrait(const ParametresTrait& parametresTrait) :
        ParametresTrait()
{
    this->copy(parametresTrait);
}

ParametresTrait::~ParametresTrait()
{
}

const int& ParametresTrait::getStyleTrait() const
{
    return this->styleTrait;
}

const int& ParametresTrait::getEpaisseurTrait() const
{
    return this->epaisseurTrait;
}

const QRgb& ParametresTrait::getCouleurTrait() const
{
    return this->couleurTrait;
}

void ParametresTrait::setStyleTrait(const int& styleTrait)
{
    this->styleTrait = styleTrait;
}

void ParametresTrait::setEpaisseurTrait(const int& epaisseurTrait)
{
    this->epaisseurTrait = epaisseurTrait;
}

void ParametresTrait::setCouleurTrait(const QRgb& couleurTrait)
{
    this->couleurTrait = couleurTrait;
}

void ParametresTrait::clear()
{
    this->set((int) styleTraitDefaut, (int) epaisseurTraitDefaut, (QRgb) couleurTraitDefaut);
}

void ParametresTrait::set(const int& styleTrait, const int& epaisseurTrait,
        const QRgb& couleurTrait)
{
    this->setStyleTrait(styleTrait);
    this->setEpaisseurTrait(epaisseurTrait);
    this->setCouleurTrait(couleurTrait);
}

void ParametresTrait::copy(const ParametresTrait& parametresTrait)
{
    this->set(parametresTrait.getStyleTrait(), parametresTrait.getEpaisseurTrait(),
            parametresTrait.getCouleurTrait());
}

bool ParametresTrait::equals(const ParametresTrait& parametresTrait) const
{
    if (this->getStyleTrait() != parametresTrait.getStyleTrait())
        return false;
    if (this->getEpaisseurTrait() != parametresTrait.getEpaisseurTrait())
        return false;
    if (this->getCouleurTrait() != parametresTrait.getCouleurTrait())
        return false;
    return true;
}

void ParametresTrait::fromString(const QString& fromString, const char& sep)
{
    // TODO void ParametresTrait::fromString(const QString& fromString, const char& sep)
    Q_UNUSED(fromString);
    Q_UNUSED(sep);
}

const QString ParametresTrait::toString(const char& sep) const
{
    QString toString;
    toString += QString::number(this->getStyleTrait()) + sep;
    toString += QString::number(this->getEpaisseurTrait()) + sep;
    toString += QColor::fromRgb(this->getCouleurTrait()).name();
    return toString;
}
