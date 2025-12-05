/**
 * @file ChartCtrl_Prefix.h
 * @brief Common headers for ChartCtrl library
 *
 * This header provides all necessary Windows/MFC/ATL includes for the
 * ChartCtrl library without requiring precompiled headers.
 *
 * Build configuration (UNICODE, _WIN32_WINNT, etc.) should be set via
 * CMakeLists.txt or the consuming project's build system.
 */

#pragma once

// MFC core and standard components
#include <afxwin.h>
#include <afxext.h>
#include <afxcmn.h>
// OLE automation classes (COleDateTime/COleVariant)
#include <afxdisp.h>

// ATL helpers for date/time (ATL::COleDateTime)
#include <atlbase.h>
#include <atlcomtime.h>

// CRT and STL
#include <cmath>
#include <algorithm>
#include <map>
#include <list>
#include <vector>
#include <string>

// TCHAR helpers
#include <tchar.h>
