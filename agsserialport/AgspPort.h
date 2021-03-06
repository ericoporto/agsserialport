/*
 * Copyright (C) 2020  Érico Vieira Porto
 *
 * This program is free software. You can use and redistribute it
 *  under the terms and conditions of the LGPL License (see LICENCE).
 */

#pragma once

#ifndef _AGSP_PORT_H
#define _AGSP_PORT_H

#include "plugin/agsplugin.h"
#include "libserialport.h"
#include "AgspPortConfig.h"
#include <string>

class AgspPort {
private:
    sp_port* _port;
    std::string _buffer;
public :
    int id;
    AgspPort(const char * portname);
    ~AgspPort();
    int Open(int mode);
    int Close();

    const char * GetName();

    const char *  GetDescription();

    int GetTransport();

    int SetConfig(AgspPortConfig* agspPortConfig);
    AgspPortConfig* GetConfig();

    const char * Read(int count);
    int Write(const char * buffer);

    int GetWaitingBytesRead();
    int GetWaitingBytesWrite();

    int Flush(int buffers);

    int SetBaudrate(int baudrate);
    int SetBits(int bits);
    int SetParity(int parity);
    int SetStopBits(int stopbits);
    int SetFlowControl(int flowcontrol);
};

//------------------------------------------------------------------------------
// AGS interface instances

class AgspPortInterface : public IAGSScriptManagedObject
{
public:
    static const char* name;

    AgspPortInterface() {};

    virtual int Dispose(const char* address, bool force);
    virtual const char* GetType() { return (name); }
    virtual int Serialize(const char* address, char* buffer, int bufsize);

};

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

class AgspPortReader : public IAGSManagedObjectReader
{
public:

    AgspPortReader() {}

    virtual void Unserialize(int key, const char* serializedData, int dataSize);

};

//------------------------------------------------------------------------------

extern AgspPortInterface AgspPort_Interface;
extern AgspPortReader AgspPort_Reader;

//------------------------------------------------------------------------------

#endif /* _AGSP_PORT_H */

//............
