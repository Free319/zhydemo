#include "zhylib.h"
#include <iostream>

using namespace std;

#ifdef DLL_EXPORT
#include <functional>
#endif

void ZhyPrint()
{
	cout << "ZHY,Hello World!" << endl;
	return;
}

int ZhyAdd(int a, int b)
{
	return  a - b;
}
