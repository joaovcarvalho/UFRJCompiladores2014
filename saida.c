#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inteiro;
int boolean;
double coracao;
float Universo;
char letra;
char poema[256];
int array[0];
int MDC( int a, int b ) {
  int temp_boolean_1;
  int temp_int_1;

  temp_boolean_1 = b == 0;
  if( !temp_boolean_1 ) goto l_if_fim_1;

return a;
  l_if_fim_1:;
  temp_int_1 = a % b;

return MDC(b,temp_int_1);
}

int main() {
  int temp_boolean_1;
  int temp_int_1;

  printf( "%d" , MDC(15,225) );
  printf( "%s" , "\n" );
  return 0;
}

