# Lista de Nomes 

Exercício feito para a disciplina de Algoritmo e Estruturas de Dados I do curso de Engenharia de Computação do CEFET - MG, Campus V.

O exercício proposto era o seguinte:

Faça um diagrama para representar uma inserção, remoção e pesquisa em uma lista linear.

## Respostas as questões
--------------------

Esse exercício não possui qualquer tipo de implementação.

Uma Lista LLinear é formada por meramente uma dupla de ponteiros de inteiros, o primeiro e o último e um vetor. Este vetor pode ser de qualquer estrutura que seja necessária para a resolução do programa que está sendo feito. Por via de regra, o ponteiro de primeiro da Lista aponta para a primeira célula deste vetor, enquanto o último aponta sempre para a próxima célula do último item que possui dados. Segue abaixo a imagem exemplificando melhor.

![lista]

[arquivo]: linkdaimagem "Exemplo de Lista"

Para inserirmos um valor em uma Lista, é necessário meramente aproveitar o ponteiro de último, inserir o conteúdo que será adicionado na célula que ele já está apontando e em seguida jogar o ponteiro de último para a próxima célula. Isso claro, caso o tamanho do vetor já não seja o máximo tamanho do vetor possível na Lista. Segue abaixo um diagrama do processo.

![lista]

[arquivo]: linkdaimagem "Diagrama Inserir"

Para removermos um valor de uma lista, é necessário primeiro checar se a lista está vazia. Caso não esteja, procurar pelo valor até o encontrar. Caso o encontre, são feitas várias trocas com este elemento até levá-lo para a última posição da lista atual, e então o ponteiro de último é decrementado em um, assim, quando o próximo item for inserido, simplesmente irá sobrescrever o valor deste elemento.

![lista]

[arquivo]: linkdaimagem "Diagrama Excluir"

A pesquisa não possui nada de especial, tanto que ela existe no Excluir. A pesquisa numa lista linear é meramente percorrer todos os valores desta lista até encontrar o que deseja, ou nunca encontrar.