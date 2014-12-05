
Indiviso MDC(Indiviso a, Indiviso b) Preludio
    Na hipotese de(b Equivalente a 0)
        Restitua a;
    Salvo
        Restitua MDC(b, a Remanescente b);
Epilogo

Primacial Preludio
    Indiviso a;
    Indiviso b;
    Indiviso c;
    Exclame " MDC =======================\n"; 
    Exclame "Qual o valor de a ? ";
    Averigue >> a;

    Exclame "Qual o valor de b ? ";
    Averigue >> b;

    Exclame "MDC de " a " e " b  ": " MDC(a, b) "\n";
Epilogo