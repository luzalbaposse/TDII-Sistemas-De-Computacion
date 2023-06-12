---
description: Pooling, interrupciones y DMA
---

# Sistema de Entrada/Salida

{% file src="../.gitbook/assets/T19_Sistemas_de_Entrada_Salida_handout.pdf" %}
Presentación - Clase de Sistemas de Entrada/Salida
{% endfile %}

## Hardware de E/S

Anteriormente estudiamos el hardware de e/s. A modo de **repaso**:

* Formas de acceder a dispositivos de E/S:
  * Mapeado de memoria
  * Puertos de E/S
* Estrategias de control:
  * Espera activa (_Polling_)
  * Interrupciones
  * Acceso Directo a Memoria (DMA)

## Formas de acceso a entrada/salida

Hay formas diferentes de acceder al espacio de memoria en los dispositivos.

### E/S mapeado a memoria

Los accesos a memoria son capturados y de estar en el rango de memoria de **los dispositivos**, **estos son los que responden**, tanto a escrituras como lecturas sobre memoria. Las direcciones a las que se accede son **direcciones físicas** que ignoran el mecanismo de paginación. Además, **la memoria cache no puede interferir** en estos accesos, siendo desactivada en el rango de E/S

### Puertos de E/S

Eciste un **espacio de direccionamiento independiente** para E/S. A este espacio se accede por un bus independiente. Suele tener una frecuencia más lenta que el bus de memoria y un rango de direcciones de menor tamaño.

Para controlar los dispositivos se cuenta con registros especiales que se clasifican como:

```
data-in register: se lee por el sistema para obtener datos
data-out register: el sistema lo escribe para enviar datos
control register: es escrito por el sistema para controlar al dispositivo
control register: es escrito por el sistema para controlar al dispositivo
```

### Interrupciones

El mecanismo de interrupciones cuenta con **rutinas que son ejecutadas cuando se presenta una interrupción.**

Las rutinas pueden atender a múltiples dispositivos o a uno solo, además son atendidas según su prioridad. Incluso, pueden estar enmascaradas impidiendo que puedan interrumpir la ejecución de otra rutina.

Desde el punto de vista del sistema operativo se suele utilizar el siguiente protocolo:

1. El sistema mediante el driver, configura al dispositivo para realizar una operación de E/S
2. El dispositivo inicia la acción y en algún momento cuando termina, genera una interrupción.
3. La interrupción es atendida por el procesador, este recibe o genera la información del dispositivo y continua la ejecución del proceso interrumpido.

En algún momento, cuadno caeuna interrupción, lo que va a pasar es que el driver del dispositivo inicializa una acción de E/S, lo que va a quedar configurado (atacheado) el driver con el dispositivo. En arduino lo vamos a ver como un **attach, basicamente le decimos esta instrucción correla cuando caiga esta interrupción.** O sea, dispara una rutina que attacheamos. Cuando cae efectivamente en interrupción, se recibe y se transfiere el control del código que haya que correr dirctamente a la CPU. Después, va a retornar el proceso que estaba corriendo al Sistema Operativo.&#x20;

En arduino no es tan así, sino que le vuelve el control a lo que estaba corriendo (porque no hay sistema operativo). La maquinaria de arduino de lo **único** que se encarga es de guardar el contexto para después seguir corriendolo.

Lo que pasa en un sistema operativo es que al caer la interrupcion, detenes el proceso, se gaurda en el PC y cuando termina la interrupción, el Sistema operativo puede decidir si pone a correr lo que estaba corriendo o pone a correr otro, lo que sea.&#x20;

En arduino no hay Process Control Block, guardamos todo el estado en un lugar y después una función recupera el estado que estaba corriendo.

### Acceso Directo a Memoria

**For dummies:** Los dispositivos van a tener un buffer, lo que vamos a querer hacer es moverlo a memoria principal desde el dispositivo o viceversa.

La idea es que ese dispositivo lo configuremos, con registros, y lo único que se encarga de hacer es copiar la memoria de un lugar a otro.

