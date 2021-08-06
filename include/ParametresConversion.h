//==============================================================================
// Name        : ParametresConversion.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Header file of the ParametresConversion class
//==============================================================================

#ifndef PARAMETRESCONVERSION_H
#define PARAMETRESCONVERSION_H

#include <QChar>
#include <QMap>
#include <QString>

class ParametresConversion
{
public:
    // Enumération des méthodes de conversion
    enum MethodeConversion
    {
        BRUTE, NOIR_ET_BLANC, NIVEAUX_DE_GRIS, TEINTES_SATUREES
    };

    // Constructeurs et destructeurs
    ParametresConversion() = default;
    ParametresConversion(const MethodeConversion& methodeConversion, const int& seuilNoirEtBlanc,
            const int& nombreNiveauxDeGris, const int& nombreTeintesSaturees,
            const int& seuilSaturation);

    // Opérateurs
    bool operator==(const ParametresConversion& parametresConversion) const = default;
    bool operator!=(const ParametresConversion& parametresConversion) const = default;

    // Getters
    const MethodeConversion& getMethodeConversion() const;
    const int& getSeuilNoirEtBlanc() const;
    const int& getNombreNiveauxDeGris() const;
    const int& getNombreTeintesSaturees() const;
    const int& getSeuilSaturation() const;

    // Setters
    void setMethodeConversion(const MethodeConversion& methodeConversion);
    void setSeuilNoirEtBlanc(const int& seuilNoirEtBlanc);
    void setNombreNiveauxDeGris(const int& nombreNiveauxDeGris);
    void setNombreTeintesSaturees(const int& nombreTeintesSaturees);
    void setSeuilSaturation(const int& seuilSaturation);

    // Méthodes génériques
    void clear();
    void set(const MethodeConversion& methodeConversion, const int& seuilNoirEtBlanc,
            const int& nombreNiveauxDeGris, const int& nombreTeintesSaturees,
            const int& seuilSaturation);
    void fromString(const QString& fromString, const QChar& sep);
    const QString toString(const QChar& sep) const;

    // Méthodes spécifiques
    const QString getMethodeConversionTexte() const;
    double getSeuilNoirEtBlancFacteur() const;
    double getSeuilSaturationFacteur() const;
    void setMethodeConversionTexte(const QString& methodeConversionTexte);
    void setSeuilNoirEtBlancFacteur(const double& seuilNoirEtBlancFacteur);
    void setSeuilSaturationFacteur(const double& seuilSaturationFacteur);

    // Définition des valeurs par défaut des paramètres de conversion
    static const MethodeConversion methodeConversionDefaut { BRUTE };
    static const int seuilNoirEtBlancDefaut { 223 };
    static const int nombreNiveauxDeGrisDefaut { 5 };
    static const int nombreTeintesSatureesDefaut { 6 };
    static const int seuilSaturationDefaut { 32 };

private:
    // Attributs de classe
    MethodeConversion _methodeConversion { methodeConversionDefaut };
    int _seuilNoirEtBlanc { seuilNoirEtBlancDefaut };
    int _nombreNiveauxDeGris { nombreNiveauxDeGrisDefaut };
    int _nombreTeintesSaturees { nombreTeintesSatureesDefaut };
    int _seuilSaturation { seuilSaturationDefaut };

    // Définition des correspondances
    static const QMap<MethodeConversion, QString> _methodeConversionTexte;
};

#endif /* PARAMETRESCONVERSION_H */
