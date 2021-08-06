//==============================================================================
// Name        : ParametresRecherche.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Source file of the ParametresRecherche class
//==============================================================================

#include "ParametresRecherche.h"
#include "Outils.h"
#include <cmath>
#include <QStringList>

const int ParametresRecherche::seuilToleranceNiveauxDeGrisDefaut = 32;
const int ParametresRecherche::seuilToleranceTeintesSatureesDefaut = 60;
const bool ParametresRecherche::selectionValeursMoyennesDefaut = true;
const bool ParametresRecherche::selectionValeursMinimalesDefaut = false;
const bool ParametresRecherche::selectionValeursMaximalesDefaut = false;

ParametresRecherche::ParametresRecherche() :
        _seuilToleranceNiveauxDeGris(seuilToleranceNiveauxDeGrisDefaut),
                _seuilToleranceTeintesSaturees(seuilToleranceTeintesSatureesDefaut),
                _selectionValeursMoyennes(selectionValeursMoyennesDefaut),
                _selectionValeursMinimales(selectionValeursMinimalesDefaut),
                _selectionValeursMaximales(selectionValeursMaximalesDefaut)
{
    clear();
}

ParametresRecherche::ParametresRecherche(const int& seuilToleranceNiveauxDeGris,
        const int& seuilToleranceTeintesSaturees, const bool& selectionValeursMoyennes,
        const bool& selectionValeursMinimales, const bool& selectionValeursMaximales) :
        ParametresRecherche()
{
    set(seuilToleranceNiveauxDeGris, seuilToleranceTeintesSaturees, selectionValeursMoyennes,
            selectionValeursMinimales, selectionValeursMaximales);
}

ParametresRecherche::ParametresRecherche(const ParametresRecherche& parametresRecherche) :
        ParametresRecherche()
{
    copy(parametresRecherche);
}

ParametresRecherche::~ParametresRecherche()
{
}

ParametresRecherche& ParametresRecherche::operator=(const ParametresRecherche& parametresRecherche)
{
    copy(parametresRecherche);
    return *this;
}

bool ParametresRecherche::operator==(const ParametresRecherche& parametresRecherche) const
{
    return equals(parametresRecherche);
}

bool ParametresRecherche::operator!=(const ParametresRecherche& parametresRecherche) const
{
    return !equals(parametresRecherche);
}

const int& ParametresRecherche::getSeuilToleranceNiveauxDeGris() const
{
    return _seuilToleranceNiveauxDeGris;
}

const int& ParametresRecherche::getSeuilToleranceTeintesSaturees() const
{
    return _seuilToleranceTeintesSaturees;
}

const bool& ParametresRecherche::getSelectionValeursMoyennes() const
{
    return _selectionValeursMoyennes;
}

const bool& ParametresRecherche::getSelectionValeursMinimales() const
{
    return _selectionValeursMinimales;
}

const bool& ParametresRecherche::getSelectionValeursMaximales() const
{
    return _selectionValeursMaximales;
}

void ParametresRecherche::setSeuilToleranceNiveauxDeGris(const int& seuilToleranceNiveauxDeGris)
{
    _seuilToleranceNiveauxDeGris = seuilToleranceNiveauxDeGris;
}

void ParametresRecherche::setSeuilToleranceTeintesSaturees(const int& seuilToleranceTeintesSaturees)
{
    _seuilToleranceTeintesSaturees = seuilToleranceTeintesSaturees;
}

void ParametresRecherche::setSelectionValeursMoyennes(const bool& selectionValeursMoyennes)
{
    _selectionValeursMoyennes = selectionValeursMoyennes;
}

void ParametresRecherche::setSelectionValeursMinimales(const bool& selectionValeursMinimales)
{
    _selectionValeursMinimales = selectionValeursMinimales;
}

void ParametresRecherche::setSelectionValeursMaximales(const bool& selectionValeursMaximales)
{
    _selectionValeursMaximales = selectionValeursMaximales;
}

