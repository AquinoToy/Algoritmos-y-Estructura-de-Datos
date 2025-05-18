Algoritmo BurbujaOptimizada(A,n)
    cambios = SI
    i=0
    mientras i<= n-2 && cambios != NO hacer
        cambios = NO
        para j=0 hasta (n-2)-i hacer
            si(A[j] < A[j+1]) hacer
                aux = A[j]
                A[j] = A[j+1]
                A[j+1] = aux
                cambios = SI
            fin si
        fin para
        i= i+1
    fin mientras
fin Algoritmo