Los mecanismos de DMA o E/S PIO (Programada) se ocupan de tomar el control del bus de memoria y realizar las tareas de transferencia de datos que realizaría el procesador.&#x20;

Para esto se debe contar con un buffer en memoria física que utilizará el sistema para dejar los datos que el DMA requiera.

El sistema cuenta con multiples dispositivos DMA, debe coordinar su uso, prioriando las tareas de transferencias de datos a realizar.

1. El sistema selecciona una tarea de transferencia en la cola de espera del dispositivo DMA.
2. Configura los registros de control y configuración del DMA.
3. Queda a la espera de la interrupción de finalización para cargar una nueva tarea de transferencia.

<mark style="background-color:green;">En procesadores modernos, por un lado está el CPU con su controlador de memoria, tienen otro puesto para conectar los dipositivos de tipo DMA, porque sino no pueden hacer caminos directos.</mark>&#x20;

### Tipos de dispositivos de E/S

Hay varios tipos de dispositivos que dependen de una clasificación. Vamos a verlos:

<table data-view="cards"><thead><tr><th></th><th></th><th></th></tr></thead><tbody><tr><td><mark style="background-color:purple;"><strong>Modo de transferencia de datos</strong></mark></td><td>Flujo de caracteres: transfiere de a bytes</td><td>Flujo de bloques: transfiere a bloques de bytes</td></tr><tr><td><mark style="background-color:purple;"><strong>Método de acceso</strong></mark></td><td>Acceso secuencial: acceso es determinado por el dispositivo</td><td>Acceso aleatorio: acceso es determinado por el usuario del dispositivo</td></tr><tr><td><mark style="background-color:purple;"><strong>Forma de transferencia</strong></mark></td><td>Síncrona: el tiempo de respuesta es predecible</td><td>Asíncrona: el tiempo de respuesta es aleatorio</td></tr><tr><td><mark style="background-color:purple;"><strong>Compartición</strong></mark></td><td>Compartible: varios procesos lo pueden usar concurrentemente</td><td>Dedicado: solo un proceso a la vez</td></tr><tr><td><mark style="background-color:purple;"><strong>Velocidad</strong></mark></td><td>Latencia, tiempo de búsqueda, tasa de transferencia, etc.</td><td></td></tr><tr><td><mark style="background-color:purple;"><strong>Tipo de operación</strong></mark></td><td>Solo lectura<br>Solo escritura<br>Lectura-escritura</td><td></td></tr></tbody></table>

### Subsistema de E/S

Cada proceso debe poder comunicarse con los dispositivos que necesita a través del sistema. Para esto, se provee una interfaz que permite abstraer el acceso a los dispositivos en comandos simples, mientras **oculta el funcionamiento interno** de cada dipositivo.

Hay 5 capas, vamos a ver cada una:

* **Capa 0**: Hardware
*   **Capa 1:** Manejador de interrupciones y rutinas

    Por medio de un conjunto de rutinas básicas, el OS puede atender interrupciones y dar el control a las capas superiores. Además utiliza rutinas especiales, que permiten acceder al **espacio de memoria de los dispositivos**. \
    El sistema cuenta con todo tipo de rutinas para atender dispositivos, desde **rutinas genéricas** para dispositivos, donde solo se provee una interfaz para acceder a memoria, hasta complejas rutinas para tender dispositivos específicos.\
    <mark style="background-color:green;">El desarrollo de esta capa es fundamental para construir drivers de dispositivo eficientes.</mark>
* **Capa 2:** Controladores de dispositivos.\
  El funcionamiento de cada dispositivo depende del fabricante. Este implementa un **protocolo de comunicación particular.** Para esto, los fabricantes proveen drivers específicos para cada dispositivo y sistema donde serán utilizados.\
  <mark style="background-color:green;">La interfaz de la capa anterior es utilizada por los drivers para acceder directamente al hardware.</mark> \
  Por esta razón, muchas veces los sistemas no implementan las interfaces que necesitan los drivers, y por lo tanto son incompatibles con el sistema. Otras veces, los fabricantes directamente no dan soporte para algunos sistemas operativos.\
  Los drivers deben ser rutinas **reentrantes**, es decir que deben poder recibir una nueva solicitud mientras están ejecutando otra.
