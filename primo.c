#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    int num = atoi(argv[1]), i, result = 0;

    if (argc <= 1) {
        printf("Nenhum numero fornecido como argumento.\n");
        return 1;
    }

    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            result++;
            break;
        }
    }

    if (result == 0)
        printf("E Primo\n");
    else
        printf("Não e primo\n");

    return 0;
}