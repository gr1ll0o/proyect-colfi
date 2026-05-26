/*  
Este archivo maneja todo lo que es interactivo
al final de todo se incluye un texto que explica como funciona cada una de las animaciones
*/


/*ORDEN DE LAS SECCIONES
   Esta lista define el orden en que aparecen las secciones
   cuando navegas con las flechas del teclado.
   Si hay que agregar o reordenar, se cambia aca.*/
const secciones = ['inicio', 'info', 'sistema', 'archivos', 'fotos', 'equipo'];

// Esta variable guarda en que seccion esta el usuario
let seccionActual = 0;


/*FUNCION: irA(nombreSeccion)
   
   Funcion principal para cambiar de seccion.
   Recibe el ID de la seccion a donde queremos ir.
 
   1. Saca la clase "activa" de la seccion actual
   2. Saca la clase "activo" del boton de nav actual
   3. Busca la nueva seccion y le pone "activa"
   4. Busca el boton que corresponde y le pone "activo"
   5. Actualiza la variable seccionActual*/
function irA(nombreSeccion) {
    // Agarra todos los elementos necesarios
    const todasLasSecciones = document.querySelectorAll('.seccion');
    const todosLosBotones   = document.querySelectorAll('.nav-boton');

    // Saca la clase activa de todo (limpio el estado anterior)
    todasLasSecciones.forEach(s => s.classList.remove('activa'));
    todosLosBotones.forEach(b => b.classList.remove('activo'));

    // Pongo activa la seccion q corresponjde
    const nuevaSeccion = document.getElementById(nombreSeccion);
    if (nuevaSeccion) {
        nuevaSeccion.classList.add('activa');
    }

    // Pone activo el boton de la nav que corresponde
    const botonCorrespondiente = document.querySelector(`[data-seccion="${nombreSeccion}"]`);
    if (botonCorrespondiente) {
        botonCorrespondiente.classList.add('activo');
    }

    // Actualizo la variable para saber donde estamos
    seccionActual = secciones.indexOf(nombreSeccion);
}


/*NAVEGACION CON TECLADO
   
   Cuando el usuario aprieta una tecla, revisamos si es
   una flecha. Si es flecha arriba o izquierda, vamos
   a la seccion anterior. Si es flecha abajo o derecha,
   vamos a la siguiente.
   
   Math.max y Math.min los usamos para no salir del rango
   (no ir antes del inicio ni despues del final).*/
document.addEventListener('keydown', function(evento) {

    // Flecha derecha o flecha abajo → seccion siguiente
    if (evento.key === 'ArrowRight' || evento.key === 'ArrowDown') {
        const siguiente = Math.min(seccionActual + 1, secciones.length - 1);
        irA(secciones[siguiente]);
    }

    // Flecha izquierda o flecha arriba → seccion anterior
    if (evento.key === 'ArrowLeft' || evento.key === 'ArrowUp') {
        const anterior = Math.max(seccionActual - 1, 0);
        irA(secciones[anterior]);
    }
});


/*LOS BOTONES DE LA NAV LATERAL
   
   Cada boton tiene un atributo data-seccion con el ID
   de la seccion a donde tiene que ir.
   Buscamos todos los botones y les agregamos un click.*/
document.querySelectorAll('.nav-boton').forEach(function(boton) {
    boton.addEventListener('click', function() {
        const destino = boton.getAttribute('data-seccion');
        irA(destino);
    });
});


/* CARRUSEL DE FOTOS
   
   - Hay varias fotos en el HTML, todas con clase .foto-carrusel
   - Solo una a la vez tiene la clase .foto-visible (que la hace opaca)
   - Cuando el usuario aprieta "next" o "prev", cambiamos cual tiene esa clase
   
   Primero filtramos las fotos que si cargaron bien
   (las que tienen display != 'none', es decir, las que no fallaron).*/

// Indice de la foto que estamos viendo ahora
let fotoActual = 0;

// Cuando carga la pagina, inicializamos el carrusel
window.addEventListener('load', function() {
    iniciarCarrusel();
});

function iniciarCarrusel() {
    // Agarramos todas las fotos del HTML
    const todasLasFotos = document.querySelectorAll('.foto-carrusel');

    // Filtramos solo las que se cargaron bien (las que no tienen display:none)
    // Nota: el onerror en el HTML pone display:none en las que fallan
    const fotosDisponibles = Array.from(todasLasFotos).filter(function(foto) {
        return foto.style.display !== 'none';
    });

    // Si no hay ninguna foto disponible, mostramos el mensaje de "sin imagen"
    if (fotosDisponibles.length === 0) {
        const mensajeVacio = document.getElementById('carrusel-vacio');
        if (mensajeVacio) {
            mensajeVacio.style.display = 'flex';
        }
        return;
    }

    // Mostramos la primera foto
    mostrarFoto(0);

    // Creamos los puntitos de navegacion (uno por cada foto disponible)
    crearPuntitos(fotosDisponibles.length);
}


/*FUNCION: mostrarFoto(numero)
   
   Muestra la foto en la posicion indicada.
   Saca la clase .foto-visible de todas las fotos
   y se la pone solo a la que queremos ver.*/