* **Capa 3:** Subsistema de E/S independiente del dispositivo. \
  Publica una interfaz uniforme para acceder a los dispositivos. Los _drivers_ se deben adaptar y exponer la interfaz que el sistema propone. De esta forma todos los dispositivos de comportamiento similar, son utilizados por los usuarios de la misma forma. \
  Además se ocupa de la **Planificación de E/S**. Determiando el orden en que se atenderán las solicitudes y respetando las prioridades entre los diferentes dispositivos. \
  Esta capa también se ocupa de resolver las operaciones comunes a todos los dispositivos.\
  Algunas operaciones comunes son:
  * **Administración de búferes:** los datos a transferir se almacenan temporalmente en memoria, permitiendo adaptar los tamaños de transferencia entre dispositivos y sistema.
  * **Administración de errores:** los errores son capturados por el sistema como resultado de una operación de E/S. Existen errores que pueden dejar al sistyema en un estado inconsistente que debe ser administrado correctamente para evitar la perdida de datos.
  * **Asignación y liberación de dispositivos dedicados:** el sistema debe aceptar y rechazar soliciudes de uso de uso de dispositivos teniendo en cuenta las carecterísticas de uso de cada uno. Evitando en todo momento generar _deadlocks_ por condiciones de sincronización.
* **Capa 4:** Software de E/S en la capa de usuario.\
  Esta capa está formada por el conjunto de **bibliotecas de funciones que resuelven el acceso a E/S:**\
  Proporcionan comandos o funciones que nos permiten utilizar los recursos que proveen los dispositivos de forma más simple. \
  Por ejemplo, printf llama internamente a syscalls como write cuando se debe imprimir un texto largo o put cuando es un solo caracter.

### Relojes

Los relojes son un tipo específico de dispositivos de e/s. Su interfaz de hardware se ocupa de **generar eventos en intervalos regulares de tiempo**. Estos eventos se suelen traducir en interrupciones o dejan registro en contadores.&#x20;

Los sistemas cuentan con múltiples relojes que operan a distintas frecuencias.

El sistema distingue entre distintas fuentes de tiempo:

* Temporizador de tiempo real (_real-time-clock, RTCI)_
* Temporizador de eventos de alta precisión (_high precision event timer, HPET_)

La interfaz del reloj provee tres funciones básicas:

* Obtener el tiempo actual
* Obtener el tiempo transcurrido desde el último evento
* Configurar el reloj para despertar la operación X en el momento T

Internamente el sistema requiere múltiples relojes, para resolver esto, se crean relojes virtuales. Los relojes virtuales se actualizan o cambian su estado en función de los relojes físicos.

### Administración de energía

El sistema operativo juega un rol fundamental en la administración de la energía.

Ya sea que se cuente con una bateria como fuente de alimentación o se esté conectado a la red eléctrica. La reducción del consumo de energía es un eje básico de diseño.

Los sistemas están diseñados para disipar una determinada cantidad de energía que se manifiesta en **calor.** Este calor debe ser reducido mediante sistemas de enfriamiento como _coolers_.

**Advanced Configuration and Power Interface(ACPI):** Provee un estandar para que el sistemas operativo pueda descubrir y configurar los componentes de ´ hardware del sistema y administrar el consumo de energ´ıa. Permite monitorar el uso del los componentes, su estado, y mecanismos de Plug and Play y hot swapping. El sistema operativo se encarga de decidir cuando encender o apagar componentes, o incluso degradar su funcionamiento para reducir el consumo. Esta tarea es muy compleja ya que para reducir el consumo se debe afectar la experiencia de usuario.

{% hint style="info" %}
Lo más importante es **clasificación** de **dispositivos**, las **diferentes** **capas** y **conceptos** **generales**.&#x20;
{% endhint %}
