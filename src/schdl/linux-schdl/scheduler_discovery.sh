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