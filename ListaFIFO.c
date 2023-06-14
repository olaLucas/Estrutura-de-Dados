#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int dado;
    struct node *proximo;
} *ptr_node;

ptr_node fila;
int counter = 1;

void inicializar();
void inserir(ptr_node fila);
void excluir(ptr_node fila);
void exibir(ptr_node fila);
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
        
        //printf("Counter: %d\n", counter);
        exibir(fila);
        
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
            inserir(fila);
            break;

        case 2:
            excluir(fila);
            break;

        case 3:
            exibir(fila);
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

void inserir(ptr_node fila)
{
    if (counter <= 1)
    {
        inicializar();
    }
    else
    {
        while (fila->proximo != NULL)
        {
            fila = fila->proximo;
        }

        fila->proximo = (ptr_node)malloc(sizeof(ptr_node));
        fila = fila->proximo;
        fila->dado = counter;
        counter++;
        fila->proximo = NULL;
    }
}

void excluir(ptr_node fila)
{
    if (counter == 1)
    {
        system("clear");
        printf("Fila vazia, não há dados para excluir. \n\n");
        cleanBuffer();
        getchar();
        return;
    }

    if (counter == 2)
    {
        free(fila);
        counter--;
        return;
    }
    
    if (fila->proximo != NULL)
    {
        ptr_node atual;

        atual = fila;
        fila = fila->proximo;

        atual->dado = fila->dado;
        atual->proximo = fila->proximo;
        free(fila);
        counter--;
    }
}

void exibir(ptr_node fila)
{   
    if (counter == 1)
    {
        printf("Pilha vazia, não há dados para exibir! \n");
        return;
    }
    
    printf("[ ");
    while (fila->proximo != NULL)
    {
        printf("(Dado: %d | Próximo: %p )", fila->dado, fila->proximo);
        fila = fila->proximo;
    }

    printf("(Dado: %d | Próximo: %p )", fila->dado, fila->proximo);
    printf("]");
}

void inicializar()
{
    fila = (ptr_node)malloc(sizeof(ptr_node));
    fila->dado = counter;
    fila->proximo = NULL;
    counter++;
}

void cleanBuffer()
{
    int c;
    while ((c = getchar()) != '\n');
}