//==============================================================================
// Name        : FenetreParametresAffichage.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Source file of the FenetreParametresAffichage class
//==============================================================================

#include "FenetreParametresAffichage.h"
#include "ui_FenetreParametresAffichage.h"
#include "ParametresPoint.h"
#include "ParametresTrait.h"
#include <QColor>
#include <QColorDialog>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QRgb>
#include <QString>

FenetreParametresAffichage::FenetreParametresAffichage(QWidget* parent) :
        QDialog(parent), _ui(new Ui::FenetreParametresAffichage)
{
    _ui->setupUi(this);
    initialiserElementsGraphiques();
    actualiserElementsGraphiques();
}

FenetreParametresAffichage::~FenetreParametresAffichage()
{
    delete _ui;
}

const ParametresAffichage& FenetreParametresAffichage::getParametresAffichage() const
{
    return _parametresAffichage;
}

void FenetreParametresAffichage::setParametresAffichage(
        const ParametresAffichage& parametresAffichage)
{
    _parametresAffichage = parametresAffichage;
}

void FenetreParametresAffichage::initialiserElementsGraphiques()
{
    _ui->spinBoxNombreDecimalesOuChiffresSignificatifs->setMinimum(0);
    _ui->spinBoxNombreDecimalesOuChiffresSignificatifs->setMaximum(20);
    _ui->spinBoxEpaisseurAxes->setMinimum(0);
    _ui->spinBoxEpaisseurAxes->setMaximum(20);
    _ui->spinBoxEpaisseurCourbes->setMinimum(0);
    _ui->spinBoxEpaisseurCourbes->setMaximum(20);
    _ui->spinBoxEpaisseurPointsAxes->setMinimum(0);
    _ui->spinBoxEpaisseurPointsAxes->setMaximum(20);
    _ui->spinBoxEpaisseurPointsCourbes->setMinimum(0);
    _ui->spinBoxEpaisseurPointsCourbes->setMaximum(20);
    _ui->spinBoxEpaisseurPointsManuels->setMinimum(0);
    _ui->spinBoxEpaisseurPointsManuels->setMaximum(20);
    _ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Annuler");
}

void FenetreParametresAffichage::actualiserElementsGraphiques()
{
    const QRgb& couleurAxes = _parametresAffichage.getParametresAxes().getCouleurTrait();
    const QRgb& couleurCourbes = _parametresAffichage.getParametresCourbes().getCouleurTrait();
    const QRgb& couleurPointsAxes =
            _parametresAffichage.getParametresPointsAxes().getCouleurPoint();
    const QRgb& couleurPointsCourbes =
            _parametresAffichage.getParametresPointsCourbes().getCouleurPoint();
    const QRgb& couleurPointsManuels =
            _parametresAffichage.getParametresPointsManuels().getCouleurPoint();

    const QString texteCouleurAxes = QColor(couleurAxes).name().toUpper();
    const QString texteCouleurCourbes = QColor(couleurCourbes).name().toUpper();
    const QString texteCouleurPointsAxes = QColor(couleurPointsAxes).name().toUpper();
    const QString texteCouleurPointsCourbes = QColor(couleurPointsCourbes).name().toUpper();
    const QString texteCouleurPointsManuels = QColor(couleurPointsManuels).name().toUpper();

    _ui->comboBoxFormatNotationNombres->setCurrentIndex(
            _parametresAffichage.getFormatNotationNombres());
    _ui->spinBoxNombreDecimalesOuChiffresSignificatifs->setValue(
            _parametresAffichage.getNombreChiffresSignificatifs());
    _ui->pushButtonCouleurAxes->setText(texteCouleurAxes);
    _ui->pushButtonCouleurAxes->setStyleSheet(
            QString("background-color: %1").arg(texteCouleurAxes));
    _ui->spinBoxEpaisseurAxes->setValue(
            _parametresAffichage.getParametresAxes().getEpaisseurTrait());
    _ui->comboBoxStyleAxes->setCurrentIndex(
            _parametresAffichage.getParametresAxes().getStyleTrait());
    _ui->pushButtonCouleurCourbes->setText(texteCouleurCourbes);
    _ui->pushButtonCouleurCourbes->setStyleSheet(
            QString("background-color: %1").arg(texteCouleurCourbes));
    _ui->spinBoxEpaisseurCourbes->setValue(
            _parametresAffichage.getParametresCourbes().getEpaisseurTrait());
    _ui->comboBoxStyleCourbes->setCurrentIndex(
            _parametresAffichage.getParametresCourbes().getStyleTrait());
    _ui->pushButtonCouleurPointsAxes->setText(texteCouleurPointsAxes);
    _ui->pushButtonCouleurPointsAxes->setStyleSheet(
            QString("background-color: %1").arg(texteCouleurPointsAxes));
    _ui->spinBoxEpaisseurPointsAxes->setValue(
            _parametresAffichage.getParametresPointsAxes().getEpaisseurPoint());
    _ui->comboBoxStylePointsAxes->setCurrentIndex(
            _parametresAffichage.getParametresPointsAxes().getStylePoint());
    _ui->pushButtonCouleurPointsCourbes->setText(texteCouleurPointsCourbes);
    _ui->pushButtonCouleurPointsCourbes->setStyleSheet(
            QString("background-color: %1").arg(texteCouleurPointsCourbes));
    _ui->spinBoxEpaisseurPointsCourbes->setValue(
            _parametresAffichage.getParametresPointsCourbes().getEpaisseurPoint());
    _ui->comboBoxStylePointsCourbes->setCurrentIndex(
            _parametresAffichage.getParametresPointsCourbes().getStylePoint());
    _ui->pushButtonCouleurPointsManuels->setText(texteCouleurPointsManuels);
    _ui->pushButtonCouleurPointsManuels->setStyleSheet(
            QString("background-color: %1").arg(texteCouleurPointsManuels));
    _ui->spinBoxEpaisseurPointsManuels->setValue(
            _parametresAffichage.getParametresPointsManuels().getEpaisseurPoint());
    _ui->comboBoxStylePointsManuels->setCurrentIndex(
            _parametresAffichage.getParametresPointsManuels().getStylePoint());
}

