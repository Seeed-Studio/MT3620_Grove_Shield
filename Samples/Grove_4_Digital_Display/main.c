#include <applibs/log.h>

#include <Sensors/Grove4DigitDisplay.h>
#include <Common/Delay.h>

int main(int argc, char *argv[])
{
	Log_Debug("Application starting\n");

	// Initialize Grove 4 Digital Display, use pin_4 as pin_clik, pin_5 as pin_dio
	void *dev = Grove4DigitDisplay_Open(4, 5);

	// Enable clock point
	Grove4DigitDisplay_DisplayClockPoint(true);

	// Main loop
	int number = 1234;
	while (true) {
		// Display increasing number
		Grove4DigitDisplay_DisplayValue(dev, number++);
		usleep(1000000);
	}

	Log_Debug("Application exiting\n");
	return 0;
}
