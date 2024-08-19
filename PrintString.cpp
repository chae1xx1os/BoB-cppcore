#include "pch.h"
#include "PrintString.h"
#include <Windows.h>
#include <tchar.h>
#include <cstdio>

void PrintString(LPCTSTR pszContext)
{
    tprintf(TEXT("%s"), pszContext);
}
