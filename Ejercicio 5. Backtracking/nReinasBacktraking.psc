nReinasBacktracking(tablero, columna, n)
{
    si (columna >= n)
        retornar verdadero

    para fila = 1 hasta n hacer
    {
        si (validarPosicion(tablero, fila, columna))
        {
            tablero[fila][columna] = 1

            si (nReinasBacktracking(tablero, columna + 1, n))
                retornar verdadero

            tablero[fila][columna] = 0
        }
    }

    retornar falso
}
