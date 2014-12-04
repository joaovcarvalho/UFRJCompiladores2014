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
  int temp_int_2;
  int temp_int_3;

int array[10];
int i;
  i = 0;
l_for_cond_1: 
  temp_boolean_2 = i < 10;
temp_boolean_3 = !temp_boolean_2;
 if( temp_boolean_3 ) goto l_for_fim_1;
  array[i] = i;

  temp_int_2 = i + 1;
  i = temp_int_2;
 goto l_for_cond_1; l_for_fim_1:;
temp_int_3 = 0;
x_int = array[temp_int_3];l_for_cond_2: 
  temp_boolean_4 = temp_int_3 < 10;
temp_boolean_5 = !temp_boolean_4;
 if( temp_boolean_5 ) goto l_for_fim_2;
 if( temp_int_3 < 10 - 7) goto l_passo_pipe_1;
  printf( "%d" , x_int );
  printf( "%s" , "\n" );

l_passo_pipe_1:
temp_int_3 = temp_int_3 + 1;
x_int = array[temp_int_3]; goto l_for_cond_2; l_for_fim_2:;
  return 0;
}

