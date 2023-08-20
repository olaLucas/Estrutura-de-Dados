# Inicializar

```c
// Função para inicializar um novo nó da fila.
// Recebe um nó 'elemento' como parâmetro.
// Retorna o nó inicializado.
ptr_node inicializar(ptr_node elemento)
{
    elemento = (ptr_node)malloc(sizeof(ptr_node)); // Aloca memória para um novo nó.
    elemento->dado = 0; // Define o campo 'dado' do nó como 0.
    elemento->proximo = NULL; // Define o ponteiro 'proximo' como nulo (indicando o final da fila).

    return elemento; // Retorna o nó inicializado.
}
```

## Explicação

- **`void inicializar()`**
    - Esta função é responsável por criar e inicializar um novo nó da fila.
    - Ela recebe um nó `elemento` como parâmetro, que será inicializado.
    - A função aloca dinamicamente memória para um novo nó com o tamanho de `ptr_node` usando `malloc`.
    - Define o campo `dado` do nó como 0, presumivelmente um valor padrão.
    - Define o campo `proximo` como NULL, indicando que este é o último nó da fila.
    - Retorna o nó inicializado.

# Inserir

```c
// Função para inserir um elemento na fila.
// Recebe um ponteiro para um ponteiro de nó 'fila'.
void inserir(ptr_node * fila)
{
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

    ptr_node navegador = * fila; // Cria um ponteiro 'navegador' apontando para a fila.

    // Verifica se a fila está vazia.
    if (navegador == NULL)
    {
        // Inicializa a fila, alocando memória para o primeiro nó e atribuindo o valor 'num'.
        *fila = inicializar(*fila);
        navegador = * fila;
        navegador->dado = num;
    }
    else
    {
        // Se a fila não estiver vazia, percorre a fila até o último elemento.
        while (navegador->proximo != NULL)
        {
            navegador = navegador->proximo;
        }

        // Inicializa o próximo elemento da fila e atribui o valor 'num' a ele.
        navegador->proximo = inicializar(*fila);
        navegador = navegador->proximo;
        navegador->dado = num;
    }
}
```

## Explicação

- **`void inserir()`**
    - Esta função é responsável por inserir um elemento na fila.
    - Recebe um ponteiro para um ponteiro de nó `fila`, permitindo acesso e modificação da fila original.
    - Inicializa `num` com -1 para entrar em um loop que só sai quando o usuário insere um número diferente de -1.
    - Dentro do loop, solicita ao usuário que insira um número com a opção de digitar 0 para sair, usando `scanf`.
    - Se o usuário digitar 0, a função retorna, indicando que não há mais números para inserir.
    - Inicializa um ponteiro `navegador` com o valor da fila passada por referência.
    - Verifica se a fila está vazia (ou seja, `navegador == NULL`).
    - Se a fila estiver vazia, inicializa a fila alocando memória para o primeiro nó e atribui o valor `num` a ele.
    - Se a fila não estiver vazia, percorre a fila até o último elemento usando um loop `while`.
    - Inicializa o próximo elemento da fila e atribui o valor `num` a ele.

# Excluir

```c
// Função para excluir o elemento mais antigo da fila.
// Recebe um ponteiro para um ponteiro de nó 'fila'.
void excluir(ptr_node * fila)
{
    ptr_node navegador = *fila; // Cria um ponteiro 'navegador' apontando para a fila.

    if (*fila == NULL) // Verifica se a fila está vazia.
    {
        return; // Retorna se a fila estiver vazia.
    }
    else if (navegador->proximo == NULL) // Se a fila tiver apenas um elemento.
    {
        *fila = NULL; // Esvazia a fila definindo o ponteiro da fila como nulo.
        free(*fila); // Libera a memória do único elemento.
        return;
    }
    else if (navegador->proximo != NULL) // Se a fila tiver mais de um elemento.
    {
        ptr_node atual = navegador;

        navegador = navegador->proximo; // Move o ponteiro 'navegador' para o próximo nó.
        atual->dado = navegador->dado; // Copia o 'dado' do próximo nó para o nó atual.
        atual->proximo = navegador->proximo; // Atualiza o ponteiro 'proximo' do nó atual.

        free(navegador); // Libera a memória do próximo nó.
    }
}
```

## Explicação

- **`void excluir()`**
    - Esta função é responsável por excluir o elemento mais antigo da fila.
    - Recebe um ponteiro para um ponteiro de nó `fila`, permitindo acesso e modificação da fila original.
    - Inicializa um ponteiro `navegador` com o valor da fila passada por referência.
    - Verifica se a fila está vazia (ou seja, `fila == NULL`).
    - Se a fila estiver vazia, a função simplesmente retorna, indicando que não há nada para excluir.
    - Se a fila tiver apenas um elemento (ou seja, `navegador->proximo == NULL`), a função esvazia a fila definindo o ponteiro da fila como nulo (`fila = NULL`) e libera a memória do único elemento usando `free`.
    - Se a fila tiver mais de um elemento, a função copia o valor do próximo nó para o nó atual e ajusta os ponteiros para excluir o próximo nó da fila. Em seguida, a memória alocada para o próximo nó é liberada com `free`.
