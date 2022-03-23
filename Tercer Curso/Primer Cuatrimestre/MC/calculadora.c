%{

int factor1=0,factor2=0;
char operador;
float operando1=0,operando2=0,respuesta=0;
void eval();

%}

DIGITO [0-9]
NUMERO {DIGITO}+(\.{DIGITO}+)?
OPERADOR [*/+-]

%%

{NUMERO} {
	if(factor1==0)
	{
		operando1=atof(yytext);
		factor1=1;
	}

	else if(factor2==-1)
	{
		operando2=atof(yytext);
		factor2=1;
	}

	if((factor1==1) && (factor2==1))
	{
		eval();
		factor1=0;
		factor2=0;

	}
}

{OPERADOR} {
	
	operador=(char) *yytext;
	factor2=-1;
}

[\n] {

	if(factor1==1 && factor2==1)
	{	
		eval;
		factor1=0;
		factor2=0;
	}
}	

%%


main()
{
	yylex();
}


void eval()
{
	switch(operador)
	{
		case '+':
			respuesta=operando1+operando2;
			break;

		case '-':
			respuesta=operando1-operando2;
			break;

		case '*':
			respuesta=operando1*operando2;
			break;

		case '/':
			if(operando2==0)
			{
				printf("ERROR");
				return;
			}
			else
			{
				respuesta=operando1/operando2;
			}
			break;
		default:
			printf("La operación no está disponible");
			break;
	}
	printf("La respuesta es = %lf\n",respuesta);
}