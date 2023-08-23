#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura para um nó da lista
typedef struct node
{
    int dado;
    struct node *proximo;
} * ptr_node;

typedef struct lista
{
    unsigned int tamanho;
    ptr_node inicio;
    ptr_node fim;
} lista;

ptr_node init_node(ptr_node elemento, ptr_node prox, int dado);
void init_lista(lista * lis);
int get_dado();
void inserir_final(lista * lis);
void excluir(lista * lis);
void exibir(lista * lis);
void menu(lista * lis);
void cleanBuffer();

int main(void)
{    
    lista lis; init_lista(&lis);

    menu(&lis);
    return 0;
}

void menu(lista * lis)
{
    int seletor = 0;
    while (seletor != 4)
    {
        system("clear");
        exibir(lis);
        
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
            inserir_final(lis);
            break;

        case 2:
            excluir(lis);
            break;

        case 3:
            exibir(lis);
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

int get_dado()
{
    int dado = -1;
    printf("Insira um número: (-1. Cancelar)"); 
    printf("\n\n>>> "); scanf("%d", &dado);

    return dado;
}



// Inserir um elemento no final da lista
void inserir_final(lista* lis) 
{
    int dado = get_dado(); // Função para obter um dado (não fornecida aqui)
    if (dado == -1) 
    {
        return; // Se o dado for inválido, não faz nada
    }

    if (lis->inicio == NULL) // Se a lista estiver vazia
    { 
        lis->inicio = init_node(lis->inicio, NULL, dado); // Inicializa o primeiro nó
        lis->inicio->proximo = lis->inicio; // faz o unico elemento apontar para si mesmo
        lis->tamanho++; // atualiza o tamanho da lista
        lis->fim = lis->inicio; // atualiza o fim da lista
        return;
    }

    ptr_node navegador = lis->inicio;
    if (navegador->proximo == lis->inicio)  // Se houver apenas um elemento na lista
    {
        navegador->proximo = init_node(navegador->proximo, lis->inicio, dado); // Inicializa um novo nó
        lis->tamanho++; // atualiza o tamanho da lista
        lis->fim = navegador->proximo; // atualiza o fim da lista
    } 
    else // Se houver mais de um elemento na lista
    { 
        while (navegador != lis->fim) // Percorre a lista até o último elemento
        { 
            navegador = navegador->proximo;
        }
        navegador->proximo = init_node(navegador->proximo, lis->inicio, dado); // Inicializa um novo nó no final
        lis->tamanho++; // atualiza o tamanho da lista
        lis->fim = navegador->proximo; // atualiza o fim da lista
    }
}

// Excluir um elemento da lista
void excluir(lista * lis) 
{
    if (lis->inicio == NULL) // Se a lista estiver vazia 
    { 
        system("clear");
        printf("Lista vazia, não há dados para excluir.\n\n");
        cleanBuffer(); // Função para limpar o buffer de entrada
        getchar();
        return;
    }

    int num = get_dado(); // Função para obter o numero à ser excluido
    if (num == -1) 
    {
        return; // Usuário escolheu retornar para o menu
    }

    ptr_node navegador = lis->inicio;
    if (lis->inicio->dado == num) { // Se o primeiro elemento for igual ao número a ser excluído
        if (lis->inicio == lis->fim) // Se houver apenas um elemento na lista 
        { 
            free(lis->inicio); // Libera a memória do primeiro nó
            init_lista(lis);    // Inicializa a lista como vazia
        } 
        else if (lis->inicio != lis->fim) // Se houver mais elementos na lista
        { 
            lis->fim->proximo = lis->inicio->proximo; // faz o fim e inicio apontar para
            lis->inicio = lis->inicio->proximo; // o segundo elemento da lista para excluir o primeiro
            free(navegador); // Libera a memória do nó a ser excluído
        }
        return;
    } 
    else if (lis->fim->dado == num) // Se o último elemento for igual ao número a ser excluído
    { 
        navegador = lis->inicio;
        while (navegador->proximo != lis->fim) {
            navegador = navegador->proximo;
        }
        navegador->proximo = lis->fim->proximo;
        free(lis->fim); // Libera a memória do último nó
        lis->fim = navegador;
    } 
    else // Se o número a ser excluído estiver em algum nó do meio 
    { 
        ptr_node anterior = navegador;
        while (navegador->dado != num)  // percorre a lista até encontrar o numero
        {
            if (navegador == lis->fim) // caso encontre o final da lista antes
            {
                printf("Número não encontrado!\n\n");
                cleanBuffer(); // Função para limpar o buffer de entrada
                getchar();
                return;
            } 
            else 
            {
                anterior = navegador;
                navegador = navegador->proximo;
            }
        }
        anterior->proximo = navegador->proximo;
        free(navegador); // Libera a memória do nó a ser excluído
    }
}

void exibir(lista * lis)
{   
    if (lis->inicio == NULL) // lista vazia
    {
        printf("Pilha vazia, não há dados para exibir. \n\n");
        return;
    }
    
    if (lis->inicio == lis->fim) // somente um elemento na lista
    {
        printf("[ ");
        printf("( Endereço: %p | Dado: %d | Próximo: %p )", lis->inicio, lis->inicio->dado, lis->inicio->proximo);
        printf(" ]");

        return;
    }
         
    if (lis->inicio != lis->fim) // mais de um elemento na lista
    {
        ptr_node navegador = lis->inicio;

        printf("[ ");
        while (navegador != lis->fim)
        {
            printf("( Endereço: %p | Dado: %d | Próximo: %p )", navegador, navegador->dado, navegador->proximo);
            navegador = navegador->proximo;
        }

        printf("( Endereço: %p | Dado: %d | Próximo: %p )", navegador, navegador->dado, navegador->proximo);
        printf(" ]");
    }
}

void init_lista(lista * lis) // define os valores iniciais da lista
{
    lis->inicio = NULL;
    lis->tamanho = 0;
    lis->fim = NULL;
}

ptr_node init_node(ptr_node elemento, ptr_node prox, int dado) // inicia um nó
{
    elemento = (ptr_node)malloc(sizeof(ptr_node));
    elemento->dado = dado;
    elemento->proximo = prox;

    return elemento;
}

void cleanBuffer()
{
    int c;
    while ((c = getchar()) != '\n');
}