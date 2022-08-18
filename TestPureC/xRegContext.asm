

.code


rax_offset	equ	0
rbx_offset	equ	8
rcx_offset	equ	16
rdx_offset	equ	24
rsi_offset	equ	32
rdi_offset	equ	40
r8_offset	equ	48
r9_offset	equ	56
r10_offset	equ	64
r11_offset	equ	72
r12_offset	equ	80
r13_offset	equ	88
r14_offset	equ	96
r15_offset	equ	104
rip_offset	equ	112
rsp_offset	equ	120
rbp_offset	equ	128
rflags_offset	equ	136
mxcsr_offset	equ	144
fcw_offset	equ	152
xmm0_offset	equ	160
xmm1_offset	equ	176
xmm2_offset	equ	192
xmm3_offset	equ	208
xmm4_offset	equ	224
xmm5_offset	equ	240
xmm6_offset	equ	256
xmm7_offset	equ	272
xmm8_offset	equ	288
xmm9_offset	equ	304
xmm10_offset	equ	320
xmm11_offset	equ	336
xmm12_offset	equ	352
xmm13_offset	equ	368
xmm14_offset	equ	384
xmm15_offset	equ	400

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;unsigned long long xSaveRegCtx(void* bufferRcx, unsigned long long dummyRdx, unsigned long long dummyR8, unsigned long long dummyR9);


public xSaveRegCtx

xSaveRegCtx proc

	;rax_offset	equ	0
	mov [rcx + rax_offset], rax

	;rbx_offset	equ	8
	mov [rcx + rbx_offset], rbx

	;rcx_offset	equ	16
	mov [rcx + rcx_offset], rcx

	;rdx_offset	equ	24
	mov [rcx + rdx_offset], rdx

	;rsi_offset	equ	32
	mov [rcx + rsi_offset], rsi

	;rdi_offset	equ	40
	mov [rcx + rdi_offset], rdi

	;r8_offset	equ	48
	mov [rcx + r8_offset], r8

	;r9_offset	equ	56
	mov [rcx + r9_offset], r9

	;r10_offset	equ	64
	mov [rcx + r10_offset], r10

	;r11_offset	equ	72
	mov [rcx + r11_offset], r11

	;r12_offset	equ	80
	mov [rcx + r12_offset], r12

	;r13_offset	equ	88
	mov [rcx + r13_offset], r13

	;r14_offset	equ	96
	mov [rcx + r14_offset], r14

	;r15_offset	equ	104
	mov [rcx + r15_offset], r15

	;rip_offset	equ	112
	mov rax, [rsp]
	mov [rcx + rip_offset], rax

	;rsp_offset	equ	120
	lea rax, [rsp + 8]
	mov [rcx + rsp_offset], rax

	;rbp_offset	equ	128
	mov [rcx + rbp_offset], rbp

	;rflags_offset	equ	136
	pushfq
	pop rax
	mov [rcx + rflags_offset], rax

	;mxcsr_offset	equ	144
	stmxcsr [rcx + mxcsr_offset]

	;fcw_offset	equ	152
	fnstcw [rcx + fcw_offset]

	;xmm0_offset	equ	160
	movdqa [rcx + xmm0_offset], xmm0

	;xmm1_offset	equ	176
	movdqa [rcx + xmm1_offset], xmm1

	;xmm2_offset	equ	192
	movdqa [rcx + xmm2_offset], xmm2

	;xmm3_offset	equ	208
	movdqa [rcx + xmm3_offset], xmm3

	;xmm4_offset	equ	224
	movdqa [rcx + xmm4_offset], xmm4

	;xmm5_offset	equ	240
	movdqa [rcx + xmm5_offset], xmm5

	;xmm6_offset	equ	256
	movdqa [rcx + xmm6_offset], xmm6

	;xmm7_offset	equ	272
	movdqa [rcx + xmm7_offset], xmm7

	;xmm8_offset	equ	288
	movdqa [rcx + xmm8_offset], xmm8

	;xmm9_offset	equ	304
	movdqa [rcx + xmm9_offset], xmm9

	;xmm10_offset	equ	320
	movdqa [rcx + xmm10_offset], xmm10

	;xmm11_offset	equ	336
	movdqa [rcx + xmm11_offset], xmm11

	;xmm12_offset	equ	352
	movdqa [rcx + xmm12_offset], xmm12

	;xmm13_offset	equ	368
	movdqa [rcx + xmm13_offset], xmm13

	;xmm14_offset	equ	384
	movdqa [rcx + xmm14_offset], xmm14

	;xmm15_offset	equ	400
	movdqa [rcx + xmm15_offset], xmm15


	mov rax, 0
	ret

