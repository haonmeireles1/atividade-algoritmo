#include <stdio.h>

typedef struct {
    int quantidadePecas;
    float salario;
} Funcionario;

void validaQuantidade(Funcionario *funcionario) {
    printf("Digite a quantidade de pecas fabricadas: ");
    scanf("%d", &(funcionario->quantidadePecas));

}

void calculaSalario(Funcionario *funcionario) {
    float salarioBase = 600.0;
    int quantidadePecas = funcionario->quantidadePecas;

    if (quantidadePecas <= 50) {
        funcionario->salario = salarioBase;
    } else if (quantidadePecas <= 80) {
        funcionario->salario = salarioBase + 0.5 * (quantidadePecas - 50);
    } else {
        funcionario->salario = salarioBase + 0.5 * 30 + 0.75 * (quantidadePecas - 80);
    }
}

void mostraFinal(Funcionario *funcionario) {
    printf("Salario final do funcionario: R$%.2f\n", funcionario->salario);
}

int main() {
    Funcionario funcionario;

    validaQuantidade(&funcionario);
    calculaSalario(&funcionario);
    mostraFinal(&funcionario);

    return 0;
}
