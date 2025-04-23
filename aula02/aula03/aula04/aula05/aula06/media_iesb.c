#include <stdio.h>

int main() {
    float nota_a1 = 0.0f;
    float nota_a2 = 0.0f;
    int leu_certo = 0;


    printf("Entre com a nota A1: ");
    leu_certo = scanf("%f", &nota_a1);
    getchar();

    if (nota_a1 < 0.0f || nota_a1 > 10.0f || !leu_certo) {
        printf("A nota A1 deve ser entre 0.0 e 10.0.\n");
        return 0;
    }

    printf("Entre com a nota A2: ");
    scanf("%f", &nota_a2);
    getchar();

    if (nota_a2 < 0.0f || nota_a2 > 10.0f || !leu_certo) {
        printf("A nota A2 deve ser entre 0.0 e 10.0.\n");
        return 0;
    }

    float media = 0.4f * nota_a1 + 0.6f * nota_a2;

    if (9.0 <= media && media <= 10.0f) {
        printf("A media e %.1f e a mencao SS.\n", media);
    } else if (7.0f <= media && media <= 8.9f) {
        printf("A media e %.1f e a mencao MS.\n", media);
    } else if (5.0f <= media && media <= 6.9f) {
        printf("A media e %.1f e a mencao MM.\n", media);
    } else if (3.0f <= media && media <= 4.9f) {
        printf("A media e %.1f e a mencao MI.\n", media);
    } else if (0.1f <= media && media <= 2.9f) {
        printf("A media e %.1 e a ,encao II.\n", media);
    } else {
        printf("A media e %.1f e a mencao SR.\n", media);
    }


    return 0;
}