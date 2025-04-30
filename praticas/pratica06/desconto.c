#include <stdio.h>

int main (){
    float valor_bruto;
    float valor_desconto;

    printf("Digite o valor: ");
    scanf("%f", &valor_bruto);

    if (valor_bruto <= 100.00f)
{
    valor_desconto = valor_bruto * 0.1f; 
    printf("Voce tem 1 porcento de desconto: %.2f\n", valor_desconto);
} 
    else if (valor_bruto <= 500.00f) 
{
    valor_desconto = valor_bruto * 0.05f;
    printf("Voce tem 5 porcento de desconto: %.2f\n", valor_desconto);
}
    else
{
    valor_desconto = valor_bruto * 0.1f;
    printf("Seu desconto e de 10 porcento: %.2f\n", valor_desconto);
}    

    return 0;
}