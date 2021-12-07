algoritmo megaEjemplo;
    const 
        a = 156;
        b = 159.65;
        c = 'Esto es una cadena';
        d = "c";
        e = verdadero;
    fconst 
    ent f, g: entero; h,i: real;
    sal f, g: entero;
{Precondicion}
    var 
        x,z: entero;
        mcd:entero;
        mcm: real;
    fvar
    x:= a;
    z:= a;
    mientras 1 <> z hacer
        si x > z -> x := x-z
        [] x < z -> z := z-x
        fsi
    fmientras;
    mcd:= x;
    mcm := (a*b) div mcd
{Postcondicion}
falgoritmo