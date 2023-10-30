/*
Código C++
Programa Arduino Game perguntas e respostas
prof. Edney Rossi

Esquema:
D13---Saida led1
D12---Saida led2
D11---Entrada botao1
D10---Entrada botao2
D9---Entrada botaoReset


Funcionamento: Ao apertar o botao1 o led1 liga e impede que o led2 ligue
e fica assim até que o botaoReset seja precionado e então desliga, 
ao apertar o botao2 o led2 liga e impede que o led1 ligue 
e fica assim até que o botaoReset seja pressionado e então desliga.
*/

// Definição dos pinos
const int led1Pin = 13;
const int led2Pin = 12;
const int button1Pin = 11;
const int button2Pin = 10;
const int buttonResetPin = 9;

// Variáveis para rastrear o estado dos botões e LEDs
bool led1State = false;
bool led2State = false;
bool button1Pressed = false;
bool button2Pressed = false;

void setup() {
  // Inicializa os pinos como saídas ou entradas
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(buttonResetPin, INPUT_PULLUP);

  // Desliga os LEDs no início
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
}

void loop() {
  // Verifica o estado do botão 1
  if (digitalRead(button1Pin) == LOW && !button2Pressed) {
    button1Pressed = true;
    button2Pressed = false;  // Garante que apenas um LED está ligado
    led1State = true;  // Alterna o estado do LED1
    digitalWrite(led1Pin, led1State);
    digitalWrite(led2Pin, LOW);  // Desliga o LED2
  }

  // Verifica o estado do botão 2
  if (digitalRead(button2Pin) == LOW && !button1Pressed) {
    button2Pressed = true;
    button1Pressed = false;  // Garante que apenas um LED está ligado
    led2State = true;  // Alterna o estado do LED2
    digitalWrite(led2Pin, led2State);
    
    digitalWrite(led1Pin, LOW);  // Desliga o LED1
  }

  // Verifica o botão de reset
  if (digitalRead(buttonResetPin) == LOW) {
    // Desliga ambos os LEDs e permite que os botões sejam pressionados novamente
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    button1Pressed = false;
    button2Pressed = false;
  }
}
