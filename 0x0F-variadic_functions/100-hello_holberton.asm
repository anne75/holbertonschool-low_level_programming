; hello_64.asm    print a string using printf
; Assemble:	  nasm -f elf64 -l hello_64.lst  hello_64.asm
; Link:		  gcc -m64 -o hello_64  hello_64.o
; Run:		  ./hello_64 > hello_64.out
; Output:	  cat hello_64.out

; Equivalent C code
; // hello.c
; #include <stdio.h>
; int main()
; {
;   char msg[] = "Hello, Holberton\n";
;   printf("%s\n",msg);
;   return 0;
; }


        section .data		; Data section, initialized variables
msg:	db "Hello, Holberton\n", 0	; C string needs 0
len:	equ $-msg

        section .text           ; Code section.

        global main		; the standard gcc entry point
main:				; the program label for the entry point
        push    rbp		; set up stack frame, must be aligned
	mov	rbp, rsp
	mov	ecx, len
	mov	edx,msg
	mov	esi, 1		; arg one: file descriptor
	mov	edi, 1		; syscall number
	mov	eax, 0
	int	0x80		; Interrupt 0x80 no sy s c a l l
	mov	eax,0		; or can be  xor  rax,rax

	pop	rbp		; restore stack

	mov	rax,0		; normal, no error, return value
	ret			; return
