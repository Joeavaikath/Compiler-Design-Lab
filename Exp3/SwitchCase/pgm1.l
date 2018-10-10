%{
#include "y.tab.h"
%}

id [a-z]([a-zA-Z]|[0-9])*
num [0-9]*
op [\+\-\/\*]

%%

"switch" {return SW;}
"("      {return OB;}
")"      {return CB;}
"\n"	 {return NL;}
"{"	 {return COB;}
"}"	 {return CCB;}
"case" 	 {return CS;}
":"	 {return Q;}
"break"	 {return BR;}
";"	 {return SEM;}
{num}	 {return NUM;}
{id}     {return ID;}
"="	 {return EQ;}
{op}	 {return OP;}
" "
%%


int yywrap(){

return 0;

}

