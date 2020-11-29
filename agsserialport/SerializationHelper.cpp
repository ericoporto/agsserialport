/*
 * Copyright (C) 2020  Érico Vieira Porto
 *
 * This program is free software. You can use and redistribute it
 *  under the terms and conditions of the LGPL License (see LICENCE).
 */

#include <assert.h>
#include "SerializationHelper.h"

namespace SerializationHelper {

	char* IntToChar(int32 i, char * buf, char* end) {
		assert(buf + sizeof(int32) < end);

		*((int32*)buf) = i;

		return buf + sizeof(int32);
	}

	char* FloatToChar(float32 f, char * buf, char* end) {
		assert(buf + sizeof(float32) < end);

		*((float*)buf) = f;

		return buf + sizeof(float32);
	}

	char* BoolToChar(bool b, char* buf, char* end) {
		assert(buf + sizeof(char) < end);

		if (b) {
			*buf = 1;
		}
		else {
			*buf = 0;
		}
		return buf + sizeof(char);
	}


	char* CharToBool(bool &b, char* buf) {
		if (*buf == 0) {
			b = false;
		}
		else {
			b = true;
		}
		return buf + sizeof(char);
	}

	char* CharToInt(int32 &i, char * buf) {
		i = *((int32*)buf);
		return buf + sizeof(int32);
	}

	char* CharToFloat(float32 &f, char * buf) {
		f = *((float32*)buf);
		return buf + sizeof(float32);
	}

}
