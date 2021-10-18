***********************************************
*
* stack instructions
*
***********************************************


* main program starts at $C000


	ORG 	$C000

	LDS	#$01FF	Initialize stack
	LDAA	#5	Initialize registers
	LDX	#$1234
	PSHA		Push A
	PSHX		Push X
	LDX	#0	Clear registers
	CLRA
	PULX		Pull X
	PULA		Pull A
	PSHA		Push A
	PSHX		Push X
	LDX	#0	Clear registers
	CLRA
	PULA		Pull A
	PULX		Pull X
	PULA		Pull A from empty stack
DONE	BRA	DONE	infinite loop
	END		Tells assembler that we are done

