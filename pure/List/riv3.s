	.file	"list_riv3.c"
# GNU C (Ubuntu 4.8.4-2ubuntu1~14.04.3) version 4.8.4 (x86_64-linux-gnu)
#	compiled by GNU C version 4.8.4, GMP version 5.1.3, MPFR version 3.1.2-p3, MPC version 1.0.1
# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -I ../include -imultiarch x86_64-linux-gnu list_riv3.c
# -mtune=generic -march=x86-64 -O3 -fverbose-asm -fstack-protector -Wformat
# -Wformat-security
# options enabled:  -faggressive-loop-optimizations
# -fasynchronous-unwind-tables -fauto-inc-dec -fbranch-count-reg
# -fcaller-saves -fcombine-stack-adjustments -fcommon -fcompare-elim
# -fcprop-registers -fcrossjumping -fcse-follow-jumps -fdefer-pop
# -fdelete-null-pointer-checks -fdevirtualize -fdwarf2-cfi-asm
# -fearly-inlining -feliminate-unused-debug-types -fexpensive-optimizations
# -fforward-propagate -ffunction-cse -fgcse -fgcse-after-reload -fgcse-lm
# -fgnu-runtime -fgnu-unique -fguess-branch-probability
# -fhoist-adjacent-loads -fident -fif-conversion -fif-conversion2
# -findirect-inlining -finline -finline-atomics -finline-functions
# -finline-functions-called-once -finline-small-functions -fipa-cp
# -fipa-cp-clone -fipa-profile -fipa-pure-const -fipa-reference -fipa-sra
# -fira-hoist-pressure -fira-share-save-slots -fira-share-spill-slots
# -fivopts -fkeep-static-consts -fleading-underscore -fmath-errno
# -fmerge-constants -fmerge-debug-strings -fmove-loop-invariants
# -fomit-frame-pointer -foptimize-register-move -foptimize-sibling-calls
# -foptimize-strlen -fpartial-inlining -fpeephole -fpeephole2
# -fpredictive-commoning -fprefetch-loop-arrays -free -freg-struct-return
# -fregmove -freorder-blocks -freorder-functions -frerun-cse-after-loop
# -fsched-critical-path-heuristic -fsched-dep-count-heuristic
# -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
# -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
# -fsched-stalled-insns-dep -fschedule-insns2 -fshow-column -fshrink-wrap
# -fsigned-zeros -fsplit-ivs-in-unroller -fsplit-wide-types
# -fstack-protector -fstrict-aliasing -fstrict-overflow
# -fstrict-volatile-bitfields -fsync-libcalls -fthread-jumps
# -ftoplevel-reorder -ftrapping-math -ftree-bit-ccp -ftree-builtin-call-dce
# -ftree-ccp -ftree-ch -ftree-coalesce-vars -ftree-copy-prop
# -ftree-copyrename -ftree-cselim -ftree-dce -ftree-dominator-opts
# -ftree-dse -ftree-forwprop -ftree-fre -ftree-loop-distribute-patterns
# -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-partial-pre
# -ftree-phiprop -ftree-pre -ftree-pta -ftree-reassoc -ftree-scev-cprop
# -ftree-sink -ftree-slp-vectorize -ftree-slsr -ftree-sra
# -ftree-switch-conversion -ftree-tail-merge -ftree-ter
# -ftree-vect-loop-version -ftree-vectorize -ftree-vrp -funit-at-a-time
# -funswitch-loops -funwind-tables -fvect-cost-model -fverbose-asm
# -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
# -maccumulate-outgoing-args -malign-stringops -mfancy-math-387
# -mfp-ret-in-387 -mfxsr -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-sse4
# -mpush-args -mred-zone -msse -msse2 -mtls-direct-seg-refs

	.text
	.p2align 4,,15
	.type	direct_riv, @function
direct_riv:
.LFB43:
	.cfi_startproc
	#movq	RIV_REGION(%rip), %rdx	# RIV_REGION, baseAddr
	movq	%rdi, %rcx
	movq	%rdi, %rax	# value, D.3326
	sarq	$31, %rcx
	salq	$18, %rcx
	andl	$2147483647, %eax	#, D.3326
	#salq	$18, %rdx	#, baseAddr
	orq	newvalue(%rip), %rcx	# newvalue, baseAddr
	addq	(%rcx), %rax	# *baseAddr.15_9, D.3326
	ret
	.cfi_endproc
