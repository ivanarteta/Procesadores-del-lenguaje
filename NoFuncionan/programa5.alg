algoritmo factorial;
    ent fact, n: entero;
    {Prec lo que sea}
    var
        i,j:entero;
    fvar
    n := 10;
    fact := 1;
    i := 1;
    j := n;
    mientras i <> j+1 hacer
        Si i+1 <= j
            fact := fact * i * j;
            i := i + 1;
            j := j - 1
        [] i+1 > j
            fact := fact * j;
            j := j - 1
        fsi
    fmientras
    {Post lo que sea}
falgoritmo