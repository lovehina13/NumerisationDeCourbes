//==============================================================================
// Name        : FenetreParametresExport.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/06/2016)
// Description : Source file of the FenetreParametresExport class
//==============================================================================

#include "FenetreParametresExport.h"
#include "ui_FenetreParametresExport.h"
#include <QDoubleValidator>

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
    QDoubleValidator* nombreReel = new QDoubleValidator(this);
    this->ui->lineEditSeuilInterpolationNumerique->setValidator(nombreReel);
    this->ui->lineEditSeuilInterpolationNumerique->setValidator(nombreReel);
    this->ui->spinBoxNombreDecimalesOuChiffresSignificatifs->setMinimum(0);
    this->ui->spinBoxNombreDecimalesOuChiffresSignificatifs->setMaximum(20);
}

void FenetreParametresExport::actualiserElementsGraphiques()
{
    this->ui->comboBoxCaractereSeparation->setCurrentIndex(
            this->parametresExport.getIndiceCaractereSeparation());
    this->ui->lineEditSeuilInterpolationNumerique->setText(
            QString::number(this->parametresExport.getSeuilInterpolationNumerique()));
    this->ui->comboBoxFormatNotationNombres->setCurrentIndex(
            this->parametresExport.getFormatNotationNombres());
    this->ui->comboBoxCaractereSeparateurDecimal->setCurrentIndex(
            this->parametresExport.getIndiceCaractereSeparateurDecimal());
    this->ui->spinBoxNombreDecimalesOuChiffresSignificatifs->setValue(
            this->parametresExport.getNombreChiffresSignificatifs());
}

void FenetreParametresExport::on_comboBoxCaractereSeparation_currentIndexChanged()
{
    this->parametresExport.setIndiceCaractereSeparation(
            this->ui->comboBoxCaractereSeparation->currentIndex());
}

void FenetreParametresExport::on_lineEditSeuilInterpolationNumerique_textChanged()
{
    this->parametresExport.setSeuilInterpolationNumerique(
            this->ui->lineEditSeuilInterpolationNumerique->text().toDouble());
}

void FenetreParametresExport::on_comboBoxFormatNotationNombres_currentIndexChanged()
{
    this->parametresExport.setFormatNotationNombres(
            this->ui->comboBoxFormatNotationNombres->currentIndex());
}

void FenetreParametresExport::on_comboBoxCaractereSeparateurDecimal_currentIndexChanged()
{
    this->parametresExport.setIndiceCaractereSeparateurDecimal(
            this->ui->comboBoxCaractereSeparateurDecimal->currentIndex());
}

void FenetreParametresExport::on_spinBoxNombreDecimalesOuChiffresSignificatifs_valueChanged()
{
    this->parametresExport.setNombreChiffresSignificatifs(
            this->ui->spinBoxNombreDecimalesOuChiffresSignificatifs->value());
}
