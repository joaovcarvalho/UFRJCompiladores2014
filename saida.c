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

int x_1;
int inteiro;
int magnitude;
  magnitude = 3;
int dimensao;
  dimensao = 4;
int grandeza;
  grandeza = 3;
int acumulador;
  acumulador = 0;
int matriz1[12];
int matriz2[12];
int produto[9];
  inteiro = 0;
int i;
  i = 0;
l_for_cond_2: 
  temp_boolean_1 = i < magnitude;
temp_boolean_4 = !temp_boolean_1;
 if( temp_boolean_4 ) goto l_for_fim_2;
int j;
  j = 0;
l_for_cond_1: 
  temp_boolean_2 = j < dimensao;
temp_boolean_3 = !temp_boolean_2;
 if( temp_boolean_3 ) goto l_for_fim_1;
  temp_int_3 = i + 1;
temp_int_4 = i*4;
temp_int_5 = temp_int_4 + j;
  matriz1[temp_int_5] = temp_int_3;
temp_int_6 = i*4;
temp_int_7 = temp_int_6 + j;
  printf( "%d" , matriz1[temp_int_7] );
  printf( "%s" , " " );

  temp_int_2 = j + 1;
  j = temp_int_2;
 goto l_for_cond_1; l_for_fim_1:;
  printf( "%s" , "\n" );

  temp_int_1 = i + 1;
  i = temp_int_1;
 goto l_for_cond_2; l_for_fim_2:;
  i = 0;
l_for_cond_4: 
  temp_boolean_5 = i < dimensao;
temp_boolean_8 = !temp_boolean_5;
 if( temp_boolean_8 ) goto l_for_fim_4;
  j = 0;
l_for_cond_3: 
  temp_boolean_6 = j < grandeza;
temp_boolean_7 = !temp_boolean_6;
 if( temp_boolean_7 ) goto l_for_fim_3;
  temp_int_10 = i + 1;
temp_int_11 = i*3;
temp_int_12 = temp_int_11 + j;
  matriz2[temp_int_12] = temp_int_10;
temp_int_13 = i*3;
temp_int_14 = temp_int_13 + j;
  printf( "%d" , matriz2[temp_int_14] );
  printf( "%s" , " " );

  temp_int_9 = j + 1;
  j = temp_int_9;
 goto l_for_cond_3; l_for_fim_3:;
  printf( "%s" , "\n" );

  temp_int_8 = i + 1;
  i = temp_int_8;
 goto l_for_cond_4; l_for_fim_4:;
  i = 0;
l_for_cond_7: 
  temp_boolean_9 = i < magnitude;
temp_boolean_14 = !temp_boolean_9;
 if( temp_boolean_14 ) goto l_for_fim_7;
  j = 0;
l_for_cond_6: 
  temp_boolean_10 = j < grandeza;
temp_boolean_13 = !temp_boolean_10;
 if( temp_boolean_13 ) goto l_for_fim_6;
  acumulador = 0;
int k;
  k = 0;
l_for_cond_5: 
  temp_boolean_11 = k < dimensao;
temp_boolean_12 = !temp_boolean_11;
 if( temp_boolean_12 ) goto l_for_fim_5;
temp_int_18 = i*4;
temp_int_19 = temp_int_18 + k;
temp_int_20 = k*3;
temp_int_21 = temp_int_20 + j;
  temp_int_22 = matriz1[temp_int_19] * matriz2[temp_int_21];
  temp_int_23 = acumulador + temp_int_22;
  acumulador = temp_int_23;

  temp_int_17 = k + 1;
  k = temp_int_17;
 goto l_for_cond_5; l_for_fim_5:;
temp_int_24 = i*3;
temp_int_25 = temp_int_24 + j;
  produto[temp_int_25] = acumulador;
  printf( "%s" , "Posicao " );
  printf( "%d" , i );
  printf( "%s" , " - " );
  printf( "%d" , j );
  printf( "%s" , " : " );
temp_int_26 = i*3;
temp_int_27 = temp_int_26 + j;
  printf( "%d" , produto[temp_int_27] );
  printf( "%s" , "\n" );

  temp_int_16 = j + 1;
  j = temp_int_16;
 goto l_for_cond_6; l_for_fim_6:;

  temp_int_15 = i + 1;
  i = temp_int_15;
 goto l_for_cond_7; l_for_fim_7:;
  return 0;
}

