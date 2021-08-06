//==============================================================================
// Name        : ParametresExport.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
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

const QMap<int, char> ParametresExport::_formatsNotationNombresCaractere = QMap<int, char>(
        std::map<int, char> { { STANDARD, 'f' }, { SCIENTIFIQUE, 'e' } });
const QMap<int, QString> ParametresExport::_formatsNotationNombresTexte = QMap<int, QString>(
        std::map<int, QString> { { STANDARD, QString::fromUtf8("Standard") }, { SCIENTIFIQUE,
                QString::fromUtf8("Scientifique") } });
const QMap<char, int> ParametresExport::_caracteresSeparationIndice = QMap<char, int>(
        std::map<char, int> { { ' ', ESPACE }, { '\t', TABULATION }, { ';', POINT_VIRGULE } });
const QMap<char, QString> ParametresExport::_caracteresSeparationTexte = QMap<char, QString>(
        std::map<char, QString> { { ' ', QString::fromUtf8("Espace") }, { '\t', QString::fromUtf8(
                "Tabulation") }, { ';', QString::fromUtf8("Point-virgule") } });
const QMap<char, int> ParametresExport::_caracteresSeparateurDecimalIndice = QMap<char, int>(
        std::map<char, int> { { '.', POINT }, { ',', VIRGULE } });
const QMap<char, QString> ParametresExport::_caracteresSeparateurDecimalTexte = QMap<char, QString>(
        std::map<char, QString> { { '.', QString::fromUtf8("Point") }, { ',', QString::fromUtf8(
                "Virgule") } });

ParametresExport::ParametresExport() :
        _formatNotationNombres(formatNotationNombresDefaut),
                _nombreChiffresSignificatifs(nombreChiffresSignificatifsDefaut),
                _caractereSeparation(caractereSeparationDefaut),
                _caractereSeparateurDecimal(caractereSeparateurDecimalDefaut),
                _seuilInterpolationNumerique(seuilInterpolationNumeriqueDefaut)
{
    clear();
}

ParametresExport::ParametresExport(const int& formatNotationNombres,
        const int& nombreChiffresSignificatifs, const char& caractereSeparation,
        const char& caractereSeparateurDecimal, const double& seuilInterpolationNumerique) :
        ParametresExport()
{
    set(formatNotationNombres, nombreChiffresSignificatifs, caractereSeparation,
            caractereSeparateurDecimal, seuilInterpolationNumerique);
}

ParametresExport::ParametresExport(const ParametresExport& parametresExport) :
        ParametresExport()
{
    copy(parametresExport);
}

ParametresExport::~ParametresExport()
{
}

ParametresExport& ParametresExport::operator=(const ParametresExport& parametresExport)
{
    copy(parametresExport);
    return *this;
}

bool ParametresExport::operator==(const ParametresExport& parametresExport) const
{
    return equals(parametresExport);
}

bool ParametresExport::operator!=(const ParametresExport& parametresExport) const
{
    return !equals(parametresExport);
}

const int& ParametresExport::getFormatNotationNombres() const
{
    return _formatNotationNombres;
}

const int& ParametresExport::getNombreChiffresSignificatifs() const
{
    return _nombreChiffresSignificatifs;
}

const char& ParametresExport::getCaractereSeparation() const
{
    return _caractereSeparation;
}

const char& ParametresExport::getCaractereSeparateurDecimal() const
{
    return _caractereSeparateurDecimal;
}

const double& ParametresExport::getSeuilInterpolationNumerique() const
{
    return _seuilInterpolationNumerique;
}

void ParametresExport::setFormatNotationNombres(const int& formatNotationNombres)
{
    _formatNotationNombres = formatNotationNombres;
}

void ParametresExport::setNombreChiffresSignificatifs(const int& nombreChiffresSignificatifs)
{
    _nombreChiffresSignificatifs = nombreChiffresSignificatifs;
}

void ParametresExport::setCaractereSeparation(const char& caractereSeparation)
{
    _caractereSeparation = caractereSeparation;
}

void ParametresExport::setCaractereSeparateurDecimal(const char& caractereSeparateurDecimal)
{
    _caractereSeparateurDecimal = caractereSeparateurDecimal;
}

void ParametresExport::setSeuilInterpolationNumerique(const double& seuilInterpolationNumerique)
{
    _seuilInterpolationNumerique = seuilInterpolationNumerique;
}

void ParametresExport::clear()
{
    set(formatNotationNombresDefaut, nombreChiffresSignificatifsDefaut, caractereSeparationDefaut,
            caractereSeparateurDecimalDefaut, seuilInterpolationNumeriqueDefaut);
}

