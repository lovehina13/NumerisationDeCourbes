//==============================================================================
// Name        : FenetreGraphique.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.5 (07/06/2017)
// Description : Header file of the FenetreGraphique class
//==============================================================================

#ifndef FENETREGRAPHIQUE_H_
#define FENETREGRAPHIQUE_H_

#include "ParametresAffichage.h"
#include "ParametresGraphique.h"
#include "ParametresPoint.h"
#include "ParametresTrait.h"
#include "Point.h"
#include <QDialog>
#include <QList>
#include <QWidget>

namespace Ui
{
class FenetreGraphique;
}

class FenetreGraphique : public QDialog
{
    Q_OBJECT

public:
    // Constructeurs et destructeurs
    explicit FenetreGraphique(QWidget* parent = 0);
    ~FenetreGraphique();

    // Getters
    const QList<Courbe>& getListeDeCourbes() const;
    const QList<Point>& getListeDePointsManuels() const;
    const ParametresGraphique& getParametresGraphique() const;
    const ParametresAffichage& getParametresAffichage() const;

    // Setters
    void setListeDeCourbes(const QList<Courbe>& listeDeCourbes);
    void setListeDePointsManuels(const QList<Point>& listeDePointsManuels);
    void setParametresGraphique(const ParametresGraphique& parametresGraphique);
    void setParametresAffichage(const ParametresAffichage& parametresAffichage);

    // Méthodes génériques

    // Méthodes spécifiques
    void actualiserElementsGraphiques();

protected:
    // Méthodes spécifiques
    void initialiserElementsGraphiques();
    void effacerGraphique();
    void dessinerGraphique();
    void dessinerRepereGraphique();
    void dessinerGrilleGraphique();
    void dessinerCourbe(const Courbe& courbe);
    void dessinerPointManuel(const Point& pointManuel);
    void dessinerCourbeGraphique(const Courbe& courbe, const ParametresTrait& parametresCourbe);
    void dessinerPointGraphique(const Point& point, const ParametresPoint& parametresPoint);

protected slots:
    // Connecteurs spécifiques
    void on_lineEditAxeHorizontalBorneInferieure_textChanged();
    void on_lineEditAxeHorizontalBorneSuperieure_textChanged();
    void on_lineEditAxeHorizontalPasPrincipal_textChanged();
    void on_lineEditAxeHorizontalPasSecondaire_textChanged();
    void on_checkBoxAxeHorizontalGrillePrincipale_stateChanged();
    void on_checkBoxAxeHorizontalGrilleSecondaire_stateChanged();
    void on_lineEditAxeVerticalBorneInferieure_textChanged();
    void on_lineEditAxeVerticalBorneSuperieure_textChanged();
    void on_lineEditAxeVerticalPasPrincipal_textChanged();
    void on_lineEditAxeVerticalPasSecondaire_textChanged();
    void on_checkBoxAxeVerticalGrillePrincipale_stateChanged();
    void on_checkBoxAxeVerticalGrilleSecondaire_stateChanged();

private:
    // Attributs de classe
    Ui::FenetreGraphique* ui;
    QList<Courbe> listeDeCourbes;
    QList<Point> listeDePointsManuels;
    ParametresGraphique parametresGraphique;
    ParametresAffichage parametresAffichage;
};

#endif /* FENETREGRAPHIQUE_H_ */
