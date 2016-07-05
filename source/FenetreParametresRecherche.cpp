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
    this->ui->spinBoxSeuilToleranceNiveauxDeGris->setMinimum(0);
    this->ui->spinBoxSeuilToleranceNiveauxDeGris->setMaximum(256);
    this->ui->spinBoxSeuilToleranceTeintesSaturees->setMinimum(0);
    this->ui->spinBoxSeuilToleranceTeintesSaturees->setMaximum(360);
}

void FenetreParametresRecherche::actualiserElementsGraphiques()
{
    this->ui->spinBoxSeuilToleranceNiveauxDeGris->setValue(
            this->parametresRecherche.getSeuilToleranceNiveauxDeGris());
    this->ui->spinBoxSeuilToleranceTeintesSaturees->setValue(
            this->parametresRecherche.getSeuilToleranceTeintesSaturees());
    this->ui->checkBoxSelectionValeursMoyennes->setChecked(
            this->parametresRecherche.getSelectionValeursMoyennes());
    this->ui->checkBoxSelectionValeursMinimales->setChecked(
            this->parametresRecherche.getSelectionValeursMinimales());
    this->ui->checkBoxSelectionValeursMaximales->setChecked(
            this->parametresRecherche.getSelectionValeursMaximales());
}

void FenetreParametresRecherche::on_spinBoxSeuilToleranceNiveauxDeGris_valueChanged()
{
    this->parametresRecherche.setSeuilToleranceNiveauxDeGris(
            this->ui->spinBoxSeuilToleranceNiveauxDeGris->value());
}

void FenetreParametresRecherche::on_spinBoxSeuilToleranceTeintesSaturees_valueChanged()
{
    this->parametresRecherche.setSeuilToleranceTeintesSaturees(
            this->ui->spinBoxSeuilToleranceTeintesSaturees->value());
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