void ParametresExport::set(const int& formatNotationNombres, const int& nombreChiffresSignificatifs,
        const char& caractereSeparation, const char& caractereSeparateurDecimal,
        const double& seuilInterpolationNumerique)
{
    setFormatNotationNombres(formatNotationNombres);
    setNombreChiffresSignificatifs(nombreChiffresSignificatifs);
    setCaractereSeparation(caractereSeparation);
    setCaractereSeparateurDecimal(caractereSeparateurDecimal);
    setSeuilInterpolationNumerique(seuilInterpolationNumerique);
}

void ParametresExport::copy(const ParametresExport& parametresExport)
{
    set(parametresExport.getFormatNotationNombres(),
            parametresExport.getNombreChiffresSignificatifs(),
            parametresExport.getCaractereSeparation(),
            parametresExport.getCaractereSeparateurDecimal(),
            parametresExport.getSeuilInterpolationNumerique());
}

bool ParametresExport::equals(const ParametresExport& parametresExport) const
{
    if (getFormatNotationNombres() != parametresExport.getFormatNotationNombres())
        return false;
    if (getNombreChiffresSignificatifs() != parametresExport.getNombreChiffresSignificatifs())
        return false;
    if (getCaractereSeparation() != parametresExport.getCaractereSeparation())
        return false;
    if (getCaractereSeparateurDecimal() != parametresExport.getCaractereSeparateurDecimal())
        return false;
    if (getSeuilInterpolationNumerique() != parametresExport.getSeuilInterpolationNumerique())
        return false;
    return true;
}

void ParametresExport::fromString(const QString& fromString, const QChar& sep)
{
    const QStringList fromStringList = listeSousElements(fromString, sep);
    setFormatNotationNombres(fromStringList.at(0).toInt());
    setNombreChiffresSignificatifs(fromStringList.at(1).toInt());
    setCaractereSeparation(fromStringList.at(2).at(1).toLatin1());
    setCaractereSeparateurDecimal(fromStringList.at(3).at(1).toLatin1());
    setSeuilInterpolationNumerique(fromStringList.at(4).toDouble());
}

const QString ParametresExport::toString(const QChar& sep) const
{
    QString toString;
    toString += QString::number(getFormatNotationNombres()) + sep;
    toString += QString::number(getNombreChiffresSignificatifs()) + sep;
    toString += "'" + QString(getCaractereSeparation()) + "'" + sep;
    toString += "'" + QString(getCaractereSeparateurDecimal()) + "'" + sep;
    toString += QString::number(getSeuilInterpolationNumerique());
    return toString;
}

char ParametresExport::getFormatNotationNombresCaractere() const
{
    return _formatsNotationNombresCaractere.value(getFormatNotationNombres());
}

const QString ParametresExport::getFormatNotationNombresTexte() const
{
    return _formatsNotationNombresTexte.value(getFormatNotationNombres());
}

int ParametresExport::getCaractereSeparationIndice() const
{
    return _caracteresSeparationIndice.value(getCaractereSeparation());
}

const QString ParametresExport::getCaractereSeparationTexte() const
{
    return _caracteresSeparationTexte.value(getCaractereSeparation());
}

int ParametresExport::getCaractereSeparateurDecimalIndice() const
{
    return _caracteresSeparateurDecimalIndice.value(getCaractereSeparateurDecimal());
}

const QString ParametresExport::getCaractereSeparateurDecimalTexte() const
{
    return _caracteresSeparateurDecimalTexte.value(getCaractereSeparateurDecimal());
}

void ParametresExport::setFormatNotationNombresCaractere(const char& formatNotationNombresCaractere)
{
    setFormatNotationNombres(_formatsNotationNombresCaractere.key(formatNotationNombresCaractere));
}

void ParametresExport::setFormatNotationNombresTexte(const QString& formatNotationNombresTexte)
{
    setFormatNotationNombres(_formatsNotationNombresTexte.key(formatNotationNombresTexte));
}

void ParametresExport::setCaractereSeparationIndice(const int& caractereSeparationIndice)
{
    setCaractereSeparation(_caracteresSeparationIndice.key(caractereSeparationIndice));
}

void ParametresExport::setCaractereSeparationTexte(const QString& caractereSeparationTexte)
{
    setCaractereSeparation(_caracteresSeparationTexte.key(caractereSeparationTexte));
}

void ParametresExport::setCaractereSeparateurDecimalIndice(
        const int& caractereSeparateurDecimalIndice)
{
    setCaractereSeparateurDecimal(
            _caracteresSeparateurDecimalIndice.key(caractereSeparateurDecimalIndice));
}

void ParametresExport::setCaractereSeparateurDecimalTexte(
        const QString& caractereSeparateurDecimalTexte)
{
    setCaractereSeparateurDecimal(
            _caracteresSeparateurDecimalTexte.key(caractereSeparateurDecimalTexte));
}
