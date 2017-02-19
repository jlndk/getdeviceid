#include "stdafx.h"

#include "Keyboard.h"

Keyboard::Keyboard(const char * file)
{
	this->file = strdup(file);
}

void Keyboard::GetAndSaveDeviceIdToFile()
{
	Query();
	SaveToIniFile();
}


void Keyboard::Query(void)
{
	// There may be an unprocessed key up event in the queue, trash it
	Interception *in0 = new Interception(INTERCEPTION_FILTER_KEY_DOWN);
	in0->Wait(100);
	in0->GetStroke();
	delete in0;

	printf("Press a key on the keyboard that should be intercepted\n\n");

	// There will be key a key down event followed by a key up event. 
	Interception *in = new Interception(INTERCEPTION_FILTER_KEY_ALL);
	in->Wait(INFINITE);
	//trigger = new KeyStroke(in->GetStroke()); // safe, it will not time out!
	device = in->GetDeviceNameCopy();

	in->Wait(INFINITE); // wait for key up
	in->GetStroke(); // trash it
	delete in;

}
void Keyboard::SaveToIniFile()
{
	char *l;

	if (device)
		WritePrivateProfileStringA(l, "device", device, file);
}
