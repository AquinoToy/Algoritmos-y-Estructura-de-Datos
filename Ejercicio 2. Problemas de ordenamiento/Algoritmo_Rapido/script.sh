 # chmod +x script.sh //permisos de ejecucion

#!/bin/bash
./rapido 1000 < 10mil_numeros.txt > salida_rapido_test1.txt
./rapido 5000 < 10mil_numeros.txt > salida_rapido_test2.txt
./rapido 10000 < 10mil_numeros.txt > salida_rapido_test3.txt
