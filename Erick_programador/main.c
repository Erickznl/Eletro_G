#include <stdio.h>

 int main(void) {
    int comprimento = 400;
    int altura = 10;
    int area = altura * comprimento;
    printf("a area sera igual a %d multiplicado por %d e o resultado sera %d", altura, comprimento, area);
    float preco = 1.6;
    int total = preco * area;
    printf(", o preco sera %f por %d que o seu resultado ira da %d", preco, area, total);

    return 0;
 }