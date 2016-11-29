; source https://www.csee.umbc.edu/portal/help/nasm/sample_64.shtml#hello_64.asm
; hello_64.asm    print a string using printf
; Assemble:	  nasm -f elf64 -l hello_64.lst  hello_64.asm
; Link:		  gcc -m64 -o hello_64  hello_64.o
; Run:		  ./hello_64 > hello_64.out
; Output:	  cat hello_64.out

; Equivalent C code
; // hello.c
; #include <unistd.h>
; int main()
; {
;   char msg[] = "Hello, Holberton\n";
;   write(1, msg, 17);
;   return 0;
; }


        section .data		; Data section, initialized variables
msg:	db "Hello, Holberton", 0	; C string needs 0
len:	equ $-msg
n1:	dq 10			; newline

        section .text           ; Code section.

        global main		; the standard gcc entry point
main:				; the program label for the entry point
        push    rbp		; set up stack frame, must be aligned
	mov	rbp, rsp
	mov	edx, 16		; arg3, length
	mov	ecx,msg		; arg2, pointer to string
	mov	ebx, 1		; arg1, where to write, screen
	mov	eax,4 		; write interrupt IMPR: different with interrupt
	int	0x80		; Interrupt 0x80 no sy s c a l l

	mov	edx, 1
	mov	ecx, n1
	mov	ebx, 1
	mov	eax, 4
	int	0x80

	mov	eax,0		; or can be  xor  rax,rax

	pop	rbp		; restore stack

	mov	rax,0		; normal, no error, return value
	ret			; return
