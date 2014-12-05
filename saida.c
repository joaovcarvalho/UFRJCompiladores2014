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
  int temp_boolean_6;
  int temp_boolean_7;
  int temp_boolean_8;
  int temp_boolean_9;
  int temp_boolean_10;
  int temp_boolean_11;
  int temp_boolean_12;
  int temp_boolean_13;
  int temp_boolean_14;
  int temp_boolean_15;
  int temp_boolean_16;
  int temp_boolean_17;
  int temp_boolean_18;
  int temp_boolean_19;
  int temp_boolean_20;
  int temp_boolean_21;
  int temp_boolean_22;
  int temp_boolean_23;
  int temp_boolean_24;
  int temp_boolean_25;
  int temp_boolean_26;
  int temp_boolean_27;
  int temp_boolean_28;
  int temp_boolean_29;
  int temp_boolean_30;
  int temp_boolean_31;
  int temp_int_1;
  int temp_int_2;
  int temp_int_3;
  int temp_int_4;
  int temp_int_5;
  int temp_int_6;
  int temp_int_7;
  int temp_int_8;
  int temp_int_9;
  int temp_int_10;
  int temp_int_11;
  int temp_int_12;
  int temp_int_13;
  int temp_int_14;
  int temp_int_15;
  int temp_int_16;
  int temp_int_17;
  int temp_int_18;
  int temp_int_19;
  int temp_int_20;
  int temp_int_21;
  int temp_int_22;
  int temp_int_23;
  int temp_int_24;
  int temp_int_25;
  int temp_int_26;
  int temp_int_27;
  int temp_int_28;
  int temp_int_29;
  int temp_int_30;
  int temp_int_31;
  int temp_int_32;
  int temp_int_33;
  int temp_int_34;
  int temp_int_35;

int a;
int b;
  printf( "%s" , "=======================\n" );
  printf( "%s" , "Qual o valor de a ? " );
  scanf( "%d" , &a );
  printf( "%s" , "Qual o valor de b ? " );
  scanf( "%d" , &b );
  printf( "%s" , "MDC de " );
  printf( "%d" , a );
  printf( "%s" , " e " );
  printf( "%d" , b );
  printf( "%s" , ": " );
  printf( "%d" , MDC(a,b) );
  printf( "%s" , "\n" );
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
  printf( "%s" , "=======================\n" );
  printf( "%s" , "Test Pipes array => Segregue[ X Superior a 0 ] => EmCompletude[ Exclame X; ]: \n" );
  printf( "%s" , "=======================\n" );
temp_int_3 = 0;
x_int = array[temp_int_3];l_for_cond_2: 
  temp_boolean_6 = temp_int_3 < 10;
temp_boolean_7 = !temp_boolean_6;
 if( temp_boolean_7 ) goto l_for_fim_2;
  temp_boolean_4 = x_int > 0;
  temp_boolean_5 = !temp_boolean_4;
  if( temp_boolean_5 ) goto l_passo_pipe_1;
  printf( "%d" , x_int );
  printf( "%s" , "\n" );

l_passo_pipe_1:
temp_int_3 = temp_int_3 + 1;
x_int = array[temp_int_3]; goto l_for_cond_2; l_for_fim_2:;
  printf( "%s" , "=======================\n" );
  printf( "%s" , "Test Pipes array => Primordiais[ 5 ] => EmCompletude[ Exclame X; ]: \n" );
  printf( "%s" , "=======================\n" );
temp_int_4 = 0;
x_int = array[temp_int_4];l_for_cond_3: 
  temp_boolean_9 = temp_int_4 < 10;
temp_boolean_10 = !temp_boolean_9;
 if( temp_boolean_10 ) goto l_for_fim_3;
temp_boolean_8=temp_int_4 >= 5;
 if( temp_boolean_8) goto l_passo_pipe_2;
  printf( "%d" , x_int );
  printf( "%s" , "\n" );

l_passo_pipe_2:
temp_int_4 = temp_int_4 + 1;
x_int = array[temp_int_4]; goto l_for_cond_3; l_for_fim_3:;
  printf( "%s" , "=======================\n" );
  printf( "%s" , "Test Pipes array => Terminantes[ 5 ] => EmCompletude[ Exclame X; ]: \n" );
  printf( "%s" , "=======================\n" );
temp_int_5 = 0;
x_int = array[temp_int_5];l_for_cond_4: 
  temp_boolean_12 = temp_int_5 < 10;
temp_boolean_13 = !temp_boolean_12;
 if( temp_boolean_13 ) goto l_for_fim_4;
temp_int_6 = 10 - 5;
temp_boolean_11= temp_int_5 < temp_int_6;
 if( temp_boolean_11 ) goto l_passo_pipe_3;
  printf( "%d" , x_int );
  printf( "%s" , "\n" );

l_passo_pipe_3:
temp_int_5 = temp_int_5 + 1;
x_int = array[temp_int_5]; goto l_for_cond_4; l_for_fim_4:;
  printf( "%s" , "=======================\n" );
  printf( "%s" , "Multiplicação de Matrizes:\n" );
