//==============================================================================
// Name        : Parametres.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/01/2016)
// Description : SOurce file of the Parametres class
//==============================================================================

#include "Parametres.h"

Parametres::Parametres() :
        nombreChiffresSignificatifs(nombreChiffresSignificatifsDefaut), seuilToleranceNiveauxDeGris(
                seuilToleranceNiveauxDeGrisDefaut), seuilToleranceTeintesSaturees(
                seuilToleranceTeintesSatureesDefaut)
{
    this->clear();
}

Parametres::Parametres(const QString& cheminFichierEtude, const QString& cheminFichierImage,
        const QString& cheminFichierExport, const int& nombreChiffresSignificatifs,
        const int& seuilToleranceNiveauxDeGris, const int& seuilToleranceTeintesSaturees) :
        Parametres()
{
    this->initialize(cheminFichierEtude, cheminFichierImage, cheminFichierExport,
            nombreChiffresSignificatifs, seuilToleranceNiveauxDeGris,
            seuilToleranceTeintesSaturees);
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

const QString& Parametres::getCheminFichierImage() const
{
    return this->cheminFichierImage;
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

void Parametres::setCheminFichierEtude(const QString& cheminFichierEtude)
{
    this->cheminFichierEtude = cheminFichierEtude;
}

void Parametres::setCheminFichierImage(const QString& cheminFichierImage)
{
    this->cheminFichierImage = cheminFichierImage;
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

void Parametres::clear()
{
    this->initialize(QString(), QString(), QString(), (int) nombreChiffresSignificatifs,
            (int) seuilToleranceNiveauxDeGrisDefaut, (int) seuilToleranceTeintesSatureesDefaut);
}

void Parametres::initialize(const QString& cheminFichierEtude, const QString& cheminFichierImage,
        const QString& cheminFichierExport, const int& nombreChiffresSignificatifs,
        const int& seuilToleranceNiveauxDeGris, const int& seuilToleranceTeintesSaturees)
{
    this->setCheminFichierEtude(cheminFichierEtude);
    this->setCheminFichierImage(cheminFichierImage);
    this->setCheminFichierExport(cheminFichierExport);
    this->setNombreChiffresSignificatifs(nombreChiffresSignificatifs);
    this->setSeuilToleranceNiveauxDeGris(seuilToleranceNiveauxDeGris);
    this->setSeuilToleranceTeintesSaturees(seuilToleranceTeintesSaturees);
}

void Parametres::copy(const Parametres& parametres)
{
    this->setCheminFichierEtude(parametres.getCheminFichierEtude());
    this->setCheminFichierImage(parametres.getCheminFichierImage());
    this->setCheminFichierExport(parametres.getCheminFichierExport());
    this->setNombreChiffresSignificatifs(parametres.getNombreChiffresSignificatifs());
    this->setSeuilToleranceNiveauxDeGris(parametres.getSeuilToleranceNiveauxDeGris());
    this->setSeuilToleranceTeintesSaturees(parametres.getSeuilToleranceTeintesSaturees());
}

bool Parametres::equals(const Parametres& parametres) const
{
    if (this->getCheminFichierEtude() != parametres.getCheminFichierEtude())
        return false;
    if (this->getCheminFichierImage() != parametres.getCheminFichierImage())
        return false;
    if (this->getCheminFichierExport() != parametres.getCheminFichierExport())
        return false;
    if (this->getNombreChiffresSignificatifs() != parametres.getNombreChiffresSignificatifs())
        return false;
    if (this->getSeuilToleranceNiveauxDeGris() != parametres.getSeuilToleranceNiveauxDeGris())
        return false;
    if (this->getSeuilToleranceTeintesSaturees() != parametres.getSeuilToleranceTeintesSaturees())
        return false;
    return true;
}

void Parametres::fromString(const QString& fromString, const char& sep)
{
    // TODO void Parametres::fromString(const QString& fromString, const char& sep)
}

const QString Parametres::toString(const char& sep) const
{
    // TODO const QString Parametres::toString(const char& sep) const
    return QString();
}
