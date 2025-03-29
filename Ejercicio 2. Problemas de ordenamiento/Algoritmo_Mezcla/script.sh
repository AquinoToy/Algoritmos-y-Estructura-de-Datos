 # chmod +x script.sh //permisos de ejecucion

#!/bin/bash
./mezcla 1000 < 10mil_numeros.txt > salida_mezcla_test1.txt
./mezcla 5000 < 10mil_numeros.txt > salida_mezcla_test2.txt
./mezcla 10000 < 10mil_numeros.txt > salida_mezcla_test3.txt
