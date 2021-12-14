if [ $# -ne 1 ] 
then
	echo "Faltan argumentos o sobran argumentos"
	echo "$0 <nombre_dir>" 
	exit 1
fi

mkdir $1
mkdir $1/include
mkdir $1/src
mkdir $1/obj
mkdir $1/lib
mkdir $1/bin
mkdir $1/doc
