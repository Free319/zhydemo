#include <iostream>
#include "zhylib.h"
#ifdef _WIN32
#include <Windows.h>
#endif
#include <cassert>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, char* argv[])
{
	pair t_pair(1, "sss");
	auto [a, s] = t_pair;

	ZhyPrint();

	if (3 < argc)
	{
		cout << "parameter right" << endl;
		cout << (atoi(argv[1]) + atoi(argv[2])) << endl;
	}
	else
	{
		return -1;
	}

}


