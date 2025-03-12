#include <Arduino.h>

// lecture 1 and 2
int sumFunction(int, int);
int my_integers[6] = { 1,2,3,4,5 };
char my_char[6] = { 'a', 'b', 'c', 'd', 'e' };

// lecture 3
const int totalStates = 10;
const int ledPin = 7;
int ledState[totalStates] = { LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH };
int ledDuration[totalStates] = { 200, 300, 400, 200, 200, 300, 400, 200, 200, 200 };

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  while (!Serial) {

  }

  Serial.println("Your array numbers:");
  for (int i = 0; i < 5; i++) {
    Serial.print("Index: ");
    Serial.print(i);
    Serial.print(" Value: ");
    Serial.println(my_integers[i]);
  }

  Serial.println();
  Serial.println("Let's calculate those numbers:");
  int calculated_ints[4];

  for (int i = 0; i < 4; i++) {
    Serial.print(my_integers[i]);
    Serial.print(" + ");
    Serial.print(my_integers[i + 1]);
    Serial.print(" = ");
    calculated_ints[i] = sumFunction(my_integers[i], my_integers[i + 1]);
    Serial.println(calculated_ints[i]);

    my_integers[i + 1] = calculated_ints[i];
  }


  // Lecture 2
  Serial.println();
  Serial.println("Your array characters:");
  for (int i = 0; i < 5; i++) {
    Serial.print("Index: ");
    Serial.print(i);
    Serial.print(" Value: ");
    Serial.print(my_char[i]);
    Serial.print(", ");
    Serial.print("ASCII Value: ");
    Serial.println((int)my_char[i]);
  }

  // Lecture 3
  pinMode(ledPin, OUTPUT);

}

void loop() {
  for (int i = 0; i < totalStates; i++)
  {
    digitalWrite(ledPin, ledState[i]);
    delay(ledDuration[i]);
  }

}

// put function definitions here:
int sumFunction(int x, int y) {
  return x + y;
}