#include "AgspPortConfig.h"

int AgspPortConfig::GetBaudrate() {
    int value = 0;
    if(_port_cfg == nullptr) return eAGSP_ERR_NULLPTR;
    int error_value = sp_get_config_baudrate(_port_cfg, &value);
    if(error_value != SP_OK) return error_value;
    return value;
}

void AgspPortConfig::SetBaudrate(int baudrate) {

}

int AgspPortConfig::GetBits() {
    int value = 0;
    if(_port_cfg == nullptr) return eAGSP_ERR_NULLPTR;
    int error_value = sp_get_config_bits(_port_cfg, &value);
    if(error_value != SP_OK) return error_value;
    return value;
}

void AgspPortConfig::SetBits(int bits) {

}

int AgspPortConfig::GetParity() {
    int value = 0;
    if(_port_cfg == nullptr) return eAGSP_ERR_NULLPTR;
    int error_value = sp_get_config_parity(_port_cfg, (enum sp_parity*) &value);
    if(error_value != SP_OK) return error_value;
    return value;
}

void AgspPortConfig::SetParity(int parity) {

}

int AgspPortConfig::GetStopBits() {
    int value = 0;
    if(_port_cfg == nullptr) return eAGSP_ERR_NULLPTR;
    int error_value = sp_get_config_stopbits(_port_cfg, &value);
    if(error_value != SP_OK) return error_value;
    return value;
}

void AgspPortConfig::SetStopBits(int stopbits) {

}

int AgspPortConfig::GetRTS() {
    int value = 0;
    if(_port_cfg == nullptr) return eAGSP_ERR_NULLPTR;
    int error_value = sp_get_config_rts(_port_cfg, (enum sp_rts*) &value);
    if(error_value != SP_OK) return error_value;
    return value;
}

void AgspPortConfig::SetRTS(int rts) {

}

int AgspPortConfig::GetCTS() {
    int value = 0;
    if(_port_cfg == nullptr) return eAGSP_ERR_NULLPTR;
    int error_value = sp_get_config_cts(_port_cfg, (enum sp_cts*) &value);
    if(error_value != SP_OK) return error_value;
    return value;
}

void AgspPortConfig::SetCTS(int cts) {

}

int AgspPortConfig::GetDTR() {
    int value = 0;
    if(_port_cfg == nullptr) return eAGSP_ERR_NULLPTR;
    int error_value = sp_get_config_dtr(_port_cfg, (enum sp_dtr*) &value);
    if(error_value != SP_OK) return error_value;
    return value;
}

void AgspPortConfig::SetDTR(int dtr) {

}

int AgspPortConfig::GetDSR() {
    int value = 0;
    if(_port_cfg == nullptr) return eAGSP_ERR_NULLPTR;
    int error_value = sp_get_config_dsr(_port_cfg, (enum sp_dsr*) &value);
    if(error_value != SP_OK) return error_value;
    return value;
}

void AgspPortConfig::SetDSR(int dsr) {

}

int AgspPortConfig::GetXonXoff() {
    int value = 0;
    if(_port_cfg == nullptr) return eAGSP_ERR_NULLPTR;
    int error_value = sp_get_config_xon_xoff(_port_cfg, (enum sp_xonxoff*) &value);
    if(error_value != SP_OK) return error_value;
    return value;
}

void AgspPortConfig::SetXonXoff(int xonxoff) {

}

void AgspPortConfig::SetFlowControl(int flowcontrol) {

}

AgspPortConfig::AgspPortConfig() {
    id = -1;
    _port_cfg = nullptr;
}

AgspPortConfig::~AgspPortConfig() {

}
