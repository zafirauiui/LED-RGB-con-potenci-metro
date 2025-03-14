/* Programa que ilumina con diferentes intensidades un LED RGB
 * O programa debe sacar polo monitor serie os valores das seis cores en decimal, 
 * hexadecimal e binario.
 * Asegúrate que o programa funciona tanto para LEDS RGB,como 
 * para o potenciómetro.
 * O programa debe definir un número limitado de niveis.

 * de luminosidade e empezando de 0, subir de intensidade.
 * Ao chegar ao máximo debe disminuir a intensidade até 0 
 * novamente. 
 * Criterios acerca do código:
 * (a) Debe ser lexible,
 * (b) o mantemento debe ser o máis sinxelo só con seis cores.
 * AUTOR:Dolores Patiño
 * Data:08/Marzo/2025
 */

// Declaración de saídas analóxicas

// Definir los pines
const int potPin = A0;
const int redPin = 6;
const int greenPin = 5;
const int bluePin = 3;

// Variable para definir si el LED es de ánodo común (true) o cátodo común (false)
const bool commonAnode = false;

int potValue;
long colorValue;
int red, green, blue;
int max, min = 0;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  potValue = analogRead(potPin);
  colorValue = map(potValue, 0, 1023, 38000, 1250000);
  setColor(colorValue);
  displayColorValues(colorValue);
  delay(100);
}

// Función para establecer el color del LED
void setColor(long colorValue) {
  if (colorValue < 250000) {
    red = 255; green = 0; blue = 0; // Rojo
  } else if (colorValue < 500000) {
    red = 0; green = 255; blue = 0; // Verde
  } else if (colorValue < 750000) {
    red = 0; green = 0; blue = 255; // Azul
  } else if (colorValue < 1000000) {
    red = 255; green = 255; blue = 0; // Amarillo
  } else if (colorValue < 1250000) {
    red = 255; green = 0; blue = 255; // Magenta
  } else {
    red = 0; green = 255; blue = 255; // Cian
  }

  // Ajustar los valores de color según el tipo de LED
  if (commonAnode) {
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  }

  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

// Función para mostrar los valores de color en el monitor serie
void displayColorValues(int colorValue) {
  Serial.print("Decimal: ");
  Serial.print(colorValue);
  Serial.print(", Hexadecimal: ");
  Serial.print(colorValue, HEX);
  Serial.print(", Binario: ");
  Serial.println(colorValue, BIN);
}


