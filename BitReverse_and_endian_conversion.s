.global assembly_project
.func assembly_project

assembly_project:
	CMP R1,#0 @0 = bit reverse, 1 = endian convert	
	MOV R1,R0 
	@LDR R1,[R7] @ first value in array
	@ADD R7,R7,#4
	@LDR R2,[R7] @ second value in array
	@ADD R7,R7,#4
	@LDR R3,[R7] @ third value in array
	BEQ _bit_reverse @ for bit reverse
	BNE _endian_convert @ for endian conversion

_endian_convert:
	@ MOV R5,#0
	MOV R5,#32 @for loop runs 
_endian_loop:
	LSR R6,R1,#8 @ Uses same code but 8 bits for endian conversion
	LSL R6,R6,#8
	SUB R7,R1,R6 @has the end 8 bits
	LSR R1,R1,#8
	SUB R5,R5,#8
	LSL R8,R7,R5
	ADD R9,R9,R8 @has final value
	CMP R5,#0 @check to see if loop ends
	BNE _endian_loop
	MOV R0,R9 @return value
	MOV R1,#0 @reset
	MOV R6,#0
	MOV R7,#0
	MOV R8,#0
	MOV R9,#0
	BX LR

	
_bit_reverse:  
	MOV R5,#32 @ for loop
_bit_loop:
	LSR R6,R1,#1 @divide by 2
	LSL R6,R6,#1 @multiply by 2
	SUB R7,R1,R6 @has the end bit
	LSR R1,R1,#1 @actual value divided by 2
	SUB R5,R5,#1 @for loop
	LSL R8,R7,R5 @bit reverse
	ADD R9,R9,R8 @has final value
	CMP R5,#0 @ condition check: if i=0
	BNE _bit_loop @if not branch
	MOV R0,R9 @return value
	MOV R1,#0 @reset
	MOV R6,#0
	MOV R7,#0
	MOV R8,#0
	MOV R9,#0
	BX LR @ return to C
				
	

