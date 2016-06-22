#===============================================================================
# Name        : NumerisationDeCourbes.pro
# Author      : Alexis Foerster (alexis.foerster@gmail.com)
# Version     : 1.0 (30/01/2016)
# Description : Qt project file of the NumerisationDeCourbes project
#===============================================================================

TEMPLATE = app
TARGET = NumerisationDeCourbes
DEPENDPATH += . include source
INCLUDEPATH += . include
OBJECTS_DIR = objects

HEADERS += include/EcranPrincipal.h \
           include/Etude.h \
           include/FenetreParametresAffichage.h \
           include/FenetreParametresConversion.h \
           include/FenetreParametresExport.h \
           include/FenetreParametresRecherche.h \
           include/Image.h \
           include/Outils.h \
           include/Parametres.h \
           include/Point.h \
           include/Repere.h
SOURCES += source/NumerisationDeCourbes.cpp \
           source/EcranPrincipal.cpp \
           source/Etude.cpp \
           source/FenetreParametresAffichage.cpp \
           source/FenetreParametresConversion.cpp \
           source/FenetreParametresExport.cpp \
           source/FenetreParametresRecherche.cpp \
           source/Image.cpp \
           source/Outils.cpp \
           source/Parametres.cpp \
           source/Point.cpp \
           source/Repere.cpp
FORMS += interfaces/EcranPrincipal.ui \
         interfaces/FenetreParametresAffichage.ui \
         interfaces/FenetreParametresConversion.ui \
         interfaces/FenetreParametresExport.ui \
         interfaces/FenetreParametresRecherche.ui

QMAKE_CXXFLAGS += -std=c++11
