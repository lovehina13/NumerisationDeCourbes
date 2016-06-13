//==============================================================================
// Name        : Parametres.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/01/2016)
// Description : Source file of the Parametres class
//==============================================================================

#include "Parametres.h"
#include "Image.h"

Parametres::Parametres() :
        nombreChiffresSignificatifs(nombreChiffresSignificatifsDefaut),
                seuilToleranceNiveauxDeGris(seuilToleranceNiveauxDeGrisDefaut),
                seuilToleranceTeintesSaturees(seuilToleranceTeintesSatureesDefaut),
                methodeConversion(Image::BRUTE), seuilNoirEtBlanc(Image::seuilNoirEtBlancDefaut),
                nombreNiveauxDeGris(Image::nombreNiveauxDeGrisDefaut),
                nombreTeintesSaturees(Image::nombreTeintesSatureesDefaut),
                seuilSaturation(Image::seuilSaturationDefaut)
{
    this->clear();
}

Parametres::Parametres(const QString& cheminFichierEtude, const QString& cheminFichierImageSource,
        const QString& cheminFichierImageConvertie, const QString& cheminFichierExport,
        const int& nombreChiffresSignificatifs, const int& seuilToleranceNiveauxDeGris,
        const int& seuilToleranceTeintesSaturees, const int& methodeConversion,
        const int& seuilNoirEtBlanc, const int& nombreNiveauxDeGris,
        const int& nombreTeintesSaturees, const int& seuilSaturation) :
        Parametres()
{
    this->set(cheminFichierEtude, cheminFichierImageSource, cheminFichierImageConvertie,
            cheminFichierExport, nombreChiffresSignificatifs, seuilToleranceNiveauxDeGris,
            seuilToleranceTeintesSaturees, methodeConversion, seuilNoirEtBlanc, nombreNiveauxDeGris,
            nombreTeintesSaturees, seuilSaturation);
}

Parametres::Parametres(const Parametres& parametres) :
        Parametres()
{
    this->copy(parametres);
}

Parametres::~Parametres()
{
}

const QString& Parametres::getCheminFichierEtude() const
{
    return this->cheminFichierEtude;
}

const QString& Parametres::getCheminFichierImageSource() const
{
    return this->cheminFichierImageSource;
}

const QString& Parametres::getCheminFichierImageConvertie() const
{
    return this->cheminFichierImageConvertie;
}

const QString& Parametres::getCheminFichierExport() const
{
    return this->cheminFichierExport;
}

const int& Parametres::getNombreChiffresSignificatifs() const
{
    return this->nombreChiffresSignificatifs;
}

const int& Parametres::getSeuilToleranceNiveauxDeGris() const
{
    return this->seuilToleranceNiveauxDeGris;
}

const int& Parametres::getSeuilToleranceTeintesSaturees() const
{
    return this->seuilToleranceTeintesSaturees;
}

const int& Parametres::getMethodeConversion() const
{
    return this->methodeConversion;
}

const int& Parametres::getSeuilNoirEtBlanc() const
{
    return this->seuilNoirEtBlanc;
}

const int& Parametres::getNombreNiveauxDeGris() const
{
    return this->nombreNiveauxDeGris;
}

const int& Parametres::getNombreTeintesSaturees() const
{
    return this->nombreTeintesSaturees;
}

const int& Parametres::getSeuilSaturation() const
{
    return this->seuilSaturation;
}

void Parametres::setCheminFichierEtude(const QString& cheminFichierEtude)
{
    this->cheminFichierEtude = cheminFichierEtude;
}

void Parametres::setCheminFichierImageSource(const QString& cheminFichierImageSource)
{
    this->cheminFichierImageSource = cheminFichierImageSource;
}

void Parametres::setCheminFichierImageConvertie(const QString& cheminFichierImageConvertie)
{
    this->cheminFichierImageConvertie = cheminFichierImageConvertie;
}

void Parametres::setCheminFichierExport(const QString& cheminFichierExport)
{
    this->cheminFichierExport = cheminFichierExport;
}

void Parametres::setNombreChiffresSignificatifs(const int& nombreChiffresSignificatifs)
{
    this->nombreChiffresSignificatifs = nombreChiffresSignificatifs;
}

void Parametres::setSeuilToleranceNiveauxDeGris(const int& seuilToleranceNiveauxDeGris)
{
    this->seuilToleranceNiveauxDeGris = seuilToleranceNiveauxDeGris;
}

void Parametres::setSeuilToleranceTeintesSaturees(const int& seuilToleranceTeintesSaturees)
{
    this->seuilToleranceTeintesSaturees = seuilToleranceTeintesSaturees;
}

void Parametres::setMethodeConversion(const int& methodeConversion)
{
    this->methodeConversion = methodeConversion;
}

void Parametres::setSeuilNoirEtBlanc(const int& seuilNoirEtBlanc)
{
    this->seuilNoirEtBlanc = seuilNoirEtBlanc;
}

void Parametres::setNombreNiveauxDeGris(const int& nombreNiveauxDeGris)
{
    this->nombreNiveauxDeGris = nombreNiveauxDeGris;
}

