//==============================================================================
// Name        : FenetreParametresRecherche.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/06/2016)
// Description : Source file of the FenetreParametresRecherche class
//==============================================================================

#include "FenetreParametresRecherche.h"
#include "ui_FenetreParametresRecherche.h"
#include <QDialogButtonBox>
#include <QPushButton>

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
    this->ui->doubleSpinBoxSeuilToleranceNiveauxDeGris->setMinimum(0);
    this->ui->doubleSpinBoxSeuilToleranceNiveauxDeGris->setMaximum(100);
    this->ui->doubleSpinBoxSeuilToleranceTeintesSaturees->setMinimum(0);
    this->ui->doubleSpinBoxSeuilToleranceTeintesSaturees->setMaximum(100);
    this->ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Annuler");
}

void FenetreParametresRecherche::actualiserElementsGraphiques()
{
    this->ui->doubleSpinBoxSeuilToleranceNiveauxDeGris->setValue(
            this->parametresRecherche.getSeuilToleranceNiveauxDeGrisFacteur() * 100.0);
    this->ui->doubleSpinBoxSeuilToleranceTeintesSaturees->setValue(
            this->parametresRecherche.getSeuilToleranceTeintesSatureesFacteur() * 100.0);
    this->ui->checkBoxSelectionValeursMoyennes->setChecked(
            this->parametresRecherche.getSelectionValeursMoyennes());
    this->ui->checkBoxSelectionValeursMinimales->setChecked(
            this->parametresRecherche.getSelectionValeursMinimales());
    this->ui->checkBoxSelectionValeursMaximales->setChecked(
            this->parametresRecherche.getSelectionValeursMaximales());
}

void FenetreParametresRecherche::on_doubleSpinBoxSeuilToleranceNiveauxDeGris_valueChanged()
{
    this->parametresRecherche.setSeuilToleranceNiveauxDeGrisFacteur(
            this->ui->doubleSpinBoxSeuilToleranceNiveauxDeGris->value() / 100.0);
}

void FenetreParametresRecherche::on_doubleSpinBoxSeuilToleranceTeintesSaturees_valueChanged()
{
    this->parametresRecherche.setSeuilToleranceTeintesSatureesFacteur(
            this->ui->doubleSpinBoxSeuilToleranceTeintesSaturees->value() / 100.0);
}

void FenetreParametresRecherche::on_checkBoxSelectionValeursMoyennes_stateChanged()
{
    this->parametresRecherche.setSelectionValeursMoyennes(
            this->ui->checkBoxSelectionValeursMoyennes->isChecked());
}

void FenetreParametresRecherche::on_checkBoxSelectionValeursMinimales_stateChanged()
{
    this->parametresRecherche.setSelectionValeursMinimales(
            this->ui->checkBoxSelectionValeursMinimales->isChecked());
}

void FenetreParametresRecherche::on_checkBoxSelectionValeursMaximales_stateChanged()
{
    this->parametresRecherche.setSelectionValeursMaximales(
            this->ui->checkBoxSelectionValeursMaximales->isChecked());
}
