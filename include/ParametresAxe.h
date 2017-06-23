//==============================================================================
// Name        : ParametresAxe.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.5 (07/06/2017)
// Description : Header file of the ParametresAxe class
//==============================================================================

#ifndef PARAMETRESAXE_H_
#define PARAMETRESAXE_H_

#include <QString>

class ParametresAxe
{
public:
    // Constructeurs et destructeurs
    ParametresAxe();
    ParametresAxe(const double& borneInferieure, const double& borneSuperieure,
            const double& pasPrincipal, const double& pasSecondaire);
    ParametresAxe(const ParametresAxe& parametresAxe);
    virtual ~ParametresAxe();

    // Getters
    const double& getBorneInferieure() const;
    const double& getBorneSuperieure() const;
    const double& getPasPrincipal() const;
    const double& getPasSecondaire() const;

    // Setters
    void setBorneInferieure(const double& borneInferieure);
    void setBorneSuperieure(const double& borneSuperieure);
    void setPasPrincipal(const double& pasPrincipal);
    void setPasSecondaire(const double& pasSecondaire);

    // Méthodes génériques
    void clear();
    void set(const double& borneInferieure, const double& borneSuperieure,
            const double& pasPrincipal, const double& pasSecondaire);
    void copy(const ParametresAxe& parametresAxe);
    bool equals(const ParametresAxe& parametresAxe) const;
    void fromString(const QString& fromString, const char& sep);
    const QString toString(const char& sep) const;

    // Méthodes spécifiques
    // TODO Méthodes spécifiques "ParametresAxe"

    // Définition des valeurs par défaut des paramètres d'axe
    static const double borneInferieureDefaut;
    static const double borneSuperieureDefaut;
    static const double pasPrincipalDefaut;
    static const double pasSecondaireDefaut;

private:
    // Attributs de classe
    double borneInferieure;
    double borneSuperieure;
    double pasPrincipal;
    double pasSecondaire;
};

#endif /* PARAMETRESAXE_H_ */
