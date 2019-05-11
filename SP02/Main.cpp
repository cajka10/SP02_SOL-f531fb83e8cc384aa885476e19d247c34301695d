#include "structures/heap_monitor.h"
#include <iostream>
#include "Volby.h"

int main()
{

	initHeapMonitor();
	Volby* volby = new Volby();
	delete volby;
	return 0;
}
