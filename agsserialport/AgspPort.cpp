#include "AgspPort.h"

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
}

AgspPort::~AgspPort() {

}
