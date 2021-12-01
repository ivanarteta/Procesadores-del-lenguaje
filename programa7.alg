algoritmo orden3;
    ent a, b, c: entero; 
    sal max, min, med: entero;
{Prec: a = A AND b = B AND c = C}
    si a = 5->
        max := a;
        si b >= c ->
            med := b; 
            min := c
        [] b = 5 ->
            med := c; 
            min := b
        fsi
    fsi
{Post: a=A AND b = B AND c= C ...}
falgoritmo