void Parametres::setNombreTeintesSaturees(const int& nombreTeintesSaturees)
{
    this->nombreTeintesSaturees = nombreTeintesSaturees;
}

void Parametres::setSeuilSaturation(const int& seuilSaturation)
{
    this->seuilSaturation = seuilSaturation;
}

void Parametres::clear()
{
    this->set(QString(), QString(), QString(), QString(), (int) nombreChiffresSignificatifsDefaut,
            (int) seuilToleranceNiveauxDeGrisDefaut, (int) seuilToleranceTeintesSatureesDefaut,
            (int) Image::BRUTE, (int) Image::seuilNoirEtBlancDefaut,
            (int) Image::nombreNiveauxDeGrisDefaut, (int) Image::nombreTeintesSatureesDefaut,
            (int) Image::seuilSaturationDefaut);
}

void Parametres::set(const QString& cheminFichierEtude, const QString& cheminFichierImageSource,
        const QString& cheminFichierImageConvertie, const QString& cheminFichierExport,
        const int& nombreChiffresSignificatifs, const int& seuilToleranceNiveauxDeGris,
        const int& seuilToleranceTeintesSaturees, const int& methodeConversion,
        const int& seuilNoirEtBlanc, const int& nombreNiveauxDeGris,
        const int& nombreTeintesSaturees, const int& seuilSaturation)
{
    this->setCheminFichierEtude(cheminFichierEtude);
    this->setCheminFichierImageSource(cheminFichierImageSource);
    this->setCheminFichierImageConvertie(cheminFichierImageConvertie);
    this->setCheminFichierExport(cheminFichierExport);
    this->setNombreChiffresSignificatifs(nombreChiffresSignificatifs);
    this->setSeuilToleranceNiveauxDeGris(seuilToleranceNiveauxDeGris);
    this->setSeuilToleranceTeintesSaturees(seuilToleranceTeintesSaturees);
    this->setMethodeConversion(methodeConversion);
    this->setSeuilNoirEtBlanc(seuilNoirEtBlanc);
    this->setNombreNiveauxDeGris(nombreNiveauxDeGris);
    this->setNombreTeintesSaturees(nombreTeintesSaturees);
    this->setSeuilSaturation(seuilSaturation);
}

void Parametres::copy(const Parametres& parametres)
{
    this->setCheminFichierEtude(parametres.getCheminFichierEtude());
    this->setCheminFichierImageSource(parametres.getCheminFichierImageSource());
    this->setCheminFichierImageConvertie(parametres.getCheminFichierImageConvertie());
    this->setCheminFichierExport(parametres.getCheminFichierExport());
    this->setNombreChiffresSignificatifs(parametres.getNombreChiffresSignificatifs());
    this->setSeuilToleranceNiveauxDeGris(parametres.getSeuilToleranceNiveauxDeGris());
    this->setSeuilToleranceTeintesSaturees(parametres.getSeuilToleranceTeintesSaturees());
    this->setMethodeConversion(parametres.getMethodeConversion());
    this->setSeuilNoirEtBlanc(parametres.getSeuilNoirEtBlanc());
    this->setNombreNiveauxDeGris(parametres.getNombreNiveauxDeGris());
    this->setNombreTeintesSaturees(parametres.getNombreTeintesSaturees());
    this->setSeuilSaturation(parametres.getSeuilSaturation());
}

bool Parametres::equals(const Parametres& parametres) const
{
    if (this->getCheminFichierEtude() != parametres.getCheminFichierEtude())
        return false;
    if (this->getCheminFichierImageSource() != parametres.getCheminFichierImageSource())
        return false;
    if (this->getCheminFichierImageConvertie() != parametres.getCheminFichierImageConvertie())
        return false;
    if (this->getCheminFichierExport() != parametres.getCheminFichierExport())
        return false;
    if (this->getNombreChiffresSignificatifs() != parametres.getNombreChiffresSignificatifs())
        return false;
    if (this->getSeuilToleranceNiveauxDeGris() != parametres.getSeuilToleranceNiveauxDeGris())
        return false;
    if (this->getSeuilToleranceTeintesSaturees() != parametres.getSeuilToleranceTeintesSaturees())
        return false;
    if (this->getMethodeConversion() != parametres.getMethodeConversion())
        return false;
    if (this->getSeuilNoirEtBlanc() != parametres.getSeuilNoirEtBlanc())
        return false;
    if (this->getNombreNiveauxDeGris() != parametres.getNombreNiveauxDeGris())
        return false;
    if (this->getNombreTeintesSaturees() != parametres.getNombreTeintesSaturees())
        return false;
    if (this->getSeuilSaturation() != parametres.getSeuilSaturation())
        return false;
    return true;
}

void Parametres::fromString(const QString& fromString, const char& sep)
{
    // TODO void Parametres::fromString(const QString& fromString, const char& sep)
    Q_UNUSED(fromString);
    Q_UNUSED(sep);
}

const QString Parametres::toString(const char& sep) const
{
    // TODO const QString Parametres::toString(const char& sep) const
    Q_UNUSED(sep);
    return QString();
}
