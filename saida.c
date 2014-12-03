#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inteiro;
int boolean;
double coracao;
float Universo;
char letra;
char poema[256];
int array[0];
int MDC( int a, int b ) {
  int temp_boolean_1;
  int temp_int_1;

  temp_boolean_1 = b == 0;
  if( !temp_boolean_1 ) goto l_if_fim_1;

return a;
  l_if_fim_1:;
  temp_int_1 = a % b;

return MDC(b,temp_int_1);
}

int main() {
  int temp_boolean_1;
  int temp_boolean_2;
  int temp_boolean_3;
  int temp_boolean_4;
  int temp_boolean_5;
  int temp_boolean_6;
  int temp_boolean_7;
  int temp_boolean_8;
  int temp_boolean_9;
  int temp_int_1;
  int temp_int_2;
  int temp_int_3;
  int temp_int_4;
  int temp_int_5;
  int temp_int_6;

int colecao[0];
  inteiro = 0;
int i;
  i = 0;
l_for_cond_2: 
  temp_boolean_2 = i < 3;
temp_boolean_5 = !temp_boolean_2;
 if( temp_boolean_5 ) goto l_for_fim_2;
int j;
  j = 0;
l_for_cond_1: 
  temp_boolean_3 = j < 4;
temp_boolean_4 = !temp_boolean_3;
 if( temp_boolean_4 ) goto l_for_fim_1;
  colecao[0] = inteiro;
  temp_int_4 = inteiro + 1;
  inteiro = temp_int_4;

  temp_int_3 = j + 1;
  j = temp_int_3;
 goto l_for_cond_1; l_for_fim_1:;

  temp_int_2 = i + 1;
  i = temp_int_2;
 goto l_for_cond_2; l_for_fim_2:;
  i = 0;
l_for_cond_4: 
  temp_boolean_6 = i < 3;
temp_boolean_9 = !temp_boolean_6;
 if( temp_boolean_9 ) goto l_for_fim_4;
  j = 0;
l_for_cond_3: 
  temp_boolean_7 = j < 4;
temp_boolean_8 = !temp_boolean_7;
 if( temp_boolean_8 ) goto l_for_fim_3;

  temp_int_6 = j + 1;
  j = temp_int_6;
 goto l_for_cond_3; l_for_fim_3:;

  temp_int_5 = i + 1;
  i = temp_int_5;
 goto l_for_cond_4; l_for_fim_4:;
  return 0;
}

