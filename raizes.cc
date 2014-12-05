Diade discriminante(Diade a, Diade b, Diade c) 
Preludio
	Restitua b Vezes b Menos 4 Vezes a Vezes b;
Epilogo

Diade modulo(Diade n) Preludio
    Na hipotese de (n Inferior a 0) Preludio
        Restitua n Vezes (Menos 1);
    Epilogo
    Salvo Preludio
        Restitua n;
    Epilogo
Epilogo

Diade raiz(Diade n, Diade r) Preludio
    Na hipotese de(modulo(r Menos (n Sobre r)) Inferior a 0.00001 Bem como r Divergente a 0) Preludio
        Restitua r;
    Epilogo

    Na hipotese de (r Equivalente a 0) Preludio
        Restitua raiz(n, (n Sobre 2 Mais 2) Sobre 2);
    Epilogo
    Salvo Preludio
        Restitua raiz(n, ((n Sobre r)Mais r) Sobre 2);
    Epilogo

Epilogo


Primacial Preludio
	Diade a,b,c;
	Exclame " Raizes =======================\n";
	Exclame "Qual o valor de a ? ";
	Averigue >> a;

	Exclame "Qual o valor de b ? ";
	Averigue >> b;

	Exclame "Qual o valor de c ? ";
	Averigue >> c;

	Exclame a b c;

	Diade delta = discriminante(a,b,c);
	Diade r1,r2;
	Na hipotese de (delta Superior a 0) Preludio
		r1 = (((Menos b) Mais raiz(discriminante(a,b,c))) Sobre (2 Vezes a))
		r2 = (((Menos b) Menos raiz(discriminante(a,b,c))) Sobre (2 Vezes a))
		Exclame "Discriminante>0  ---> Raizes reais :"r1" e "r2
	Epilogo
	Salvo Na hipotese de (delta Equivalente a 0) Preludio
		r1 = ((Menos b) Sobre (2 Vezes a))
		Exclame "Discriminante=0  ---> Raizes reais:"r1" e "r1
	Salvo Na hipotese de (delta Inferior a 0) Preludio
		r1 = (((Menos b) Mais raiz(Menos discriminante(a,b,c))) Sobre (2 Vezes a))
		r2 = (((Menos b) Menos raiz(Menos discriminante(a,b,c))) Sobre (2 Vezes a))
		Exclame "Discriminante<0  ---> Raizes imaginarias :"r1"i e "r2"i"
Epilogo