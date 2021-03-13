#include <stdbool.h>
#include <applibs/log.h>

#include <Sensors/GroveLEDButton.h>
#include <Common/Delay.h>

int main(int argc, char *argv[])
{
    Log_Debug("Application starting\n");

	void *btn = GroveLEDButton_Init(1, 0);
	GPIO_Value_Type btn_sta, last_btn_sta;
	last_btn_sta = GroveLEDButton_GetBtnState(btn);

    // Main loop
    while (true) {
		btn_sta = GroveLEDButton_GetBtnState(btn);
		
		if (btn_sta != last_btn_sta) {
			if (btn_sta == 0) {
				GroveLEDButton_LedOn(btn);
				Log_Debug("Button pressed.\n");
			}
			else {
				GroveLEDButton_LedOff(btn);
				Log_Debug("Button released.\n");
			}
		}
		last_btn_sta = btn_sta;

		usleep(1);
    }

    Log_Debug("Application exiting\n");
    return 0;
}
