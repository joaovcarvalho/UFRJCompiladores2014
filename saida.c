#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
  int x_int;
  double x_double;
  float x_float;
  int temp_boolean_1;
  int temp_boolean_2;
  int temp_boolean_3;
  int temp_boolean_4;
  int temp_int_1;
  int temp_int_2;

int array[10];
int i;
  i = 0;
l_for_cond_1: 
  temp_boolean_1 = i < 10;
temp_boolean_2 = !temp_boolean_1;
 if( temp_boolean_2 ) goto l_for_fim_1;
  array[i] = i;

  temp_int_1 = i + 1;
  i = temp_int_1;
 goto l_for_cond_1; l_for_fim_1:;
temp_int_2 = 0;
x_int = array[temp_int_2];l_for_cond_2: 
  temp_boolean_3 = temp_int_2 < 10;
temp_boolean_4 = !temp_boolean_3;
 if( temp_boolean_4 ) goto l_for_fim_2;
 if( temp_int_2 < 10 - 7) goto l_passo_pipe_1;
  printf( "%d" , x_int );
  printf( "%s" , "\n" );

l_passo_pipe_1:
temp_int_2 = temp_int_2 + 1;
x_int = array[temp_int_2]; goto l_for_cond_2; l_for_fim_2:;
  return 0;
}

