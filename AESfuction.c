
#include<stdio.h>
#include"GFmath.h"

unsigned char mix[4][4]={
						 {0x02,0x03,0x01,0x01},
						 {0x01,0x02,0x03,0x01},
						 {0x01,0x01,0x02,0x03},
						 {0x03,0x01,0x01,0x02}
						
						};



void shiftrow(unsigned char state[][4])
{

	unsigned char tmp = 0x00 ;
	tmp = state[1][0] ;
	for (int i = 0; i < 3; i++)
	{
		state[1][i] = state[1][i+1] ; 
	}
	state[1][3] = tmp ;
	//=============row 1 shift============================

	tmp = state[2][0]         ;
	state[2][0] = state[2][2] ;
	state[2][2] = tmp         ;

	tmp = state[2][1]         ;
	state[2][1] = state[2][3] ;
	state[2][3] = tmp         ;
	//=============row 2 shift 2times============================
	tmp = state[3][3] ;
	for (int i = 3; i >0; i--)
	{
		state[3][i] = state[3][i-1] ; 
	}
	state[3][0] = tmp ;

	for (int i = 0; i < 4; i++)
	{	
		for (int j = 0; j < 4; j++)
		{
			printf("%X ",state[i][j]);
			
			//printf("%x ",state[i][j]>>4 & 0XFF) ; 
		}
		printf("\n") ;
	}

} 

void mixcolumn(unsigned char state[][4])
{

	printf("Ori.\n");
	for (int i = 0; i < 4; i++)
	{	
		for (int j = 0; j < 4; j++)
		{
			printf("%X ",state[i][j]);
			
			//printf("%x ",state[i][j]>>4 & 0XFF) ; 
		}
		printf("\n") ;
	}



	for (int i = 0; i < 1; i++)
	{	
		state[0][i] = mutiplication(0x02,state[0][i]) ^ mutiplication(0x03,state[1][i]) ^ 
					  mutiplication(0x01,state[2][i]) ^ mutiplication(0x01,state[3][i]) ;
		state[1][i] = mutiplication(0x01,state[0][i]) ^ mutiplication(0x02,state[1][i]) ^ 
					  mutiplication(0x03,state[2][i]) ^ mutiplication(0x01,state[3][i]) ;
		state[2][i] = mutiplication(0x01,state[0][i]) ^ mutiplication(0x01,state[1][i]) ^ 
					  mutiplication(0x02,state[2][i]) ^ mutiplication(0x03,state[3][i]) ;
		state[3][i] = mutiplication(0x03,state[0][i]) ^ mutiplication(0x01,state[1][i]) ^ 
					  mutiplication(0x01,state[2][i]) ^ mutiplication(0x02,state[3][i]) ;					  					  

	}	

	printf("after.\n");
	for (int i = 0; i < 4; i++)
	{	
		for (int j = 0; j < 4; j++)
		{
			printf("%X ",state[i][j]);
			
			//printf("%x ",state[i][j]>>4 & 0XFF) ; 
		}
		printf("\n") ;
	}

}


  


