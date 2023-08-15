# SistemaNotas
 - Desenvolvido por Caio Gabriel
 - A construção foi feita com a Linguagem C
 - Pode ser utilizados nos seguintes Sistemas Operacionais: Microsoft Windows, Linux e suas distribuições e MacOS

# Resumo
O objetivo do projeto é implementar os conceitos sobre estrutura de dados e linguagem C, para aprendizado e aprofundamento. O sistema de notas foi escolhido por ser um exemplo interessante, onde a estrutura _Aluno_ contém os dados importantes, como a sua disciplina, suas notas, seu nome e sua situação (Aprovação ou Reprovação).

# Informações do Sistema
Modelo inicial do Sistema de Notas baseado no critério de Aprovação da UERJ (Universidade Estadual do Rio de Janeiro). O Sistema calcula a aprovação do aluno baseado nos seguintes critérios:
 - Caso o aluno tenha media maior ou igual a 7.0, é considerado como aprovado;
 - Se a nota for menor que 4.0, o aluno é diretamente reprovado;
 - Se a nota for menor que 7.0 e maior ou igual a 4.0, poderá fazer a prova final.
O programa salva os dados inseridos numa planilha .csv para o usuário final no seguinte formato: "notas_NomeDisciplina.csv".

# Utilização do Sistema
Para a construção do executável em qualquer Sistema Operacional, em seu terminal basta digitar o seguinte comando:
```
gcc -o sistemaNotas sistemaNotas.c
```
