//==============================================================================
// Name        : ParametresAxe.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.5 (07/06/2017)
// Description : Source file of the ParametresAxe class
//==============================================================================

#include "ParametresAxe.h"
#include "Outils.h"
#include <QStringList>

const double ParametresAxe::borneInferieureDefaut = 0.0;
const double ParametresAxe::borneSuperieureDefaut = 0.0;
const double ParametresAxe::pasPrincipalDefaut = 0.0;
const double ParametresAxe::pasSecondaireDefaut = 0.0;

ParametresAxe::ParametresAxe() :
        borneInferieure(borneInferieureDefaut), borneSuperieure(borneSuperieureDefaut),
                pasPrincipal(pasPrincipalDefaut), pasSecondaire(pasSecondaireDefaut)
{
    this->clear();
}

ParametresAxe::ParametresAxe(const double& borneInferieure, const double& borneSuperieure,
        const double& pasPrincipal, const double& pasSecondaire) :
        ParametresAxe()
{
    this->set(borneInferieure, borneSuperieure, pasPrincipal, pasSecondaire);
}

ParametresAxe::ParametresAxe(const ParametresAxe& parametresAxe) :
        ParametresAxe()
{
    this->copy(parametresAxe);
}

ParametresAxe::~ParametresAxe()
{
}

const double& ParametresAxe::getBorneInferieure() const
{
    return this->borneInferieure;
}

const double& ParametresAxe::getBorneSuperieure() const
{
    return this->borneSuperieure;
}

const double& ParametresAxe::getPasPrincipal() const
{
    return this->pasPrincipal;
}

const double& ParametresAxe::getPasSecondaire() const
{
    return this->pasSecondaire;
}

void ParametresAxe::setBorneInferieure(const double& borneInferieure)
{
    this->borneInferieure = borneInferieure;
}

void ParametresAxe::setBorneSuperieure(const double& borneSuperieure)
{
    this->borneSuperieure = borneSuperieure;
}

void ParametresAxe::setPasPrincipal(const double& pasPrincipal)
{
    this->pasPrincipal = pasPrincipal;
}

void ParametresAxe::setPasSecondaire(const double& pasSecondaire)
{
    this->pasSecondaire = pasSecondaire;
}

void ParametresAxe::clear()
{
    this->set(borneInferieureDefaut, borneSuperieureDefaut, pasPrincipalDefaut,
            pasSecondaireDefaut);
}

void ParametresAxe::set(const double& borneInferieure, const double& borneSuperieure,
        const double& pasPrincipal, const double& pasSecondaire)
{
    this->setBorneInferieure(borneInferieure);
    this->setBorneSuperieure(borneSuperieure);
    this->setPasPrincipal(pasPrincipal);
    this->setPasSecondaire(pasSecondaire);
}

void ParametresAxe::copy(const ParametresAxe& parametresAxe)
{
    this->set(parametresAxe.getBorneInferieure(), parametresAxe.getBorneSuperieure(),
            parametresAxe.getPasPrincipal(), parametresAxe.getPasSecondaire());
}

bool ParametresAxe::equals(const ParametresAxe& parametresAxe) const
{
    if (this->getBorneInferieure() != parametresAxe.getBorneInferieure())
        return false;
    if (this->getBorneSuperieure() != parametresAxe.getBorneSuperieure())
        return false;
    if (this->getPasPrincipal() != parametresAxe.getPasPrincipal())
        return false;
    if (this->getPasSecondaire() != parametresAxe.getPasSecondaire())
        return false;
    return true;
}

void ParametresAxe::fromString(const QString& fromString, const char& sep)
{
    const QStringList fromStringList = listeSousElements(fromString, sep);
    this->setBorneInferieure(fromStringList.at(0).toDouble());
    this->setBorneSuperieure(fromStringList.at(1).toDouble());
    this->setPasPrincipal(fromStringList.at(2).toDouble());
    this->setPasSecondaire(fromStringList.at(3).toDouble());
}

const QString ParametresAxe::toString(const char& sep) const
{
    QString toString;
    toString += QString::number(this->getBorneInferieure()) + sep;
    toString += QString::number(this->getBorneSuperieure()) + sep;
    toString += QString::number(this->getPasPrincipal()) + sep;
    toString += QString::number(this->getPasSecondaire());
    return toString;
}