void FenetreParametresAffichage::on_comboBoxFormatNotationNombres_currentIndexChanged()
{
    _parametresAffichage.setFormatNotationNombres(
            static_cast<ParametresAffichage::FormatNotationNombres>(_ui->comboBoxFormatNotationNombres->currentIndex()));
}

void FenetreParametresAffichage::on_spinBoxNombreDecimalesOuChiffresSignificatifs_valueChanged()
{
    _parametresAffichage.setNombreChiffresSignificatifs(
            _ui->spinBoxNombreDecimalesOuChiffresSignificatifs->value());
}

void FenetreParametresAffichage::on_pushButtonCouleurAxes_clicked()
{
    ParametresTrait parametresAxes = _parametresAffichage.getParametresAxes();
    QColorDialog* fenetreCouleurAxes = new QColorDialog(QColor(parametresAxes.getCouleurTrait()),
            this);
    if (fenetreCouleurAxes->exec() == QColorDialog::Rejected)
        return;
    parametresAxes.setCouleurTrait(fenetreCouleurAxes->selectedColor().rgb());
    _parametresAffichage.setParametresAxes(parametresAxes);
    actualiserElementsGraphiques();
}

void FenetreParametresAffichage::on_comboBoxStyleAxes_currentIndexChanged()
{
    ParametresTrait parametresAxes = _parametresAffichage.getParametresAxes();
    parametresAxes.setStyleTrait(
            static_cast<ParametresTrait::StyleTrait>(_ui->comboBoxStyleAxes->currentIndex()));
    _parametresAffichage.setParametresAxes(parametresAxes);
}

void FenetreParametresAffichage::on_spinBoxEpaisseurAxes_valueChanged()
{
    ParametresTrait parametresAxes = _parametresAffichage.getParametresAxes();
    parametresAxes.setEpaisseurTrait(_ui->spinBoxEpaisseurAxes->value());
    _parametresAffichage.setParametresAxes(parametresAxes);
}

void FenetreParametresAffichage::on_pushButtonCouleurCourbes_clicked()
{
    ParametresTrait parametresCourbes = _parametresAffichage.getParametresCourbes();
    QColorDialog* fenetreCouleurCourbes = new QColorDialog(
            QColor(parametresCourbes.getCouleurTrait()), this);
    if (fenetreCouleurCourbes->exec() == QColorDialog::Rejected)
        return;
    parametresCourbes.setCouleurTrait(fenetreCouleurCourbes->selectedColor().rgb());
    _parametresAffichage.setParametresCourbes(parametresCourbes);
    actualiserElementsGraphiques();
}

void FenetreParametresAffichage::on_comboBoxStyleCourbes_currentIndexChanged()
{
    ParametresTrait parametresCourbes = _parametresAffichage.getParametresCourbes();
    parametresCourbes.setStyleTrait(
            static_cast<ParametresTrait::StyleTrait>(_ui->comboBoxStyleCourbes->currentIndex()));
    _parametresAffichage.setParametresCourbes(parametresCourbes);
}

void FenetreParametresAffichage::on_spinBoxEpaisseurCourbes_valueChanged()
{
    ParametresTrait parametresCourbes = _parametresAffichage.getParametresCourbes();
    parametresCourbes.setEpaisseurTrait(_ui->spinBoxEpaisseurCourbes->value());
    _parametresAffichage.setParametresCourbes(parametresCourbes);
}

