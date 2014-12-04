
Indiviso MDC(Indiviso a, Indiviso b) Preludio
    Na hipotese de(b Equivalente a 0)
        Restitua a;
    Salvo
        Restitua MDC(b, a Remanescente b);
Epilogo



Primacial Preludio

    Intervalo[1 .. 10] => Segregue[ X Superior a 5] => EmCompletude[ Exclame X "\n"; ] ;
    // Indiviso x_1;
    // Indiviso inteiro;
    // Indiviso magernitude= 3;
    // Indiviso dimensao = 4;
    // Indiviso grandeza = 3;
    // Indiviso acumulador;
    // Indiviso[3][4] matriz1;       // 3 por 4
    // Indiviso[4][3] matriz2;           // 4 por 10
    // Indiviso[3][3] produto;          // 3 por 10
    // inteiro=0;
    // Seja qual for( Indiviso i=0 ; i = i Mais 1; Tal que i Inferior a magnitude)            // Inicialização da primeira matriz
    //     Seja qual for( Indiviso j=0 ; j = j Mais 1; Tal que j Inferior a dimensao)
    //     Preludio
    //         matriz1[i][j] = i Mais 1;
    //         inteiro = inteiro Mais 1;
    //     Epilogo
    // Seja qual for( i=0 ; i = i Mais 1; Tal que i Inferior a dimensao)           // Inicialização da segunda matriz
    //     Seja qual for( j =0; j = j Mais 1; Tal que j Inferior a grandeza)
    //     Preludio
    //         matriz2[i][j] = i Mais 1;
    //         inteiro = inteiro Mais 1;
    //     Epilogo

    // Seja qual for( i =0; i = i Mais 1; Tal que i Inferior a magnitude)                  //Multiplicação
    //     Seja qual for( j=0 ; j = j Mais 1; Tal que j Inferior a grandeza)
    //     Preludio
    //         acumulador=0;
    //         Seja qual for( Indiviso k=0 ; k = k Mais 1; Tal que k Inferior a dimensao) Preludio
    //             acumulador = acumulador  Mais  matriz1[i][k] Vezes  matriz2[k][j];
    //         Epilogo
    //         produto[i][j] = acumulador;
    //         Exclame "Posicao " i " - " j " : "produto[i][j] "\n";
    //     Epilogo
Epilogo