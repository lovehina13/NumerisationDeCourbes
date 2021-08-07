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
    _ui->comboBoxCaractereSeparation->setCurrentIndex(_parametresExport.getCaractereSeparation());
    _ui->lineEditSeuilInterpolationNumerique->setText(
            QString::number(_parametresExport.getSeuilInterpolationNumerique()));
    _ui->comboBoxFormatNotationNombres->setCurrentIndex(
            _parametresExport.getFormatNotationNombres());
    _ui->comboBoxCaractereSeparateurDecimal->setCurrentIndex(
            _parametresExport.getCaractereSeparateurDecimal());
    _ui->spinBoxNombreDecimalesOuChiffresSignificatifs->setValue(
            _parametresExport.getNombreChiffresSignificatifs());
}

void FenetreParametresExport::on_comboBoxCaractereSeparation_currentIndexChanged(int index)
{
    _parametresExport.setCaractereSeparation(
            static_cast<ParametresExport::CaractereSeparation>(index));
}

void FenetreParametresExport::on_comboBoxFormatNotationNombres_currentIndexChanged(int index)
{
    _parametresExport.setFormatNotationNombres(
            static_cast<ParametresExport::FormatNotationNombres>(index));
}

void FenetreParametresExport::on_comboBoxCaractereSeparateurDecimal_currentIndexChanged(int index)
{
    _parametresExport.setCaractereSeparateurDecimal(
            static_cast<ParametresExport::CaractereSeparateurDecimal>(index));
}

void FenetreParametresExport::on_spinBoxNombreDecimalesOuChiffresSignificatifs_valueChanged(
        int value)
{
    _parametresExport.setNombreChiffresSignificatifs(value);
}

void FenetreParametresExport::on_lineEditSeuilInterpolationNumerique_textChanged(
        const QString& text)
{
    _parametresExport.setSeuilInterpolationNumerique(text.toDouble());
}
