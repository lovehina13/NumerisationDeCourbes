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
#include <QWidget>

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

    // Setters

    // Méthodes génériques

    // Méthodes spécifiques

protected:
    // Méthodes spécifiques
    void initialiserElementsGraphiques();
    void creerNouvelleEtude();
    void chargerEtudeExistante();
    void sauverEtudeCourante();
    void exporterEtudeCourante();
    void verifierEtatSauvegardeEtude();
    void actualiserEtudeReference();
    void actualiserCoordonneesPoints();
    void actualiserCoordonneesPointDepart();
    void actualiserCoordonneesPointArrivee();
    void actualiserCoordonneesPointManuel();
    void actualiserCoordonneesListeDePoints();
    void effacerVueGraphiqueEtude();
    void dessinerVueGraphiqueEtude();

protected slots:
    // Connecteurs spécifiques
    void on_actionCreer_triggered();
    void on_actionCharger_triggered();
    void on_actionSauver_triggered();
    void on_actionExporter_triggered();
    void on_actionQuitter_triggered();
    void on_actionParametresAffichage_triggered();
    void on_actionParametresConversion_triggered();
    void on_actionParametresRecherche_triggered();
    void on_actionParametresExport_triggered();
    void on_actionDocumentation_triggered();
    void on_actionAbout_triggered();
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
    void on_pushButtonPointX0_clicked();
    void on_pushButtonPointX1_clicked();
    void on_pushButtonPointY0_clicked();
    void on_pushButtonPointY1_clicked();
    void on_lineEditPointDepartXPixel_textChanged();
    void on_lineEditPointDepartYPixel_textChanged();
    void on_lineEditPointArriveeXPixel_textChanged();
    void on_lineEditPointArriveeYPixel_textChanged();
    void on_lineEditPointManuelXPixel_textChanged();
    void on_lineEditPointManuelYPixel_textChanged();
    void on_pushButtonPointDepart_clicked();
    void on_pushButtonPointArrivee_clicked();
    void on_pushButtonPointManuel_clicked();
    void on_pushButtonAjouter_clicked();
    void on_pushButtonRechercher_clicked();
    void on_pushButtonSupprimer_clicked();
    void on_pushButtonGraphique_clicked();

private:
    // Attributs de classe
    Ui::EcranPrincipal* ui;
    Etude etude;
    Etude etudeReference;
};

#endif /* ECRANPRINCIPAL_H_ */
