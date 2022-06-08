# trabalho-aed-arvore
Trabalho de implementação de arvores da disciplina de aed

Instruções para compilação e execução:

gcc main.c menu.c tree_functions.c -o main.exe

Para executá-lo é possível utilizar apenas:

./main.exe

Se valgrind estiver disponível(para checagem de vazamentos de memória):

valgrind –leak-check=yes /main.exe
