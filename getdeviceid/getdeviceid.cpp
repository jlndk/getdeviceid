// intercept.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Keyboard.h"
#include "util.h"

void help(void)
{
	printf("Command line parameters:\n");
	printf("\t/ini path\to\file.ini specify where the device id is saved (optional)\n");
}


int _tmain(int argc, _TCHAR* argv[]) {
	
	// Set to default, /ini switch will override
	char currDir[1024];
	GetCurrentDirectory(1024, currDir);
	char iniFile[1024];
	sprintf(iniFile, "%s\\deviceid.ini", currDir);

	for (int i=0; i<argc; i++) {
		
		if (stricmp(argv[i], "/ini") == 0) {
			// Missing parameter
			if ( i == argc-1 )
				help();

			strcpy(iniFile, argv[i+1]);
			i++;
		}
	}

	printf("Using configuration file %s\n\n", iniFile);

	Keyboard keyboard(iniFile);

	keyboard.GetAndSaveDeviceIdToFile();

	return 0;
}

