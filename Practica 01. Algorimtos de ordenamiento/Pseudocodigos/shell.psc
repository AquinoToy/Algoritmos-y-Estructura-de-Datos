Algoritmo Shell(A,n)
    k = TRUNC(n/2)
    mientras k >= 1 hacer
        b= 1
        mientras b!=0 hacer
            b=0
            para i=k hasta n-1 hacer
                si A[i-k] > A[i] 
                    temp=A[i]
                    A[i]=A[i-k]
                    A[i-k]=temp
                    b=b+1
                fin si
            fin para
        fin mientras
        k=TRUNC(k/2)
    fin mientras
fin Algoritmo
