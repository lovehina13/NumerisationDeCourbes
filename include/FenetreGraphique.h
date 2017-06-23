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
    const QList<Point>& getListeDePoints() const;
    const ParametresGraphique& getParametresGraphique() const;
    const ParametresAffichage& getParametresAffichage() const;

    // Setters
    void setListeDePoints(const QList<Point>& listeDePoints);
    void setParametresGraphique(const ParametresGraphique& parametresGraphique);
    void setParametresAffichage(const ParametresAffichage& parametresAffichage);

    // Méthodes génériques

    // Méthodes spécifiques
    void actualiserElementsGraphiques();

protected:
    // Méthodes spécifiques
    void initialiserElementsGraphiques();

protected slots:
    // Connecteurs spécifiques
    void on_lineEditAxeHorizontalBorneInferieure_textChanged();
    void on_lineEditAxeHorizontalBorneSuperieure_textChanged();
    void on_lineEditAxeHorizontalPasPrincipal_textChanged();
    void on_lineEditAxeHorizontalPasSecondaire_textChanged();
    void on_lineEditAxeVerticalBorneInferieure_textChanged();
    void on_lineEditAxeVerticalBorneSuperieure_textChanged();
    void on_lineEditAxeVerticalPasPrincipal_textChanged();
    void on_lineEditAxeVerticalPasSecondaire_textChanged();

private:
    // Attributs de classe
    Ui::FenetreGraphique* ui;
    QList<Point> listeDePoints;
    ParametresGraphique parametresGraphique;
    ParametresAffichage parametresAffichage;
};

#endif /* FENETREGRAPHIQUE_H_ */
