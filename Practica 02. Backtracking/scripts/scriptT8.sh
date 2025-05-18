#!/bin/bash

# Test 8: cambio de color en Imagenes/SunTest8.bmp en diferentes niveles de tolerancia

for tolerancia in 0 10 20 35 50 70 100 140 200 255; do
  for i in {1..10}; do
    ./cambioColor Imagenes/SunTest8.bmp "(625,580)" "(181,230,29)" $tolerancia >> Tests/tolerancia${tolerancia}/test8.txt
  done
done