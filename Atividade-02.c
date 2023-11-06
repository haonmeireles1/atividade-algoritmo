#include <stdio.h>

typedef struct {
    char sexo;
    float salario;
} Assalariado;

char validaSexo() {
    char sexo;
    do {
        printf("Informe o sexo (M para masculino, F para feminino): ");
        scanf(" %c", &sexo);
    } while(sexo != 'M' && sexo != 'F');
    return sexo;
}

float validaSalario() {
    float salario;
    do {
        printf("Informe o salário: ");
        scanf("%f", &salario);
    } while(salario <= 1);
    return salario;
}

char* classificaSalario(float salario) {
    if (salario > 1400) {
        return "Acima";
    } else if (salario == 1400) {
        return "Igual";
    } else {
        return "Abaixo";
    }
}

void mostraClassifica(Assalariado assalariado) {
    printf("Sexo: %c\n", assalariado.sexo);
    printf("Salário: R$%.2f\n", assalariado.salario);
    printf("Classificação em relação ao salário mínimo: %s\n\n", classificaSalario(assalariado.salario));
}

int main() {
    int totalAbaixoSalarioMinimo = 0;
    int totalAcimaSalarioMinimo = 0;
    Assalariado assalariado;

    while(1) {
        assalariado.sexo = validaSexo();
        assalariado.salario = validaSalario();
        mostraClassifica(assalariado);

        if (assalariado.salario < 1400) {
            totalAbaixoSalarioMinimo++;
        } else if (assalariado.salario > 1400) {
            totalAcimaSalarioMinimo++;
        }
    }

    printf("Total de assalariados abaixo do salario minimo: %d\n", totalAbaixoSalarioMinimo);
    printf("Total de assalariados acima do salario minimo: %d\n", totalAcimaSalarioMinimo);

    return 0;
}
