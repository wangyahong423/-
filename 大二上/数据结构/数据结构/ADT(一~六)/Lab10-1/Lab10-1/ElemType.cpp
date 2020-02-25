/***
*ElemType.cpp - ElemTypeµÄÊµÏÖ
*	
****/

#include <stdio.h>
#include "ElemType.h"

int compare(ElemType x, ElemType y)
{
	if(x==y)
		return 0;
	else 
		return 1;
}

void visit(ElemType e)
{
	printf("%d     ", e);
}