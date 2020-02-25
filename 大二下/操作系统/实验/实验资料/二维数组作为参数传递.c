#include <stdio.h>

void PrintMatrix(int *M,int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", M[i * col + j]);
        }
        printf("\n");
    }
}

void PrintMatrix1(int M[][4],int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}



int main(void)
{
    int i, j, Matrix[3][4];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            Matrix[i][j] = (i+1) *10 +j;
        }
    }

   PrintMatrix(*Matrix, 3, 4);
   // PrintMatrix1(Matrix, 3, 4);




    return 0;
}