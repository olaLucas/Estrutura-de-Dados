#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int dado;
    struct node *proximo;
} *ptr_node;

ptr_node pilha;
int counter = 1;

void inicializar();
void inserir(ptr_node pilha);
void excluir(ptr_node pilha);
void exibir(ptr_node pilha);
void menu();
void cleanBuffer();

int main(void)
{    
    inicializar();

    menu();
    return 0;
}

void menu()
{
    int seletor = 0;
    while (seletor != 4)
    {
        system("clear");
        
        exibir(pilha);
        
        printf("\nSelecione uma opção: \n\n");
        printf("1. Inserir dados.\n");
        printf("2. Excluir dados.\n");
        printf("3. Exibir dados.\n");
        printf("4. Sair.\n");
        
        printf("\n>>> ");
        scanf("%d", &seletor);

        switch (seletor)
        {
        case 1:
            inserir(pilha);
            break;

        case 2:
            excluir(pilha);
            break;

        case 3:
            exibir(pilha);
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

void inserir(ptr_node pilha)
{
    if (counter <= 1)
    {
        inicializar();
    }
    else
    {
        while (pilha->proximo != NULL)
        {
            pilha = pilha->proximo;
        }

        pilha->proximo = (ptr_node)malloc(sizeof(ptr_node));
        pilha = pilha->proximo;
        pilha->dado = counter;
        counter++;
        pilha->proximo = NULL;
    }
}

void excluir(ptr_node pilha)
{
    if (counter == 1)
    {
        system("clear");
        printf("Pilha vazia, não há dados para excluir. \n\n");
        cleanBuffer();
        getchar();
        return;
    }

    ptr_node atual;

    while (pilha->proximo != NULL)
    {   
        atual = pilha;
        pilha = pilha->proximo;
    }

    if (pilha->proximo == NULL)
    {
        if (counter == 2)
        {
            free(pilha);
            counter--;
        }
        else
        {
            atual->proximo = pilha->proximo;
            counter--;
            free(pilha);
        }
    }
}

void exibir(ptr_node pilha)
{   
    if (counter == 1)
    {
        printf("Pilha vazia, não há dados para exibir! \n");
        return;
    }
    
    printf("[ ");
    while (pilha->proximo != NULL)
    {
        printf("(Dado: %d | Próximo: %p )", pilha->dado, pilha->proximo);
        pilha = pilha->proximo;
    }

    printf("(Dado: %d | Próximo: %p )", pilha->dado, pilha->proximo);
    printf("]");
}

void inicializar()
{
    pilha = (ptr_node)malloc(sizeof(ptr_node));
    pilha->dado = counter;
    pilha->proximo = NULL;
    counter++;
}

void cleanBuffer()
{
    int c;
    while ((c = getchar()) != '\n');
}