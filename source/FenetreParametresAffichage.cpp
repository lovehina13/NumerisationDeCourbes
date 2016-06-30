//==============================================================================
// Name        : FenetreParametresAffichage.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/06/2016)
// Description : Source file of the FenetreParametresAffichage class
//==============================================================================

#include "FenetreParametresAffichage.h"
#include "ui_FenetreParametresAffichage.h"

FenetreParametresAffichage::FenetreParametresAffichage(QWidget* parent) :
        QDialog(parent), ui(new Ui::FenetreParametresAffichage)
{
    this->ui->setupUi(this);
    this->initialiserElementsGraphiques();
    this->actualiserElementsGraphiques();
}

FenetreParametresAffichage::~FenetreParametresAffichage()
{
    delete this->ui;
}

const ParametresAffichage& FenetreParametresAffichage::getParametresAffichage() const
{
    return this->parametresAffichage;
}

void FenetreParametresAffichage::setParametresAffichage(
        const ParametresAffichage& parametresAffichage)
{
    this->parametresAffichage = parametresAffichage;
}

void FenetreParametresAffichage::initialiserElementsGraphiques()
{
    // TODO void FenetreParametresAffichage::initialiserElementsGraphiques()
}

void FenetreParametresAffichage::actualiserElementsGraphiques()
{
    // TODO void FenetreParametresAffichage::actualiserElementsGraphiques()
}
