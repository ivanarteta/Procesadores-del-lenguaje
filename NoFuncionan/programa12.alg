algoritmo megaEjemplo;
    tipo
        a = entero;
        b = real;
        c = cadena;
    ftipo 
    const 
        d = 156;
        e = 'Esto es una cadena';
    fconst

    accion MCDmcm(ent a, b: entero; sal mcd, mcm: entero);
    funcion maxComDiv(a, b: entero) dev mcd: entero;

    accion MCDmcm(ent a, b: entero; sal mcd, mcm: entero);
        var
            x, y: entero;
        fvar
        x:= a;
        y:= b;
        mientras x <> y hacer
            si x > y → x := x-y
            [] x < y → y := y-x
            fsi
        fmientras;
        mcd:= x;
        mcm := (a*b) div mcd
    faccion

    funcion maxComDiv(a, b: entero) dev mcd: entero;
        var
            y: entero;
        fvar
        mcd:= a;
        y:= b;
        mientras x <> y hacer
            si mcd > y → mcd := mcd-y
            [] mcd < y → y := y-mcd
            fsi
        fmientras;
        dev mcd;
    ffuncion

    ent aux, bau: entero;
    sal aux, bau: entero;
    {Precondicion}
        continuar
    {Postcondicion}
falgoritmo