# Inicializar

```c
ptr_node inicializar(ptr_node elemento)
{
    // Aloca memória para um novo nó e o inicializa com valores padrão.
    elemento = (ptr_node)malloc(sizeof(ptr_node));
    elemento->dado = '\0'; // Valor padrão para dado (um caractere nulo).
    elemento->proximo = NULL;

    return elemento;
}
```

## Explicação

- **`void inicializar()`**
    - Esta função é usada para alocar memória e inicializar um novo nó.
    - Recebe um nó `elemento` como parâmetro.
    - Aloca memória para um novo nó (`malloc(sizeof(ptr_node))`).
    - Define o campo `dado` do nó como '\0' (um caractere nulo) como um valor padrão.
    - Define o campo `proximo` como `NULL` para indicar que é o último elemento da pilha.
    - Retorna o novo nó inicializado.

# Inserir

```c
void inserir(ptr_node * pilha)
{
    // Cria um ponteiro para um nó e inicializa-o com o valor da pilha passada por referência.
    ptr_node navegador = * pilha;
    int num = -1;

    // Entra em um loop até que o usuário insira um número válido (diferente de -1).
    while (num == -1)
    {
        printf("\nInforme o número que deseja inserir: (0 = Sair)");
        printf("\n\n>>> ");
        scanf("%d", &num);
        limparBuffer(); // Função não definida, presume-se que ela limpa o buffer de entrada.

        // Se o usuário digitar 0, retorna, indicando que não há mais números para inserir.
        if (num == 0)
        {
            return;
        }
    }

    // Verifica se a pilha está vazia.
    if (navegador == NULL)
    {
        // Inicializa a pilha, alocando memória para o primeiro nó.
        *pilha = inicializar(pilha);
        navegador = * pilha;
        navegador->dado = num;
    }
    else
    {
        // Se a pilha não estiver vazia, percorre a pilha até o último elemento.
        while (navegador->proximo != NULL)
        {
            navegador = navegador->proximo;
        }
    
        // Inicializa o próximo elemento da pilha e atribui o valor num a ele.
        navegador->proximo = inicializar(pilha);
        navegador = navegador->proximo;
        navegador->dado = num;
    }
}
```

## Explicação

- **`void inserir()`**
    - Esta função é responsável por inserir um elemento na pilha.
    - Recebe um ponteiro para um ponteiro de nó (`ptr_node *pilha`), que permite acessar e modificar a pilha original.
    - Inicializa um ponteiro `navegador` com o valor da pilha passada por referência.
    - Inicializa `num` com -1 para entrar em um loop que só sairá quando o usuário inserir um número diferente de -1.
    - No loop, solicita ao usuário que insira um número, com a opção de digitar 0 para sair. Isso é feito usando `scanf`.
    - Se o usuário digitar 0, a função retorna, indicando que não há mais números para inserir.
    - Se a pilha estiver vazia (ou seja, `navegador == NULL`), ela é inicializada chamando a função `inicializar`, alocando memória para o primeiro nó da pilha e atribuindo o valor `num` a ele.
    - Caso a pilha não esteja vazia, o código percorre a pilha até o último elemento usando um loop `while`.
    - Inicializa o próximo elemento da pilha e atribui o valor `num` a ele.

# Excluir

```c
void excluir(ptr_node * pilha)
{
    // Cria um ponteiro para um nó e inicializa-o com o valor da pilha passada por referência.
    ptr_node navegador = *pilha;

    // Verifica se a pilha está vazia.
    if (navegador == NULL)
    {
        return; // Retorna se a pilha estiver vazia.
    } 
    else if (navegador->proximo == NULL)
    {
        // Se a pilha tiver apenas um elemento, libera a memória dele e define a pilha como vazia.
        *pilha = NULL;
        free(*pilha);
        return;
    } 
    else
    {
        // Se a pilha tiver mais de um elemento, percorre a pilha até o penúltimo elemento.
        ptr_node atual;
        while (navegador->proximo != NULL)
        {
            atual = navegador;
            navegador = navegador->proximo;
        }
        
        // Remove o último elemento da pilha, ajustando os ponteiros.
        atual->proximo = navegador->proximo;
        navegador = NULL;
        free(navegador);
    }
}
```

## Explicação

- **`void excluir()`**
    - Esta função é responsável por excluir o elemento mais recentemente inserido na pilha.
    - Recebe um ponteiro para um ponteiro de nó (`ptr_node *pilha`), que permite acessar e modificar a pilha original.
    - Inicializa um ponteiro `navegador` com o valor da pilha passada por referência.
    - Verifica se a pilha está vazia. Se estiver, a função simplesmente retorna, indicando que não há nada para excluir.
    - Se a pilha tiver apenas um elemento (ou seja, `navegador->proximo == NULL`), ela é esvaziada definindo o ponteiro da pilha como nulo (`pilha = NULL`) e liberando a memória do único elemento.
    - Se a pilha tiver mais de um elemento, o código percorre a pilha até o penúltimo elemento, mantendo um ponteiro `atual` que aponta para o elemento anterior ao que será excluído.
    - O último elemento é removido ajustando os ponteiros (`atual->proximo = navegador->proximo`), e a memória alocada para ele é liberada.
