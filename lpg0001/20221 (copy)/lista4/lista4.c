#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*Todos os exercícios foram resolvidos por funções.*/

/*Funçõezinhas adicionais*/
int strlen_meu(char str[]);//Comprimento de string

/*Funçõezinhas da lista*/
int string_contem_char(char s[],char c);//Ex1
int string_conta_char(char s[],char c);//Ex2
void concatena( char str1[], char str2[] );//Ex3
int palindrome(char str[]);//Ex4
void min_pra_max(char str[]);//Ex5
int so_digitos(char str[]);//Ex6
int str_conv_int( char str[]);//Ex7
int e_digito(char c);//Ex8
int formato_certo(char str[]);
void gravar_data(char str[],int v[3]);
int e_data(int v[3]);
void trim( char srt[] );//Ex9
void inverte (char str[]);//Ex10
void apaga(char str[],char c);//Ex11
int compara( char str1[], char str2[] );//Ex12


int main() {
  printf("=============\n");
  printf("LISTA 4\n");
  printf("\n");
  printf("=============\n");
  printf("OBSERVACOES:\n");
  printf("  - EVITE USAR AS SETAS NO CYGWIN AO DIGITAR!!!\n");
  printf("  - ESPACOS NO COMECO DAS STRINGS SAO IGNORADOS EXCETO NOS EXERCICIOS 9-11.");
  printf("=============\n");

  int num_ex=1;
  while (num_ex!=0) {

    printf("Digite o numero do exercicio que voce quer testar (1 a 12)\nou 0 para sair: ");
    scanf("%d",&num_ex);

    if (num_ex==1) {
      char str[500];
      char c;
      printf("Digite a string (até 500 caracteres):\n");

      scanf(" %[^\n]%*c", str);

      printf("Digite o caracter: ");
      scanf(" %c",&c);

      int contem=string_contem_char(str,c);

      if (contem==0) {
        printf("A string NAO CONTEM o caracter.\n");
      }
      else {
        printf("A string CONTEM o caracter.\n");
      }
    }
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    else if (num_ex==2) {
      char str[500];
      char c;
      printf("Digite a string (até 500 caracteres):\n");

      scanf(" %[^\n]%*c", str);

      printf("Digite o caracter: ");
      scanf(" %c",&c);

      int numerodevezes=string_conta_char(str,c);

      printf("A string contem o caracter %d vezes.\n",numerodevezes);
      printf("(obs: a contagem diferencia maiusculo e minusculo)\n");
    }
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    else if (num_ex==3) {
      char str1[500];
      char str2[500];
      printf("(Digite strings ate 250 caracteres, por favor. :p)\n");

      printf("Digite a primeira string:\n");
      scanf(" %[^\n]%*c", str1);

      printf("Digite a segunda string:\n");
      scanf(" %[^\n]%*c", str2);

      printf("\n");
      printf("A primeira string e\n");
      printf("%s",str1);
      printf("\n\n");

      printf("A segunda string e\n");
      printf("%s",str2);
      printf("\n\n");

      concatena(str1,str2);

      printf("A concatenacao delas e\n");
      printf("%s",str1);
      printf("\n");
    }
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    else if (num_ex==4) {
      char str[500];

      printf("Digite a string (ate 500 caracteres;cuidado com espacos):\n");
      scanf(" %[^\n]%*c", str);

      int pal=palindrome(str);

      if (pal==0) {
        printf("A string NAO; e palindrome.\n");
      }
      else {
        printf("A string e palindrome.\n");
      }
    }
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    else if (num_ex==5) {
      char str[500];
      printf("Digite a string (ate 500 caracteres;cuidado com espacos):\n");
      scanf(" %[^\n]%*c", str);

      printf("\nA string e\n");
      printf("%s",str);
      printf("\n\nA string alterada com minusculas para maiusculas e\n");
      min_pra_max(str);
      printf("%s",str);
      printf("\n");
    }
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    else if (num_ex==6) {
      char str[500];
      printf("Digite a string (ate 500 caracteres):\n");
      scanf(" %[^\n]%*c", str);

      if (so_digitos(str)) {
        printf("A string so tem digitos.\n");
      }
      else {
        printf("A string NAO tem so digitos.\n");
      }
    }
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    else if (num_ex==7) {
        char str[500];
        printf("Digite uma string somente com digitos (ate 500 caracteres):\n");
        scanf(" %[^\n]%*c", str);
        if (!(so_digitos(str))) {
          printf("Essa string nao tem so digitos, cabecudo.\n");
        }
        else {
          printf("A string e\n");
          printf("%s\n",str);
          printf("que e o numero %d.\n",str_conv_int(str));
        }

    }
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    else if (num_ex==8) {
        char str[500];
        printf("Digite uma string com uma data no formato DD/MM/AAAA\n");
        printf("(CUIDADO: ponha zeros na frente, i.e., escreva 01/04/2012 e\n");
        printf("nao simplesmente 1/4/2012):\n");

        scanf(" %[^\n]%*c", str);
        if (!formato_certo(str)) {
          printf("O formato nao esta certo!\n");
        }
        else {
          int v[3];
          gravar_data(str,v);
          if (e_data(v)) {
            printf("A data foi gravada num vetor inteiro.\n");
            printf("Dia: %d\n",v[0]);
            printf("Mes: %d\n",v[1]);
            printf("Ano: %d\n",v[2]);
          }
          else {
            printf("O formato esta correto, mas nao e uma data valida.\n");
          }
        }
    }
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    else if (num_ex==9) {
        char str[500];
        printf("Digite uma string (ate 500 caracteres) para fazer trim:\n");
        //scanf(" %[^\n]%*c", str);
        //Tem que ser um pouco diferente do acima para nao apagar espacos no comeco
        int cc;
        while ( (cc = getchar()) != '\n' && cc != EOF );

        fgets(str,500,stdin);

        //Apaga o '\n' no final
        int i;
        for (i=1;str[i]!=0;i++)  { }
        str[i-1]=0;

        printf("A string original (dentro de aspas) e\n");
        printf("\"%s\"\n",str);
        trim(str);

        printf("e a string \"trimada\" e\n");
        printf("\"%s\"\n",str);
    }
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    else if (num_ex==10) {
        char str[500];
        printf("Digite uma string (ate 500 caracteres):\n");
        //scanf(" %[^\n]%*c", str);
        //Tem que ser um pouco diferente do acima para nao apagar espacos no comeco
        int cc;
        while ( (cc = getchar()) != '\n' && cc != EOF );

        fgets(str,500,stdin);

        //Apaga o '\n' no final
        int i;
        for (i=1;str[i]!=0;i++)  { }
        str[i-1]=0;


        printf("A string original (dentro de aspas) e\n");
        printf("\"%s\"\n",str);


        inverte(str);
        printf("e a string invertida e\n");
        printf("\"%s\"\n",str);
    }
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    else if (num_ex==11) {
        char str[500];
        printf("Digite uma string (ate 500 caracteres):\n");
        //scanf(" %[^\n]%*c", str);
        //Tem que ser um pouco diferente do acima para nao apagar espacos no comeco
        int cc;
        while ( (cc = getchar()) != '\n' && cc != EOF );

        fgets(str,500,stdin);

        //Apaga o '\n' no final
        int i;
        for (i=1;str[i]!=0;i++)  { }
        str[i-1]=0;

        char charac;
        printf("Digite um caracter:\n");
        //scanf(" %[^\n]%*c", str);
        //Tem que ser um pouco diferente do acima para nao apagar espacos no comeco
        scanf(" %c",&charac);

        printf("A string original (dentro de aspas) e\n");
        printf("\"%s\"\n",str);

        apaga(str,charac);
        printf("e a string sem o caracter e\n");
        printf("\"%s\"\n",str);
    }
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    else if (num_ex==12) {
      char str1[500];
      printf("Digite a primeira string (ate 500 caracteres):\n");
      scanf(" %[^\n]%*c", str1);

      char str2[500];
      printf("Digite a segunda string (ate 500 caracteres):\n");
      scanf(" %[^\n]%*c", str2);

      int comparacao=compara(str1,str2);

      if (comparacao==0) {
        printf("As strings sao iguais.\n");
      }
      else if (comparacao<0) {
        printf("A primeira string e menor.\n");
      }
      else {
        printf("A segunda string e menor.\n");
      }
    }
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////

    printf("=============\n");
  }
  return 0;
}
////////////////////////////////////////////////////////////////////////////////
//FUNÇÕES AUXILIARES

