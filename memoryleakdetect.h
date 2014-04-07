// make NO CHANGES to this file

#pragma once				// include this .h file file only once

// enable Visual C++ memory leak checking
#ifdef _DEBUG
#include <ostream>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif
