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

void updateCourse(FILE *arq, int newCourse, int nroUsp){
    REGISTRO reg;
    fseek(arq, 0, SEEK_SET);

    while (fread(&reg, sizeof(REGISTRO), 1, arq))
    {
        if(reg.NroUSP == nroUsp){
            reg.curso = newCourse;
            fseek(arq, -sizeof(REGISTRO), SEEK_CUR);
            fwrite(&reg, sizeof(REGISTRO), 1, arq);
        }
    }
    
}