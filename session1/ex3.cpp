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

REGISTRO getRegister(FILE *arq, int nroUsp){
    REGISTRO reg;

    while (fread(&reg, sizeof(REGISTRO), 1, arq))
    {
        if (reg.NroUSP == nroUsp)
        {
            return reg;
        }
    }
}