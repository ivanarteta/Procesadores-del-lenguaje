/* Definiciones */
letra [a-zA-Z]
cifra [0-9]
blanco [ \t\n]
identificador {letra}({letra}|{cifra})*
accion accion
algoritmo algoritmo
begin begin
booleano booleano
cadena cadena
caracter caracter
const const
continuar continuar
de de
dev dev
div div
end end
ent ent
entero entero
entsal e\/s
faccion faccion
falgoritmo falgoritmo
fconst fconst
fmientras fmientras
fpara fpara
fsi fsi
ftipo ftipo
ftupla ftupla
fvar fvar
hacer hacer
hasta hasta
mientras mientras
mod mod
no no
o o
para para
real real
ref ref
sal sal
si si
tabla tabla
tipo tipo
tupla tupla
var var
y y

/*seccion de los strings */
literal_booleano verdadero|falso
literal_cadena \'(([^\'])|\/\')*\'
literal_caracter \"[^\"]\"
literal_entero {cifra}+(e{cifra}+)?

/*seccion de los comentarios, precondiciones y postcondiciones */
comentario \{([^\}]|\/\})*\}
comentario_pre \{pre([^\}]|\/\})*\}
comentario_post \{post([^\}]|\/\})*\}

/*seccion para los operadores */
asignacion :=
comparador <|>|<=|>=|<>
composicion_secuencial ;
definicion :
entonces ->
fin_array ]
fin_parentesis \)
igual =
inicio_array \[
inicio_parentesis \(
op_division \/
op_multiplicacion \*
op_resta \-
op_suma \+
separador ,
si_no_si \[\]
subrango \.\.
%%
	/* Reglas */
{entonces}          {printf("SCANNER: entonces\n");}
{accion}            {printf("SCANNER: accion\n");}
{algoritmo}         {printf("SCANNER: algoritmo\n");}
{booleano}          {printf("SCANNER: tipo_booleano\n");}
{cadena}            {printf("SCANNER: tipo_cadena\n");}
{caracter}          {printf("SCANNER: tipo_caracter\n");}
{const}             {printf("SCANNER: const\n");}
{continuar}         {printf("SCANNER: continuar\n");}
{de}                {printf("SCANNER: de\n");}
{dev}               {printf("SCANNER: dev\n");}
{div}               {printf("SCANNER: div\n");}
{ent}               {printf("SCANNER: ent\n");}
{entero}            {printf("SCANNER: tipo_entero\n");}
{entsal}            {printf("SCANNER: entsal\n");}
{faccion}           {printf("SCANNER: faccion\n");}
{falgoritmo}        {printf("SCANNER: falgoritmo\n");}
{fconst}            {printf("SCANNER: fconst\n");}
{ffuncion}          {printf("SCANNER: ffuncion\n");}
{fmientras}         {printf("SCANNER: fmientras\n");}
{fpara}             {printf("SCANNER: fpara\n");}
{fsi}               {printf("SCANNER: fsi\n");}
{ftipo}             {printf("SCANNER: ftipo\n");}
{ftupla}            {printf("SCANNER: ftupla\n");}
{funcion}           {printf("SCANNER: funcion\n");}
{fvar}              {printf("SCANNER: fvar\n");}
{hacer}             {printf("SCANNER: hacer\n");}
{mientras}          {printf("SCANNER: mientras\n");}
{mod}               {printf("SCANNER: mod\n");}
{no}                {printf("SCANNER: no\n");}
{o}                 {printf("SCANNER: o\n");}
{para}              {printf("SCANNER: para\n");}
{hasta}             {printf("SCANNER: hasta\n");}
{real}              {printf("SCANNER: tipo_real\n");}
{ref}               {printf("SCANNER: ref\n");}
{sal}               {printf("SCANNER: sal\n");}
{si}                {printf("SCANNER: si\n");}
{tabla}             {printf("SCANNER: tabla\n");}
{tipo}              {printf("SCANNER: tipo\n");}
{tupla}             {printf("SCANNER: tupla\n");}
{var}               {printf("SCANNER: var\n");}
{y}                 {printf("SCANNER: y\n");}
{comentario_pre}    {printf("SCANNER: comentario pre\n");}
{comentario_post}   {printf("SCANNER: comentario post\n");}
{comentario}        {printf("SCANNER: comentario\n");}
{asignacion}        {printf("SCANNER: asignacion\n");}
{composicion_secuencial} {printf("SCANNER: composicion_secuencial\n");}
{separador}         {printf("SCANNER: separador\n");}
{subrango}          {printf("SCANNER: subrango\n");}
{definicion}        {printf("SCANNER: definicion\n");}
{si_no_si}          {printf("SCANNER: si_no_si\n");}
{comparador}        {printf("SCANNER: comparador %s\n", yytext); yylval.val_string = strdup(yytext);}
{igual}             {printf("SCANNER: igual\n");} 			
{inicio_array}      {printf("SCANNER: inicio_array\n");} 		
{fin_array}         {printf("SCANNER: fin_array\n");}
{inicio_parentesis} {printf("SCANNER: inicio_parentesis\n");}
{fin_parentesis}    {printf("SCANNER: fin_parentesis\n");}
{literal_entero}    {printf("SCANNER: entero: %d\n", (int) atof(yytext)); yylval.val_int=(int) atof(yytext);}
{cifra}+\.{cifra}*(e{cifra}+)?/[^\.]      {printf("SCANNER: real: %f\n", atof(yytext)); yylval.val_double = atof(yytext);}
{literal_booleano}  {printf("SCANNER: booleano: %s\n", yytext); yylval.val_int = (strcasecmp(yytext, "VERDADERO")) ? 1 : 0;}
{literal_caracter}  {printf("SCANNER: caracter: %c\n", yytext[1]); yylval.val_char = yytext[1];}
{literal_cadena}    {printf("SCANNER: cadena: %s\n", yytext); yylval.val_string = strdup(yytext);}
{identificador}     {printf("SCANNER: identificador: %s\n", yytext);  yylval.val_string = strdup(yytext);}
{op_division}       {printf("SCANNER: division\n");}
{op_multiplicacion} {printf("SCANNER: multiplicacion\n");}
{op_suma}           {printf("SCANNER: suma\n");}
{op_resta}          {printf("SCANNER: resta\n");}
{blanco}+      
%%
	/* Código */
    /* int main(int argc, char *argv[]) {
	if (argc > 1){
		yyin = fopen(argv[1], "r");	
	}
	yylex();
	if (argc > 1){
		fclose(yyin);
	}
} */
