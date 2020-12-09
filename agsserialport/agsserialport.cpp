// agsserialport.cpp : Defines the entry point for the DLL application.

#pragma region Defines_and_Includes

#include "core/platform.h"

#define MIN_EDITOR_VERSION 1
#define MIN_ENGINE_VERSION 3

#if AGS_PLATFORM_OS_WINDOWS
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#if !defined(BUILTIN_PLUGINS)
#define THIS_IS_THE_PLUGIN
#endif

#include "plugin/agsplugin.h"
#include "agsserialport_ash.h"
#include "agsp_globalvars.h"
#include "AgsNumberInterface.h"
#include "AgspPortConfig.h"
#include "AgspPort.h"
#include <cstring>
#include <string>
#include <vector>

#if defined(BUILTIN_PLUGINS)
namespace agsserialport {
#endif

#pragma endregion //Defines_and_Includes

#if AGS_PLATFORM_OS_WINDOWS
	// The standard Windows DLL entry point

	BOOL APIENTRY DllMain(HANDLE hModule,
		DWORD ul_reason_for_call,
		LPVOID lpReserved) {

		switch (ul_reason_for_call) {
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
		}
		return TRUE;
	}
#endif

	//define engine
	IAGSEngine *engine;


#if AGS_PLATFORM_OS_WINDOWS

	//==============================================================================

	// ***** Design time *****

	IAGSEditor *editor; // Editor interface

	//------------------------------------------------------------------------------
	LPCSTR AGS_GetPluginName(void)
	{
		// Return the plugin description
		return "agsserialport";
	}

	//------------------------------------------------------------------------------

	int AGS_EditorStartup(IAGSEditor *lpEditor)
	{
		// User has checked the plugin to use it in their game

		// If it's an earlier version than what we need, abort.
		if (lpEditor->version < MIN_EDITOR_VERSION)
			return (-1);

		editor = lpEditor;
		editor->RegisterScriptHeader(agsserialport_ash);

		// Return 0 to indicate success
		return (0);
	}

	//------------------------------------------------------------------------------

	void AGS_EditorShutdown()
	{
		// User has un-checked the plugin from their game
		editor->UnregisterScriptHeader(agsserialport_ash);
	}

	//------------------------------------------------------------------------------

	void AGS_EditorProperties(HWND parent)                        //*** optional ***
	{
		// User has chosen to view the Properties of the plugin
		// We could load up an options dialog or something here instead
 	MessageBox(parent,
        L"agsserialport v0.1.0 By eri0o",
        L"About",
		 MB_OK | MB_ICONINFORMATION);

	}

	//------------------------------------------------------------------------------

	int AGS_EditorSaveGame(char *buffer, int bufsize)             //*** optional ***
	{
		// Called by the editor when the current game is saved to disk.
		// Plugin configuration can be stored in [buffer] (max [bufsize] bytes)
		// Return the amount of bytes written in the buffer
		return (0);
	}

	//------------------------------------------------------------------------------

	void AGS_EditorLoadGame(char *buffer, int bufsize)            //*** optional ***
	{
		// Called by the editor when a game is loaded from disk
		// Previous written data can be read from [buffer] (size [bufsize]).
		// Make a copy of the data, the buffer is freed after this function call.
	}

