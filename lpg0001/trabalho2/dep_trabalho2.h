struct Data {
    int dia;
    int mes;
    int ano;
};
struct Horario {
    int hora;
    int minuto;
};
struct Evento {
    struct Data data;
    struct Horario inicio;
    struct Horario fim;
    char* desc;
    char* local;
};

int compara_Horario(struct Horario h1, struct Horario h2) {
    /*
        Retorna a diferenca em minutos de h1 a h2
        >0 se h1 e apos h2; 0 se h1==h2; <0 se h2 e apos h1
    */

    return 60*(h1.hora-h2.hora)+h1.minuto-h2.minuto;
}

int fim_de_mes(int dia,int mes,int ano) {
    /*
        Verifica se e fim de mes
    */

   if (dia<28) {
    return 0;
   }

   //Vamos tratar fevereiro. Note que é no minimo dia 28

   if (mes==2 && ano%4!=0) {
     return 1;
   }

   //Em todas as outras situacoes, dia 28 nao e fim de mes
   if (dia==28) {
    return 0;
   }

   //Dia a partir do 29. So em fevereiro que e fim de mes

   if (mes==2) {
    return 1;
   }

   //Se o dia nao for 29 fora de fevereiro, nao e fim de mes

   if (dia==29) {
    return 0;
   }

   //A partir do dia 30. Meses usuais sao fim de mes

   if (mes==4 || mes==6 || mes==9 || mes==11) {
    return 1;
   }
   
    //Nao e mes que termina em  30

    if (dia==30) {
        return 0;
    }

    return 1;
}

void proximo_Dia(struct Data data_atual,struct Data* proxima_data) {
    /*
        Grava o dia posterior a data_atual em proxima_data
    */

    //Se for 31 de dezembro, e obvio

    if ( (data_atual.mes==12) && (data_atual.dia==31) ) {
        proxima_data->ano=data_atual.ano+1;
        proxima_data->mes=1;
        proxima_data->dia=1;
        return;
    }

    //Se nao for 31 de dezembro, o ano e o mesmo

    proxima_data->ano=data_atual.ano;

    //Se for fim de mes
    if (fim_de_mes(data_atual.dia,data_atual.mes,data_atual.ano)) {
        proxima_data->mes=data_atual.mes+1;
        proxima_data->dia=1;
        return;
    }
    else {//Caso contrario,
        proxima_data->mes=data_atual.mes;
        proxima_data->dia=data_atual.dia+1;
        return;
    }
}

int compara_Data(struct Data d1, struct Data d2) {
    /*
        Retorna a diferenca em minutos de d1 a d2
        >0 se d1 e apos d2; 0 se d1==d2; <0 se d2 e apos d1
    */
   
    //Primeiro, vamos garantir que a data d2 e antes da d1
    if (d2.ano>d1.ano) {
        return -compara_Data(d2,d1);
    }
    if (d2.mes>d1.mes) {
        return -compara_Data(d2,d1);
    }
    if (d2.dia>d1.dia) {
        return -compara_Data(d2,d1);
    }

    //Agora, d2 e antes de d1.
    int dif_minutos=0;
    //Fazemos uma copia de d2 e passamos de dia a dia
    struct Data copia;
    copia.dia=d2.dia;
    copia.mes=d2.mes;
    copia.ano=d2.ano;

    while ( (copia.dia != d1.dia) || (copia.mes != d1.mes) || (copia.ano != d1.ano) ) {
        dif_minutos+=1440;//=24*60
        proximo_Dia(copia,&copia);
    }

    return dif_minutos;
}

int compara_Evento(struct Evento e1, struct Evento e2) {
    /*
        Retorna o tempo entre os eventos e1 e e2
        >0 se e1 e apos e2; 0 se e1==d2; <0 se e2 e apos e1
    */

   return compara_Data(e1.data,e2.data)+compara_Horario(e1.inicio,e2.fim);
}

int Data_valida(int dia, int mes, int ano) {
  /*
    Verifica se se uma sequência de 3 números inteiros dá uma data valida,
    com dia mês e ano.
  */

  //Se qualquer um for negativo, não é.
  if (dia<0 || mes<0 || ano<0) {
    return 0;
  }
  //Se o mes for acima de 12, também não dá
  if (mes>12){
    return 0;
  }
  //Se o dia for acima de 31....
  if (dia>31) {
    return 0;
  }
  //Ou se for acima de 30 para Abril (4), Junho (6), Setembro (9) ou Novembro (11)
  if ((mes==4)||(mes==6)||(mes==9)||(mes==11)) {
    if (dia>30) {
      return 0;
    }
  }
  //Ou se for fevereiro e dia acima de 29
  if ((mes==2) && (dia>29)) {
    return 0;
  }
  //Ou se o ano nao for bissexto, o mes for fevereiro e o dia for 29
  if ((!(ano%4==0)) && (mes==2) && (dia==29)) {
    return 0;
  }

  //Caso nada disso aconteça, é data correta
  return 1;
}

int Horario_valido(int hora, int minuto) {
    /*
        Determina se um horario e valido
    */

   if ((hora<0) || (minuto<0)) {
    return 0;
   }

   if ((hora<24) && (minuto<60)) {
    return 1;
   }

   return 0;
}

char* data_para_texto(struct Data data_a_converter) {
    //Aloca dinamicamente uma data num texto
    char* texto=malloc(10*sizeof(char)+1);
    texto[0]=data_a_converter.dia/10+'0';
    texto[1]=data_a_converter.dia%10+'0';
    texto[2]='/';
    texto[3]=data_a_converter.mes/10+'0';
    texto[4]=data_a_converter.mes%10+'0';
    texto[5]='/';
    texto[6]=data_a_converter.ano/1000+'0';
    texto[7]=(data_a_converter.ano/100)%10+'0';
    texto[8]=(data_a_converter.ano/10)%10+'0';
    texto[9]=data_a_converter.ano%10+'0';
    texto[10]=0;

    return texto;
}

char* input_string(FILE* stream){
    /*
        Aloca dinamicamente uma string de um file stream de tamanho desconhecido
    */
    int alocacao=16;//"Blocos" de alocacao. 16 arbitrario
    char *str= malloc(sizeof(char)*(alocacao+1));//Aloca uma area dea tamanho 16+1
    int comp = 0;//Comprimento ja gravado
    int c=fgetc(stream);//Pega o primeiro caracter da stream;
    
    while( c!=EOF && c != '\n'){
        str[comp]=c;
        comp++;
        //Alocamos mais um caracter.
        //Sera que chegamos no fim do espaco?
        if(comp==alocacao){
            alocacao+=16;
            str = realloc(str, sizeof(char)*(alocacao+1));
        }
        c=fgetc(stream);
    }
    str[comp]='\0';
    comp++;
    str=realloc(str, sizeof(char)*(comp+1));

    return str;
}

int strlen_meu(char* str) {
    /*
        Comprimento da string contando espacos
    */

   int n=0;
   while (str[n]!=0) {
    n++;
   }
   return n;
}