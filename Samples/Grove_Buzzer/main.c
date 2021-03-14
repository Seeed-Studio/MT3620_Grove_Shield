#include <stdbool.h>
#include <applibs/log.h>

#include <Sensors/GroveRelay.h>
#include <Common/Delay.h>

int main(int argc, char *argv[])
{
    Log_Debug("Application starting\n");

    void *relay = GroveRelay_Open(0);

    // Main loop
    bool state = true;
    while (true) {
        if(state) {
            GroveRelay_On(relay);
			Log_Debug("Relay on\n");
        } else {
            GroveRelay_Off(relay);
			Log_Debug("Relay off\n");
        }        
        state = !state;
        
        usleep(2000000);
    }

    Log_Debug("Application exiting\n");
    return 0;
}
