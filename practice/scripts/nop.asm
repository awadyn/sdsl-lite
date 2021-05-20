	.global _start

_start:
	nop
	nop
	nop
	nop
	nop
	mov	$1,	%rax
	int	$0x80
	hlt
