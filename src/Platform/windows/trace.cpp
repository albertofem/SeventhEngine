#include "Platform/windows/trace.h"

#ifdef _DEBUG

bool _trace(TCHAR* format, ...)
{
   TCHAR buffer[1000];

   va_list argptr;
   va_start(argptr, format);
   wvsprintf(buffer, format, argptr);
   va_end(argptr);

   OutputDebugString(buffer);
   OutputDebugString("\n");

   return true;
}

#endif