#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
  int x_int;
  double x_double;
  float x_float;
  int* sortArray_int;
  int* sortArray_double;
  int* sortArray_float;
  int temp_boolean_1;
  int temp_boolean_2;
  int temp_boolean_3;
  int temp_boolean_4;
  int temp_boolean_5;
  int temp_boolean_6;
  int temp_boolean_7;
  int temp_boolean_8;
  int temp_boolean_9;
  int temp_boolean_10;
  int temp_int_1;
  int temp_int_2;
  int temp_int_3;
  int temp_int_4;
  int temp_int_5;
  int temp_int_6;
  int temp_int_7;
  int temp_int_8;
  int temp_int_9;

int array[10];
int i;
  i = 0;
l_for_cond_1: 
  temp_boolean_1 = i < 10;
temp_boolean_2 = !temp_boolean_1;
 if( temp_boolean_2 ) goto l_for_fim_1;
  temp_int_2 = 10 - i;
  array[i] = temp_int_2;

  temp_int_1 = i + 1;
  i = temp_int_1;
 goto l_for_cond_1; l_for_fim_1:;
  printf( "%s" , "=======================\n" );
  printf( "%s" , "Test Pipes array => Disponha[ X Superior a 0 ] => EmCompletude[ Exclame X; ]: \n" );
  printf( "%s" , "=======================\n" );
temp_int_3 = 0;
sortArray_int = array;
x_int = array[temp_int_3];l_for_cond_4: 
  temp_boolean_9 = temp_int_3 < 10;
temp_boolean_10 = !temp_boolean_9;
 if( temp_boolean_10 ) goto l_for_fim_4;
temp_int_4 = 10- 1;
l_for_cond_3: 
 temp_boolean_3 = temp_int_4 >= 0;
temp_boolean_8 = !temp_boolean_3;
 if( temp_boolean_8 ) goto l_for_fim_3;
temp_int_5 = 0;
l_for_cond_2: 
 temp_boolean_3 = temp_int_5 < temp_int_4;
temp_boolean_7 = !temp_boolean_4;
 if( temp_boolean_7 ) goto l_for_fim_2;
temp_int_7= temp_int_5+ 1;
temp_int_8 = sortArray_int[temp_int_7];
temp_int_9 = sortArray_int[temp_int_5];
temp_boolean_6 = temp_int_9>temp_int_8;
  if( !temp_boolean_6 ) goto l_if_fim_1;
temp_int_6 = sortArray_int[temp_int_5];
sortArray_int[temp_int_5] = sortArray_int[temp_int_7];
sortArray_int[temp_int_7] = temp_int_6;
  l_if_fim_1:;

 temp_int_5 = temp_int_5 + 1;
 goto l_for_cond_2; l_for_fim_2:;

 temp_int_4 = temp_int_4 - 1;
 goto l_for_cond_3; l_for_fim_3:;
  printf( "%d" , x_int );
  printf( "%s" , "\n" );

l_passo_pipe_1:
temp_int_3 = temp_int_3 + 1;
x_int = array[temp_int_3]; goto l_for_cond_4; l_for_fim_4:;
  return 0;
}

