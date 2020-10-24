#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 500
set ejecutable = ordenacion2
set salida = tiempos_ordenacionMEJOR.dat

@ i = $inicio
@ d = 0
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 10000` >> $salida
  while ( $d < $i )
    printf($d)
    @ d = $d+1
  end
  @ i += $incremento
end
