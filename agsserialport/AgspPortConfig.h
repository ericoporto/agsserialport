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

#define eAGSP_ERR_NULLPTR -10

class AgspPortConfig {
private:
    sp_port_config* _port_cfg;
public:
    int id;
    AgspPortConfig();
    AgspPortConfig(struct sp_port * port);
    ~AgspPortConfig();

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

    void SetFlowControl(int flowcontrol);
    sp_port_config* get_sp_port_config();
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
