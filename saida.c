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
  int temp_boolean_3;
  int temp_boolean_4;
  int temp_boolean_5;
  int temp_int_1;
  int temp_int_2;

  coracao = 100.20;
  temp_boolean_1 = coracao == 100.10;
  if( temp_boolean_1 ) goto l_if_true_1;
  goto l_if_false_1;
  l_if_true_1:
  printf( "%s" , "Foi" );
  goto l_if_fim_1;
  l_if_false_1:
  printf( "%s" , "Não foi" );
  l_if_fim_1:
  inteiro = 100;
l_while_inicio_1: ;
  temp_boolean_2 = inteiro > 0;
temp_boolean_3 = !temp_boolean_2;
if( temp_boolean_3 ) goto l_while_fim_1;
  printf( "%d" , inteiro );
  temp_int_1 = inteiro - 1;
  inteiro = temp_int_1;
 goto l_while_inicio_1; 
 l_while_fim_1: ;
int i;
  i = 0;
  temp_boolean_4 = i < 100;
l_for_cond_1: 
temp_boolean_5 = !temp_boolean_4;
 if( temp_boolean_5 ) goto l_for_fim_1;
  printf( "%d" , i );
  printf( "%s" , "\n" );

  temp_int_2 = i + 1;
  i = temp_int_2;
 goto l_for_cond_1; l_for_fim_1:;
  return 0;
}

