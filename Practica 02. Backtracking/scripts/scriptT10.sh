#!/bin/bash

# Test 10: cambio de color en Imagenes/FarosTest10.bmp en diferentes niveles de tolerancia

for tolerancia in 0 10 20 35 50 70 100 140 200 255; do
  for i in {1..10}; do
    ./cambioColor Imagenes/FarosTest10.bmp "(134,150)" "(153,217,234)"  $tolerancia >> Tests/tolerancia${tolerancia}/test10.txt
  done
done