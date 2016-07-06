//==============================================================================
// Name        : FenetreParametresConversion.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/06/2016)
// Description : Source file of the FenetreParametresConversion class
//==============================================================================

#include "FenetreParametresConversion.h"
#include "ui_FenetreParametresConversion.h"
#include <QDialogButtonBox>
#include <QPushButton>

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
    this->ui->doubleSpinBoxSeuilNoirEtBlanc->setMinimum(0);
    this->ui->doubleSpinBoxSeuilNoirEtBlanc->setMaximum(100);
    this->ui->spinBoxNombreNiveauxDeGris->setMinimum(2);
    this->ui->spinBoxNombreNiveauxDeGris->setMaximum(256);
    this->ui->spinBoxNombreTeintesSaturees->setMinimum(1);
    this->ui->spinBoxNombreTeintesSaturees->setMaximum(360);
    this->ui->doubleSpinBoxSeuilSaturation->setMinimum(0);
    this->ui->doubleSpinBoxSeuilSaturation->setMaximum(100);
    this->ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Annuler");
}

void FenetreParametresConversion::actualiserElementsGraphiques()
{
    this->ui->doubleSpinBoxSeuilNoirEtBlanc->setValue(
            this->parametresConversion.getSeuilNoirEtBlancFacteur() * 100.0);
    this->ui->spinBoxNombreNiveauxDeGris->setValue(
            this->parametresConversion.getNombreNiveauxDeGris());
    this->ui->spinBoxNombreTeintesSaturees->setValue(
            this->parametresConversion.getNombreTeintesSaturees());
    this->ui->doubleSpinBoxSeuilSaturation->setValue(
            this->parametresConversion.getSeuilSaturationFacteur() * 100.0);
}

void FenetreParametresConversion::on_doubleSpinBoxSeuilNoirEtBlanc_valueChanged()
{
    this->parametresConversion.setSeuilNoirEtBlancFacteur(
            this->ui->doubleSpinBoxSeuilNoirEtBlanc->value() / 100.0);
}

void FenetreParametresConversion::on_spinBoxNombreNiveauxDeGris_valueChanged()
{
    this->parametresConversion.setNombreNiveauxDeGris(
            this->ui->spinBoxNombreNiveauxDeGris->value());
}

void FenetreParametresConversion::on_spinBoxNombreTeintesSaturees_valueChanged()
{
    this->parametresConversion.setNombreTeintesSaturees(
            this->ui->spinBoxNombreTeintesSaturees->value());
}

void FenetreParametresConversion::on_doubleSpinBoxSeuilSaturation_valueChanged()
{
    this->parametresConversion.setSeuilSaturationFacteur(
            this->ui->doubleSpinBoxSeuilSaturation->value() / 100.0);
}
