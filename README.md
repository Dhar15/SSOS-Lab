# SSOS-Lab
This repository contains the laboratory programs for System Software and Operating Systems.

### Run Lex and Yacc Programs on Ubuntu-

> sudo apt-get install flex bison

### Running Lex Programs -

> lex prog.l <br />
> cc lex.yy.c <br />
> ./a.out 

### Running Lex and Yacc Programs - 

> lex prog.l <br />
> yacc -d prog.y <br />
> cc lex.yy.c y.tab.c -ll <br />
> ./a.out
