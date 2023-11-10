const int buttonPin = 2;  // Pino do botão
const int ledPin = 9;     // Pino do LED PWM
int lastButtonState = HIGH;
int buttonState;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
bool buttonPressed = false;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);  // Inicia a comunicação serial
}

void loop() {
  int leBotao = digitalRead(buttonPin);

  if (leBotao != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (leBotao != buttonState) {
      buttonState = leBotao;

      if (buttonState == LOW) {
        // Botão pressionado
        if (!buttonPressed) {
          // Se o botão ainda não foi pressionado e solto, alterna o estado do LED
          digitalWrite(ledPin, !digitalRead(ledPin));  // Inverte o estado do LED
          buttonPressed = true;
        }
      } else {
        // Botão solto
        buttonPressed = false;  // Reset da flag
      }
    }
  }

  lastButtonState = leBotao;

  // Leitura do valor analógico no pino A0
  int analogValue = analogRead(A0);

  // Mapeia o valor lido (0-1023) para o intervalo de brilho do LED (0-255)
  int brightness = map(analogValue, 0, 1023, 0, 255);

  // Define o brilho do LED com base no valor mapeado
  analogWrite(ledPin, brightness);

  // Log dos estados do botão, LED e valor analógico
  Serial.print("Botão: ");
  Serial.print(buttonState == LOW ? "Pressionado" : "Solto");
  Serial.print(" | LED: ");
  Serial.print(digitalRead(ledPin) == HIGH ? "Ligado" : "Desligado");
  Serial.print(" | Valor Analógico: ");
  Serial.print(analogValue);
  Serial.print(" | Brilho do LED: ");
  Serial.println(brightness);
}