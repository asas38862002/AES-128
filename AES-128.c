#include "GFmath.h"
#include<stdio.h>


int main()
{
	unsigned int 	a  =0x11B ;
	unsigned int 	b  =0x0F ;
	unsigned int 	b_prime  =0 ;
	unsigned int 	out=0x00 ;
	//printf("%X \n",a)	;	
	//printf("%X \n",b)	;
	

	printf("add: %X\n",add(a,b));
	out =  mutiplication(a,b) ; 	
	printf("muti: %X\n",out);
	b_prime = GCD(a,b) ;
	printf("b_prime: %X\n",b_prime);
	subbye(b_prime);

	
	return 0;

}