---
description: >-
  Este TP consiste en construir un circuito electrónico, conectando componentes
  como indicadores, sensores y actuadores, para luego utilizarlos en diferentes
  ejercicios. La dificultad es incremental.
---

# 📟 TP4: E/S

## Integrantes

[Josefina Jahde](https://campusvirtual.utdt.edu/user/view.php?id=26713\&course=4302)

[Luz Alba Posse](https://github.com/luzalbaposse)

[Dafydd Jenkins](https://github.com/Dafydd8)

[Valentino Cannestraci](https://campusvirtual.utdt.edu/user/view.php?id=26746\&course=4302)

## Enunciado

### Introducción

Los mecanismos de entrada/salida que utilizan los sistemas de computo modernos requieren de una gran complejidad técnica para llevarlos a la práctica. Por esta razón se optó por utilizar dispositivos más simples basados en microcontroladores, para experimentar con mecanismos de entrada/salida.&#x20;

La presente actividad consiste construir un circuito electrónico, conectando componentes como indicadores, sensores y actuadores, para luego utilizarlos en diferentes ejercicios. Los ejercicios están diseñados para ir incrementando su dificultad a medida que se incluyen distintos mecanismos de entrada/salida y componentes.&#x20;

Para realizar el trabajo se utilizará un kit de Arduino basado en la placa Mega 2560 Rev3. Los componentes como servos, motores, joysticks no requieren mayor cuidado que conectar adecuadamente sus entradas, mientras que componentes como resistencias y leds requieren prestar mucha atención en el uso, para no manipularlos incorrectamente y dejarlos inutilizados.&#x20;

La infraestructura de Arduino provee todo el software necesario para compilar y ejecutar ejemplos sobre estas placas, además provee bibliotecas de funciones utilitarias para controlar dispositivos. Al final de este enunciado se presentan algunas funciones básicas como referencia. Es importante que utilicen la documentación oficial para resolver dudas y consultar otras funciones que gusten usar para resolver los ejercicios solicitados.

<figure><img src="../.gitbook/assets/Captura de pantalla 2023-06-13 a la(s) 06.55.31.png" alt=""><figcaption><p>Placa arduino conectada a un servomotor, joystick analógico y leds</p></figcaption></figure>

### Actividades preliminares&#x20;

Este trabajo práctico está diseñado para ser realizado durante dos jornadas de clase, para esto se debe previamente tener instalado todo el Arduino IDE. El software se debe descargar de [https://www.arduino.cc/en/software,](https://www.arduino.cc/en/software,) donde se presenta tanto para sistemas Windows, Linux o Mac.&#x20;

Es fundamental que previamente a iniciado el primer día del taller tengan instalado todo el software de Arduino. Además deben leer toda la documentación provista y estar familiarizados con el enunciado del taller, buscando analizar los códigos presentados y las posibles formas de solucionar los ejercicios pedidos.

<figure><img src="../.gitbook/assets/Captura de pantalla 2023-06-13 a la(s) 06.58.34.png" alt=""><figcaption></figcaption></figure>

El segundo paso, ya en clase, será armar el circuito presentado anteriormente. Deben conectar todos los cables y conexiones a componentes como se indica en la figura. Puede que para esto, tengan que usar más cables de los indicados, lo importante es respetar las conexiones del circuito.&#x20;

### Ejercicios&#x20;

Algunos de los items de los ejercicios estás marcados con la etiqueta **\[Trabajo Previo]**, esto indica,  que es tarea que se debe realizar previamente al taller. En todos los casos se solicitará que tengan completos estos puntos antes de comenzar el taller. El 30% de la calificación del taller corresponde a que tengan realizada está tarea, la cual será verificada al comienzo del taller. Por otro lado, otros items pueden tener las etiquetas \[Opción A] o \[Opción B], esto quiere decir que a la hora de realizar el ejercicio, pueden elegir entre hacer uno u otro de los items.

1.  **Introducción**&#x20;

    Leer la documentación adjunta, complementando el contenido con la documentación oficial provista en [https://www.arduino.cc/reference/es/](https://www.arduino.cc/reference/es/) y responder las siguientes preguntas:&#x20;

    1. **\[Trabajo Previo]** ¿Cual es la diferencia entre un pin digital y un pin analógico?&#x20;
    2. **\[Trabajo Previo]** ¿Qué hace la función digitalPinToInterrupt?&#x20;
    3. **\[Trabajo Previo]** ¿Para que sirve la función map?
    4. **\[Trabajo Previo]** ¿Para que sirve habilitar la conexión serial?
2. **Uso de Leds**
   1.  Cargar el siguiente programa y ejecutarlo.

       `const int ledPin0 = 4;` \
       `const int ledPin1 = 5;` \
       `const int ledPin2 = 6;` \
       `void setup() {` \
       `pinMode(ledPin0, OUTPUT);` \
       `pinMode(ledPin1, OUTPUT);` \
       `pinMode(ledPin2, OUTPUT); }`\
       \
       `void loop() {` \
       `digitalWrite(ledPin0, 1);` \
       `digitalWrite(ledPin1, 1);` \
       `digitalWrite(ledPin2, 1);` \
       `delay(1000);` \
       `digitalWrite(ledPin0, 0);` \
       `digitalWrite(ledPin1, 0);` \
       `digitalWrite(ledPin2, 0);` \
       `delay(1000);` \
       `}`
   2. **\[Trabajo Previo]** Explicar que realiza el programa.&#x20;
   3. **\[Opción A]** Modificar el programa para que presente la siguiente secuencia de encendido de leds: 000, 001, 011, 111, 110, 100. La misma se debe repetir todo el tiempo en intervalos regulares de 1 segundo entre cada valor.&#x20;
   4. **\[Opción B]** Modificar el programa anterior para que por cada iteración de la secuencia, el tiempo entre cada valor se reduzca en 0,05 segundos. Una vez que llegue a 0 se debe volver a reiniciar a 1 segundo
3.  **Uso de Joystick**&#x20;

    1. Cargar el siguiente programa y ejecutarlo.&#x20;

    `const int ledPin0 = 4;` \
    `const int VRy = A0;` \
    `const int VRx = A1;` \
    `const int SW = 2;` \
    `void setup() {` \
    `Serial.begin(9600);` \
    `pinMode(ledPin0, OUTPUT);` \
    `pinMode(VRx, INPUT);` \
    `pinMode(VRy, INPUT);` \
    `pinMode(SW, INPUT_PULLUP);` \
    `}` \
    `void loop() {` \
    `int xPosition = analogRead(VRx);` \
    `int yPosition = analogRead(VRy);` \
    `int SW_state = digitalRead(SW);` \
    `int mapX = map(xPosition, 0, 1023, -512, 512);` \
    `int mapY = map(yPosition, 0, 1023, -512, 512);` \
    `Serial.println(mapX);` \
    `Serial.println(mapY);` \
    `Serial.println(SW_state);` \
    `digitalWrite(ledPin0, SW_state);` \
    `delay(10);` \
    `}`
4. **\[Trabajo Previo]** Explicar que realiza el programa.&#x20;
5. **\[Opción A]** Modificar el programa de forma que se enciendan los leds respetando el siguiente patron:&#x20;

| Joystick | Leds |
| -------- | ---- |
| ↑        | 010  |
| ↓        | 101  |
| ←        | 110  |
| →        | 011  |

\
El umbral de encendido debe ser sobre el 10% del recorrido del Joystick. En el caso de detectar una esquina, se deben colocar todos los leds en cero.&#x20;

6. **\[Opción B]** Modificar el programa de forma que los leds se enciendan gradualmente desde 000 a 111 indicando la posición del Joystick, tanto del centro hacia arriba como del centro hacia abajo.

4\. **Uso de Servo**&#x20;

1.  Cargar el siguiente programa y ejecutarlo.&#x20;

    `#include <Servo.h>` \
    `const int servoPin = 10;` \
    `Servo servo1;` \
    `void setup() {` \
    `servo1.attach(servoPin);` \
    `} void loop() {` \
    `servo1.write(0);` \
    `delay(1000);` \
    `servo1.write(30);` \
    `delay(1000);` \
    `servo1.write(60);` \
    `delay(1000);` \
    `servo1.write(90);` \
    `delay(1000);` \
    `servo1.write(180);` \
    `delay(1000);` \
    `}`&#x20;
2. **\[Trabajo Previo]** Explicar que realiza el programa.&#x20;
3. **\[Opción A]** Modificar el programa para que el Servo reproduzca el siguiente patrón de comportamiento una y otra vez, cambiando de posición cada 2 segundos. Tiempo Posición del Servo 1 0 grados 2 90 grados 3 45 grados 4 180 grados&#x20;

| Tiempo | Posición del Servo |
| ------ | ------------------ |
| 1      | 0 grados           |
| 2      | 90 grados          |
| 3      | 45 grados          |
| 4      | 180 grados         |

4. **\[Opción B]** Modificar el programa para que el movimiento de izquierda a derecha del Joystick, reproduzca el mismo comportamiento que el Servo de 0 a 180 grados.

5\. **Interrupciones**&#x20;

1.  Cargar el siguiente programa y ejecutarlo.

    `#include <Servo.h>` \
    `Servo servo1;` \
    `const int servoPin = 10;` \
    `const byte interruptPin = 2;` \
    `volatile byte button = 0;` \
    `const int ledPin0 = 4;` \
    `const int ledPin1 = 5;` \
    `const int VRy = A0;` \
    `const int VRx = A1;` \
    `const int SW = 2;` \
    `void setup() {` \
    `servo1.attach(servoPin);` \
    `pinMode(ledPin0, OUTPUT);` \
    `pinMode(ledPin1, OUTPUT);` \
    `pinMode(interruptPin, INPUT_PULLUP); attachInterrupt(digitalPinToInterrupt(interruptPin), click, RISING); pinMode(VRx, INPUT);` \
    `pinMode(VRy, INPUT);` \
    `pinMode(SW, INPUT_PULLUP);` \
    `}` \
    `void loop() {` \
    `int xPosition = analogRead(VRx);` \
    `int yPosition = analogRead(VRy);` \
    `int SW_state = digitalRead(SW);` \
    `int angulo1 = map(xPosition, 0, 1023, 0, 180);` \
    `servo1.write(angulo1);` \
    `int brillo = map(yPosition, 0, 1023, -255, 255);` \
    `analogWrite(ledPin1, abs(brillo));` \
    `if( button ) {` \
    `digitalWrite(ledPin0, 1);` \
    `} else {` \
    `digitalWrite(ledPin0, 0);` \
    `}` \
    `}` \
    `void click() {` \
    `if( button == 0 ) { button = 1; } else { button = 0; } }`
2. **\[Trabajo Previo]** Explicar que realiza el programa.&#x20;
3. **\[Opción A]** Modificar el programa para que cada vez que se presiona el botón del Joystick se prendan todos los leds y estos queden prendidos. Cuando se presione nuevamente, estos se deben apagar.&#x20;
4. **\[Opción B]** Modificar el programa para que cada vez que se presiona el botón del Joystick se intercambie el sentido de rotación del Servo.

6\. **Resumen**&#x20;

Utilizado lo aprendido en los puntos anteriores construir un programa que respete el siguiente comportamiento:&#x20;

* Los leds van a mostrar contando del 000 al 111 la posición del Joystick en sentido vertical.&#x20;
* El movimiento del Joystick en sentido horizontal deberá mover el Servo en todo su rango.&#x20;
* Si se presiona el botón del Joystick se intercambiará el comportamiento de los ejes vertical y horizontal.

### Referencia Arduino&#x20;

El proyecto Arduino consiste en una familia de placas para realizar proyectos simples de electrónica. Compuestas por un microcontrolador programable con una configuración mínima y una serie de pines que permiten establecer conexiones entre el microcontrolador y dispositivos externos, como sensores, actuadores o incluso displays.

#### Pin Out

<figure><img src="../.gitbook/assets/Captura de pantalla 2023-06-13 a la(s) 08.12.05.png" alt=""><figcaption></figcaption></figure>

La placa Arduino se conecta a la computadora por medio de un conector USB tipo A, por lo tanto se debe contar con tal puerto para poder programar la placa. Recuerden traer adaptadores en caso de ser necesario.

### Estructura&#x20;

La estructura de un programa para un Arduino consiste en dos funciones.&#x20;

* `setup():` Esta función es llamada al comienzo del programa, cuando inicia la placa y es ejecutada solo una sola vez. Se ocupa de inicializar variables, el modo de los pines, bibliotecas de funciones, etc.&#x20;
* `loop():` Luego de la función `setup()` se ejecuta la función loop. Esta función es ejecutada, como su nombre lo indica, es ejecutada una y otra vez en un ciclo infinito. Este ciclo permite al sistema Arduino tomar el control de forma activa entre cada iteración del ciclo.

### Funciones básicas

`digitalRead(pin):` Lee el estado de un pin digital. Este puede ser HIGH o LOW.

Parámetros

* pin: El número del pin digital a leer.

`digitalWrite(pin, value):` Escribe un valor HIGH o LOW en un pin digital seleccionado.

Parámetros

* pin:`El número de pin digital a escribir.`value:\` HIGH o LOW.

`pinMode(pin, mode):` Configura el comportamiento de un pin, ya sea como entrada o como salida.&#x20;

Parámetros

* pin: El número de pin a configurar.
* mode: INPUT, OUTPUT o INPUT PULLUP.

`analogRead(pin):` Lee el valor de un pin analógico. El conversor de analógico a digital es de 10 bits, por lo tanto, retorna valores entre 0 y 1023. La resolución es de 4.9 mV por unidad (5 volts / 1024 unidades). El conversor demora aproximadamente 100 microsegundos (0.0001 segundos) en convertir la magnitud analógica en un valor digital, pudiendo llegar a un máximo de 10000 lecturas por segundo.&#x20;

Parámetros

* pin: El número del pin analógico a leer.

`analogWrite(pin, value):` Escribe un valor analógico en el pin como una onda PWM (Modulación por ancho de pulsos). La frecuencia de la onda es de 490 Hz o 980 Hz, dependiendo del pin que se esté utilizando. Esta característica puede ser utilizada para variar la intensidad de un LED o la velocidad de un motor de continua.&#x20;

Parámetros

* pin: Número de pin donde escribir.
* value: Valor del duty cycle: entre 0 (siempre apagado) y 255 (siempre encendido).

`map(value, fromLow, fromHigh, toLow, toHigh):` Remapea un número entero desde un rango a otro rango. Esto quiere decir que mapea la magnitud fromLow a toLow y fromHigh a toHigh, junto con todos los valores intermedios. Esta función opera en enteros, resultando truncados los valores fraccionarios en la operación. La función permite operar tanto con rangos negativos como con rangos ascendentes o descendentes.&#x20;

Parámetros

* value: El número a mapear.
* fromLow: El límite inferior del valor actual.
* fromHigh: El límite superior del valor actual.
* toLow: El límite inferior del valor destino.
* toHigh: El límite superior del valor destino.

`delay(ms):` Detiene el programa durante un tiempo especificado en milisegundos (1000 milisegundos = 1 segundo). \`Parámetros

* ms: Cantidad de milisegundos de pausa.

### Funciones de Comunicación&#x20;

`Serial.begin(speed)` Inicializa la comunicación serial, configurando la cantidad de bits por segundo que debe enviar. Por default envia 8 bits, sin bit de paridad y sin bit de stop.&#x20;

Parámetros

* `speed`: cantidad de bits por segundo (baudios).&#x20;
*   `Serial.print(val)` Imprime en el canal serial el dato pasado por parámetro.&#x20;

    Parámetros

    * `val`: Dato a imprimir, puede ser tanto un número entero, en punto flotante o una string.

### Interrupciones

Las interrupciones son utilizadas en el sistema Arduino para el control de múltiples dispositivos y temporizadores. Parte de esta lógica puede ser delegada al desarrollador por medio de asociar rutinas a interrupciones. Las interrupciones son disparadas por el cambio de estado en pines especíificos de la placa.&#x20;

`attachInterrupt(interrupt, ISR, mode):` Asocia una función a una interrupción que responde al cambio de estado en un pin específico. La placa puede escuchar interrupciones sobre los pines 2, 3, 18, 19, 20 y 21. Para traducir el número de pin al número de interrupción se usa el resultado de la función `digitalPinToInterrupt(pin)` como primer parámetro para attachInterrupt.&#x20;

Parámetros

* interrupt: Número de interrupción (int)
* ISR: La función o rutina de atención de interrupciones que se ejecutará cuando se genere la interrupci´on. No toma ning´un par´ametro ni retorna ning´un resultado.
* mode: Define cuando la interrupci´on debe ser generada. Los modos validos son:
* LOW: Cuando el pin está en estado bajo.
* CHANGE: Cuando el pin cambia de valor de bajo a alto o a la inversa.
* RISING: Cuando el pin cambia de estado bajo a estado alto.
* FALLING: Cuando el pin cambia de estado alto a estado bajo. Servo Los servos son dispositivos actuadores compuestos por un motor, una caja reductora, un potenciómetro y una placa de control. El motor puede moverse mediante la caja reductora a una posici´on determinada controlada por la placa de control y el potenciómetro. Gracias al potenciómetro el servo puede medir en que posición se encuentra, y mantener está posición mediante la placa de control que aplica la energía necesaria al motor.

<figure><img src="../.gitbook/assets/Captura de pantalla 2023-06-13 a la(s) 08.28.14.png" alt=""><figcaption></figcaption></figure>

* servo: Variable de tipo servo.
* pin: Número de pin al que asociar la variable servo. servo.write(angle) Escribe en una variable servo la nueva posición donde mover el servo. La posici´on corresponde a un angulo en grados de orientación donde moverse desde la posici´on anterior. Par´ametros
* servo: Variable de tipo servo.
* angle: Valor del angulo en grados para posicionar el servo. N´umero entre 0 y 180.

Los servos son controlados mediante una señal de pulsos, dependiendo del ancho del pulso, se controla su posición. Este control es generado por la biblioteca de funciones Servo.h.&#x20;

Las siguientes son las funciones básicas para utilizar está biblioteca.&#x20;

`servo.attach(pin):` Asocia una variable de tipo servo a un pin. Esta libreria está limitada para controlar servos solo sobre los pines 9 y 10.&#x20;

Parámetros

* servo: Variable de tipo servo.
* pin: Número de pin al que asociar la variable servo.&#x20;

`servo.write(angle):` Escribe en una variable servo la nueva posición donde mover el servo. La posición corresponde a un angulo en grados de orientación donde moverse desde la posición anterior.&#x20;

Parámetros

* servo: Variable de tipo servo.
* angle: Valor del angulo en grados para posicionar el servo. Número entre 0 y 180.

### Notas complementarias&#x20;

Detalle del conexionado interno del protoboard:

<figure><img src="../.gitbook/assets/Captura de pantalla 2023-06-13 a la(s) 08.37.29.png" alt=""><figcaption></figcaption></figure>

Tabla de colores de resistencias:

<figure><img src="../.gitbook/assets/Captura de pantalla 2023-06-13 a la(s) 08.38.19.png" alt=""><figcaption></figcaption></figure>

## Solución

### \[Trabajo Previo]

#### ¿Cuál es la diferencia entre un pin digital y un pin analógico?

Los pines digitales en Arduino son utilizados para leer o escribir señales digitales, lo que significa que solo pueden tomar dos valores distintos: "HIGH" (alto) o "LOW" (bajo). Estos pines son comúnmente utilizados para conectar y controlar dispositivos que trabajan con señales digitales, como LEDs, botones, etc. Cada pin digital en una placa Arduino puede funcionar como una entrada (para leer señales) o como una salida (para enviar señales).

Después, están los pines analógicos que son utilizados para leer señales analógicas, lo que significa que pueden tomar valores continuos en un rango específico. Estos pines son utilizados para leer sensores analógicos, como potenciómetros, sensores de temperatura, sensores de luz, etc. Los pines analógicos pueden tomar valores desde 0 hasta un valor máximo determinado por la resolución del conversor analógico-digital (ADC) de la placa, generalmente 10 bits en las placas más comunes.

#### ¿Qué hace la función digitalPinToInterrupt?&#x20;

La función `digitalPinToInterrupt()` es una función en Arduino que se utiliza para asignar un número de interrupción a un pin digital específico. Las interrupciones son eventos que pueden interrumpir la ejecución normal del programa cuando ocurre algún cambio en un pin específico. Cuando se produce una interrupción, el programa puede detener temporalmente lo que está haciendo y ejecutar una función especial llamada "rutina de interrupción"  que se asoció con ese pin.

La función `digitalPinToInterrupt()` toma como argumento el número del pin digital y devuelve el número de interrupción correspondiente. Es útil cuando se quiere utilizar una interrupción en un pin digital específico. Algunas placas Arduino tienen pines designados para admitir interrupciones, y `digitalPinToInterrupt()` proporciona la correspondencia entre los pines digitales y los números de interrupción asociados.

#### ¿Para que sirve la función map?

Se utiliza para convertir un valor de un rango a otro rango. Permite escalar o mapear un valor de entrada a un rango diferente de salida. La sintaxis es:

`map(valor, rangoEntradaMin, rangoEntradaMax, rangoSalidaMin, rangoSalidaMax);`

* `valor`: el valor que se desea mapear al nuevo rango.
* `rangoEntradaMin` y `rangoEntradaMax`: el rango de valores de entrada dentro del cual se encuentra el valor.
* `rangoSalidaMin` y `rangoSalidaMax`: el rango de valores de salida al que se desea mapear el valor.

Entonces `map()` toma el valor de entrada y lo convierte proporcionalmente al nuevo rango especificado. Por ejemplo, si quieres mapear un valor de entrada que está en el rango de 0 a 1023 (como el resultado de una lectura analógica) a un nuevo rango de 0 a 255 (como el rango de valores de un pin PWM), puedes usar `map()` de la siguiente manera:

`int valorEntrada = analogRead(A0);` \
`int valorMapeado = map(valorEntrada, 0, 1023, 0, 255);`

En este ejemplo, el valor de entrada se mapea del rango de 0 a 1023 al rango de 0 a 255. Si el valor de entrada es 512, la función `map()` convertirá ese valor a aproximadamente 127 en el nuevo rango.

Es útil cuando se necesita adaptar un valor de entrada a un rango específico requerido por un componente o dispositivo en particular. En general, se usa para mapear valores de sensores analógicos a un rango de salida deseado o para ajustar valores de entrada antes de enviarlos a un actuador.

#### ¿Para que sirve habilitar la conexión serial?

Habilitar la conexión serial permite establecer una comunicación bidireccional entre la placa Arduino y un dispositivo externo, como una computadora o un módulo Bluetooth. La conexión serial se basa en la comunicación serie, donde los datos se transmiten uno después del otro a través de un único canal de comunicación.

## Uso de leds

#### Explicar que realiza el programa.&#x20;

```arduino
const int ledPin0 = 4; // Acá se configuran los pines de los leds.
const int ledPin1 = 5; 
const int ledPin2 = 6; 
void setup() { 
pinMode(ledPin0, OUTPUT);// Se define que se van a usar para enviar señales (controlar leds)
pinMode(ledPin1, OUTPUT); 
pinMode(ledPin2, OUTPUT); }
void loop() { 
digitalWrite(ledPin0, 1); // Se prenden los tres pines (están en 1)
digitalWrite(ledPin1, 1); 
digitalWrite(ledPin2, 1); 
delay(1000); 
digitalWrite(ledPin0, 0); // Se apagan los tres pines (están en 0)
digitalWrite(ledPin1, 0); 
digitalWrite(ledPin2, 0); 
delay(1000); }
```

Este código enciende los leds conectados a los pines 4, 5 y 6 de la placa Arduino, espera 1 segundo y después los apaga.

### Opción A - Leds

```arduino
/* Modificar el programa para que presente la siguiente secuencia de encendido de leds: 000, 
001, 011, 111, 110, 100. La misma se debe repetir todo el tiempo en intervalos regulares de 1 
segundo entre cada valor. 
*/
const int ledPin0 = 4; 
const int ledPin1 = 5; 
const int ledPin2 = 6; 
void setup() { 
pinMode(ledPin0, OUTPUT); 
pinMode(ledPin1, OUTPUT); 
pinMode(ledPin2, OUTPUT); }

void loop() { 
// 000
digitalWrite(ledPin0, 0); 
digitalWrite(ledPin1, 0); 
digitalWrite(ledPin2, 0); 
delay(1000);
// 001
digitalWrite(ledPin0, 0); 
digitalWrite(ledPin1, 0); 
digitalWrite(ledPin2, 1); 
delay(1000); 
// 011
digitalWrite(ledPin0, 0); 
digitalWrite(ledPin1, 1); 
digitalWrite(ledPin2, 1); 
delay(1000); 
// 111
digitalWrite(ledPin0, 1); 
digitalWrite(ledPin1, 1); 
digitalWrite(ledPin2, 1); 
delay(1000); 
// 110
digitalWrite(ledPin0, 1);
digitalWrite(ledPin1, 1);
digitalWrite(ledPin2, 0);
delay(1000);

// 100
digitalWrite(ledPin0, 1); 
digitalWrite(ledPin1, 0); 
digitalWrite(ledPin2, 0); 
delay(1000); 
}
```

## Opción B - Leds

```arduino
/*
Modificar el programa anterior para que por cada iteración de la secuencia, 
el tiempo entre cada valor se reduzca en 0,05 segundos. Una vez que llegue a 
0 se debe volver a reiniciar a 1 segundo
*/
const int ledPin0 = 4;
const int ledPin1 = 5;
const int ledPin2 = 6;

void setup() {
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  int tiempo = 1000; 

  while (tiempo > 0) {
    digitalWrite(ledPin0, HIGH); // Dato: se puede poner 1 o high, simplemente simboliza que hay una señal
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    delay(tiempo);

    digitalWrite(ledPin0, LOW);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    delay(tiempo);

    tiempo = tiempo - 50;
      if (tiempo <= 0) {
      tiempo = 1000;
    }
  }
}
```

## Uso de Joystick

#### Explicar que hace el programa.

```arduino
const int ledPin0 = 4; // Asigna el pin 4 al led (es digital)
const int VRy = A0; // Asigna el pin A0 que es analógico
const int VRx = A1; 
const int SW = 2; 
void setup() { 
Serial.begin(9600); 
pinMode(ledPin0, OUTPUT); // Esto va a enviar señales
pinMode(VRx, INPUT); // Esto va a recibir señales
pinMode(VRy, INPUT); 
pinMode(SW, INPUT_PULLUP); 
} 
void loop() { 
int xPosition = analogRead(VRx); 
int yPosition = analogRead(VRy); 
int SW_state = digitalRead(SW); 
int mapX = map(xPosition, 0, 1023, -512, 512); // Convierte la posición 
int mapY = map(yPosition, 0, 1023, -512, 512); 
Serial.println(mapX); // Lo imprime en monitor serie 
Serial.println(mapY); 
Serial.println(SW_state); 
digitalWrite(ledPin0, SW_state); 
delay(10); 
}
```

Básicamente, se leen e interpretan las entradas del joystick y el estado de un botón. O sea, lee las posiciones X e Y del joystick, el estado del botón y los imprime en el monitor serie. También controla un LED en función del estado de ese botón. Entonces, muevo el joystick y pasan cosas.

## Opción A - Joystick

```arduino
/*
Modificar el programa de forma que se enciendan los leds respetando el siguiente patron: 
010 -> arriba
101 -> abajo
110 -> izquierda
011 -> derecha

El umbral de encendido debe ser del 10% del recorrido del joystick

*/
const int ledPin0 = 4;
const int ledPin1 = 5;
const int ledPin2 = 6;
const int VRy = A0;
const int VRx = A1;
const int SW = 2;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin0, OUTPUT);

  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);
}

void loop() {
  int xPosition = analogRead(VRx); // Lees analógicamente
  int yPosition = analogRead(VRy); // Aca tambien jaja
  int SW_state = digitalRead(SW); // Lees digital el botón. 
  int mapX = map(xPosition, 0, 1023, -512, 512);
  int mapY = map(yPosition, 0, 1023, -512, 512);
  
  Serial.println(mapX);
  Serial.println(mapY);
  Serial.println(SW_state);

  // Verificar los patrones de movimiento
  if (mapX < 51 && -51 < mapX && mapY >= 51) {  // Patrón: arriba (010) // 10% es 461
    digitalWrite(ledPin0, 0);
    digitalWrite(ledPin1, 1);
    digitalWrite(ledPin2, 0);
  } else if (mapX < 51 && -51 < mapX && mapY < -51) {  // Patrón: abajo (101)
    digitalWrite(ledPin0, 1);
    digitalWrite(ledPin1, 0);
    digitalWrite(ledPin2, 1);
  } else if (mapX <= -51 && mapY >= -51 && mapY <= 51) {  // Patrón: izquierda (110)
    digitalWrite(ledPin0, 1);
    digitalWrite(ledPin1, 1);
    digitalWrite(ledPin2, 0);
  } else if (mapX >= 51 && mapY >= -51 && mapY <= 51) {  // Patrón: derecha (011)
    digitalWrite(ledPin0, 0);
    digitalWrite(ledPin1, 1);
    digitalWrite(ledPin2, 1);
  }
  else {
    digitalWrite(ledPin0, 0);
    digitalWrite(ledPin1, 0);
    digitalWrite(ledPin2, 0);
  }
  
  
  delay(10);
}
/*
Se utilizan las variables mapX y mapY para almacenar las lecturas mapeadas 
de los sensores analógicos. Después, se verifica el estado de los botones y las 
lecturas mapeadas para determinar el patrón de movimiento. Si se encuentra una 
coincidencia con uno de los patrones especificados, se enciende el LED (ledPin0).
*/
```

## Uso de Servomotor

#### Explicar que realiza el programa.

```arduino
#include <Servo.h> 
const int servoPin = 10; // En qué pin está el servomotor
Servo servo1; 
void setup() { 
servo1.attach(servoPin); 
} void loop() { 
servo1.write(0); // Ángulo 0
delay(1000); 
servo1.write(30); // Ángulo 30 
delay(1000); 
servo1.write(60); // Ángulo 60 
delay(1000); 
servo1.write(90); // Ángulo 90
delay(1000); 
servo1.write(180); // Ángulo 180 
delay(1000); 
} 
```

El código mueve el servomotor conectado al pin 10 en diferentes ángulos (0, 30, 60, 90 y 180 grados) en un ciclo. Cada posición se mantiene durante un segundo antes de pasar a la siguiente posición. Esto permite controlar la posición del servomotor y crear movimientos específicos según los ángulos proporcionados.

## Opción A - Servomotor

```arduino
/*
Modificar el programa para que el Servo reproduzca el siguiente patrón de comportamiento 
una y otra vez, cambiando de posición cada 2 segundos. 1 0 grados 
2 90 grados 3 45 grados 4 180 grados 
*/
#include <Servo.h> 
const int servoPin = 10; 
Servo servo1; 
void setup() { 
servo1.attach(servoPin); 
} 
void loop() { 
servo1.write(0); 
delay(2000); 
servo1.write(90); 
delay(2000); 
servo1.write(45); 
delay(2000); 
servo1.write(180); 
delay(2000); 
} 
```

## Opción B - Servomotor

```arduino
/*
Modificar el programa para que el movimiento de izquierda a derecha del Joystick, 
reproduzca el mismo comportamiento que el Servo de 0 a 180 grados.
*/
#include <Servo.h>

const int VRx = A1;
const int servoPin = 10;
Servo servo1;

void setup() {
  servo1.attach(servoPin);
}

void loop() {
  int xPosition = analogRead(VRx);
  int mapX = map(xPosition, 0, 1023, 0, 180);
  servo1.write(mapX);
  delay(10);
}
```

## Interrupciones

#### Explicar qué hace este programa.

```arduino
#include <Servo.h> 
Servo servo1; 
const int servoPin = 10; // Define el pin
const byte interruptPin = 2; 
volatile byte button = 0; 
const int ledPin0 = 4; 
const int ledPin1 = 5; 
const int VRy = A0; 
const int VRx = A1; 
const int SW = 2; 
void setup() { 
servo1.attach(servoPin); // Le digo que el servo está acá
pinMode(ledPin0, OUTPUT); // Esto envia señales
pinMode(ledPin1, OUTPUT); 
pinMode(interruptPin, INPUT_PULLUP); // Recibe señales
attachInterrupt(digitalPinToInterrupt(interruptPin), click, RISING); pinMode(VRx, INPUT); 
pinMode(VRy, INPUT); 
pinMode(SW, INPUT_PULLUP); 
} 
void loop() { 
int xPosition = analogRead(VRx); // Se guarda en variables lo que se lee
int yPosition = analogRead(VRy); 
int SW_state = digitalRead(SW); 
int angulo1 = map(xPosition, 0, 1023, 0, 180); // Mapea para convertir a ángulo 
servo1.write(angulo1); 
int brillo = map(yPosition, 0, 1023, -255, 255); // Mapea para convertir a brillo o intensidad
analogWrite(ledPin1, abs(brillo)); 
if( button ) { 
digitalWrite(ledPin0, 1); 
} else { 
digitalWrite(ledPin0, 0); 
} 
} 
void click() { 
if( button == 0 ) { button = 1; } else { button = 0; } 
}
```

Utiliza las lecturas del joystick para controlar la posición de un servomotor y el brillo de un LED. Además, utiliza un botón para cambiar el estado de una variable que controla el **encendido/apagado** de otro LED. La posición del joystick se mapea a un ángulo y se utiliza para mover el servomotor, mientras que el valor del eje Y del joystick se mapea a un brillo y se aplica a un LED.&#x20;

## Opción A - Interrupciones

```arduino
/*
Modificar el programa para que cada vez que se presiona el botón del Joystick se prendan todos los leds y estos queden prendidos. Cuando se presione nuevamente, estos se deben apagar. 
*/
#include <Servo.h>
Servo servo1;
const int servoPin = 10;
const byte interruptPin = 2;
volatile byte button = 0;
const int ledPin0 = 4;
const int ledPin1 = 5;
const int ledPin2 = 6;
const int VRy = A0;
const int VRx = A1;
const int SW = 2;
int time_stamp = 0; // Usamos time_stamp para solucionar el problema con las interrupciones

void setup() {
  servo1.attach(servoPin);
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), click, RISING);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);
  
}

