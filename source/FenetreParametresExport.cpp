//==============================================================================
// Name        : FenetreParametresExport.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Source file of the FenetreParametresExport class
//==============================================================================

#include "FenetreParametresExport.h"
#include "ui_FenetreParametresExport.h"
#include <QDialogButtonBox>
#include <QDoubleValidator>
#include <QPushButton>
#include <QString>

FenetreParametresExport::FenetreParametresExport(QWidget* parent) :
        QDialog(parent), _ui(new Ui::FenetreParametresExport)
{
    _ui->setupUi(this);
    initialiserElementsGraphiques();
    actualiserElementsGraphiques();
}

FenetreParametresExport::~FenetreParametresExport()
{
    delete _ui;
}

const ParametresExport& FenetreParametresExport::getParametresExport() const
{
    return _parametresExport;
}

void FenetreParametresExport::setParametresExport(const ParametresExport& parametresExport)
{
    _parametresExport = parametresExport;
}

void FenetreParametresExport::initialiserElementsGraphiques()
{
    const QDoubleValidator* nombreReel = new QDoubleValidator(this);
    _ui->lineEditSeuilInterpolationNumerique->setValidator(nombreReel);
    _ui->lineEditSeuilInterpolationNumerique->setValidator(nombreReel);
    _ui->spinBoxNombreDecimalesOuChiffresSignificatifs->setMinimum(0);
    _ui->spinBoxNombreDecimalesOuChiffresSignificatifs->setMaximum(20);
    _ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Annuler");
}

void FenetreParametresExport::actualiserElementsGraphiques()
{
    _ui->comboBoxCaractereSeparation->setCurrentIndex(
            _parametresExport.getCaractereSeparationIndice());
    _ui->lineEditSeuilInterpolationNumerique->setText(
            QString::number(_parametresExport.getSeuilInterpolationNumerique()));
    _ui->comboBoxFormatNotationNombres->setCurrentIndex(
            _parametresExport.getFormatNotationNombres());
    _ui->comboBoxCaractereSeparateurDecimal->setCurrentIndex(
            _parametresExport.getCaractereSeparateurDecimalIndice());
    _ui->spinBoxNombreDecimalesOuChiffresSignificatifs->setValue(
            _parametresExport.getNombreChiffresSignificatifs());
}

void FenetreParametresExport::on_comboBoxCaractereSeparation_currentIndexChanged()
{
    _parametresExport.setCaractereSeparationIndice(
            _ui->comboBoxCaractereSeparation->currentIndex());
}

void FenetreParametresExport::on_comboBoxFormatNotationNombres_currentIndexChanged()
{
    _parametresExport.setFormatNotationNombres(_ui->comboBoxFormatNotationNombres->currentIndex());
}

void FenetreParametresExport::on_comboBoxCaractereSeparateurDecimal_currentIndexChanged()
{
    _parametresExport.setCaractereSeparateurDecimalIndice(
            _ui->comboBoxCaractereSeparateurDecimal->currentIndex());
}

void FenetreParametresExport::on_spinBoxNombreDecimalesOuChiffresSignificatifs_valueChanged()
{
    _parametresExport.setNombreChiffresSignificatifs(
            _ui->spinBoxNombreDecimalesOuChiffresSignificatifs->value());
}

void FenetreParametresExport::on_lineEditSeuilInterpolationNumerique_textChanged()
{
    _parametresExport.setSeuilInterpolationNumerique(
            _ui->lineEditSeuilInterpolationNumerique->text().toDouble());
}
