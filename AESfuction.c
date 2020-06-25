
#include<stdio.h>
#include"GFmath.h"

unsigned char mix[4][4]={
						 {0x02,0x03,0x01,0x01},
						 {0x01,0x02,0x03,0x01},
						 {0x01,0x01,0x02,0x03},
						 {0x03,0x01,0x01,0x02}
						
						};
unsigned char 	subbyte[16][16]={0} ;
unsigned char 	Inv_subbyte[16][16]={0} ;


void creat_sbox()
{
	unsigned int 	a  =0x11B ;	
	unsigned int 	b_prime  =0 ;
	for (int i = 0; i < 16; i++)
	{	
		for (int j = 0; j < 16; j++)
		{
			b_prime = GCD(a,j+16*i) ;
			subbyte[i][j] = subbyte_creat(b_prime);
		}
		//b_prime = GCD(a,i) ;
		//printf("b_prime: %X\n",b_prime);
	}
	/*
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
			printf("%X ",subbyte[i][j]);
		printf("\n");
	}  //display s-box 
*/
}


void creat_Inv_sbox()
{
	unsigned int 	a  =0x11B ;	
	unsigned int 	b_prime  =0 ;
	//unsigned  int temp  = 0x00
	for (int i = 0; i < 16; i++)
	{	
		for (int j = 0; j < 16; j++)
		{
			b_prime = Inv_subbyte_creat(j+16*i) & 0xff ;
			Inv_subbyte[i][j] = GCD(a,b_prime) ;
		}
	}
	
/*	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
			printf("%X ",Inv_subbyte[i][j]);
		printf("\n");
	}  //display Inv_s-box 
*/
}


void subbytes(unsigned char state[][4])
{
	for (int i = 0; i < 4; i++)
	{	
		for (int j = 0; j < 4; j++)
		{
			//printf("%X:= %X,%X\n",state[i][j],state[i][j]>>4 & 0XF,state[i][j] & 0XF) ;
			state[i][j]=subbyte[state[i][j]>>4 & 0XF][state[i][j] & 0XF];
			//printf("%X ",state[i][j]);
			
			//printf("%x ",state[i][j]>>4 & 0XFF) ; 
		}
		//printf("\n");
	}

}


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

	/*for (int i = 0; i < 4; i++)
	{	
		for (int j = 0; j < 4; j++)
		{
			printf("%X ",state[i][j]);
			
			//printf("%x ",state[i][j]>>4 & 0XFF) ; 
		}
		printf("\n") ;
	}*/

} 

void mixcolumn(unsigned char state[][4])
{
	unsigned char temp[4][4]={0};

	/*printf("Ori.\n");
	for (int i = 0; i < 4; i++)
	{	
		for (int j = 0; j < 4; j++)
		{
			printf("%X ",state[i][j]);
			
			//printf("%x ",state[i][j]>>4 & 0XFF) ; 
		}
		printf("\n") ;
	}*/


	for (int i = 0; i < 4; i++)
	{	
		temp[0][i] = mutiplication(0x02,state[0][i]) ^ mutiplication(0x03,state[1][i]) ^ 
					  mutiplication(0x01,state[2][i]) ^ mutiplication(0x01,state[3][i]) ;
		temp[1][i] = mutiplication(0x01,state[0][i]) ^ mutiplication(0x02,state[1][i]) ^ 
					  mutiplication(0x03,state[2][i]) ^ mutiplication(0x01,state[3][i]) ;
		temp[2][i] = mutiplication(0x01,state[0][i]) ^ mutiplication(0x01,state[1][i]) ^ 
					  mutiplication(0x02,state[2][i]) ^ mutiplication(0x03,state[3][i]) ;
		temp[3][i] = mutiplication(0x03,state[0][i]) ^ mutiplication(0x01,state[1][i]) ^ 
					  mutiplication(0x01,state[2][i]) ^ mutiplication(0x02,state[3][i]) ;					  					  

	}


	//printf("after.\n");
	for (int i = 0; i < 4; i++)
	{	
		for (int j = 0; j < 4; j++)
		{
			state[i][j] = temp[i][j] ;  
			//printf("%X ",state[i][j]); 
		}
	//	printf("\n") ;
	}

}

