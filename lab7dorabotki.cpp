#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

int vismas[4];
int sprev;

void DFS(int s, int n, int* vis, int** G) {
    vis[s] = 1;
   
    vismas[s] = s;
    
    //f (s < sprev)
    //    printf("\n\n%d ", s);
    //else
        printf("%d ", s);
    sprev = s;
    for (int i = 0; i < n; i++)
    {
        if (G[s][i] == 1 && vis[i] == 0)
        { 
            DFS(i, n, &vis[0], &(&G)[0][0]);
        }
    }
}

int main() {
    int n, i = 0;
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    printf("Введите количество вершин для матрицы: ");
    scanf_s("%d", &n);
    int** G = new int* [n];
    int* vis = new int[n];
    for (int i = 0; i < n; i++)
    {
        G[i] = new int[n];
        vis[i] = 0;
    }



    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                G[i][j] = 0;
            }
            else if (i != j)
            {
                G[i][j] = rand() % 2;
                G[j][i] = G[i][j];
            }
        }
    }

    printf("Матрица смежности:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    for (int i = 0; i < 4; i++)
        vismas[i] = 0;
    DFS(0, n, &vis[0], &(&G)[0][0]);
    printf("\n\n");
    for (int i = 0; i < 4; i++)
    {
        if ((vismas[i] == 0) && i > 0)
            DFS(i, n, &vis[0], &(&G)[i][0]);
            printf("%d", i);
    }
    
}