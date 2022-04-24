#include <stdio.h>

/*copia e adapta a anterior. Vamos tentar fazer um código bizonho,
só por diversão, com truquezinhos e fórmulas estranhas*/
int maxof2int(int a, int b);//funcao que toma o maximo de 2 numeros
int minof2int(int a, int b);//funcao que toma o maximo de 2 numeros

int main() {
  printf("\n\nDigite dois valores inteiros, separados por um espaco.\n"
  "Voce obtera a soma dos numeros impares estritamente entre esses dois valores.\n\n");

  int x,y;
  scanf("%d %d",&x,&y);

  //Primeiro, precisamos determinar o menor inteiro acima do minimo entre x e y
  //Truquezinho matemático ;3. Variáveis intermediárias para evitar ficar recalculando
  //o mínimo e máximo de x,y repetidamente

  int menordosdois=minof2int(x,y);
  int soma=0;
  int i;

  /*Poderia-se utilizar o fato de que o menor impar acima de um inteiro n é
  n+(1-r),
  em que r é o resto da divisao (euclidiana) de n por 2. Mas como C faz divisão
  com sinal, teria que lidar com isso... Mais facil fazer do jeito obvio.    */
  if (menordosdois%2==0) {
    menordosdois++;
  }
  for (i=menordosdois+1;i<maxof2int(x,y);i+=2) {
    soma+=i;
  }

  printf("\nA soma dos numeros impares entre %d e %d eh\n%d\n",x,y,soma);
  return 0;
}

int maxof2int(int a, int b) {
  if (a>b) {
    return a;
  }
  return b;
}

int minof2int(int a, int b) {/*truquezinho safado, provavelmente
  menos eficiente do que o jeito óbvio :')   */
  return a+b-maxof2int(a,b);
}
