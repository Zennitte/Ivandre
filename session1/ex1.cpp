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

void removeInvalid(FILE *arq1, FILE *arq2){
    REGISTRO reg;
    while (fread(&reg, sizeof(REGISTRO), 1, arq1))
    {
        if (reg.valido)
        {
            fwrite(&reg, sizeof(REGISTRO), 1, arq2);
        }
    } 
}


int main()
{
    FILE *arq1 = fopen("arq1.dat", "rb");
    FILE *arq2 = fopen("arq2.dat", "wb");
    
    if (arq1 == NULL || arq2 == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }
    
    removeInvalid(arq1, arq2);
    
    fclose(arq1);
    fclose(arq2);

    return 0;
}