#include <applibs/log.h>

#include <Grove.h>
#include <Sensors/GroveRotaryAngleSensor.h>

int main(int argc, char *argv[])
{
    Log_Debug("Application starting\n");

	// Initialize Grove Shield
	int i2cFd;
	GroveShield_Initialize(&i2cFd, 9600);

	void* rotary = GroveRotaryAngleSensor_Init(i2cFd, 0);

    // Main loop
    while (true) {
		float occupy = 1.0f - GroveRotaryAngleSensor_Read(rotary);
        Log_Debug("Angle Value %.2f\n", occupy);

        usleep(1000000);
    }

    Log_Debug("Application exiting\n");
    return 0;
}