int strlen_meu(char str[]) {
  if (str[0]=='\0') {
    return 0;
  }

  return 1+strlen_meu(str+1);
}

////////////////////////////////////////////////////////////////////////////////
//FUNÇÕES DOS EXERCICIOS

/*
  1) Dados uma string s e um caractere c faça um programa que verifique se s contém
  c. Dica: a implementação dentro de uma função facilita a definição da solução.
*/
int string_contem_char(char s[],char c) {
  if (s[0]=='\0') {
    //String vazia
    return 0;
  }

  if (s[0]==c) {
    return 1;
  }

  return string_contem_char(s+1,c);
}


/*
  2) Modifique o código da questão anterior fazendo com que o programa determine
  quantas vezes o caractere ocorre na string.
*/
int string_conta_char(char s[],char c) {
  if (s[0]=='\0') {
    //String vazia
    return 0;
  }

  if (s[0]==c) {
    return 1+string_conta_char(s+1,c);
  }

  return string_conta_char(s+1,c);

}

/*
  3) Escreva uma função que implementa o comportamento da função strcat(),
  ou seja, dadas duas strings str1 e str2, a função deve concatenar as duas
  strings e o conteúdo deve ficar em str1. Não utilize funções predefinidas.
*/
void concatena( char str1[], char str2[] ) {
  int tamanho1=strlen_meu(str1);//Tamanho de str1[]

  //Roda pelas entradas de str2
  int i;
  for (i=0;str2[i]!='\0';i++) {
    //Pões elas em str 1.
    str1[i+tamanho1]=str2[i];
  }

  //No fim, tem as strings 1 e 2 concatenadas. Tem-se i=strlen_meu(str2).
  //Fecha str1
  str1[i+tamanho1]='\0';
}

