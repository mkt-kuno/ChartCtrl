#pragma once

// Project-wide precompiled header for ChartCtrl
// - Provides Windows/MFC/ATL time types (COleDateTime)
// - Trims Windows headers, sets reasonable target version
// - Add common STL headers used across the project

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif

// Target Windows 7+ by default unless already specified
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0601
#endif

// Use Unicode
#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif

// MFC core and standard components
#include <afxwin.h>
#include <afxext.h>
#include <afxcmn.h>
// OLE automation classes (COleDateTime/COleVariant)
#include <afxdisp.h>

// ATL helpers for date/time (ATL::COleDateTime)
#include <atlbase.h>
#include <atlcomtime.h>

// CRT and STL (frequently used)
#include <cassert>
#include <cstdint>
#include <cmath>
#include <limits>
#include <memory>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <string>

// TCHAR helpers
#include <tchar.h>

// Notes:
// - This header is force-included by the build to ensure COleDateTime is available
//   in translation units that don't explicitly include afxdisp.h.
// - If you target a different Windows version, override _WIN32_WINNT in your build.
