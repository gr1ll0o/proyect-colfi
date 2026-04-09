# 💡 Proyecto Li-Fi con Arduino

![Proyecto Li-Fi|100](/assets/banner.png "Logo Li-Fi")

Este proyecto busca demostrar un **sistema básico de comunicación Li-Fi** (Light Fidelity) utilizando dos placas Arduino. La transmisión de datos se realiza mediante la modulación de la luz de un LED, mientras que la recepción se lleva a cabo con un fototransistor. Este proyecto a pequeña escala pretende servir como ejemplo y referencia a posibles avances con respecto a esta tecnología.

El sistema consiste en:
- Un Arduino transmisor que envía información encendiendo y apagando un LED en una secuencia específica (código binario).
- Un Arduino receptor que detecta los cambios de luz usando un fototransistor y reconstruye la señal recibida.

Este proyecto fue desarrollado como parte de una feria de ciencias, con el objetivo de demostrar cómo la luz visible puede utilizarse como medio de comunicación.
## ⚙️ Componentes necesarios
- Transmisor.
- 2x Arduino (UNO, Nano, etc.).
- 1x LED.
- 1x Resistencia (220Ω–330Ω).
- Cables.
- 1x Fototransistor.
- 1x Resistencia (10kΩ recomendada).
## 🔌 Esquema básico
- #### Transmisor 
  LED conectado a un pin analógico del Arduino.
- #### Receptor
  Fototransistor (lectura de la intensidad de luz del led)

## 🚀 Funcionamiento
El Arduino transmisor convierte datos en una secuencia binaria (1s y 0s)
y la reproduce en el LED secuencialmente variando su intensidad según corresponda. Si el LED está prendido al 100%, está enviando 1. Si el led
está prendido al 25-30%, está enviando 0. Si está totalmente apagado está
enviando una pausa o apagado.

El Arduino receptor esperará señales de este transmisor y las decodificará
en texto legible, tomando las pausas necesarias para leer el mensaje enviado
por el transmisor. Mostrará finalmente el texto enviado.

## 💻 Código
El repositorio incluye:

`emisor.ino` → Código del Arduino transmisor\
`receptor.ino` → Código del Arduino receptor

## 📊 ¿Qué se puede mejorar?
Buscamos incentivar este concepto e idea a través de una simulación
a baja escala, para esto, se construye el proyecto con la intención de
abrir paso a:
- Aumentar la velocidad de transmisión
- Implementar corrección de errores
- Usar modulaciones más avanzadas
- Filtrar ruido de luz ambiente
- Transmitir textos extensos y/o datos de programa

## 🌟 Aplicaciones del Li-Fi
- Comunicación inalámbrica en entornos donde el Wi-Fi no es viable
- Redes seguras (la luz no atraviesa paredes)
- Internet de alta velocidad mediante iluminación LED

## 👨‍🔬 Autores

Proyecto realizado por:\
[Thiago Grillo](https://github.com/gr1ll0o),
[Ciro Lopez](https://markdownlivepreview.com/),
[Lucas Marin](https://github.com/M4rr1nn),
[Valentino Russo](https://github.com/Rusko33), y [Yago Sayas](https://github.com/yagosayas123).

Para la "Feria de Educación, Artes, Ciencias y Tecnología 2026".

Estudiantes de la E. T. N35 "Ing. Eduardo Latzina" (CABA, Argentina).
