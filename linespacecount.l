%{
#include<stdio.h>
int lines=0,spaces=0,tabs=0;
%}

%%
[\n] {lines++}
[\t] {tabs++}
[ ] {spaces++}
%%

int yywrap(){}

int main(){
	yylex();
	printf("lines : %d",lines);
	printf("spaces : %d",spaces);
	printf("tabs : %d",tabs);
} 