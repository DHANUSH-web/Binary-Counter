/*
Project Name: 4-bit Binary counter using Arduino UNO
Created by: Dhanush H V
Teammate Name: Chethan P
Hardware required:
1) Monochromatic LED x4 (each led indicates each bit)
2) Arduino UNO x1, 220 Ohm or 320 Ohm Resistors x4, connecting wires, power cable for Arduino UNO
*/

const int led[4] = {2, 3, 4, 5};
int i, j;
void setup()
{
  Serial.begin(9600);
  for (i=0; i<4; i++)
  {
    pinMode(led[i], OUTPUT);
  }
}

void loop()
{
  for (j=0; j<16; j++)
  {
    delay(1000);
    displayBinary(j);
    Serial.println();
  }
}

void displayBinary(byte n)
{
  for (i=0; i<4; i++)
  {
    if (bitRead(n, i) == 1)
    {
      Serial.print(1);
      digitalWrite(led[i], true);
    }
    else
    {
      Serial.print(0);
      digitalWrite(led[i], false);
    }
  }
}
