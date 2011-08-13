/**
 *
 * SeventhEngine, an SDL-based general-purpose
 * game engine. Made for learning purposes
 *
 * Licensed under GNU General Public License v3
 * <http://www.gnu.org/licenses/gpl.html>
 *
 * @author	Alberto Fernández <albertofem@gmail.com>
 * @version	1.0
 * @since		2011.0625
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

#endif
