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

	creat_Inv_sbox() ;

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

	//printf("addroundkey\n" ) ;

	printf("Plaintext\n");
	displaystate(state);


	addroundkey(state,roundkey,0);
	//===================================== addroundkey=======================================
	for(int i = 1 ;i<10;i++)
	{
		//printf("subbyte: \n") ;
		subbytes(state) ;
		//====================================subbyte=========================================
		//printf("shiftrow: \n") ;
		shiftrow(state);
		//====================================shiftrow========================================
		//printf("Mixcolumn: \n") ;
		mixcolumn(state);
		//====================================Mixcolumn========================================
		//printf("addroundkey\n" ) ;
		addroundkey(state,roundkey,i);
		//===================================== addroundkey=======================================
		
		//displaystate(state);
		//printf("\n");
	}
	//printf("subbyte: \n") ;
	subbytes(state) ;
	//====================================subbyte=========================================
	//printf("shiftrow: \n") ;
	shiftrow(state);
	//====================================shiftrow========================================
	//printf("addroundkey\n" ) ;
	addroundkey(state,roundkey,10);
	//===================================== addroundkey=======================================
	printf("Encrytion\n");
	displaystate(state);

	//===================================== Inv_STEP=======================================




	addroundkey(state,roundkey,10);
	//displaystate(state);
	//===================================== addroundkey=======================================
	for(int i = 9 ;i>0;i--)
	{
		Inv_shiftrow(state);
		//displaystate(state);
		//===================================== Inv_shiftrow=======================================
		Inv_subbytes(state);
		//displaystate(state);
		//===================================== Inv_subbyte=======================================
		addroundkey(state,roundkey,i);
		//displaystate(state);
		//===================================== addroundkey=======================================
		Inv_mixcolumn(state);
		//displaystate(state);
		//===================================== Inv_mixcolumn=======================================
	}
	Inv_shiftrow(state);
	//displaystate(state);
	//===================================== Inv_shiftrow=======================================
	Inv_subbytes(state);
	//displaystate(state);
	//===================================== Inv_subbyte=======================================
	addroundkey(state,roundkey,0);
	printf("Decrytion\n");
	displaystate(state);
	//===================================== addroundkey=======================================







	return 0;

}