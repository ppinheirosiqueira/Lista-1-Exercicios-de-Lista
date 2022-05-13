# Lista de Nomes 

Exercício feito para a disciplina de Algoritmo e Estruturas de Dados I do curso de Engenharia de Computação do CEFET - MG, Campus V.

O exercício proposto era o seguinte:

Crie uma lista linear que consiga armazenar um conjunto de 100 nomes quaisquer, os quais serão salvos de forma aleatória. Feito a estrutura crie as seguintes ações:
* Uma função que consiga identificar replicações na lista, ou seja, nomes iguais. Remova todas as réplicas sem mover os "ponteiros".
* Como você gerenciaria os espaços em branco para novas inserções? Qual seria o custo dessas novas inserções?

## Entradas

De acordo com o professor em questão, poderíamos colocar um arquivo com os nomes para serem lidos. Com isso, este programa possui como entrada um arquivo chamado nomes.txt, que deve ser colocado na mesma pasta de seu Makefile. Este arquivo txt contém um nome por linha, como no exemplo abaixo:

![arquivo]

[arquivo]: https://github.com/ppinheirosiqueira/Lista-1-Exercicios-de-Lista/blob/main/Ex2/images/ArquivoTxt.png "Exemplo de Arquivo de Entrada"

## Implementação 

A base dos processos da Lista Linear foi dada pelo professor em questão e podemos encontrar sua implementação [em seu github](https://github.com/mpiress/linear_list). Adaptações foram feitas para atender ao Item da nossa lista, que é uma string ao invés de um inteiro.

Como o objetivo era excluir os nomes da Lista sem mover os "ponteiros", a lista acabaria com espaços vazios onde existiam tais nomes. Uma das perguntas foi exatamente sobre como lidar com tais espaços. Para isso foi criado um auxiliar que contara quantos desses espaços vazios existirão. Sempre que um nome repetido é excluído, esta auxiliar é acrescida de um valor unitário.

O programa começa lendo a entrada (arquivo txt) e inserindo todos os nomes na lista linear. Após este ponto, foi feita a exclusão dos nomes repetidos, rodando nome a nome e comparando-o com os nomes a frente, onde os iguais eram excluídos. Como citado anteriormente, a cada exclusão o auxiliar é acrescentado em 1.

Após as exclusões, foi criado um menu para o usuário escolher seu próximo passo. Neste menu são dadas as seguintes opções:
1. Ver a lista;
2. Inserir um nome na lista;
3. Remover um nome da lista;
4. Sair do programa.

Ver a lista é o procedimento padrão de imprimir a lista alterado para o caso específico do nome da lista.

Para a inserção de um nome na Lista o programa pesquisa na Lista se tal nome já existe, não permitindo a inserção de nomes repetidos. Caso o nome não seja repetido, a inserção depende da auxiliar criada ser de valor nulo ou não. Caso a auxiliar não seja nula, ao adicionar o nome, esta auxiliar possui um decréscimo de 1 em seu valor.

Para a exclusão é simplesmente rodado o nome na Lista a procura, caso o encontre, o nome é excluído da mesma forma que os nomes repetidos foram excluídos, adicionando-se 1 a auxiliar.

## Respostas as questões

O gerenciamento dos espaços vazios se deu pelo auxiliar criado que sendo maior que zero determina que existem espaços vazios para serem preenchidos. Outra forma possível de se resolver tal situação seria criando uma outra lista, porém de inteiros, e o índice da lista de um nome excluído seria adicionado à lista de inteiros como um item. Sabendo-se assim diretamente quais índices possuem estes espaços vazios ao invés de simplesmente saber que eles existem. Caso esta lista fosse vazia, sabe-se que não existem locais vazios na lista. Caso ela não fosse vazia, a inserção seria mais fácil, pegando o primeiro item desta outra lista e adicionando o Nome diretamente no índice que esta segunda lista possuía armazenada. No entanto, como o exercício proposto trabalhava sem a ideia de ponteiros, foi feito por meio da auxiliar.

O custo das inserções depende da situação da Lista no momento. Para o começo, independentemente de existir ou não espaços vazios na Lista, já existe o custo inicial de 'n', pois neste programa procuramos pelo nome na Lista antes de o inserir. Na parte de inserção em si, havendo espaços vazios (Auxiliar maior que zero), o custo será no máximo igual a 'n²', não havendo espaços vazios, seria de 'n'. Pois, no caso de haver espaços vazios, é necessário percorrer o vetor para encontrar tais espaços e inserir o nome naquela posição. Não havendo espaços vazios (Auxiliar igual a zero), o custo é unitário dado que sabemos que é necessário somente a inserção direta na lista.

## Exemplo de saída

Dada a entrada apresentada no setor de ## Entradas, a saída apresentada será:

![saida]

[saida]: https://github.com/ppinheirosiqueira/Lista-1-Exercicios-de-Lista/blob/main/Ex2/images/Saida1.png "Saída do exemplo dado em Entradas"

A partir deste ponto o programa está em suas mãos, porém, demonstrando todas as opções, primeiro tentarei adicionar o nome Pedro, em seguida tentarei adicionar o nome Michel. Obtendo o seguinte resultado:

![saida2]

[saida2]: https://github.com/ppinheirosiqueira/Lista-1-Exercicios-de-Lista/blob/main/Ex2/images/Saida2.png "Saída ao adicionar nomes"

Caso decidamos mostrar a lista neste momento, teremos esta saída:

![saida3]

[saida3]: https://github.com/ppinheirosiqueira/Lista-1-Exercicios-de-Lista/blob/main/Ex2/images/Saida3.png "Demonstrando o Imprimir Lista"

E ao tentar excluir os nomes Pietro, Miguel e Pietro novamente, nesta ordem, obtemos:

![saida4]

[saida4]: https://github.com/ppinheirosiqueira/Lista-1-Exercicios-de-Lista/blob/main/Ex2/images/Saida4.png "Saída ao excluir nomes"

Caso decidamos mostrar a lista neste momento e depois sair do programa, teremos esta saída:

![saida5]

[saida5]: https://github.com/ppinheirosiqueira/Lista-1-Exercicios-de-Lista/blob/main/Ex2/images/Saida5.png "Demonstrando o Imprimir Lista"

## Conclusões

Apesar de cumprir o que se pede, o programa perde muito tempo realizando ações que seriam facilitadas com o uso de ponteiros, sendo necessário o usuário decidir entre um programa que ocupa pouco espaço de memória como este, porém que peca em velocidade, ou um que seja mais rápido que ocupe mais memória.

# Compilação e Execução

O exercício disponibilizado possui um arquivo Makefile cedido pelo professor que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

É recomendado o uso do `make clean` após qualquer pequena mudança feita no código.
