//==============================================================================
// Name        : ParametresExport.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (28/06/2016)
// Description : Source file of the ParametresExport class
//==============================================================================

#include "ParametresExport.h"
#include "Outils.h"
#include <QStringList>

const int ParametresExport::formatNotationNombresDefaut = STANDARD;
const int ParametresExport::nombreChiffresSignificatifsDefaut = 6;
const char ParametresExport::caractereSeparationDefaut = '\t';
const char ParametresExport::caractereSeparateurDecimalDefaut = '.';
const double ParametresExport::seuilInterpolationNumeriqueDefaut = 0.0;

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
    this->set(formatNotationNombresDefaut, nombreChiffresSignificatifsDefaut,
            caractereSeparationDefaut, caractereSeparateurDecimalDefaut,
            seuilInterpolationNumeriqueDefaut);
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
    QStringList fromStringList = listeSousElements(fromString, sep);
    this->setFormatNotationNombres(fromStringList.at(0).toInt());
    this->setNombreChiffresSignificatifs(fromStringList.at(1).toInt());
    this->setCaractereSeparation(fromStringList.at(2).at(1).toAscii());
    this->setCaractereSeparateurDecimal(fromStringList.at(3).at(1).toAscii());
    this->setSeuilInterpolationNumerique(fromStringList.at(4).toDouble());
}

const QString ParametresExport::toString(const char& sep) const
{
    QString toString;
    toString += QString::number(this->getFormatNotationNombres()) + sep;
    toString += QString::number(this->getNombreChiffresSignificatifs()) + sep;
    toString += "'" + QString(this->getCaractereSeparation()) + "'" + sep;
    toString += "'" + QString(this->getCaractereSeparateurDecimal()) + "'" + sep;
    toString += QString::number(this->getSeuilInterpolationNumerique());
    return toString;
}

char ParametresExport::getFormatNotationNombresTexte() const
{
    const int& formatNotationNombres = this->getFormatNotationNombres();
    if (formatNotationNombres == STANDARD)
    {
        return 'f';
    }
    else if (formatNotationNombres == SCIENTIFIQUE)
    {
        return 'e';
    }
    return '\0';
}

int ParametresExport::getIndiceCaractereSeparation() const
{
    const char& caractereSeparation = this->getCaractereSeparation();
    if (caractereSeparation == ' ')
    {
        return ESPACE;
    }
    else if (caractereSeparation == '\t')
    {
        return TABULATION;
    }
    if (caractereSeparation == ';')
    {
        return POINT_VIRGULE;
    }
    return -1;
}

int ParametresExport::getIndiceCaractereSeparateurDecimal() const
{
    const char& caractereSeparateurDecimal = this->getCaractereSeparateurDecimal();
    if (caractereSeparateurDecimal == '.')
    {
        return POINT;
    }
    else if (caractereSeparateurDecimal == ',')
    {
        return VIRGULE;
    }
    return -1;
}

void ParametresExport::setFormatNotationNombresTexte(const char& formatNotationNombresTexte)
{
    if (formatNotationNombresTexte == 'f')
    {
        this->setFormatNotationNombres(STANDARD);
    }
    else if (formatNotationNombresTexte == 'e')
    {
        this->setFormatNotationNombres(SCIENTIFIQUE);
    }
}

void ParametresExport::setIndiceCaractereSeparation(const int& indiceCaractereSeparation)
{
    if (indiceCaractereSeparation == ESPACE)
    {
        this->setCaractereSeparation(' ');
    }
    else if (indiceCaractereSeparation == TABULATION)
    {
        this->setCaractereSeparation('\t');
    }
    else if (indiceCaractereSeparation == POINT_VIRGULE)
    {
        this->setCaractereSeparation(';');
    }
}

void ParametresExport::setIndiceCaractereSeparateurDecimal(
        const int& indiceCaractereSeparateurDecimal)
{
    if (indiceCaractereSeparateurDecimal == POINT)
    {
        this->setCaractereSeparateurDecimal('.');
    }
    else if (indiceCaractereSeparateurDecimal == VIRGULE)
    {
        this->setCaractereSeparateurDecimal(',');
    }
}
