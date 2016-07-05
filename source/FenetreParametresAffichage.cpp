//==============================================================================
// Name        : FenetreParametresAffichage.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/06/2016)
// Description : Source file of the FenetreParametresAffichage class
//==============================================================================

#include "FenetreParametresAffichage.h"
#include "ui_FenetreParametresAffichage.h"
#include <QColor>
#include <QColorDialog>
#include <QPalette>

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
    this->ui->spinBoxNombreDecimalesOuChiffresSignificatifs->setMinimum(0);
    this->ui->spinBoxNombreDecimalesOuChiffresSignificatifs->setMaximum(20);
    this->ui->spinBoxEpaisseurAxes->setMinimum(0);
    this->ui->spinBoxEpaisseurAxes->setMaximum(20);
    this->ui->spinBoxEpaisseurCourbes->setMinimum(0);
    this->ui->spinBoxEpaisseurCourbes->setMaximum(20);
    this->ui->spinBoxEpaisseurPointsAxes->setMinimum(0);
    this->ui->spinBoxEpaisseurPointsAxes->setMaximum(20);
    this->ui->spinBoxEpaisseurPointsCourbes->setMinimum(0);
    this->ui->spinBoxEpaisseurPointsCourbes->setMaximum(20);
    this->ui->spinBoxEpaisseurPointsManuels->setMinimum(0);
    this->ui->spinBoxEpaisseurPointsManuels->setMaximum(20);
}

void FenetreParametresAffichage::actualiserElementsGraphiques()
{
    // TODO Gestion de la couleur des boutons sous Microsoft Windows

    QPalette paletteCouleurAxes = this->ui->pushButtonCouleurAxes->palette();
    QPalette paletteCouleurCourbes = this->ui->pushButtonCouleurCourbes->palette();
    QPalette paletteCouleurPointsAxes = this->ui->pushButtonCouleurPointsAxes->palette();
    QPalette paletteCouleurPointsCourbes = this->ui->pushButtonCouleurPointsCourbes->palette();
    QPalette paletteCouleurPointsManuels = this->ui->pushButtonCouleurPointsManuels->palette();

    paletteCouleurAxes.setColor(QPalette::Base,
            QColor(this->parametresAffichage.getParametresAxes().getCouleurTrait()));
    paletteCouleurCourbes.setColor(QPalette::Base,
            QColor(this->parametresAffichage.getParametresCourbes().getCouleurTrait()));
    paletteCouleurPointsAxes.setColor(QPalette::Base,
            QColor(this->parametresAffichage.getParametresPointsAxes().getCouleurPoint()));
    paletteCouleurPointsCourbes.setColor(QPalette::Base,
            QColor(this->parametresAffichage.getParametresPointsCourbes().getCouleurPoint()));
    paletteCouleurPointsManuels.setColor(QPalette::Base,
            QColor(this->parametresAffichage.getParametresPointsManuels().getCouleurPoint()));

    this->ui->comboBoxFormatNotationNombres->setCurrentIndex(
            this->parametresAffichage.getFormatNotationNombres());
    this->ui->spinBoxNombreDecimalesOuChiffresSignificatifs->setValue(
            this->parametresAffichage.getNombreChiffresSignificatifs());
    this->ui->pushButtonCouleurAxes->setPalette(paletteCouleurAxes);
    this->ui->spinBoxEpaisseurAxes->setValue(
            this->parametresAffichage.getParametresAxes().getEpaisseurTrait());
    this->ui->comboBoxTypeAxes->setCurrentIndex(
            this->parametresAffichage.getParametresAxes().getStyleTrait());
    this->ui->pushButtonCouleurCourbes->setPalette(paletteCouleurCourbes);
    this->ui->spinBoxEpaisseurCourbes->setValue(
            this->parametresAffichage.getParametresCourbes().getEpaisseurTrait());
    this->ui->comboBoxTypeCourbes->setCurrentIndex(
            this->parametresAffichage.getParametresCourbes().getStyleTrait());
    this->ui->pushButtonCouleurPointsAxes->setPalette(paletteCouleurPointsAxes);
    this->ui->spinBoxEpaisseurPointsAxes->setValue(
            this->parametresAffichage.getParametresPointsAxes().getEpaisseurPoint());
    this->ui->comboBoxTypePointsAxes->setCurrentIndex(
            this->parametresAffichage.getParametresPointsAxes().getStylePoint());
    this->ui->pushButtonCouleurPointsCourbes->setPalette(paletteCouleurPointsCourbes);
    this->ui->spinBoxEpaisseurPointsCourbes->setValue(
            this->parametresAffichage.getParametresPointsCourbes().getEpaisseurPoint());
    this->ui->comboBoxTypePointsCourbes->setCurrentIndex(
            this->parametresAffichage.getParametresPointsCourbes().getStylePoint());
    this->ui->pushButtonCouleurPointsManuels->setPalette(paletteCouleurPointsManuels);
    this->ui->spinBoxEpaisseurPointsManuels->setValue(
            this->parametresAffichage.getParametresPointsManuels().getEpaisseurPoint());
    this->ui->comboBoxTypePointsManuels->setCurrentIndex(
            this->parametresAffichage.getParametresPointsManuels().getStylePoint());
}

