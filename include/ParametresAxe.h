//==============================================================================
// Name        : ParametresAxe.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Header file of the ParametresAxe class
//==============================================================================

#ifndef PARAMETRESAXE_H
#define PARAMETRESAXE_H

#include <QChar>
#include <QString>

class ParametresAxe
{
public:
    // Constructeurs et destructeurs
    ParametresAxe() = default;
    ParametresAxe(const double& borneInferieure, const double& borneSuperieure,
            const double& pasPrincipal, const double& pasSecondaire, const bool& grillePrincipale,
            const bool& grilleSecondaire);

    // Opérateurs
    bool operator==(const ParametresAxe& parametresAxe) const = default;
    bool operator!=(const ParametresAxe& parametresAxe) const = default;

    // Getters
    const double& getBorneInferieure() const;
    const double& getBorneSuperieure() const;
    const double& getPasPrincipal() const;
    const double& getPasSecondaire() const;
    const bool& getGrillePrincipale() const;
    const bool& getGrilleSecondaire() const;

    // Setters
    void setBorneInferieure(const double& borneInferieure);
    void setBorneSuperieure(const double& borneSuperieure);
    void setPasPrincipal(const double& pasPrincipal);
    void setPasSecondaire(const double& pasSecondaire);
    void setGrillePrincipale(const bool& grillePrincipale);
    void setGrilleSecondaire(const bool& grilleSecondaire);

    // Méthodes génériques
    void clear();
    void set(const double& borneInferieure, const double& borneSuperieure,
            const double& pasPrincipal, const double& pasSecondaire, const bool& grillePrincipale,
            const bool& grilleSecondaire);
    void fromString(const QString& fromString, const QChar& sep);
    const QString toString(const QChar& sep) const;

    // Méthodes spécifiques
    void ajuster();
    void ajusterBornes();
    void ajusterPasPrincipal();
    void ajusterPasSecondaire();

    // Définition des valeurs par défaut des paramètres d'axe
    static constexpr double borneInferieureDefaut { 0.0 };
    static constexpr double borneSuperieureDefaut { 0.0 };
    static constexpr double pasPrincipalDefaut { 0.0 };
    static constexpr double pasSecondaireDefaut { 0.0 };
    static const bool grillePrincipaleDefaut { true };
    static const bool grilleSecondaireDefaut { false };
    static const int nombreElementsPasPrincipalDefaut { 5 };
    static const int nombreElementsPasSecondaireDefaut { 5 };

private:
    // Attributs de classe
    double _borneInferieure { borneInferieureDefaut };
    double _borneSuperieure { borneSuperieureDefaut };
    double _pasPrincipal { pasPrincipalDefaut };
    double _pasSecondaire { pasSecondaireDefaut };
    bool _grillePrincipale { grillePrincipaleDefaut };
    bool _grilleSecondaire { grilleSecondaireDefaut };
};

#endif /* PARAMETRESAXE_H */
