#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int NroUSP; // chave primária
    int curso;
    int estado;
    int idade;
    bool valido; // para exclusão lógica
} REGISTRO;

bool insertUniqueRegister(FILE *arq, REGISTRO newRegister){
    REGISTRO reg;

    while (fread(&reg, sizeof(REGISTRO), 1, arq))
    {
       if (reg.NroUSP == newRegister.NroUSP && reg.valido)
       {
            printf("Chave Duplicada encontrada");
            return false;
       }      
    }

    fseek(arq, 0, SEEK_END);
    fwrite(&newRegister, sizeof(REGISTRO), 1, arq);
    return true;
}