//==============================================================================
// Name        : ParametresRecherche.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (28/06/2016)
// Description : Source file of the ParametresRecherche class
//==============================================================================

#include "ParametresRecherche.h"

ParametresRecherche::ParametresRecherche() :
        seuilToleranceNiveauxDeGris(seuilToleranceNiveauxDeGrisDefaut),
                seuilToleranceTeintesSaturees(seuilToleranceTeintesSatureesDefaut),
                selectionValeursMoyennes(selectionValeursMoyennesDefaut),
                selectionValeursMinimales(selectionValeursMinimalesDefaut),
                selectionValeursMaximales(selectionValeursMaximalesDefaut)
{
    this->clear();
}

ParametresRecherche::ParametresRecherche(const int& seuilToleranceNiveauxDeGris,
        const int& seuilToleranceTeintesSaturees, const bool& selectionValeursMoyennes,
        const bool& selectionValeursMinimales, const bool& selectionValeursMaximales) :
        ParametresRecherche()
{
    this->set(seuilToleranceNiveauxDeGris, seuilToleranceTeintesSaturees, selectionValeursMoyennes,
            selectionValeursMinimales, selectionValeursMaximales);
}

ParametresRecherche::ParametresRecherche(const ParametresRecherche& parametresRecherche) :
        ParametresRecherche()
{
    this->copy(parametresRecherche);
}

ParametresRecherche::~ParametresRecherche()
{
}

const int& ParametresRecherche::getSeuilToleranceNiveauxDeGris() const
{
    return this->seuilToleranceNiveauxDeGris;
}

const int& ParametresRecherche::getSeuilToleranceTeintesSaturees() const
{
    return this->seuilToleranceTeintesSaturees;
}

const bool& ParametresRecherche::getSelectionValeursMoyennes() const
{
    return this->selectionValeursMoyennes;
}

const bool& ParametresRecherche::getSelectionValeursMinimales() const
{
    return this->selectionValeursMinimales;
}

const bool& ParametresRecherche::getSelectionValeursMaximales() const
{
    return this->selectionValeursMaximales;
}

void ParametresRecherche::setSeuilToleranceNiveauxDeGris(const int& seuilToleranceNiveauxDeGris)
{
    this->seuilToleranceNiveauxDeGris = seuilToleranceNiveauxDeGris;
}

void ParametresRecherche::setSeuilToleranceTeintesSaturees(const int& seuilToleranceTeintesSaturees)
{
    this->seuilToleranceTeintesSaturees = seuilToleranceTeintesSaturees;
}

void ParametresRecherche::setSelectionValeursMoyennes(const bool& selectionValeursMoyennes)
{
    this->selectionValeursMoyennes = selectionValeursMoyennes;
}

void ParametresRecherche::setSelectionValeursMinimales(const bool& selectionValeursMinimales)
{
    this->selectionValeursMinimales = selectionValeursMinimales;
}

void ParametresRecherche::setSelectionValeursMaximales(const bool& selectionValeursMaximales)
{
    this->selectionValeursMaximales = selectionValeursMaximales;
}

void ParametresRecherche::clear()
{
    this->set((int) seuilToleranceNiveauxDeGrisDefaut, (int) seuilToleranceTeintesSatureesDefaut,
            (bool) selectionValeursMoyennesDefaut, (bool) selectionValeursMinimalesDefaut,
            (bool) selectionValeursMaximalesDefaut);
}

void ParametresRecherche::set(const int& seuilToleranceNiveauxDeGris,
        const int& seuilToleranceTeintesSaturees, const bool& selectionValeursMoyennes,
        const bool& selectionValeursMinimales, const bool& selectionValeursMaximales)
{
    this->setSeuilToleranceNiveauxDeGris(seuilToleranceNiveauxDeGris);
    this->setSeuilToleranceTeintesSaturees(seuilToleranceTeintesSaturees);
    this->setSelectionValeursMoyennes(selectionValeursMoyennes);
    this->setSelectionValeursMinimales(selectionValeursMinimales);
    this->setSelectionValeursMaximales(selectionValeursMaximales);
}

void ParametresRecherche::copy(const ParametresRecherche& parametresRecherche)
{
    this->set(parametresRecherche.getSeuilToleranceNiveauxDeGris(),
            parametresRecherche.getSeuilToleranceTeintesSaturees(),
            parametresRecherche.getSelectionValeursMoyennes(),
            parametresRecherche.getSelectionValeursMinimales(),
            parametresRecherche.getSelectionValeursMaximales());
}

bool ParametresRecherche::equals(const ParametresRecherche& parametresRecherche) const
{
    if (this->getSeuilToleranceNiveauxDeGris()
            != parametresRecherche.getSeuilToleranceNiveauxDeGris())
        return false;
    if (this->getSeuilToleranceTeintesSaturees()
            != parametresRecherche.getSeuilToleranceTeintesSaturees())
        return false;
    if (this->getSelectionValeursMoyennes() != parametresRecherche.getSelectionValeursMoyennes())
        return false;
    if (this->getSelectionValeursMinimales() != parametresRecherche.getSelectionValeursMinimales())
        return false;
    if (this->getSelectionValeursMaximales() != parametresRecherche.getSelectionValeursMaximales())
        return false;
    return true;
}

void ParametresRecherche::fromString(const QString& fromString, const char& sep)
{
    // TODO void ParametresRecherche::fromString(const QString& fromString, const char& sep)
    Q_UNUSED(fromString);
    Q_UNUSED(sep);
}

const QString ParametresRecherche::toString(const char& sep) const
{
    // TODO const QString ParametresRecherche::toString(const char& sep) const
    Q_UNUSED(sep);
    return QString();
}
