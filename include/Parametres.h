//==============================================================================
// Name        : Parametres.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/01/2016)
// Description : Header file of the Parametres class
//==============================================================================

#ifndef PARAMETRES_H_
#define PARAMETRES_H_

#include <QString>

class Parametres
{
public:
    // Constructeurs et destructeurs
    Parametres();
    Parametres(const QString& cheminFichierEtude, const QString& cheminFichierImage,
            const QString& cheminFichierExport, const int& nombreChiffresSignificatifs,
            const int& seuilToleranceNiveauxDeGris, const int& seuilToleranceTeintesSaturees);
    Parametres(const Parametres& parametres);
    virtual ~Parametres();

    // Getters
    const QString& getCheminFichierEtude() const;
    const QString& getCheminFichierImage() const;
    const QString& getCheminFichierExport() const;
    const int& getNombreChiffresSignificatifs() const;
    const int& getSeuilToleranceNiveauxDeGris() const;
    const int& getSeuilToleranceTeintesSaturees() const;

    // Setters
    void setCheminFichierEtude(const QString& cheminFichierEtude);
    void setCheminFichierImage(const QString& cheminFichierImage);
    void setCheminFichierExport(const QString& cheminFichierExport);
    void setNombreChiffresSignificatifs(const int& nombreChiffresSignificatifs);
    void setSeuilToleranceNiveauxDeGris(const int& seuilToleranceNiveauxDeGris);
    void setSeuilToleranceTeintesSaturees(const int& seuilToleranceTeintesSaturees);

    // Méthodes génériques
    void clear();
    void initialize(const QString& cheminFichierEtude, const QString& cheminFichierImage,
            const QString& cheminFichierExport, const int& nombreChiffresSignificatifs,
            const int& seuilToleranceNiveauxDeGris, const int& seuilToleranceTeintesSaturees);
    void copy(const Parametres& parametres);
    bool equals(const Parametres& parametres) const;
    void fromString(const QString& fromString, const char& sep);
    const QString toString(const char& sep) const;

    // Méthodes spécifiques
    // TODO Méthodes spécifiques

    // Définition des valeurs par défaut des paramètres
    static const int nombreChiffresSignificatifsDefaut = 6;
    static const int seuilToleranceNiveauxDeGrisDefaut = 32;
    static const int seuilToleranceTeintesSatureesDefaut = 60;

private:
    // Attributs de classe
    QString cheminFichierEtude;
    QString cheminFichierImage;
    QString cheminFichierExport;
    int nombreChiffresSignificatifs;
    int seuilToleranceNiveauxDeGris;
    int seuilToleranceTeintesSaturees;
};

#endif /* PARAMETRES_H_ */