int x_1;
int inteiro;
int magnitude;
  magnitude = 3;
int dimensao;
  dimensao = 4;
int grandeza;
  grandeza = 10;
int acumulador;
  acumulador = 0;
int matriz1[12];
int matriz2[40];
int produto[30];
  inteiro = 0;
  printf( "%s" , "Matriz1: \n" );
  i = 0;
l_for_cond_6: 
  temp_boolean_14 = i < magnitude;
temp_boolean_17 = !temp_boolean_14;
 if( temp_boolean_17 ) goto l_for_fim_6;
int j;
  j = 0;
l_for_cond_5: 
  temp_boolean_15 = j < dimensao;
temp_boolean_16 = !temp_boolean_15;
 if( temp_boolean_16 ) goto l_for_fim_5;
  temp_int_9 = i + 1;
temp_int_10 = i*4;
temp_int_11 = temp_int_10 + j;
  matriz1[temp_int_11] = temp_int_9;
temp_int_12 = i*4;
temp_int_13 = temp_int_12 + j;
  printf( "%d" , matriz1[temp_int_13] );
  printf( "%s" , " " );

  temp_int_8 = j + 1;
  j = temp_int_8;
 goto l_for_cond_5; l_for_fim_5:;
  printf( "%s" , "\n" );

  temp_int_7 = i + 1;
  i = temp_int_7;
 goto l_for_cond_6; l_for_fim_6:;
  printf( "%s" , "Matriz2: \n" );
  i = 0;
l_for_cond_8: 
  temp_boolean_18 = i < dimensao;
temp_boolean_21 = !temp_boolean_18;
 if( temp_boolean_21 ) goto l_for_fim_8;
  j = 0;
l_for_cond_7: 
  temp_boolean_19 = j < grandeza;
temp_boolean_20 = !temp_boolean_19;
 if( temp_boolean_20 ) goto l_for_fim_7;
  temp_int_16 = i + 1;
temp_int_17 = i*10;
temp_int_18 = temp_int_17 + j;
  matriz2[temp_int_18] = temp_int_16;
temp_int_19 = i*10;
temp_int_20 = temp_int_19 + j;
  printf( "%d" , matriz2[temp_int_20] );
  printf( "%s" , " " );

  temp_int_15 = j + 1;
  j = temp_int_15;
 goto l_for_cond_7; l_for_fim_7:;
  printf( "%s" , "\n" );

  temp_int_14 = i + 1;
  i = temp_int_14;
 goto l_for_cond_8; l_for_fim_8:;
  i = 0;
l_for_cond_11: 
  temp_boolean_22 = i < magnitude;
temp_boolean_27 = !temp_boolean_22;
 if( temp_boolean_27 ) goto l_for_fim_11;
  j = 0;
l_for_cond_10: 
  temp_boolean_23 = j < grandeza;
temp_boolean_26 = !temp_boolean_23;
 if( temp_boolean_26 ) goto l_for_fim_10;
  acumulador = 0;
int k;
  k = 0;
l_for_cond_9: 
  temp_boolean_24 = k < dimensao;
temp_boolean_25 = !temp_boolean_24;
 if( temp_boolean_25 ) goto l_for_fim_9;
temp_int_24 = i*4;
temp_int_25 = temp_int_24 + k;
temp_int_26 = k*10;
temp_int_27 = temp_int_26 + j;
  temp_int_28 = matriz1[temp_int_25] * matriz2[temp_int_27];
  temp_int_29 = acumulador + temp_int_28;
  acumulador = temp_int_29;

  temp_int_23 = k + 1;
  k = temp_int_23;
 goto l_for_cond_9; l_for_fim_9:;
temp_int_30 = i*10;
temp_int_31 = temp_int_30 + j;
  produto[temp_int_31] = acumulador;

  temp_int_22 = j + 1;
  j = temp_int_22;
 goto l_for_cond_10; l_for_fim_10:;

  temp_int_21 = i + 1;
  i = temp_int_21;
 goto l_for_cond_11; l_for_fim_11:;
  printf( "%s" , "Resultado: \n" );
  i = 0;
l_for_cond_13: 
  temp_boolean_28 = i < magnitude;
temp_boolean_31 = !temp_boolean_28;
 if( temp_boolean_31 ) goto l_for_fim_13;
  j = 0;
l_for_cond_12: 
  temp_boolean_29 = j < grandeza;
temp_boolean_30 = !temp_boolean_29;
 if( temp_boolean_30 ) goto l_for_fim_12;
temp_int_34 = i*10;
temp_int_35 = temp_int_34 + j;
  printf( "%d" , produto[temp_int_35] );
  printf( "%s" , " " );

  temp_int_33 = j + 1;
  j = temp_int_33;
 goto l_for_cond_12; l_for_fim_12:;
  printf( "%s" , "\n" );

  temp_int_32 = i + 1;
  i = temp_int_32;
 goto l_for_cond_13; l_for_fim_13:;
  return 0;
}

