algoritmo megaEjemplo;
    accion MCDmcm(ent a, b: entero; sal mcd, mcm: entero;);
        var
            x, z: entero;
        fvar
        x:= a;
        z:= b;
        mientras x <> z hacer
            si x > z -> x := x-z
            [] x < z -> z := z-x
            fsi
        fmientras;
        mcd:= x;
        mcm := (a*b) div mcd
    faccion

    funcion maxComDiv(a, b: entero;) dev mcd: entero;
        var
            z: entero;
        fvar
        mcd:= a;
        z:= b;
        mientras mcd <> z hacer
            si mcd > z -> mcd := mcd-z
            [] mcd < z -> z := z-mcd
            fsi
        fmientras
        dev mcd
    ffuncion

    ent aux, bau: entero;
    sal aux, bau: entero;
    {Precondicion}
        continuar
    {Postcondicion}
falgoritmo