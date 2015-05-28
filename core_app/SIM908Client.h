/*
 * SIM908Client.h
 *
 * Created on: Mai 25, 2015
 * Author: Arthur Jahn
 * E-Mail: stutrzbecher@gmail.com
 *
 * Description: 
 * This file contains the definitions of the SIM908Client, based
 * on arduino Client.h interface, by using AT commands suppported
 * by SIM908 SIMCOM chip, used for handling GPS/GSM connections.
 */

#ifndef SIM908CLIENT_H
#define SIM908CLIENT_H
#include "Arduino.h"
#include "Client.h"
#include "WString.h"
#include <SoftwareSerial.h>

#define _S908_READ_BUFFER_SIZE 48

#define _S908_RECV_OK 0
#define _S908_RECV_TIMEOUT 1
#define _S908_RECV_RETURN 2
#define _S908_RECV_ECHO 3
#define _S908_RECV_READING 4
#define _S908_RECV_READ 5
#define _S908_RECV_NO_MATCH 6
#define _S908_RECV_INVALID 7

class SIM908Client : public Client
{
public:
    SIM908Client(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
    void begin(int);
    uint8_t pin(const char*);
    uint8_t attach(const char*, const char*, const char*);

    virtual int connect(IPAddress ip, uint16_t port);
    virtual int connect(const char *host, uint16_t port);
    virtual size_t write(uint8_t);
    virtual size_t write(const uint8_t *buf, size_t size);
    virtual int available();
    virtual int read();
    virtual int read(uint8_t *buf, size_t size);
    virtual int peek();
    virtual uint8_t connected();
    virtual void flush();
    virtual void stop();

    virtual void enableGps();
    virtual void enableGsm();

    virtual operator bool();

protected:
    void voidReadBuffer();
    uint8_t sendAndAssert(const __FlashStringHelper*, const __FlashStringHelper*, uint16_t, uint8_t,uint16_t=0);
    uint8_t recvExpected(const __FlashStringHelper*, uint16_t);
    size_t fillBuffer();
    uint8_t detectClosed();

private:
    // serial connection to sim908 gprs
    SoftwareSerial _modem;
    // power up pin
    uint8_t _pwrPin;
    // gps module pin
    uint8_t _gpsPin;
    // gsm module pin
    uint8_t _gsmPin;
    // class state variable
    uint8_t _state;
    // software flow control state
    uint8_t _flowctrl;
    // circular buffer
    uint8_t _buf[_S908_READ_BUFFER_SIZE];
    // buffer index and length
    size_t _bufindex, _buflen;
};

#endif