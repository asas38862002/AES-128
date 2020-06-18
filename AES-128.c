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
	unsigned char 	roundkey[4][44]={ {0x2B,0x28,0xab,0x09},
																		   {0x7e,0xae,0xf7,0xcf},
																		   {0x15,0xd2,0x15,0x4f},
																		   {0x16,0xa6,0x88,0x3C},
																	    } ;
	creat_sbox() ;

	keyExpansion(roundkey);


	printf("roundkey:\n");
	for(int k =0 ; k<11 ;k++)
	{
		printf("state %d:\n",k);
		for(int i =0 ; i<4 ;i++)
		{
			for(int j =0 ; j<4 ;j++)
			{
				printf("%x ",roundkey[i][j+4*k]);
				
			}
			printf("\n");
		}
	}


	unsigned char   state[4][4]={
								 {0x11,0X24,0X28,0X44},
								 {0x01,0x08,0x19,0x49},
								 {0x66,0x55,0xF4,0xD6},
								 {0x18,0x21,0x27,0x37}
								};
	unsigned char   state_prime[4][4]={0};
	
	//printf("%X \n",a)	;	
	//printf("%X \n",b)	;
	/*
	printf("test:%x\n",mutiplication(0x02,0x82) ) ;
	printf("test:%x\n",mutiplication(0x03,0x30) ) ;
	printf("test:%x\n",mutiplication(0x01,0xBF) ) ;
	printf("test:%x\n",mutiplication(0x01,0x9A) ) ;
*/
	//===================================== Build s-box table=======================================


	//===================================== display s-box table=======================================

	printf("subbyte: \n") ;
	subbytes(state) ;
	printf("\n");
	//====================================subbyte=========================================
	printf("shiftrow: \n") ;
	shiftrow(state);

	//====================================shiftrow========================================
	printf("Mixcolumn: \n") ;
	mixcolumn(state);


	return 0;

}