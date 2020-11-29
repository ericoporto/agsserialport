/*
 * Copyright (C) 2020  Érico Vieira Porto
 *
 * This program is free software. You can use and redistribute it
 *  under the terms and conditions of the LGPL License (see LICENCE).
 */

#pragma once

#ifndef _AGSP_SANE_CHECK_H
#define _AGSP_SANE_CHECK_H

#include "libserialport.h"

void do_check(enum sp_return result);

#endif /* _AGSP_SANE_CHECK_H */