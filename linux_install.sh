
verde='\033[32m'
rosa='\033[35m'
reset='\033[0m'

echo "\nBuilding..."
cd build;
cmake ..;
make;
echo "\nBuilt! (We hope)"

cd ..;
echo "\nCreating symlink to files..."
rm banner.txt lista_cursos.txt;
ln -s ./src/app/banner.txt;
cp ./src/lista_cursos/lista_cursos.txt ./.;

echo "\nAdding executable to current folder..."
cp ./build/src/app/app_main ./gestor_cursos;

echo "\n[ OK ] Done\n"
