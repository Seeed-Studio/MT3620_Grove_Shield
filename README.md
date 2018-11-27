## About MT3620 Grove Shield Library

This is library for Azure Sphere MT3620 Grove Shield, the shield enhences Azure Sphere by adding I2C interface and Analog input. 

### Requirements

- Operation System - Final version of Windows 10
- [Visual Studio 2017 Community/Professional/Enterprise](https://visualstudio.microsoft.com/downloads/)
- [Azure Sphere SDK Preview for Visual Studio](https://aka.ms/AzureSphereSDKDownload)
- Hardware - [Azure Sphere](https://www.seeedstudio.com/Azure-Sphere-MT3620-Development-Kit-US-Version-p-3052.html), [MT3620 Grove Shield](https://www.seeedstudio.com/MT3620-Grove-Shield-p-3145.html) 

### Create a MT3620 application with Visual Studio 2017

1. Open Visual Studio 2017
2. Select __File > New > Project__
3. Select __Installed > Visual C++ > Cross Platform > Azure Sphere__ at the left side

There are some templates for MT3620, select __Blank Application for MT3620 RDB (Azure Sphere)__ to create a blank project, or if you want to use __Azure IoT Hub__ then select __Azure IoT Hub Sample for MT3620 RDB(Azure Sphere)__.

4. Select __Blank Application for MT3620 RDB (Azure Sphere)__ and type a project name, select a project location then click __OK__.

### Import MT3620_Grove_Shield_Library to the project

1. Right-Click the solution title In __Solution Explorer__ window on the right side
2. Select __Add > Existing Project__
3. Select __MT3620_Grove_Shield_Library > MT3620_Grove_Shield_Library.vcxproj__, then click __Open__ 
4. Now MT3620_Grove_Shield_Library has been added to the solution.
5. Right-Click the project name of your application, select __Properties > C/C++ > General > Additional Include Directories__
6. Click the __down arraw >  Edit... > New Line__ icons, add the path of  __MT3620_Grove_Shield_Library__ to the blank item, click __Select Folder__ > __OK__ > __OK__
7. Go to the application project Right-Click __References__ > __Add References__, select __Projects__, click the check box of __MT3620_Grove_Shield_Library__, then click __OK__
8. Select __app_manifest.json__ in the application project, add the below attributions, so that we can use the peripherals that MT3620 Grove Shield would use.

```JSON
"Capabilities": {
	"AllowedConnections": [],
	"Gpio": [ 8, 9, 10, 15, 16, 17, 18, 19, 20, 12, 13, 0, 1, 4, 5, 57, 58, 11, 14, 48 ],
	"Uart": [ "ISU0", "ISU3" ],
	"WifiConfig": false
}
```
9. Now you can edit main.c file in __Source Files__, to include __Grove.h__ and __Sensor/xxx.h__ to drive the MT3620 Grove Shield.


### Some available header files

- Grove.h
- Sensors/Grove4DigitDisplay.h
- Sensors/GroveRelay.h
- Sensors/GroveTempHumiBaroBME280.h
- Sensors/GroveTempHumiSHT31.h
- Sensors/GroveAD7992.h
- Sensors/GroveOledDisplay96x96.h
- Sensors/GroveRelay.h
- Sensors/GroveRotaryAngleSensor.h
- Sensors/GroveLEDButton.h
- Sensors/GroveLightSensor.h
- 

### Usage of the library, see Example - Temp and Huminidy SHT31

1. Add headers

```C
#include "Grove.h"
#include "Sensors/GroveTempHumiSHT31.h"
```

2. Initialize the shield in main() function

```C
int i2cFd;
GroveShield_Initialize(&i2cFd, 115200); // baudrate - 9600,14400,19200,115200,230400 
```

1. Initialize and instantiation

```C
void* sht31 = GroveTempHumiSHT31_Open(i2cFd);
```


4. Read temp and humidiy from the sensor
   
```C
GroveTempHumiSHT31_Read(sht31);
float temp = GroveTempHumiSHT31_GetTemperature(sht31);
float humi = GroveTempHumiSHT31_GetHumidity(sht31);
```
