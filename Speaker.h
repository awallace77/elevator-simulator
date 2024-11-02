#ifndef SPEAKER_H
#define SPEAKER_H

#include <QString>
#include "SimulationComponent.h"

namespace Ui {
class Speaker;
}

class Speaker : public SimulationComponent {
    Q_OBJECT

public:
    explicit Speaker(QWidget *parent = nullptr, QString msg = "Speaker");
    ~Speaker();

    void setMessage(QString);
    QString getMessage() const;
    void soundBell();
    void soundRing();
    virtual void updateUI() override;
    virtual void initUI() override;


private:
    Ui::Speaker *ui;
    QString message;
};

#endif // SPEAKER_H
