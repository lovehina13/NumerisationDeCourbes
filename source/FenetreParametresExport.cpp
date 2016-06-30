//==============================================================================
// Name        : FenetreParametresExport.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/06/2016)
// Description : Source file of the FenetreParametresExport class
//==============================================================================

#include "FenetreParametresExport.h"
#include "ui_FenetreParametresExport.h"

FenetreParametresExport::FenetreParametresExport(QWidget* parent) :
        QDialog(parent), ui(new Ui::FenetreParametresExport)
{
    this->ui->setupUi(this);
    this->initialiserElementsGraphiques();
    this->actualiserElementsGraphiques();
}

FenetreParametresExport::~FenetreParametresExport()
{
    delete this->ui;
}

const ParametresExport& FenetreParametresExport::getParametresExport() const
{
    return this->parametresExport;
}

void FenetreParametresExport::setParametresExport(const ParametresExport& parametresExport)
{
    this->parametresExport = parametresExport;
}

void FenetreParametresExport::initialiserElementsGraphiques()
{
    // TODO void FenetreParametresExport::initialiserElementsGraphiques()
}

void FenetreParametresExport::actualiserElementsGraphiques()
{
    // TODO void FenetreParametresExport::actualiserElementsGraphiques()
}
