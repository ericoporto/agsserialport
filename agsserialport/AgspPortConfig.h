/*
 * Copyright (C) 2020  Érico Vieira Porto
 *
 * This program is free software. You can use and redistribute it
 *  under the terms and conditions of the LGPL License (see LICENCE).
 */

#pragma once

#ifndef _AGSP_PORT_CONFIG_H
#define _AGSP_PORT_CONFIG_H

#include "plugin/agsplugin.h"
#include "libserialport.h"

class AgspPortConfig {
    public :
    int id;
    AgspPortConfig() {
        id = -1;
    }
    int GetBaudrate();
    void SetBaudrate(int baudrate);

    int GetBits();
    void SetBits(int bits);

    int GetParity();
    void SetParity(int parity);

    int GetStopBits();
    void SetStopBits(int stopbits);

    int GetRTS();
    void SetRTS(int rts);

    int GetCTS();
    void SetCTS(int cts);

    int GetDTR();
    void SetDTR(int dtr);

    int GetDSR();
    void SetDSR(int dsr);

    int GetXonXoff();
    void SetXonXoff(int xonxoff);

    int GetFlowControl();
    void SetFlowControl(int flowcontrol);
};

//------------------------------------------------------------------------------
// AGS interface instances

class AgspPortConfigInterface : public IAGSScriptManagedObject
{
public:
    static const char* name;

    AgspPortConfigInterface() {};

    virtual int Dispose(const char* address, bool force);
    virtual const char* GetType() { return (name); }
    virtual int Serialize(const char* address, char* buffer, int bufsize);

};

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

class AgspPortConfigReader : public IAGSManagedObjectReader
{
public:

    AgspPortConfigReader() {}

    virtual void Unserialize(int key, const char* serializedData, int dataSize);

};

//------------------------------------------------------------------------------

extern AgspPortConfigInterface AgspPortConfig_Interface;
extern AgspPortConfigReader AgspPortConfig_Reader;

//------------------------------------------------------------------------------

#endif /* _AGSP_PORT_CONFIG_H */

//............
