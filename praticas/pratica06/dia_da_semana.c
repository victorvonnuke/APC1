#include <stdio.h>
int main ()
{
 int dia;

 printf("Que dia e hoje: \n");
 scanf("%i", &dia);

 if (dia == 1)
{
    printf("Hoje e domingo\n");
} 
else if (dia == 2)
{
    printf("Hoje e segunda\n");
}
else if (dia == 3)
{
    printf("Hoje e terca\n");
} 
else if (dia == 4)
{
    printf("Hoje e quarta\n");
}
else if (dia == 5)
{
    printf("Hoje e quinta\n");
}
else if (dia == 6)
{
    printf("Hoje e sexta\n");
}
else if (dia == 7)
{
    printf("Hoje e sabado\n");
}
else 
{
    printf("Dia invalido\n");
}
return 0;
}
