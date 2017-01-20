//==============================================================================
// Name        : ParametresFichiers.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (20/01/2017)
// Description : Source file of the ParametresFichiers class
//==============================================================================

#include "ParametresFichiers.h"
#include "Outils.h"
#include <QStringList>

ParametresFichiers::ParametresFichiers()
{
    this->clear();
}

ParametresFichiers::ParametresFichiers(const QString& cheminFichierEtude,
        const QString& cheminFichierImageSource, const QString& cheminFichierImageConvertie,
        const QString& cheminFichierExport) :
        ParametresFichiers()
{
    this->set(cheminFichierEtude, cheminFichierImageSource, cheminFichierImageConvertie,
            cheminFichierExport);
}

ParametresFichiers::ParametresFichiers(const ParametresFichiers& parametresFichiers) :
        ParametresFichiers()
{
    this->copy(parametresFichiers);
}

ParametresFichiers::~ParametresFichiers()
{
}

const QString& ParametresFichiers::getCheminFichierEtude() const
{
    return this->cheminFichierEtude;
}

const QString& ParametresFichiers::getCheminFichierImageSource() const
{
    return this->cheminFichierImageSource;
}

const QString& ParametresFichiers::getCheminFichierImageConvertie() const
{
    return this->cheminFichierImageConvertie;
}

const QString& ParametresFichiers::getCheminFichierExport() const
{
    return this->cheminFichierExport;
}

void ParametresFichiers::setCheminFichierEtude(const QString& cheminFichierEtude)
{
    this->cheminFichierEtude = cheminFichierEtude;
}

void ParametresFichiers::setCheminFichierImageSource(const QString& cheminFichierImageSource)
{
    this->cheminFichierImageSource = cheminFichierImageSource;
}

void ParametresFichiers::setCheminFichierImageConvertie(const QString& cheminFichierImageConvertie)
{
    this->cheminFichierImageConvertie = cheminFichierImageConvertie;
}

void ParametresFichiers::setCheminFichierExport(const QString& cheminFichierExport)
{
    this->cheminFichierExport = cheminFichierExport;
}

void ParametresFichiers::clear()
{
    this->set(QString(), QString(), QString(), QString());
}

void ParametresFichiers::set(const QString& cheminFichierEtude,
        const QString& cheminFichierImageSource, const QString& cheminFichierImageConvertie,
        const QString& cheminFichierExport)
{
    this->setCheminFichierEtude(cheminFichierEtude);
    this->setCheminFichierImageSource(cheminFichierImageSource);
    this->setCheminFichierImageConvertie(cheminFichierImageConvertie);
    this->setCheminFichierExport(cheminFichierExport);
}

void ParametresFichiers::copy(const ParametresFichiers& parametresFichiers)
{
    this->set(parametresFichiers.getCheminFichierEtude(),
            parametresFichiers.getCheminFichierImageSource(),
            parametresFichiers.getCheminFichierImageConvertie(),
            parametresFichiers.getCheminFichierExport());
}

bool ParametresFichiers::equals(const ParametresFichiers& parametresFichiers) const
{
    if (this->getCheminFichierEtude() != parametresFichiers.getCheminFichierEtude())
        return false;
    if (this->getCheminFichierImageSource() != parametresFichiers.getCheminFichierImageSource())
        return false;
    if (this->getCheminFichierImageConvertie()
            != parametresFichiers.getCheminFichierImageConvertie())
        return false;
    if (this->getCheminFichierExport() != parametresFichiers.getCheminFichierExport())
        return false;
    return true;
}

void ParametresFichiers::fromString(const QString& fromString, const char& sep)
{
    const QStringList fromStringList = listeSousElements(fromString, sep);
    this->setCheminFichierEtude(fromStringList.at(0).mid(1, (fromStringList.at(0).count() - 2)));
    this->setCheminFichierImageSource(
            fromStringList.at(1).mid(1, (fromStringList.at(1).count() - 2)));
    this->setCheminFichierImageConvertie(
            fromStringList.at(2).mid(1, (fromStringList.at(2).count() - 2)));
    this->setCheminFichierExport(fromStringList.at(3).mid(1, (fromStringList.at(3).count() - 2)));
}

const QString ParametresFichiers::toString(const char& sep) const
{
    QString toString;
    toString += "\"" + this->getCheminFichierEtude() + "\"" + sep;
    toString += "\"" + this->getCheminFichierImageSource() + "\"" + sep;
    toString += "\"" + this->getCheminFichierImageConvertie() + "\"" + sep;
    toString += "\"" + this->getCheminFichierExport() + "\"";
    return toString;
}
