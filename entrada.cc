Primacial Preludio
    Indiviso inteiro;
    Indiviso magnitude= 3;
    Indiviso dimensao = 4;
    Indiviso grandeza = 10;
    Indiviso acumulador;
    Indiviso [magnitude][dimensao] matriz1;       // 3 por 4
    Indiviso[dimensao][grandeza] matriz2;           // 4 por 10
    Indiviso[magnitude][grandeza] produto;          // 3 por 10
    inteiro=0;
    Seja qual for( Indiviso i=0 ; i = i+1; tal que i Inferior a magnitude)            // Inicialização da primeira matriz
        Seja qual for( Indiviso j=0 ; j = j+1; tal que j Inferior a dimensao)
        Preludio
            matriz1[i][j] = inteiro;
            inteiro = inteiro+1;
        Epilogo
    Seja qual for( i=0 ; i = i+1; tal que i Inferior a dimensao)           // Inicialização da segunda matriz
        Seja qual for( j =0; j = j+1; tal que j Inferior a grandeza)
        Preludio
            matriz2[i][j] = inteiro;
            inteiro = inteiro+1;
        Epilogo
    Exclame "Chegou!!onze";
    Seja qual for( i =0; i = i+1; tal que i Inferior a magnitude)                  //Multiplicação
        Seja qual for( j=0 ; j = j+1; tal que j Inferior a grandeza)
        Preludio
            acumulador=0;
            Seja qual for( Indiviso k=0 ; k = k+1; tal que k Inferior a dimensao)
                acumulador = acumulador + matriz1[i][k]* matriz2[k][j];
            produto[i,j] = acumulador;
            Exclame "Posicao " i " - " j " : "produto[i][j] "\n";
        Epilogo
Epilogo