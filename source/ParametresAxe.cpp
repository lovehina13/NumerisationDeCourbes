//==============================================================================
// Name        : ParametresAxe.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.3.0 (07/08/2021)
// Description : Source file of the ParametresAxe class
//==============================================================================

#include "ParametresAxe.h"
#include "Outils.h"
#include <QStringList>
#ifdef ENABLE_QWT
#include <qwt_scale_engine.h>
#endif

constexpr double ParametresAxe::borneInferieureDefaut;
constexpr double ParametresAxe::borneSuperieureDefaut;
constexpr double ParametresAxe::pasPrincipalDefaut;
constexpr double ParametresAxe::pasSecondaireDefaut;
const bool ParametresAxe::grillePrincipaleDefaut;
const bool ParametresAxe::grilleSecondaireDefaut;
const int ParametresAxe::nombreElementsPasPrincipalDefaut;
const int ParametresAxe::nombreElementsPasSecondaireDefaut;

ParametresAxe::ParametresAxe(const double& borneInferieure, const double& borneSuperieure,
        const double& pasPrincipal, const double& pasSecondaire, const bool& grillePrincipale,
        const bool& grilleSecondaire) :
        _borneInferieure(borneInferieure), _borneSuperieure(borneSuperieure),
                _pasPrincipal(pasPrincipal), _pasSecondaire(pasSecondaire),
                _grillePrincipale(grillePrincipale), _grilleSecondaire(grilleSecondaire)
{
}

const double& ParametresAxe::getBorneInferieure() const
{
    return _borneInferieure;
}

const double& ParametresAxe::getBorneSuperieure() const
{
    return _borneSuperieure;
}

const double& ParametresAxe::getPasPrincipal() const
{
    return _pasPrincipal;
}

const double& ParametresAxe::getPasSecondaire() const
{
    return _pasSecondaire;
}

const bool& ParametresAxe::getGrillePrincipale() const
{
    return _grillePrincipale;
}

const bool& ParametresAxe::getGrilleSecondaire() const
{
    return _grilleSecondaire;
}

void ParametresAxe::setBorneInferieure(const double& borneInferieure)
{
    _borneInferieure = borneInferieure;
}

void ParametresAxe::setBorneSuperieure(const double& borneSuperieure)
{
    _borneSuperieure = borneSuperieure;
}

void ParametresAxe::setPasPrincipal(const double& pasPrincipal)
{
    _pasPrincipal = pasPrincipal;
}

void ParametresAxe::setPasSecondaire(const double& pasSecondaire)
{
    _pasSecondaire = pasSecondaire;
}

void ParametresAxe::setGrillePrincipale(const bool& grillePrincipale)
{
    _grillePrincipale = grillePrincipale;
}

void ParametresAxe::setGrilleSecondaire(const bool& grilleSecondaire)
{
    _grilleSecondaire = grilleSecondaire;
}

void ParametresAxe::clear()
{
    *this = ParametresAxe();
}

void ParametresAxe::set(const double& borneInferieure, const double& borneSuperieure,
        const double& pasPrincipal, const double& pasSecondaire, const bool& grillePrincipale,
        const bool& grilleSecondaire)
{
    setBorneInferieure(borneInferieure);
    setBorneSuperieure(borneSuperieure);
    setPasPrincipal(pasPrincipal);
    setPasSecondaire(pasSecondaire);
    setGrillePrincipale(grillePrincipale);
    setGrilleSecondaire(grilleSecondaire);
}

void ParametresAxe::fromString(const QString& fromString, const QChar& sep)
{
    const QStringList fromStringList = listeSousElements(fromString, sep);
    setBorneInferieure(fromStringList.at(0).toDouble());
    setBorneSuperieure(fromStringList.at(1).toDouble());
    setPasPrincipal(fromStringList.at(2).toDouble());
    setPasSecondaire(fromStringList.at(3).toDouble());
    setPasSecondaire(static_cast<bool>(fromStringList.at(4).toInt()));
    setPasSecondaire(static_cast<bool>(fromStringList.at(5).toInt()));
}

const QString ParametresAxe::toString(const QChar& sep) const
{
    QString toString;
    toString += QString::number(getBorneInferieure()) + sep;
    toString += QString::number(getBorneSuperieure()) + sep;
    toString += QString::number(getPasPrincipal()) + sep;
    toString += QString::number(getPasSecondaire()) + sep;
    toString += QString::number(getGrillePrincipale()) + sep;
    toString += QString::number(getGrilleSecondaire());
    return toString;
}

void ParametresAxe::ajuster()
{
    ajusterBornes();
    ajusterPasPrincipal();
    ajusterPasSecondaire();
}

void ParametresAxe::ajusterBornes()
{
#ifdef ENABLE_QWT
    double borneInferieure = getBorneInferieure();
    double borneSuperieure = getBorneSuperieure();
    double pasPrincipal = getPasPrincipal();
    QwtLinearScaleEngine echelle;
    echelle.autoScale(nombreElementsPasPrincipalDefaut, borneInferieure, borneSuperieure,
            pasPrincipal);
    setBorneInferieure(borneInferieure);
    setBorneSuperieure(borneSuperieure);
#endif
}

void ParametresAxe::ajusterPasPrincipal()
{
#ifdef ENABLE_QWT
    double borneInferieure = getBorneInferieure();
    double borneSuperieure = getBorneSuperieure();
    double pasPrincipal = getPasPrincipal();
    QwtLinearScaleEngine echelle;
    echelle.autoScale(nombreElementsPasPrincipalDefaut, borneInferieure, borneSuperieure,
            pasPrincipal);
    setPasPrincipal(pasPrincipal);
#endif
}

void ParametresAxe::ajusterPasSecondaire()
{
#ifdef ENABLE_QWT
    double borneInferieure = getBorneInferieure();
    double pasPrincipal = getPasPrincipal();
    double pasSecondaire = getPasSecondaire();
    double elementIntermediaire = borneInferieure + pasPrincipal;
    QwtLinearScaleEngine echelle;
    echelle.autoScale(nombreElementsPasSecondaireDefaut, borneInferieure, elementIntermediaire,
            pasSecondaire);
    setPasSecondaire(pasSecondaire);
#endif
}
