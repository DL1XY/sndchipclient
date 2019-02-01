#include "ataritiacontroller.h"

const char* ATARI_TIA_AUDC_Descriptions [] =
{
    "VOL1", 					// 0x0;
    "4BIT_POLY", 				// 0x1;
    "DIV_15_TO_4BIT_POLY",		// 0x2;
    "5BIT_POLY_TO_4BIT_POLY",   // 0x3;
    "DIV_2",                    // 0x4;
    "DIV_2_2",                  // 0x5;
    "DIV_31",                   // 0x6;
    "5BIT_POLY_TO_DIV_2",       // 0x7;
    "9BIT_POLY",                // 0x8;
    "5BIT_POLY",                // 0x9;
    "DIV_31_2",                 // 0xA;
    "LAST_4BITS_1",             // 0xB;
    "DIV_6",                    // 0xC;
    "DIV_6_2",                  // 0xD;
    "DIV_93",                   // 0xE;
    "5BIT_POLY_TO_DIV_6"        // 0xF;
};

AtariTiaController::AtariTiaController(QObject *parent, NetworkHandler* networkHandler) : QObject(parent), networkHandler(networkHandler)
{
    isStereo = false;
}

void AtariTiaController::changeVolume(qint8 channel, qint8 value)
{
    NetworkCmd cmd;
    cmd.target = ATARI_TIA_ID;

    switch (channel)
    {
        case 0:
            cmd.cmdId = CMD_ATARI_TIA_AUDO_VOL;
            break;
        case 1:
            cmd.cmdId = CMD_ATARI_TIA_AUD1_VOL;
            break;
        default:
            cmd.cmdId = CMD_ATARI_TIA_AUD_VOL;
            break;
    }
    memcpy(&cmd.data, &value, sizeof(value));
    cmd.dataLength = sizeof(cmd.data);
    cmd.cmdCounter = (char)networkHandler->getNextCmdCounter();

    networkHandler->writeCmd(cmd);
}

void AtariTiaController::changeFrequency(qint8 channel, qint8 value)
{
    NetworkCmd cmd;
    cmd.target = ATARI_TIA_ID;

    switch (channel)
    {
        case 0:
            cmd.cmdId = CMD_ATARI_TIA_AUDO_FREQ;
            break;
        case 1:
            cmd.cmdId = CMD_ATARI_TIA_AUD1_FREQ;
            break;
        default:
            cmd.cmdId = CMD_ATARI_TIA_AUD_FREQ;
            break;
    }
    memcpy(&cmd.data, &value, sizeof(value));
    cmd.dataLength = sizeof(cmd.data);
    cmd.cmdCounter = (char)networkHandler->getNextCmdCounter();
    networkHandler->writeCmd(cmd);
}

void AtariTiaController::changeControl(qint8 channel, qint8 value)
{
    NetworkCmd cmd;
    cmd.target = ATARI_TIA_ID;

    switch (channel)
    {
        case 0:
            cmd.cmdId = CMD_ATARI_TIA_AUDO_CTRL;
            break;
        case 1:
            cmd.cmdId = CMD_ATARI_TIA_AUD1_CTRL;
            break;
        default:
            cmd.cmdId = CMD_ATARI_TIA_AUD_CTRL;
            break;
    }
    memcpy(&cmd.data, &value, sizeof(value));
    cmd.dataLength = sizeof(cmd.data);
    cmd.cmdCounter = (char)networkHandler->getNextCmdCounter();

    networkHandler->writeCmd(cmd);
}

void AtariTiaController::setStereo(bool isStereo)
{
    this->isStereo = isStereo;
}

bool AtariTiaController::getStereo()
{
    return isStereo;
}