.LFE43:
	.size	direct_riv, .-direct_riv
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"error"
	.text
	.p2align 4,,15
	.globl	insert_node
	.type	insert_node, @function
insert_node:
.LFB45:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	%edi, %ebp	# x, x
	movl	$16, %edi	#,
	pushq	%rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp	#,
	.cfi_def_cfa_offset 32
	call	malloc	#
	movl	$2147483648, %edx	#, tmp78
	cmpq	%rdx, %rax	# tmp78, tmp77
	ja	.L12	#,
	movq	RIV_REGION(%rip), %rcx	# RIV_REGION, RIV_REGION.9
	movabsq	$70368744177664, %rsi	#, tmp81
	movq	head(%rip), %rdi	# head, temp
	movq	%rcx, %rdx	# RIV_REGION.9, baseAddr
	salq	$31, %rcx	#, D.3333
	salq	$18, %rdx	#, baseAddr
	orq	%rsi, %rdx	# tmp81, baseAddr
	subq	(%rdx), %rax	# *baseAddr.10_12, t
	movq	%rax, %rbx	# t, t
	orq	%rcx, %rbx	# D.3333, t
	testq	%rdi, %rdi	# temp
	je	.L13	#,
	.p2align 4,,10
	.p2align 3
.L8:
	call	direct_riv	#
	movq	8(%rax), %rdi	# MEM[(struct node *)_26].next, temp
	testq	%rdi, %rdi	# temp
	jne	.L8	#,
	movq	%rbx, 8(%rax)	# t, MEM[(struct node *)_37].next
.L10:
	movq	%rbx, %rdi	# t,
	call	direct_riv	#
	movq	%rbx, %rdi	# t,
	movl	%ebp, (%rax)	# x,* D.3335
	call	direct_riv	#
	movq	$0, 8(%rax)	#,
	addq	$8, %rsp	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx	#
	.cfi_def_cfa_offset 16
	popq	%rbp	#
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L13:
	.cfi_restore_state
	movq	%rbx, head(%rip)	# t, head
	jmp	.L10	#
.L12:
	movl	$.LC0, %edi	#,
	call	puts	#
	xorl	%edi, %edi	#
	call	exit	#
	.cfi_endproc
.LFE45:
	.size	insert_node, .-insert_node
	.section	.rodata.str1.1
.LC1:
	.string	"%p %p %p\n"
.LC2:
	.string	"a"
.LC3:
	.string	"list_riv.txt"
.LC4:
	.string	"%ld\n"
.LC6:
	.string	"insert time: %fs\n"
.LC7:
	.string	"Linked list is empty."
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC8:
	.string	"total elements traversed %d %ld\n"
	.section	.rodata.str1.1
