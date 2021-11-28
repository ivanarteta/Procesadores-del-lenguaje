algoritmo intercambio;
    const
        f = 3;
    fconst
    ent a, b: entero;
    sal a, b: entero;
{Prec: a= A AND b = B}
    var
        aux: entero;
        x: booleano;
    fvar
    aux:= a;
    a:= b;
    b:= aux;
    aux := a + b
{Post: b=A AND a = B}
falgoritmo