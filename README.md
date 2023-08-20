# Estrutura de dados

# [Pilha](Docs/Pilha.md)

Em computação, uma "pilha" (ou "stack" em inglês) refere-se a uma estrutura de dados fundamental que é usada para armazenar e gerenciar informações. A pilha é organizada de acordo com o princípio do "último a entrar, primeiro a sair" (LIFO - Last-In-First-Out), o que significa que o último elemento adicionado à pilha é o primeiro a ser removido. Pode-se pensar em uma pilha como uma pilha de pratos, onde você adiciona e remove pratos sempre do topo da pilha.

As operações básicas que podem ser realizadas em uma pilha incluem:

1. **Push (Empurrar)**: Isso envolve adicionar um elemento ao topo da pilha.
2. **Pop (Retirar)**: Isso envolve remover o elemento do topo da pilha. O elemento que é retirado é sempre o último que foi adicionado.
3. **Peek (Observar)**: Isso envolve verificar o elemento no topo da pilha sem removê-lo.

As pilhas são usadas em uma variedade de aplicações na computação, incluindo:

- **Controle de Fluxo**: Pilhas são frequentemente usadas em linguagens de programação para gerenciar a chamada de funções e a execução de código. A cada vez que uma função é chamada, um novo "quadro de pilha" é criado, contendo informações sobre essa chamada de função. Quando a função é concluída, seu quadro de pilha é removido.
- **Recursão**: A recursão é um conceito em programação onde uma função chama a si mesma. Uma pilha é usada para rastrear essas chamadas recursivas, permitindo que o programa retorne corretamente quando as chamadas recursivas são concluídas.
- **Expressões Matemáticas**: Pilhas são usadas para avaliar expressões matemáticas na notação polonesa reversa (RPN) ou para converter expressões infixas em pós-fixas (notação polonesa reversa).
- **Navegação em Sites (Back Button)**: Os navegadores da web usam uma pilha para rastrear a história da navegação, permitindo que os usuários retornem às páginas anteriores usando o botão "Voltar".
- **Implementação de Algoritmos**: As pilhas são usadas em algoritmos para armazenar temporariamente informações que podem ser recuperadas posteriormente.
- **Gerenciamento de Memória**: As pilhas são usadas para gerenciar a alocação e desalocação de memória em programas.

Em resumo, uma pilha é uma estrutura de dados importante na computação que permite o armazenamento temporário e o gerenciamento eficiente de informações, seguindo o princípio LIFO. Elas desempenham um papel fundamental em muitos aspectos da programação e do funcionamento interno de sistemas de computadores.

# [Fila](Docs/Fila.md)

Em computação, uma "fila" (ou "queue" em inglês) é outra estrutura de dados fundamental usada para armazenar e gerenciar informações. Ao contrário da pilha, uma fila segue o princípio do "primeiro a entrar, primeiro a sair" (FIFO - First-In-First-Out), o que significa que o primeiro elemento adicionado à fila é o primeiro a ser removido.

Uma fila pode ser imaginada como uma fila de pessoas esperando em uma fila de um caixa, por exemplo. A pessoa que chega primeiro é atendida primeiro, e assim por diante.

As operações básicas em uma fila incluem:

1. **Enqueue (Entrar na Fila)**: Adicionar um elemento ao final da fila.
2. **Dequeue (Sair da Fila)**: Remover o elemento do início da fila. O elemento que está na frente da fila é o primeiro a ser removido.
3. **Front (Frente da Fila)**: Visualizar o elemento no início da fila sem removê-lo.

Assim como as pilhas, as filas têm várias aplicações na computação, incluindo:

- **Processamento de Tarefas**: Filas são frequentemente usadas para gerenciar tarefas ou trabalhos que precisam ser processados em ordem. Um exemplo disso é uma fila de impressão, onde os trabalhos de impressão são processados na ordem em que foram enfileirados.
- **Gerenciamento de Recursos Compartilhados**: Em sistemas multitarefa, as filas são usadas para gerenciar o acesso a recursos compartilhados, como impressoras, memória compartilhada ou dispositivos de entrada e saída.
- **Algoritmos de Busca e Exploração**: Filas são usadas em algoritmos de busca, como a busca em largura (BFS), para explorar nós ou estados em uma estrutura de dados hierárquica, como uma árvore.
- **Escalonamento de Processos**: Em sistemas operacionais, filas podem ser usadas para escalonar processos, decidindo qual processo deve ser executado em seguida.
- **Breadth-First Traversal**: Filas são usadas para percorrer estruturas de dados hierárquicas, como árvores ou grafos, em ordem de largura.
- **FIFO Buffers**: Em comunicação de dados, filas podem ser usadas como buffers FIFO para armazenar temporariamente dados antes de serem transmitidos ou processados.

Em resumo, uma fila é uma estrutura de dados importante na computação que segue o princípio FIFO, permitindo o armazenamento ordenado e o gerenciamento eficiente de informações. Elas desempenham um papel fundamental em muitas áreas da programação e do funcionamento de sistemas de computadores.

# Documentação dos códigos

[Pilha](Estrutura%20de%20dados%204b68940048bc4603ad7071ed1b1e57e6/Pilha%20995571e6bc6f4d64a658ae636c24be60.md)

[Fila](Estrutura%20de%20dados%204b68940048bc4603ad7071ed1b1e57e6/Fila%205bfa533c62734f3d9204118440221879.md)