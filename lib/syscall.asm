
; ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;                               syscall.asm
; ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;                                                     Forrest Yu, 2005
; ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

%include "sconst.inc"

INT_VECTOR_SYS_CALL equ 0x90
_NR_printx	    equ 0
_NR_sendrec	    equ 1
_NR_getcr3	    equ 2
_NR_putcr3	    equ 2

; 导出符号
global	printx
global	sendrec
global  getcr3
global  putcr3

bits 32
[section .text]

; ====================================================================================
;                  sendrec(int function, int src_dest, MESSAGE* msg);
; ====================================================================================
; Never call sendrec() directly, call send_recv() instead.
sendrec:
	push	ebx		; .
	push	ecx		;  > 12 bytes
	push	edx		; /

	mov	eax, _NR_sendrec
	mov	ebx, [esp + 12 +  4]	; function
	mov	ecx, [esp + 12 +  8]	; src_dest
	mov	edx, [esp + 12 + 12]	; msg
	int	INT_VECTOR_SYS_CALL

	pop	edx
	pop	ecx
	pop	ebx

	ret

; ====================================================================================
;                          void printx(char* s);
; ====================================================================================
printx:
	push	edx		; 4 bytes

	mov	eax, _NR_printx
	mov	edx, [esp + 4 + 4]	; s
	int	INT_VECTOR_SYS_CALL

	pop	edx

	ret

; ====================================================================================
;              int getcr3(void);
; ====================================================================================
getcr3:
	mov	eax, _NR_getcr3
	int	INT_VECTOR_SYS_CALL
	ret

; ====================================================================================
;              void putcr3(unsigned int pdb_addr);
; ====================================================================================
putcr3:
	push	edx

	mov	eax, _NR_putcr3
	mov	edx, [esp + 4 + 4]
	int	INT_VECTOR_SYS_CALL

	pop	edx

	ret
