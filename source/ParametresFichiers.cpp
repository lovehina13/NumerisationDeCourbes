//==============================================================================
// Name        : ParametresFichiers.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Source file of the ParametresFichiers class
//==============================================================================

#include "ParametresFichiers.h"
#include "Outils.h"
#include <QStringList>

ParametresFichiers::ParametresFichiers()
{
    clear();
}

ParametresFichiers::ParametresFichiers(const QString& cheminFichierEtude,
        const QString& cheminFichierImageSource, const QString& cheminFichierImageConvertie,
        const QString& cheminFichierExport, const QString& cheminFichierParametres,
        const QString& cheminFichierGraphique) :
        ParametresFichiers()
{
    set(cheminFichierEtude, cheminFichierImageSource, cheminFichierImageConvertie,
            cheminFichierExport, cheminFichierParametres, cheminFichierGraphique);
}

ParametresFichiers::ParametresFichiers(const ParametresFichiers& parametresFichiers) :
        ParametresFichiers()
{
    copy(parametresFichiers);
}

ParametresFichiers::~ParametresFichiers()
{
}

ParametresFichiers& ParametresFichiers::operator=(const ParametresFichiers& parametresFichiers)
{
    copy(parametresFichiers);
    return *this;
}

bool ParametresFichiers::operator==(const ParametresFichiers& parametresFichiers) const
{
    return equals(parametresFichiers);
}

bool ParametresFichiers::operator!=(const ParametresFichiers& parametresFichiers) const
{
    return !equals(parametresFichiers);
}

const QString& ParametresFichiers::getCheminFichierEtude() const
{
    return _cheminFichierEtude;
}

const QString& ParametresFichiers::getCheminFichierImageSource() const
{
    return _cheminFichierImageSource;
}

const QString& ParametresFichiers::getCheminFichierImageConvertie() const
{
    return _cheminFichierImageConvertie;
}

const QString& ParametresFichiers::getCheminFichierExport() const
{
    return _cheminFichierExport;
}

const QString& ParametresFichiers::getCheminFichierParametres() const
{
    return _cheminFichierParametres;
}

const QString& ParametresFichiers::getCheminFichierGraphique() const
{
    return _cheminFichierGraphique;
}

void ParametresFichiers::setCheminFichierEtude(const QString& cheminFichierEtude)
{
    _cheminFichierEtude = cheminFichierEtude;
}

void ParametresFichiers::setCheminFichierImageSource(const QString& cheminFichierImageSource)
{
    _cheminFichierImageSource = cheminFichierImageSource;
}

void ParametresFichiers::setCheminFichierImageConvertie(const QString& cheminFichierImageConvertie)
{
    _cheminFichierImageConvertie = cheminFichierImageConvertie;
}

void ParametresFichiers::setCheminFichierExport(const QString& cheminFichierExport)
{
    _cheminFichierExport = cheminFichierExport;
}

void ParametresFichiers::setCheminFichierParametres(const QString& cheminFichierParametres)
{
    _cheminFichierParametres = cheminFichierParametres;
}

void ParametresFichiers::setCheminFichierGraphique(const QString& cheminFichierGraphique)
{
    _cheminFichierGraphique = cheminFichierGraphique;
}

void ParametresFichiers::clear()
{
    set(QString(), QString(), QString(), QString(), QString(), QString());
}

void ParametresFichiers::set(const QString& cheminFichierEtude,
        const QString& cheminFichierImageSource, const QString& cheminFichierImageConvertie,
        const QString& cheminFichierExport, const QString& cheminFichierParametres,
        const QString& cheminFichierGraphique)
{
    setCheminFichierEtude(cheminFichierEtude);
    setCheminFichierImageSource(cheminFichierImageSource);
    setCheminFichierImageConvertie(cheminFichierImageConvertie);
    setCheminFichierExport(cheminFichierExport);
    setCheminFichierParametres(cheminFichierParametres);
    setCheminFichierGraphique(cheminFichierGraphique);
}

void ParametresFichiers::copy(const ParametresFichiers& parametresFichiers)
{
    set(parametresFichiers.getCheminFichierEtude(),
            parametresFichiers.getCheminFichierImageSource(),
            parametresFichiers.getCheminFichierImageConvertie(),
            parametresFichiers.getCheminFichierExport(),
            parametresFichiers.getCheminFichierParametres(),
            parametresFichiers.getCheminFichierGraphique());
}

bool ParametresFichiers::equals(const ParametresFichiers& parametresFichiers) const
{
    if (getCheminFichierEtude() != parametresFichiers.getCheminFichierEtude())
        return false;
    if (getCheminFichierImageSource() != parametresFichiers.getCheminFichierImageSource())
        return false;
    if (getCheminFichierImageConvertie() != parametresFichiers.getCheminFichierImageConvertie())
        return false;
    if (getCheminFichierExport() != parametresFichiers.getCheminFichierExport())
        return false;
    if (getCheminFichierParametres() != parametresFichiers.getCheminFichierParametres())
        return false;
    if (getCheminFichierGraphique() != parametresFichiers.getCheminFichierGraphique())
        return false;
    return true;
}

void ParametresFichiers::fromString(const QString& fromString, const QChar& sep)
{
    const QStringList fromStringList = listeSousElements(fromString, sep);
    setCheminFichierEtude(fromStringList.at(0).mid(1, (fromStringList.at(0).count() - 2)));
    setCheminFichierImageSource(fromStringList.at(1).mid(1, (fromStringList.at(1).count() - 2)));
    setCheminFichierImageConvertie(fromStringList.at(2).mid(1, (fromStringList.at(2).count() - 2)));
    setCheminFichierExport(fromStringList.at(3).mid(1, (fromStringList.at(3).count() - 2)));
    setCheminFichierParametres(fromStringList.at(4).mid(1, (fromStringList.at(4).count() - 2)));
    setCheminFichierGraphique(fromStringList.at(5).mid(1, (fromStringList.at(5).count() - 2)));
}

const QString ParametresFichiers::toString(const QChar& sep) const
{
    QString toString;
    toString += "\"" + getCheminFichierEtude() + "\"" + sep;
    toString += "\"" + getCheminFichierImageSource() + "\"" + sep;
    toString += "\"" + getCheminFichierImageConvertie() + "\"" + sep;
    toString += "\"" + getCheminFichierExport() + "\"" + sep;
    toString += "\"" + getCheminFichierParametres() + "\"" + sep;
    toString += "\"" + getCheminFichierGraphique() + "\"";
    return toString;
}
