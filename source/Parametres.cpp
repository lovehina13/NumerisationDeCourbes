//==============================================================================
// Name        : Parametres.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.3.0 (07/08/2021)
// Description : Source file of the Parametres class
//==============================================================================

#include "Parametres.h"
#include "Outils.h"
#include <QStringList>

Parametres::Parametres(const ParametresFichiers& parametresFichiers,
        const ParametresAffichage& parametresAffichage,
        const ParametresConversion& parametresConversion,
        const ParametresRecherche& parametresRecherche, const ParametresExport& parametresExport) :
        _parametresFichiers(parametresFichiers), _parametresAffichage(parametresAffichage),
                _parametresConversion(parametresConversion),
                _parametresRecherche(parametresRecherche), _parametresExport(parametresExport)
{
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
    *this = Parametres();
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
