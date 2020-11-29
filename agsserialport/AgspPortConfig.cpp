#include "AgspPortConfig.h"
#include "AgspSaneCheck.h"

int AgspPortConfig::GetBaudrate() {
    int value = 0;
    if(_port_cfg == nullptr) return eAGSP_ERR_NULLPTR;
    int error_value = sp_get_config_baudrate(_port_cfg, &value);
    if(error_value != SP_OK) return error_value;
    return value;
}

void AgspPortConfig::SetBaudrate(int baudrate) {
    if(_port_cfg == nullptr) return;
    sp_set_config_baudrate(_port_cfg, baudrate);
}

int AgspPortConfig::GetBits() {
    int value = 0;
    if(_port_cfg == nullptr) return eAGSP_ERR_NULLPTR;
    int error_value = sp_get_config_bits(_port_cfg, &value);
    if(error_value != SP_OK) return error_value;
    return value;
}

void AgspPortConfig::SetBits(int bits) {
    if(_port_cfg == nullptr) return;
    sp_set_config_bits(_port_cfg, bits);
}

int AgspPortConfig::GetParity() {
    int value = 0;
    if(_port_cfg == nullptr) return eAGSP_ERR_NULLPTR;
    int error_value = sp_get_config_parity(_port_cfg, (enum sp_parity*) &value);
    if(error_value != SP_OK) return error_value;
    return value;
}

void AgspPortConfig::SetParity(int parity) {
    if(_port_cfg == nullptr) return;
    sp_set_config_parity(_port_cfg, (enum sp_parity) parity);
}

int AgspPortConfig::GetStopBits() {
    int value = 0;
    if(_port_cfg == nullptr) return eAGSP_ERR_NULLPTR;
    int error_value = sp_get_config_stopbits(_port_cfg, &value);
    if(error_value != SP_OK) return error_value;
    return value;
}

void AgspPortConfig::SetStopBits(int stopbits) {
    if(_port_cfg == nullptr) return;
    sp_set_config_stopbits(_port_cfg, stopbits);
}

int AgspPortConfig::GetRTS() {
    int value = 0;
    if(_port_cfg == nullptr) return eAGSP_ERR_NULLPTR;
    int error_value = sp_get_config_rts(_port_cfg, (enum sp_rts*) &value);
    if(error_value != SP_OK) return error_value;
    return value;
}

void AgspPortConfig::SetRTS(int rts) {
    if(_port_cfg == nullptr) return;
    sp_set_config_rts(_port_cfg, (enum sp_rts) rts);
}

int AgspPortConfig::GetCTS() {
    int value = 0;
    if(_port_cfg == nullptr) return eAGSP_ERR_NULLPTR;
    int error_value = sp_get_config_cts(_port_cfg, (enum sp_cts*) &value);
    if(error_value != SP_OK) return error_value;
    return value;
}

void AgspPortConfig::SetCTS(int cts) {
    if(_port_cfg == nullptr) return;
    sp_set_config_cts(_port_cfg, (enum sp_cts) cts);
}

int AgspPortConfig::GetDTR() {
    int value = 0;
    if(_port_cfg == nullptr) return eAGSP_ERR_NULLPTR;
    int error_value = sp_get_config_dtr(_port_cfg, (enum sp_dtr*) &value);
    if(error_value != SP_OK) return error_value;
    return value;
}

void AgspPortConfig::SetDTR(int dtr) {
    if(_port_cfg == nullptr) return;
    sp_set_config_dtr(_port_cfg, (enum sp_dtr) dtr);
}

int AgspPortConfig::GetDSR() {
    int value = 0;
    if(_port_cfg == nullptr) return eAGSP_ERR_NULLPTR;
    int error_value = sp_get_config_dsr(_port_cfg, (enum sp_dsr*) &value);
    if(error_value != SP_OK) return error_value;
    return value;
}

void AgspPortConfig::SetDSR(int dsr) {
    if(_port_cfg == nullptr) return;
    sp_set_config_dsr(_port_cfg, (enum sp_dsr) dsr);
}

int AgspPortConfig::GetXonXoff() {
    int value = 0;
    if(_port_cfg == nullptr) return eAGSP_ERR_NULLPTR;
    int error_value = sp_get_config_xon_xoff(_port_cfg, (enum sp_xonxoff*) &value);
    if(error_value != SP_OK) return error_value;
    return value;
}

void AgspPortConfig::SetXonXoff(int xonxoff) {
    if(_port_cfg == nullptr) return;
    sp_set_config_xon_xoff(_port_cfg, (enum sp_xonxoff) xonxoff);
}

void AgspPortConfig::SetFlowControl(int flowcontrol) {
    if(_port_cfg == nullptr) return;
    sp_set_config_flowcontrol(_port_cfg, (enum sp_flowcontrol) flowcontrol);
}

AgspPortConfig::AgspPortConfig() {
    id = -1;
    _port_cfg = nullptr;
    do_check(sp_new_config(&_port_cfg));
}

AgspPortConfig::AgspPortConfig(struct sp_port *port) {
    id = -1;
    _port_cfg = nullptr;
    do_check(sp_new_config(&_port_cfg));
    do_check(sp_get_config(port, _port_cfg));
}

AgspPortConfig::~AgspPortConfig() {
    if(_port_cfg != nullptr)
    {
        sp_free_config(_port_cfg);
    }
}

sp_port_config *AgspPortConfig::get_sp_port_config() {
    return _port_cfg;
}

//------------------------------------------------------------------------------

extern IAGSEngine* engine;

AgspPortConfigInterface AgspPortConfig_Interface;
AgspPortConfigReader AgspPortConfig_Reader;

const char* AgspPortConfigInterface::name = "SP_PortConfig";

//------------------------------------------------------------------------------

int AgspPortConfigInterface::Dispose(const char *address, bool force) {
    delete ((AgspPortConfig*)address);
    AgspPortConfig* agspPortConfig = ((AgspPortConfig*)address);
    agspPortConfig = nullptr;
    return (1);
}
