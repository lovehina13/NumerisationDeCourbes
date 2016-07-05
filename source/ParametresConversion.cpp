//==============================================================================
// Name        : ParametresConversion.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (28/06/2016)
// Description : Source file of the ParametresConversion class
//==============================================================================

#include "ParametresConversion.h"
#include <cmath>

ParametresConversion::ParametresConversion() :
        methodeConversion(methodeConversionDefaut), seuilNoirEtBlanc(seuilNoirEtBlancDefaut),
                nombreNiveauxDeGris(nombreNiveauxDeGrisDefaut),
                nombreTeintesSaturees(nombreTeintesSatureesDefaut),
                seuilSaturation(seuilSaturationDefaut)
{
    this->clear();
}

ParametresConversion::ParametresConversion(const int& methodeConversion,
        const int& seuilNoirEtBlanc, const int& nombreNiveauxDeGris,
        const int& nombreTeintesSaturees, const int& seuilSaturation) :
        ParametresConversion()
{
    this->set(methodeConversion, seuilNoirEtBlanc, nombreNiveauxDeGris, nombreTeintesSaturees,
            seuilSaturation);
}

ParametresConversion::ParametresConversion(const ParametresConversion& parametresConversion) :
        ParametresConversion()
{
    this->copy(parametresConversion);
}

ParametresConversion::~ParametresConversion()
{
}

const int& ParametresConversion::getMethodeConversion() const
{
    return this->methodeConversion;
}

const int& ParametresConversion::getSeuilNoirEtBlanc() const
{
    return this->seuilNoirEtBlanc;
}

const int& ParametresConversion::getNombreNiveauxDeGris() const
{
    return this->nombreNiveauxDeGris;
}

const int& ParametresConversion::getNombreTeintesSaturees() const
{
    return this->nombreTeintesSaturees;
}

const int& ParametresConversion::getSeuilSaturation() const
{
    return this->seuilSaturation;
}

void ParametresConversion::setMethodeConversion(const int& methodeConversion)
{
    this->methodeConversion = methodeConversion;
}

void ParametresConversion::setSeuilNoirEtBlanc(const int& seuilNoirEtBlanc)
{
    this->seuilNoirEtBlanc = seuilNoirEtBlanc;
}

void ParametresConversion::setNombreNiveauxDeGris(const int& nombreNiveauxDeGris)
{
    this->nombreNiveauxDeGris = nombreNiveauxDeGris;
}

void ParametresConversion::setNombreTeintesSaturees(const int& nombreTeintesSaturees)
{
    this->nombreTeintesSaturees = nombreTeintesSaturees;
}

void ParametresConversion::setSeuilSaturation(const int& seuilSaturation)
{
    this->seuilSaturation = seuilSaturation;
}

void ParametresConversion::clear()
{
    this->set((int) methodeConversionDefaut, (int) seuilNoirEtBlancDefaut,
            (int) nombreNiveauxDeGrisDefaut, (int) nombreTeintesSatureesDefaut,
            (int) seuilSaturationDefaut);
}

void ParametresConversion::set(const int& methodeConversion, const int& seuilNoirEtBlanc,
        const int& nombreNiveauxDeGris, const int& nombreTeintesSaturees,
        const int& seuilSaturation)
{
    this->setMethodeConversion(methodeConversion);
    this->setSeuilNoirEtBlanc(seuilNoirEtBlanc);
    this->setNombreNiveauxDeGris(nombreNiveauxDeGris);
    this->setNombreTeintesSaturees(nombreTeintesSaturees);
    this->setSeuilSaturation(seuilSaturation);
}

void ParametresConversion::copy(const ParametresConversion& parametresConversion)
{
    this->set(parametresConversion.getMethodeConversion(),
            parametresConversion.getSeuilNoirEtBlanc(),
            parametresConversion.getNombreNiveauxDeGris(),
            parametresConversion.getNombreTeintesSaturees(),
            parametresConversion.getSeuilSaturation());
}

bool ParametresConversion::equals(const ParametresConversion& parametresConversion) const
{
    if (this->getMethodeConversion() != parametresConversion.getMethodeConversion())
        return false;
    if (this->getSeuilNoirEtBlanc() != parametresConversion.getSeuilNoirEtBlanc())
        return false;
    if (this->getNombreNiveauxDeGris() != parametresConversion.getNombreNiveauxDeGris())
        return false;
    if (this->getNombreTeintesSaturees() != parametresConversion.getNombreTeintesSaturees())
        return false;
    if (this->getSeuilSaturation() != parametresConversion.getSeuilSaturation())
        return false;
    return true;
}

void ParametresConversion::fromString(const QString& fromString, const char& sep)
{
    // TODO void ParametresConversion::fromString(const QString& fromString, const char& sep)
    Q_UNUSED(fromString);
    Q_UNUSED(sep);
}

const QString ParametresConversion::toString(const char& sep) const
{
    // TODO const QString ParametresConversion::toString(const char& sep) const
    Q_UNUSED(sep);
    return QString();
}

double ParametresConversion::getSeuilNoirEtBlancFacteur() const
{
    return (this->getSeuilNoirEtBlanc() / 256.0);
}

double ParametresConversion::getSeuilSaturationFacteur() const
{
    return (this->getSeuilSaturation() / 256.0);
}

void ParametresConversion::setSeuilNoirEtBlancFacteur(const double& seuilNoirEtBlancFacteur)
{
    this->setSeuilNoirEtBlanc((int) round(seuilNoirEtBlancFacteur * 256.0));
}

void ParametresConversion::setSeuilSaturationFacteur(const double& seuilSaturationFacteur)
{
    this->setSeuilSaturation((int) round(seuilSaturationFacteur * 256.0));
}
