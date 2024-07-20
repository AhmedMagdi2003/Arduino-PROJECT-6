#include <Wire.h>
#define forword_button 4
#define backword_button 7
#define rigth_button 5
#define left_button 6
byte move[4] = { LOW, LOW, LOW, LOW };
void setup()
{
  pinMode(forword_button, INPUT);
  pinMode(backword_button, INPUT);
  pinMode(rigth_button, INPUT);
  pinMode(left_button, INPUT);
  Wire.begin(8);
}

void loop()
{
  move[0] = digitalRead(forword_button);
  move[1] = digitalRead(backword_button);
  move[2] = digitalRead(rigth_button);
  move[3] = digitalRead(left_button);
  Wire.onRequest(request1);
}
void request1() 
{
  Wire.write(move,4);
}