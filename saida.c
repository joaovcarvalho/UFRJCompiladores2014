#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double discriminante( double a, double b, double c ) {
  double temp_double_1;
  double temp_double_2;
  double temp_double_3;
  double temp_double_4;

  temp_double_1 = b * b;
  temp_double_2 = 4.0 * a;
  temp_double_3 = temp_double_2 * c;
  temp_double_4 = temp_double_1 - temp_double_3;

return temp_double_4;
}
double modulo( double n ) {
  int temp_boolean_1;
  int temp_int_1;
  double temp_double_1;
  double temp_double_2;
  double temp_double_3;
  double temp_double_4;
  double temp_double_5;

  temp_boolean_1 = n < 0;
  if( temp_boolean_1 ) goto l_if_true_1;
  goto l_if_false_1;
  l_if_true_1:
  temp_int_1 = - 1;
  temp_double_5 = n * temp_int_1;

return temp_double_5;
  goto l_if_fim_1;
  l_if_false_1:

return n;
  l_if_fim_1:;
}
double raiz( double n, double r ) {
  int temp_boolean_1;
  int temp_boolean_2;
  int temp_boolean_3;
  int temp_boolean_4;
  int temp_boolean_5;
  int temp_int_1;
  double temp_double_1;
  double temp_double_2;
  double temp_double_3;
  double temp_double_4;
  double temp_double_5;
  double temp_double_6;
  double temp_double_7;
  double temp_double_8;
  double temp_double_9;
  double temp_double_10;
  double temp_double_11;
  double temp_double_12;
  double temp_double_13;

  temp_double_6 = n / r;
  temp_double_7 = r - temp_double_6;
  temp_boolean_2 = modulo(temp_double_7) < 0.00001;
  temp_boolean_3 = r != 0;
  temp_boolean_4 = temp_boolean_2 && temp_boolean_3;
  if( !temp_boolean_4 ) goto l_if_fim_2;

return r;
  l_if_fim_2:;
  temp_boolean_5 = r == 0;
  if( temp_boolean_5 ) goto l_if_true_2;
  goto l_if_false_2;
  l_if_true_2:
  temp_double_8 = n / 2;
  temp_double_9 = temp_double_8 + 2;
  temp_double_10 = temp_double_9 / 2;

return raiz(n,temp_double_10);
  goto l_if_fim_3;
  l_if_false_2:
  temp_double_11 = n / r;
  temp_double_12 = temp_double_11 + r;
  temp_double_13 = temp_double_12 / 2;

return raiz(n,temp_double_13);
  l_if_fim_3:;
}

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
  double temp_double_1;
  double temp_double_2;
  double temp_double_3;
  double temp_double_4;
  double temp_double_5;
  double temp_double_6;
  double temp_double_7;
  double temp_double_8;
  double temp_double_9;
  double temp_double_10;
  double temp_double_11;
  double temp_double_12;
  double temp_double_13;
  double temp_double_14;
  double temp_double_15;
  double temp_double_16;
  double temp_double_17;
  double temp_double_18;
  double temp_double_19;
  double temp_double_20;
  double temp_double_21;
  double temp_double_22;
  double temp_double_23;
  double temp_double_24;
  double temp_double_25;
  double temp_double_26;
  double temp_double_27;
  double temp_double_28;
  double temp_double_29;
  double temp_double_30;
  double temp_double_31;
  double temp_double_32;
  double temp_double_33;
  double temp_double_34;

double a;
double b;
double c;
double r1;
double r2;
char resposta[256];
l_dowhile_inicio_1: 
  printf( "%s" , " Raizes =======================\n" );
  printf( "%s" , "Qual o valor de a ? " );
  scanf( "%lf" , &a );
  printf( "%s" , "Qual o valor de b ? " );
  scanf( "%lf" , &b );
  printf( "%s" , "Qual o valor de c ? " );
  scanf( "%lf" , &c );
double delta;
  delta = discriminante(a,b,c);
  temp_boolean_6 = delta > 0;
  if( temp_boolean_6 ) goto l_if_true_4;
  goto l_if_false_4;
  l_if_true_4:
  temp_double_14 = - b;
  temp_double_15 = temp_double_14 + raiz(discriminante(a,b,c),2.0);
  temp_double_16 = 2 * a;
  temp_double_17 = temp_double_15 / temp_double_16;
  r1 = temp_double_17;
  temp_double_18 = - b;
  temp_double_19 = temp_double_18 - raiz(discriminante(a,b,c),2.0);
  temp_double_20 = 2 * a;
  temp_double_21 = temp_double_19 / temp_double_20;
  r2 = temp_double_21;
  printf( "%s" , "Discriminante > 0  ---> Raizes reais :" );
  printf( "%f" , r1 );
  printf( "%s" , " e " );
  printf( "%f" , r2 );
  printf( "%s" , "\n" );
  goto l_if_fim_6;
  l_if_false_4:
  temp_boolean_7 = delta == 0;
  if( temp_boolean_7 ) goto l_if_true_3;
  goto l_if_false_3;
  l_if_true_3:
  temp_double_22 = - b;
  temp_double_23 = 2 * a;
  temp_double_24 = temp_double_22 / temp_double_23;
  r1 = temp_double_24;
  printf( "%s" , "Discriminante = 0  ---> Raizes reais:" );
  printf( "%f" , r1 );
  printf( "%s" , " e " );
  printf( "%f" , r1 );
  printf( "%s" , "\n" );
  goto l_if_fim_5;
  l_if_false_3:
  temp_boolean_8 = delta < 0;
  if( !temp_boolean_8 ) goto l_if_fim_4;
  temp_double_25 = - b;
  temp_double_26 = - discriminante(a,b,c);
  temp_double_27 = temp_double_25 + raiz(temp_double_26,2.0);
  temp_double_28 = 2 * a;
  temp_double_29 = temp_double_27 / temp_double_28;
  r1 = temp_double_29;
  temp_double_30 = - b;
  temp_double_31 = - discriminante(a,b,c);
  temp_double_32 = temp_double_30 - raiz(temp_double_31,2.0);
  temp_double_33 = 2 * a;
  temp_double_34 = temp_double_32 / temp_double_33;
  r2 = temp_double_34;
  printf( "%s" , "Discriminante < 0  ---> Raizes imaginarias :" );
  printf( "%f" , r1 );
  printf( "%s" , "i e " );
  printf( "%f" , r2 );
  printf( "%s" , "i \n" );
  l_if_fim_4:;
  l_if_fim_5:;
  l_if_fim_6:;
  printf( "%s" , "Deseja entrar com outra equacao? (sim/nao)" );
  scanf( "%s" , &resposta );
  printf( "%s" , "Resposta: " );
  printf( "%s" , resposta );
  printf( "%s" , "\n" );

  temp_boolean_9 = strcmp(resposta,"sim") == 0; 

temp_boolean_10= temp_boolean_9;
if( temp_boolean_10 ) goto l_dowhile_inicio_1;
  return 0;
}

