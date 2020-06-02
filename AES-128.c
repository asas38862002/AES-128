#include "GFmath.h"
#include<stdio.h>
#include "AESfuction.h"

int main()
{
	unsigned int 	a  =0x11B ;
	unsigned int 	b  =0x0F ;
	unsigned int 	b_prime  =0 ;
	unsigned int 	out=0x00 ;
	unsigned char 	subbyte[16][16]={0} ;

	unsigned char   state[4][4]={
								 {0x11,0X24,0X28,0X44},
								 {0x01,0x08,0x19,0x49},
								 {0x66,0x55,0xF4,0xD6},
								 {0x18,0x21,0x27,0x37}
								};
	unsigned char   state_prime[4][4]={0};
	

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
			subbyte[i][j] = subbye(b_prime);
		}
		//b_prime = GCD(a,i) ;
		//printf("b_prime: %X\n",b_prime);
	}
	//===================================== Build s-box table=======================================
	/*for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
			printf("%X ",subbyte[j][i]);
		printf("\n");
	}
	*/
	//===================================== display s-box table=======================================
	
	printf("state: \n") ;
	
	for (int i = 0; i < 4; i++)
	{	
		for (int j = 0; j < 4; j++)
		{
			//printf("%X:= %X,%X\n",state[i][j],state[i][j]>>4 & 0XF,state[i][j] & 0XF) ;
			state_prime[i][j]=subbyte[state[i][j]>>4 & 0XF][state[i][j] & 0XF];
			printf("%X ",state_prime[i][j]);
			
			//printf("%x ",state[i][j]>>4 & 0XFF) ; 
		}
		printf("\n") ;
	}
	//====================================subbyte=========================================
	printf("shift row: \n") ;
	shiftrow(state_prime);



	return 0;

}