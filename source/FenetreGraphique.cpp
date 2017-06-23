//==============================================================================
// Name        : FenetreGraphique.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.5 (07/06/2017)
// Description : Source file of the FenetreGraphique class
//==============================================================================

#include "FenetreGraphique.h"
#include "ui_FenetreGraphique.h"
#include <QDialogButtonBox>
#include <QDoubleValidator>
#include <QPushButton>

FenetreGraphique::FenetreGraphique(QWidget* parent) :
        QDialog(parent), ui(new Ui::FenetreGraphique)
{
    this->ui->setupUi(this);
    this->initialiserElementsGraphiques();
    this->actualiserElementsGraphiques();
}

FenetreGraphique::~FenetreGraphique()
{
    delete this->ui;
}

void FenetreGraphique::initialiserElementsGraphiques()
{
    const QDoubleValidator* nombreReel = new QDoubleValidator(this);
    this->ui->lineEditAxeHorizontalBorneInferieure->setValidator(nombreReel);
    this->ui->lineEditAxeHorizontalBorneSuperieure->setValidator(nombreReel);
    this->ui->lineEditAxeHorizontalPasPrincipal->setValidator(nombreReel);
    this->ui->lineEditAxeHorizontalPasSecondaire->setValidator(nombreReel);
    this->ui->lineEditAxeVerticalBorneInferieure->setValidator(nombreReel);
    this->ui->lineEditAxeVerticalBorneSuperieure->setValidator(nombreReel);
    this->ui->lineEditAxeVerticalPasPrincipal->setValidator(nombreReel);
    this->ui->lineEditAxeVerticalPasSecondaire->setValidator(nombreReel);
    this->ui->buttonBox->button(QDialogButtonBox::Save)->setText("Enregistrer");
}

void FenetreGraphique::actualiserElementsGraphiques()
{
    // TODO void FenetreGraphique::actualiserElementsGraphiques()
}
