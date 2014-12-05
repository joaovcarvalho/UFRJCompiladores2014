Primacial Preludio
    Exclame "Multiplicação de Matrizes:\n";
    Indiviso x_1;
    Indiviso inteiro;
    Indiviso magnitude= 3;
    Indiviso dimensao = 4;
    Indiviso grandeza = 10;
    Indiviso acumulador = 0;
    Indiviso[3][4] matriz1;       // 3 por 4
    Indiviso[4][10] matriz2;           // 4 por 10
    Indiviso[3][10] produto;          // 3 por 10
    inteiro=0;

    Exclame "Matriz1: \n";
    Seja qual for(Indiviso i=0 ; i = i Mais 1; Tal que i Inferior a magnitude)           // Inicialização da segunda matriz
    Preludio
        Seja qual for( Indiviso j =0; j = j Mais 1; Tal que j Inferior a dimensao)
        Preludio
            matriz1[i][j] = i Mais 1;
            Exclame matriz1[i][j] " ";
        Epilogo
        Exclame "\n";
    Epilogo

    Exclame "Matriz2: \n";
    Seja qual for( i=0 ; i = i Mais 1; Tal que i Inferior a dimensao)           // Inicialização da segunda matriz
    Preludio
        Seja qual for( j =0; j = j Mais 1; Tal que j Inferior a grandeza)
        Preludio
            matriz2[i][j] = i Mais 1;
            Exclame matriz2[i][j] " ";
        Epilogo
        Exclame "\n";
    Epilogo

    Seja qual for( i =0; i = i Mais 1; Tal que i Inferior a magnitude)                  //Multiplicação
        Seja qual for( j=0 ; j = j Mais 1; Tal que j Inferior a grandeza)
        Preludio
            acumulador=0;
            Seja qual for( Indiviso k=0 ; k = k Mais 1; Tal que k Inferior a dimensao) Preludio
                acumulador = acumulador  Mais matriz1[i][k] Vezes  matriz2[k][j];
            Epilogo
            produto[i][j] = acumulador;
        Epilogo

    Exclame "Resultado: \n";
    Seja qual for( i=0 ; i = i Mais 1; Tal que i Inferior a magnitude)           // Inicialização da segunda matriz
    Preludio
        Seja qual for( j =0; j = j Mais 1; Tal que j Inferior a grandeza)
        Preludio
            Exclame produto[i][j] " ";
        Epilogo
        Exclame "\n";
    Epilogo
Epilogo