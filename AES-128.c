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
	creat_sbox() ;//create s-box  

	keyExpansion(roundkey); //create round key  

	//displaykeyExpansion(roundkey);

	unsigned char   state[4][4]={
								 {0x32,0X88,0X31,0XE0},
								 {0x43,0x5A,0x31,0x37},
								 {0xF6,0x30,0x98,0x07},
								 {0xA8,0x8D,0xA2,0x34}
								};
	//unsigned char   state_prime[4][4]={0};
	
	//printf("%X \n",a)	;	
	//printf("%X \n",b)	;
	/*
	printf("test:%x\n",mutiplication(0x02,0x82) ) ;
	printf("test:%x\n",mutiplication(0x03,0x30) ) ;
	printf("test:%x\n",mutiplication(0x01,0xBF) ) ;
	printf("test:%x\n",mutiplication(0x01,0x9A) ) ;
*/


	addroundkey(state,roundkey,0);
	//===================================== addroundkey=======================================
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