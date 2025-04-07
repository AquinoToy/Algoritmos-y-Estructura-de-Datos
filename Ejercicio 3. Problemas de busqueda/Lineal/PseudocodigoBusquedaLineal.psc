Algoritmo Búsqueda_lineal(A, n, valor)
  res = -1
  para i = 0 hasta n - 1 hacer
    si A[i] == valor
      res = i
    fin si
  fin para
  regresa res
fin Algoritmo
//Para un conjunto ordenado
Algoritmo Búsqueda_lineal(A, n, valor)
  res = -1
  para i = 0 hasta n - 1 || A[i] > valor hacer
    si A[i] == valor
      res = i
    fin si
  fin para
  regresa res
Fin Algoritmo
