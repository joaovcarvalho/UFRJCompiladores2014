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

int magnitude;
  magnitude = 3;
int dimensao;
  dimensao = 4;
int grandeza;
  grandeza = 10;
int acumulador;
int matriz1[0];
int matriz2[0];
int produto[0];
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
temp_int_3 = i*0;
temp_int_4 = temp_int_3 + j;
  matriz1[temp_int_4] = inteiro;
  temp_int_5 = inteiro + 1;
  inteiro = temp_int_5;

  temp_int_2 = j + 1;
  j = temp_int_2;
 goto l_for_cond_1; l_for_fim_1:;

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
temp_int_8 = i*0;
temp_int_9 = temp_int_8 + j;
  matriz2[temp_int_9] = inteiro;
  temp_int_10 = inteiro + 1;
  inteiro = temp_int_10;

  temp_int_7 = j + 1;
  j = temp_int_7;
 goto l_for_cond_3; l_for_fim_3:;

  temp_int_6 = i + 1;
  i = temp_int_6;
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
temp_int_14 = i*0;
temp_int_15 = temp_int_14 + k;
temp_int_16 = k*0;
temp_int_17 = temp_int_16 + j;
  temp_int_18 = matriz1[temp_int_15] * matriz2[temp_int_17];
  temp_int_19 = acumulador + temp_int_18;
  acumulador = temp_int_19;

  temp_int_13 = k + 1;
  k = temp_int_13;
 goto l_for_cond_5; l_for_fim_5:;
temp_int_20 = i*0;
temp_int_21 = temp_int_20 + j;
  produto[temp_int_21] = acumulador;
  printf( "%s" , "Posicao" );
  printf( "%d" , i );
  printf( "%s" , " - " );
  printf( "%d" , j );
temp_int_22 = i*0;
temp_int_23 = temp_int_22 + j;
  printf( "%d" , produto[temp_int_23] );
  printf( "%s" , "\n" );

  temp_int_12 = j + 1;
  j = temp_int_12;
 goto l_for_cond_6; l_for_fim_6:;

  temp_int_11 = i + 1;
  i = temp_int_11;
 goto l_for_cond_7; l_for_fim_7:;
  return 0;
}

