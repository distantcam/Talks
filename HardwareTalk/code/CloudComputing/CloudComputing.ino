#include "SPI.h"
#include "Cube.h"

#define RAINDROPDELAY 100     // Milliseconds between raindrop movements

byte drop1XPos;
byte drop1YPos;
byte drop1ZPos = 2;

byte drop2XPos;
byte drop2YPos;
byte drop2ZPos = 0;

Cube cube;

void setup(void) {
  // Serial port options for control of the Cube using serial commands are:
  // 0: Control via the USB connector (most common).
  // 1: Control via the RXD and TXD pins on the main board.
  // -1: Don't attach any serial port to interact with the Cube.
  cube.begin(0, 115200); // Start on serial port 0 (USB) at 115200 baud
}

void loop(void) {
  if(drop1ZPos == 4)
  {
    drop1XPos = random(4);
    drop1YPos = random(4);
  }

  if(drop2ZPos == 4)
  {
    drop2XPos = random(4);
    drop2YPos = random(4);
  }

  cube.all(BLACK);
  cube.setplane(Z, 3, WHITE); // Cloud layer

  if(drop1ZPos > 0)
  {
    drop1ZPos--;
    cube.set(drop1XPos, drop1YPos, drop1ZPos, BLUE);
  } else {
    drop1ZPos = 4;
  }

  if(drop2ZPos > 0)
  {
    drop2ZPos--;
    cube.set(drop2XPos, drop2YPos, drop2ZPos, BLUE);
  } else {
    drop2ZPos = 4;
  }

  delay(RAINDROPDELAY);
}
