/* Question - Write YACC program to evaluate arithmetic expression involving operators: +, -,*, and /. */

%{
	#include"y.tab.h"
	extern int yylval;
%}
%%
[0-9]+	  {yylval=atoi(yytext);return num;}
[\t]	  ; 
[\n]	  {return 0;}
.	  {return yytext[0];}
%%
