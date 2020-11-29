/*
 * Copyright (C) 2020  Érico Vieira Porto
 *
 * This program is free software. You can use and redistribute it
 *  under the terms and conditions of the LGPL License (see LICENCE).
 */

#pragma once

#ifndef _AGSP_NUMBER_INTERFACE_H
#define _AGSP_NUMBER_INTERFACE_H

int inline ToAgsBool(bool b){
    return b ? 1 : 0;
}

bool inline ToNormalBool(int bi){
    return bi!=0 ? true : false;
}

#endif /* _AGSP_NUMBER_INTERFACE_H */

//..............................................................................
