//==============================================================================
// Name        : ParametresExport.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (24/06/2016)
// Description : Header file of the ParametresExport class
//==============================================================================

#ifndef PARAMETRESEXPORT_H_
#define PARAMETRESEXPORT_H_

#include <QString>

class ParametresExport
{
public:
    // Constructeurs et destructeurs
    ParametresExport();
    ParametresExport(const int& formatNotationNombres, const int& nombreChiffresSignificatifs,
            const char& caractereSeparation, const char& caractereSeparateurDecimal,
            const double& seuilInterpolationNumerique);
    ParametresExport(const ParametresExport& parametresExport);
    virtual ~ParametresExport();

    // Getters
    const int& getFormatNotationNombres() const;
    const int& getNombreChiffresSignificatifs() const;
    const char& getCaractereSeparation() const;
    const char& getCaractereSeparateurDecimal() const;
    const double& getSeuilInterpolationNumerique() const;

    // Setters
    void setFormatNotationNombres(const int& formatNotationNombres);
    void setNombreChiffresSignificatifs(const int& nombreChiffresSignificatifs);
    void setCaractereSeparation(const char& caractereSeparation);
    void setCaractereSeparateurDecimal(const char& caractereSeparateurDecimal);
    void setSeuilInterpolationNumerique(const double& seuilInterpolationNumerique);

    // Méthodes génériques
    void clear();
    void set(const int& formatNotationNombres, const int& nombreChiffresSignificatifs,
            const char& caractereSeparation, const char& caractereSeparateurDecimal,
            const double& seuilInterpolationNumerique);
    void copy(const ParametresExport& parametresExport);
    bool equals(const ParametresExport& parametresExport) const;
    void fromString(const QString& fromString, const char& sep);
    const QString toString(const char& sep) const;

    // Méthodes spécifiques
    // TODO Méthodes spécifiques

    // Enumération des formats de notation des nombres
    enum formatsNotationNombres
    {
        STANDARD, SCIENTIFIQUE
    };

    // Définition des valeurs par défaut des paramètres d'export
    static const int formatNotationNombresDefaut = STANDARD;
    static const int nombreChiffresSignificatifsDefaut = 6;
    static const char caractereSeparationDefaut = '\t';
    static const char caractereSeparateurDecimalDefaut = '.';
    static constexpr double seuilInterpolationNumeriqueDefaut = 1.0;

private:
    // Attributs de classe
    int formatNotationNombres;
    int nombreChiffresSignificatifs;
    char caractereSeparation;
    char caractereSeparateurDecimal;
    double seuilInterpolationNumerique;
};

#endif /* PARAMETRESEXPORT_H_ */
