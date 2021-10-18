**************************************
*
* Name: Nathan Toepke
* PawPrint ID: nst9fk
* Date: 2/25/21
* Lab2
*
* Program description: 
* Program will divide the dividend by the divisor through looped subtraction
* and provide accurate values to the Quotient and Remainder variables.
* Pseudocode:
*
*	#define DIVIDEND 201
*	#define DIVISOR 6
*
*	unsigned int quotient;
*	unsigned int remainder;
*   quotient = 0;
*   remainder = DIVIDEND;
*
*   if (DIVISOR==0)
*   {
*    quotient = $FF; 
*    remainder = $FF;
*   }
*   else
*   {
*    	while(remainder>=DIVISOR){
*    		remainder-=DIVISOR;
*    		quotient+=1;
*    }
*   }
*
**************************************

* start of data section

	ORG $B000
DIVIDEND	FCB      201         The dividend
DIVISOR	FCB        6         The divisor.

	ORG $B010
QUOTIENT	RMB       1         The quotient.
REMAINDER	RMB       1         The remainder.
* define any other variables that you might need here

	ORG $C000
* start of your program
	CLR QUOTIENT	quotient = 0;
	CLR REMAINDER	remainder = 0; clear memory to initialize
	LDAA DIVIDEND	Load DIVIDEND to register A, in order to store in REMAINDER
	STAA REMAINDER	REMAINDER = DIVIDEND;
IF	CLRA			Set Registry A to zero for IF statement
	CMPA DIVISOR	if(DIVISOR==0)
	BNE ELSE
THEN	LDAA #$FF		{ Load $FF into Register A to store into memory
	STAA QUOTIENT	quotient = $FF
	STAA REMAINDER	remainder = $FF
	BRA ENDIF		}
ELSE	NOP			Did not name LDAA REMAINDER ELSE and WHILE, thus the NOP line
WHILE	LDAA REMAINDER	Else { 
	CMPA DIVISOR	while(remainder>=DIVISOR){
	BLO ENDWHILE	
	SUBA DIVISOR	remainder-=DIVISOR; Subtract the divisor from registry A
	STAA REMAINDER	Save the subtraction to memory
	INC QUOTIENT	quotient+=1;
	BRA WHILE		}
ENDWHILE NOP		} Same as ELSE, both ENDWHILE and ENDIF lead to stop, thus the NOP for ENDWHILE
ENDIF STOP





