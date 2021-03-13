#include <applibs/log.h>

#include <Grove.h>
#include <Sensors/GroveLightSensor.h>
#include <Sensors/GroveAD7992.h>

int main(int argc, char *argv[])
{
    Log_Debug("Application starting\n");

	// Initialize Grove Shield
	int i2cFd;
	GroveShield_Initialize(&i2cFd, 115200);

	// Initialize Light Sensor
	void *light = GroveLightSensor_Init(i2cFd, 0);

    // Main loop
    while (true) {
		float value = GroveLightSensor_Read(light);
		value = GroveAD7992_ConvertToMillisVolt(value);
        Log_Debug("Light value %dmV\n", (uint16_t)value);

        usleep(1000000);
    }

    Log_Debug("Application exiting\n");
    return 0;
}
