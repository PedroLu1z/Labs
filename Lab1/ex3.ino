int led = 13;

// Define os padrões das letras em código Morse
const int morseM[] = {1, 1}; // letra M
const int morseO[] = {1, 1, 1}; // letra O
const int morseS[] = {0, 0, 0}; // letra S
const int morseC[] = {1, 0, 1, 0}; // letra C
const int morseU[] = {0, 0, 1}; // letra U

// Função para reproduzir um caractere Morse
void playMorse(const int *morsePattern, int length) {
  for (int i = 0; i < length; i++) {
    digitalWrite(led, HIGH);    // Acende o LED
    delay(morsePattern[i] == 0 ? 150 : 400);
    digitalWrite(led, LOW);     // Apaga o LED
    delay(100);
  }
}

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  playMorse(morseM, sizeof(morseM) / sizeof(morseM[0])); // M
  delay(200);
  playMorse(morseO, sizeof(morseO) / sizeof(morseO[0])); // O
  delay(200);
  playMorse(morseS, sizeof(morseS) / sizeof(morseS[0])); // S
  delay(200);
  playMorse(morseC, sizeof(morseC) / sizeof(morseC[0])); // C
  delay(200);
  playMorse(morseO, sizeof(morseO) / sizeof(morseO[0])); // O
  delay(200);
  playMorse(morseU, sizeof(morseU) / sizeof(morseU[0])); // U

  delay(3000);
}