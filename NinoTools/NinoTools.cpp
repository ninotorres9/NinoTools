// NinoTools.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Zip.h"

#include <vector>
#include <iostream>
#include <string>
#include <list>
#include <type_traits>
#include <algorithm>


int main()
{
	auto function = [](int x) {return x % 10; };

	std::vector<int> container = { 1, 9, 25, 49, 81 };
	std::sort(std::begin(container), std::end(container),
		[function](int lhs, int rhs) {return function(lhs) < function(rhs); });
	for (auto each : container) {
		std::cout << each << std::endl;
	}

	system("pause");
    return 0;
}

