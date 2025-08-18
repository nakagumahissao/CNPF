#include "CNPF.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char* EvaluateFirstDV(const char NineAlfaDigitsValue[], int arraySize) {
    if (arraySize != 9) {
        perror("Número de dígitos incorreto.");
        return NULL;
    }

    char Buffer[10];
    unsigned int charValues[9];
    unsigned int weighted[9];
    unsigned int sumValues = 0;

    for (int i = 0; i < arraySize; i++) {
        Buffer[i] = toupper(NineAlfaDigitsValue[i]);

        if (!(isupper(Buffer[i]) || isdigit(Buffer[i]))) {
            perror("CPF deve conter apenas números e letras.");
            return NULL;
        }

        if (Buffer[i] >= 'A' && Buffer[i] <= 'Z') {
            charValues[i] = (Buffer[i] - 'A') + 10;            
        } else {
            charValues[i] = Buffer[i] - '0';
        }

        weighted[i] = charValues[i] * (10 - i);
        sumValues += weighted[i];
    }

    unsigned int dv = sumValues % 11;

    if (dv < 2) {
        dv = 0;
    } else {
        dv = 11 - dv;
    }

    // Allocate memory for final CNPF + DV + '\0'
    char *finalCNPF = malloc(arraySize + 2);

    if (!finalCNPF) {
        perror("Falha na alocação de memória");
        return NULL;
    }

    strcpy(finalCNPF, Buffer);

    // Append dv as string
    char dvStr[3 ];          // single digit + '\0'
    sprintf(dvStr, "%u", dv);

    strcat(finalCNPF, dvStr);

    return finalCNPF;
}

char* EvaluateSecondDV(const char NineAlfaDigitsValue[], int arraySize) {
    if (arraySize != 10) {
        perror("Número de dígitos incorreto.");
        return NULL;
    }

    char Buffer[11];
    unsigned int charValues[10];
    unsigned int weighted[10];
    unsigned int sumValues = 0;

    for (int i = 0; i < arraySize; i++) {
        Buffer[i] = toupper(NineAlfaDigitsValue[i]);

        if (!(isupper(Buffer[i]) || isdigit(Buffer[i]))) {
            perror("CPF deve conter apenas números e letras.");
            return NULL;
        }

        if (Buffer[i] >= 'A' && Buffer[i] <= 'Z') {
            charValues[i] = (Buffer[i] - 'A') + 10;
        } else {
            charValues[i] = Buffer[i] - '0';
        }

        weighted[i] = charValues[i] * (11 - i);
        sumValues += weighted[i];
    }

    unsigned int dv = sumValues % 11;

    if (dv < 2) {
        dv = 0;
    } else {
        dv = 11 - dv;
    }

    // Allocate memory for final CNPF + DV + '\0'
    char *finalCNPF = malloc(arraySize + 2);

    if (!finalCNPF) {
        perror("Falha na alocação de memória");
        return NULL;
    }

    strcpy(finalCNPF, Buffer);

    // Append dv as string
    char dvStr[3];          // single digit + '\0'
    sprintf(dvStr, "%u", dv);

    strcat(finalCNPF, dvStr);

    return finalCNPF;
}