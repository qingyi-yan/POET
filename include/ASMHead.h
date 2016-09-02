
#if defined(INS_256BIT)
/* Register definition */
#define Y(r)		y##r
#define X(r)		x##r

#define yreg0		"%%ymm0"
#define yreg1		"%%ymm1"
#define yreg2		"%%ymm2"
#define yreg3		"%%ymm3"
#define yreg4		"%%ymm4"
#define yreg5		"%%ymm5"
#define yreg6		"%%ymm6"
#define yreg7		"%%ymm7"
#ifdef ATL_GAS_x8664
	#define yreg8	"%%ymm8"
	#define yreg9	"%%ymm9"
	#define yreg10	"%%ymm10"
	#define yreg11	"%%ymm11"
	#define yreg12	"%%ymm12"
	#define yreg13	"%%ymm13"
	#define yreg14	"%%ymm14"
	#define yreg15	"%%ymm15"
	#define yreg16	"%%ymm0"
#endif
#define xreg0		"%%xmm0"
#define xreg1		"%%xmm1"
#define xreg2		"%%xmm2"
#define xreg3		"%%xmm3"
#define xreg4		"%%xmm4"
#define xreg5		"%%xmm5"
#define xreg6		"%%xmm6"
#define xreg7		"%%xmm7"
#ifdef ATL_GAS_x8664
	#define xreg8	"%%xmm8"
	#define xreg9	"%%xmm9"
	#define xreg10	"%%xmm10"
	#define xreg11	"%%xmm11"
	#define xreg12	"%%xmm12"
	#define xreg13	"%%xmm13"
	#define xreg14	"%%xmm14"
	#define xreg15	"%%xmm15"
	#define xreg16	"%%xmm0"
#endif


/* Structure of inline assembly
 * __asm__ __volatile__ (assembly template \
 *					: output operand list
 *					: input operand list
 *					: clobber list);
 * __volatile__ is optional

 */


#define gen_vece_mr(op,mem,reg) \
        __asm__ __volatile__ (#op " %0, " Y(reg) \
                              :  /* nothing */ \
                              : "m" (((mem)[0])), "m" (((mem)[1])))

#define gen_vece_rm(op,reg,mem) \
        __asm__ __volatile__ (#op " " Y(reg) ", %0" \
                              : "=m" (((mem)[0])), "=m" (((mem)[1])) \
                              :  /* nothing */ )                          

#define gen_vece_rr(op,reg1,reg2) \
        __asm__ __volatile__ (#op " " Y(reg1) ", " Y(reg2) ", " Y(reg2) \
                              :  /* nothing */ \
                              : /* nothing */)

#define gen_vece_rr3(op,reg1,reg2,reg3) \
        __asm__ __volatile__ (#op " " Y(reg1) ", " Y(reg2) ", " Y(reg3) \
                              :  /* nothing */ \
                              : /* nothing */)

#define gen_vece_mr3(op,mem,reg1,reg2)\
		__asm__ __volatile__ (#op " %0, "Y(reg1) ", "Y(reg2)\
							  : /* nothing*/\
							  : "m" (((mem)[0])), "m" (((mem)[1])))

#define gen_vece_mov(op,reg1,reg2) \
        __asm__ __volatile__ (#op " " Y(reg1) ", " Y(reg2) \
                              :  /* nothing */ \
                              : /* nothing */)


#define gen_vece_reduce(reg1,reg2) \
		__asm__ __volatile__ ("vhaddpd " Y(reg2) ", " Y(reg1) ", " Y(reg1) "\n" \
							  "vextractf128 $0x1," Y(reg1) ", " X(reg2) "\n" \
							  "vaddpd " Y(reg2) ", " Y(reg1) "," Y(reg1) "\n" \
							  ::)
#define gen_vec_mr(op,mem,reg) \
        __asm__ __volatile__ ("vzeroupper\n"#op " %0, " X(reg)\
                              :  /* nothing */ \
                              : "m" (((mem)[0])), "m" (((mem)[1])))
#define vzeroupper() \
		__asm__ __volatile__("vzeroupper"::)

#define gen_vec_rm(op,reg,mem) \
        __asm__ __volatile__ (#op " " X(reg) ", %0" \
                              : "=m" (((mem)[0])), "=m" (((mem)[1])) \
                              :  /* nothing */ )                          


#define gen_vec_rr(op,reg1,reg2) \
        __asm__ __volatile__ (#op " " X(reg1) ", " X(reg2) \
                              :  /* nothing */ \
                              : /* nothing */)


