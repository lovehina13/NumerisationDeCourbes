//==============================================================================
// Name        : NumerisationDeCourbes.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.3.0 (07/08/2021)
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
