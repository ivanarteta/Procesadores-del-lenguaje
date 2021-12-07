algoritmo factorial;
    ent fact, n: entero;
{Prec: n = N AND N > 0}
    var
        i, j: entero;
    fvar
    fact:= 1;
    i:= 1;
    j:= n;
    mientras i <> j + 1 hacer
        si i+1 <= j ->
            fact:= fact * i * j;
            i:= i + 1;
            j:= j + 1
        [] i+1 > j ->
            fact:= fact * j;
            j := j - 1
        fsi
    fmientras
{Post: fact = N!}
falgoritmo
