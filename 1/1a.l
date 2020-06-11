/* Question - Write a LEX program to recognize valid arithmetic expression. Identifiers in the expression 
   could be only integers and operators could be + and *. Count the identifiers & operators 
   present and print them separately. */

%{
	#include<stdio.h>
	int id=0, optr=0,p=0;
%}
%%
[0-9]+		{id++;printf("Identifier is %s\n", yytext);}
[+*]		  {optr++;printf("Operator is %s\n",yytext);}
[(]		    {p++;}
[)]		    {p--;}

%%
int main()
{
	printf("Enter an expression:");
	yylex();
	if(id==optr+1 && p==0 && optr>=1)
	{
		printf("This is a valid expression\n");
		printf("Count of operators = %d\nCount of identifiers= %d\n",optr,id);
	}
	else
	{
		printf("Invalid expression\n");
	}
	return 0;
}

int yywrap()
{
	return 1;
}
