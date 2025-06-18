#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ERROS 6
#define TAM_PALAVRA 30
#define MAX_NOME 30
#define MAX_JOGADORES 100
#define ARQUIVO_RANKING "ranking.txt"

int main() {
    srand(time(NULL));

    typedef struct {
        char nome[MAX_NOME];
        int vitorias;
        int derrotas;
    } Jogador;

    int opcao;
    do {
        // Menu
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        printf("\n=== MENU FORCA ===\n");
        printf("1. Jogar (Facil)\n");
        printf("2. Jogar (Medio)\n");
        printf("3. Jogar (Dificil)\n");
        printf("4. Ver Ranking\n");
        printf("5. Creditos\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao >= 1 && opcao <= 3) {
            const char* palavrasFacil[] = {"bola", "casa", "pato", "gato", "mesa"};
            const char* palavrasMedio[] = {"escola", "carro", "janela", "viagem", "trabalho"};
            const char* palavrasDificil[] = {"astronauta", "helicoptero", "ornitorrinco", "subterraneo", "desenvolvedor"};

            const char* palavra;
            int indice = rand() % 5;

            if (opcao == 1)
                palavra = palavrasFacil[indice];
            else if (opcao == 2)
                palavra = palavrasMedio[indice];
            else
                palavra = palavrasDificil[indice];

            char nomeJogador[MAX_NOME];
            printf("\nDigite seu nome: ");
            fgets(nomeJogador, MAX_NOME, stdin);
            nomeJogador[strcspn(nomeJogador, "\n")] = 0;

            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif

            printf("=== JOGO DA FORCA ===\n");

            int erros = 0, tentativas = 0, acertos = 0;
            char letrasChutadas[26] = {0};
            int tamanho = strlen(palavra);
            char palavraAcertada[tamanho + 1];
            for (int i = 0; i < tamanho; i++) {
                palavraAcertada[i] = '_';
            }
            palavraAcertada[tamanho] = '\0';

            while (erros < MAX_ERROS && acertos < tamanho) {
                printf("\n _______\n");
                printf(" |     |\n");
                printf(" |     %c\n", (erros >= 1) ? 'O' : ' ');
                printf(" |    %c%c%c\n", (erros >= 3) ? '/' : ' ', (erros >= 2) ? '|' : ' ', (erros >= 4) ? '\\' : ' ');
                printf(" |    %c %c\n", (erros >= 5) ? '/' : ' ', (erros >= 6) ? '\\' : ' ');
                printf("_|_\n\n");

                printf("Palavra: ");
                for (int i = 0; i < tamanho; i++) {
                    printf("%c ", palavraAcertada[i]);
                }

                printf("\nLetras tentadas: ");
                for (int i = 0; i < tentativas; i++) {
                    printf("%c ", letrasChutadas[i]);
                }

                char escolha;
                do {
                    printf("\nDeseja tentar adivinhar a palavra inteira? (s/n): ");
                    escolha = getchar();
                    while (getchar() != '\n');
                    escolha = tolower(escolha);
                } while (escolha != 's' && escolha != 'n');

                if (escolha == 's') {
                    char tentativaPalavra[TAM_PALAVRA];
                    printf("Digite a palavra: ");
                    fgets(tentativaPalavra, TAM_PALAVRA, stdin);
                    tentativaPalavra[strcspn(tentativaPalavra, "\n")] = 0;
                    for (int i = 0; tentativaPalavra[i]; i++) {
                        tentativaPalavra[i] = tolower(tentativaPalavra[i]);
                    }

                    if (strcmp(tentativaPalavra, palavra) == 0) {
                        strcpy(palavraAcertada, palavra);
                        acertos = tamanho;
                        break;
                    } else {
                        erros++;
                        printf("Palavra errada! Tentativas restantes: %d\n", MAX_ERROS - erros);
                        if (erros >= MAX_ERROS) break;
                    }

                } else {
                    char chute;
                    do {
                        printf("Digite uma letra: ");
                        chute = getchar();
                        while (getchar() != '\n');
                        chute = tolower(chute);
                        if (!isalpha(chute)) {
                            printf("Por favor, digite apenas letras do alfabeto!\n");
                        }
                    } while (!isalpha(chute));

                    int repetida = 0;
                    for (int i = 0; i < tentativas; i++) {
                        if (letrasChutadas[i] == chute) {
                            repetida = 1;
                            break;
                        }
                    }
                    if (repetida) {
                        printf("Voce ja tentou essa letra!\n");
                        continue;
                    }

                    letrasChutadas[tentativas++] = chute;

                    int encontrou = 0;
                    for (int i = 0; i < tamanho; i++) {
                        if (palavra[i] == chute) {
                            if (palavraAcertada[i] == '_') {
                                palavraAcertada[i] = chute;
                                acertos++;
                            }
                            encontrou = 1;
                        }
                    }

                    if (!encontrou) {
                        erros++;
                        printf("Letra incorreta! Tentativas restantes: %d\n", MAX_ERROS - erros);
                    }
                }
            }

            printf("\n _______\n");
            printf(" |     |\n");
            printf(" |     %c\n", (erros >= 1) ? 'O' : ' ');
            printf(" |    %c%c%c\n", (erros >= 3) ? '/' : ' ', (erros >= 2) ? '|' : ' ', (erros >= 4) ? '\\' : ' ');
            printf(" |    %c %c\n", (erros >= 5) ? '/' : ' ', (erros >= 6) ? '\\' : ' ');
            printf("_|_\n\n");

            if (acertos == tamanho) {
                printf("Parabens, %s! Voce acertou a palavra: %s\n", nomeJogador, palavra);
            } else {
                printf("Voce perdeu, %s! A palavra era: %s\n", nomeJogador, palavra);
            }

            // Atualizar ranking
            Jogador jogadores[MAX_JOGADORES];
            int total = 0;
            FILE* arquivo = fopen(ARQUIVO_RANKING, "r");
            if (arquivo != NULL) {
                while (fscanf(arquivo, " %s %d %d", jogadores[total].nome, &jogadores[total].vitorias, &jogadores[total].derrotas) == 3) {
                    total++;
                }
                fclose(arquivo);
            }

            int encontrado = 0;
            for (int i = 0; i < total; i++) {
                if (strcmp(jogadores[i].nome, nomeJogador) == 0) {
                    if (acertos == tamanho)
                        jogadores[i].vitorias++;
                    else
                        jogadores[i].derrotas++;
                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado) {
                strcpy(jogadores[total].nome, nomeJogador);
                jogadores[total].vitorias = (acertos == tamanho) ? 1 : 0;
                jogadores[total].derrotas = (acertos == tamanho) ? 0 : 1;
                total++;
            }

            arquivo = fopen(ARQUIVO_RANKING, "w");
            if (arquivo != NULL) {
                for (int i = 0; i < total; i++) {
                    fprintf(arquivo, "%s %d %d\n", jogadores[i].nome, jogadores[i].vitorias, jogadores[i].derrotas);
                }
                fclose(arquivo);
            }

            printf("\nPressione Enter para voltar ao menu...");
            getchar();

        } else if (opcao == 4) {
            // Ranking Ordenado
            FILE* arquivo = fopen(ARQUIVO_RANKING, "r");
            if (arquivo == NULL) {
                printf("Ainda nao ha registros no ranking.\n");
            } else {
                Jogador jogadores[MAX_JOGADORES];
                int total = 0;

                while (fscanf(arquivo, " %s %d %d", jogadores[total].nome, &jogadores[total].vitorias, &jogadores[total].derrotas) == 3) {
                    total++;
                }
                fclose(arquivo);

                // Ordenando ranking por vitorias decrescentes
                for (int i = 0; i < total - 1; i++) {
                    for (int j = i + 1; j < total; j++) {
                        if (jogadores[j].vitorias > jogadores[i].vitorias) {
                            Jogador temp = jogadores[i];
                            jogadores[i] = jogadores[j];
                            jogadores[j] = temp;
                        }
                    }
                }

                printf("\n=== RANKING DE JOGADORES ===\n");
                printf("%-20s | Vitorias | Derrotas\n", "Jogador");
                printf("-----------------------------------------\n");
                for (int i = 0; i < total; i++) {
                    printf("%-20s |    %2d    |    %2d\n", jogadores[i].nome, jogadores[i].vitorias, jogadores[i].derrotas);
                }
                printf("-----------------------------------------\n");
            }
            printf("\nPressione Enter para voltar ao menu...");
            getchar();

        } else if (opcao == 5) {
            // Créditos
            printf("\n=========== CREDITOS ===========\n");
            printf("Jogo da Forca desenvolvido por:\n");
            printf("- Andre Souza Mattos & Lucas Frazao\n");
            printf("- THE GAME A FORCA \n");
            printf("================================\n");
            printf("\nPressione Enter para voltar ao menu...");
            getchar();

        } else if (opcao == 6) {
            printf("Saindo do jogo...\n");
        } else {
            printf("Opcao invalida. Pressione Enter para continuar...");
            getchar();
        }

    } while (opcao != 6);

    return 0;
}
