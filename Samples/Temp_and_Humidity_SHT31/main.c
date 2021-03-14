#include <applibs/log.h>

#include <Grove.h>
#include <Sensors/GroveTempHumiSHT31.h>

int main(int argc, char *argv[])
{
    Log_Debug("Application starting\n");

	int i2cFd;
	GroveShield_Initialize(&i2cFd, 115200);
	void* sht31 = GroveTempHumiSHT31_Open(i2cFd);

    // Main loop
    while (true) {
		GroveTempHumiSHT31_Read(sht31);
		float temp = GroveTempHumiSHT31_GetTemperature(sht31);
		float humi = GroveTempHumiSHT31_GetHumidity(sht31);
		Log_Debug("Temperature: %.1fC\n", temp);
		Log_Debug("Humidity: %.1f\%c\n", humi, 0x25);

		usleep(1000000);
    }

    Log_Debug("Application exiting\n");
    return 0;
}
