#include <errno.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
//#include "../MT3620_Grove_Shield_Library/Grove.h"
#include "Grove.h"

#include <applibs/log.h>

static const struct timespec LoopInterval = { 0, 200000000 };
static volatile sig_atomic_t TerminationRequired = false;

static void TerminationHandler(int signalNumber)
{
	// Don't use Log_Debug here, as it is not guaranteed to be async signal safe
	TerminationRequired = true;
}

int main(int argc, char *argv[])
{
	Log_Debug("AzureSphereDemo1 application starting\n");

	struct sigaction action;
	memset(&action, 0, sizeof(struct sigaction));
	action.sa_handler = TerminationHandler;
	sigaction(SIGTERM, &action, NULL);

	int i2cFd;
	GroveShield_Initialize(&i2cFd);
	void* sht31 = GroveTempHumiSHT31_Open(i2cFd);

	////////////////////////////////////////
	// Loop

	while (!TerminationRequired)
	{
		GroveTempHumiSHT31_Read(sht31);
		float temp = GroveTempHumiSHT31_GetTemperature(sht31);
		Log_Debug("Temperature: %.1fC\n", temp);

		nanosleep(&LoopInterval, NULL);
	}

	////////////////////////////////////////
	// Terminate

	Log_Debug("Application exiting\n");
	return 0;
}
