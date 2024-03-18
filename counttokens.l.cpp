%{
#include<stdio.h>
int n=0;
%}

%%
"if"|"else"|"do"|"while"|"int"|"float"|"char"|"char"|"continue"|"break" {
	n++;
	printf("keyword %s:",yytext);
}
[a-zA-Z][a-zA-Z0-9]* {
	n++;
	printf("identifier %s:",yytext);
}
"+"|"-"|"*"|"/"|"=" {
	n++;
	printf("operator %s:",yytext);
}
[(){},:;] {
	n++;
	printf("seperator %s:",yytext);
}
[0-9]*"."[0-9]+ {
	n++;
	printf("float %s:",yytext);
}
[0-9]+ {
	n++;
	printf("integer %s:",yytext);
}
%%

int yywrap(){}

int main(){
	yylex();
	printf("total number of tokens: %d",n);
}