/*
  4) Escreva um programa que leia uma string e determina se a mesma é
  palíndrome, ou seja, se forma a mesma sequência de caracteres quando lida de
  trás para frente.
*/

int palindrome(char str[]) {
  //Tamanho da string
  int tamanho=strlen_meu(str);
  //Caracteres a testar
  int atestar=tamanho/2;

  int i;
  for (i=0;i<atestar;i++) {
    if (str[i]!=str[tamanho-1-i]) {
      return 0;
    }
  }
  return 1;
}

/*
  5) Faça um programa que leia uma cadeia de caracteres e converta todos os
  caracteres que forem letras minúsculas para letras maiúsculas.
*/

void min_pra_max(char str[]) {
  int i;

  for (i=0;str[i]!='\0';i++) {//Corre nas entradas de str
    if ((str[i]>='a') && (str[i]<='z')) {
      //a=97 e A=65=97-32. Similarmente para b,B, c,C, etc.
      str[i]-=32;
    }
  }
}

/*
  6) Faça um programa que verifica se uma string contém somente dígitos decimais
  (0 a 9).
*/

int so_digitos(char str[]) {
  //'0'=48 e '9'=57 em ASCII
  int i;
  for (i=0 ; str[i]!=0 ; i++) {
    if ((str[i]<48)||(str[i]>57)) {
      return 0;
    }
  }
  return 1;
}

/*
  7)  Escreva um programa que converta uma string que contém somente dígitos
  em um valor inteiro (variável int).
*/

int str_conv_int( char str[]) {
  //Assume-se questr só tem digitos, e que e nao vazia
  //'0'=48 e '9'=57 em ASCII

  int i,n=0;
  for (i=0;str[i]!=0;i++) {
    //Olha pro i-esimo digito e poe na frente, convertendo digito para int
    n*=10;
    n+=((int)str[i])-48;
  }

  return n;
}


/*
  8) Escreva um programa que leia uma cadeia de caracteres no formato
  "DD/MM/AAAA" e copie o dia, mês e ano para 3 variáveis inteiras. Antes disso,
  o programa deve verificar se o formato está correto, ou seja, se as barras
  estão no lugar certo, e se D, M e A são dígitos.
*/

int e_digito(char c) {//Verifica seum character e um digito
  //'0'=48 e '9'=57 em ASCII
  if ((c<48)||(c>57)) {
      return 0;
  }
  return 1;
}

