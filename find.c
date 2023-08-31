int    min_value(int a, int b, int c)
{
    if (a <= b && a <= c) 
       return a;
    else if (b <= a && b <= c) 
        return b;
    else 
        return c;
}


int find_square(char **map, char *empty, char *obs, char *full)
{
    int **map = //funcion que genera el mapa
    int max_square = 0;
    int **matrix_aux;
    int i;
    int j;
    int row;
    int colum;      //generar matriz para filas y columnas
    
    i = 0;
    while (i < row) 
    {
        j = 0;
        while (j < colum - 1) 
        {
           if (map[i][j] == obs)
              matrix_aux[i][j] = 0;
              else
                     matrix_aux[i][j] = 1;
            if (i > 0 && j > 0 && map[i][j] != obs) 
                matrix_aux[i][j] = min_value([i-1][j], matrix_aux[i][j-1], matrix_aux[i-1][j-1]) + 1;
            if (matrix_aux[i][j] > max_square)
              max_square = matrix_aux[i][j];
            j++;
        }
        i++;
    }
    return count_max;
}