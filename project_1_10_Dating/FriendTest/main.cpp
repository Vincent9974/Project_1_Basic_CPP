#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include "ComputerService.h"

#include "Computer.h"

void upgrade(Computer* computer)
{
    computer->cpu = "i9";
}

int main(void) {
	Computer desktop;
    ComputerService service;

	std::cout << desktop.description() << std::endl;
	
	service.upgrade(&desktop);

	std::cout << desktop.description() << std::endl;

    service.clean(&desktop);
    service.kill(&desktop);

	system("pause");
	return 0;
}
