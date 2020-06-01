#include "GFmath.h"
#include<stdio.h>


int main()
{
	unsigned int 	a  =0x11B ;
	unsigned int 	b  =0x0F ;
	unsigned int 	b_prime  =0 ;
	unsigned int 	out=0x00 ;
	unsigned char 	subbyte[16][16]={0} ;

	//printf("%X \n",a)	;	
	//printf("%X \n",b)	;
	

	printf("add: %X\n",add(a,b));
	out =  mutiplication(a,b) ; 	
	printf("muti: %X\n",out);
	for (int i = 0; i < 16; i++)
	{	
		for (int j = 0; j < 16; j++)
		{
			b_prime = GCD(a,j+16*i) ;
			subbyte[j][i] = subbye(b_prime);
		}
		//b_prime = GCD(a,i) ;
		//printf("b_prime: %X\n",b_prime);
	}
	//===================================== build subbyte table=======================================
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
			printf("%X ",subbyte[j][i]);
		printf("\n");
	}



	
	return 0;

}