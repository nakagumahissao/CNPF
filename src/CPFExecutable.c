#include "CNPF.h"
#include "CPF.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    // For CNPF    
    const char* cnpf = "156a1220b";
    char * str = NULL;
    str = EvaluateFirstDV(cnpf, 9);
    printf("%.3s.%.3s.%.3s-%.1s\n", str, str + 3, str + 6, str + 9);

    str = EvaluateSecondDV(EvaluateFirstDV(cnpf, 9), 10);
    printf("%.3s.%.3s.%.3s-%.2s\n", str, str + 3, str + 6, str + 9);

    // For CPF
    const char* cpf = "569122009";
    char * stra = NULL;
    stra = EvaluateOldFirstDV(cpf, 9);
    printf("%.3s.%.3s.%.3s-%.1s\n", stra, stra + 3, stra + 6, stra + 9);

    stra = EvaluateOldSecondDV(EvaluateOldFirstDV(cpf, 9), 10);
    printf("%.3s.%.3s.%.3s-%.2s\n", stra, stra + 3, stra + 6, stra + 9);
}