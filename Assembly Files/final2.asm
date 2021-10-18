		ORG        $B000            (Main Program Data Section)
DATA1    FCB        5
DATA2    FCB        6
RESULT    RMB        1

	ORG $C000
MAIN	LDS	#$01FF
	LDAA	DATA1
	PSHA
	LDAA	DATA2
	PSHA
	CLRA
	JSR SUB
	PULA
	STAA	RESULT
DONE	STOP

	ORG $D000
SUB	PULY
	PULA
	PULB
	ABA
	PSHA
	PSHY
	RTS