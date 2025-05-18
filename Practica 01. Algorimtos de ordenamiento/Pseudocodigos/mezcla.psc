Algoritmo MergeSort(A, p, r)
    si ( p < r ) entonces
        q = parteEntera((p+r)/2)
        MergeSort(A, p, q)
        MergeSort(A, q+1, r)
        Merge(A, p, q, r)
    fin si
fin Algoritmo

Algoritmo Merge(A, p, q, r)
    l = r - p + 1, i = p, j = q + 1
    para k = 0 hasta k >= l hacer
        si (i <= q && j <= r)
            si (A[i] < A[j])
                C[k] = A[i]
                i++
            sino
                C[k] = A[j]
                j++
            fin si
        sino si (i <= q)
            C[k] = A[i]
            i++
        sino
            C[k] = A[j]
            j++
        fin si
    fin para
    k = p
    para i = 0 hasta i < l hacer
        A[k] = C[i]
        k++
    fin para
fin Algoritmo

