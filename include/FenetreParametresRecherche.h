//==============================================================================
// Name        : FenetreParametresRecherche.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.3.0 (07/08/2021)
// Description : Header file of the FenetreParametresRecherche class
//==============================================================================

#ifndef FENETREPARAMETRESRECHERCHE_H
#define FENETREPARAMETRESRECHERCHE_H

#include "ParametresRecherche.h"
#include <QDialog>
#include <QWidget>

namespace Ui
{
class FenetreParametresRecherche;
}

class FenetreParametresRecherche : public QDialog
{
    Q_OBJECT

public:
    // Constructeurs et destructeurs
    explicit FenetreParametresRecherche(QWidget* parent = nullptr);
    virtual ~FenetreParametresRecherche() override;

    // Getters
    const ParametresRecherche& getParametresRecherche() const;

    // Setters
    void setParametresRecherche(const ParametresRecherche& parametresRecherche);

    // Méthodes génériques

    // Méthodes spécifiques
    void actualiserElementsGraphiques();

protected:
    // Méthodes spécifiques
    void initialiserElementsGraphiques();

protected slots:
    // Connecteurs spécifiques
    void on_spinBoxSeuilToleranceNiveauxDeGris_valueChanged(int value);
    void on_doubleSpinBoxSeuilToleranceNiveauxDeGrisFacteur_valueChanged(double value);
    void on_spinBoxSeuilToleranceTeintesSaturees_valueChanged(int value);
    void on_doubleSpinBoxSeuilToleranceTeintesSatureesFacteur_valueChanged(double value);
    void on_checkBoxSelectionValeursMoyennes_stateChanged(int state);
    void on_checkBoxSelectionValeursMinimales_stateChanged(int state);
    void on_checkBoxSelectionValeursMaximales_stateChanged(int state);

private:
    // Attributs de classe
    Ui::FenetreParametresRecherche* _ui { nullptr };
    ParametresRecherche _parametresRecherche;
};

#endif /* FENETREPARAMETRESRECHERCHE_H */
