!# /bin/bash

cd build;

cmake ..;

make;

cp ./../src/app/banner.txt ./..
cp ./../src/lista_cursos/lista_cursos.txt ./..
cp ./src/app/app_main ./../gestor_cursos
