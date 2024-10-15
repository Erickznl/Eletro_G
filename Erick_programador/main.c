#include <stdio.h>
//3.1

void calcular_custo_copiadora() {
    int a;
    float b;  

    printf("Quantas folhas foram copiadas?");
    scanf("%d", &a);

    if (a >= 100) {
        b = a * 0.20;
    } else {
        b = a * 0.25;
    }

    printf("O valor total a ser pago sera: %.2f\n", b); 
}
// 3.2

void verificar_manutencao_maquina() {
    int a, b, c;

    printf("Qual a quantidade de pecas produzidas? ");
    scanf("%d", &a);

    printf("Qual foi o numero de pecas com defeito? ");
    scanf("%d", &b);

    c = a * 10 / 100;  

    if (b >= c) {
        printf("A maquina precisa de manutencao\n");
    } else {
        printf("Nao precisa de manutencao\n");
    }
}

//3.3
void categoria_por_idade() {
    int a;

    printf("Qual sua idade? ");
    scanf("%d", &a);

    if (a <= 10) {
        printf("Sua categoria eh infantil!!\n");
    } else if (a <= 17) {
        printf("Sua categoria eh jovem!!\n");
    } else {
        printf("Sua categoria eh idosa!!\n");
    }
}

// 3.4
void classificar_triangulo() {
    int a, b, c;

    printf("Informe os tres lados do triangulo:\n");
    scanf("%d %d %d", &a, &b, &c);  

    if (a == b && b == c) {
        printf("O triangulo eh equilatero!\n");
    } else if (a == b || b == c || a == c) {
        printf("O triangulo eh isosceles!\n");
    } else {
        printf("O triangulo eh escaleno!\n");
    }
}


int main() {
    int opcao;

    printf("Escolha uma opcao:\n");
    printf("1 - Calcular custo da copiadora\n");
    printf("2 - Verificar manutencao da maquina\n");
    printf("3 - Categoria por idade\n");
    printf("4 - Classificar triangulo\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            calcular_custo_copiadora();
            break;
        case 2:
            verificar_manutencao_maquina();
            break;
        case 3:
            categoria_por_idade();
            break;
        case 4:
            classificar_triangulo();
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }

    return 0;
}
