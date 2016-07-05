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
    this->ui->spinBoxSeuilNoirEtBlanc->setMinimum(0);
    this->ui->spinBoxSeuilNoirEtBlanc->setMaximum(100);
    this->ui->spinBoxNombreNiveauxDeGris->setMinimum(2);
    this->ui->spinBoxNombreNiveauxDeGris->setMaximum(256);
    this->ui->spinBoxNombreTeintesSaturees->setMinimum(1);
    this->ui->spinBoxNombreTeintesSaturees->setMaximum(360);
    this->ui->spinBoxSeuilSaturation->setMinimum(0);
    this->ui->spinBoxSeuilSaturation->setMaximum(100);
}

void FenetreParametresConversion::actualiserElementsGraphiques()
{
    this->ui->spinBoxSeuilNoirEtBlanc->setValue(this->parametresConversion.getSeuilNoirEtBlanc());
    this->ui->spinBoxNombreNiveauxDeGris->setValue(
            this->parametresConversion.getNombreNiveauxDeGris());
    this->ui->spinBoxNombreTeintesSaturees->setValue(
            this->parametresConversion.getNombreTeintesSaturees());
    this->ui->spinBoxSeuilSaturation->setValue(this->parametresConversion.getSeuilSaturation());
}

void FenetreParametresConversion::on_spinBoxSeuilNoirEtBlanc_valueChanged()
{
    this->parametresConversion.setSeuilNoirEtBlanc(this->ui->spinBoxSeuilNoirEtBlanc->value());
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

void FenetreParametresConversion::on_spinBoxSeuilSaturation_valueChanged()
{
    this->parametresConversion.setSeuilSaturation(this->ui->spinBoxSeuilSaturation->value());
}
