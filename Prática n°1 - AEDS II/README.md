<p align="center"> 
  <img src="Img/image.png" alt="CEFET-MG" width="100px" height="100px">
</p>


<h1 align="center" font-size="200em"><b>Prática N°1 - Árvores Binárias</b></h1>


<div align="center">

![Ubuntu](https://img.shields.io/badge/ubuntu-orange?style=for-the-badge&logo=ubuntu&logoColor=white)
![Static Badge](https://img.shields.io/badge/makefile-orangered?style=for-the-badge&logoColor=white)
![VS Code](https://img.shields.io/badge/vs%20code-royalblue?style=for-the-badge&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-blue?style=for-the-badge&logo=c%2B%2B&logoColor=white)


</div>

<br>

## Introdução

### Sobre os Exercícios:
<p align="justify">
Neste período, somos apresentados a novas estruturas de dados, as árvores. No contexto desta estrutura, o professor da disciplina, Michel Pires, propoe alguns exercícios de fixação da matéria, principalmente da base - que é a arvore binária - para que possamos avançar posteriormente e entender melhor outros tipos de árvore, como a AVL, RedBLack e as inumeras variações da tipo B.

Portanto, esta parte do reposítorio contém alguns comentários sobre implementações, possíveis dificuldades e tentativas na solução dos exercícios.
</p>

<br>

## Propostas

### Exercício 01:

<p align="justify">
O exercício 1 requisita a criação de árvores binárias e a manipulação delas mediante a remoção de certos elementos. A maior dificuldade aqui são as remoções que em alguns casos passam pelas regras do predecessor/sucessor. É importante lembrar que, na implementação dessa estrutura, deve-se usar somente um dos dois métodos de remoção.
</p>

### Exercício 02:
<p align="justify">
O exercício 02 pede a criação de um código de árvore binária para que faça-se alguns estudos sobre o desbalanceamento nesse tipo de árvore, já que diferente das AVL, RedBlacks ou B, essa árvore não possui regras de rebalanceamento. Dessa forma, além da implementação das funções básicas da árvore, como inserção, remoção e vizualização - que pode ser feita de várias formas - também foi feita a implementação da função que calcula a altura máxima da árvore. Isso foi feito porque, na implementação, são feitas duas árvores, uma delas propositalmente desbalanceada, e dessa forma pode-se observar os impactos do desbalanceamento em uma árvore.
</p>

### Exercício 03:
<p align="justify">
O exercício 03 pede também a criação de um código de árvore, mas neste caso uma árvore de palavras. sua implementação é basicamente a mesma da árvore anterior, mas aqui precisa-se implementar características de autocompletar/sugestões inteligentes, e esse é o maior no contexto deste exercício.
</p>

## Comentários

### Exercício 01:
<p align="justify">
Esse exercicio foi, para mim, o mais tranquilo. Não so ajudou a entender a estrutura base e o pensamento sobre como o programa deveria ser estruturado, mas também montou a base para entender vizualmente o funcionamento das remoções, e como isso poderia afetar o balanceamento da árvore.
</p>

### Exercício 02:
<p align="justify">
Esse exercício foi minha primeira expeririência com o código da árvore em si. Como sempre, a prática apresenta um olhar novo sobre o que foi aprendido na teoria, e permitiu particularmente vizualizar o quão genial é essa estrutura, como ela pode ser aplicada pra diversas situações e, finalmente, ajudou a entender como algorítmos de busca binária funcionam.

Sobre a prerrogativa de que a árvore desbalanceada sofre possue um custo 39% maior, isso é notavel na maioria dos testes. O teste que foi deixado como padrão mostra que, em relação a árvore feita aleatoriamente que possui 5 níveis, a árvore tendenciada possui 7 níveis. Fazendo um arredondamento simples, somente o aumento de nível ja apresenta 40% de aumento. Em termos de custo computacional para o caminhamento dentro da estrutura, que em árvores se apresenta como log(n), o aumento foi de cerca de 20%. Pensando em uma massa de dados bem maior, ja que me limitei a 20 unidades nos testes, esse desbalanceamento seria bem mais significativo, portanto é razoavel esperar que os 20% representem um valor nada irrisório no fim, ou talvez ate aumente.
</p>

### Exercício 03:
<p align="justify">
Este exercício, como esperado, foi o mais díficil. Uma das muitas ideias que eu tive, e que foi a que cheguei mais perto de conseguir implementar, foi o uso de substrings. Durante uma das competições de programaçao competitiva, tive um problema que me levou a esta mesma solução, que na época implementei sem sucesso. Desta vez, como já tive algum contato, consegui fazer algo próximo da solução que eu tinha em mente.

O que pensei foi: Implemente a árvore de strings e carregue nela os dados. Com os dados carregados, a cada nova inserção use uma função que passa por toda a árvore e confere se existe, nas palavras já na árvore, uma substring da palavra cuja inserção esta sendo feita. Caso exista, essa palavra é adicionada à uma lista, que no final da inserção é printada no terminal como as recomendações/sugestões.

Embora tenha sido uma solução bem engenhosa, ela não lidou perfeitamente como esperado. Em minha ideia, eu espera que a função que eu utilizei para a conferência de substrings fosse implementada para buscar todas as substrings possíveis, descartando, claro, caracter por caracter. Dessa forma caso fosse digitado "medo" o programa recomendaria "dor", "meu", "metido"... O que acontece na realidade é que o programa procura se toda a string "medo" existe em alguma das palavras já carregadas na árvore.

Apesar de não ter sido um sucesso total, considero que este foi um pontapé inicial para pensa em soluções mais elegantes, como a utilização de prefixos, que é a ideia da árvore tipo Trie. Não de forma aleatória, foram esses problemas que me levaram a conhecer ainda uma nova variação dessa estrutura, então considero que embora o programa não tenha funcionado exatamento como o esperado, ainda houve aproveitamento das minhas dificuldades encontradas.
</p>

## Conclusão
<p align="justify">
Os exercícios propostos proporcionaram uma base sólida para o entendimento e aplicação de árvores binárias e suas variações. Cada exercício trouxe desafios únicos, que não apenas reforçaram conceitos teóricos, mas também estimularam a reflexão prática e a busca por soluções criativas e eficientes.

No geral, a experiência proporcionada por esses exercícios foi enriquecedora e desafiadora. Ao longo do processo, foi possível não apenas entender os conceitos de árvores binárias, mas também explorar diferentes abordagens e identificar áreas para aprimoramento.
</p>

## Compilação e Execução:

 Especificações da máquina em que o código foi rodado:
  * Processador Intel Core i5, 10th Gen;
  * Sistema Operacional Windows 11 Home;
  * Terminal do WSL: Ubuntu 22.04.5;
  * 16GB de RAM.

| Comando                |  Função                                                                                           |                     
  | -----------------------| ------------------------------------------------------------------------------------------------- |
  |  `make clean`          | Apaga a última compilação realizada contida na pasta build.                                       |
  |  `make`                | Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build.          |
  |  `make run`            | Executa o programa da pasta build após a realização da compilação.                                |


<br>

## Contato:

**Jader Oliveira Silva**  
[![Static Badge](https://img.shields.io/badge/%7C%200livas-black?style=flat-square&logo=github)](https://github.com/0livas)
[![Static Badge](https://img.shields.io/badge/%7C%20jaderoliveira28%40gmail.com%20%20-black?style=flat-square&logo=gmail)](mailto:jaderoliveira28@gmail.com)
