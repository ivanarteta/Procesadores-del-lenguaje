algoritmo raizAproximada;
    ent n, r: entero;
{Prec: n = N AND N >= 1}
    var
        a, b: entero;
    fvar
    r:= 0;
    a:= 1;
    bi:= 1;
    mientras a <= n hacer
        a:= a + 3 * b + 3 * r + 4;
        b:= b + 2 * r + 3;
        r := r + 1
    fmientras
{Post: r^3 <= N < (r + 1)^3}
falgoritmo