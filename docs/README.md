# Introduction

This is a demonstration and experiment kit for PID tuning experiments.



### Folder Structure

- circuit: The circuit design
- design
    - CAD: SolidWorks 2016 design files
    - STL_3dPrint: STL files needed to be printed
- docs: Documentation
- firmware: The firmware of the ESP32 development board

#### Circuit

Circuit design was done using the software named Fritzing, and the schematic is available in PDF format.

![image](https://user-images.githubusercontent.com/11540782/158548865-b33d34e3-3fe2-4efb-8626-4ecc9cf046ce.png)

#### Design

The complete CAD design is available as a SolidWorks 2016 model from [here](https://github.com/NuwanJ/pid-experiment-kit/design/CAD/). Additionally, 3d printable parts will be available as STL files from [here](https://github.com/NuwanJ/pid-experiment-kit/design/STL_3dPrint)

#### firmware

The complete firmware is available [here](https://github.com/NuwanJ/pid-experiment-kit/firmware). The microcontroller used here is ESP32 Dev Board. But it is possible to change the firmware a little and use it with another microcontroller.

Can change following variables to alter the *kP, kI and kD* constants.
```cpp
//PID constants
double kp = 15;
double ki = 0.01;
double kd = 0.05;
```

You can build and upload the firmware using *[PlatformIO](https://platformio.org/)*.