void FenetreParametresAffichage::on_comboBoxFormatNotationNombres_currentIndexChanged()
{
    this->parametresAffichage.setFormatNotationNombres(
            this->ui->comboBoxFormatNotationNombres->currentIndex());
}

void FenetreParametresAffichage::on_spinBoxNombreDecimalesOuChiffresSignificatifs_valueChanged()
{
    this->parametresAffichage.setNombreChiffresSignificatifs(
            this->ui->spinBoxNombreDecimalesOuChiffresSignificatifs->value());
}

void FenetreParametresAffichage::on_pushButtonCouleurAxes_clicked()
{
    ParametresTrait parametresAxes = this->parametresAffichage.getParametresAxes();
    QColorDialog* fenetreCouleurAxes = new QColorDialog(QColor(parametresAxes.getCouleurTrait()),
            this);
    if (fenetreCouleurAxes->exec() == QColorDialog::Rejected)
        return;
    parametresAxes.setCouleurTrait(fenetreCouleurAxes->selectedColor().rgb());
    this->parametresAffichage.setParametresAxes(parametresAxes);
}

void FenetreParametresAffichage::on_spinBoxEpaisseurAxes_valueChanged()
{
    ParametresTrait parametresAxes = this->parametresAffichage.getParametresAxes();
    parametresAxes.setEpaisseurTrait(this->ui->spinBoxEpaisseurAxes->value());
    this->parametresAffichage.setParametresAxes(parametresAxes);
}

void FenetreParametresAffichage::on_comboBoxTypeAxes_currentIndexChanged()
{
    ParametresTrait parametresAxes = this->parametresAffichage.getParametresAxes();
    parametresAxes.setStyleTrait(this->ui->comboBoxTypeAxes->currentIndex());
    this->parametresAffichage.setParametresAxes(parametresAxes);
}

void FenetreParametresAffichage::on_pushButtonCouleurCourbes_clicked()
{
    ParametresTrait parametresCourbes = this->parametresAffichage.getParametresCourbes();
    QColorDialog* fenetreCouleurCourbes = new QColorDialog(
            QColor(parametresCourbes.getCouleurTrait()), this);
    if (fenetreCouleurCourbes->exec() == QColorDialog::Rejected)
        return;
    parametresCourbes.setCouleurTrait(fenetreCouleurCourbes->selectedColor().rgb());
    this->parametresAffichage.setParametresCourbes(parametresCourbes);
}

void FenetreParametresAffichage::on_spinBoxEpaisseurCourbes_valueChanged()
{
    ParametresTrait parametresCourbes = this->parametresAffichage.getParametresCourbes();
    parametresCourbes.setEpaisseurTrait(this->ui->spinBoxEpaisseurCourbes->value());
    this->parametresAffichage.setParametresCourbes(parametresCourbes);
}

void FenetreParametresAffichage::on_comboBoxTypeCourbes_currentIndexChanged()
{
    ParametresTrait parametresCourbes = this->parametresAffichage.getParametresCourbes();
    parametresCourbes.setStyleTrait(this->ui->comboBoxTypeCourbes->currentIndex());
    this->parametresAffichage.setParametresCourbes(parametresCourbes);
}

