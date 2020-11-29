#include <string>
#include <sstream>
#include "agsp_globalvars.h"
#include "AgspPort.h"

void do_check(enum sp_return result);

int AgspPort::Open(int mode) {
    return 0;
}

int AgspPort::Close() {
    return 0;
}

const char *AgspPort::GetName() {
    return nullptr;
}

const char *AgspPort::GetDescription() {
    return nullptr;
}

int AgspPort::GetTransport() {
    return 0;
}

void AgspPort::SetConfig(AgspPortConfig *agspPortConfig) {

}

AgspPortConfig *AgspPort::GetConfig() {
    return nullptr;
}

const char *AgspPort::Read(int count) {
    return nullptr;
}

int AgspPort::Write(const char *buffer) {
    return 0;
}

int AgspPort::GetWaitingBytesRead() {
    return 0;
}

int AgspPort::GetWaitingBytesWrite() {
    return 0;
}

int AgspPort::Flush(int buffers) {
    return 0;
}

AgspPort::AgspPort(const char *portname) {
  id = -1;
  _port = nullptr;
    /* Call sp_get_port_by_name() to find the port. The port
   * pointer will be updated to refer to the port found. */
    do_check(sp_get_port_by_name(portname, &_port));
}

AgspPort::~AgspPort() {

}

int check(enum sp_return result, IAGSEngine *lpEngine)
{
    // exits game on error
    char *error_message;
    std::ostringstream stringStream;

    switch (result) {
        case SP_ERR_ARG:
            lpEngine->AbortGame("Error: Invalid argument.\n");
            break;
        case SP_ERR_FAIL:
            error_message = sp_last_error_message();
            stringStream << "Error: Failed: " << error_message << "\n";
            sp_free_error_message(error_message);
            lpEngine->AbortGame(stringStream.str().c_str());
            break;
        case SP_ERR_SUPP:
            lpEngine->AbortGame("Error: Not supported.\n");
            break;
        case SP_ERR_MEM:
            lpEngine->AbortGame("Error: Couldn't allocate memory.\n");
            break;
        case SP_OK:
        default:
            return result;
    }
}

void do_check(enum sp_return result)
{
    check(result, engine);
}