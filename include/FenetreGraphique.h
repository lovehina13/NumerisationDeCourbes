//==============================================================================
// Name        : FenetreGraphique.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.3.0 (07/08/2021)
// Description : Header file of the FenetreGraphique class
//==============================================================================

#ifndef FENETREGRAPHIQUE_H
#define FENETREGRAPHIQUE_H

#include "ParametresAffichage.h"
#include "ParametresFichiers.h"
#include "ParametresGraphique.h"
#include "ParametresPoint.h"
#include "ParametresTrait.h"
#include "Point.h"
#include <QAbstractButton>
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
    explicit FenetreGraphique(QWidget* parent = nullptr);
    virtual ~FenetreGraphique() override;

    // Getters
    const QList<Courbe>& getListeDeCourbes() const;
    const QList<Point>& getListeDePointsManuels() const;
    const ParametresGraphique& getParametresGraphique() const;
    const ParametresAffichage& getParametresAffichage() const;
    const ParametresFichiers& getParametresFichiers() const;

    // Setters
    void setListeDeCourbes(const QList<Courbe>& listeDeCourbes);
    void setListeDePointsManuels(const QList<Point>& listeDePointsManuels);
    void setParametresGraphique(const ParametresGraphique& parametresGraphique);
    void setParametresAffichage(const ParametresAffichage& parametresAffichage);
    void setParametresFichiers(const ParametresFichiers& parametresFichiers);

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
    void exporterGraphique();

protected slots:
    // Connecteurs spécifiques
    void on_lineEditAxeHorizontalBorneInferieure_textChanged(const QString& text);
    void on_lineEditAxeHorizontalBorneSuperieure_textChanged(const QString& text);
    void on_lineEditAxeHorizontalPasPrincipal_textChanged(const QString& text);
    void on_lineEditAxeHorizontalPasSecondaire_textChanged(const QString& text);
    void on_checkBoxAxeHorizontalGrillePrincipale_stateChanged(int state);
    void on_checkBoxAxeHorizontalGrilleSecondaire_stateChanged(int state);
    void on_lineEditAxeVerticalBorneInferieure_textChanged(const QString& text);
    void on_lineEditAxeVerticalBorneSuperieure_textChanged(const QString& text);
    void on_lineEditAxeVerticalPasPrincipal_textChanged(const QString& text);
    void on_lineEditAxeVerticalPasSecondaire_textChanged(const QString& text);
    void on_checkBoxAxeVerticalGrillePrincipale_stateChanged(int state);
    void on_checkBoxAxeVerticalGrilleSecondaire_stateChanged(int state);
    void on_buttonBox_clicked(QAbstractButton* button);

private:
    // Attributs de classe
    Ui::FenetreGraphique* _ui { nullptr };
    QList<Courbe> _listeDeCourbes;
    QList<Point> _listeDePointsManuels;
    ParametresGraphique _parametresGraphique;
    ParametresAffichage _parametresAffichage;
    ParametresFichiers _parametresFichiers;
};

#endif /* FENETREGRAPHIQUE_H */
