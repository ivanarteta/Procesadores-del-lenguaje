algoritmo factorialInferior;
    ent x, n: entero;
{Prec: x = X AND X > 0}
    var
        f: entero;
    fvar
    n:= 0;
    f:= 1;
    mientras f <= x hacer
        f:= f * (n + 2);
        n:= n + 1
    fmientras
{Post: x = X AND n! <= x < (n+1)!}
falgoritmo
