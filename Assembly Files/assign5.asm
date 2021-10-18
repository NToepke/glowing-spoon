***************************************
*
* Name: Nathan Toepke
* ID:   12556636
* Date: 04/13/21
* Lab 5
*
* Program description:
* This program will go through an array of 1-byte numbers and
* will send each number to a subroutine via call-by-value in register. 
* The subroutine will calculate if the number is a prime or not
* and will send the result back to the main program via call-by-value over stack. 
* All variables used in the subroutine will be implemented on the stack.
* The main program will store the result in the PRIME array. 
*
* Pseudocode of Main Program:
*
* unsigned int N[];
* unsigned int PRIME[];
* #define SENTIN $FF
*
* pointer1=&N[0];
* pointer2=&PRIME[0];
* while (*pointer1 != SENTIN){
*	A-register=*pointer1;
*	store pointer1 on stack;
*	call subroutine;
*	get Prime off the stack
*	store it to memory where pointer2 is pointing to;
*	get pointer 1 off stack;
*	pointer1++;
*	pointer2++;
* }
* END
*
*
*---------------------------------------
*
* Local subroutine variables
*
* unsigned int NV     -  holds the N value
* unsigned int PV     -  holds prime value
* unsigned int RV     -  jolds remainder value
*
* Pseudocode Subroutine
*
* N=data sent to subroutine;
* if(N!=1){
*   PRIME=1;	
*   i=2;
*   while(i<N){
*	Remainder=N;
*	while(Remainder >= i){
*		Remainder = Remainder - i;
*       }
*       if(Remainder==0) PRIME=0;
*	i++;
*   }
* } else PRIME=0;
* pull return address off the stack
* push result onto stack
* push return address back on the stack
* return to main program
*
*	
***************************************
* start of data section

	ORG $B000
N	FCB     1, 2, 11, 14, 31, 32, 37, 241, 251, 252, $FF     
SENTIN	EQU	$FF
    
	ORG $B010
PRIME	RMB       10   

* define any other variables that you might need here using RMB (not FCB or FDB)
* remember that your subroutine must not access any of these variables, including
* N and PRIME

	ORG $C000
	LDS	#$01FF		initialize stack pointer
* start of your program
	LDX	#N		pointer1=&N[0];
	LDY	#PRIME		pointer2=&PRIME[0];
WHILE    LDAA	0,X		while (*pointer1 != SENTIN){
	CMPA	#SENTIN		
	BEQ	ENDWHL
	PSHX			store pointer1 on stack
	JSR	CPRIME		jump to subroutine
	PULA			get prime byte;
	STAA	0,Y		*pointer2=prime byte;
	PULX			get pointer1 off stack
	INX			pointer1++;
	INY			pointer2++;
	BRA	WHILE		}
ENDWHL
DONE	STOP




*OLD VARIABLE DECLARATIONS FROM LAB4
*NV	RMB	1		holds the N value sent from main program
*PV	RMB	1		holds the prime value
*RV	RMB	1		holds the remainder value 

	ORG $D000
* start of your subroutine 
CPRIME
	DES			Open Hole for NV stored at 2,X
	DES			Open Hole for PV stored at 1,X
	DES			Open Hole for RV stored at 0,X
	TSX			Set X to point to RV
IF1	CMPA	#1		if(N!=1){
	BEQ	ELSE1	
THEN1	STAA	2,X		 initialize N variable
	LDAA	#1
	STAA	1,X               PRIME=1;
	LDAB	#2		 i=2;
WHILE1	CMPB	2,X		 while(i<N){
	BHS	ENDWHL1
	LDAA	2,X
	STAA	0,X		   Remainder=N;
WHILE2	CMPB	0,X		   while(i <= Remainder){
	BHI	ENDWHL2
	SBA
	STAA	0,X		     Remainder = Remainder - i;
	BRA	WHILE2		   }
ENDWHL2
IF2	TST	0,X		   if(Remainder==0)
	BNE	ENDIF2
THEN2	CLR	1,X			PRIME=0;
ENDIF2  INCB			   i++;	
	BRA	WHILE1		 }
ENDWHL1	BRA     ENDIF1 	
ELSE1	CLR	1,X		} else PRIME=0;
ENDIF1	LDAA	1,X		get the prime value
	INS			Close Hole for RV
	INS			Close Hole for PV
	INS			Close Hole for NV
	PULX			pull return address off
	PSHA			push result onto stack
	PSHX			push return address back
	RTS



