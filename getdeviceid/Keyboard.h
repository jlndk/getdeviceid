#pragma once

#include "interceptionpp.h"

class Keyboard
{
	char *file;
	char *device;
public:
	Keyboard(const char *file);
	void GetAndSaveDeviceIdToFile();
	void Query();
	void SaveToIniFile();
};

