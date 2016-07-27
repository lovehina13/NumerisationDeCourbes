//==============================================================================
// Name        : ParametresAffichage.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (28/06/2016)
// Description : Source file of the ParametresAffichage class
//==============================================================================

#include "ParametresAffichage.h"

const ParametresTrait ParametresAffichage::parametresAxesDefaut = ParametresTrait(
        (int) ParametresTrait::styleTraitDefaut, (int) ParametresTrait::epaisseurTraitDefaut,
        (QRgb) ParametresTrait::couleurTraitAxeDefaut);
const ParametresTrait ParametresAffichage::parametresCourbesDefaut = ParametresTrait(
        (int) ParametresTrait::styleTraitDefaut, (int) ParametresTrait::epaisseurTraitDefaut,
        (QRgb) ParametresTrait::couleurTraitCourbeDefaut);
const ParametresPoint ParametresAffichage::parametresPointsAxesDefaut = ParametresPoint(
        (int) ParametresPoint::stylePointDefaut, (int) ParametresPoint::epaisseurPointDefaut,
        (QRgb) ParametresPoint::couleurPointAxeDefaut);
const ParametresPoint ParametresAffichage::parametresPointsCourbesDefaut = ParametresPoint(
        (int) ParametresPoint::stylePointDefaut, (int) ParametresPoint::epaisseurPointDefaut,
        (QRgb) ParametresPoint::couleurPointCourbeDefaut);
const ParametresPoint ParametresAffichage::parametresPointsManuelsDefaut = ParametresPoint(
        (int) ParametresPoint::stylePointDefaut, (int) ParametresPoint::epaisseurPointDefaut,
        (QRgb) ParametresPoint::couleurPointManuelDefaut);

ParametresAffichage::ParametresAffichage() :
        formatNotationNombres(formatNotationNombresDefaut),
                nombreChiffresSignificatifs(nombreChiffresSignificatifsDefaut)
{
    this->clear();
}

ParametresAffichage::ParametresAffichage(const int& formatNotationNombres,
        const int& nombreChiffresSignificatifs, const ParametresTrait& parametresAxes,
        const ParametresTrait& parametresCourbes, const ParametresPoint& parametresPointsAxes,
        const ParametresPoint& parametresPointsCourbes,
        const ParametresPoint& parametresPointsManuels) :
        ParametresAffichage()
{
    this->set(formatNotationNombres, nombreChiffresSignificatifs, parametresAxes, parametresCourbes,
            parametresPointsAxes, parametresPointsCourbes, parametresPointsManuels);
}

ParametresAffichage::ParametresAffichage(const ParametresAffichage& parametresAffichage) :
        ParametresAffichage()
{
    this->copy(parametresAffichage);
}

ParametresAffichage::~ParametresAffichage()
{
}

const int& ParametresAffichage::getFormatNotationNombres() const
{
    return this->formatNotationNombres;
}

const int& ParametresAffichage::getNombreChiffresSignificatifs() const
{
    return this->nombreChiffresSignificatifs;
}

const ParametresTrait& ParametresAffichage::getParametresAxes() const
{
    return this->parametresAxes;
}

const ParametresTrait& ParametresAffichage::getParametresCourbes() const
{
    return this->parametresCourbes;
}

const ParametresPoint& ParametresAffichage::getParametresPointsAxes() const
{
    return this->parametresPointsAxes;
}

const ParametresPoint& ParametresAffichage::getParametresPointsCourbes() const
{
    return this->parametresPointsCourbes;
}

const ParametresPoint& ParametresAffichage::getParametresPointsManuels() const
{
    return this->parametresPointsManuels;
}

void ParametresAffichage::setFormatNotationNombres(const int& formatNotationNombres)
{
    this->formatNotationNombres = formatNotationNombres;
}

void ParametresAffichage::setNombreChiffresSignificatifs(const int& nombreChiffresSignificatifs)
{
    this->nombreChiffresSignificatifs = nombreChiffresSignificatifs;
}

void ParametresAffichage::setParametresAxes(const ParametresTrait& parametresAxes)
{
    this->parametresAxes = parametresAxes;
}

