#===============================================================================
# Name        : NumerisationDeCourbes.pro
# Author      : Alexis Foerster (alexis.foerster@gmail.com)
# Version     : 1.0.6 (26/06/2017)
# Description : Qt project file of the NumerisationDeCourbes project
#===============================================================================

TEMPLATE = app
TARGET = NumerisationDeCourbes
DEPENDPATH += . include source
INCLUDEPATH += . include
OBJECTS_DIR = objects
MOC_DIR = objects
RCC_DIR = objects
UI_DIR = objects

HEADERS += include/EcranPrincipal.h \
           include/Etude.h \
           include/FenetreDocumentation.h \
           include/FenetreGraphique.h \
           include/FenetreParametresAffichage.h \
           include/FenetreParametresConversion.h \
           include/FenetreParametresExport.h \
           include/FenetreParametresRecherche.h \
           include/Image.h \
           include/Outils.h \
           include/Parametres.h \
           include/ParametresAffichage.h \
           include/ParametresAxe.h \
           include/ParametresConversion.h \
           include/ParametresExport.h \
           include/ParametresFichiers.h \
           include/ParametresGraphique.h \
           include/ParametresPoint.h \
           include/ParametresRecherche.h \
           include/ParametresTrait.h \
           include/Point.h \
           include/Repere.h \
           include/VueGraphiqueEtude.h
SOURCES += source/NumerisationDeCourbes.cpp \
           source/EcranPrincipal.cpp \
           source/Etude.cpp \
           source/FenetreDocumentation.cpp \
           source/FenetreGraphique.cpp \
           source/FenetreParametresAffichage.cpp \
           source/FenetreParametresConversion.cpp \
           source/FenetreParametresExport.cpp \
           source/FenetreParametresRecherche.cpp \
           source/Image.cpp \
           source/Outils.cpp \
           source/Parametres.cpp \
           source/ParametresAffichage.cpp \
           source/ParametresAxe.cpp \
           source/ParametresConversion.cpp \
           source/ParametresExport.cpp \
           source/ParametresFichiers.cpp \
           source/ParametresGraphique.cpp \
           source/ParametresPoint.cpp \
           source/ParametresRecherche.cpp \
           source/ParametresTrait.cpp \
           source/Point.cpp \
           source/Repere.cpp \
           source/VueGraphiqueEtude.cpp
FORMS += interfaces/EcranPrincipal.ui \
         interfaces/FenetreDocumentation.ui \
         interfaces/FenetreGraphique.ui \
         interfaces/FenetreParametresAffichage.ui \
         interfaces/FenetreParametresConversion.ui \
         interfaces/FenetreParametresExport.ui \
         interfaces/FenetreParametresRecherche.ui
RESOURCES += ressources/Ressources.qrc

QMAKE_CXXFLAGS += -std=c++11 -pedantic -Wall -Wextra
# QMAKE_CXXFLAGS += -std=c++11 -pedantic -pedantic-errors -Wall -Wextra -Wconversion -Wsign-conversion -Wunused-parameter -Werror

QWT_ROOT = $$(QWT_ROOT)
isEmpty(QWT_ROOT) {
  message("La variable d'environnement QWT_ROOT n'est pas définie.")
  message("L'application n'intègrera pas les fonctionnalités associées.")
} else {
  message("La variable d'environnement QWT_ROOT est définie ($$(QWT_ROOT)).")
  message("L'application intègrera les fonctionnalités associées.")
  CONFIG += qwt
  INCLUDEPATH += $$(QWT_ROOT)/include
  LIBS += -L$$(QWT_ROOT)/lib -lqwt
  QMAKE_CXXFLAGS += -DENABLE_QWT
}
