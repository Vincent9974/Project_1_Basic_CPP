#include "ComputerService.h"
#include "Computer.h"
#include <iostream>

void ComputerService::upgrade(Computer* computer) {
	computer->cpu = "i9";
}

void ComputerService::clean(Computer *computer)
{
	std::cout << "正在对电脑执行清理[CPU:" 
			  << computer->cpu << "]..." 
			  << std::endl;
}

void ComputerService::kill(Computer *computer)
{
		std::cout << "正在对电脑执行杀毒[CPU:"
		<< computer->cpu << "]..."
		<< std::endl;

}
