#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dep_trabalho2.h"

int main() {

    /*Capa*/
    printf(
        "=======================================================================\n"
        "||        +      _     ____  *____  ___   ___   ___  _               ||\n"
        "||*             | |   |  _ \\ / ___|/ _ \\ / _ \\ / _ \\/ |        *     ||\n"
        "||        *     | |   | |_) | |  _| | | | | | | | | | |              ||\n"
        "||              | |___|  __/| |_| | |_| | |_| | |_| | |     +      * ||\n"
        "||    +         |_____|_|    \\____|\\___/ \\___/ \\___/|_|              ||\n"
        "||         _____          _    *      _ _   *         ____       +   ||\n"
        "||        |_   _| __+__ _| |__   __ _| | |__   ___   |___ \\          ||\n"
        "||   *      | || '__/ _` | '_ \\ / _` | | '_ \\ / _ \\    __) |      *  ||\n"
        "||          | || | | (_| | |_) | (_| | | | | | (_) |  / __/          ||\n"
        "||       *  |_||_|  \\__,_|_.__/ \\__,_|_|_| |_|\\___/  |_____|   *     ||  \n"
        "||+               *                         +           (patorjk.com)||\n"//Estilo standard
        "=======================================================================\n"
        "Aluno: Luiz Gustavo Cordeiro\n"
        "Semestre: 2022-1\n"
        "Professor: Rui Tramontin\n"
        "=======================================================================\n"
    );

    /*Explicação*/

    printf(
        "Este programa cria uma agenda de eventos.\n"
        "=======================================================================\n"
    );

    
    int i;//Indices
    int opcao;//opcoes gerais
    char c;

    //Abre o arquivo de agendas
    FILE *agendas = fopen("agendas.txt", "rt");
    char* nome_agenda_atual;
    int numero_de_agendas;
    char** lista_de_agendas;

    int numero_de_eventos;
    struct Evento* lista_de_eventos;

    if (agendas == NULL) {
        printf(
            "Arquivo de agendas nao encontrado.\n"
            "Gerando um novo arquivo.\n"
        );

        lista_de_agendas=malloc(0);//lista vazia
        opcao=0;//Para criar uma nova agenda
        numero_de_agendas=0;
        fclose(agendas);
    }
    else {
        //O arquivo de agendas existe.
        //Vamos pegar a primeira linha, que tem o numero de agendas salvas.
        fscanf(agendas,"%d",&numero_de_agendas);
        fgetc(agendas);
        /*
            A nova linha nao foi lida no fscanf... Diferenca do fscanf e do fgetc
            Por isso a linha acima
        */

        lista_de_agendas=malloc(numero_de_agendas*sizeof(char*));

        if (numero_de_agendas==0) {
            printf("Nao ha agendas salvas.\n");
            opcao=0;
            fclose(agendas);
        }
        else {
            //Ha agendas salvas.

            /*
                Vamos fazer um vetor com os nomes das agendas.
            */

            for (i=0;i<numero_de_agendas;i++) {
                lista_de_agendas[i]=input_string(agendas);
            }
            /*
                Aqui, poderiamos fazer uma verificacao de integridade...
            */

            if (numero_de_agendas==1){
                printf("Ha 1 agenda gravada:\n");
            }
            else {
                printf("\nHa %d agendas gravadas:\n",numero_de_agendas);
            }

            for (i=0;i<numero_de_agendas;i++) {
                printf("%d: %s\n", i+1,lista_de_agendas[i]);
            }

            fclose(agendas);

            printf(
                "\nEscolha uma agenda para carregar (pelo numero), ou \"0\" (sem aspas) para\n"
                "criar uma nova agenda: "
            );

            scanf("%d",&opcao);

            while (opcao<0 || opcao>numero_de_agendas) {
                printf("Opcao invalida. Tente novamente: ");
                scanf("%d",&opcao);
            }

            //Limpa o stdin, que esta com um '\n'
            c=getchar();
            /*while ( (c!=EOF) && (c!='\n') ) {
                printf("yeah");
                c=fgetc(stdin);
            }*/

            //stdin limpo. Dá-lhe!
        }
    }

    if (opcao!=0) {
        nome_agenda_atual=lista_de_agendas[opcao-1];
    }
    else {//opcao==0
        //Poe espaco para mais um nome.
        lista_de_agendas=realloc(lista_de_agendas,(numero_de_agendas+1)*sizeof(char*));
        printf("\nDigite um nome para a nova agenda: ");
        while (1) {
            nome_agenda_atual=input_string(stdin);
            //Aqui poderia por alguma verificacao de bom nome. Nao tenho tempo pra isso.

            if (numero_de_agendas>0) {//Verifica se a agenda ja existe
                //Verifica se e < primeira agenda
                if (strcmp(nome_agenda_atual,lista_de_agendas[0])<0) {
                    break;
                }

                //Caso contrario, vamos achar o maior indice que e <=
                int left=0,right=numero_de_agendas-1,m;
                while (right-left>1) {//intervalos de tamanho >=2
                    //Considera o ponto intermediario,arredondado para baixo
                    m=(left+right)/2;
                    if (strcmp(nome_agenda_atual,lista_de_agendas[m])<=0) {
                        //Comeca comparando a direita, pois o arredondamento e para baixo (m<right sempre!)                        
                        right=m;
                    } else {//Se o meio estiver estritamente a esquerda
                        left=m;
                    }
                }
                //No fim, o intervalo tem tamanho 1 ou 2. O maior indice e 'left'

                if ( (strcmp(nome_agenda_atual,lista_de_agendas[left])==0) || (strcmp(nome_agenda_atual,lista_de_agendas[right])==0) ) {
                    //Se a agenda ja existir
                    printf("Esta agenda ja existe. Tente outro nome: ");
                    continue;
                }
            }

            //Caso contrario, vai em frente;
            break;
        }
        
        //Alocar o nome da agenda sequencialmente vai ser o mais eficiente
        numero_de_agendas++;
        i=numero_de_agendas-2;
        while (i>=0 && strcmp(nome_agenda_atual,lista_de_agendas[i])<0) {
            lista_de_agendas[i+1]=lista_de_agendas[i];
            i--;
        }
        //Para quando lista_de_agendas[i]<nome_agenda_atual (pensa que lista_de_agendas[-1]=-infinity)

        lista_de_agendas[i+1]=nome_agenda_atual;
    
        //Vamos regravar o arquivo de agendas

        agendas=fopen("agendas.txt","wt");
        fprintf(agendas,"%d\n",numero_de_agendas);
        for (i=0;i<numero_de_agendas;i++) {
            fprintf(agendas,"%s\n",lista_de_agendas[i]);
        }

        fclose(agendas);
    }
    


    printf("=======================================================================\n");
    //Abrir a agenda atual.

    char* endereco_agenda=malloc((strlen_meu(nome_agenda_atual)+11)*sizeof(char));
    endereco_agenda[0]='.';
    endereco_agenda[1]='/';
    endereco_agenda[2]='a';
    endereco_agenda[3]='g';
    endereco_agenda[4]='e';
    endereco_agenda[5]='n';
    endereco_agenda[6]='d';
    endereco_agenda[7]='a';
    endereco_agenda[8]='s';
    endereco_agenda[9]='/';

    for (i=0;i<strlen_meu(nome_agenda_atual);i++) {
        endereco_agenda[i+10]=nome_agenda_atual[i];
    }
    endereco_agenda[i+10]=0;

    //O carregamento do arquivo e basicamente a mesma coisa que o de agendas...
    //CTRL+C--CTRL+V na veia
    FILE* arquivo_agenda_atual=fopen(endereco_agenda,"rt");

    if (arquivo_agenda_atual == NULL) {
        printf(
            "Agenda nao encontrada.\n"
            "Gerando um novo arquivo.\n"
        );
        numero_de_eventos=0;
        fclose(arquivo_agenda_atual);
    }
    else {
        //A agenda existe
        //Vamos pegar a primeira linha, que tem o numero de eventos salvas.
        fscanf(arquivo_agenda_atual,"%d",&numero_de_eventos);
        fgetc(arquivo_agenda_atual);//Limpa \n
    }

    lista_de_eventos=malloc(numero_de_eventos*sizeof(struct Evento*));

    //Carrega os eventos
    printf("yea");
    for(i=0;i<numero_de_eventos;i++) {
        fscanf(arquivo_agenda_atual,"%d",&lista_de_eventos[i].data.ano);
        fgetc(arquivo_agenda_atual);
        printf("%d\n",lista_de_eventos[i].data.ano);
        fscanf(arquivo_agenda_atual,"%d",&lista_de_eventos[i].data.mes);
        fgetc(arquivo_agenda_atual);
        printf("%d\n",lista_de_eventos[i].data.mes);
        fscanf(arquivo_agenda_atual,"%d",&lista_de_eventos[i].data.dia);
        fgetc(arquivo_agenda_atual);
        printf("%d\n",lista_de_eventos[i].data.dia);
        fscanf(arquivo_agenda_atual,"%d",&lista_de_eventos[i].inicio.hora);
        fgetc(arquivo_agenda_atual);
        printf("%d\n",lista_de_eventos[i].inicio.hora);
        fscanf(arquivo_agenda_atual,"%d",&lista_de_eventos[i].inicio.minuto);
        fgetc(arquivo_agenda_atual);
        printf("%d\n",lista_de_eventos[i].inicio.minuto);
        fscanf(arquivo_agenda_atual,"%d",&lista_de_eventos[i].fim.hora);
        fgetc(arquivo_agenda_atual);
        printf("%d\n",lista_de_eventos[i].fim.hora);
        printf("yeah");
        int n;
        fscanf(arquivo_agenda_atual,"%d",&lista_de_eventos[i].fim.minuto);
        fgetc(arquivo_agenda_atual);
        printf("%d\n",lista_de_eventos[i].fim.minuto);
        lista_de_eventos[i].desc=input_string(arquivo_agenda_atual);
        lista_de_eventos[i].local=input_string(arquivo_agenda_atual);
    }
    
    fclose(arquivo_agenda_atual);

    opcao=0;

    while (1) {
        printf("=======================================================================\n");

        if (opcao==0) {
            if (numero_de_eventos==0) {
                printf("Nao ha eventos nesta agenda.\n");
            }
            else if (numero_de_eventos==1) {
                printf("\nHa 1 evento nesta agenda.\n");
            }
            else {
                printf("\nHa %d eventos nesta agenda.\n",numero_de_eventos);
                for (i=0;i<numero_de_agendas;i++) {
                    printf("%d: %s\n", i+1,lista_de_agendas[i]);
                }
            }

            printf("\n");
            printf(
                "Escolha uma das seguintes opcoes:\n"
                "  0. Mostrar as opcoes.\n"
                "  1. Cadastrar um novo evento.\n"
                "  2. Mostrar todos os eventos.\n"
                "  3. Mostrar todos os eventos de uma data.\n"
                "  4. Filtrar eventos por descricao.\n"
                "  5. Remover um evento.\n"
                "  6. Salvar alteracoes e sair.\n"
            );

            scanf("%d",&opcao);
            continue;//vai em frente
        }
        else if (opcao==1) {
            //Alocar o nome da agenda sequencialmente vai ser o mais eficiente
            printf("Qual a data do evento?");
            
            numero_de_agendas++;
        i=numero_de_agendas-2;
        while (i>=0 && strcmp(nome_agenda_atual,lista_de_agendas[i])<0) {
            lista_de_agendas[i+1]=lista_de_agendas[i];
            i--;
        }
        //Para quando lista_de_agendas[i]<nome_agenda_atual (pensa que lista_de_agendas[-1]=-infinity)

        lista_de_agendas[i+1]=nome_agenda_atual;
        }
        else if (opcao==2) {
        }
        else if (opcao==3) {
        }
        else if (opcao==4) {
        }
        else if (opcao==5) {
        }
        else if (opcao==6) {
            break;
        }
        else {
            printf("Opcao invalida!\n");
        }
        opcao=0;//Mostra as opcoes de novo
    }
    

    //A agenda atual existe a ja foi selecionada.
    //A lista de agendas pode ser limpada
    for (i=0;i<numero_de_agendas;i++) {
        free(lista_de_agendas[i]);
    }
    free(lista_de_agendas);
    free(nome_agenda_atual);
    free(endereco_agenda);
    
    for(i=0;i<numero_de_eventos;i++) {
            free(lista_de_eventos[i].desc);
            free(lista_de_eventos[i].local);
        }

    return 0;
}

