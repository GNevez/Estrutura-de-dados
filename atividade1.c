#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void SortCrescente(int array[], int size) {
    int i, j, minIndex, temp;
    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
}

void imprimirMenorMaior(int array[], int size) {
    int menor = array[0];
    int maior = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < menor) {
            menor = array[i];
        }
        if (array[i] > maior) {
            maior = array[i];
        }
    }
    printf("Menor numero: %d\n", menor);
    printf("Maior numero: %d\n", maior);
}

int main(int argc, char* argv[]) {
    float Media;
    float Soma;

    if (argc <= 1) {
        printf("Erro, Nenhum argumento recebido!");
        return 1;
    }

    int* numeros = malloc((argc - 1) * sizeof(int));
    if (numeros == NULL) {
        printf("Erro de alocacao de memoria!");
        return 1;
    }

    printf("Total de argumentos recebidos: %d \n", argc - 1);
    printf("---------------------------------\n");
    
    for (int f = 1; f < argc; f++) {
        printf("%s \n", argv[f]);
        numeros[f - 1] = atoi(argv[f]);
        Soma += atoi(argv[f]);
    }

    Media = Soma / (argc - 1);

    printf("---------------------------------\n");
    printf("Media dos numeros %2.f \n", Media);

    SortCrescente(numeros, argc - 1);

    printf("---------------------------------\n");
    printf("Ordem dos numeros apos ordenacao: \n");
    for (int f = 0; f < argc - 1; f++) {
        printf("%d \n", numeros[f]);
    }
    printf("---------------------------------\n");
    imprimirMenorMaior(numeros, argc - 1);

    free(numeros);
    return 0;
}
