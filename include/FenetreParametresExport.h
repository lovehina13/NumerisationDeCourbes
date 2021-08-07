//==============================================================================
// Name        : FenetreParametresExport.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Header file of the FenetreParametresExport class
//==============================================================================

#ifndef FENETREPARAMETRESEXPORT_H
#define FENETREPARAMETRESEXPORT_H

#include "ParametresExport.h"
#include <QDialog>
#include <QWidget>

namespace Ui
{
class FenetreParametresExport;
}

class FenetreParametresExport : public QDialog
{
    Q_OBJECT

public:
    // Constructeurs et destructeurs
    explicit FenetreParametresExport(QWidget* parent = nullptr);
    virtual ~FenetreParametresExport() override;

    // Getters
    const ParametresExport& getParametresExport() const;

    // Setters
    void setParametresExport(const ParametresExport& parametresExport);

    // Méthodes génériques

    // Méthodes spécifiques
    void actualiserElementsGraphiques();

protected:
    // Méthodes spécifiques
    void initialiserElementsGraphiques();

protected slots:
    // Connecteurs spécifiques
    void on_comboBoxCaractereSeparation_currentIndexChanged(int index);
    void on_comboBoxFormatNotationNombres_currentIndexChanged(int index);
    void on_comboBoxCaractereSeparateurDecimal_currentIndexChanged(int index);
    void on_spinBoxNombreDecimalesOuChiffresSignificatifs_valueChanged(int value);
    void on_lineEditSeuilInterpolationNumerique_textChanged(const QString& text);

private:
    // Attributs de classe
    Ui::FenetreParametresExport* _ui { nullptr };
    ParametresExport _parametresExport;
};

#endif /* FENETREPARAMETRESEXPORT_H */
