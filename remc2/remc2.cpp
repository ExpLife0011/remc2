// remc2.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include "engine/engine_support.h"
#include "engine/sub_main.h"
int main(int argc, char** argv)
//int main()
{
	VGA_Init();
	//char *argv[] = { "netherw.exe","-level","2", NULL };
	//int argc = (sizeof(argv) / sizeof(argv[0])) - 1;
	char *envp[] = { NULL };
	//char *envp[] = { "env=xx", NULL };
	//ds:esi - cesta k nazvu
	support_begin();
	int retval = sub_main(argc, argv, envp);
	support_end();
	//saveactstate();
    return 0;
}

