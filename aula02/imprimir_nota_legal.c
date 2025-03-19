#include <stdio.h>

int main() {
    printf("----------------------------------\n");
    printf("       N O T A   L E G A L        \n");
    printf("----------------------------------\n");
    printf("Item         Qde      Prc    Valor\n");
    printf("%-12s %03i %8.2f %8.2f\n", "Caneta", 2, 2.0, 4.0);
    printf("%-12s %03i %8.2f %8.2f\n", "Borracha", 1, 5.0, 5.0);
    printf("%-12s %03i %8.2f %8.2f\n", "Caderno", 3, 12.0, 12.0);
    printf("----------------------------------\n");
    printf("TOTAL.................: R$ %7.2f\n", 21.0);

    return 0;
}