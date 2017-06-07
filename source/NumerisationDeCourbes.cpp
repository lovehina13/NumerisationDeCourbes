//==============================================================================
// Name        : NumerisationDeCourbes.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.5 (07/06/2017)
// Description : Main file of the NumerisationDeCourbes project
//==============================================================================

#include "EcranPrincipal.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication application(argc, argv);
    EcranPrincipal ecranPrincipal;
    ecranPrincipal.show();
    return application.exec();
}
