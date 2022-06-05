#include <iostream>
#include <cmath>

#include <string>

#include "Header.h"

int main()
{
	int stop = 1;
	std::cout << "Starting..." << std::endl << std::endl;
	while (stop == 1)
	{
		stop = request();
	}
	return 0;
}