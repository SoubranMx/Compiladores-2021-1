%{
%}

id [a-zA-Z][a-zA-Z0-9]*
entero  [0-9]+
real    [0-9]*"."[0-9]+

%%
int {return INT;}
float   {}
{id}