//==============================================================================
// Name        : ParametresGraphique.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Source file of the ParametresGraphique class
//==============================================================================

#include "ParametresGraphique.h"
#include "Outils.h"
#include <QStringList>

ParametresGraphique::ParametresGraphique()
{
    clear();
}

ParametresGraphique::ParametresGraphique(const ParametresAxe& parametresAxeHorizontal,
        const ParametresAxe& parametresAxeVertical) :
        ParametresGraphique()
{
    set(parametresAxeHorizontal, parametresAxeVertical);
}

ParametresGraphique::ParametresGraphique(const ParametresGraphique& parametresGraphique) :
        ParametresGraphique()
{
    copy(parametresGraphique);
}

ParametresGraphique::~ParametresGraphique()
{
}

ParametresGraphique& ParametresGraphique::operator=(const ParametresGraphique& parametresGraphique)
{
    copy(parametresGraphique);
    return *this;
}

bool ParametresGraphique::operator==(const ParametresGraphique& parametresGraphique) const
{
    return equals(parametresGraphique);
}

bool ParametresGraphique::operator!=(const ParametresGraphique& parametresGraphique) const
{
    return !equals(parametresGraphique);
}

const ParametresAxe& ParametresGraphique::getParametresAxeHorizontal() const
{
    return _parametresAxeHorizontal;
}

const ParametresAxe& ParametresGraphique::getParametresAxeVertical() const
{
    return _parametresAxeVertical;
}

void ParametresGraphique::setParametresAxeHorizontal(const ParametresAxe& parametresAxeHorizontal)
{
    _parametresAxeHorizontal = parametresAxeHorizontal;
}

void ParametresGraphique::setParametresAxeVertical(const ParametresAxe& parametresAxeVertical)
{
    _parametresAxeVertical = parametresAxeVertical;
}

void ParametresGraphique::clear()
{
    set(ParametresAxe(), ParametresAxe());
}

void ParametresGraphique::set(const ParametresAxe& parametresAxeHorizontal,
        const ParametresAxe& parametresAxeVertical)
{
    setParametresAxeHorizontal(parametresAxeHorizontal);
    setParametresAxeVertical(parametresAxeVertical);
}

void ParametresGraphique::copy(const ParametresGraphique& parametresGraphique)
{
    set(parametresGraphique.getParametresAxeHorizontal(),
            parametresGraphique.getParametresAxeVertical());
}

bool ParametresGraphique::equals(const ParametresGraphique& parametresGraphique) const
{
    if (!getParametresAxeHorizontal().equals(parametresGraphique.getParametresAxeHorizontal()))
        return false;
    if (!getParametresAxeVertical().equals(parametresGraphique.getParametresAxeVertical()))
        return false;
    return true;
}

void ParametresGraphique::fromString(const QString& fromString, const QChar& sep)
{
    const QStringList fromStringList = listeSousElements(fromString, sep);
    ParametresAxe parametresAxeHorizontal = getParametresAxeHorizontal();
    ParametresAxe parametresAxeVertical = getParametresAxeVertical();
    parametresAxeHorizontal.fromString(fromStringList.at(0), sep);
    parametresAxeVertical.fromString(fromStringList.at(1), sep);
    setParametresAxeHorizontal(parametresAxeHorizontal);
    setParametresAxeVertical(parametresAxeVertical);
}

const QString ParametresGraphique::toString(const QChar& sep) const
{
    QString toString;
    toString += QString("(%1)").arg(getParametresAxeHorizontal().toString(sep)) + sep;
    toString += QString("(%1)").arg(getParametresAxeVertical().toString(sep));
    return toString;
}
