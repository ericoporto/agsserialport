// dllmain.cpp : Defines the entry point for the DLL application.

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
#include "AgsNumberInterface.h"
#include "AgspPortConfig.h"
#include "AgspPort.h"

#include <cstring>

#if defined(BUILTIN_PLUGINS)
namespace agsserialport {
#endif

typedef unsigned char uint8;


#if !AGS_PLATFORM_OS_WINDOWS
#define min(x,y) (((x) < (y)) ? (x) : (y))
#define max(x,y) (((x) > (y)) ? (x) : (y))
#endif

#define abs(a)             ((a)<0 ? -(a) : (a))

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
} //--

int AgspPortCfg_get_Bits(AgspPortConfig* self)
{
  return self->GetBits();
}

void AgspPortCfg_set_Bits(AgspPortConfig* self, int bits)
{
  self->SetBits(bits);
} //--

int AgspPortCfg_get_Parity(AgspPortConfig* self)
{
  return self->GetParity();
}

void AgspPortCfg_set_Parity(AgspPortConfig* self, int parity)
{
  self->SetParity(parity);
} //--

int AgspPortCfg_get_StopBits(AgspPortConfig* self)
{
  return self->GetStopBits();
}

void AgspPortCfg_set_StopBits(AgspPortConfig* self, int stopbits)
{
  self->SetStopBits(stopbits);
} //--

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
} //-- FlowControl

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

AgspPortConfig* AgspPort_get_Config(AgspPort* self)
{
  AgspPortConfig* agspPortCfg = new AgspPortConfig();
  agspPortCfg->id = engine->RegisterManagedObject(agspPortCfg, &AgspPortConfig_Interface);
  return agspPortCfg;
}

void AgspPort_set_Config(AgspPort* self, AgspPortConfig* agspPortConfig)
{
  self->SetConfig(agspPortConfig);
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


// -- end AgspPort

// -- begin AGSP

int AGSP_get_PortNamesCount()
{
    return 0;
}

const char* AGSP_geti_PortNames(int i)
{
    return engine->CreateScriptString("");
}

// -- end AGSP


void AGS_EngineStartup(IAGSEngine *lpEngine)
{
	engine = lpEngine;

	// Make sure it's got the version with the features we need
	if (engine->version < MIN_ENGINE_VERSION)
		engine->AbortGame("Plugin needs engine version " STRINGIFY(MIN_ENGINE_VERSION) " or newer.");

    engine->AddManagedObjectReader(AgspPortInterface::name, &AgspPort_Reader);
    engine->AddManagedObjectReader(AgspPortConfigInterface::name, &AgspPortConfig_Reader);

    engine->RegisterScriptFunction("AGSP::get_PortNamesCount", (void*)AGSP_get_PortNamesCount);
    engine->RegisterScriptFunction("AGSP::geti_PortNames", (void*)AGSP_geti_PortNames);

    engine->RegisterScriptFunction("SP_Port::Create^1", (void*)AgspPort_Create);
    engine->RegisterScriptFunction("SP_Port::AgspPort_Open^1", (void*)AgspPort_Open);
    engine->RegisterScriptFunction("SP_Port::AgspPort_Close^0", (void*)AgspPort_Close);
    engine->RegisterScriptFunction("SP_Port::get_Name", (void*)AgspPort_get_Name);
    engine->RegisterScriptFunction("SP_Port::get_Description", (void*)AgspPort_get_Description);
    engine->RegisterScriptFunction("SP_Port::get_Transport", (void*)AgspPort_get_Transport);
    engine->RegisterScriptFunction("SP_Port::get_Config", (void*)AgspPort_get_Config);
    engine->RegisterScriptFunction("SP_Port::set_Config", (void*)AgspPort_set_Config);
    engine->RegisterScriptFunction("SP_Port::Read^1", (void*)AgspPort_Read);
    engine->RegisterScriptFunction("SP_Port::Write^1", (void*)AgspPort_Write);
    engine->RegisterScriptFunction("SP_Port::get_WaitingBytesRead", (void*)AgspPort_get_WaitingBytesRead);
    engine->RegisterScriptFunction("SP_Port::get_WaitingBytesWrite", (void*)AgspPort_get_WaitingBytesWrite);
    engine->RegisterScriptFunction("SP_Port::Flush^1", (void*)AgspPort_Flush);

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


//------------------------------------------------------------------------------


//..............................................................................


#if defined(BUILTIN_PLUGINS)
}
#endif