void loop() {
  int xPosition = analogRead(VRx);
  int yPosition = analogRead(VRy);
  int SW_state = digitalRead(SW);
  int angulo1 = map(xPosition, 0, 1023, 0, 180);
  servo1.write(angulo1);
  int brillo = map(yPosition, 0, 1023, -255, 255);
  analogWrite(ledPin1, abs(brillo));
  
  if (button) {
    digitalWrite(ledPin0, HIGH);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    time_stamp = 250;
  } else{
    digitalWrite(ledPin0, LOW);
    //digitalWrite(ledPin1, LOW); Como se juega con el brillo de este pin, lo dejamos relacionado al estado que tenga
    digitalWrite(ledPin2, LOW);
    time_stamp = 250;
  }
  if (time_stamp > 0){
    time_stamp = time_stamp - 1;
  }
  delay(2);
}

void click() {
  if(time_stamp == 0){
if (button == 0) {
    button = 1;
  } else {
    button = 0;
  } 
  }
}
```

## Resumen

```arduino
/*
Utilizado lo aprendido en los puntos anteriores construir un programa que respete el siguiente
comportamiento:

Los leds van a mostrar contando del 000 al 111 la posici´on del Joystick en sentido vertical.

El movimiento del Joystick en sentido horizontal deber´a mover el Servo en todo su rango.

Si se presiona el botón del Joystick se intercambiar´a el comportamiento de los ejes vertical y
horizontal.

*/
#include <Servo.h>

