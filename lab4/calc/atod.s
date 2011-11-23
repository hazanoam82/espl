	.file	"atod.c"
	.intel_syntax noprefix
	.text
.globl atod
	.type	atod, @function
atod:
	push	ebp
	mov	ebp, esp
	sub	esp, 40
	mov	DWORD PTR [ebp-12], 0
	mov	DWORD PTR [ebp-16], 1
	mov	eax, DWORD PTR [ebp+8]
	mov	DWORD PTR [esp], eax
	call	strlen
	mov	DWORD PTR [ebp-24], eax
	mov	eax, DWORD PTR [ebp-24]
	mov	DWORD PTR [ebp-20], eax
	jmp	.L2
.L3:
	mov	eax, DWORD PTR [ebp-20]
	sub	eax, 1
	add	eax, DWORD PTR [ebp+8]
	movzx	eax, BYTE PTR [eax]
	movsx	eax, al
	sub	eax, 48
	imul	eax, DWORD PTR [ebp-16]
	add	DWORD PTR [ebp-12], eax
	mov	edx, DWORD PTR [ebp-16]
	mov	eax, edx
	sal	eax, 2
	add	eax, edx
	add	eax, eax
	mov	DWORD PTR [ebp-16], eax
	sub	DWORD PTR [ebp-20], 1
.L2:
	cmp	DWORD PTR [ebp-20], 0
	jg	.L3
	mov	eax, DWORD PTR [ebp-12]
	leave
	ret
	.size	atod, .-atod
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
