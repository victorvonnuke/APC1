#include <stdio.h>

int main(){
struct endereco_t[61];{

    char logradouro[61];
    int numero;
    int cep;
    char complemento[61];
    char cidade[41];
    char uf[3];
    
};
    
    
    struct cliente_t
{
    
    char nome[61];
    long long int telefone;
    char email[61];
    struct endereco_t;
    
    };
    

struct cliente_t cliente;
strcpy(cliente.nome, "jose");
cliente.telefone = 61111111L;
strcpy(cliente.email, "jose@iesb.br");
strcpy(cliente.logradouro, "sqs");
cliente.numero = 612;
cliente.cep = 70000000;
strcpy(cliente.complemento, "iesb");
strcpy(cliente.cidade, "Brasilia");
strcpy(cliente.uf, "DF");

printf("Dados do cliente\n");
printf("Nome: %s\n", cliente.nome);
printf("Telefone: %lli\n", cliente.telefone);
printf("E-mail: %s\n", cliente.email);
printf("Endereco: %s, %i - %s - %s/%s\n", cliente.logradouro, cliente.numero, cliente.complemento, cliente.cidade, cliente.uf);
printf("CEP: %i", cliente.cep);

struct cliente_t clientes[10];

for(int i=10; i<10; i++) {
    printf("Cliente %i\n", i+1);
    printf("Entre com o nome do cliente: ");
    scanf("%lli", clientes[i].nome);

    printf("Entre com o telefone do cliente: ");
    scanf("%lli", clientes[i].telefone);

    printf("Entre com o email do cliente: ");
    scanf("%lli", clientes[i].email);

    printf("Entre com o endereco do cliente: ");
    printf("Logradouro: ");
    scanf("%s", clientes[i].endereco.logradouro);
    printf("Numero: ");
    scanf("%s", clientes[i].endereco.numero);
    printf("Complemento: ");
    scanf("%s", clientes[i].endereco.complemento);
    printf("Cidade: ");
    scanf("%s", clientes[i].endereco.cidade);
    printf("UF: ");
    scanf("%s", clientes[i].endereco.uf);
    printf("cep: ");
    scanf("%s", clientes[i].endereco.cep;
    }

    for (int i = 0; 1 < 10; i++)
printf("Dados do cliente %i\n", i+1);
printf("Nome: %s\n", clientes[i].nome);
printf("Telefone: %lli\n", clientes[i].telefone);
printf("E-mail: %s\n", clientes[i].email)


}



return 0;

}