void FenetreParametresAffichage::on_pushButtonCouleurPointsAxes_clicked()
{
    ParametresPoint parametresPointsAxes = this->parametresAffichage.getParametresPointsAxes();
    QColorDialog* fenetreCouleurPointsAxes = new QColorDialog(
            QColor(parametresPointsAxes.getCouleurPoint()), this);
    if (fenetreCouleurPointsAxes->exec() == QColorDialog::Rejected)
        return;
    parametresPointsAxes.setCouleurPoint(fenetreCouleurPointsAxes->selectedColor().rgb());
    this->parametresAffichage.setParametresPointsAxes(parametresPointsAxes);
}

void FenetreParametresAffichage::on_spinBoxEpaisseurPointsAxes_valueChanged()
{
    ParametresPoint parametresPointsAxes = this->parametresAffichage.getParametresPointsAxes();
    parametresPointsAxes.setEpaisseurPoint(this->ui->spinBoxEpaisseurPointsAxes->value());
    this->parametresAffichage.setParametresPointsAxes(parametresPointsAxes);
}

void FenetreParametresAffichage::on_comboBoxTypePointsAxes_currentIndexChanged()
{
    ParametresPoint parametresPointsAxes = this->parametresAffichage.getParametresPointsAxes();
    parametresPointsAxes.setStylePoint(this->ui->comboBoxTypePointsAxes->currentIndex());
    this->parametresAffichage.setParametresPointsAxes(parametresPointsAxes);
}

void FenetreParametresAffichage::on_pushButtonCouleurPointsCourbes_clicked()
{
    ParametresPoint parametresPointsCourbes =
            this->parametresAffichage.getParametresPointsCourbes();
    QColorDialog* fenetreCouleurPointsCourbes = new QColorDialog(
            QColor(parametresPointsCourbes.getCouleurPoint()), this);
    if (fenetreCouleurPointsCourbes->exec() == QColorDialog::Rejected)
        return;
    parametresPointsCourbes.setCouleurPoint(fenetreCouleurPointsCourbes->selectedColor().rgb());
    this->parametresAffichage.setParametresPointsCourbes(parametresPointsCourbes);
}

void FenetreParametresAffichage::on_spinBoxEpaisseurPointsCourbes_valueChanged()
{
    ParametresPoint parametresPointsCourbes =
            this->parametresAffichage.getParametresPointsCourbes();
    parametresPointsCourbes.setEpaisseurPoint(this->ui->spinBoxEpaisseurPointsCourbes->value());
    this->parametresAffichage.setParametresPointsCourbes(parametresPointsCourbes);
}

void FenetreParametresAffichage::on_comboBoxTypePointsCourbes_currentIndexChanged()
{
    ParametresPoint parametresPointsCourbes =
            this->parametresAffichage.getParametresPointsCourbes();
    parametresPointsCourbes.setStylePoint(this->ui->comboBoxTypePointsCourbes->currentIndex());
    this->parametresAffichage.setParametresPointsCourbes(parametresPointsCourbes);
}

void FenetreParametresAffichage::on_pushButtonCouleurPointsManuels_clicked()
{
    ParametresPoint parametresPointsManuels =
            this->parametresAffichage.getParametresPointsManuels();
    QColorDialog* fenetreCouleurPointsManuels = new QColorDialog(
            QColor(parametresPointsManuels.getCouleurPoint()), this);
    if (fenetreCouleurPointsManuels->exec() == QColorDialog::Rejected)
        return;
    parametresPointsManuels.setCouleurPoint(fenetreCouleurPointsManuels->selectedColor().rgb());
    this->parametresAffichage.setParametresPointsManuels(parametresPointsManuels);
}

void FenetreParametresAffichage::on_spinBoxEpaisseurPointsManuels_valueChanged()
{
    ParametresPoint parametresPointsManuels =
            this->parametresAffichage.getParametresPointsManuels();
    parametresPointsManuels.setEpaisseurPoint(this->ui->spinBoxEpaisseurPointsManuels->value());
    this->parametresAffichage.setParametresPointsManuels(parametresPointsManuels);
}

void FenetreParametresAffichage::on_comboBoxTypePointsManuels_currentIndexChanged()
{
    ParametresPoint parametresPointsManuels =
            this->parametresAffichage.getParametresPointsManuels();
    parametresPointsManuels.setStylePoint(this->ui->comboBoxTypePointsManuels->currentIndex());
    this->parametresAffichage.setParametresPointsManuels(parametresPointsManuels);
}
