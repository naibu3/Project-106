!# /bin/bash

verde='\033[32m'
rosa='\033[35m'
reset='\033[0m'

echo "\n${rosa}Building...${reset}"
cd build;
cmake ..;
make;
echo "\n${verde}Built! (We hope)${reset}"

cd ..;
echo "\n${rosa}Creating symlink to files...${reset}"
rm banner.txt lista_cursos.txt;
ln -s ./src/app/banner.txt;
cp ./src/lista_cursos/lista_cursos.txt ./.;

echo "\n${rosa}Adding executable to current folder...${reset}"
cp ./build/src/app/app_main ./gestor_cursos;

echo "\n[${verde} OK ${reset}] Done\n"
