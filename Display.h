#ifndef DISPLAY_H
#define DISPLAY_H

#include <QString>
#include "SimulationComponent.h"

namespace Ui {
class Display;
}

class Display : public SimulationComponent {
    Q_OBJECT

public:
    explicit Display(QWidget *parent = nullptr, QString msg = "Display");
    ~Display();

    void setMessage(QString);
    QString getMessage() const;
    virtual void updateUI() override;

private:
    Ui::Display *ui;
    QString message;
    virtual void initUI() override;
};

#endif // DISPLAY_H