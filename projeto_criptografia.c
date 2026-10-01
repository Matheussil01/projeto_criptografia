#include <stdio.h>
#include <string.h>

int main() {

    char palavra[] = "coracao";
    int shift = 3;
    int tipoSequencia = 3;

    int sequencia[15];
    char camada1[16];
    char resultado[16];

    int quantidade;
    int i;

    FILE *arquivo;

    quantidade = strlen(palavra);

    if (quantidade > 15) {
        printf("A palavra possui mais de 15 letras.\n");
        return 1;
    }

    if (tipoSequencia == 1) {

        for (i = 0; i < 15; i++) {
            sequencia[i] = i + 1;
        }

    } else if (tipoSequencia == 2) {

        sequencia[0] = 1;

        for (i = 1; i < 15; i++) {
            sequencia[i] = sequencia[i - 1] * 2;
        }

    } else if (tipoSequencia == 3) {

        sequencia[0] = 1;
        sequencia[1] = 1;

        for (i = 2; i < 15; i++) {
            sequencia[i] = sequencia[i - 1] + sequencia[i - 2];
        }

    } else if (tipoSequencia == 4) {

        int numero = 2;
        int contador = 0;
        int primo;
        int j;

        while (contador < 15) {

            primo = 1;

            for (j = 2; j < numero; j++) {

                if (numero % j == 0) {
                    primo = 0;
                    break;
                }
            }

            if (primo == 1) {
                sequencia[contador] = numero;
                contador++;
            }

            numero++;
        }
    }

    printf("Projeto de Criptografia\n\n");

    printf("Palavra: %s\n", palavra);
    printf("Quantidade de letras: %d\n", quantidade);
    printf("SHIFT: %d\n", shift);
    printf("Tipo da sequencia: %d\n", tipoSequencia);

    if (tipoSequencia == 1) {
        printf("Sequencia: PA\n");
    } else if (tipoSequencia == 2) {
        printf("Sequencia: PG\n");
    } else if (tipoSequencia == 3) {
        printf("Sequencia: Fibonacci\n");
    } else {
        printf("Sequencia: Numeros Primos\n");
    }

    printf("\nSequencia utilizada: ");

    for (i = 0; i < quantidade; i++) {

        printf("%d", sequencia[i]);

        if (i < quantidade - 1) {
            printf(", ");
        }
    }

    printf("\n\n");

    for (i = 0; i < quantidade; i++) {

        camada1[i] =
            ((palavra[i] - 'a' + shift) % 26) + 'a';
    }

    camada1[quantidade] = '\0';

    printf("Camada 1 - Cifra de Cesar: %s\n", camada1);

    for (i = 0; i < quantidade; i++) {

        resultado[i] =
            ((camada1[i] - 'a' + sequencia[i]) % 26) + 'a';
    }

    resultado[quantidade] = '\0';

    printf("Camada 2 - Resultado: %s\n", resultado);

    arquivo = fopen("resultado_criptografia.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    fprintf(arquivo, "Projeto de Criptografia\n\n");
    fprintf(arquivo, "Palavra original: %s\n", palavra);
    fprintf(arquivo, "Quantidade de letras: %d\n", quantidade);
    fprintf(arquivo, "SHIFT: %d\n", shift);
    fprintf(arquivo, "Tipo da sequencia: %d\n", tipoSequencia);

    if (tipoSequencia == 1) {
        fprintf(arquivo, "Sequencia: PA\n");
    } else if (tipoSequencia == 2) {
        fprintf(arquivo, "Sequencia: PG\n");
    } else if (tipoSequencia == 3) {
        fprintf(arquivo, "Sequencia: Fibonacci\n");
    } else {
        fprintf(arquivo, "Sequencia: Numeros Primos\n");
    }

    fprintf(arquivo, "Sequencia utilizada: ");

    for (i = 0; i < quantidade; i++) {

        fprintf(arquivo, "%d", sequencia[i]);

        if (i < quantidade - 1) {
            fprintf(arquivo, ", ");
        }
    }

    fprintf(arquivo, "\n");
    fprintf(arquivo, "Camada 1 - Cifra de Cesar: %s\n", camada1);
    fprintf(arquivo, "Camada 2 - Resultado: %s\n", resultado);
    fprintf(arquivo, "Palavra codificada: %s\n", resultado);

    fclose(arquivo);

    printf("\nArquivo resultado_criptografia.txt criado com sucesso!\n");

    return 0;
}