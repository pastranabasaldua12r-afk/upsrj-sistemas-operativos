# instala linux-source para poder ver el codigo fuente del kernel
sudo apt install linux-source

# se mueve a la carpeta donde se guardan los archivos del kernel
cd /usr/src

# muestra los archivos que hay en esta ruta
ls

# entra al directorio del linux source del kernel
cd linux-source-5.15.0

# descomprime el archivo del kernel
sudo tar -xjf linux-source-5.15.0.tar.bz2

# entra al directorio donde se descomprimio el kernel
cd linux-source-5.15.0

# muestra lo que hay dentro del directorio
ls

# entra a la carpeta del kernel
cd kernel

# muestra el contenido del directorio kernel
ls

# entra al directorio donde se encuentra el archivo fair.c
cd sched

# muestra los archivos del directorio sched
ls

# visualiza el contenido del archivo fair.c
cat fair.c

## Pregunta de reflexión (obligatoria)

Responder dentro del script como comentario:

> ¿Por qué Linux no implementa directamente FCFS, SJF o RR como se ven en los libros?
# Porque estos algoritmos se presentan de forma teórica para facilitar la comprensión
# de los conceptos básicos de planificación.
# En la práctica, un sistema operativo debe administrar muchos procesos al mismo tiempo,
# con comportamientos y prioridades distintas.
# Por esta razón, Linux utiliza un planificador más avanzado y flexible, capaz de
# adaptarse a diferentes situaciones y distribuir el tiempo del CPU de manera más eficiente y justa.