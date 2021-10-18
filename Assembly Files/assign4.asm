***************************************
*
* Name: Nathan Toepke
* PawPrint ID:  nst9fk 
* Date: 3.23.21
* Lab 4
*
* Program description: Program evaluates the values stored in N
* and stores if that value is prime in an array PRIME by utilizing an
* algorithm from Lab 3 in a subroutine.
*
*
* Pseudocode of Main Program:
* 	#define SENTIN $FF
* 	unsigned int N[11] = [1,2,11,14,31,32,37,241,251,252,$FF];
* 	unsigned int prime[10];
*	while (*N != SENTIN)
*	{
*		*prime = Subroutine(*N);
*		N++;
*		prime++;
*	}
*---------------------------------------
*
* Pseudocode of Subroutine:
* unsigned int prime = 1;
*	unsigned int divisor = 2;
*	unsigned int ncopy = N;
*	unsigned int dividend = ncopy;
*	if (ncopy == 1)
*	{
*		prime = 0;
*	}
*	else
*	{
*		while (divisor < ncopy)//loop through all possible divisors
*		{
*			while (divisor <= dividend) //looped division
*			{
*				dividend -= divisor;
*				
*			}
*			divisor++;
*			if (dividend == 0)
*			{
*				prime = 0;
*			}
*			dividend = ncopy;
*		}
*	}
*	return prime;
*	
***************************************
* start of data section

	ORG $B000
N	FCB     1, 2, 11, 14, 31, 32, 37, 241, 251, 252, $FF     
SENTIN	EQU	$FF
    
	ORG $B010
PRIME	RMB     10   
NPOINT	RMB 2
* define any other variables that you might need here
* remember that your subroutine must not access any of these variables, including
* N and PRIME

	ORG $C000
	LDS	#$01FF		initialize stack pointer
* start of your program
	LDX #N			Load the address of N into the X register for storage later
	LDY #PRIME			Load the address of PRIME into the Y register to store data into the memory later
	STX NPOINT			Store the address of N into a local variable, as the X register will be overwritten by subroutine
WHILE LDX NPOINT			Load Pointer to N into X register for comparison
	LDAA 0,X			Load element of N that pointer is currently at into A register for while loop comparison
	CMPA #SENTIN		while (*N != SENTIN)	Compare element of N to SENTIN, which is $FF 
	BEQ ENDWHILE		If the value at N equals the SENTIN value, branch to end of program
	JSR CPRIME			Call subroutine, where element of N is passed by value in the A register
	PULA 				Upon return from subroutine, pull the return value off of the stack into A register
	STAA 0,Y			*prime = Subroutine(*N); store return into Y register's pointed to location
	INC NPOINT+1		N++;
	INY				prime++;
	BRA WHILE			} Loop continues
ENDWHILE	STOP			END of program

* define any other variables that you might need here using RMB (not FCB or FDB)
* remember that your main program must not access any of these variables, including

PRIMEFLAG	RMB   1		PRIMEFLAG is 1 if an element is prime, 0 if the element is not
DIVISOR   	RMB	1		DIVISOR is used in the loop to execute division and check if a number is prime
DIVIDEND	RMB	1		DIVIDEND holds an element, and is used in the loop for division to check if a number is prime
NCOPY		RMB	1		NCOPY holds the element that was passed by reference in the A register
	ORG $D000
* start of your subroutine 
* start of your program
CPRIME	STAA  NCOPY		save N from A register ( as parameter ) to local variable
		LDAA	#1		Load 1 to A register to store into prime
		STAA	PRIMEFLAG		prime = 1;
		LDAA	#2		Load 1 to A register to store into divisor
		STAA	DIVISOR	divisor = 2;
		LDAA	N		Load N to A register to store into dividend
		STAA	DIVIDEND	dividend = N;
IF1		LDAA 	#1		Load 1 into A register to compare to N
		CMPA	NCOPY		if ( N == 1)
		BNE	ELSE1		{	Branch if Not Equal
THEN1		CLRA			Clear A register to store into prime
		STAA	PRIMEFLAG		prime = 0;
		BRA	ENDIF1	}	Always branch to complete if statement
ELSE1		NOP			NOP to allow for ELSE1 Label
WHILE2	LDAB	DIVISOR	Load divisor to B register to compare to N
		CMPB	NCOPY		while (divisor < N)
		BHS	ENDWHILE2	{			Branch if Lower or same
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
THEN		CLR	PRIMEFLAG		prime = 0;			
ENDIF		LDAA	NCOPY		}				Load N into A register to store in DIVIDEND
		STAA	DIVIDEND	dividend = N;		store N in dividend
		BRA	WHILE2	}				Branch always to continue loop
ENDIF1	NOP			NOP for label spacing for ENDIF1
ENDWHILE2	PULX			pull the subroutine return PC off the stack
		LDAA	PRIMEFLAG	return prime;
		PSHA			puts return item onto the stack for retrieval
		PSHX			replaces the subroutine return PC on the stack so that RTS will work correctly
		RTS			End of subroutine	


