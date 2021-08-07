//==============================================================================
// Name        : FenetreParametresAffichage.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.3.0 (07/08/2021)
// Description : Header file of the FenetreParametresAffichage class
//==============================================================================

#ifndef FENETREPARAMETRESAFFICHAGE_H
#define FENETREPARAMETRESAFFICHAGE_H

#include "ParametresAffichage.h"
#include <QDialog>
#include <QWidget>

namespace Ui
{
class FenetreParametresAffichage;
}

class FenetreParametresAffichage : public QDialog
{
    Q_OBJECT

public:
    // Constructeurs et destructeurs
    explicit FenetreParametresAffichage(QWidget* parent = nullptr);
    virtual ~FenetreParametresAffichage() override;

    // Getters
    const ParametresAffichage& getParametresAffichage() const;

    // Setters
    void setParametresAffichage(const ParametresAffichage& parametresAffichage);

    // Méthodes génériques

    // Méthodes spécifiques
    void actualiserElementsGraphiques();

protected:
    // Méthodes spécifiques
    void initialiserElementsGraphiques();

protected slots:
    // Connecteurs spécifiques
    void on_comboBoxFormatNotationNombres_currentIndexChanged(int index);
    void on_spinBoxNombreDecimalesOuChiffresSignificatifs_valueChanged(int value);
    void on_pushButtonCouleurAxes_clicked();
    void on_comboBoxStyleAxes_currentIndexChanged(int index);
    void on_spinBoxEpaisseurAxes_valueChanged(int value);
    void on_pushButtonCouleurCourbes_clicked();
    void on_comboBoxStyleCourbes_currentIndexChanged(int index);
    void on_spinBoxEpaisseurCourbes_valueChanged(int value);
    void on_pushButtonCouleurPointsAxes_clicked();
    void on_comboBoxStylePointsAxes_currentIndexChanged(int index);
    void on_spinBoxEpaisseurPointsAxes_valueChanged(int value);
    void on_pushButtonCouleurPointsCourbes_clicked();
    void on_comboBoxStylePointsCourbes_currentIndexChanged(int index);
    void on_spinBoxEpaisseurPointsCourbes_valueChanged(int value);
    void on_pushButtonCouleurPointsManuels_clicked();
    void on_comboBoxStylePointsManuels_currentIndexChanged(int index);
    void on_spinBoxEpaisseurPointsManuels_valueChanged(int value);

private:
    // Attributs de classe
    Ui::FenetreParametresAffichage* _ui { nullptr };
    ParametresAffichage _parametresAffichage;
};

#endif /* FENETREPARAMETRESAFFICHAGE_H */
