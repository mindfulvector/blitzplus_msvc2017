
/* Win32 runtime dynamic link lib */

#ifndef BBRUNTIME_DLL_H
#define BBRUNTIME_DLL_H

#include <windows.h>

#include "../app/debugger.h"

class Runtime
{
public:
  virtual int version();
  virtual const char* nextSym();
  virtual int symValue(const char* sym);
  virtual void startup(void* hinstance);
  virtual void shutdown();
  virtual void asyncStop();
  virtual void asyncRun();
  virtual void asyncEnd();
  virtual void checkmem(void* streambuf);

  virtual void execute(void (*pc)(), const char* args, BBDebugger* dbg);
};

extern "C" _declspec(dllexport) Runtime * _cdecl runtimeGetRuntime();

#endif