int formato_certo(char str[]) {
  //Função que verifica se esta no formato DD/MM/AAAA, como numa data
  if (e_digito(str[0])) {
    if (e_digito(str[1])) {
      if (str[2]=='/') {
        if (e_digito(str[3])) {
          if (e_digito(str[4])) {
            if (str[5]=='/') {
              if (e_digito(str[6])) {
                if (e_digito(str[7])) {
                  if (e_digito(str[8])) {
                    if (e_digito(str[9])) {
                      if (str[10]==0) {
                        return 1;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

void gravar_data(char str[],int v[3]) {
  //Grava uma data numa string str em um vetor v de tamanho 3
  //Assume-se que str de fato e uma daat
  v[0]=10*((int)str[0])+((int)str[1])-528;//480+48=528
  v[1]=10*((int)str[3])+((int)str[4])-528;//480+48=528
  v[2]=1000*((int)str[6])+100*((int)str[7])+10*((int)str[8])+((int)str[9])-53328;//48000+4800+480+48=53328
}

int e_data(int v[3]) {
  /*
    Verifica se se uma sequência de 3 números inteiros dá uma data valida,
    com dia mês e ano.
  */

  //Se qualquer um for negativo, não é.
  if (v[0]<0 || v[1]<0 || v[2]<0) {
    return 0;
  }
  //Se o mes for acima de 12, também não dá
  if (v[1]>12){
    return 0;
  }
  //Se o dia for acima de 31....
  if (v[0]>31) {
    return 0;
  }
  //Ou se for acima de 30 para Abril (4), Junho (6), Setembro (9) ou Novembro (11)
  if ((v[1]==4)||(v[1]==6)||(v[1]==9)||(v[1]==11)) {
    if (v[0]>30) {
      return 0;
    }
  }
  //Ou se for fevereiro e dia acima de 29
  if ((v[0]>29) && (v[1]==2)) {
    return 0;
  }
  //Ou se o ano nao for bissexto, o mes for fevereiro e o dia for 29
  if ((!(v[2]%4==0)) && (v[1]==2) && (v[0]==29)) {
    return 0;
  }

  //Caso anda disso aconteça, é data
  return 1;
}


/*
  9) Escreva uma função remove todos os espaços no início e no final de uma
  string (processo é chamado de trimming).
*/

void trim( char str[] ) {
  //Vamos procurar o primeiro caracter diferente de um espaco
  int primeiro_nao_espaco;
  for (primeiro_nao_espaco=0;str[primeiro_nao_espaco]==' ';primeiro_nao_espaco++) {
    //
  }
  //neste ponto,nao_espaco guarda o indice do primeiro nao-espaco da string
  //Pode ser que o primeiro nao-espaço seja o fim da string!

  if (str[primeiro_nao_espaco]==0) {
    str[0]=0;//Apaga a string
    return;
  }
  //Mas caso contrario, vai ser um caracter normal
  //Agora, vamos encontrar o ultimo nao espacos

  int ultimo_nao_espaco=primeiro_nao_espaco;
  int i;
  for (i=primeiro_nao_espaco+1;str[i]!=0;i++) {
    if (str[i]!=' ') {
      ultimo_nao_espaco=i;
    }
  }
  //Por fim, corremos de primeiro_nao_espaco ate ultimo_nao_espaco, guardando
  //os caratecteres em str[0],str[1] etc

  for (i=primeiro_nao_espaco;i<=ultimo_nao_espaco;i++) {
    str[i-primeiro_nao_espaco]=str[i];
  }
  str[i-primeiro_nao_espaco]=0;//Fecha


  return;
}


/*
  10) Escreva uma função que inverte a ordem dos caracteres de uma string.
*/

void inverte (char str[]) {
  //Tamanho da string
  int tamanho=strlen_meu(str);
  //Caracteres a trocar
  int atrocar=tamanho/2;

  int i;
  for (i=0;i<atrocar;i++) {
    /*
      Lembra do truquezinho para trocar numeros x e y de lugar sem variavel auxiliar?
        x=x+y
        y=x-y
        x=x-y
      Faz o mesmo ;)
    */
    str[i]=str[i]+str[tamanho-1-i];
    str[tamanho-1-i]=str[i]-str[tamanho-1-i];
    str[i]=str[i]-str[tamanho-1-i];
  }

  return;
}

/*
  11) Crie uma função que recebe uma string s e um caractere c,
  e apague todas as ocorrências de c em s
*/

void apaga(char * str,char c) {
  int numero_de_vezes=0;//Numero de vezes que se achou c em str
  int i;
  for (i=0;str[i]!=0;i++) {
    if (str[i]!=c) {
      str[i-numero_de_vezes]=str[i];
    }
    else {
      numero_de_vezes++;
    }
  }

  str[i-numero_de_vezes]=0;
  return;
}

/*
  12) Escreva uma função que implementa o comportamento da função strcmp(),
  ou seja, dadas duas strings str1 e str2, a função deve comparar os conteúdos
  considerando a ordem alfabética.
*/

int compara( char str1[], char str2[] ) {
  int i;
  for (i=0;(str1[i]!=0)||(str2[i]!=0);i++) {
    if (str1[i]<str2[i]) {
      return -1;
    }
    if (str1[i]>str2[i]) {
      return 1;
    }
  }

  return 0;
}