	//==============================================================================

#endif

// ***** Run time *****

// Engine interface

//------------------------------------------------------------------------------


#define STRINGIFY(s) STRINGIFY_X(s)
#define STRINGIFY_X(s) #s

// -- begin AgspPortConfig

AgspPortConfig* AgspPortCfg_Create()
{
    AgspPortConfig* agspPortCfg = new AgspPortConfig();
    agspPortCfg->id = engine->RegisterManagedObject(agspPortCfg, &AgspPortConfig_Interface);
    return  agspPortCfg;
}

int AgspPortCfg_get_Baudrate(AgspPortConfig* self)
{
    return self->GetBaudrate();
}

void AgspPortCfg_set_Baudrate(AgspPortConfig* self, int baudrate)
{
    self->SetBaudrate(baudrate);
} //-- Baudrate

int AgspPortCfg_get_Bits(AgspPortConfig* self)
{
    return self->GetBits();
}

void AgspPortCfg_set_Bits(AgspPortConfig* self, int bits)
{
    self->SetBits(bits);
} //-- Bits

int AgspPortCfg_get_Parity(AgspPortConfig* self)
{
    return self->GetParity();
}

void AgspPortCfg_set_Parity(AgspPortConfig* self, int parity)
{
    self->SetParity(parity);
} //-- Parity

int AgspPortCfg_get_StopBits(AgspPortConfig* self)
{
    return self->GetStopBits();
}

void AgspPortCfg_set_StopBits(AgspPortConfig* self, int stopbits)
{
    self->SetStopBits(stopbits);
} //-- StopBits

int AgspPortCfg_get_RTS(AgspPortConfig* self)
{
    return self->GetRTS();
}

void AgspPortCfg_set_RTS(AgspPortConfig* self, int rts)
{
    self->SetRTS(rts);
} //-- RTS

int AgspPortCfg_get_CTS(AgspPortConfig* self)
{
    return self->GetCTS();
}

void AgspPortCfg_set_CTS(AgspPortConfig* self, int cts)
{
    self->SetCTS(cts);
} //-- CTS

int AgspPortCfg_get_DTR(AgspPortConfig* self)
{
    return self->GetDTR();
}

void AgspPortCfg_set_DTR(AgspPortConfig* self, int dtr)
{
    self->SetDTR(dtr);
} //-- DTR

int AgspPortCfg_get_DSR(AgspPortConfig* self)
{
    return self->GetDSR();
}

void AgspPortCfg_set_DSR(AgspPortConfig* self, int dsr)
{
    self->SetDSR(dsr);
} //-- DSR

int AgspPortCfg_get_XonXoff(AgspPortConfig* self)
{
    return self->GetXonXoff();
}

void AgspPortCfg_set_XonXoff(AgspPortConfig* self, int xonxoff)
{
    self->SetXonXoff(xonxoff);
} //-- XonXoff

void AgspPortCfg_SetFlowControl(AgspPortConfig* self, int flowcontrol)
{
    self->SetFlowControl(flowcontrol);
}

// -- end AgspPortConfig

// -- begin AgspPort

AgspPort* AgspPort_Create(const char * portname)
{
    AgspPort* agspPort = new AgspPort(portname);
    agspPort->id = engine->RegisterManagedObject(agspPort, &AgspPort_Interface);
    return  agspPort;
}

int AgspPort_Open(AgspPort* self, int mode)
{
    return self->Open(mode);
}

int AgspPort_Close(AgspPort* self)
{
    return self->Close();
}

const char * AgspPort_get_Name(AgspPort* self)
{
    return engine->CreateScriptString(self->GetName());
}

const char * AgspPort_get_Description(AgspPort* self)
{
    return engine->CreateScriptString(self->GetDescription());
}

int AgspPort_get_Transport(AgspPort* self)
{
    return self->GetTransport();
}

AgspPortConfig* AgspPort_GetConfig(AgspPort* self)
{
    AgspPortConfig* agspPortCfg = self->GetConfig();
    agspPortCfg->id = engine->RegisterManagedObject(agspPortCfg, &AgspPortConfig_Interface);
    return agspPortCfg;
}

int AgspPort_SetConfig(AgspPort* self, AgspPortConfig* agspPortConfig)
{
    return self->SetConfig(agspPortConfig);
} 

const char * AgspPort_Read(AgspPort* self, int count)
{
    return engine->CreateScriptString(self->Read(count));
}

int AgspPort_Write(AgspPort* self, const char * buffer)
{
    return self->Write(buffer);
}

int AgspPort_get_WaitingBytesRead(AgspPort* self)
{
    return self->GetWaitingBytesRead();
}

int AgspPort_get_WaitingBytesWrite(AgspPort* self)
{
    return self->GetWaitingBytesWrite();
}

int AgspPort_Flush(AgspPort* self, int buffers)
{
    return self->Flush(buffers);
}

int AgspPort_SetBaudrate(AgspPort* self, int baudrate)
{
    return self->SetBaudrate(baudrate);
}

int AgspPort_SetBits(AgspPort* self, int bits)
{
    return self->SetBits(bits);
}

int AgspPort_SetParity(AgspPort* self, int parity)
{
    return self->SetParity(parity);
}

int AgspPort_SetStopBits(AgspPort* self, int stopbits)
{
    return self->SetStopBits(stopbits);
}

int AgspPort_SetFlowControl(AgspPort* self, int flowcontrol)
{
    return self->SetFlowControl(flowcontrol);
}

// -- end AgspPort

// -- begin AGSP

std::vector<std::string> _agsp_port_names;

void AgspPort_UpdatePortNames()
{
    _agsp_port_names.clear();

    struct sp_port **port_list;
    // Call sp_list_ports() to get the ports. The port_list
    // pointer will be updated to refer to the array created.
    enum sp_return result = sp_list_ports(&port_list);

    if (result != SP_OK) {
        if(port_list != nullptr) sp_free_port_list(port_list);
        return;
    }
    int i;
    for (i = 0; port_list[i] != NULL; i++) {
        struct sp_port *port = port_list[i];

        // Get the name of the port.
        char *port_name = sp_get_port_name(port);
        std::string pname = port_name;
        _agsp_port_names.push_back(pname);
    }
    // Free the array created by sp_list_ports().
    sp_free_port_list(port_list);
    // Note that this will also free all the sp_port structures it points to
}

int AGSP_get_PortNamesCount()
{
    return _agsp_port_names.size();
}

const char* AGSP_geti_PortNames(int i)
{
    if(i < 0 || i >= _agsp_port_names.size()) return nullptr;
    return engine->CreateScriptString(_agsp_port_names[i].c_str());
}

// -- end AGSP


void AGS_EngineStartup(IAGSEngine *lpEngine)
{
    engine = lpEngine;

    // Make sure it's got the version with the features we need
    if (engine->version < MIN_ENGINE_VERSION)
    {
        engine->AbortGame("Plugin needs engine version " STRINGIFY(MIN_ENGINE_VERSION) " or newer.");
    }

    AgspPort_UpdatePortNames();

    engine->AddManagedObjectReader(AgspPortInterface::name, &AgspPort_Reader);
    engine->AddManagedObjectReader(AgspPortConfigInterface::name, &AgspPortConfig_Reader);

    engine->RegisterScriptFunction("AGSP::get_PortNamesCount", (void*)AGSP_get_PortNamesCount);
    engine->RegisterScriptFunction("AGSP::geti_PortNames", (void*)AGSP_geti_PortNames);
    engine->RegisterScriptFunction("AGSP::UpdatePortNames^0", (void*)AgspPort_UpdatePortNames);

    engine->RegisterScriptFunction("SP_Port::Create^1", (void*)AgspPort_Create);
    engine->RegisterScriptFunction("SP_Port::AgspPort_Open^1", (void*)AgspPort_Open);
    engine->RegisterScriptFunction("SP_Port::AgspPort_Close^0", (void*)AgspPort_Close);
    engine->RegisterScriptFunction("SP_Port::get_Name", (void*)AgspPort_get_Name);
    engine->RegisterScriptFunction("SP_Port::get_Description", (void*)AgspPort_get_Description);
    engine->RegisterScriptFunction("SP_Port::get_Transport", (void*)AgspPort_get_Transport);
    engine->RegisterScriptFunction("SP_Port::GetConfig^0", (void*)AgspPort_GetConfig);
    engine->RegisterScriptFunction("SP_Port::SetConfig^1", (void*)AgspPort_SetConfig);
    engine->RegisterScriptFunction("SP_Port::Read^1", (void*)AgspPort_Read);
    engine->RegisterScriptFunction("SP_Port::Write^1", (void*)AgspPort_Write);
    engine->RegisterScriptFunction("SP_Port::get_WaitingBytesRead", (void*)AgspPort_get_WaitingBytesRead);
    engine->RegisterScriptFunction("SP_Port::get_WaitingBytesWrite", (void*)AgspPort_get_WaitingBytesWrite);
    engine->RegisterScriptFunction("SP_Port::Flush^1", (void*)AgspPort_Flush);
    engine->RegisterScriptFunction("SP_Port::SetBaudrate^1", (void*)AgspPort_SetBaudrate);
    engine->RegisterScriptFunction("SP_Port::SetBits^1", (void*)AgspPort_SetBits);
    engine->RegisterScriptFunction("SP_Port::SetParity^1", (void*)AgspPort_SetParity);
    engine->RegisterScriptFunction("SP_Port::SetStopBits^1", (void*)AgspPort_SetStopBits);
    engine->RegisterScriptFunction("SP_Port::SetFlowControl^1", (void*)AgspPort_SetFlowControl);

    engine->RegisterScriptFunction("SP_PortConfig::Create^1", (void*)AgspPortCfg_Create);
    engine->RegisterScriptFunction("SP_PortConfig::SetFlowControl^1", (void*)AgspPortCfg_SetFlowControl);
    engine->RegisterScriptFunction("SP_PortConfig::get_Baudrate", (void*)AgspPortCfg_get_Baudrate);
    engine->RegisterScriptFunction("SP_PortConfig::set_Baudrate", (void*)AgspPortCfg_set_Baudrate);
    engine->RegisterScriptFunction("SP_PortConfig::get_Bits", (void*)AgspPortCfg_get_Bits);
    engine->RegisterScriptFunction("SP_PortConfig::set_Bits", (void*)AgspPortCfg_set_Bits);
    engine->RegisterScriptFunction("SP_PortConfig::get_Parity", (void*)AgspPortCfg_get_Parity);
    engine->RegisterScriptFunction("SP_PortConfig::set_Parity", (void*)AgspPortCfg_set_Parity);
    engine->RegisterScriptFunction("SP_PortConfig::get_StopBits", (void*)AgspPortCfg_get_StopBits);
    engine->RegisterScriptFunction("SP_PortConfig::set_StopBits", (void*)AgspPortCfg_set_StopBits);
    engine->RegisterScriptFunction("SP_PortConfig::get_RTS", (void*)AgspPortCfg_get_RTS);
    engine->RegisterScriptFunction("SP_PortConfig::set_RTS", (void*)AgspPortCfg_set_RTS);
    engine->RegisterScriptFunction("SP_PortConfig::get_CTS", (void*)AgspPortCfg_get_CTS);
    engine->RegisterScriptFunction("SP_PortConfig::set_CTS", (void*)AgspPortCfg_set_CTS);
    engine->RegisterScriptFunction("SP_PortConfig::get_DTR", (void*)AgspPortCfg_get_DTR);
    engine->RegisterScriptFunction("SP_PortConfig::set_DTR", (void*)AgspPortCfg_set_DTR);
    engine->RegisterScriptFunction("SP_PortConfig::get_DSR", (void*)AgspPortCfg_get_DSR);
    engine->RegisterScriptFunction("SP_PortConfig::set_DSR", (void*)AgspPortCfg_set_DSR);
    engine->RegisterScriptFunction("SP_PortConfig::get_XonXoff", (void*)AgspPortCfg_get_XonXoff);
    engine->RegisterScriptFunction("SP_PortConfig::set_XonXoff", (void*)AgspPortCfg_set_XonXoff);
}

//------------------------------------------------------------------------------

void AGS_EngineShutdown()
{

}

//------------------------------------------------------------------------------
//..............................................................................


#if defined(BUILTIN_PLUGINS)
}
#endif
