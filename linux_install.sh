!# /bin/bash

verde='\033[32m'
rosa='\033[35m'
reset='\033[0m'

echo "\n${rosa}Building...${reset}\n"
cd build;
cmake ..;
make;
echo "\n${verde}Built! (We hope)${reset}"

cd ..;
echo "${rosa}Creating symlink to files...${reset}\n"
echo ''
rm banner.txt lista_cursos.txt;
ln -s ./src/app/banner.txt;
ln -s ./src/lista_cursos/lista_cursos.txt;
echo "\n${rosa}Adding executable to current folder...${reset}\n"
cp ./build/src/app/app_main ./gestor_cursos;

echo "\n${verde}[ OK ] Done${reset}\n"
