# 💡 Proyecto Col-Fi

![Proyecto Col-Fi|100](/assets/banner.png "Logo Col-Fi")

Este proyecto busca demostrar un **sistema básico de comunicación Col-Fi** (Color Fidelity) utilizando dos placas Arduino. La transmisión de datos se realiza mediante los colores de un LED RGB, mientras que la recepción se lleva a cabo con un sensor de luz y color. Este proyecto a pequeña escala pretende servir como ejemplo y referencia a posibles avances con respecto a esta tecnología que hermana el concepto de Li-Fi.

El sistema consiste en:
- Un Arduino transmisor que envía información encendiendo y apagando dos LEDs en una secuencia específica de colores (código binario).
- Un Arduino receptor que detecta los cambios de luz usando un fototransistor y reconstruye la señal recibida.

Este proyecto fue desarrollado como parte de una feria de ciencias, con el objetivo de demostrar cómo la luz visible puede utilizarse como medio de comunicación.
## ⚙️ Componentes necesarios
- Transmisor.
- 2x Arduino (UNO, Nano, etc.).
- 1x LED RGB. / 3x LEDs
- 1x Resistencia (220Ω–330Ω).
- Cables.
- 3x Fotorresistencias.
- 1x Resistencia (10kΩ recomendada).

## 🚀 Funcionamiento
Para comprender el funcionamiento del concepto Col-Fi, véase la bibliografía del proyecto, disponible
en el directorio "doc" y en el **apartado "Bibliografía" debajo.**

## 💻 Código
El repositorio incluye:

`emisor.ino` → Código del Arduino transmisor\
`receptor.ino` → Código del Arduino receptor

Tambien se incluye la [página web del proyecto](https://col-fi.netlify.app/).
La carpeta `photos` contiene registros de nuestro trabajo. En `docs` se puede encontrar
toda la documentacion del proyecto (teorias, material, desarrollo, entre otros).

## 📊 ¿Qué se puede mejorar?
Buscamos incentivar este concepto e idea a través de una simulación
a baja escala, para esto, se construye el proyecto con la intención de
abrir paso a:
- Aumentar la velocidad de transmisión
- Implementar corrección de errores
- Usar modulaciones más avanzadas
- Filtrar ruido de luz ambiente
- Transmitir textos extensos y/o datos de programa

## 🌟 Aplicaciones del Li-Fi actualmente
- Comunicación inalámbrica en entornos donde el Wi-Fi no es viable
- Redes seguras (la luz no atraviesa paredes)
- Internet de alta velocidad mediante iluminación LED
Con el concepto "Col-Fi", buscamos crear un concepto que pueda complementar el funcionamiento y entendimiento
del Li-Fi hoy en día e incluso servir como alternativa a este y al Wi-Fi.

## 📚 Bibliografía
En este apartado se encuentra la documentación del proyecto, tanto teórica como práctica.

Recomendamos preferentemente mirar el [Drive oficial del proyecto.](https://drive.google.com/drive/folders/1M8bsisLBoXe9x6PtQzhPXleN-MD1DhaQ?usp=sharing)

- ["Tecnología Col-Fi con LEDs RGB" - Thiago Grillo](https://docs.google.com/document/d/173AnS3XXFvmV6eeRK5DUw5NHlWwti-Y3nihKtxYBDz8/edit?usp=sharing)
- ["Eficiencia" - Ciro Lopez](https://docs.google.com/document/d/1-Dihl-4YaM7QIMXAFMvgepBVzemDwMUJAeh4PGH9Aec/edit?usp=sharing)
- ["Filtro de Colores en Fotorresistores" - Lucas Marin](https://docs.google.com/document/d/1OwOuXwQXEYv3yIC2PsYxsM0OvnhcgxYVaa0rZ5TPpB4/edit?usp=sharing)
- ["Módulo conversor entre PDF y cadenas de bytes" - Thiago Grillo](https://docs.google.com/document/d/1fV5GKmVl1-d8AKbPXNDRjsVWpZwv2OXho6giDldE7og/edit?usp=sharing)


(Toda esta documentación puede ser descargada desde el directorio "doc" y en el Drive).
## 👨‍🔬 Autores

Proyecto realizado por:\
[Thiago Grillo](https://github.com/gr1ll0o),
[Ciro Lopez](https://markdownlivepreview.com/),
[Lucas Marin](https://github.com/M4rr1nn),
[Thiago Puga](https://github.com/thiagomanupuga-bit), y [Yago Sayas](https://github.com/yagosayas123).

Para la "Feria de Educación, Artes, Ciencias y Tecnología 2026".

Estudiantes de la E. T. N35 "Ing. Eduardo Latzina" (CABA, Argentina).
