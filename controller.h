#ifndef CONTROLLER_H
#define CONTROLLER_H


class Controller
{
protected:
    Controller(const unsigned int ctrlType) {
        this->ctrlType = ctrlType;
    }

    unsigned int ctrlType = Controller::NONE;

public:
    virtual ~Controller() {}

    enum ControllerType : unsigned int
    {
        NONE                = 0x00,
        UDP_CONTROLLER      = 0x01,
        COAP_CONTROLLER     = 0x02
    };

    inline unsigned int getCtrlType()
    {
        return ctrlType;
    }
};

#endif // CONTROLLER_H
