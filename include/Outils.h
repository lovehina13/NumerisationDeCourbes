//==============================================================================
// Name        : Outils.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (27/04/2016)
// Description : Header file of the Outils elements
//==============================================================================

#ifndef OUTILS_H_
#define OUTILS_H_

void genererImageTest();
void testerConversionNoirEtBlanc(const int& seuilNoirEtBlanc);
void testerConversionNiveauxDeGris(const int& nombreNiveauxDeGris);
void testerConversionTeintesSaturees(const int& nombreNiveauxDeGris,
        const int& nombreTeintesSaturees, const int& seuilSaturation);

#endif /* OUTILS_H_ */