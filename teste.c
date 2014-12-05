i = 10- 1;
l_for_cond_3: 
 temp_boolean_3 = i >= 0;
temp_boolean_8 = !temp_boolean_3;
 if( temp_boolean_8 ) goto l_for_fim_3;
j = 0;
l_for_cond_2: 
 temp_boolean_3 = j < i;
temp_boolean_7 = !temp_boolean_4;
 if( temp_boolean_7 ) goto l_for_fim_2;
temp_int_6= j+ 1;
temp_int_7 = sortArray_int[temp_int_6];
temp_int_8 = sortArray_int[j];
temp_boolean_6 = temp_int_8>temp_int_7;
  if( !temp_boolean_6 ) goto l_if_fim_1;
temp_int_5 = sortArray_int[j];
sortArray_int[j] = sortArray_int[temp_int_6];
sortArray_int[temp_int_6] = temp_int_5;
  l_if_fim_1:;

 j = j + 1;
 goto l_for_cond_2; l_for_fim_2:;

 i = i - 1;
 goto l_for_cond_3; l_for_fim_3:;

 int i;
  temp_int_1 = dimensao - 1;
  i = temp_int_1;
l_for_cond_2: 
  temp_boolean_1 = i >= 0;
temp_boolean_5 = !temp_boolean_1;
 if( temp_boolean_5 ) goto l_for_fim_2;
int j;
  j = 0;
l_for_cond_1: 
  temp_boolean_2 = j < i;
temp_boolean_4 = !temp_boolean_2;
 if( temp_boolean_4 ) goto l_for_fim_1;
  temp_int_4 = j + 1;
  temp_boolean_3 =   colecao[j] >   colecao[temp_int_4];
  if( !temp_boolean_3 ) goto l_if_fim_1;
  auxiliar =   colecao[j];
  temp_int_5 = j + 1;
  colecao[j] =   colecao[temp_int_5];
  temp_int_6 = j + 1;
  colecao[temp_int_6] = auxiliar;
  l_if_fim_1:;

  temp_int_3 = j + 1;
  j = temp_int_3;
 goto l_for_cond_1; l_for_fim_1:;

  temp_int_2 = i - 1;
  i = temp_int_2;
 goto l_for_cond_2; l_for_fim_2:;
