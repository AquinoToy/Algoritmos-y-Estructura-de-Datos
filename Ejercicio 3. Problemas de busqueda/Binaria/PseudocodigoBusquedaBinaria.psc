//Modo iterativo
Procedimiento Búsqueda_binaria(A, valor, inicio, fin)
  res = -1
  repetir hasta inicio = fin
    mitad = (inicio + fin) / 2
    si (valor == A[mitad])
      regresa mitad
    sino si (valor > A[mitad]) // puede estar en el lado derecho
      inicio = mitad + 1
    sino // está en el lado izquierdo
      fin = mitad - 1
    fin si
  fin repetir
  regresa res
fin Procedimiento
//Modo recursivo
Procedimiento Búsqueda_binaria (A, valor, inicio, fin)
  si inicio > fin
    regresa -1
  sino
    mitad = (inicio + fin) / 2
    si (valor == A[mitad])
      regresa mitad
    sino si (valor > A[mitad])     // x puede estar en el lado derecho
      regresa Búsqueda_binaria (A, valor, mitad + 1, fin)
    sino                           // x está en el lado izquierdo
      regresa Búsqueda_binaria (A, valor, inicio, mitad - 1)
  fin si
fin Procedimiento