void FenetreParametresAffichage::on_pushButtonCouleurPointsAxes_clicked()
{
    ParametresPoint parametresPointsAxes = _parametresAffichage.getParametresPointsAxes();
    QColorDialog* fenetreCouleurPointsAxes = new QColorDialog(
            QColor(parametresPointsAxes.getCouleurPoint()), this);
    if (fenetreCouleurPointsAxes->exec() == QColorDialog::Rejected)
        return;
    parametresPointsAxes.setCouleurPoint(fenetreCouleurPointsAxes->selectedColor().rgb());
    _parametresAffichage.setParametresPointsAxes(parametresPointsAxes);
    actualiserElementsGraphiques();
}

void FenetreParametresAffichage::on_comboBoxStylePointsAxes_currentIndexChanged()
{
    ParametresPoint parametresPointsAxes = _parametresAffichage.getParametresPointsAxes();
    parametresPointsAxes.setStylePoint(
            static_cast<ParametresPoint::StylePoint>(_ui->comboBoxStylePointsAxes->currentIndex()));
    _parametresAffichage.setParametresPointsAxes(parametresPointsAxes);
}

void FenetreParametresAffichage::on_spinBoxEpaisseurPointsAxes_valueChanged()
{
    ParametresPoint parametresPointsAxes = _parametresAffichage.getParametresPointsAxes();
    parametresPointsAxes.setEpaisseurPoint(_ui->spinBoxEpaisseurPointsAxes->value());
    _parametresAffichage.setParametresPointsAxes(parametresPointsAxes);
}

void FenetreParametresAffichage::on_pushButtonCouleurPointsCourbes_clicked()
{
    ParametresPoint parametresPointsCourbes = _parametresAffichage.getParametresPointsCourbes();
    QColorDialog* fenetreCouleurPointsCourbes = new QColorDialog(
            QColor(parametresPointsCourbes.getCouleurPoint()), this);
    if (fenetreCouleurPointsCourbes->exec() == QColorDialog::Rejected)
        return;
    parametresPointsCourbes.setCouleurPoint(fenetreCouleurPointsCourbes->selectedColor().rgb());
    _parametresAffichage.setParametresPointsCourbes(parametresPointsCourbes);
    actualiserElementsGraphiques();
}

void FenetreParametresAffichage::on_comboBoxStylePointsCourbes_currentIndexChanged()
{
    ParametresPoint parametresPointsCourbes = _parametresAffichage.getParametresPointsCourbes();
    parametresPointsCourbes.setStylePoint(
            static_cast<ParametresPoint::StylePoint>(_ui->comboBoxStylePointsCourbes->currentIndex()));
    _parametresAffichage.setParametresPointsCourbes(parametresPointsCourbes);
}

void FenetreParametresAffichage::on_spinBoxEpaisseurPointsCourbes_valueChanged()
{
    ParametresPoint parametresPointsCourbes = _parametresAffichage.getParametresPointsCourbes();
    parametresPointsCourbes.setEpaisseurPoint(_ui->spinBoxEpaisseurPointsCourbes->value());
    _parametresAffichage.setParametresPointsCourbes(parametresPointsCourbes);
}

void FenetreParametresAffichage::on_pushButtonCouleurPointsManuels_clicked()
{
    ParametresPoint parametresPointsManuels = _parametresAffichage.getParametresPointsManuels();
    QColorDialog* fenetreCouleurPointsManuels = new QColorDialog(
            QColor(parametresPointsManuels.getCouleurPoint()), this);
    if (fenetreCouleurPointsManuels->exec() == QColorDialog::Rejected)
        return;
    parametresPointsManuels.setCouleurPoint(fenetreCouleurPointsManuels->selectedColor().rgb());
    _parametresAffichage.setParametresPointsManuels(parametresPointsManuels);
    actualiserElementsGraphiques();
}

void FenetreParametresAffichage::on_comboBoxStylePointsManuels_currentIndexChanged()
{
    ParametresPoint parametresPointsManuels = _parametresAffichage.getParametresPointsManuels();
    parametresPointsManuels.setStylePoint(
            static_cast<ParametresPoint::StylePoint>(_ui->comboBoxStylePointsManuels->currentIndex()));
    _parametresAffichage.setParametresPointsManuels(parametresPointsManuels);
}

void FenetreParametresAffichage::on_spinBoxEpaisseurPointsManuels_valueChanged()
{
    ParametresPoint parametresPointsManuels = _parametresAffichage.getParametresPointsManuels();
    parametresPointsManuels.setEpaisseurPoint(_ui->spinBoxEpaisseurPointsManuels->value());
    _parametresAffichage.setParametresPointsManuels(parametresPointsManuels);
}
