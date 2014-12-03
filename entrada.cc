Indiviso inteiro;
Booliano boolean;
Diade coracao;
Irresoluto Universo;
Grafema letra;
Manifesto poema;

Indiviso[10] array;

Indiviso MDC(Indiviso a, Indiviso b ) Preludio
	Na hipotese de(b Equivalente a 0)
		Restitua a;

	Restitua MDC(b, a Remanescente b);
Epilogo

Primacial Preludio
	// Testando o if
	// coracao = 100.20;
	// Na hipotese de ( coracao Equivalente a 100.10)
	// 	Preludio
	// 		Exclame "Foi";
	// 	Epilogo
	// Salvo
	// 	Preludio
	// 		Exclame "Não foi";
	// 	Epilogo
		
	// inteiro = 100;
	// // Testando o While
	// Ao passo que(inteiro Superior a 0)
	// Preludio
	// 	Exclame inteiro "\n";
	// 	inteiro = inteiro Menos 1;
	// Epilogo

	// // Testando o for
	// Seja qual for( Indiviso i = 0; i = i Mais 1; Tal que i Inferior a 100  )
	// 	Exclame i "\n";

	// Tesytando o Do while
	// Averigue >> inteiro;
	// Realize
	// Preludio
	// 	Exclame inteiro "\n";
	// 	inteiro = inteiro Menos 1;
	// Epilogo
	// Ao passo que(inteiro Superior a 0);
	Indiviso [3][4] colecao;
	inteiro=0;
	Seja qual for( Indiviso i = 0 ; i = i Mais 1; Tal que i Inferior a 3)
		Seja qual for( Indiviso j = 0 ; j = j Mais 1; Tal que j Inferior a 4)
		Preludio
			colecao[i][j] = inteiro;
			inteiro = inteiro Mais 1;
		Epilogo
	Seja qual for( i = 0 ; i = i Mais 1; Tal que i Inferior a 3)
		Seja qual for( j = 0 ; j = j Mais 1; Tal que j Inferior a 4)
		Preludio
			Exclame(colecao[i][j]);
		Epilogo
Epilogo