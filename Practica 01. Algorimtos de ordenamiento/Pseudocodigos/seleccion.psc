Algoritmo Seleccion(A,n)
    para k=0 hasta n-2 hacer
        p=k
        para i=k+1 hasta n-1 hacer
            si A[i] < A[p] entonces
                p=i
            fin si
        fin para
        temp = A[p]
        A[p] = A[k]
        A[k] = temp
    fin para
fin Algoritmo
