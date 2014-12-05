Primacial Preludio
 
  Indiviso[10] colecao;
  colecao[0] = 2;
  colecao[1] = 10;
  colecao[2] = 3;
  colecao[3] = 5;
  colecao[4] = 7;
  colecao[5] = 4;
  colecao[6] = 9;
  colecao[7] = 8;
  colecao[8] = 1;
  colecao[9] = 6;
  Indiviso dimensao = 10;
  Indiviso auxiliar = 0;
 
  Seja qual for(Indiviso i=dimensao Menos 1; i = i  Menos  1; Tal que i Superior ou equivalente a 0)  
    Seja qual for( Indiviso j=0; j = j Mais 1;Tal que j Inferior a i)
      Na hipotese de(colecao[j] Superior a colecao[ j Mais 1 ]) 
      Preludio
        auxiliar = colecao[j];
        colecao[j] = colecao[j Mais 1];
        colecao[j Mais 1] = auxiliar;
      Epilogo

  Exclame "Foi" "\n";
  Seja qual for(Indiviso r=0; r = r Mais 1; Tal que r Inferior a 10)
  Preludio
    Exclame colecao[r] " ";
  Epilogo
Epilogo