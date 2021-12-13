algoritmo hastaDondePuedoLlegar;
    ent m, r: entero;
{Prec: m = M AND M >= 1}
    var
        q, p: entero;
    fvar
    r:= 0;
    q:= 1;
    p:= 2;
    mientras (p+q) <= m hacer
        q:= q + p;
        p:= p * 2;
        r:= r + 1
    fmientras
{Post: SUMATORIO[r, k=0] 2^k <= m < SUMATORIO[r+1, k=0] 2^k AND m = M}
falgoritmo