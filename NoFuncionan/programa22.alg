algoritmo rango;
    ent n, i: entero;
{Prec: n = N AND 1 <= N < 99}
    var
        f: entero;
        t: tabla[0..99] de entero;
    fvar
    i:= 0;
    f:= 1;
    t[0]:= 1;
    mientras f <= n hacer
        t[i+1]:= f;
        si (i+2) mod 2 = 0 -> f:= 2 * t[(i+2) div 2]
        [] (i+2) mod 2 = 1 -> f:= ((i+2) div 2) + t[i+1]
        fsi
        i:= i + 1
    fmientras
{Post: n = N AND A(i)<= n < A(i+1)}
falgoritmo