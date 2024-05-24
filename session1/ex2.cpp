#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    int NroUSP; // chave primária
    int curso;
    int estado;
    int idade;
    bool valido; // para exclusão lógica
} REGISTRO;

void copyByEnd(FILE *arq1, FILE *arq2){
    fseek(arq1, 0, SEEK_END);
    long fileSize = ftell(arq1);
    int recordCount = fileSize / sizeof(REGISTRO);
    
    REGISTRO *records = (REGISTRO *) malloc(fileSize);
    
    fseek(arq1, 0, SEEK_SET);
    fread(records, sizeof(REGISTRO), recordCount, arq1);
    
    for (int i = recordCount - 1; i >= 0; i--) {
        fwrite(&records[i], sizeof(REGISTRO), 1, arq2);
    }
    
    free(records);
}
