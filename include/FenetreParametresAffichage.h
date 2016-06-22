#ifndef FENETREPARAMETRESAFFICHAGE_H_
#define FENETREPARAMETRESAFFICHAGE_H_

#include <QDialog>

namespace Ui
{
class FenetreParametresAffichage;
}

class FenetreParametresAffichage : public QDialog
{
    Q_OBJECT

public:
    explicit FenetreParametresAffichage(QWidget* parent = 0);
    ~FenetreParametresAffichage();

private:
    Ui::FenetreParametresAffichage* ui;
};

#endif /* FENETREPARAMETRESAFFICHAGE_H_ */
