#include <iostream>
#include "zhylib.h"
#include <Windows.h>

using namespace std;
int main()
{
	auto handle = LoadLibrary("zhytest.dll");

	ZhyPrint();
	return 0;
}