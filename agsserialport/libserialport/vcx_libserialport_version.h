/*
 * This file is part of the libserialport project.
 *
 * Copyright (C) 2013, 2015 Martin Ling <martin-libserialport@earth.li>
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

#ifndef LIBSERIALPORT_LIBSERIALPORT_VERSION_H
#define LIBSERIALPORT_LIBSERIALPORT_VERSION_H

/**
 * @defgroup Versions Versions
 *
 * Version number querying functions, definitions, and macros.
 *
 * This set of API calls returns two different version numbers related
 * to libserialport. The "package version" is the release version number of the
 * libserialport tarball in the usual "major.minor.micro" format, e.g. "0.1.0".
 *
 * The "library version" is independent of that; it is the libtool version
 * number in the "current:revision:age" format, e.g. "2:0:0".
 * See http://www.gnu.org/software/libtool/manual/libtool.html#Libtool-versioning for details.
 *
 * @deprecated Since 0.1.2 the "library version" macros and functions are
 * deprecated and will always return 9 or "9:9:9" dummy values respectively.
 *
 * Both version numbers (and/or individual components of them) can be
 * retrieved via the API calls at runtime, and/or they can be checked at
 * compile/preprocessor time using the respective macros.
 *
 * @{
 */

/*
 * Package version macros (can be used for conditional compilation).
 */

/** The libserialport package 'major' version number. */
#define SP_PACKAGE_VERSION_MAJOR 0

/** The libserialport package 'minor' version number. */
#define SP_PACKAGE_VERSION_MINOR 1

/** The libserialport package 'micro' version number. */
#define SP_PACKAGE_VERSION_MICRO 0

/** The libserialport package version ("major.minor.micro") as string. */
#define SP_PACKAGE_VERSION_STRING "0.1.2-git-9b16c7f"

/*
 * Library/libtool version macros (can be used for conditional compilation).
 */

/**
 * The libserialport libtool 'current' version number.
 *
 * @deprecated Since 0.1.2 this will always be a dummy value of 9.
 */
#define SP_LIB_VERSION_CURRENT 9

/**
 * The libserialport libtool 'revision' version number.
 *
 * @deprecated Since 0.1.2 this will always be a dummy value of 9.
 */
#define SP_LIB_VERSION_REVISION 9

/**
 * The libserialport libtool 'age' version number.
 *
 * @deprecated Since 0.1.2 this will always be a dummy value of 9.
 */
#define SP_LIB_VERSION_AGE 9

/**
 * The libserialport libtool version ("current:revision:age") as string.
 *
 * @deprecated Since 0.1.2 this will always be a dummy value of "9:9:9".
 */
#define SP_LIB_VERSION_STRING "9:9:9"

/**
 * Get the major libserialport package version number.
 *
 * @return The major package version number.
 *
 * @since 0.1.0
 */
SP_API int sp_get_major_package_version(void);

/**
 * Get the minor libserialport package version number.
 *
 * @return The minor package version number.
 *
 * @since 0.1.0
 */
SP_API int sp_get_minor_package_version(void);

/**
 * Get the micro libserialport package version number.
 *
 * @return The micro package version number.
 *
 * @since 0.1.0
 */
SP_API int sp_get_micro_package_version(void);

/**
 * Get the libserialport package version number as a string.
 *
 * @return The package version number string. The returned string is
 *         static and thus should NOT be free'd by the caller.
 *
 * @since 0.1.0
 */
SP_API const char *sp_get_package_version_string(void);

/**
 * Get the "current" part of the libserialport library version number.
 *
 * @deprecated Since 0.1.2 this will always return a dummy value of 9.
 *
 * @return The "current" library version number.
 *
 * @since 0.1.0
 */
SP_API int sp_get_current_lib_version(void);

/**
 * Get the "revision" part of the libserialport library version number.
 *
 * @deprecated Since 0.1.2 this will always return a dummy value of 9.
 *
 * @return The "revision" library version number.
 *
 * @since 0.1.0
 */
SP_API int sp_get_revision_lib_version(void);

/**
 * Get the "age" part of the libserialport library version number.
 *
 * @deprecated Since 0.1.2 this will always return a dummy value of 9.
 *
 * @return The "age" library version number.
 *
 * @since 0.1.0
 */
SP_API int sp_get_age_lib_version(void);

/**
 * Get the libserialport library version number as a string.
 *
 * @deprecated Since 0.1.2 this will always return a dummy value of "9:9:9".
 *
 * @return The library version number string. The returned string is
 *         static and thus should NOT be free'd by the caller.
 *
 * @since 0.1.0
 */
SP_API const char *sp_get_lib_version_string(void);

/** @} */

#endif
