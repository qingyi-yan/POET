#include <immintrin.h>
#if defined(INS_256BIT)
/* Register definition */
#define Y(r)        y##r
#define X(r)        x##r

#define yreg0        "%%ymm0"
#define yreg1        "%%ymm1"
#define yreg2        "%%ymm2"
#define yreg3        "%%ymm3"
#define yreg4        "%%ymm4"
#define yreg5        "%%ymm5"
#define yreg6        "%%ymm6"
#define yreg7        "%%ymm7"
#ifdef ATL_GAS_x8664
    #define yreg8     "%%ymm8"
    #define yreg9     "%%ymm9"
    #define yreg10    "%%ymm10"
    #define yreg11    "%%ymm11"
    #define yreg12    "%%ymm12"
    #define yreg13    "%%ymm13"
    #define yreg14    "%%ymm14"
    #define yreg15    "%%ymm15"
    #define yreg16    "%%ymm0"
#endif
#define xreg0         "%%xmm0"
#define xreg1         "%%xmm1"
#define xreg2         "%%xmm2"
#define xreg3         "%%xmm3"
#define xreg4         "%%xmm4"
#define xreg5         "%%xmm5"
#define xreg6         "%%xmm6"
#define xreg7         "%%xmm7"
#ifdef ATL_GAS_x8664
    #define xreg8     "%%xmm8"
    #define xreg9     "%%xmm9"
    #define xreg10    "%%xmm10"
    #define xreg11    "%%xmm11"
    #define xreg12    "%%xmm12"
    #define xreg13    "%%xmm13"
    #define xreg14    "%%xmm14"
    #define xreg15    "%%xmm15"
    #define xreg16    "%%xmm0"
#endif


/* Structure of inline assembly
 * __asm__ __volatile__ (assembly template \
 *                    : output operand list
 *                    : input operand list
 *                    : clobber list);
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
        __asm__ __volatile__ (#op " %0, " Y(reg1) ", " Y(reg2)\
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
        __asm__ __volatile__(#op " %0, " X(reg)\
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


#define vec_zero(reg)           vzeroupper();
#define vec_splat(mem,reg)      gen_vece_mr(vbroadcastsd,mem,reg)
#define vec_add_rr(mem,reg)     gen_vece_rr(vaddpd,mem,reg)
#define vec_mul_rr(mem,reg)     gen_vece_rr(vmulpd,mem,reg)
#define vec_div_rr(mem,reg)     gen_vece_rr(vdivpd,mem,reg)
#define vec_sub_rr(mem,reg)     gen_vece_rr(vsubpd,mem,reg)

#define vec_add_rr3(reg1,reg2,reg3)     gen_vece_rr3(vaddpd,reg1,reg2,reg3)
#define vec_mul_rr3(reg1,reg2,reg3)     gen_vece_rr3(vmulpd,reg1,reg2,reg3)
#define vec_fma_rr3(reg1,reg2,reg3)     gen_vece_rr3(vfmadd231pd,reg1,reg2,reg3)
#define vec_fms_rr3(reg1,reg2,reg3)     gen_vece_rr3(vfmsub231pd,reg1,reg2,reg3)
#define vec_sub_rr3(reg1,reg2,reg3)     gen_vece_rr3(vsubpd,reg1,reg2,reg3)
#define vec_div_rr3(reg1,reg2,reg3)     gen_vece_rr3(vdivpd,reg1,reg2,reg3)
#define vec_mov_mr(mem,reg)     gen_vece_mr(vmovupd,mem,reg)
#define vec_mov_rm(reg,mem)     gen_vece_rm(vmovupd,reg,mem)
#define vec_mov_mr_a(mem,reg)   gen_vece_mr(vmovupd,mem,reg)
#define vec_mov_rm_a(reg,mem)   gen_vece_rm(vmovupd,reg,mem)
#define vec_mov_rr(reg1,reg2)   gen_vece_mov(vmovapd,reg1,reg2)
#define vec_red(reg1,reg2)      gen_vece_reduce(reg1,reg2)

#define vec_mov_mr_1(mem,reg)   gen_vece_rr(vxorpd,reg,reg); gen_vec_mr(movsd,mem,reg)
#define vec_mov_rm_1(reg,mem)   gen_vec_rm(movsd,reg,mem)
#define vec_mov_rr_1(reg1,reg2) gen_vec_rr(movsd,reg1,reg2)

// 256bit <=
#define gen_cmp_nle(reg1, reg2, reg3, mem) \
    __asm__ __volatile__ ("vcmppd $05," Y(reg1) ", " Y(reg2) "," Y(reg3) "\n"\
                          "vmovmskpd " Y(reg3) ", %%eax\n" \
                          "movl %%eax, %0\n"\
                          :"=m" (((mem)[0])) \
                          : /*nothing*/)

#define gen_cmp_ngt(reg1, reg2, reg3, mem) \
    __asm__ __volatile__ ("vcmppd $10," Y(reg1) ", " Y(reg2) "," Y(reg3) "\n"\
                          "vmovmskpd " Y(reg3) ", %%eax\n" \
                          "movl %%eax, %0\n"\
                          :"=m" (((mem)[0])) \
                          : /*nothing*/)