Servo servo1;
const int servoPin = 10;
const byte interruptPin = 2;
volatile byte button = 0;
const int ledPin0 = 4;
const int ledPin1 = 5;
const int ledPin2 = 6;
const int VRy = A0;
const int VRx = A1;
const int SW = 2;
int time_stamp = 0;

void setup() {
  servo1.attach(servoPin);
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), click, RISING);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);

  // Estado inicial: LEDs verticales, servomotor horizontal
  int horizontal = 90;  // Posición horizontal media para el servomotor
  int vertical = 0;    // Valor inicial para los LEDs verticales
  servo1.write(horizontal);
  digitalWrite(ledPin0, (vertical & 1));
  digitalWrite(ledPin1, (vertical & 2));
  digitalWrite(ledPin2, (vertical & 4));
}

void loop() {
  int xPosition = analogRead(VRx);
  int yPosition = analogRead(VRy);
  int horizontal, vertical;

  if (button) {
    horizontal = map(yPosition, 0, 1023, 0, 180);
    vertical = map(xPosition, 0, 1023, 0, 7);
  } else {
    horizontal = map(xPosition, 0, 1023, 0, 180);
    vertical = map(yPosition, 0, 1023, 0, 7);
  }

  servo1.write(horizontal);

  digitalWrite(ledPin0, (vertical & 1));
  digitalWrite(ledPin1, (vertical & 2));
  digitalWrite(ledPin2, (vertical & 4));

  if (time_stamp > 0) {
    time_stamp = time_stamp - 1;
  }

  delay(2);
}

void click() {
  if (time_stamp == 0) {
    if (button == 0) {
      button = 1;
    } else {
      button = 0;
    }
  }
}

```

## Repositorio

{% embed url="https://github.com/luzalbaposse/Entrada-Salida-Arduino" %}

