//==============================================================================
// Name        : Parametres.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/01/2016)
// Description : Header file of the Parametres class
//==============================================================================

#ifndef PARAMETRES_H_
#define PARAMETRES_H_

#include "ParametresAffichage.h"
#include "ParametresConversion.h"
#include "ParametresExport.h"
#include "ParametresFichiers.h"
#include "ParametresRecherche.h"
#include <QString>

class Parametres
{
public:
    // Constructeurs et destructeurs
    Parametres();
    Parametres(const ParametresFichiers& parametresFichiers,
            const ParametresAffichage& parametresAffichage,
            const ParametresConversion& parametresConversion,
            const ParametresRecherche& parametresRecherche,
            const ParametresExport& parametresExport);
    Parametres(const Parametres& parametres);
    virtual ~Parametres();

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
    void copy(const Parametres& parametres);
    bool equals(const Parametres& parametres) const;
    void fromString(const QString& fromString, const char& sep);
    const QString toString(const char& sep) const;

    // Méthodes spécifiques

private:
    // Attributs de classe
    ParametresFichiers parametresFichiers;
    ParametresAffichage parametresAffichage;
    ParametresConversion parametresConversion;
    ParametresRecherche parametresRecherche;
    ParametresExport parametresExport;
};

#endif /* PARAMETRES_H_ */
