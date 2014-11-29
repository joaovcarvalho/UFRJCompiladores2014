#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ff;
int gg;
int c;

int main() {
  int temp_bool_1;
  int temp_int_1;
  int temp_int_2;
  int temp_int_3;
  int temp_int_4;

  ff = 0;
  gg = 1;
  temp_int_1 = ff + gg;
  temp_int_2 = 10 * ff;
  temp_int_3 = 1 + temp_int_2;
  temp_int_4 = temp_int_1 * temp_int_3;
  ff = temp_int_4;
  temp_boolean_1 = ff < gg;
  c = temp_boolean_1;
  printf( "%s" , "hello, world" );
  return 0;
}

