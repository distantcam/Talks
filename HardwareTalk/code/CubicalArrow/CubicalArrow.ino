#include "SPI.h"
#include "Cube.h"

Cube cube;

void setup() 
{
  // Serial port options for control of the Cube using serial commands are:
  // 0: Control via the USB connector (most common).
  // 1: Control via the RXD and TXD pins on the main board.
  // -1: Don't attach any serial port to interact with the Cube.
  cube.begin(0, 115200); // Start on serial port 0 (USB) at 115200 baud
}

void loop() 
{
  cube.all(BLACK);
  for (int i = 0; i < 3; i++) {
    cube.set(i, 0, 0, RED);
    cube.set(0, i, 0, RED);
    cube.set(0, 0, i, RED);
  }
  cube.set(1, 1, 0, RED);
  cube.set(0, 1, 1, RED);
  cube.set(1, 0, 1, RED);
  delay(1000);
  
  cube.all(BLACK);
  for (int i = 0; i < 3; i++) {
    cube.set(i, 3, 0, RED);
    cube.set(0, 3-i, 0, RED);
    cube.set(0, 3, i, RED);
  }
  cube.set(1, 2, 0, RED);
  cube.set(0, 2, 1, RED);
  cube.set(1, 3, 1, RED);
  delay(1000);
  
  cube.all(BLACK);
  for (int i = 0; i < 3; i++) {
    cube.set(3-i, 3, 0, RED);
    cube.set(3, 3-i, 0, RED);
    cube.set(3, 3, i, RED);
  }
  cube.set(2, 2, 0, RED);
  cube.set(3, 2, 1, RED);
  cube.set(2, 3, 1, RED);
  delay(1000);
  
  cube.all(BLACK);
  for (int i = 0; i < 3; i++) {
    cube.set(3-i, 0, 0, RED);
    cube.set(3, i, 0, RED);
    cube.set(3, 0, i, RED);
  }
  cube.set(2, 1, 0, RED);
  cube.set(3, 1, 1, RED);
  cube.set(2, 0, 1, RED);
  delay(1000);
}
