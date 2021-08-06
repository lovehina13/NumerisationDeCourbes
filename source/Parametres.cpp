//==============================================================================
// Name        : Parametres.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Source file of the Parametres class
//==============================================================================

#include "Parametres.h"
#include "Outils.h"
#include <QStringList>

Parametres::Parametres()
{
    clear();
}

Parametres::Parametres(const ParametresFichiers& parametresFichiers,
        const ParametresAffichage& parametresAffichage,
        const ParametresConversion& parametresConversion,
        const ParametresRecherche& parametresRecherche, const ParametresExport& parametresExport) :
        Parametres()
{
    set(parametresFichiers, parametresAffichage, parametresConversion, parametresRecherche,
            parametresExport);
}

Parametres::Parametres(const Parametres& parametres) :
        Parametres()
{
    copy(parametres);
}

Parametres::~Parametres()
{
}

Parametres& Parametres::operator=(const Parametres& parametres)
{
    copy(parametres);
    return *this;
}

bool Parametres::operator==(const Parametres& parametres) const
{
    return equals(parametres);
}

bool Parametres::operator!=(const Parametres& parametres) const
{
    return !equals(parametres);
}

const ParametresFichiers& Parametres::getParametresFichiers() const
{
    return _parametresFichiers;
}

const ParametresAffichage& Parametres::getParametresAffichage() const
{
    return _parametresAffichage;
}

const ParametresConversion& Parametres::getParametresConversion() const
{
    return _parametresConversion;
}

const ParametresRecherche& Parametres::getParametresRecherche() const
{
    return _parametresRecherche;
}

const ParametresExport& Parametres::getParametresExport() const
{
    return _parametresExport;
}

void Parametres::setParametresFichiers(const ParametresFichiers& parametresFichiers)
{
    _parametresFichiers = parametresFichiers;
}

void Parametres::setParametresAffichage(const ParametresAffichage& parametresAffichage)
{
    _parametresAffichage = parametresAffichage;
}

void Parametres::setParametresConversion(const ParametresConversion& parametresConversion)
{
    _parametresConversion = parametresConversion;
}

void Parametres::setParametresRecherche(const ParametresRecherche& parametresRecherche)
{
    _parametresRecherche = parametresRecherche;
}

void Parametres::setParametresExport(const ParametresExport& parametresExport)
{
    _parametresExport = parametresExport;
}

void Parametres::clear()
{
    set(ParametresFichiers(), ParametresAffichage(), ParametresConversion(), ParametresRecherche(),
            ParametresExport());
}

void Parametres::set(const ParametresFichiers& parametresFichiers,
        const ParametresAffichage& parametresAffichage,
        const ParametresConversion& parametresConversion,
        const ParametresRecherche& parametresRecherche, const ParametresExport& parametresExport)
{
    setParametresFichiers(parametresFichiers);
    setParametresAffichage(parametresAffichage);
    setParametresConversion(parametresConversion);
    setParametresRecherche(parametresRecherche);
    setParametresExport(parametresExport);
}

void Parametres::copy(const Parametres& parametres)
{
    set(parametres.getParametresFichiers(), parametres.getParametresAffichage(),
            parametres.getParametresConversion(), parametres.getParametresRecherche(),
            parametres.getParametresExport());
}

bool Parametres::equals(const Parametres& parametres) const
{
    if (!getParametresFichiers().equals(parametres.getParametresFichiers()))
        return false;
    if (!getParametresAffichage().equals(parametres.getParametresAffichage()))
        return false;
    if (!getParametresConversion().equals(parametres.getParametresConversion()))
        return false;
    if (!getParametresRecherche().equals(parametres.getParametresRecherche()))
        return false;
    if (!getParametresExport().equals(parametres.getParametresExport()))
        return false;
    return true;
}

void Parametres::fromString(const QString& fromString, const QChar& sep)
{
    const QStringList fromStringList = listeSousElements(fromString, sep);
    ParametresFichiers parametresFichiers = getParametresFichiers();
    ParametresAffichage parametresAffichage = getParametresAffichage();
    ParametresConversion parametresConversion = getParametresConversion();
    ParametresRecherche parametresRecherche = getParametresRecherche();
    ParametresExport parametresExport = getParametresExport();
    parametresFichiers.fromString(fromStringList.at(0), sep);
    parametresAffichage.fromString(fromStringList.at(1), sep);
    parametresConversion.fromString(fromStringList.at(2), sep);
    parametresRecherche.fromString(fromStringList.at(3), sep);
    parametresExport.fromString(fromStringList.at(4), sep);
    setParametresFichiers(parametresFichiers);
    setParametresAffichage(parametresAffichage);
    setParametresConversion(parametresConversion);
    setParametresRecherche(parametresRecherche);
    setParametresExport(parametresExport);
}

const QString Parametres::toString(const QChar& sep) const
{
    QString toString;
    toString += QString("(%1)").arg(getParametresFichiers().toString(sep)) + sep;
    toString += QString("(%1)").arg(getParametresAffichage().toString(sep)) + sep;
    toString += QString("(%1)").arg(getParametresConversion().toString(sep)) + sep;
    toString += QString("(%1)").arg(getParametresRecherche().toString(sep)) + sep;
    toString += QString("(%1)").arg(getParametresExport().toString(sep));
    return toString;
}
