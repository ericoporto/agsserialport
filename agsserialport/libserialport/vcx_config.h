/*
 * This file is part of the libserialport project.
 *
 * Copyright (C) 2020 Uwe Hermann <uwe@hermann-uwe.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBSERIALPORT_CONFIG_H
#define LIBSERIALPORT_CONFIG_H

/* #undef HAVE_SYS_FILE_H */

/* #undef HAVE_FLOCK */
/* #undef HAVE_REALPATH */
/* #undef HAVE_CLOCK_GETTIME */

/* #undef HAVE_BOTHER */

/* #undef HAVE_STRUCT_SERIAL_STRUCT */
/* #undef HAVE_STRUCT_TERMIOS2 */
/* #undef HAVE_STRUCT_TERMIOX */
/* #undef HAVE_STRUCT_TERMIOS2_C_ISPEED */
/* #undef HAVE_STRUCT_TERMIOS2_C_OSPEED */
/* #undef HAVE_STRUCT_TERMIOS_C_ISPEED */
/* #undef HAVE_STRUCT_TERMIOS_C_OSPEED */

#if defined(HAVE_STRUCT_TERMIOS_C_ISPEED) && defined(HAVE_STRUCT_TERMIOS_C_OSPEED)
#define HAVE_TERMIOS_SPEED 1
#endif
#if defined(HAVE_STRUCT_TERMIOS2_C_ISPEED) && defined(HAVE_STRUCT_TERMIOS2_C_OSPEED)
#define HAVE_TERMIOS2_SPEED 1
#endif

#endif
