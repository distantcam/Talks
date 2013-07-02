#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

int brightness = 15;
int currentSpeed = 2;

byte cell[8][8];

void setup() {
  matrix.begin(0x70);  // pass in the address
  matrix.setBrightness(15);
  
  randomSeed(analogRead(0));
  
  ResetBoard();
}

void loop() {
  DrawBoard();
  int diff = MoveNext();
  if (diff == 0)
  {
    ResetBoard();
    delay(500);
  }
  delay(100);
}

int MoveNext() {
  int diff = 0;
  
  byte next[8][8];
  
  for (byte x = 0; x < 8; x++) {
    for (byte y = 0; y < 8; y++) {
      byte count = CountNeighbours(x, y);
      next[x][y] = cell[x][y];
      if (cell[x][y] > 0) {
        if (count < 2 || count > 3) {
          next[x][y] = 0;
          diff++;
        } else if (cell[x][y] < 255) {
          next[x][y] = cell[x][y] + 1;
          if (next[x][y] < 4) diff++;
        }
      } else if (count == 3) {
        next[x][y] = 1;
        diff++;
      }
    }
  }
  
  for (byte x = 0; x < 8; x++) {
    for (byte y = 0; y < 8; y++) {
      cell[x][y] = next[x][y];
    }
  }
  
  return diff;
}

int CountNeighbours(byte x, byte y) {
  byte count = 0;
  for (int i = x-1; i <= x+1; i++) {
    for (int j = y-1; j <= y+1; j++) {
      if ((i != x || j != y) && cell[Wrap(i)][Wrap(j)] > 0)
        count++;
    }
  }
  return count;
}

int Wrap(int value) {
  int result = value;
  while (result < 0)
    result += 8;
  while (result > 7)
    result -= 8;
  return result;
}

void ResetBoard() {
  for (byte x = 0; x < 8; x++) {
    for (byte y = 0; y < 8; y++) {
      cell[x][y] = random(2);
    }
  }
}

void DrawBoard() {
  matrix.clear();
  for (byte x = 0; x < 8; x++) {
    for (byte y = 0; y < 8; y++) {
      if (cell[x][y] > 2)
        matrix.drawPixel(x, y, LED_RED);
      else if (cell[x][y] > 1)
        matrix.drawPixel(x, y, LED_YELLOW);
      else if (cell[x][y] > 0)
        matrix.drawPixel(x, y, LED_GREEN);
    } 
  }
  matrix.writeDisplay();
}
