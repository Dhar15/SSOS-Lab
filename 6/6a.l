/* Question - Write a LEX program to eliminate comment lines in a C program and copy the
   resulting program into a separate file. */
   
%{
	#include<stdio.h>
	int c=0;
%}
%%
[/][/][a-zA-Z0-9\t ]*		      {c++;printf(" ");}
[/][*][a-zA-Z0-9\n\t ]*[*][/]	{c++;printf(" ");}
%%
void main(int argc, char *argv[])
{
	yyin = fopen(argv[1],"r");
	yyout = fopen(argv[2],"w");
	yylex();
	printf("The number of comment lines = %d\n", c);
}
int yywrap() {
	return 1;
}
