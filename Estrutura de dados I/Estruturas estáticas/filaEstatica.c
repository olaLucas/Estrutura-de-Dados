#include <stdio.h>
#include <stdlib.h>

#define tamanho 3

struct fila
{
    int dados[tamanho];
    int inicio;
    int fim;
};

struct fila f1;

void inserir();
void excluir();
void exibir();
void menu();
void cleanBuffer();
void realocar();

int main(void)
{   
    f1.inicio = 0;
    f1.fim = 0;
    
    menu();

    return 0;
}

void inserir()
{   
    if (f1.fim == tamanho)
    {
        printf("\nFila cheia!\n");
        cleanBuffer();
        getchar();
        return;
    }
    else
    {
        int num = 0;
        printf("\nInforme um número: \n >>> ");
        scanf("%d", &num);

        f1.dados[f1.fim] = num;
        f1.fim++;
        return;
    }
}

void excluir()
{
    if (f1.fim == f1.inicio)
    {
        printf("\n\nFila vazia, não há dados para excluir. \n");
        cleanBuffer();
        getchar();
        return;
    }
    else
    {
        f1.dados[f1.inicio] = 0;
        realocar();
        f1.fim--;
    }
}

void exibir()
{
    if (f1.fim == f1.inicio)
    {
        printf("\n\nFila vazia, não há dados para exibir. \n");
        return;
    }

    printf("[ ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", f1.dados[i]);
    }
    printf("]");
}

void menu()
{
    int seletor = 0;
    while (seletor != 4)
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

void realocar()
{

    if (f1.fim == f1.inicio)
    {
        printf("\nFila vazia, não há elementos para realocar!\n");
        cleanBuffer();
        getchar();
        return;
    }
    else
    {
        for (int i = 0; i < f1.fim-1; i++)
        {
            f1.dados[i] = f1.dados[i+1];
            f1.dados[i+1] = 0; 
        } 
    }
}

void cleanBuffer()
{
    int c;
    while ((c = getchar()) != '\n');
}