#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int dado;
    struct node * proximo;
} * ptr_node;

ptr_node init_node();
void inserir();
void exibir();
void excluir();
void menu();

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n');
}

void inserir(ptr_node * pilha)
{
    ptr_node navegador = * pilha;
    int num = -1;
    while (num == -1)
    {
        printf("\nInforme o número que deseja inserir: (0 = Sair)");
        printf("\n\n>>> ");
        scanf("%d", &num);
        limparBuffer();

        if (num == 0)
        {
            return;
        }
    }

    if (navegador == NULL) // incializa a pilha
    {
        *pilha = init_node(pilha);
        navegador = * pilha;
        navegador->dado = num;
    }
    else
    {
        while (navegador->proximo != NULL) // vai até o ultimo elemento da pilha
        {
            navegador = navegador->proximo;
        }
    
        navegador->proximo = init_node(pilha); // inicializa o proximo elemento
        navegador = navegador->proximo;
        navegador->dado = num;
    }
}

void exibir(ptr_node pilha)
{
    printf("Pilha: [ ");
    if (pilha != NULL)
    {
        printf("%d ", pilha->dado);
        while (pilha->proximo != NULL)
        {
            pilha = pilha->proximo;
            if (pilha->dado != 0)
            {
                printf("%d ", pilha->dado);
            }
        }
    } 
    else 
    {
        printf("vazia ");
    }
    
    printf("]\n");
}

void excluir(ptr_node * pilha)
{
    ptr_node navegador = * pilha;
    if (navegador == NULL)
    {
        return;
    } 
    else if (navegador->proximo == NULL)
    {
        *pilha = NULL;
        free(*pilha);
        return;
    } 
    else
    {
        ptr_node atual;
        while (navegador->proximo != NULL )
        {
            atual = navegador;
            navegador = navegador->proximo;
        }
        
        atual->proximo = navegador->proximo;
        navegador = NULL;
        free(navegador);
    }
}

ptr_node init_node(ptr_node elemento)
{
    elemento = (ptr_node)malloc(sizeof(ptr_node));
    elemento->dado = '\0';
    elemento->proximo = NULL;

    return elemento;
}

void menu(ptr_node pilha)
{
    int seletor = -1;
    while (seletor != 0)
    {
        system("clear");
        printf("--------------| ELEMETOS |--------------\n");
        exibir(pilha);
        
        printf("\nSelecione uma opção: \n\n");
        printf("0. Sair \n");
        printf("1. Inserir dados.\n");
        printf("2. Excluir dados.\n");
        
        printf("\n >>> ");
        scanf("%d", &seletor);
        limparBuffer();

        switch (seletor)
        {
        case 0:
            return;
            break;
        
        case 1:
            inserir(&pilha);
            break;

        case 2:
            excluir(&pilha);
            break;
        
        default:
            printf("Opção inválida! Tente novamente. \n\n");
            limparBuffer();
            getchar();
            break;
        }
    }
}

int main(void)
{
    ptr_node pilha = NULL;
    menu(pilha);
    
    return 0;
}