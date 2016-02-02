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

HEADERS += include/Etude.h \
           include/Image.h \
           include/Parametres.h \
           include/Point.h \
           include/Repere.h
SOURCES += source/NumerisationDeCourbes.cpp \
           source/Etude.cpp \
           source/Image.cpp \
           source/Parametres.cpp \
           source/Point.cpp \
           source/Repere.cpp
