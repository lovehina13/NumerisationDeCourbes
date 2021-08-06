//==============================================================================
// Name        : ParametresConversion.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Source file of the ParametresConversion class
//==============================================================================

#include "ParametresConversion.h"
#include "Outils.h"
#include <cmath>
#include <QStringList>

const int ParametresConversion::methodeConversionDefaut = BRUTE;
const int ParametresConversion::seuilNoirEtBlancDefaut = 223;
const int ParametresConversion::nombreNiveauxDeGrisDefaut = 5;
const int ParametresConversion::nombreTeintesSatureesDefaut = 6;
const int ParametresConversion::seuilSaturationDefaut = 32;

const QMap<int, QString> ParametresConversion::_methodesConversionTexte =
        QMap<int, QString>(
                std::map<int, QString> { { BRUTE, QString::fromUtf8("Brute") }, { NOIR_ET_BLANC,
                        QString::fromUtf8("Noir et blanc") }, { NIVEAUX_DE_GRIS, QString::fromUtf8(
                        "Niveaux de gris") }, { TEINTES_SATUREES, QString::fromUtf8(
                        "Teintes saturées") } });

ParametresConversion::ParametresConversion() :
        _methodeConversion(methodeConversionDefaut), _seuilNoirEtBlanc(seuilNoirEtBlancDefaut),
                _nombreNiveauxDeGris(nombreNiveauxDeGrisDefaut),
                _nombreTeintesSaturees(nombreTeintesSatureesDefaut),
                _seuilSaturation(seuilSaturationDefaut)
{
    clear();
}

ParametresConversion::ParametresConversion(const int& methodeConversion,
        const int& seuilNoirEtBlanc, const int& nombreNiveauxDeGris,
        const int& nombreTeintesSaturees, const int& seuilSaturation) :
        ParametresConversion()
{
    set(methodeConversion, seuilNoirEtBlanc, nombreNiveauxDeGris, nombreTeintesSaturees,
            seuilSaturation);
}

ParametresConversion::ParametresConversion(const ParametresConversion& parametresConversion) :
        ParametresConversion()
{
    copy(parametresConversion);
}

ParametresConversion::~ParametresConversion()
{
}

ParametresConversion& ParametresConversion::operator=(
        const ParametresConversion& parametresConversion)
{
    copy(parametresConversion);
    return *this;
}

bool ParametresConversion::operator==(const ParametresConversion& parametresConversion) const
{
    return equals(parametresConversion);
}

bool ParametresConversion::operator!=(const ParametresConversion& parametresConversion) const
{
    return !equals(parametresConversion);
}

const int& ParametresConversion::getMethodeConversion() const
{
    return _methodeConversion;
}

const int& ParametresConversion::getSeuilNoirEtBlanc() const
{
    return _seuilNoirEtBlanc;
}

const int& ParametresConversion::getNombreNiveauxDeGris() const
{
    return _nombreNiveauxDeGris;
}

const int& ParametresConversion::getNombreTeintesSaturees() const
{
    return _nombreTeintesSaturees;
}

const int& ParametresConversion::getSeuilSaturation() const
{
    return _seuilSaturation;
}

void ParametresConversion::setMethodeConversion(const int& methodeConversion)
{
    _methodeConversion = methodeConversion;
}

void ParametresConversion::setSeuilNoirEtBlanc(const int& seuilNoirEtBlanc)
{
    _seuilNoirEtBlanc = seuilNoirEtBlanc;
}

void ParametresConversion::setNombreNiveauxDeGris(const int& nombreNiveauxDeGris)
{
    _nombreNiveauxDeGris = nombreNiveauxDeGris;
}

void ParametresConversion::setNombreTeintesSaturees(const int& nombreTeintesSaturees)
{
    _nombreTeintesSaturees = nombreTeintesSaturees;
}

void ParametresConversion::setSeuilSaturation(const int& seuilSaturation)
{
    _seuilSaturation = seuilSaturation;
}

void ParametresConversion::clear()
{
    set(methodeConversionDefaut, seuilNoirEtBlancDefaut, nombreNiveauxDeGrisDefaut,
            nombreTeintesSatureesDefaut, seuilSaturationDefaut);
}

void ParametresConversion::set(const int& methodeConversion, const int& seuilNoirEtBlanc,
        const int& nombreNiveauxDeGris, const int& nombreTeintesSaturees,
        const int& seuilSaturation)
{
    setMethodeConversion(methodeConversion);
    setSeuilNoirEtBlanc(seuilNoirEtBlanc);
    setNombreNiveauxDeGris(nombreNiveauxDeGris);
    setNombreTeintesSaturees(nombreTeintesSaturees);
    setSeuilSaturation(seuilSaturation);
}

void ParametresConversion::copy(const ParametresConversion& parametresConversion)
{
    set(parametresConversion.getMethodeConversion(), parametresConversion.getSeuilNoirEtBlanc(),
            parametresConversion.getNombreNiveauxDeGris(),
            parametresConversion.getNombreTeintesSaturees(),
            parametresConversion.getSeuilSaturation());
}

bool ParametresConversion::equals(const ParametresConversion& parametresConversion) const
{
    if (getMethodeConversion() != parametresConversion.getMethodeConversion())
        return false;
    if (getSeuilNoirEtBlanc() != parametresConversion.getSeuilNoirEtBlanc())
        return false;
    if (getNombreNiveauxDeGris() != parametresConversion.getNombreNiveauxDeGris())
        return false;
    if (getNombreTeintesSaturees() != parametresConversion.getNombreTeintesSaturees())
        return false;
    if (getSeuilSaturation() != parametresConversion.getSeuilSaturation())
        return false;
    return true;
}

void ParametresConversion::fromString(const QString& fromString, const QChar& sep)
{
    const QStringList fromStringList = listeSousElements(fromString, sep);
    setMethodeConversion(fromStringList.at(0).toInt());
    setSeuilNoirEtBlanc(fromStringList.at(1).toInt());
    setNombreNiveauxDeGris(fromStringList.at(2).toInt());
    setNombreTeintesSaturees(fromStringList.at(3).toInt());
    setSeuilSaturation(fromStringList.at(4).toInt());
}

const QString ParametresConversion::toString(const QChar& sep) const
{
    QString toString;
    toString += QString::number(getMethodeConversion()) + sep;
    toString += QString::number(getSeuilNoirEtBlanc()) + sep;
    toString += QString::number(getNombreNiveauxDeGris()) + sep;
    toString += QString::number(getNombreTeintesSaturees()) + sep;
    toString += QString::number(getSeuilSaturation());
    return toString;
}

const QString ParametresConversion::getMethodeConversionTexte() const
{
    return _methodesConversionTexte.value(getMethodeConversion());
}

double ParametresConversion::getSeuilNoirEtBlancFacteur() const
{
    return (getSeuilNoirEtBlanc() / 255.0);
}

double ParametresConversion::getSeuilSaturationFacteur() const
{
    return (getSeuilSaturation() / 255.0);
}

void ParametresConversion::setMethodeConversionTexte(const QString& methodeConversionTexte)
{
    setMethodeConversion(_methodesConversionTexte.key(methodeConversionTexte));
}

void ParametresConversion::setSeuilNoirEtBlancFacteur(const double& seuilNoirEtBlancFacteur)
{
    setSeuilNoirEtBlanc(static_cast<int>(round(seuilNoirEtBlancFacteur * 255.0)));
}

void ParametresConversion::setSeuilSaturationFacteur(const double& seuilSaturationFacteur)
{
    setSeuilSaturation(static_cast<int>(round(seuilSaturationFacteur * 255.0)));
}
