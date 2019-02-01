#ifndef ATARITIACONTROLLER_H
#define ATARITIACONTROLLER_H

#include <QObject>

#include "atari_tia/atari_tia.h"
#include "net/network_handler.h"

/* Strings representing AUDC status */

extern const char* ATARI_TIA_AUDC_Descriptions [];

class AtariTiaController: public QObject {

    Q_OBJECT

public:
    explicit AtariTiaController(QObject* parent = nullptr, NetworkHandler* networkHandler=nullptr);
    virtual ~AtariTiaController() {

    }

    void changeVolume(qint8 channel, qint8 value);
    void changeFrequency(qint8 channel, qint8 value);
    void changeControl(qint8 channel, qint8 value);

    void setStereo(bool isStereo);
    bool getStereo();

private:
    NetworkHandler* networkHandler;
    bool isStereo;
};

#endif // ATARITIACONTROLLER_H