function mostrarFoto(numero) {
    const todasLasFotos = document.querySelectorAll('.foto-carrusel');

    // Filtramos de vuelta las que estan disponibles
    const fotosDisponibles = Array.from(todasLasFotos).filter(function(foto) {
        return foto.style.display !== 'none';
    });

    // Si el numero esta fuera de rango, no hacemos nada
    if (numero < 0 || numero >= fotosDisponibles.length) return;

    // Sacamos la clase visible de todas
    fotosDisponibles.forEach(function(foto) {
        foto.classList.remove('foto-visible');
    });

    // Se la ponemos solo a la que queremos
    fotosDisponibles[numero].classList.add('foto-visible');

    // Actualizamos la variable global
    fotoActual = numero;

    // Actualizamos los puntitos para que el activo sea el correcto
    actualizarPuntitos(numero);
}


/*FUNCION: moverCarrusel(direccion)
   
   Esta es la que llaman los botones "prev" y "next"
   Recibe 1 para ir hacia adelante o -1 para ir hacia atras.
   Calcula la foto siguiente y llama a mostrarFoto().
   
   Con el % (modulo) hacemos que sea circular*/
function moverCarrusel(direccion) {
    const todasLasFotos = document.querySelectorAll('.foto-carrusel');
    const fotosDisponibles = Array.from(todasLasFotos).filter(function(foto) {
        return foto.style.display !== 'none';
    });

    if (fotosDisponibles.length === 0) return;

    // Calculamos la proxima foto con wrap-around (circular)
    const proximaFoto = (fotoActual + direccion + fotosDisponibles.length) % fotosDisponibles.length;
    mostrarFoto(proximaFoto);
}


/*FUNCION: crearPuntitos(cantidad)
   Crea los puntitos de navegacion abajo del carrusel.
   Un puntito por cada foto. Al hacer click en un puntito,
   va directamente a esa foto.*/

function crearPuntitos(cantidad) {
    const contenedorPuntitos = document.getElementById('carrusel-puntitos');
    if (!contenedorPuntitos) return;

    // Limpiamos por si habia algo antes
    contenedorPuntitos.innerHTML = '';

    // Creamos un puntito por cada foto
    for (let i = 0; i < cantidad; i++) {
        const puntito = document.createElement('div');
        puntito.classList.add('puntito');

        // El primero arranca activo
        if (i === 0) puntito.classList.add('activo');

        // Al hacer click, va a esa foto
        puntito.addEventListener('click', function() {
            mostrarFoto(i);
        });

        contenedorPuntitos.appendChild(puntito);
    }
}


/*  FUNCION: actualizarPuntitos(fotoActual)
   Cuando cambia la foto, actualiza cual puntito
   esta marcado como activo.*/
function actualizarPuntitos(indice) {
    const todosPuntitos = document.querySelectorAll('.puntito');

    // Sacamos la clase activo de todos
    todosPuntitos.forEach(function(p) {
        p.classList.remove('activo');
    });

    // Se la ponemos al que corresponde
    if (todosPuntitos[indice]) {
        todosPuntitos[indice].classList.add('activo');
    }
}
/*
   ANIMACION 1: Entrada de la seccion activa
   
   Cuando cambias de seccion, la nueva seccion "entra"
   desde la derecha con un fade + deslizamiento.
   
   CSS es el que hace esto
   - .seccion tiene: opacity:0 y transform:translateX(18px)
   - .seccion.activa tiene: opacity:1 y transform:translateX(0)
   - La transicion esta definida en la clase .seccion:
    transition: opacity 0.35s ease, transform 0.35s ease;
   
   Es decir, cuando el JS agrega la clase "activa",
   el CSS solito hace la animacion. No necesitamos JS para eso.

   ANIMACION 2: El puntito que parpadea en inicio
   
   Definida en estilos.css con @keyframes parpadeo-punto
   Se aplica al ::before del .barra-estado
   Va de opacity:1 a opacity:0.3 y vuelve, en loop.

   ANIMACION 3: El cursor parpadeante tipo terminal
   
   Definida en estilos.css con @keyframes parpadeo-cursor
   El elemento .cursor-parpadeante alterna entre visible
   e invisible cada 0.6 segundos.

   ANIMACION 4: El efecto glitch del logo "ColFi."
   
   Definida en estilos.css con @keyframes efecto-glitch
   La mayor parte del tiempo (88%) no pasa nada.
   Luego por unos pocos frames
   - Se mueve un poco (skew)
   - Aparecen sombras de texto en morado y amarillo

   ANIMACION 5: Hover en botones de nav y archivos
   
   Cuando pones el mouse encima de un boton o link,
   cambia el color y el fondo suavemente.
   Esto lo hace el CSS con "transition: color 0.2s, background 0.2s"
   en las clases .nav-boton:hover, .entrada-archivo:hover, etc.

   ANIMACION 6: La flechita → en los links de archivos
   
   Cuando haces hover en una .entrada-archivo,
   la flechita → se mueve 4px a la derecha.
   CSS: .entrada-archivo:hover .archivo-flecha { transform: translateX(4px) }
   con transition: transform 0.2s en .archivo-flecha

   ANIMACION 7: Fade del carrusel de fotos
   
   Cuando cambias de foto en el carrusel, la foto nueva
   aparece suavemente con un fade (opacidad de 0 a 1).
   CSS: .foto-carrusel tiene transition: opacity 0.4s ease
   El JS agrega/saca la clase "foto-visible" para activarlo.*/
