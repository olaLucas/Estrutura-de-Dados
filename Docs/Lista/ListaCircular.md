# Lista Circular

## Estruturas

```c
// Estrutura para um nó da lista
typedef struct Node {
    int dado;             // Dado armazenado no nó
    struct Node* proximo; // Ponteiro para o próximo nó na lista
} * ptr_node;
```

Aqui, é definida uma estrutura `Node` que representa um nó da lista. Cada nó contém um inteiro (`dado`) para armazenar dados e um ponteiro para o próximo nó (`proximo`) na lista. Em seguida, é definido um tipo `ptr_node`, que é um ponteiro para a estrutura `Node`.

```c
// Estrutura para a lista encadeada
typedef struct lista {
    ptr_node inicio; // Ponteiro para o primeiro nó da lista
    ptr_node fim;    // Ponteiro para o último nó da lista
    int tamanho;     // Tamanho da lista
} lista;
```

Aqui, é definida uma estrutura `Lista` que representa a lista encadeada em si. A lista contém ponteiros para o primeiro (`inicio`) e o último (`fim`) nós da lista, além de uma variável `tamanho` para rastrear o número de elementos na lista.

## `inserir_final()`

```c
void inserir_final(lista * lis) // Obter um dado (provavelmente fornecido em algum lugar do código)
{
   
    int dado = get_dado(); 
    if (dado == -1) 
    {
        return; // Se o dado for inválido, não faz nada
    }

    if (lis->inicio == NULL) // Se a lista estiver vazia
    { 
        // Inicializa o primeiro nó com o dado
        lis->inicio = init_node(lis->inicio, NULL, dado);
        lis->inicio->proximo = lis->inicio; // Faz apontar para si mesmo
        lis->tamanho++;
        lis->fim = lis->inicio;
        return;
    }

    ptr_node navegador = lis->inicio;
    if (navegador->proximo == lis->inicio) // Se houver apenas um elemento na lista
    { 
        // Inicializa um novo nó com o dado
        navegador->proximo = init_node(navegador->proximo, lis->inicio, dado);
        lis->tamanho++;
        lis->fim = navegador->proximo;
    } 
    else // Se houver mais de um elemento na lista
    { 
        while (navegador != lis->fim) { // Percorre a lista até o último elemento
            navegador = navegador->proximo;
        }
        // Inicializa um novo nó no final com o dado
        navegador->proximo = init_node(navegador->proximo, lis->inicio, dado);
        lis->tamanho++;
        lis->fim = navegador->proximo;
    }
}
```

A função `inserir_final` insere um novo elemento no final da lista. Ela começa obtendo um dado usando a função `get_dado`. Se o dado for válido (não for igual a -1), ela procede a inserção.

- Se a lista estiver vazia, ela inicializa o primeiro nó com o dado e faz com que ele aponte para si mesmo. Isso cria uma lista com um único elemento.
- Se a lista já contiver um ou mais elementos, ela percorre a lista até o último nó e cria um novo nó no final, que aponta de volta para o primeiro nó para manter a circularidade da lista.

## `excluir()`

```c
void excluir(lista * lis) 
{
    if (lis->inicio == NULL) // Se a lista estiver vazia
    { 
        system("clear");
        printf("Lista vazia, não há dados para excluir.\n\n");
        cleanBuffer(); // Função para limpar o buffer de entrada (não fornecida aqui)
        getchar();
        return;
    }

    int num = get_dado(); // Obter um dado (provavelmente fornecido em algum lugar do código)
    if (num == -1) 
    {
        return; // Se o dado for inválido, não faz nada
    }

    ptr_node navegador = lis->inicio;
    if (lis->inicio->dado == num) // Se o primeiro elemento for igual ao número a ser excluído
    { 
        if (lis->inicio == lis->fim) // Se houver apenas um elemento na lista
        { 
            free(lis->inicio); // Libera a memória do primeiro nó
            init_lista(lis);    // Inicializa a lista como vazia
        } 
        else if (lis->inicio != lis->fim) // Se houver mais elementos na lista
        { 
            lis->fim->proximo = lis->inicio->proximo;
            lis->inicio = lis->inicio->proximo;
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
        while (navegador->dado != num) 
        {
            if (navegador == lis->fim) 
            {
                printf("Número não encontrado!\n\n");
                cleanBuffer(); // Função para limpar o buffer de entrada (não fornecida aqui)
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
```

A função `excluir` remove um elemento da lista com base em um número fornecido. Ela começa verificando se a lista está vazia e se o número é válido. Em seguida, ela verifica três casos:

- Se o número a ser excluído estiver no primeiro nó, ela lida com dois subcasos:
  - Se houver apenas um elemento na lista, ela libera a memória do primeiro nó e inicializa a lista como vazia.
  - Se houver mais de um elemento na lista, ela ajusta os ponteiros do primeiro nó e libera a memória do nó a ser excluído.
- Se o número estiver no último nó, ela percorre a lista até o penúltimo nó, ajusta os ponteiros e libera a memória do último nó.
- Se o número estiver em algum nó do meio, ela percorre a lista até encontrar o nó com o número correspondente, ajusta os ponteiros e libera a memória desse nó.

Em cada caso, a função manipula os ponteiros para manter a lista encadeada corretamente.