for i in $(seq 1 9); do
rm media
gcc -x assembler-with-cpp -D TEST=$i –no-pie media.s -o media
printf "__TEST%02d__%35s\n" $i "" | tr " " "-" ; ./media
done