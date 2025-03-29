 # chmod +x script.sh //permisos de ejecucion

#!/bin/bash
./insercion 1000 < 10mil_numeros.txt > salida_insercion_test1.txt
./insercion 5000 < 10mil_numeros.txt > salida_insercion_test2.txt
./insercion 10000 < 10mil_numeros.txt > salida_insercion_test3.txt
