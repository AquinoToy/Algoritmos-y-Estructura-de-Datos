 # chmod +x script.sh //permisos de ejecucion

#!/bin/bash
./seleccion 1000 < 10mil_numeros.txt > salida_seleccion_test1.txt
./seleccion 5000 < 10mil_numeros.txt > salida_seleccion_test2.txt
./seleccion 10000 < 10mil_numeros.txt > salida_seleccion_test3.txt
