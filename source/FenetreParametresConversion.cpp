//==============================================================================
// Name        : FenetreParametresConversion.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/06/2016)
// Description : Source file of the FenetreParametresConversion class
//==============================================================================

#include "FenetreParametresConversion.h"
#include "ui_FenetreParametresConversion.h"

FenetreParametresConversion::FenetreParametresConversion(QWidget* parent) :
        QDialog(parent), ui(new Ui::FenetreParametresConversion)
{
    this->ui->setupUi(this);
    this->initialiserElementsGraphiques();
    this->actualiserElementsGraphiques();
}

FenetreParametresConversion::~FenetreParametresConversion()
{
    delete this->ui;
}

const ParametresConversion& FenetreParametresConversion::getParametresConversion() const
{
    return this->parametresConversion;
}

void FenetreParametresConversion::setParametresConversion(
        const ParametresConversion& parametresConversion)
{
    this->parametresConversion = parametresConversion;
}

void FenetreParametresConversion::initialiserElementsGraphiques()
{
    // TODO void FenetreParametresConversion::initialiserElementsGraphiques()
}

void FenetreParametresConversion::actualiserElementsGraphiques()
{
    // TODO void FenetreParametresConversion::actualiserElementsGraphiques()
}