.LC9:
	.string	"traverse time: %fs\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB44:
	.cfi_startproc
	pushq	%r13	#
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	movl	$2015, %edi	#,
	movq	%rsi, %r13	# argv, argv
	pushq	%r12	#
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp	#
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	movabsq	$562947805937664, %rbp	#, tmp128
	pushq	%rbx	#
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	subq	$40, %rsp	#,
	.cfi_def_cfa_offset 80
	call	srand	#
	call	rand	#
	movl	$1441151881, %edx	#, tmp123
	movl	%eax, %ecx	#, D.3360
	xorl	%r9d, %r9d	#
	imull	%edx	# tmp123
	movl	%ecx, %eax	# D.3360, tmp125
	xorl	%r8d, %r8d	#
	sarl	$31, %eax	#, tmp125
	movl	$8, %esi	#,
	movq	$917373, RIV_REGION(%rip)	#, RIV_REGION
	sarl	$25, %edx	#, tmp121
	subl	%eax, %edx	# tmp125, tmp121
	movl	%ecx, %eax	# D.3360, D.3360
	movl	$49, %ecx	#,
	imull	$100000000, %edx, %edx	#, tmp121, tmp126
	subl	%edx, %eax	# tmp126, D.3360
	movl	$3, %edx	#,
	cltq
	andq	%rax, %rbp	# base.0, nvbase
	movq	%rax, base(%rip)	# base.0, base
	movabsq	$70368744177664, %rax	#, tmp130
	movq	%rbp, %rdi	# nvbase, rid
	shrq	$3, %rdi	#, rid
	orq	%rax, %rdi	# tmp130, rid
	call	mmap	#
	movq	RIV_REGION(%rip), %rbx	# RIV_REGION, RIV_REGION.2
	xorl	%r9d, %r9d	#
	xorl	%r8d, %r8d	#
	movl	$49, %ecx	#,
	movl	$3, %edx	#,
	movl	$8, %esi	#,
	movl	%ebx, (%rax)	# RIV_REGION.2, *rid_19
	salq	$18, %rbx	#, baseAddr
	orq	newvalue(%rip), %rbx	# newvalue, baseAddr
	movq	%rbx, %rdi	# baseAddr,
	call	mmap	#
	movq	RIV_REGION(%rip), %r8	# RIV_REGION,
	movq	%rbx, %rcx	# baseAddr,
	movq	%rax, %r12	#, nvbase_p
	movq	%rax, %rdx	# nvbase_p,
	movl	$.LC1, %esi	#,
	movl	$1, %edi	#,
	xorl	%eax, %eax	#
	call	__printf_chk	#
	movq	8(%r13), %rdi	# MEM[(char * *)argv_34(D) + 8B], MEM[(char * *)argv_34(D) + 8B]
	movq	%rbp, (%r12)	# nvbase, *nvbase_p_28
	movl	$10, %edx	#,
	xorl	%esi, %esi	#
	call	strtoll	#
	movl	$.LC2, %esi	#,
	movq	%rax, %rbp	#, D.3365
	movl	$.LC3, %edi	#,
	movl	%eax, %ebx	# D.3365, data
	addl	$30000, %ebp	#, D.3360
	call	fopen	#
	xorl	%esi, %esi	#
	movq	%rax, %r12	#, pfp
	movq	%rsp, %rdi	#,
	xorl	%eax, %eax	#
	call	gettimeofday	#
	.p2align 4,,10
	.p2align 3
.L16:
	movl	%ebx, %edi	# data,
	addl	$1, %ebx	#, data
	call	insert_node	#
	cmpl	%ebp, %ebx	# D.3360, data
	jne	.L16	#,
	leaq	16(%rsp), %rdi	#, tmp174
	xorl	%esi, %esi	#
	xorl	%eax, %eax	#
	movl	$10000, %r13d	#, D.3367
	call	gettimeofday	#
	movq	16(%rsp), %rbx	# tempo1.tv_sec, elapsed_seconds
	subq	(%rsp), %rbx	# tempo.tv_sec, elapsed_seconds
	movl	$.LC4, %edx	#,
	movl	$1, %esi	#,
	movq	%r12, %rdi	# pfp,
	xorl	%eax, %eax	#
	imulq	$1000000, %rbx, %rbx	#, elapsed_seconds, elapsed_utime
	addq	24(%rsp), %rbx	# tempo1.tv_usec, elapsed_utime
	subq	8(%rsp), %rbx	# tempo.tv_usec, elapsed_utime
	movq	%rbx, %rcx	# elapsed_utime,
	call	__fprintf_chk	#
	cvtsi2sdq	%rbx, %xmm0	# elapsed_utime, D.3364
	movl	$.LC6, %esi	#,
	movl	$1, %edi	#,
	movl	$1, %eax	#,
	divsd	.LC5(%rip), %xmm0	#, D.3364
	call	__printf_chk	#
	xorl	%esi, %esi	#
	movq	%rsp, %rdi	#,
	xorl	%eax, %eax	#
	call	gettimeofday	#
	movl	$4, %esi	#,
	movl	$1, %edi	#,
	call	calloc	#
	movq	%rax, %rbp	#, s
	.p2align 4,,10
	.p2align 3
.L21:
	movq	head(%rip), %rdi	# head, t
	testq	%rdi, %rdi	# t
	je	.L26	#,
	movl	0(%rbp), %ebx	# *s_58, D.3360
	.p2align 4,,10
	.p2align 3
.L19:
	call	direct_riv	#
	movq	8(%rax), %rdi	# MEM[(struct node *)_87].next, t
	addl	$1, %ebx	#, D.3360
	movl	%ebx, 0(%rbp)	# D.3360, *s_58
	testq	%rdi, %rdi	# t
	jne	.L19	#,
	subl	$1, %r13d	#, D.3367
	jne	.L21	#,
