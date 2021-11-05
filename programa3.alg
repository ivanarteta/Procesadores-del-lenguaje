algoritmo orden3;
    ent a, b, c: entero; sal max, min, med: entero;
    "Literal string";
    'wasd';
    {Esto es un comentario}
{Prec: a = A AND b = B AND c = C}
    si A >= b y a >= c ->
        max := a;
        si b >= c ->mEd := b; MIn := c
        [] b <c ->med := c; min := b
        fsi
    [] b >= a y b >= c ->
        max := b;
        si a >= c ->med := a; min := c
        [] a <c ->med := c; min := a
        fsi
    [] c >= b y c >= a o c = 45e+34->
        MAX := c;
        si b >= a ->med := b; min := a
        [] b <a ->med := a; min := b
        fsi
    fsi
@
{Post: a=A AND b = B AND c= C ...}
falgoritmo