#define vec_zero(reg)			vzeroupper();
#define vec_splat(mem,reg)      gen_vece_mr(vbroadcastsd,mem,reg)
#define vec_add_rr(mem,reg)     gen_vece_rr(vaddpd,mem,reg)
#define vec_mul_rr(mem,reg)     gen_vece_rr(vmulpd,mem,reg)
#define vec_sub_rr(mem,reg)     gen_vece_rr(vsubpd,mem,reg)

#define vec_add_rr3(reg1,reg2,reg3)     gen_vece_rr3(vaddpd,reg1,reg2,reg3)
#define vec_mul_rr3(reg1,reg2,reg3)     gen_vece_rr3(vmulpd,reg1,reg2,reg3)
#define vec_fma_rr3(reg1,reg2,reg3)		gen_vece_rr3(vfmadd231pd,reg1,reg2,reg3)
#define vec_fms_rr3(reg1,reg2,reg3)		gen_vece_rr3(vfmsub231pd,reg1,reg2,reg3)
#define vec_sub_rr3(reg1,reg2,reg3)     gen_vece_rr3(vsubpd,reg1,reg2,reg3)
#define vec_div_rr3(reg1,reg2,reg3)     gen_vece_rr3(vdivpd,reg1,reg2,reg3)
#define vec_mov_mr(mem,reg)     gen_vece_mr(vmovupd,mem,reg)
#define vec_mov_rm(reg,mem)     gen_vece_rm(vmovupd,reg,mem)
#define vec_mov_mr_a(mem,reg)   gen_vece_mr(vmovupd,mem,reg)
#define vec_mov_rm_a(reg,mem)   gen_vece_rm(vmovupd,reg,mem)
#define vec_mov_rr(reg1,reg2)   gen_vece_mov(vmovapd,reg1,reg2)
#define vec_red(reg1,reg2)		gen_vece_reduce(reg1,reg2)

#define vec_mov_mr_1(mem,reg)   gen_vec_mr(movsd,mem,reg)
#define vec_mov_rm_1(reg,mem)   gen_vec_rm(movsd,reg,mem)
#define vec_mov_rr_1(reg1,reg2) gen_vec_rr(movsd,reg1,reg2)

/* New conditions here!! */
//c is a temp register to store the comparison results
#define vec_cmp_lt(a, b, c)	gen_cmp(vcmpltpd, a, b, c)
#define vec_cmp_le(a, b, c) gen_cmp(vcmplepd, a, b, c)
#define vec_cmp_eq(a, b, c) gen_cmp(vcmpeqpd, a, b, c)


#define gen_cmp(op, reg1, reg2, reg3) \
	__asm__ __volatile__ (#op " " Y(reg1) ", " Y(reg2) "," Y(reg3) \
		                  : /*nothing*/\
			              : /*nothing*/)

//reg2 stores (1, 1, 1, 1) which is used to translate -nan to a valid number
//reg1 stores the reduced results of the comparison results
#define red_cmp_res(reg1, reg2) \
	__asm__ __volatile__ ("vandpd " Y(reg1) ", " Y(reg2) ", " Y(reg1) "\n" \
			              "vperm2f128 $0x03, " Y(reg1) ", " Y(reg1) ", " Y(reg2) "\n" \
			              "vaddpd " Y(reg1) ", " Y(reg2) ", " Y(reg1) "\n" \
			              "vhaddpd " Y(reg1) ", " Y(reg1) ", " Y(reg1) "\n"\
			              : /* nothing */\
                          : /* nothing */)

#define vec_cmp_lt_sse(a, b, c)	gen_cmp_sse(cmpltpd, a, b, c)
#define vec_cmp_le_sse(a, b, c) gen_cmp_sse(cmplepd, a, b, c)
#define vec_cmp_eq_sse(a, b, c) gen_cmp_sse(cmpeqpd, a, b, c)


#define gen_cmp_sse(op, reg1, reg2, reg3) \
	__asm__ __volatile__ ("movupd " X(reg2) ", "X(reg3) "\n"\
                          #op " "X(reg1) ", " X(reg3) \
		                  : /*nothing*/\
			              : /*nothing*/)

//reg2 stores (1, 1, 1, 1) which is used to translate -nan to a valid number
//reg1 stores the reduced results of the comparison results
#define red_cmp_res_sse(reg1, reg2) \
	__asm__ __volatile__ ("andpd " X(reg2) "," X(reg1) "\n" \
			              "haddpd " X(reg1) ", " X(reg1) \
			              : /* nothing */\
                          : /* nothing */)



#else

#include <SSE3Dnow.h>

#endif
