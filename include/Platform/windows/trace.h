#include <windows.h>

#ifdef _DEBUG
bool _trace(TCHAR *format, ...);
#define TRACE _trace
#else
#define TRACE false
#define _trace false
#endif
