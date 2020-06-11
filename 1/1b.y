%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<ctype.h>
	int valid=1;
%}
%token num
%left '+' '-'
%left '*' '/'
%left '(' ')'
%nonassoc UMINUS
%%
exp: e		{if(valid) printf("Value of exp is %d", $1); exit(0);}
e: e'+'e	{$$ = $1 + $3;}
e: e'-'e	{$$ = $1 - $3;}
e: e'*'e	{$$ = $1 * $3;}
e: e'/'e	{if($3==0) printf("Divide by zero error\n"); 
		       else ($$ = $1 / $3);}
e:'('e')'	{$$ = $2;}
e:num		{$$ = $1;}
e:'-'e		{$$ = -$2;}
%%
int main()
{
	printf("Enter the expression\n");
	yyparse();
	printf("Invalid");
}

int yyerror() {
	valid = 0;
}
