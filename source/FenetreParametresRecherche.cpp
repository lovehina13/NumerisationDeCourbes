//==============================================================================
// Name        : FenetreParametresRecherche.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Source file of the FenetreParametresRecherche class
//==============================================================================

#include "FenetreParametresRecherche.h"
#include "ui_FenetreParametresRecherche.h"
#include <QDialogButtonBox>
#include <QPushButton>

FenetreParametresRecherche::FenetreParametresRecherche(QWidget* parent) :
        QDialog(parent), _ui(new Ui::FenetreParametresRecherche)
{
    _ui->setupUi(this);
    initialiserElementsGraphiques();
    actualiserElementsGraphiques();
}

FenetreParametresRecherche::~FenetreParametresRecherche()
{
    delete _ui;
}

const ParametresRecherche& FenetreParametresRecherche::getParametresRecherche() const
{
    return _parametresRecherche;
}

void FenetreParametresRecherche::setParametresRecherche(
        const ParametresRecherche& parametresRecherche)
{
    _parametresRecherche = parametresRecherche;
}

void FenetreParametresRecherche::initialiserElementsGraphiques()
{
    _ui->spinBoxSeuilToleranceNiveauxDeGris->setMinimum(0);
    _ui->spinBoxSeuilToleranceNiveauxDeGris->setMaximum(255);
    _ui->doubleSpinBoxSeuilToleranceNiveauxDeGrisFacteur->setMinimum(0.0);
    _ui->doubleSpinBoxSeuilToleranceNiveauxDeGrisFacteur->setMaximum(100.0);
    _ui->spinBoxSeuilToleranceTeintesSaturees->setMinimum(0);
    _ui->spinBoxSeuilToleranceTeintesSaturees->setMaximum(360);
    _ui->doubleSpinBoxSeuilToleranceTeintesSatureesFacteur->setMinimum(0.0);
    _ui->doubleSpinBoxSeuilToleranceTeintesSatureesFacteur->setMaximum(100.0);
    _ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Annuler");
}

void FenetreParametresRecherche::actualiserElementsGraphiques()
{
    _ui->spinBoxSeuilToleranceNiveauxDeGris->setValue(
            _parametresRecherche.getSeuilToleranceNiveauxDeGris());
    _ui->doubleSpinBoxSeuilToleranceNiveauxDeGrisFacteur->setValue(
            _parametresRecherche.getSeuilToleranceNiveauxDeGrisFacteur() * 100.0);
    _ui->spinBoxSeuilToleranceTeintesSaturees->setValue(
            _parametresRecherche.getSeuilToleranceTeintesSaturees());
    _ui->doubleSpinBoxSeuilToleranceTeintesSatureesFacteur->setValue(
            _parametresRecherche.getSeuilToleranceTeintesSatureesFacteur() * 100.0);
    _ui->checkBoxSelectionValeursMoyennes->setChecked(
            _parametresRecherche.getSelectionValeursMoyennes());
    _ui->checkBoxSelectionValeursMinimales->setChecked(
            _parametresRecherche.getSelectionValeursMinimales());
    _ui->checkBoxSelectionValeursMaximales->setChecked(
            _parametresRecherche.getSelectionValeursMaximales());
}

void FenetreParametresRecherche::on_spinBoxSeuilToleranceNiveauxDeGris_valueChanged()
{
    _parametresRecherche.setSeuilToleranceNiveauxDeGris(
            _ui->spinBoxSeuilToleranceNiveauxDeGris->value());
    _ui->doubleSpinBoxSeuilToleranceNiveauxDeGrisFacteur->blockSignals(true);
    _ui->doubleSpinBoxSeuilToleranceNiveauxDeGrisFacteur->setValue(
            _parametresRecherche.getSeuilToleranceNiveauxDeGrisFacteur() * 100.0);
    _ui->doubleSpinBoxSeuilToleranceNiveauxDeGrisFacteur->blockSignals(false);
}

void FenetreParametresRecherche::on_doubleSpinBoxSeuilToleranceNiveauxDeGrisFacteur_valueChanged()
{
    _parametresRecherche.setSeuilToleranceNiveauxDeGrisFacteur(
            _ui->doubleSpinBoxSeuilToleranceNiveauxDeGrisFacteur->value() / 100.0);
    _ui->spinBoxSeuilToleranceNiveauxDeGris->blockSignals(true);
    _ui->spinBoxSeuilToleranceNiveauxDeGris->setValue(
            _parametresRecherche.getSeuilToleranceNiveauxDeGris());
    _ui->spinBoxSeuilToleranceNiveauxDeGris->blockSignals(false);
}

void FenetreParametresRecherche::on_spinBoxSeuilToleranceTeintesSaturees_valueChanged()
{
    _parametresRecherche.setSeuilToleranceTeintesSaturees(
            _ui->spinBoxSeuilToleranceTeintesSaturees->value());
    _ui->doubleSpinBoxSeuilToleranceTeintesSatureesFacteur->blockSignals(true);
    _ui->doubleSpinBoxSeuilToleranceTeintesSatureesFacteur->setValue(
            _parametresRecherche.getSeuilToleranceTeintesSatureesFacteur() * 100.0);
    _ui->doubleSpinBoxSeuilToleranceTeintesSatureesFacteur->blockSignals(false);
}

void FenetreParametresRecherche::on_doubleSpinBoxSeuilToleranceTeintesSatureesFacteur_valueChanged()
{
    _parametresRecherche.setSeuilToleranceTeintesSatureesFacteur(
            _ui->doubleSpinBoxSeuilToleranceTeintesSatureesFacteur->value() / 100.0);
    _ui->spinBoxSeuilToleranceTeintesSaturees->blockSignals(true);
    _ui->spinBoxSeuilToleranceTeintesSaturees->setValue(
            _parametresRecherche.getSeuilToleranceTeintesSaturees());
    _ui->spinBoxSeuilToleranceTeintesSaturees->blockSignals(false);
}

void FenetreParametresRecherche::on_checkBoxSelectionValeursMoyennes_stateChanged()
{
    _parametresRecherche.setSelectionValeursMoyennes(
            _ui->checkBoxSelectionValeursMoyennes->isChecked());
}

void FenetreParametresRecherche::on_checkBoxSelectionValeursMinimales_stateChanged()
{
    _parametresRecherche.setSelectionValeursMinimales(
            _ui->checkBoxSelectionValeursMinimales->isChecked());
}

void FenetreParametresRecherche::on_checkBoxSelectionValeursMaximales_stateChanged()
{
    _parametresRecherche.setSelectionValeursMaximales(
            _ui->checkBoxSelectionValeursMaximales->isChecked());
}
