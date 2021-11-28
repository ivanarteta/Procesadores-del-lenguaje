algoritmo fibonacciInferior;
    ent n, i: entero;
{Prec: n = N AND N > 0}
    var
        f, g: entero;
    fvar
    f:= 1;
    g:= 1;
    i:= 0;
    mientras g <= n hacer
        g:= g + f;
        f:= g - f;
        i:= i + 1
    fmientras
{Post: n = N AND fib(i) <= N <= fib(i+1)}
falgoritmo