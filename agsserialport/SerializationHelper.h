/*
 * Copyright (C) 2020  Érico Vieira Porto
 *
 * This program is free software. You can use and redistribute it
 *  under the terms and conditions of the LGPL License (see LICENCE).
 */
 
#pragma once

#ifndef AGSP_SERIALHELPER_H
#define AGSP_SERIALHELPER_H

#include "AgspPort.h"
#include "AgspPortConfig.h"
#include <plugin/agsplugin.h>
typedef float float32;

namespace SerializationHelper {
	
	union u_cf
	{
		float32 f;
		char s[sizeof(float32)];
	};

	union u_ci
	{
		int32 i;
		char s[sizeof(int32)];
	};

	char* IntToChar(int32 i, char * buf, char* end);
	char* FloatToChar(float32 f, char * buf, char* end);
	char* BoolToChar(bool b, char* buf, char* end);

	char* CharToBool(bool &b, char* buf);
	char* CharToInt(int32 &i, char * buf);
	char* CharToFloat(float32 &f, char * buf);
}

#endif /* AGSP_SERIALHELPER_H */
