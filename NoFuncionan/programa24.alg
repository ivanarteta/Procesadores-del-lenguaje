algoritmo sumaDeCoeficientesBinomiales;
    ent n, r: entero;
{Prec: n = N AND N >= 1}
    var
        c, j: entero;
    fvar
    j:= 0;
    c:= 1;
    r:= 1;
    mientras j <> n hacer
        c:= (c * (n - j)) div (j + 1);
        r:= r + c;
        j := j + 1
    fmientras
{Post: n = N AND r= SUMATORIO[n, i=0] C(n,i) }
falgoritmo
