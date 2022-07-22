#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dep_trabalho2.h"

int main() {

    /*Capa*/
    printf(
        "=======================================================================\n"
        "||        +      _     ____  *____  ___ . ___   ___  _               ||\n"
        "||*             | |   |  _ \\ / ___|/ _ \\ / _ \\ / _ \\/ | .      *     ||\n"
        "||        *     | | . | |_) | |  _| | | | |+| | | | | |              ||\n"
        "|| .            | |___|  __/| |_| | |_| | |_| | |_| | |     +      * ||\n"
        "||    +    .    |_____|_|    \\____|\\___/ \\___/ \\___/|_|              ||\n"
        "||         _____          _    *      _ _   *         ____       +   ||\n"
        "||        |_   _| __+__ _| |__   __ _| | |__   ___   |___ \\  .       ||\n"
        "||   *      | || '__/ _` | '_ \\ / _` | | '_ \\ / _ \\    __) |      *  ||\n"
        "||          | || | | (_| | |_) | (_| | | | | | (_) |  / __/          ||\n"
        "||  .    *  |_||_|  \\__,_|_.__/.\\__,_|_|_| |_|\\___/  |_____|   *     ||  \n"
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

    //Abre o arquivo com os nomes das agendas salvas
    FILE* agendas = fopen( "agendas.save", "rb");
    char* nome_agenda_atual;
    int numero_de_agendas;
    char** lista_de_agendas;
    int comp_nome_agenda;

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
        fread(&numero_de_agendas,sizeof(int),1,agendas);
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
                //Quando era texto: lista_de_agendas[i]=input_string(agendas);
                fread(&comp_nome_agenda,sizeof(int),1,agendas);
                lista_de_agendas[i]=malloc((comp_nome_agenda+1)*sizeof(char));
                fread(lista_de_agendas[i],sizeof(char),comp_nome_agenda+1,agendas);
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

            if (numero_de_agendas>0) {//Verifica se a agenda ja existe por busca binaria
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

        /*Quando era texto
        agendas=fopen("agendas.txt","wt");
        fprintf(agendas,"%d\n",numero_de_agendas);
        for (i=0;i<numero_de_agendas;i++) {
            fprintf(agendas,"%s\n",lista_de_agendas[i]);
        }
        */

        agendas=fopen("agendas.save","wb");
        fwrite(&numero_de_agendas,sizeof(int),1,agendas);
        for (i=0;i<numero_de_agendas;i++) {
            comp_nome_agenda=strlen_meu(lista_de_agendas[i]);
            fwrite(&comp_nome_agenda,sizeof(int),1,agendas);
            fwrite(lista_de_agendas[i],sizeof(char),comp_nome_agenda+1,agendas);
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
    FILE* arquivo_agenda_atual=fopen(endereco_agenda,"rb");

    if (arquivo_agenda_atual == NULL) {
        printf(
            "Agenda nao encontrada.\n"
            "Gerando um novo arquivo.\n"
        );
        numero_de_eventos=0;
        fclose(arquivo_agenda_atual);
    }
    else {
        printf(
            "Carregando a agenda...\n"
        );
        //A agenda existe
        //Vamos pegar a primeira linha, que tem o numero de eventos salvas.
        fread(&numero_de_eventos,sizeof(int),1,arquivo_agenda_atual);
    }

    lista_de_eventos=malloc(numero_de_eventos*sizeof(struct Evento));

    //Carrega os eventos
    for(i=0;i<numero_de_eventos;i++) {
        /*Quando era texto,com testes e algum erro;
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
        int n;
        fscanf(arquivo_agenda_atual,"%d",&lista_de_eventos[i].fim.minuto);
        fgetc(arquivo_agenda_atual);
        printf("%d\n",lista_de_eventos[i].fim.minuto);
        lista_de_eventos[i].desc=input_string(arquivo_agenda_atual);
        lista_de_eventos[i].local=input_string(arquivo_agenda_atual);*/
        
        fread(&lista_de_eventos[i].data,sizeof(struct Data),1,arquivo_agenda_atual);
        fread(&lista_de_eventos[i].inicio,sizeof(struct Horario),1,arquivo_agenda_atual);
        fread(&lista_de_eventos[i].fim,sizeof(struct Horario),1,arquivo_agenda_atual);
        fread(&lista_de_eventos[i].comp_desc,sizeof(int),1,arquivo_agenda_atual);
        lista_de_eventos[i].desc=malloc(sizeof(char)*(lista_de_eventos[i].comp_desc));
        fread((lista_de_eventos[i].desc),sizeof(char),lista_de_eventos[i].comp_desc,arquivo_agenda_atual);
        fread(&lista_de_eventos[i].comp_local,sizeof(int),1,arquivo_agenda_atual);
        lista_de_eventos[i].local=malloc(sizeof(char)*(lista_de_eventos[i].comp_local));
        fread(lista_de_eventos[i].local,sizeof(char),lista_de_eventos[i].comp_local,arquivo_agenda_atual);
        //tem que readicionar
    }
    
    //fclose(arquivo_agenda_atual);
    //tem que readicionar

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

            printf("Opcao: ");
            scanf("%d",&opcao);

            getchar();//limpa o \n nostdin
            continue;//vai em frente
        }
        else if (opcao==1) {
            printf("Inserindo novo evento.\n\n");

            int tenta_alocar=1;//Vamos tentar alocar

            //Alocar o evento
            struct Evento evento_novo;

            //Aqui, vamos fazer a verificacao
            //Data
            printf("Qual a data do evento (dd/mm/aaaa)? ");
            char* data_string=input_string(stdin);
            int data_valida=Data_str_valida(data_string,&evento_novo.data);

            while (!data_valida) {
                printf("Data invalida. Tente de novo: ");
                data_string=input_string(stdin);
                data_valida=Data_str_valida(data_string,&evento_novo.data);
            }

            free(data_string);

            //Faz entrar no loop de verificacao de inicio e fim
            evento_novo.inicio.hora=0;
            evento_novo.inicio.minuto=1;
            evento_novo.fim.hora=0;
            evento_novo.fim.minuto=0;
            
            char* horario_string;
            int horario_valido;
            
            while (1) {
                //Inicio
                printf("Qual o horario de inicio do evento (hh:mm)? ");
                horario_string=input_string(stdin);
                horario_valido=Horario_str_valido(horario_string,&evento_novo.inicio);
                
                while (!horario_valido) {
                    printf("Horario invalido. Tente de novo: ");
                    horario_string=input_string(stdin);
                    horario_valido=Horario_str_valido(horario_string,&evento_novo.inicio);
                }

                //Fim
                printf("Qual o horario de fim do evento (hh:mm)? ");
                horario_string=input_string(stdin);
                horario_valido=Horario_str_valido(horario_string,&evento_novo.fim);

                while (!horario_valido) {
                    printf("Horario invalido. Tente de novo: ");
                    horario_string=input_string(stdin);
                    horario_valido=Horario_str_valido(horario_string,&evento_novo.fim);
                }

                if (compara_Horario(evento_novo.fim,evento_novo.inicio)>0) {
                    break;
                }

                printf("\nO inicio do evento deve antecedeer o seu fim. Escolha novos horarios.\n\n");
            }

            free(horario_string);

            data_valida=1;
            if (numero_de_eventos>0) {//Verifica se o evento e alocavel por busca binaria
                //Vamos guardar o resultado na variavel "data_valida" (que ja esta declarada)
                //Verifica se o evento e anterior ao primeiro evento
                int left=0,right=numero_de_eventos-1,m;
                if (compara_Evento(evento_novo,lista_de_eventos[0])<=0) {
                    //Se o evento novo comeca antes do primeiro
                    if (compara_Data(evento_novo.data,lista_de_eventos[0].data)+compara_Horario(evento_novo.fim,lista_de_eventos[0].inicio)>0) {
                        printf("1");
                        data_valida=0;
                    } else {
                        data_valida=1;
                    }
                } else if (compara_Evento(evento_novo,lista_de_eventos[numero_de_eventos-1])>=0) {
                    //Se o evento novo comeca depois do ultimo
                    if (compara_Data(evento_novo.data,lista_de_eventos[numero_de_eventos-1].data)+compara_Horario(evento_novo.inicio,lista_de_eventos[numero_de_eventos-1].fim)<0) {
                        printf("2");
                        data_valida=0;
                    } else {
                        data_valida=1;
                    }
                } else {//Caso contrario, o evento esta entre os extremos
                    //vamos achar o maior indice em que o evento anterior comeca antes do primeiro
                    while (right-left>1) {//intervalos de tamanho >=2
                        //Considera o ponto intermediario,arredondado para baixo
                        m=(left+right)/2;
                        if (compara_Evento(evento_novo,lista_de_eventos[m])<=0) {
                            //Comeca comparando a direita, pois o arredondamento e para baixo (m<right sempre!)
                            right=m;
                        } else {//Se o meio estiver estritamente a esquerda
                            left=m;
                        }
                    }
                    //No fim, o intervalo [left,right] tem tamanho 1 ou 2.
                    //left esta estritamente a esquerda do novo. O maior indice com essa propriedade e 'left'
                    if (compara_Data(evento_novo.data,lista_de_eventos[left].data)+compara_Horario(evento_novo.inicio,lista_de_eventos[left].fim)<0) {
                        //Se o evento novo comecar antes do fim do anterior
                        printf("3");
                        data_valida=0;
                    } else if (compara_Data(evento_novo.data,lista_de_eventos[right].data)+compara_Horario(evento_novo.fim,lista_de_eventos[right].inicio)>0) {
                        //Se o evento novo terminar depois do comeco do proximo
                        printf("4");
                        data_valida=0;
                    } else {
                        //Caso nada disso acontaca,
                        data_valida=1;
                    }
                }
            }

            if (data_valida==0) {
                printf("\nEste horario ja possui um evento marcado.\n");
            } else {

                //Pode alocar.

                printf("Descricao: ");
                char* descricao_novo_evento=input_string(stdin);
                printf("Local: ");
                char* local_novo_evento=input_string(stdin);

                //Poe na posicao correta sequenciamente
                numero_de_eventos++;
                lista_de_eventos=realloc(lista_de_eventos,sizeof(struct Evento)*(numero_de_eventos));//ASTERISCO DO INFERNO
                for (i=numero_de_eventos-2;i>=0 && compara_Evento(evento_novo,lista_de_eventos[i])<0;i--) {
                    lista_de_eventos[i+1]=lista_de_eventos[i];
                }
                lista_de_eventos[i+1]=evento_novo;//O evento novo tem a data e os horarios. Falta o resto

                lista_de_eventos[i+1].comp_desc=strlen_meu(descricao_novo_evento)+1;//comprimento
                lista_de_eventos[i+1].desc=malloc(sizeof(char)*(strlen_meu(descricao_novo_evento)+1));//aloca
                strcpy(lista_de_eventos[i+1].desc,descricao_novo_evento);//copia
                lista_de_eventos[i+1].desc[strlen_meu(descricao_novo_evento)]=0;//fecha a string

                lista_de_eventos[i+1].comp_local=strlen_meu(local_novo_evento)+1;//idem
                lista_de_eventos[i+1].local=malloc(sizeof(char)*(strlen_meu(local_novo_evento)+1));
                strcpy(lista_de_eventos[i+1].local,local_novo_evento);
                lista_de_eventos[i+1].local[strlen_meu(local_novo_evento)]=0;
                
                free(descricao_novo_evento);
                free(local_novo_evento);
            }
        }
        else if (opcao==2) {

            for (i=0;i<numero_de_eventos;i++) {
                int comprimento_de_linha=40,j;//Fica bonzinho
                printf("Evento %d:\n",i+1);
                char* temp=data_para_texto(lista_de_eventos[i].data);
                printf("  Data: %s\n",temp);
                free(temp);
                temp=horario_para_texto(lista_de_eventos[i].inicio);
                printf("  Inicio: %s\n",temp);
                free(temp);
                temp=horario_para_texto(lista_de_eventos[i].fim);
                printf("  Fim: %s\n",temp);
                free(temp);
                imprime_descricao(lista_de_eventos[i].desc,comprimento_de_linha);
                printf("\n");
                imprime_local(lista_de_eventos[i].local,comprimento_de_linha);
                printf("\n");
                if (i<numero_de_eventos-1) {
                    for (j=0;j<comprimento_de_linha;j++) {
                        printf("-");
                    }
                    printf("\n");
                }
            }
        }
        else if (opcao==3) {
        }
        else if (opcao==4) {
        }
        else if (opcao==5) {
        }
        else if (opcao==6) {
            FILE* arquivo_agenda_atual=fopen(endereco_agenda,"wb");
            fwrite(&numero_de_eventos,sizeof(int),1,arquivo_agenda_atual);//numero de eventos
            //Salva os eventos
            for(i=0;i<numero_de_eventos;i++) {
                fwrite(&lista_de_eventos[i].data,sizeof(struct Data),1,arquivo_agenda_atual);
                fwrite(&lista_de_eventos[i].inicio,sizeof(struct Horario),1,arquivo_agenda_atual);
                fwrite(&lista_de_eventos[i].fim,sizeof(struct Horario),1,arquivo_agenda_atual);
                fwrite(&lista_de_eventos[i].comp_desc,sizeof(int),1,arquivo_agenda_atual);
                fwrite(lista_de_eventos[i].desc,sizeof(char),lista_de_eventos[i].comp_desc,arquivo_agenda_atual);
                fwrite(&lista_de_eventos[i].comp_local,sizeof(int),1,arquivo_agenda_atual);
                fwrite(lista_de_eventos[i].local,sizeof(char),lista_de_eventos[i].comp_local,arquivo_agenda_atual);
            }

            fclose(arquivo_agenda_atual);
            break;
        }
        else {
            printf("Opcao invalida!\n");
        }

        barras();
        printf("Pressione ENTER para mostrar as opcoes.");
        c=getchar();
        /*
            Limpa o stdin caso algum bestao ponha mais coisa
        */
        while ( (c!=EOF) && (c!='\n') ) {
            c=getchar();
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

