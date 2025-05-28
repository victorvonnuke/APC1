#include <stdio.h>

int main()
{

    int numeros[10];
    numeros[0] = 5;
    numeros[1] = -1;
    numeros[2] = 10;
    numeros[3] = 6;
    numeros[4] = -5;
    numeros[5] = -7;
    numeros[6] = 7;
    numeros[7] = 11;
    numeros[8] = 2;
    numeros[9] = 0;

    int maior = -99999;
    int menor = 99999;

    printf("Entre com 10 numeros inteiros\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Numero %i: ", i + 1);
        scanf("%i", &numeros[i]);

        if (maior < numeros[i])
        {
            maior = numeros[i];
        }

        if (menor > numeros[i])
        {
            menor = numeros[i];
        }
    }

    printf("Seus numeros foram: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%i", numeros[i]);
    }
    printf("\n");
    printf("O maior numero foi %i e o menor numero foi %i\n", maior, menor);

    return 0;
}