xSaveRegCtx endp



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;unsigned long long xRestoreRegCtx(void* bufferRcx, unsigned long long dummyRdx, unsigned long long dummyR8, unsigned long long dummyR9);

public xRestoreRegCtx

xRestoreRegCtx proc

	;rax_offset	equ	0
	mov rax, [rcx + rax_offset]

	;rbx_offset	equ	8
	mov rbx, [rcx + rbx_offset]

	;rcx_offset	equ	16
	push rcx
	mov rcx, [rcx + rcx_offset]
	pop rcx

	;rdx_offset	equ	24
	mov rdx, [rcx + rdx_offset]

	;rsi_offset	equ	32
	mov rsi, [rcx + rsi_offset]

	;rdi_offset	equ	40
	mov rdi, [rcx + rdi_offset]

	;r8_offset	equ	48
	mov r8, [rcx + r8_offset]

	;r9_offset	equ	56
	mov r9, [rcx + r9_offset]

	;r10_offset	equ	64
	mov r10, [rcx + r10_offset]

	;r11_offset	equ	72
	mov r11, [rcx + r11_offset]

	;r12_offset	equ	80
	mov r12, [rcx + r12_offset]

	;r13_offset	equ	88
	mov r13, [rcx + r13_offset]

	;r14_offset	equ	96
	mov r14, [rcx + r14_offset]

	;r15_offset	equ	104
	mov r15, [rcx + r15_offset]

	;;;restore at end
	;;;rip_offset	equ	112
	;;;mov rax, [rsp]
	;;;mov rax, [rcx + rip_offset]

	;;;restore at end
	;;;rsp_offset	equ	120
	;;;lea rax, [rsp + 8]
	;;;mov rax, [rcx + rsp_offset]

	;rbp_offset	equ	128
	mov rbp, [rcx + rbp_offset]

	;;;restore at end
	;;;rflags_offset	equ	136
	;;;pushfq
	;;;pop rax
	;;;mov rax, [rcx + rflags_offset]

	;mxcsr_offset	equ	144
	ldmxcsr [rcx + mxcsr_offset]

	;fcw_offset	equ	152
	fnclex
	fldcw [rcx + fcw_offset]

	;xmm0_offset	equ	160
	movdqa xmm0, [rcx + xmm0_offset]

	;xmm1_offset	equ	176
	movdqa xmm1, [rcx + xmm1_offset]

	;xmm2_offset	equ	192
	movdqa xmm2, [rcx + xmm2_offset]

	;xmm3_offset	equ	208
	movdqa xmm3, [rcx + xmm3_offset]

	;xmm4_offset	equ	224
	movdqa xmm4, [rcx + xmm4_offset]

	;xmm5_offset	equ	240
	movdqa xmm5, [rcx + xmm5_offset]

	;xmm6_offset	equ	256
	movdqa xmm6, [rcx + xmm6_offset]

	;xmm7_offset	equ	272
	movdqa xmm7, [rcx + xmm7_offset]

	;xmm8_offset	equ	288
	movdqa xmm8, [rcx + xmm8_offset]

	;xmm9_offset	equ	304
	movdqa xmm9, [rcx + xmm9_offset]

	;xmm10_offset	equ	320
	movdqa xmm10, [rcx + xmm10_offset]

	;xmm11_offset	equ	336
	movdqa xmm11, [rcx + xmm11_offset]

	;xmm12_offset	equ	352
	movdqa xmm12, [rcx + xmm12_offset]

	;xmm13_offset	equ	368
	movdqa xmm13, [rcx + xmm13_offset]

	;xmm14_offset	equ	384
	movdqa xmm14, [rcx + xmm14_offset]

	;xmm15_offset	equ	400
	movdqa xmm15, [rcx + xmm15_offset]

	;;;;;;;;
	;restore flags
	mov rax, [rcx + rflags_offset]
	push rax
	popfq

	;;;;;;;;
	;restore stack
	mov rsp, [rcx + rsp_offset]

	;;;;;;;;
	;restore rip
	mov rax, [rcx + rip_offset]
	jmp rax

xRestoreRegCtx endp




end