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
int 

int main() {
  printf("LISTA 4\n");
  printf("\n");
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
    else if (num_ex==5) {char str[500];

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

    }
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    else if (num_ex==7) {

    }
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    else if (num_ex==8) {

    }
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    else if (num_ex==9) {

    }
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    else if (num_ex==10) {

    }
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    else if (num_ex==11) {

    }
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    else if (num_ex==12) {

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
