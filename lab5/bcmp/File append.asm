; The program opens "Test.txt" and adds "Some text" in it
; If Test.txt does not exists, it is not created.
; Current directory action.



	org	100h
start:

	mov	ax,3d02h	; open file read/write
	lea	dx,eax		; gets file name
	int	21h

	mov	handle,ax

	mov	ax,4202h	; seek end of file
	mov	bx,handle
	xor	dx,dx
	mov	cx,dx
	int	21h

	mov	ah,3eh		; close file
	mov	bx,handle
	int	21h

	ret

handle  dw	0

end