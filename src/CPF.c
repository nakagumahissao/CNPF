#include "CPF.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char* EvaluateOldFirstDV(const char NineAlfaDigitsValue[], int arraySize) {
    if (arraySize != 9) {
        perror("Número de dígitos incorreto.");
        return NULL;
    }

    unsigned int charValues[9];
    unsigned int weighted[9];
    unsigned int sumValues = 0;

    for (int i = 0; i < arraySize; i++) {
        if (!isdigit(NineAlfaDigitsValue[i])) {
            perror("Valor não numérico encontrado no numero a ser calculado.");
            return NULL;
        }

        charValues[i] = (unsigned int) NineAlfaDigitsValue[i] - 48;
        weighted[i] = charValues[i] * (10 - i);
        sumValues += weighted[i];
    }

    unsigned int dv = sumValues % 11;

    if (dv < 2) {
        dv = 0;
    }
    else {
        dv = 11 - dv;
    }

    // Allocate memory for final CNPF + DV + '\0'
    char *finalCPF = malloc(arraySize + 2);

    if (!finalCPF) {
        perror("Falha na alocação de memória");
        return NULL;
    }

    strcpy(finalCPF, NineAlfaDigitsValue);

    // Append dv as string
    char dvStr[3 ];          // single digit + '\0'
    sprintf(dvStr, "%u", dv);

    strcat(finalCPF, dvStr);

    return finalCPF;
}

char* EvaluateOldSecondDV(const char NineAlfaDigitsValue[], int arraySize) {
    if (arraySize != 10) {
        perror("Número de dígitos incorreto.");
        return NULL;
    }

    unsigned int charValues[10];
    unsigned int weighted[10];
    unsigned int sumValues = 0;

    for (int i = 0; i < arraySize; i++) {
        if (!isdigit(NineAlfaDigitsValue[i])) {
            perror("Valor não numérico encontrado no numero a ser calculado.");
            return NULL;
        }

        charValues[i] = (unsigned int) NineAlfaDigitsValue[i] - 48;        
        weighted[i] = charValues[i] * (11 - i);
        sumValues += weighted[i];
    }

    unsigned int dv = sumValues % 11;

    if (dv < 2) {
        dv = 0;
    }
    else {
        dv = 11 - dv;
    }

    // Allocate memory for final CNPF + DV + '\0'
    char *finalCPF = malloc(arraySize + 2);

    if (!finalCPF) {
        perror("Falha na alocação de memória");
        return NULL;
    }

    strcpy(finalCPF, NineAlfaDigitsValue);

    // Append dv as string
    char dvStr[3];          // single digit + '\0'
    sprintf(dvStr, "%u", dv);

    strcat(finalCPF, dvStr);

    return finalCPF;
}