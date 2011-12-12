section	.text
	global ahalan
	extern puts

ahalan:					;void ahalan()
	push ebp
	mov ebp, esp
	push	msg	;message to write
	call	puts
	add esp, 8
	ret

section	.data

msg	db	'ahalan!',0xa,0	;our dear string
