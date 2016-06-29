#ifndef FENETREPARAMETRESCONVERSION_H_
#define FENETREPARAMETRESCONVERSION_H_

#include <QDialog>

namespace Ui
{
class FenetreParametresConversion;
}

class FenetreParametresConversion : public QDialog
{
    Q_OBJECT

public:
    explicit FenetreParametresConversion(QWidget* parent = 0);
    ~FenetreParametresConversion();

    // TODO Implémentation de la classe FenetreParametresConversion

private:
    Ui::FenetreParametresConversion* ui;
};

#endif /* FENETREPARAMETRESCONVERSION_H_ */
