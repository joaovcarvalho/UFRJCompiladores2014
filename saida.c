#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double coracao;

int main() {
  int x_int;
  double x_double;
  float x_float;
  int temp_boolean_1;

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
  return 0;
}

