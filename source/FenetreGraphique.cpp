//==============================================================================
// Name        : FenetreGraphique.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.5 (07/06/2017)
// Description : Source file of the FenetreGraphique class
//==============================================================================

#include "FenetreGraphique.h"
#include "ui_FenetreGraphique.h"
#include "ParametresAxe.h"
#include <QDialogButtonBox>
#include <QDoubleValidator>
#include <QPushButton>

FenetreGraphique::FenetreGraphique(QWidget* parent) :
        QDialog(parent), ui(new Ui::FenetreGraphique)
{
    this->ui->setupUi(this);
    this->initialiserElementsGraphiques();
    this->actualiserElementsGraphiques();
}

FenetreGraphique::~FenetreGraphique()
{
    delete this->ui;
}

const QList<Point>& FenetreGraphique::getListeDePoints() const
{
    return this->listeDePoints;
}

const ParametresGraphique& FenetreGraphique::getParametresGraphique() const
{
    return this->parametresGraphique;
}

const ParametresAffichage& FenetreGraphique::getParametresAffichage() const
{
    return this->parametresAffichage;
}

void FenetreGraphique::setListeDePoints(const QList<Point>& listeDePoints)
{
    this->listeDePoints = listeDePoints;
}

void FenetreGraphique::setParametresGraphique(const ParametresGraphique& parametresGraphique)
{
    this->parametresGraphique = parametresGraphique;
}

void FenetreGraphique::setParametresAffichage(const ParametresAffichage& parametresAffichage)
{
    this->parametresAffichage = parametresAffichage;
}

void FenetreGraphique::initialiserElementsGraphiques()
{
    const QDoubleValidator* nombreReel = new QDoubleValidator(this);
    this->ui->lineEditAxeHorizontalBorneInferieure->setValidator(nombreReel);
    this->ui->lineEditAxeHorizontalBorneSuperieure->setValidator(nombreReel);
    this->ui->lineEditAxeHorizontalPasPrincipal->setValidator(nombreReel);
    this->ui->lineEditAxeHorizontalPasSecondaire->setValidator(nombreReel);
    this->ui->lineEditAxeVerticalBorneInferieure->setValidator(nombreReel);
    this->ui->lineEditAxeVerticalBorneSuperieure->setValidator(nombreReel);
    this->ui->lineEditAxeVerticalPasPrincipal->setValidator(nombreReel);
    this->ui->lineEditAxeVerticalPasSecondaire->setValidator(nombreReel);
    this->ui->buttonBox->button(QDialogButtonBox::Save)->setText("Enregistrer");
}

void FenetreGraphique::actualiserElementsGraphiques()
{
    // TODO void FenetreGraphique::actualiserElementsGraphiques()
}

void FenetreGraphique::on_lineEditAxeHorizontalBorneInferieure_textChanged()
{
    ParametresAxe parametresAxeHorizontal = this->parametresGraphique.getParametresAxeHorizontal();
    parametresAxeHorizontal.setBorneInferieure(
            this->ui->lineEditAxeHorizontalBorneInferieure->text().toDouble());
    this->parametresGraphique.setParametresAxeHorizontal(parametresAxeHorizontal);
}

void FenetreGraphique::on_lineEditAxeHorizontalBorneSuperieure_textChanged()
{
    ParametresAxe parametresAxeHorizontal = this->parametresGraphique.getParametresAxeHorizontal();
    parametresAxeHorizontal.setBorneSuperieure(
            this->ui->lineEditAxeHorizontalBorneSuperieure->text().toDouble());
    this->parametresGraphique.setParametresAxeHorizontal(parametresAxeHorizontal);
}

void FenetreGraphique::on_lineEditAxeHorizontalPasPrincipal_textChanged()
{
    ParametresAxe parametresAxeHorizontal = this->parametresGraphique.getParametresAxeHorizontal();
    parametresAxeHorizontal.setPasPrincipal(
            this->ui->lineEditAxeHorizontalPasPrincipal->text().toDouble());
    this->parametresGraphique.setParametresAxeHorizontal(parametresAxeHorizontal);
}

void FenetreGraphique::on_lineEditAxeHorizontalPasSecondaire_textChanged()
{
    ParametresAxe parametresAxeHorizontal = this->parametresGraphique.getParametresAxeHorizontal();
    parametresAxeHorizontal.setPasSecondaire(
            this->ui->lineEditAxeHorizontalPasSecondaire->text().toDouble());
    this->parametresGraphique.setParametresAxeHorizontal(parametresAxeHorizontal);
}

void FenetreGraphique::on_lineEditAxeVerticalBorneInferieure_textChanged()
{
    ParametresAxe parametresAxeVertical = this->parametresGraphique.getParametresAxeVertical();
    parametresAxeVertical.setBorneInferieure(
            this->ui->lineEditAxeVerticalBorneInferieure->text().toDouble());
    this->parametresGraphique.setParametresAxeVertical(parametresAxeVertical);
}

void FenetreGraphique::on_lineEditAxeVerticalBorneSuperieure_textChanged()
{
    ParametresAxe parametresAxeVertical = this->parametresGraphique.getParametresAxeVertical();
    parametresAxeVertical.setBorneSuperieure(
            this->ui->lineEditAxeVerticalBorneSuperieure->text().toDouble());
    this->parametresGraphique.setParametresAxeVertical(parametresAxeVertical);
}

void FenetreGraphique::on_lineEditAxeVerticalPasPrincipal_textChanged()
{
    ParametresAxe parametresAxeVertical = this->parametresGraphique.getParametresAxeVertical();
    parametresAxeVertical.setPasPrincipal(
            this->ui->lineEditAxeVerticalPasPrincipal->text().toDouble());
    this->parametresGraphique.setParametresAxeVertical(parametresAxeVertical);
}

void FenetreGraphique::on_lineEditAxeVerticalPasSecondaire_textChanged()
{
    ParametresAxe parametresAxeVertical = this->parametresGraphique.getParametresAxeVertical();
    parametresAxeVertical.setPasSecondaire(
            this->ui->lineEditAxeVerticalPasSecondaire->text().toDouble());
    this->parametresGraphique.setParametresAxeVertical(parametresAxeVertical);
}
