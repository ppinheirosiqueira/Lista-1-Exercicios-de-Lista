# Lista de Nomes 

Exercício feito para a disciplina de Algoritmo e Estruturas de Dados I do curso de Engenharia de Computação do CEFET - MG, Campus V.

O exercício proposto era o seguinte:

Em uma lista A temos um conjunto de elementos inteiros positivos ou não {a<sub>1</sub>, a<sub>2</sub> , ... , a<sub>n</sub>}. Elabore uma função que consiga encontrar neste conjunto a máxima soma.

## Entradas

Como não existe nenhum valor especial nas entradas, então antes do programa rodar em si, só é pedido o tamanho deste vetor de inteiros e qual o valor máximo que ele deseja que os inteiros dessa Lista assumam. Ambos esses valores precisam ser inteiros e positivos.

![entrada]

[entrada]: https://github.com/ppinheirosiqueira/Lista-1-Exercicios-de-Lista/blob/main/Ex4/images/Entradas.png "Exemplo das entradas"

## Implementação 

Após algumas tentativas frustradas de tentar algo mais otimizado e falhar no uso de ponteiros (somente perto da entrega fiquei sabendo da possibidade de fazer com Lista Linear). A implementação foi a famosa força bruta. Não existe muito o que se falar do algoritmo implementado. A maior soma do vetor é encontrada porque todas as somas possíveis são feitas da maneira mais direta possível em uma sequência de loops.


## Exemplo de saída

Dada a entrada apresentada no setor de ## Entradas, a saída apresentada será:

![saida]

[saida]: https://github.com/ppinheirosiqueira/Lista-1-Exercicios-de-Lista/blob/main/Ex4/images/Saida1.png "Saída do exemplo dado em Entradas"

Não existe muito mais a se mostrar deste programa, não é fácil replicar exatamente o resultado já que os números são gerados aleatoriamente. 

# Compilação e Execução

O exercício disponibilizado possui um arquivo Makefile cedido pelo professor que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

É recomendado o uso do `make clean` após qualquer pequena mudança feita no código.
