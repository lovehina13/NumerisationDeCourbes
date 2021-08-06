//==============================================================================
// Name        : ParametresGraphique.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Header file of the ParametresGraphique class
//==============================================================================

#ifndef PARAMETRESGRAPHIQUE_H
#define PARAMETRESGRAPHIQUE_H

#include "ParametresAxe.h"
#include <QChar>
#include <QString>

class ParametresGraphique
{
public:
    // Constructeurs et destructeurs
    ParametresGraphique() = default;
    ParametresGraphique(const ParametresAxe& parametresAxeHorizontal,
            const ParametresAxe& parametresAxeVertical);

    // Opérateurs
    bool operator==(const ParametresGraphique& parametresGraphique) const = default;
    bool operator!=(const ParametresGraphique& parametresGraphique) const = default;

    // Getters
    const ParametresAxe& getParametresAxeHorizontal() const;
    const ParametresAxe& getParametresAxeVertical() const;

    // Setters
    void setParametresAxeHorizontal(const ParametresAxe& parametresAxeHorizontal);
    void setParametresAxeVertical(const ParametresAxe& parametresAxeVertical);

    // Méthodes génériques
    void clear();
    void set(const ParametresAxe& parametresAxeHorizontal,
            const ParametresAxe& parametresAxeVertical);
    void fromString(const QString& fromString, const QChar& sep);
    const QString toString(const QChar& sep) const;

    // Méthodes spécifiques

private:
    // Attributs de classe
    ParametresAxe _parametresAxeHorizontal;
    ParametresAxe _parametresAxeVertical;
};

#endif /* PARAMETRESGRAPHIQUE_H */
