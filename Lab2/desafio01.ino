const int buttonPin = 2;
const int ledPin = 13;
int lastButtonState = HIGH;
int buttonState;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
bool buttonPressed = false;

void setup() {
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
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
            buttonPressed = false; 
        }
        }
    }

    lastButtonState = leBotao;
}