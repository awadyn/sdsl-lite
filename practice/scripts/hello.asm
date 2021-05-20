	.global _start
_start:
	mov	$msg,	%rcx
	mov	$6,	%rdx
	mov	$1,	%rbx
	mov	$4,	%rax
	int	$0x80
	mov	$1,	%rax
	int	$0x80
	hlt


msg:
	.string "hello "
	
