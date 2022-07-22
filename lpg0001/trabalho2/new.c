#include <stdio.h>
#include <stdlib.h>
#include "dep_trabalho2.h"


int main(void){
    printf("Qual a data do evento (dd/mm/aaaa)? ");
    struct Data data_nova;
    char* data_string=input_string(stdin);

    while (!data_str_valida(data_string,&data_nova)) {//Aqui ja salva na avaliacao do while
        printf("Data invalida. Tente de novo: ");
        char* data_string=input_string(stdin);
    }

    free(data_string);
    return 0;
}