#define gen_cmp_nge(reg1, reg2, reg3, mem) \
    __asm__ __volatile__ ("vcmppd $9," Y(reg1) ", " Y(reg2) "," Y(reg3) "\n"\
                          "vmovmskpd " Y(reg3) ", %%eax\n" \
                          "movl %%eax, %0\n"\
                          :"=m" (((mem)[0])) \
                          : /*nothing*/)

// 256bit <
#define gen_cmp_nlt(reg1, reg2, reg3, mem) \
    __asm__ __volatile__ ("vcmppd $06," Y(reg1) ", " Y(reg2) "," Y(reg3) "\n"\
                          "vmovmskpd " Y(reg3) ", %%eax\n" \
                          "movl %%eax, %0\n"\
                          :"=m" (((mem)[0])) \
                          : /*nothing*/)

// 256bit ==
#define gen_cmp_eq(reg1, reg2, reg3, mem) \
    __asm__ __volatile__ ("vcmppd $0," Y(reg1) ", " Y(reg2) "," Y(reg3) "\n"\
                          "vmovmskpd " Y(reg3) ", %%eax\n" \
                          "movl %%eax, %0\n"\
                          :"=m" (((mem)[0])) \
                          : /*nothing*/)

//!=
#define gen_cmp_neq(reg1, reg2, reg3, mem) \
    __asm__ __volatile__ ("vcmppd $04," Y(reg1) ", " Y(reg2) "," Y(reg3) "\n"\
                          "vmovmskpd " Y(reg3) ", %%eax\n" \
                          "movl %%eax, %0\n"\
                          :"=m" (((mem)[0])) \
                          : /*nothing*/)


// 128bit ==
#define gen_cmp_eq_sse(reg1, reg2, reg3, mem) \
    __asm__ __volatile__ ("movupd " X(reg2) ", " X(reg3) "\n"\
                          "cmppd $0," X(reg1) ", " X(reg3)  "\n"\
                          "movmskpd " X(reg3) ", %%rax\n" \
                          "movq %%rax, %0\n"\
                          :"=m" (((mem)[0])) \
                          : /*nothing*/)

// 128bit ==
#define gen_cmp_neq_sse(reg1, reg2, reg3, mem) \
    __asm__ __volatile__ ("movupd " X(reg2) ", " X(reg3) "\n"\
                          "cmppd $04," X(reg1) ", " X(reg3)  "\n"\
                          "movmskpd " X(reg3) ", %%rax\n" \
                          "movq %%rax, %0\n"\
                          :"=m" (((mem)[0])) \
                          : /*nothing*/)


// 128bit <=
#define gen_cmp_nle_sse(reg1, reg2, reg3, mem) \
    __asm__ __volatile__ ("movupd " X(reg2) ", " X(reg3) "\n"\
                          "cmppd $5," X(reg1) ", " X(reg3)  "\n"\
                          "movmskpd " X(reg3) ", %%rax\n" \
                          "movq %%rax, %0\n"\
                          :"=m" (((mem)[0])) \
                          : /*nothing*/)

// 128bit <
#define gen_cmp_nlt_sse(reg1, reg2, reg3, mem) \
    __asm__ __volatile__ ("movupd " X(reg2) ", " X(reg3) "\n"\
                          "cmppd $6," X(reg1) ", " X(reg3)  "\n"\
                          "movmskpd " X(reg3) ", %%rax\n" \
                          "movq %%eax, %0\n"\
                          :"=m" (((mem)[0])) \
                          : /*nothing*/)

// 128bit <=
#define gen_cmp_nge_sse(reg1, reg2, reg3, mem) \
    __asm__ __volatile__ ("movupd " X(reg2) ", " X(reg3) "\n"\
                          "cmppd $9," X(reg1) ", " X(reg3)  "\n"\
                          "movmskpd " X(reg3) ", %%rax\n" \
                          "movq %%rax, %0\n"\
                          :"=m" (((mem)[0])) \
                          : /*nothing*/)

// 128bit <
#define gen_cmp_ngt_sse(reg1, reg2, reg3, mem) \
    __asm__ __volatile__ ("movupd " X(reg2) ", " X(reg3) "\n"\
                          "cmppd $10," X(reg1) ", " X(reg3)  "\n"\
                          "movmskpd " X(reg3) ", %%rax\n" \
                          "movq %%eax, %0\n"\
                          :"=m" (((mem)[0])) \
                          : /*nothing*/)

#define vec_bitand_rr(reg1, reg2) \
    __asm__ __volatile__ ("vandpd " Y(reg1)", " Y(reg2) "," Y(reg2) "\n" \
                          ::)


#define vec_bitand_rr_1(reg1, reg2) \
    __asm__ __volatile__ ("andpd " X(reg1)", " X(reg2) "\n" \
                          ::)
#else

//#include </home/hhill2/POET/trunk/include/SSE3Dnow.h>
#include <SSE3Dnow.h>
#endif
