#include <cstring>
#include "AgspPort.h"
#include "AgspSaneCheck.h"

int AgspPort::Open(int mode) {
    if(_port == nullptr) return eAGSP_ERR_NULLPTR;
    return sp_open(_port, (enum sp_mode) mode);
}

int AgspPort::Close() {
    if(_port == nullptr) return eAGSP_ERR_NULLPTR;
    return sp_close(_port);
}

const char *AgspPort::GetName() {
    if(_port == nullptr) return nullptr;
    return sp_get_port_name(_port);
}

const char *AgspPort::GetDescription() {
    if(_port == nullptr) return nullptr;
    return sp_get_port_description(_port);
}

int AgspPort::GetTransport() {
    if(_port == nullptr) return eAGSP_ERR_NULLPTR;
    return sp_get_port_transport(_port);
}

int AgspPort::SetConfig(AgspPortConfig *agspPortConfig) {
    if(_port == nullptr) return eAGSP_ERR_NULLPTR;
    return sp_set_config(_port, agspPortConfig->get_sp_port_config());
}

AgspPortConfig* AgspPort::GetConfig() {
    return new AgspPortConfig(_port);
}

const char *AgspPort::Read(int count) {
    if(_port == nullptr) return nullptr;
    if(count < 0) return nullptr;
    char* buffer = new char[count+1];
    if(sp_nonblocking_read(_port, buffer, count) == SP_OK)
    {
        return buffer;
    }
    delete[] buffer;
    return nullptr;
}

int AgspPort::Write(const char *buffer) {
    if(_port == nullptr) return eAGSP_ERR_NULLPTR;
    if(buffer == nullptr) return eAGSP_ERR_NULLPTR;
    size_t size = strlen(buffer);
    return sp_nonblocking_write(_port, buffer, size);
}

int AgspPort::GetWaitingBytesRead() {
    if(_port == nullptr) return eAGSP_ERR_NULLPTR;
    return sp_input_waiting(_port);
}

int AgspPort::GetWaitingBytesWrite() {
    if(_port == nullptr) return eAGSP_ERR_NULLPTR;
    return sp_output_waiting(_port);
}

int AgspPort::Flush(int buffers) {
    if(_port == nullptr) return eAGSP_ERR_NULLPTR;
    return sp_flush(_port, (enum sp_buffer) buffers);
}

int AgspPort::SetBaudrate(int baudrate) {
    if(_port == nullptr) return eAGSP_ERR_NULLPTR;
    return sp_set_baudrate(_port, baudrate);
}

int AgspPort::SetBits(int bits) {
    if(_port == nullptr) return eAGSP_ERR_NULLPTR;
    return sp_set_bits(_port, bits);
}

int AgspPort::SetParity(int parity) {
    if(_port == nullptr) return eAGSP_ERR_NULLPTR;
    return sp_set_parity(_port, (enum sp_parity) parity);
}

int AgspPort::SetStopBits(int stopbits) {
    if(_port == nullptr) return eAGSP_ERR_NULLPTR;
    return sp_set_stopbits(_port, stopbits);
}

int AgspPort::SetFlowControl(int flowcontrol) {
    if(_port == nullptr) return eAGSP_ERR_NULLPTR;
    return sp_set_flowcontrol(_port, (enum sp_flowcontrol) flowcontrol);
}


AgspPort::AgspPort(const char *portname) {
    id = -1;
    _port = nullptr;
    /* Call sp_get_port_by_name() to find the port. The port
    * pointer will be updated to refer to the port found. */
    do_check(sp_get_port_by_name(portname, &_port));
}

AgspPort::~AgspPort() {
    if(_port != nullptr)
    {
        void* discard = nullptr;
        if(sp_get_port_handle(_port, discard) == SP_OK)
        {
            sp_close(_port);
        }
        discard = nullptr;
        sp_free_port(_port);
    }
}



//------------------------------------------------------------------------------

extern IAGSEngine* engine;

AgspPortInterface AgspPort_Interface;
AgspPortReader AgspPort_Reader;

const char* AgspPortInterface::name = "SP_Port";

//------------------------------------------------------------------------------

int AgspPortInterface::Dispose(const char *address, bool force) {
    delete ((AgspPort*)address);
    AgspPort* agspPort = ((AgspPort*)address);
    agspPort = nullptr;
    return (1);
}

int AgspPortInterface::Serialize(const char* address, char* buffer, int bufsize)
{
    return 0;
}

void AgspPortReader::Unserialize(int key, const char* serializedData, int dataSize)
{
}
