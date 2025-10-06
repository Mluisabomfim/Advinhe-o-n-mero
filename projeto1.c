#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define TAM 5

void gera_numero(int numero[], int n) {
  srand(time(NULL));

  for (int i = 0; i < n; ++i)
    numero[i] = rand() % 10;
}

int devolve_numero(int numero[], int n) {
  int num = 0;
  for (int i = 0; i < n; ++i)
    num = num * 10 + numero[i];
  return num;
}

void imprime_acertados(int numero[], int acertados[], int n) {
  printf("Algarismos corretos: ");
  for (int i = 0; i < n; ++i) {
    if (acertados[i] == 1)
      printf("%d", numero[i]);
    else
      printf("_");
  }
  printf("\n");
}
int main() {
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    int num[TAM], num_tent, i, tent, resto, vet_tent[TAM];
    int acertados[TAM] = {0,0,0,0,0};
    int todos_certos=0;

  gera_numero(num, TAM);

  //printf("%d\n", devolve_numero(num,TAM));
  printf("Gerei um número aleatório de %d algarismos. Tente adivinhar!\n", TAM);

  printf("Digite a quantidade de tentativas para encontrar o número: ");
  scanf("%d", &num_tent);

  for (i=0; i<num_tent; i++)
  {
      todos_certos = 0;
      printf("Digite um número:");
      scanf("%d", &tent);

      for (int j= TAM - 1; j>=0; j--)
      {
          resto = tent%10;
          vet_tent[j] = resto;
          tent = tent/10;
      }

      for (int j=0; j<TAM; j++)
      {
          if (vet_tent[j] == num [j])
          {
              acertados [j] = 1;
          }
          else
          {
              acertados[j] = 0;
          }

          if (!(acertados[j] == 1))
          {
              todos_certos = 1;
          }
      }
      imprime_acertados(num, acertados, TAM);

      for (int k = 0; k < TAM; k++)
        {
            acertados[k] = 0;
        }

      if (todos_certos == 0)
      {
          printf("Parabéns, você adivinhou o número %05d!\n", devolve_numero(num, TAM));
          break;
      }
  }
  if(!(todos_certos == 0))
      {
          printf("Depois de %d tentativas, você não encontrou o número ", num_tent);
          printf("%d\n", devolve_numero(num,TAM));
      }
  return 0;
}
