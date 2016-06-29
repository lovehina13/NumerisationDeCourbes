//==============================================================================
// Name        : ParametresExport.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (28/06/2016)
// Description : Source file of the ParametresExport class
//==============================================================================

#include "ParametresExport.h"

ParametresExport::ParametresExport() :
        formatNotationNombres(formatNotationNombresDefaut),
                nombreChiffresSignificatifs(nombreChiffresSignificatifsDefaut),
                caractereSeparation(caractereSeparationDefaut),
                caractereSeparateurDecimal(caractereSeparateurDecimalDefaut),
                seuilInterpolationNumerique(seuilInterpolationNumeriqueDefaut)
{
    this->clear();
}

ParametresExport::ParametresExport(const int& formatNotationNombres,
        const int& nombreChiffresSignificatifs, const char& caractereSeparation,
        const char& caractereSeparateurDecimal, const double& seuilInterpolationNumerique) :
        ParametresExport()
{
    this->set(formatNotationNombres, nombreChiffresSignificatifs, caractereSeparation,
            caractereSeparateurDecimal, seuilInterpolationNumerique);
}

ParametresExport::ParametresExport(const ParametresExport& parametresExport) :
        ParametresExport()
{
    this->copy(parametresExport);
}

ParametresExport::~ParametresExport()
{
}

const int& ParametresExport::getFormatNotationNombres() const
{
    return this->formatNotationNombres;
}

const int& ParametresExport::getNombreChiffresSignificatifs() const
{
    return this->nombreChiffresSignificatifs;
}

const char& ParametresExport::getCaractereSeparation() const
{
    return this->caractereSeparation;
}

const char& ParametresExport::getCaractereSeparateurDecimal() const
{
    return this->caractereSeparateurDecimal;
}

const double& ParametresExport::getSeuilInterpolationNumerique() const
{
    return this->seuilInterpolationNumerique;
}

void ParametresExport::setFormatNotationNombres(const int& formatNotationNombres)
{
    this->formatNotationNombres = formatNotationNombres;
}

void ParametresExport::setNombreChiffresSignificatifs(const int& nombreChiffresSignificatifs)
{
    this->nombreChiffresSignificatifs = nombreChiffresSignificatifs;
}

void ParametresExport::setCaractereSeparation(const char& caractereSeparation)
{
    this->caractereSeparation = caractereSeparation;
}

void ParametresExport::setCaractereSeparateurDecimal(const char& caractereSeparateurDecimal)
{
    this->caractereSeparateurDecimal = caractereSeparateurDecimal;
}

void ParametresExport::setSeuilInterpolationNumerique(const double& seuilInterpolationNumerique)
{
    this->seuilInterpolationNumerique = seuilInterpolationNumerique;
}

void ParametresExport::clear()
{
    this->set((int) formatNotationNombresDefaut, (int) nombreChiffresSignificatifsDefaut,
            (char) caractereSeparationDefaut, (char) caractereSeparateurDecimalDefaut,
            (double) seuilInterpolationNumeriqueDefaut);
}

void ParametresExport::set(const int& formatNotationNombres, const int& nombreChiffresSignificatifs,
        const char& caractereSeparation, const char& caractereSeparateurDecimal,
        const double& seuilInterpolationNumerique)
{
    this->setFormatNotationNombres(formatNotationNombres);
    this->setNombreChiffresSignificatifs(nombreChiffresSignificatifs);
    this->setCaractereSeparation(caractereSeparation);
    this->setCaractereSeparateurDecimal(caractereSeparateurDecimal);
    this->setSeuilInterpolationNumerique(seuilInterpolationNumerique);
}

void ParametresExport::copy(const ParametresExport& parametresExport)
{
    this->set(parametresExport.getFormatNotationNombres(),
            parametresExport.getNombreChiffresSignificatifs(),
            parametresExport.getCaractereSeparation(),
            parametresExport.getCaractereSeparateurDecimal(),
            parametresExport.getSeuilInterpolationNumerique());
}

bool ParametresExport::equals(const ParametresExport& parametresExport) const
{
    if (this->getFormatNotationNombres() != parametresExport.getFormatNotationNombres())
        return false;
    if (this->getNombreChiffresSignificatifs() != parametresExport.getNombreChiffresSignificatifs())
        return false;
    if (this->getCaractereSeparation() != parametresExport.getCaractereSeparation())
        return false;
    if (this->getCaractereSeparateurDecimal() != parametresExport.getCaractereSeparateurDecimal())
        return false;
    if (this->getSeuilInterpolationNumerique() != parametresExport.getSeuilInterpolationNumerique())
        return false;
    return true;
}

void ParametresExport::fromString(const QString& fromString, const char& sep)
{
    // TODO void ParametresExport::fromString(const QString& fromString, const char& sep)
    Q_UNUSED(fromString);
    Q_UNUSED(sep);
}

const QString ParametresExport::toString(const char& sep) const
{
    // TODO const QString ParametresExport::toString(const char& sep) const
    Q_UNUSED(sep);
    return QString();
}
