
#include<stdio.h>




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




  


