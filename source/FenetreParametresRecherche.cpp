//==============================================================================
// Name        : FenetreParametresRecherche.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/06/2016)
// Description : Source file of the FenetreParametresRecherche class
//==============================================================================

#include "FenetreParametresRecherche.h"
#include "ui_FenetreParametresRecherche.h"

FenetreParametresRecherche::FenetreParametresRecherche(QWidget* parent) :
        QDialog(parent), ui(new Ui::FenetreParametresRecherche)
{
    this->ui->setupUi(this);
    this->initialiserElementsGraphiques();
    this->actualiserElementsGraphiques();
}

FenetreParametresRecherche::~FenetreParametresRecherche()
{
    delete this->ui;
}

const ParametresRecherche& FenetreParametresRecherche::getParametresRecherche() const
{
    return this->parametresRecherche;
}

void FenetreParametresRecherche::setParametresRecherche(
        const ParametresRecherche& parametresRecherche)
{
    this->parametresRecherche = parametresRecherche;
}

void FenetreParametresRecherche::initialiserElementsGraphiques()
{
    // TODO void FenetreParametresRecherche::initialiserElementsGraphiques()
}

void FenetreParametresRecherche::actualiserElementsGraphiques()
{
    // TODO void FenetreParametresRecherche::actualiserElementsGraphiques()
}
