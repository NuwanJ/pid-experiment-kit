# Introduction

This is a demonstration and experiment kit for PID tuning experiments.

![Image](https://user-images.githubusercontent.com/11540782/159842468-e33c2a17-1b92-4fab-a162-e6a546336e6b.jpg)

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

#### Bill of Materials

- ESP32 Dev Board
- TB6612FNG (Motor Driver)
- N20 DC Geared Motor (Recommended Motor: 6v 100rpm)
- 100kOhm Potentiometer
- 5mm Form Board (Size: A4)
- Limit Switches (Optional, previously realized those are not required)
- Vero Board
- Circuit Wire
- A few 3mm screws and nuts
  - M3x15 2pcs
  - M3x35 1pcs
- 3D Printed Components
  - Arrow Gear (PLA, White)
  - Motor Gear (PLA, White)
  - Motor Bracket (PLA, Black)
  - Belt (TPU or Flexible Material)

#### Firmware

The complete firmware is available [here](https://github.com/NuwanJ/pid-experiment-kit/firmware). The microcontroller used here is ESP32 Dev Board. But it is possible to change the firmware a little and use it with another microcontroller.

Can change following variables to alter the *kP, kI and kD* constants.
```cpp
//PID constants
double kp = 15;
double ki = 0.01;
double kd = 0.05;
```

You can build and upload the firmware using *[PlatformIO](https://platformio.org/)*.

#### Example

![ezgif-1-cd30b49b66](https://user-images.githubusercontent.com/11540782/159843286-3516f3f6-1661-443f-b3f9-af0feb3332eb.gif)
