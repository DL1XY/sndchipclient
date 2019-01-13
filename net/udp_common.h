#ifndef UDPCOMMANDS_H
#define UDPCOMMANDS_H

#define MAX_PAYLOAD 512;

// General UDP Commands 0x00 - 0x0F
#define UDP_CMD_INIT        0x00;
#define UDP_CMD_RESET       0x01;
#define UDP_CMD_GET_STATUS  0x02;



struct UdpCommand
{
    char cmdId;
    char *data;
};

extern void sendCmd(UdpCommand& cmd, void (callbackFunc)(char& respBuffer), char* data);


#endif // UDPCOMMANDS_H
