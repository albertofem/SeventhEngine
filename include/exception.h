/**
 * SeventhEngine, an SDL-based general-purpose
 * game engine. Made for learning purposes
 *
 * Copyright (C) 2011 Alberto Fernández
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @author	Alberto Fernández <albertofem@gmail.com>
 * @version	0.1
 *
 */

#include <exception>

#ifndef STH_EXCEPTION_H_
#define STH_EXCEPTION_H_

/**
 * what() enum definition
 */

enum exception_what
{
	STH_EXCEPTION_CANNOT_LOAD_CONFIG_INI,
	STH_EXCEPTION_WRONG_INI_VALUES,
	STH_EXCEPTION_CANNOT_LOAD_SDL,
	STH_EXCEPTION_CANNOT_SET_VIDEOMODE,
	STH_EXCEPTION_BAD_RESOURCE_FILE,
	STH_EXCEPTION_SURFACE_LOAD,
	STH_EXCEPTION_GLTEXTURE_NOT_INITIALIZED
};

/**
 * Base class for all exception class
 * that will throw the engine
 *
 * @author Alberto
 * @since 1.0
 */
class seventh_exception : public std::exception
{
public:
	const char* getReason() throw()
	{
		return reason;
	}

	const exception_what getErrorID() throw()
	{
		return _id;
	}

protected:
	const char* reason;
	exception_what _id;

	seventh_exception(const char* what, const exception_what id) throw()
		: reason(what), _id(id)
	{
	};
};

/**
 * Engine exception
 *
 * @author Alberto
 * @since 1.0
 */
class seventh_engine_exception : public seventh_exception
{
public:
	seventh_engine_exception(const char* what, const exception_what id) throw()
		: seventh_exception(what, id)
	{
	};

	const char* what() const throw()
	{
		return "Engine core exception";
	};
};

/**
 * Main subsystem exception
 *
 * @author Alberto
 * @since 1.0
 */
class seventh_subsystem_exception : public seventh_exception
{
public:
	seventh_subsystem_exception(const char* what, const exception_what id) throw()
		: seventh_exception(what, id)
	{
	};

	const char* what() const throw()
	{
		return "Subsystem exception";
	};
};

/**
 * Display core exceptions
 *
 * @author Alberto
 * @since 1.0
 */

class seventh_displaycore_exception : public seventh_exception
{
public:
	seventh_displaycore_exception(const char* what, const exception_what id) throw()
		: seventh_exception(what, id)
	{
	};

	const char* what() const throw()
	{
		return "DisplayCore exception";
	};
};

/**
 * Resource manager exceptions
 *
 * @author Alberto
 * @since 1.0
 */

class seventh_resourcemanager_exception : public seventh_exception
{
public:
	seventh_resourcemanager_exception(const char* what, const exception_what id) throw()
		: seventh_exception(what, id)
	{
	};

	const char* what() const throw()
	{
		return "ResourceManager exception";
	};
};

#endif
