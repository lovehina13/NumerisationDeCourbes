//==============================================================================
// Name        : EcranPrincipal.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (14/06/2016)
// Description : Source file of the EcranPrincipal class
//==============================================================================

#include "EcranPrincipal.h"
#include "ui_EcranPrincipal.h"

EcranPrincipal::EcranPrincipal(QWidget* parent) :
        QMainWindow(parent), ui(new Ui::EcranPrincipal)
{
    this->ui->setupUi(this);
}

EcranPrincipal::~EcranPrincipal()
{
    delete this->ui;
}

void EcranPrincipal::on_actionCreer_toggled()
{
    // TODO void EcranPrincipal::on_actionCreer_toggled()
}

void EcranPrincipal::on_actionCharger_toggled()
{
    // TODO void EcranPrincipal::on_actionCharger_toggled()
}

void EcranPrincipal::on_actionSauver_toggled()
{
    // TODO void EcranPrincipal::on_actionSauver_toggled()
}

void EcranPrincipal::on_actionExporter_toggled()
{
    // TODO void EcranPrincipal::on_actionExporter_toggled()
}

void EcranPrincipal::on_actionQuitter_toggled()
{
    // TODO void EcranPrincipal::on_actionQuitter_toggled()
}

void EcranPrincipal::on_actionParametresAffichage_toggled()
{
    // TODO void EcranPrincipal::on_actionParametresAffichage_toggled()
}

void EcranPrincipal::on_actionParametresConversion_toggled()
{
    // TODO void EcranPrincipal::on_actionParametresConversion_toggled()
}

void EcranPrincipal::on_actionParametresRecherche_toggled()
{
    // TODO void EcranPrincipal::on_actionParametresRecherche_toggled()
}

void EcranPrincipal::on_actionParametresExport_toggled()
{
    // TODO void EcranPrincipal::on_actionParametresExport_toggled()
}

void EcranPrincipal::on_actionDocumentation_toggled()
{
    // TODO void EcranPrincipal::on_actionDocumentation_toggled()
}

void EcranPrincipal::on_actionAbout_toggled()
{
    // TODO void EcranPrincipal::on_actionAbout_toggled()
}

void EcranPrincipal::on_radioButtonNoirEtBlanc_clicked()
{
    // TODO void EcranPrincipal::on_radioButtonNoirEtBlanc_clicked()
}

void EcranPrincipal::on_radioButtonNiveauxDeGris_clicked()
{
    // TODO void EcranPrincipal::on_radioButtonNiveauxDeGris_clicked()
}

void EcranPrincipal::on_radioButtonTeintesSaturees_clicked()
{
    // TODO void EcranPrincipal::on_radioButtonTeintesSaturees_clicked()
}

void EcranPrincipal::on_pushButtonConvertir_clicked()
{
    // TODO void EcranPrincipal::on_pushButtonConvertir_clicked()
}

void EcranPrincipal::on_pushButtonRestaurer_clicked()
{
    // TODO void EcranPrincipal::on_pushButtonRestaurer_clicked()
}

void EcranPrincipal::on_lineEditPointX0XPixel_textChanged()
{
    // TODO void EcranPrincipal::on_lineEditPointX0XPixel_textChanged()
}

void EcranPrincipal::on_lineEditPointX0YPixel_textChanged()
{
    // TODO void EcranPrincipal::on_lineEditPointX0YPixel_textChanged()
}

void EcranPrincipal::on_lineEditPointX0Valeur_textChanged()
{
    // TODO void EcranPrincipal::on_lineEditPointX0Valeur_textChanged()
}

void EcranPrincipal::on_lineEditPointX1XPixel_textChanged()
{
    // TODO void EcranPrincipal::on_lineEditPointX1XPixel_textChanged()
}

void EcranPrincipal::on_lineEditPointX1YPixel_textChanged()
{
    // TODO void EcranPrincipal::on_lineEditPointX1YPixel_textChanged()
}

void EcranPrincipal::on_lineEditPointX1Valeur_textChanged()
{
    // TODO void EcranPrincipal::on_lineEditPointX1Valeur_textChanged()
}

void EcranPrincipal::on_lineEditPointY0XPixel_textChanged()
{
    // TODO void EcranPrincipal::on_lineEditPointY0XPixel_textChanged()
}

void EcranPrincipal::on_lineEditPointY0YPixel_textChanged()
{
    // TODO void EcranPrincipal::on_lineEditPointY0YPixel_textChanged()
}

void EcranPrincipal::on_lineEditPointY0Valeur_textChanged()
{
    // TODO void EcranPrincipal::on_lineEditPointY0Valeur_textChanged()
}

void EcranPrincipal::on_lineEditPointY1XPixel_textChanged()
{
    // TODO void EcranPrincipal::on_lineEditPointY1XPixel_textChanged()
}

void EcranPrincipal::on_lineEditPointY1YPixel_textChanged()
{
    // TODO void EcranPrincipal::on_lineEditPointY1YPixel_textChanged()
}

void EcranPrincipal::on_lineEditPointY1Valeur_textChanged()
{
    // TODO void EcranPrincipal::on_lineEditPointY1Valeur_textChanged()
}

void EcranPrincipal::on_lineEditPointDepartXPixel_textChanged()
{
    // TODO void EcranPrincipal::on_lineEditPointDepartXPixel_textChanged()
}

void EcranPrincipal::on_lineEditPointDepartYPixel_textChanged()
{
    // TODO void EcranPrincipal::on_lineEditPointDepartYPixel_textChanged()
}

void EcranPrincipal::on_lineEditPointArriveeXPixel_textChanged()
{
    // TODO void EcranPrincipal::on_lineEditPointArriveeXPixel_textChanged()
}

void EcranPrincipal::on_lineEditPointArriveeYPixel_textChanged()
{
    // TODO void EcranPrincipal::on_lineEditPointArriveeYPixel_textChanged()
}

void EcranPrincipal::on_pushButtonRechercherPoints_clicked()
{
    // TODO void EcranPrincipal::on_pushButtonRechercherPoints_clicked()
}

void EcranPrincipal::on_pushButtonSupprimerTout_clicked()
{
    // TODO void EcranPrincipal::on_pushButtonSupprimerTout_clicked()
}

void EcranPrincipal::on_pushButtonSupprimerSelection_clicked()
{
    // TODO void EcranPrincipal::on_pushButtonSupprimerSelection_clicked()
}

void EcranPrincipal::on_pushButtonGraphique_clicked()
{
    // TODO void EcranPrincipal::on_pushButtonGraphique_clicked()
}
