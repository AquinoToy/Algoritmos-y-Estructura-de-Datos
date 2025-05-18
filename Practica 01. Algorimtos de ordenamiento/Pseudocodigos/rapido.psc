Algoritmo QuickSort(A, p, r)
    si p < r entonces
        j = Pivot(A, p, r)
        QuickSort(A, p, j-1)
        QuickSort(A, j+1, r)
    fin si
fin Algoritmo

Algoritmo Pivot(A, p, r)
    piv = A[p], i = p + 1, j = r
    mientras (i < j)
        mientras A[i] <= piv y i < r hacer
            i++
        mientras A[j] > piv hacer
            j--
        si i < j entonces
            Intercambiar(A, i, j)
        fin si
    fin mientras
    Intercambiar(A, p, j)
    regresar j
fin Algoritmo

Algoritmo Intercambiar(A, i, j)
    temp = A[j]
    A[j] = A[i]
    A[i] = temp
fin Algoritmo