void ParametresRecherche::clear()
{
    set(seuilToleranceNiveauxDeGrisDefaut, seuilToleranceTeintesSatureesDefaut,
            selectionValeursMoyennesDefaut, selectionValeursMinimalesDefaut,
            selectionValeursMaximalesDefaut);
}

void ParametresRecherche::set(const int& seuilToleranceNiveauxDeGris,
        const int& seuilToleranceTeintesSaturees, const bool& selectionValeursMoyennes,
        const bool& selectionValeursMinimales, const bool& selectionValeursMaximales)
{
    setSeuilToleranceNiveauxDeGris(seuilToleranceNiveauxDeGris);
    setSeuilToleranceTeintesSaturees(seuilToleranceTeintesSaturees);
    setSelectionValeursMoyennes(selectionValeursMoyennes);
    setSelectionValeursMinimales(selectionValeursMinimales);
    setSelectionValeursMaximales(selectionValeursMaximales);
}

void ParametresRecherche::copy(const ParametresRecherche& parametresRecherche)
{
    set(parametresRecherche.getSeuilToleranceNiveauxDeGris(),
            parametresRecherche.getSeuilToleranceTeintesSaturees(),
            parametresRecherche.getSelectionValeursMoyennes(),
            parametresRecherche.getSelectionValeursMinimales(),
            parametresRecherche.getSelectionValeursMaximales());
}

bool ParametresRecherche::equals(const ParametresRecherche& parametresRecherche) const
{
    if (getSeuilToleranceNiveauxDeGris() != parametresRecherche.getSeuilToleranceNiveauxDeGris())
        return false;
    if (getSeuilToleranceTeintesSaturees()
            != parametresRecherche.getSeuilToleranceTeintesSaturees())
        return false;
    if (getSelectionValeursMoyennes() != parametresRecherche.getSelectionValeursMoyennes())
        return false;
    if (getSelectionValeursMinimales() != parametresRecherche.getSelectionValeursMinimales())
        return false;
    if (getSelectionValeursMaximales() != parametresRecherche.getSelectionValeursMaximales())
        return false;
    return true;
}

void ParametresRecherche::fromString(const QString& fromString, const QChar& sep)
{
    const QStringList fromStringList = listeSousElements(fromString, sep);
    setSeuilToleranceNiveauxDeGris(fromStringList.at(0).toInt());
    setSeuilToleranceTeintesSaturees(fromStringList.at(1).toInt());
    setSelectionValeursMoyennes(static_cast<bool>(fromStringList.at(2).toInt()));
    setSelectionValeursMinimales(static_cast<bool>(fromStringList.at(3).toInt()));
    setSelectionValeursMaximales(static_cast<bool>(fromStringList.at(4).toInt()));
}

const QString ParametresRecherche::toString(const QChar& sep) const
{
    QString toString;
    toString += QString::number(getSeuilToleranceNiveauxDeGris()) + sep;
    toString += QString::number(getSeuilToleranceTeintesSaturees()) + sep;
    toString += QString::number(getSelectionValeursMoyennes()) + sep;
    toString += QString::number(getSelectionValeursMinimales()) + sep;
    toString += QString::number(getSelectionValeursMaximales());
    return toString;
}

double ParametresRecherche::getSeuilToleranceNiveauxDeGrisFacteur() const
{
    return (getSeuilToleranceNiveauxDeGris() / 255.0);
}

double ParametresRecherche::getSeuilToleranceTeintesSatureesFacteur() const
{
    return (getSeuilToleranceTeintesSaturees() / 360.0);
}

void ParametresRecherche::setSeuilToleranceNiveauxDeGrisFacteur(
        const double& seuilToleranceNiveauxDeGrisFacteur)
{
    setSeuilToleranceNiveauxDeGris(
            static_cast<int>(round(seuilToleranceNiveauxDeGrisFacteur * 255.0)));
}

void ParametresRecherche::setSeuilToleranceTeintesSatureesFacteur(
        const double& seuilToleranceTeintesSatureesFacteur)
{
    setSeuilToleranceTeintesSaturees(
            static_cast<int>(round(seuilToleranceTeintesSatureesFacteur * 360.0)));
}
