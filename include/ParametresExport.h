//==============================================================================
// Name        : ParametresExport.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Header file of the ParametresExport class
//==============================================================================

#ifndef PARAMETRESEXPORT_H
#define PARAMETRESEXPORT_H

#include <QChar>
#include <QMap>
#include <QString>

class ParametresExport
{
public:
    // Enumération des formats de notation des nombres
    enum FormatNotationNombres
    {
        STANDARD, SCIENTIFIQUE
    };

    // Enumération des caractères de séparation
    enum CaractereSeparation
    {
        ESPACE, TABULATION, POINT_VIRGULE
    };

    // Enumération des caractères de séparateur décimal
    enum CaractereSeparateurDecimal
    {
        POINT, VIRGULE
    };

    // Constructeurs et destructeurs
    ParametresExport() = default;
    ParametresExport(const FormatNotationNombres& formatNotationNombres,
            const int& nombreChiffresSignificatifs, const CaractereSeparation& caractereSeparation,
            const CaractereSeparateurDecimal& caractereSeparateurDecimal,
            const double& seuilInterpolationNumerique);

    // Opérateurs
    bool operator==(const ParametresExport& parametresExport) const = default;
    bool operator!=(const ParametresExport& parametresExport) const = default;

    // Getters
    const FormatNotationNombres& getFormatNotationNombres() const;
    const int& getNombreChiffresSignificatifs() const;
    const CaractereSeparation& getCaractereSeparation() const;
    const CaractereSeparateurDecimal& getCaractereSeparateurDecimal() const;
    const double& getSeuilInterpolationNumerique() const;

    // Setters
    void setFormatNotationNombres(const FormatNotationNombres& formatNotationNombres);
    void setNombreChiffresSignificatifs(const int& nombreChiffresSignificatifs);
    void setCaractereSeparation(const CaractereSeparation& caractereSeparation);
    void setCaractereSeparateurDecimal(
            const CaractereSeparateurDecimal& caractereSeparateurDecimal);
    void setSeuilInterpolationNumerique(const double& seuilInterpolationNumerique);

    // Méthodes génériques
    void clear();
    void set(const FormatNotationNombres& formatNotationNombres,
            const int& nombreChiffresSignificatifs, const CaractereSeparation& caractereSeparation,
            const CaractereSeparateurDecimal& caractereSeparateurDecimal,
            const double& seuilInterpolationNumerique);
    void fromString(const QString& fromString, const QChar& sep);
    const QString toString(const QChar& sep) const;

    // Méthodes spécifiques
    const QChar getFormatNotationNombresCaractere() const;
    const QString getFormatNotationNombresTexte() const;
    const QChar getCaractereSeparationCaractere() const;
    const QString getCaractereSeparationTexte() const;
    const QChar getCaractereSeparateurDecimalCaractere() const;
    const QString getCaractereSeparateurDecimalTexte() const;
    void setFormatNotationNombresCaractere(const QChar& formatNotationNombresCaractere);
    void setFormatNotationNombresTexte(const QString& formatNotationNombresTexte);
    void setCaractereSeparationCaractere(const QChar& caractereSeparationCaractere);
    void setCaractereSeparationTexte(const QString& caractereSeparationTexte);
    void setCaractereSeparateurDecimalCaractere(const QChar& caractereSeparateurDecimalCaractere);
    void setCaractereSeparateurDecimalTexte(const QString& caractereSeparateurDecimalTexte);

    // Définition des valeurs par défaut des paramètres d'export
    static const FormatNotationNombres formatNotationNombresDefaut { STANDARD };
    static const int nombreChiffresSignificatifsDefaut { 6 };
    static const CaractereSeparation caractereSeparationDefaut { TABULATION };
    static const CaractereSeparateurDecimal caractereSeparateurDecimalDefaut { POINT };
    static constexpr double seuilInterpolationNumeriqueDefaut { 0.0 };

private:
    // Attributs de classe
    FormatNotationNombres _formatNotationNombres { formatNotationNombresDefaut };
    int _nombreChiffresSignificatifs { nombreChiffresSignificatifsDefaut };
    CaractereSeparation _caractereSeparation { caractereSeparationDefaut };
    CaractereSeparateurDecimal _caractereSeparateurDecimal { caractereSeparateurDecimalDefaut };
    double _seuilInterpolationNumerique { seuilInterpolationNumeriqueDefaut };

    // Définition des correspondances
    static const QMap<FormatNotationNombres, QChar> _formatNotationNombresCaractere;
    static const QMap<FormatNotationNombres, QString> _formatNotationNombresTexte;
    static const QMap<CaractereSeparation, QChar> _caractereSeparationCaractere;
    static const QMap<CaractereSeparation, QString> _caractereSeparationTexte;
    static const QMap<CaractereSeparateurDecimal, QChar> _caractereSeparateurDecimalCaractere;
    static const QMap<CaractereSeparateurDecimal, QString> _caractereSeparateurDecimalTexte;
};

#endif /* PARAMETRESEXPORT_H */
