//Konieczne jest pozostawienie zera na końcu wektora
#include "nutki.h"

int tones[] =
{
  C5, C5, G4, C5, D5,
  DS5, DS5, D5, C5,
  D5, D5, C5, AS4,
  C5, AS4, GS4,
  //DRUGA LINIA
  C5, G4, C5, G4, C5, G4, C5, D5,
  DS5, DS5, D5, C5,
  D5, D5, DS5, F5,
  G5, G5, GS5, G5,
  //TRZECIA LINIA
  GS5, G5, GS5, G5,
  GS5, G5,
  DS5, G5, G5, F5,
  G5, DS5,
  GS5, GS5, GS5, G5,
  //CZWARTA LINIA
  DS5, G5,
  GS5, GS5, GS5, AS5,
  G5, DS5,
  0
};
int tempo[] =
{
  //PIERWSZA LINIA
  2, 8, 8, 8, 8,
  2, 8, 8, 8,
  2, 8, 8, 8,
  2, 4, 4,
  //DRUGA LINIA
  8, 8, 8, 8, 8, 8, 8, 8,
  2, 8, 8, 8,
  2, 8, 8, 8,
  2, 8, 8, 8,
  //TRZECIA LINIA
  2, 8, 8, 8,
  2, 4,
  2, 8, 8, 8,
  2, 2,
  2, 8, 8, 8,
  //CZWARTA LINIA
  2, 4,
  2, 8, 8, 8,
  2, 2,
  0
};

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  int a = counter(tones);
  int b = counter(tempo);
  if (a != b)
  {
    Serial.println("BŁĄD");
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
  int number = counter(tones);
  int i = 0;
  for (i = 0; i < number; i++)
  {
    long time = 1200 / tempo[i];
    tone(8, tones[i], time);
    delay(time * 1.3);
    noTone(8);
  }
  delay(1000);
}

int counter(int array[])
{
  int i = 0;
  while (array[i] != 0)
  {
    i++;
  }
  return i;
}
