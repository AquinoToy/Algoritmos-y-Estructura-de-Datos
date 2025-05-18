Algoritmo Insercion(A,n)
    para i=0 hasta n-1 hacer
        j=i
        temp=A[i]
        mientras (j>0) && (temp<A[j-1]) hacer
            A[j]=A[j-1]
            j--
        fin mientras
        A[j]=temp
    fin para
fin Algoritmo
