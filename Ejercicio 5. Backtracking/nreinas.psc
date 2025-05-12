NReinas(n)
{
    tablero = matriz de tamaño n x n
    para i = 1 hasta n hacer
    {
        para j = 1 hasta n hacer
            tablero[i][j] = 0
    }

    si (nReinasBacktracking(tablero, 0, n))
        imprimir(tablero)
    sino
        imprimir("No se encontró solución")
}
