algoritmo seno;
    ent x, s: real; n: entero;
{Prec: x = X AND -pi <= X < pi AND n = N AND N >= 0}
    var
        p, q, r, k: entero;
    fvar
    k:= 0;
    r:= 1;
    p:= x;
    q:= 1;
    s:= x;
    mientras k <> n hacer
        r:= r * (-1);
        p:= p * x * x:
        q:= q * (2 * k + 2) * (2 * k + 3);
        s:= s + (r * p div q);
        k:= k + 1
    fmientras
{Post: s= SUMATORIO[n, i=0] (-1^i) * x^(2 - i + 1) / (2 * i + 1)! AND x = X AND n = N}
falgoritmo

