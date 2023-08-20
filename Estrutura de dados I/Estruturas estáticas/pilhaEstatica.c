#include <stdio.h>
#include <stdlib.h>

#define tamanho 3

struct pilha
{
    int dados[tamanho];
    int inicio;
    int fim;
};

struct pilha p1;

void inserir();
void excluir();
void exibir();
void menu();
void cleanBuffer();

int main(void)
{   
    p1.inicio = 0;
    p1.fim = 0;
    
    menu();

    return 0;
}

void inserir()
{   
    if (p1.fim == tamanho)
    {
        printf("\nPilha cheia!\n");
        cleanBuffer();
        getchar();
        return;
    }
    else
    {
        int num = 0;
        printf("\nInforme um número: \n >>> ");
        scanf("%d", &num);

        p1.dados[p1.fim] = num;
        p1.fim++;
        return;
    }
}

void excluir()
{
    if (p1.fim == p1.inicio)
    {
        printf("\n\nPilha vazia, não há dados para excluir. \n");
        cleanBuffer();
        getchar();
        return;
    }
    else
    {
        p1.dados[p1.fim-1] = 0;
        p1.fim--;
    }
}

void exibir()
{
    if (p1.fim == p1.inicio)
    {
        printf("\n\nPilha vazia, não há dados para exibir. \n");
        return;
    }

    printf("[ ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", p1.dados[i]);
    }
    printf("]");
}

void menu()
{
    int seletor = 0;
    while (seletor != 10)
    {
        system("clear");
        exibir();
        
        printf("\nSelecione uma opção: \n\n");
        printf("1. Inserir dados.\n");
        printf("2. Excluir dados.\n");
        printf("3. Exibir dados.\n");
        printf("4. Sair.\n");
        
        printf("\n >>> ");
        scanf("%d", &seletor);

        switch (seletor)
        {
        case 1:
            inserir();
            break;

        case 2:
            excluir();
            break;

        case 3:
            exibir();
            break;

        case 4:
            return;
            break;
        
        default:
            printf("Opção inválida! Tente novamente. \n\n");
            cleanBuffer();
            getchar();
            break;
        }
    }
}

void cleanBuffer()
{
    int c;
    while ((c = getchar()) != '\n');
}
