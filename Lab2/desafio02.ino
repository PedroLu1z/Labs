const int buttonPin = 2;   // Pino do botão
const int ledPin = 13;     // Pino do LED
int lastButtonState = HIGH; // Último estado do botão
int buttonState;            // Estado atual do botão
unsigned long lastDebounceTime = 0;  // Último tempo de debounce
unsigned long debounceDelay = 50;    // Tempo de debounce de 50ms
bool buttonPressed = false;         // Flag para verificar se o botão foi pressionado e solto

    void setup() {
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
    
    // Inicia a comunicação serial com uma taxa de 9600 bps
    Serial.begin(9600);
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
            digitalWrite(ledPin, !digitalRead(ledPin)); // Inverte o estado do LED
            buttonPressed = true;
            }
        } else {
            // Botão solto
            buttonPressed = false; // Reset da flag
        }
        }
    }

    lastButtonState = leBotao;

  // Log dos estados do botão e do LED
    Serial.print("Botão: ");
    Serial.print(buttonState == LOW ? "Pressionado" : "Solto");
    Serial.print(" | LED: ");
    Serial.println(digitalRead(ledPin) == HIGH ? "Ligado" : "Desligado");
}