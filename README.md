# Project-106

# Introducción

Este es un proyecto para la asignatura de Ingeniería del Software en el Grado en Ingeniería Informática en la Universidad de Córdoba.

Consiste en un sistema de gestión de inscripciones para el servicio de cursos de extensión de la propia Universidad de Córdoba. Se trata de un prototipo con fin docente, no dispone de sistemas de seguridad, no introducir información personal y/o sensible.

# Instalacion

Es posible instalar la aplicación de varias formas:

- Instalador (actualmente solo para linux)
- Compilando manualmente con cmake

En ambos casos se debe clonar este repositorio (con git):

    git clone "https://github.com/naibu3/Project-106"

Además se requiere tener instalados los siguientes paquetes:

- cmake
- make

### Instalacion con instalador (solo linux)

Para instalar con el instalador basta con darle permisos de ejecución y ejecutarlo:

    chmod +x linux_install.sh
    ./linux_install.sh

Solo resta ejecutar el programa:

    ./gestor_cursos

### Instalación compilando manualmente

Una vez clonado se debe crear el directorio build dentro de la raíz del proyecto:

    mkdir build

A continuación, dentro de 'build/' ejecutaremos cmake y make:

    cd build
    cmake ..
    make

Es necesario incluir ciertos ficheros al directorio donde se encuentra el ejecutable, pueden copiarse, pero es mejor emplear links simbólicos:

    cd src/app
    ln -s ./../../../src/app/banner.txt
    ln -s ./../../../src/lista_cursos/lista_cursos.txt

El ejecutable se encuentra en 'Project-106/build/app/app_main', para ejecutarlo:

    ./app_main
