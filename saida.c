#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inteiro;
int boolean;
double coracao;
float Universo;
char letra;
char poema[256];

int main() {
  int temp_boolean_1;
  int temp_boolean_2;
  int temp_int_1;

  scanf( "%d" , &inteiro );
l_dowhile_inicio_1: 
  printf( "%d" , inteiro );
  printf( "%s" , "\n" );
  temp_int_1 = inteiro - 1;
  inteiro = temp_int_1;

  temp_boolean_1 = inteiro > 0;

temp_boolean_2= temp_boolean_1;
if( temp_boolean_2 ) goto l_dowhile_inicio_1;
  return 0;
}