void ParametresAffichage::setParametresCourbes(const ParametresTrait& parametresCourbes)
{
    this->parametresCourbes = parametresCourbes;
}

void ParametresAffichage::setParametresPointsAxes(const ParametresPoint& parametresPointsAxes)
{
    this->parametresPointsAxes = parametresPointsAxes;
}

void ParametresAffichage::setParametresPointsCourbes(const ParametresPoint& parametresPointsCourbes)
{
    this->parametresPointsCourbes = parametresPointsCourbes;
}

void ParametresAffichage::setParametresPointsManuels(const ParametresPoint& parametresPointsManuels)
{
    this->parametresPointsManuels = parametresPointsManuels;
}

void ParametresAffichage::clear()
{
    this->set((int) formatNotationNombresDefaut, (int) nombreChiffresSignificatifsDefaut,
            (ParametresTrait) parametresAxesDefaut, (ParametresTrait) parametresCourbesDefaut,
            (ParametresPoint) parametresPointsAxesDefaut,
            (ParametresPoint) parametresPointsCourbesDefaut,
            (ParametresPoint) parametresPointsManuelsDefaut);
}

void ParametresAffichage::set(const int& formatNotationNombres,
        const int& nombreChiffresSignificatifs, const ParametresTrait& parametresAxes,
        const ParametresTrait& parametresCourbes, const ParametresPoint& parametresPointsAxes,
        const ParametresPoint& parametresPointsCourbes,
        const ParametresPoint& parametresPointsManuels)
{
    this->setFormatNotationNombres(formatNotationNombres);
    this->setNombreChiffresSignificatifs(nombreChiffresSignificatifs);
    this->setParametresAxes(parametresAxes);
    this->setParametresCourbes(parametresCourbes);
    this->setParametresPointsAxes(parametresPointsAxes);
    this->setParametresPointsCourbes(parametresPointsCourbes);
    this->setParametresPointsManuels(parametresPointsManuels);
}

void ParametresAffichage::copy(const ParametresAffichage& parametresAffichage)
{
    this->set(parametresAffichage.getFormatNotationNombres(),
            parametresAffichage.getNombreChiffresSignificatifs(),
            parametresAffichage.getParametresAxes(), parametresAffichage.getParametresCourbes(),
            parametresAffichage.getParametresPointsAxes(),
            parametresAffichage.getParametresPointsCourbes(),
            parametresAffichage.getParametresPointsManuels());
}

bool ParametresAffichage::equals(const ParametresAffichage& parametresAffichage) const
{
    if (this->getFormatNotationNombres() != parametresAffichage.getFormatNotationNombres())
        return false;
    if (this->getNombreChiffresSignificatifs()
            != parametresAffichage.getNombreChiffresSignificatifs())
        return false;
    if (!this->getParametresAxes().equals(parametresAffichage.getParametresAxes()))
        return false;
    if (!this->getParametresCourbes().equals(parametresAffichage.getParametresCourbes()))
        return false;
    if (!this->getParametresPointsAxes().equals(parametresAffichage.getParametresPointsAxes()))
        return false;
    if (!this->getParametresPointsCourbes().equals(
            parametresAffichage.getParametresPointsCourbes()))
        return false;
    if (!this->getParametresPointsManuels().equals(
            parametresAffichage.getParametresPointsManuels()))
        return false;
    return true;
}

void ParametresAffichage::fromString(const QString& fromString, const char& sep)
{
    // TODO void ParametresAffichage::fromString(const QString& fromString, const char& sep)
    Q_UNUSED(fromString);
    Q_UNUSED(sep);
}

const QString ParametresAffichage::toString(const char& sep) const
{
    QString toString;
    toString += QString::number(this->getFormatNotationNombres()) + sep;
    toString += QString::number(this->getNombreChiffresSignificatifs()) + sep;
    toString += "(" + this->getParametresAxes().toString(sep) + ")" + sep;
    toString += "(" + this->getParametresCourbes().toString(sep) + ")" + sep;
    toString += "(" + this->getParametresPointsAxes().toString(sep) + ")" + sep;
    toString += "(" + this->getParametresPointsCourbes().toString(sep) + ")" + sep;
    toString += "(" + this->getParametresPointsManuels().toString(sep) + ")";
    return toString;
}