.L27:
	leaq	16(%rsp), %rdi	#, tmp175
	xorl	%esi, %esi	#
	xorl	%eax, %eax	#
	call	gettimeofday	#
	movq	16(%rsp), %rbx	# tempo1.tv_sec, elapsed_seconds
	subq	(%rsp), %rbx	# tempo.tv_sec, elapsed_seconds
	movl	$1759218605, %ecx	#, tmp158
	movl	0(%rbp), %esi	# *s_58, *s_58
	movq	%r12, %rdi	# pfp,
	movl	%esi, %eax	# *s_58, tmp169
	sarl	$31, %esi	#, tmp160
	imulq	$1000000, %rbx, %rbx	#, elapsed_seconds, elapsed_utime
	addq	24(%rsp), %rbx	# tempo1.tv_usec, elapsed_utime
	imull	%ecx	# tmp158
	subq	8(%rsp), %rbx	# tempo.tv_usec, elapsed_utime
	xorl	%eax, %eax	#
	movl	%edx, %ecx	# D.3360, D.3360
	movl	$.LC8, %edx	#,
	sarl	$12, %ecx	#, D.3360
	movq	%rbx, %r8	# elapsed_utime,
	subl	%esi, %ecx	# tmp160, D.3360
	movl	$1, %esi	#,
	call	__fprintf_chk	#
	cvtsi2sdq	%rbx, %xmm0	# elapsed_utime, D.3364
	movl	$.LC9, %esi	#,
	movl	$1, %edi	#,
	movl	$1, %eax	#,
	divsd	.LC5(%rip), %xmm0	#, D.3364
	call	__printf_chk	#
	addq	$40, %rsp	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	xorl	%eax, %eax	#
	popq	%rbx	#
	.cfi_def_cfa_offset 32
	popq	%rbp	#
	.cfi_def_cfa_offset 24
	popq	%r12	#
	.cfi_def_cfa_offset 16
	popq	%r13	#
	.cfi_def_cfa_offset 8
	ret
.L26:
	.cfi_restore_state
	movl	$.LC7, %edi	#,
	call	puts	#
	subl	$1, %r13d	#, D.3367
	jne	.L21	#,
	jmp	.L27	#
	.cfi_endproc
.LFE44:
	.size	main, .-main
	.text
	.p2align 4,,15
	.globl	traverse
	.type	traverse, @function
traverse:
.LFB46:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rdi, %rbp	# s, s
	pushq	%rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp	#,
	.cfi_def_cfa_offset 32
	movq	head(%rip), %rdi	# head, t
	testq	%rdi, %rdi	# t
	je	.L33	#,
	movl	0(%rbp), %eax	# *s_9(D), tmp69
	leal	1(%rax), %ebx	#, ivtmp.50
	.p2align 4,,10
	.p2align 3
.L31:
	call	direct_riv	#
	movq	8(%rax), %rdi	# MEM[(struct node *)_7].next, t
	movl	%ebx, 0(%rbp)	# ivtmp.50, *s_9(D)
	addl	$1, %ebx	#, ivtmp.50
	testq	%rdi, %rdi	# t
	jne	.L31	#,
	addq	$8, %rsp	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx	#
	.cfi_def_cfa_offset 16
	popq	%rbp	#
	.cfi_def_cfa_offset 8
	ret
.L33:
	.cfi_restore_state
	addq	$8, %rsp	#,
	.cfi_def_cfa_offset 24
	movl	$.LC7, %edi	#,
	popq	%rbx	#
	.cfi_def_cfa_offset 16
	popq	%rbp	#
	.cfi_def_cfa_offset 8
	jmp	puts	#
	.cfi_endproc
.LFE46:
	.size	traverse, .-traverse
	.globl	head
	.bss
	.align 16
	.type	head, @object
	.size	head, 8
head:
	.zero	8
	.globl	newvalue
	.data
	.align 16
	.type	newvalue, @object
	.size	newvalue, 8
newvalue:
	.quad	70368744177664
	.comm	base,8,8
	.comm	RIV_REGION,8,8
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC5:
	.long	0
	.long	1093567616
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
