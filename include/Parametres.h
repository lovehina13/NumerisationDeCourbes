//==============================================================================
// Name        : Parametres.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.3.0 (07/08/2021)
// Description : Header file of the Parametres class
//==============================================================================

#ifndef PARAMETRES_H
#define PARAMETRES_H

#include "ParametresAffichage.h"
#include "ParametresConversion.h"
#include "ParametresExport.h"
#include "ParametresFichiers.h"
#include "ParametresRecherche.h"
#include <QChar>
#include <QString>

class Parametres
{
public:
    // Constructeurs et destructeurs
    Parametres() = default;
    Parametres(const ParametresFichiers& parametresFichiers,
            const ParametresAffichage& parametresAffichage,
            const ParametresConversion& parametresConversion,
            const ParametresRecherche& parametresRecherche,
            const ParametresExport& parametresExport);

    // Opérateurs
    bool operator==(const Parametres& parametres) const = default;
    bool operator!=(const Parametres& parametres) const = default;

    // Getters
    const ParametresFichiers& getParametresFichiers() const;
    const ParametresAffichage& getParametresAffichage() const;
    const ParametresConversion& getParametresConversion() const;
    const ParametresRecherche& getParametresRecherche() const;
    const ParametresExport& getParametresExport() const;

    // Setters
    void setParametresFichiers(const ParametresFichiers& parametresFichiers);
    void setParametresAffichage(const ParametresAffichage& parametresAffichage);
    void setParametresConversion(const ParametresConversion& parametresConversion);
    void setParametresRecherche(const ParametresRecherche& parametresRecherche);
    void setParametresExport(const ParametresExport& parametresExport);

    // Méthodes génériques
    void clear();
    void set(const ParametresFichiers& parametresFichiers,
            const ParametresAffichage& parametresAffichage,
            const ParametresConversion& parametresConversion,
            const ParametresRecherche& parametresRecherche,
            const ParametresExport& parametresExport);
    void fromString(const QString& fromString, const QChar& sep);
    const QString toString(const QChar& sep) const;

    // Méthodes spécifiques

private:
    // Attributs de classe
    ParametresFichiers _parametresFichiers;
    ParametresAffichage _parametresAffichage;
    ParametresConversion _parametresConversion;
    ParametresRecherche _parametresRecherche;
    ParametresExport _parametresExport;
};

#endif /* PARAMETRES_H */
