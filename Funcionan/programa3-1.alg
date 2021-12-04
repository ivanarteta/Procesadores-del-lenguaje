algoritmo division;
	ent dividendo, divisor: entero;
	sal cociente, resto: entero; 
{Prec: dividendo=A AND divisor=B}
    var
        auxR: real;
        auxE: entero;
		resultadoReal: real;
    fvar
    
	cociente := dividendo div divisor;
	resto := dividendo mod divisor;
	resultadoReal := dividendo / divisor;
	
	auxR := resultadoReal + resto * cociente;
	auxE := - divisor
{Post: dividendo=A AND divisor=B AND cociente=floor(A/B) AND resto=A%B}
falgoritmo
