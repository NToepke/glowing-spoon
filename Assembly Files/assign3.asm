**************************************
*
* Name: Nathan Toepke
* PawPrint ID:NST9FK
* Date: 3/8/21
* Lab3
*
* Program description:
*
* Pseudocode:
*
*	#define N 251
*
*    	unsigned int prime = 1;
*    	unsigned int divisor = 2;
*    	unsigned int dividend = N;
*    	if ( N == 1)
*    	{
*        	prime = 0;
*    	}
*    	else
*    	{
*        	while (divisor < N)//loop through all possible divisors
*        	{
*        
*            	while (divisor <= dividend) //looped division
*            	{
*                	dividend -= divisor;
*            	}
*			divisor++;
*            	if (dividend == 0)
*            	{
*                	prime = 0;
*            	}
*            	dividend = N;
*        	}
*    	}
**************************************

* start of data section

		ORG $B000
N		FCB   71     
    
		ORG $B010
PRIME		RMB   1
DIVISOR   	RMB	1
DIVIDEND	RMB	1

* define any other variables that you might need here

		ORG $C000
* start of your program
		LDAA	#1		Load 1 to A register to store into prime
		STAA	PRIME		prime = 1;
		LDAA	#2		Load 1 to A register to store into divisor
		STAA	DIVISOR	divisor = 2;
		LDAA	N		Load N to A register to store into dividend
		STAA	DIVIDEND	dividend = N;
IF1		LDAA 	#1		Load 1 into A register to compare to N
		CMPA	N		if ( N == 1)
		BNE	ELSE1		{	Branch if Not Equal
THEN1		CLRA			Clear A register to store into prime
		STAA	PRIME		prime = 0;
		BRA	ENDIF1	}	Always branch to complete if statement
ELSE1		NOP			NOP to allow for ELSE1 Label
WHILE		LDAB	DIVISOR	Load divisor to B register to compare to N
		CMPB	N		while (divisor < N)
		BHS	ENDWHILE	{			Branch if Lower or same
WHILE1	CMPB	DIVIDEND	while (divisor < dividend) DIVISOR is already in register B
		BHI	ENDWHILE1	{			Branch if Higher than
		LDAA	DIVIDEND				Load Dividend for subtraction
		SBA						Perform subtraction of dividend -= divisor
		STAA	DIVIDEND	dividend -= divisor;	store result of dividend - divisor in dividend
		BRA	WHILE1	}		branch always to continue loop
ENDWHILE1	INCB					Increment Divisor as loop counter
		STAB	DIVISOR	divisor++;	store loop counter
IF		CMPA	#0		if (dividend == 0)	check for prime
		BNE	ENDIF		{				Branch if Not Equal
THEN		CLR	PRIME		prime = 0;			
ENDIF		LDAA	N		}				Load N into A register to store in DIVIDEND
		STAA	DIVIDEND	dividend = N;		store N in dividend
		BRA	WHILE		}				Branch always to continue loop
ENDIF1	NOP					NOP to allow for ENDIF1 Label
ENDWHILE	STOP					End of program
		




