//==============================================================================
// Name        : ParametresConversion.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.3.0 (07/08/2021)
// Description : Source file of the ParametresConversion class
//==============================================================================

#include "ParametresConversion.h"
#include "Outils.h"
#include <cmath>
#include <QStringList>

using MethodeConversion = ParametresConversion::MethodeConversion;

const MethodeConversion ParametresConversion::methodeConversionDefaut;
const int ParametresConversion::seuilNoirEtBlancDefaut;
const int ParametresConversion::nombreNiveauxDeGrisDefaut;
const int ParametresConversion::nombreTeintesSatureesDefaut;
const int ParametresConversion::seuilSaturationDefaut;

const QMap<MethodeConversion, QString> ParametresConversion::_methodeConversionTexte = QMap<
        MethodeConversion, QString>(
        { { BRUTE, QString::fromUtf8("Brute") },
                { NOIR_ET_BLANC, QString::fromUtf8("Noir et blanc") }, { NIVEAUX_DE_GRIS,
                        QString::fromUtf8("Niveaux de gris") }, { TEINTES_SATUREES,
                        QString::fromUtf8("Teintes saturées") } });

ParametresConversion::ParametresConversion(const MethodeConversion& methodeConversion,
        const int& seuilNoirEtBlanc, const int& nombreNiveauxDeGris,
        const int& nombreTeintesSaturees, const int& seuilSaturation) :
        _methodeConversion(methodeConversion), _seuilNoirEtBlanc(seuilNoirEtBlanc),
                _nombreNiveauxDeGris(nombreNiveauxDeGris),
                _nombreTeintesSaturees(nombreTeintesSaturees), _seuilSaturation(seuilSaturation)
{
}

const MethodeConversion& ParametresConversion::getMethodeConversion() const
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

void ParametresConversion::setMethodeConversion(const MethodeConversion& methodeConversion)
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
    *this = ParametresConversion();
}

void ParametresConversion::set(const MethodeConversion& methodeConversion,
        const int& seuilNoirEtBlanc, const int& nombreNiveauxDeGris,
        const int& nombreTeintesSaturees, const int& seuilSaturation)
{
    setMethodeConversion(methodeConversion);
    setSeuilNoirEtBlanc(seuilNoirEtBlanc);
    setNombreNiveauxDeGris(nombreNiveauxDeGris);
    setNombreTeintesSaturees(nombreTeintesSaturees);
    setSeuilSaturation(seuilSaturation);
}

void ParametresConversion::fromString(const QString& fromString, const QChar& sep)
{
    const QStringList fromStringList = listeSousElements(fromString, sep);
    setMethodeConversion(static_cast<MethodeConversion>(fromStringList.at(0).toInt()));
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
    return _methodeConversionTexte.value(getMethodeConversion());
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
    setMethodeConversion(_methodeConversionTexte.key(methodeConversionTexte));
}

void ParametresConversion::setSeuilNoirEtBlancFacteur(const double& seuilNoirEtBlancFacteur)
{
    setSeuilNoirEtBlanc(static_cast<int>(round(seuilNoirEtBlancFacteur * 255.0)));
}

void ParametresConversion::setSeuilSaturationFacteur(const double& seuilSaturationFacteur)
{
    setSeuilSaturation(static_cast<int>(round(seuilSaturationFacteur * 255.0)));
}