void keyExpansion(unsigned char roundkey[4][44])
{
	unsigned char temp[4] ={0};
	unsigned char Nword[4] ={0};
	unsigned char swap =0x00;
	unsigned char Rcon =0x01;
	unsigned int Nk   = 4 ;

	//printf("roundkey:\n");
	/*for(int i =0 ; i<4 ;i++)
	{
		for(int j =0 ; j<4 ;j++)
		{
			printf("%x ",roundkey[i][j]);
			
		}
		printf("\n");
	}*/
	//===============================roundkey==========================
	for(int kb= 3;kb<43;kb++) //first stage last word
	{
		//printf("temp: \n");
		for(int i =0 ; i<4 ;i++)
		{
			temp[i] = roundkey[i][kb];
			//printf("%X ",temp[i]); //temp get first col.
		}
		//printf("\n");
		//==================temp get first col.=======================

		if((kb+1) % Nk==0)
		{
			//printf("Rotword temp: \n");
			swap = temp[0];
			for(int i =0 ; i<3 ;i++)
			{
				temp[i] = temp[i+1];
				//printf("%X ",temp[i]); //temp get first col.
			}
			temp[3] =swap ;
			//printf("%X ",temp[3]); //temp get first col.

			//printf("\n");

			//==========================Rot word=========================
			//printf("Subword temp: \n");
			for(int i =0 ; i<4 ;i++)
			{
				temp[i]=subbyte[temp[i]>>4 & 0XF][temp[i] & 0XF];
				//printf("%X ",temp[i]);
			}
			//printf("\n");
		
			//==========================sub word=========================
			//printf("XOR Rcon: \n");
			//printf("%x",Rcon);

			temp[0] = temp[0]^Rcon ;
			for(int i =0 ; i<4 ;i++)
			{
				//printf("%X ",temp[i]);
			}	
			Rcon = mutiplication(Rcon,0x02) ;

			//printf("\n");
		
			//==========================Xor Rcon=========================
			//printf("New Word: \n");
			for(int i =0 ; i<4 ;i++)
			{
				//Nword[i] = roundkey[i][0] ^ temp[i] ;
				roundkey[i][kb+1] = 	roundkey[i][kb-3] ^ temp[i] ;
				//printf("%X ",roundkey[i][kb+1]);
			}

			//printf("\n");
	}//if roundkey is full , temp have to get k-1 stage last word 
	else 
	{
		//printf("roundkey caculation\n");
		for(int i =0 ; i<4 ;i++)
		{
			//Nword[i] = roundkey[i][0] ^ temp[i] ;
			roundkey[i][kb+1] = 	roundkey[i][kb-3] ^ temp[i] ;
			//printf("%X ",roundkey[i][kb+1]);
		}
		//printf("\n");
	}

		

	}// creat round key for loop 
/*
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
*/
}//void keyExpansion
  

void displaykeyExpansion(unsigned char roundkey[4][44])
{
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
}

void addroundkey(unsigned char state[][4],unsigned char roundkey[4][44],int round)
{
	int  stagenum = 0 ;
	//printf("state %d\n",round);
	for(int i = 0 ;i<4;i++)
	{
		for(int j = round*4 ; j<=(round+1)*4-1;j++)
		{
		    //printf("%x ",roundkey[i][j]) ;
			state[i][stagenum] = state[i][stagenum]^roundkey[i][j] ;
			//printf("%x ",state[i][stagenum]) ;
			//printf("%x XOR %X \n",state[i][stagenum],roundkey[i][j]) ;
			stagenum = stagenum + 1 ;	
		}
		stagenum = 0 ;
		//printf("\n") ;
	}

/*	printf("Oristate \n");
	for(int i = 0 ;i<4;i++)
	{
		for(int j = 0; j<4;j++)
		{
		    printf("%x ",state[i][j]) ;			
		}
		printf("\n") ;
	}
*/


}

void displaystate(unsigned char state[][4])
{
	for(int i = 0 ;i<4;i++)
	{
		for(int j = 0 ; j<4;j++)
		{
			printf("%X ",state[i][j]);

		}
		printf("\n");
	}

}
