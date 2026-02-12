#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int a[100][100];

    // Read matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Check if square matrix
    if (m != n)
    {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    // Check symmetry
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i][j] != a[j][i])
            {
                printf("Not a Symmetric Matrix");
                return 0;
            }
        }
    }

    printf("Symmetric Matrix");
    return 0;
}
