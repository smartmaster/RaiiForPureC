#pragma once

typedef struct tRegContext
{
		unsigned long long rax_offset;//	equ	0
		unsigned long long rbx_offset;//	equ	8
		unsigned long long rcx_offset;//	equ	16
		unsigned long long rdx_offset;//	equ	24
		unsigned long long rsi_offset;//	equ	32
		unsigned long long rdi_offset;//	equ	40
		unsigned long long r8_offset;//	equ	48
		unsigned long long r9_offset;//	equ	56
		unsigned long long r10_offset;//	equ	64
		unsigned long long r11_offset;//	equ	72
		unsigned long long r12_offset;//	equ	80
		unsigned long long r13_offset;//	equ	88
		unsigned long long r14_offset;//	equ	96
		unsigned long long r15_offset;//	equ	104
		unsigned long long rip_offset;//	equ	112
		unsigned long long rsp_offset;//	equ	120
		unsigned long long rbp_offset;//	equ	128
		unsigned long long rflags_offset;//	equ	136
		unsigned long long mxcsr_offset;//	equ	144
		unsigned long long fcw_offset;//	equ	152
		unsigned long long xmm0_offset[2];//	equ	160
		unsigned long long xmm1_offset[2];//	equ	176
		unsigned long long xmm2_offset[2];//	equ	192
		unsigned long long xmm3_offset[2];//	equ	208
		unsigned long long xmm4_offset[2];//	equ	224
		unsigned long long xmm5_offset[2];//	equ	240
		unsigned long long xmm6_offset[2];//	equ	256
		unsigned long long xmm7_offset[2];//	equ	272
		unsigned long long xmm8_offset[2];//	equ	288
		unsigned long long xmm9_offset[2];//	equ	304
		unsigned long long xmm10_offset[2];//	equ	320
		unsigned long long xmm11_offset[2];//	equ	336
		unsigned long long xmm12_offset[2];//	equ	352
		unsigned long long xmm13_offset[2];//	equ	368
		unsigned long long xmm14_offset[2];//	equ	384
		unsigned long long xmm15_offset[2];//	equ	400
		struct tRegContext* prev;
}tRegContext;
