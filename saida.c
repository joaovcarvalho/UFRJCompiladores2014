#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MDC( int a, int b ) {
  int temp_boolean_1;
  int temp_int_1;

  temp_boolean_1 = b == 0;
  if( temp_boolean_1 ) goto l_if_true_1;
  goto l_if_false_1;
  l_if_true_1:

return a;
  goto l_if_fim_1;
  l_if_false_1:
  temp_int_1 = a % b;

return MDC(b,temp_int_1);
  l_if_fim_1:;
}

int main() {
  int x_int;
  double x_double;
  float x_float;
  int temp_boolean_1;
  int temp_boolean_2;
  int temp_boolean_3;
  int temp_boolean_4;
  int temp_boolean_5;
  int temp_int_1;

  x_int = 1;
l_for_cond_1: 
  temp_boolean_4 = x_int <= 10;
temp_boolean_5 = !temp_boolean_4;
 if( temp_boolean_5 ) goto l_for_fim_1;
  temp_boolean_2 = x_int > 5;
  temp_boolean_3 = !temp_boolean_2;
  if( temp_boolean_3 ) goto l_passo_pipe_1;
  printf( "%d" , x_int );
  printf( "%s" , "\n" );

l_passo_pipe_1:
  x_int = x_int + 1;
 goto l_for_cond_1; l_for_fim_1:;
  return 0;
}

