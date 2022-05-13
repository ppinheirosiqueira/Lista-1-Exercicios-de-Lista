# Máxima Cadeia

Exercício feito para a disciplina de Algoritmo e Estruturas de Dados I do curso de Engenharia de Computação do CEFET - MG, Campus V.

O exercício proposto era o seguinte:

O problema da máxima cadeia. Elabore um programa que receba uma cadeias de DNA. Cada posição da cadeia deve conter um códon, ou seja, uma triade de nucleotídeos -> T, A, G, C. Feito isso, leia de um arquivo uma sequência de nucleotídios (i.e., ACGTGGCTCTCTAACGTACGTACGTACGGGGTTATATTCGAT) e tente identificar a maior cadeia da lista que se relaciona a essa entrada.

## Entradas
----------

Apesar do enunciado citar para o programa receber a cadeia de DNA que seria comparada com o arquivo que possuia a sequência, foi nos dito que poderíamos colocar ambas as entradas como leitura de arquivos. Como o enunciado falava outra coisa, ambas as opções são dadas ao usuário neste programa. A entrada manual é necessário colocar cada nucleotídeo a mão, colocando os códons que se deseja. O programa orienta o usuário, perguntando se este deseja adicionar um nucleotídeo novo ou não.

Para a entrada em arquivo, é necessário somente que coloque a sequência desejada **sem espaços** em um arquivo txt nomeado **input.txt**. O exemplo que mostraremos possui a seguinte entrada: TCTAACCGTACGTAC

Além disso, a sequência de DNA sempre será feita por arquivo. Este, igual o anterior, **não pode ter espaços** e o seu nome precisa ser **dna.txt**. O exemplo que mostraremos a seguir possuia a entrada demonstrada no próprio enunciado do exercício: ACGTGGCTCTCTAACGTACGTACGTACGGGGTTATATTCGAT

## Implementação
-------------- 

Após as entradas já terem sido processadas, começa o algoritmo, que funciona na força bruta. Independente de quais das entradas o usuário escolha, um auxiliar (numEnt) é criado e o seu valor é igual ao número de nucleotídeos da entrada.

Antes da força bruta começar, são criados dois auxiliares do tipo inteiro que iniciam em 0, um que gravará o valor (quantidade de nucleotídeos) da maior cadeia (chamaremos ele aqui de numNucle, como Número de Nuclídeos) e o outro que será meramente um auxiliar deste (auxNucle).

Ele pega a cadeia maior, ou seja, a da entrada dna.txt, e compara com cada entrada do input.txt, ou do primeiro nucleotídeo colocado pelo usuário. Quando essa comparação da positiva, o auxNucle muda para 1, além disso o ponteiro apontando para a cadeia maior,e o ponteiro apontando para a menor são enviados para uma função. Nesta função são comparados os próximos codóns de cada Lista, esse processo acontece até a comparação ser diferente. Para cada comparação igual, o auxNucle é somado em 1. 

Ao retornar desta função, o auxNucle é comparado com o numNucle, e caso ele seja maior, o numNucle recebe o valor de seu auxiliar, além de ponteiros que apontam para a cabeça e para o final desta sequência. Esse processo se segue até que todo a Lista de dna.txt seja passada.

## Exemplo de saída
----------------

A saída com os exemplos de arquivo dados é padrão:

![saida]

[saida]: linkdaimagem "Saída do exemplo dado em Entradas"

Apesar de ser notável que existia o par de nucleotídeos TTC AAC antes, o programa busca pela maior cadeia e por isso a tríade depois acaba prevalecendo.

Caso utilizemos a opção de colocar os nucleotídeos a mão, ou simplesmente alteremos o arquivo para a entrada ACGTGGCTC, teríamos a seguinte saída:

![saida2]

[saida2]: linkdaimagem "Saída ao adicionar nomes"

Demonstrando que o programa consegue encontrar todos os nucleotídeos.

Como não existe muito propósito em imprimir na tela de onde até onde a cadeia foi encontrada já que se encontrou a cadeia toda, foi colocado para imprimir os ponteiros, que é tão inútil quanto demonstrar que encontrou a cadeia de A até B.

# Compilação e Execução

O exercício disponibilizado possui um arquivo Makefile cedido pelo professor que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

É recomendado o uso do `make clean` após qualquer pequena mudança feita no código.