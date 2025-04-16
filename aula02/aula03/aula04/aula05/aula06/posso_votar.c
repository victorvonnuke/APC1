#include <stdio.h>

int main() {
    int idade = 0;

    printf("Informe usa idade: ");
    scanf("%i", &idade);

    if (idade < 16) {
        printf("Voce nao pode votar!\n");
    } else {
        if (idade >= 18) {
            printf("Voce e obrigado a votar!\n");
        } else {
            printf("Voce pode votar!\n");
        }
        if (idade >= 70) {
            printf("Vai dormir veio broxa\n");
        }
    }






    return 0;
}
