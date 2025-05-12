validarPosicion(tablero, fila, columna)
{
    para i = 0 hasta columna - 1 hacer
    {
        si (tablero[fila][i] == 1)
            retornar falso
    }

    para i = fila, j = columna; i >= 0 y j >= 0; i--, j-- hacer
    {
        si (tablero[i][j] == 1)
            retornar falso
    }

    para i = fila, j = columna; i < n y j >= 0; i++, j-- hacer
    {
        si (tablero[i][j] == 1)
            retornar falso
    }

    retornar verdadero
}
