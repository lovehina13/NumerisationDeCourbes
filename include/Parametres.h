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
    Parametres(const QString& cheminFichierEtude, const QString& cheminFichierImageSource,
            const QString& cheminFichierImageConvertie, const QString& cheminFichierExport,
            const int& nombreChiffresSignificatifs, const int& seuilToleranceNiveauxDeGris,
            const int& seuilToleranceTeintesSaturees, const int& methodeConversion,
            const int& seuilNoirEtBlanc, const int& nombreNiveauxDeGris,
            const int& nombreTeintesSaturees, const int& seuilSaturation);
    Parametres(const Parametres& parametres);
    virtual ~Parametres();

    // Getters
    const QString& getCheminFichierEtude() const;
    const QString& getCheminFichierImageSource() const;
    const QString& getCheminFichierImageConvertie() const;
    const QString& getCheminFichierExport() const;
    const int& getNombreChiffresSignificatifs() const;
    const int& getSeuilToleranceNiveauxDeGris() const;
    const int& getSeuilToleranceTeintesSaturees() const;
    const int& getMethodeConversion() const;
    const int& getSeuilNoirEtBlanc() const;
    const int& getNombreNiveauxDeGris() const;
    const int& getNombreTeintesSaturees() const;
    const int& getSeuilSaturation() const;

    // Setters
    void setCheminFichierEtude(const QString& cheminFichierEtude);
    void setCheminFichierImageSource(const QString& cheminFichierImageSource);
    void setCheminFichierImageConvertie(const QString& cheminFichierImageConvertie);
    void setCheminFichierExport(const QString& cheminFichierExport);
    void setNombreChiffresSignificatifs(const int& nombreChiffresSignificatifs);
    void setSeuilToleranceNiveauxDeGris(const int& seuilToleranceNiveauxDeGris);
    void setSeuilToleranceTeintesSaturees(const int& seuilToleranceTeintesSaturees);
    void setMethodeConversion(const int& methodeConversion);
    void setSeuilNoirEtBlanc(const int& seuilNoirEtBlanc);
    void setNombreNiveauxDeGris(const int& nombreNiveauxDeGris);
    void setNombreTeintesSaturees(const int& nombreTeintesSaturees);
    void setSeuilSaturation(const int& seuilSaturation);

    // Méthodes génériques
    void clear();
    void set(const QString& cheminFichierEtude, const QString& cheminFichierImageSource,
            const QString& cheminFichierImageConvertie, const QString& cheminFichierExport,
            const int& nombreChiffresSignificatifs, const int& seuilToleranceNiveauxDeGris,
            const int& seuilToleranceTeintesSaturees, const int& methodeConversion,
            const int& seuilNoirEtBlanc, const int& nombreNiveauxDeGris,
            const int& nombreTeintesSaturees, const int& seuilSaturation);
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
    QString cheminFichierImageSource;
    QString cheminFichierImageConvertie;
    QString cheminFichierExport;
    int nombreChiffresSignificatifs;
    int seuilToleranceNiveauxDeGris;
    int seuilToleranceTeintesSaturees;
    int methodeConversion;
    int seuilNoirEtBlanc;
    int nombreNiveauxDeGris;
    int nombreTeintesSaturees;
    int seuilSaturation;
};

#endif /* PARAMETRES_H_ */

/* TODO Paramètres supplémentaires :
 *          - affichage :
 *              - point d'axe : marqueur, couleur, épaisseur
 *              - point de courbe : marqueur, couleur, épaisseur
 *              - point manuel : marqueur, couleur, épaisseur
 *              - trait d'axe : style, couleur, épaisseur
 *              - trait de courbe : style, couleur, épaisseur
 *              - affichage des nombres : notation classique/scientifique, nombre de décimales/chiffres significatifs
 *          - recherche :
 *              - sélection des valeurs : moyennes, minimales et maximales
 *              - critères : primaires, secondaires
 *          - export :
 *              - caractère de séparation
 *              - seuil d'interpolation
 *              - affichage des nombres : notation classique/scientifique, nombre de décimales/chiffres significatifs
 * TODO Diviser en plusieurs classes
 */
