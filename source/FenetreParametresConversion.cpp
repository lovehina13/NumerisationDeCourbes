//==============================================================================
// Name        : FenetreParametresConversion.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Source file of the FenetreParametresConversion class
//==============================================================================

#include "FenetreParametresConversion.h"
#include "ui_FenetreParametresConversion.h"
#include <QDialogButtonBox>
#include <QPushButton>

FenetreParametresConversion::FenetreParametresConversion(QWidget* parent) :
        QDialog(parent), _ui(new Ui::FenetreParametresConversion)
{
    _ui->setupUi(this);
    initialiserElementsGraphiques();
    actualiserElementsGraphiques();
}

FenetreParametresConversion::~FenetreParametresConversion()
{
    delete _ui;
}

const ParametresConversion& FenetreParametresConversion::getParametresConversion() const
{
    return _parametresConversion;
}

void FenetreParametresConversion::setParametresConversion(
        const ParametresConversion& parametresConversion)
{
    _parametresConversion = parametresConversion;
}

void FenetreParametresConversion::initialiserElementsGraphiques()
{
    _ui->spinBoxSeuilNoirEtBlanc->setMinimum(0);
    _ui->spinBoxSeuilNoirEtBlanc->setMaximum(255);
    _ui->doubleSpinBoxSeuilNoirEtBlancFacteur->setMinimum(0.0);
    _ui->doubleSpinBoxSeuilNoirEtBlancFacteur->setMaximum(100.0);
    _ui->spinBoxNombreNiveauxDeGris->setMinimum(2);
    _ui->spinBoxNombreNiveauxDeGris->setMaximum(256);
    _ui->spinBoxNombreTeintesSaturees->setMinimum(1);
    _ui->spinBoxNombreTeintesSaturees->setMaximum(360);
    _ui->spinBoxSeuilSaturation->setMinimum(0);
    _ui->spinBoxSeuilSaturation->setMaximum(255);
    _ui->doubleSpinBoxSeuilSaturationFacteur->setMinimum(0.0);
    _ui->doubleSpinBoxSeuilSaturationFacteur->setMaximum(100.0);
    _ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Annuler");
}

void FenetreParametresConversion::actualiserElementsGraphiques()
{
    _ui->spinBoxSeuilNoirEtBlanc->setValue(_parametresConversion.getSeuilNoirEtBlanc());
    _ui->doubleSpinBoxSeuilNoirEtBlancFacteur->setValue(
            _parametresConversion.getSeuilNoirEtBlancFacteur() * 100.0);
    _ui->spinBoxNombreNiveauxDeGris->setValue(_parametresConversion.getNombreNiveauxDeGris());
    _ui->spinBoxNombreTeintesSaturees->setValue(_parametresConversion.getNombreTeintesSaturees());
    _ui->spinBoxSeuilSaturation->setValue(_parametresConversion.getSeuilSaturation());
    _ui->doubleSpinBoxSeuilSaturationFacteur->setValue(
            _parametresConversion.getSeuilSaturationFacteur() * 100.0);
}

void FenetreParametresConversion::on_spinBoxSeuilNoirEtBlanc_valueChanged()
{
    _parametresConversion.setSeuilNoirEtBlanc(_ui->spinBoxSeuilNoirEtBlanc->value());
    _ui->doubleSpinBoxSeuilNoirEtBlancFacteur->blockSignals(true);
    _ui->doubleSpinBoxSeuilNoirEtBlancFacteur->setValue(
            _parametresConversion.getSeuilNoirEtBlancFacteur() * 100.0);
    _ui->doubleSpinBoxSeuilNoirEtBlancFacteur->blockSignals(false);
}

void FenetreParametresConversion::on_doubleSpinBoxSeuilNoirEtBlancFacteur_valueChanged()
{
    _parametresConversion.setSeuilNoirEtBlancFacteur(
            _ui->doubleSpinBoxSeuilNoirEtBlancFacteur->value() / 100.0);
    _ui->spinBoxSeuilNoirEtBlanc->blockSignals(true);
    _ui->spinBoxSeuilNoirEtBlanc->setValue(_parametresConversion.getSeuilNoirEtBlanc());
    _ui->spinBoxSeuilNoirEtBlanc->blockSignals(false);
}

void FenetreParametresConversion::on_spinBoxNombreNiveauxDeGris_valueChanged()
{
    _parametresConversion.setNombreNiveauxDeGris(_ui->spinBoxNombreNiveauxDeGris->value());
}

void FenetreParametresConversion::on_spinBoxNombreTeintesSaturees_valueChanged()
{
    _parametresConversion.setNombreTeintesSaturees(_ui->spinBoxNombreTeintesSaturees->value());
}

void FenetreParametresConversion::on_spinBoxSeuilSaturation_valueChanged()
{
    _parametresConversion.setSeuilSaturation(_ui->spinBoxSeuilSaturation->value());
    _ui->doubleSpinBoxSeuilSaturationFacteur->blockSignals(true);
    _ui->doubleSpinBoxSeuilSaturationFacteur->setValue(
            _parametresConversion.getSeuilSaturationFacteur() * 100.0);
    _ui->doubleSpinBoxSeuilSaturationFacteur->blockSignals(false);
}

void FenetreParametresConversion::on_doubleSpinBoxSeuilSaturationFacteur_valueChanged()
{
    _parametresConversion.setSeuilSaturationFacteur(
            _ui->doubleSpinBoxSeuilSaturationFacteur->value() / 100.0);
    _ui->spinBoxSeuilSaturation->blockSignals(true);
    _ui->spinBoxSeuilSaturation->setValue(_parametresConversion.getSeuilSaturation());
    _ui->spinBoxSeuilSaturation->blockSignals(false);
}
