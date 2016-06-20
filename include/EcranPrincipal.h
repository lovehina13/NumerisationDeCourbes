//==============================================================================
// Name        : EcranPrincipal.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (14/06/2016)
// Description : Header file of the EcranPrincipal class
//==============================================================================

#ifndef ECRANPRINCIPAL_H_
#define ECRANPRINCIPAL_H_

#include "Etude.h"
#include <QMainWindow>

namespace Ui
{
class EcranPrincipal;
}

class EcranPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    // Constructeurs et destructeurs
    explicit EcranPrincipal(QWidget* parent = 0);
    ~EcranPrincipal();

    // Getters
    // TODO Getters

    // Setters
    // TODO Setters

    // Méthodes génériques
    // TODO Méthodes génériques

    // Méthodes spécifiques
    // TODO Méthodes spécifiques

protected:
    // TODO Méthodes spécifiques
    void actualiserCoordonneesPoints();
    void actualiserCoordonneesPointDepart();
    void actualiserCoordonneesPointArrivee();
    void actualiserCoordonneesPointManuel();
    void actualiserCoordonneesListeDePoints();

protected slots:
    // Connecteurs spécifiques
    // TODO Connecteurs spécifiques
    void on_actionCreer_toggled();
    void on_actionCharger_toggled();
    void on_actionSauver_toggled();
    void on_actionExporter_toggled();
    void on_actionQuitter_toggled();
    void on_actionParametresAffichage_toggled();
    void on_actionParametresConversion_toggled();
    void on_actionParametresRecherche_toggled();
    void on_actionParametresExport_toggled();
    void on_actionDocumentation_toggled();
    void on_actionAbout_toggled();
    // TODO void on_graphicsViewImage_*();
    void on_radioButtonNoirEtBlanc_clicked();
    void on_radioButtonNiveauxDeGris_clicked();
    void on_radioButtonTeintesSaturees_clicked();
    void on_pushButtonConvertir_clicked();
    void on_pushButtonRestaurer_clicked();
    void on_lineEditPointX0XPixel_textChanged();
    void on_lineEditPointX0YPixel_textChanged();
    void on_lineEditPointX0Valeur_textChanged();
    void on_lineEditPointX1XPixel_textChanged();
    void on_lineEditPointX1YPixel_textChanged();
    void on_lineEditPointX1Valeur_textChanged();
    void on_lineEditPointY0XPixel_textChanged();
    void on_lineEditPointY0YPixel_textChanged();
    void on_lineEditPointY0Valeur_textChanged();
    void on_lineEditPointY1XPixel_textChanged();
    void on_lineEditPointY1YPixel_textChanged();
    void on_lineEditPointY1Valeur_textChanged();
    void on_lineEditPointDepartXPixel_textChanged();
    void on_lineEditPointDepartYPixel_textChanged();
    void on_lineEditPointArriveeXPixel_textChanged();
    void on_lineEditPointArriveeYPixel_textChanged();
    void on_lineEditPointManuelXPixel_textChanged();
    void on_lineEditPointManuelYPixel_textChanged();
    void on_pushButtonAjouter_clicked();
    void on_pushButtonRechercher_clicked();
    void on_pushButtonSupprimer_clicked();
    void on_pushButtonGraphique_clicked();

private:
    // Attributs de classe
    Ui::EcranPrincipal* ui;
    Etude etude;
};

#endif /* ECRANPRINCIPAL_H_ */
