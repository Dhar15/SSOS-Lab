%{
	#include<stdlib.h>
	#include<stdio.h>
	int id=0,dig=0,key=0,op=0;
%}
%token DIGIT ID KEY OP
%%
input: DIGIT input {dig++;} 
| ID input  {id++;}
| KEY input {key++;}
| OP input  {op++;}
| DIGIT     {dig++;} 
| ID        {id++;}
| KEY       {key++;}
| OP        {op++;}
;
%%
#include<stdio.h>
extern int yylex();
extern int yyparse();
extern FILE *yyin;
void main() {
	FILE *myfile = fopen("kshitij.c","r");
	if(!myfile) {
		printf("Cannot open kshitij.c!");
		return -1;
	}
	yyin = myfile;
	do {
		yyparse();
	} while(!feof(yyin));
	printf("Numbers = %d\nKeywords = %d\nIdentifiers = %d\nOperators=%d\n", dig,key,id,op);
}
void yyerror() {
	printf("Parse Error!!!");
	exit(-1);
}
