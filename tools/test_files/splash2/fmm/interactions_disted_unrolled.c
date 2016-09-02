
#include <stdlib.h>
void VListInteraction(long  my_id,box* source_box,box* dest_box) {
   complex z0;
   complex z0_inv;
   complex z0_pow_minus_n[MAX_EXPANSION_TERMS];
   complex temp_exp[MAX_EXPANSION_TERMS];
   complex result_exp;
   complex source_pos;
   complex dest_pos;
   complex temp;
   long  k;
   long  j;
   if (source_box->type==CHILDLESS)  
     {
        while (source_box->interaction_synch!=1)  
          {
             ;
          }
     }
   else 
     {
        while (source_box->interaction_synch!=source_box->num_children)  
          {
             ;
          }
     }
   source_pos.r = source_box->x_center;
   source_pos.i = source_box->y_center;
   dest_pos.r = dest_box->x_center;
   dest_pos.i = dest_box->y_center;
   COMPLEX_SUB(z0,source_pos,dest_pos);
   COMPLEX_DIV(z0_inv,One,z0);
   z0_pow_minus_n[0].r = One.r;
   z0_pow_minus_n[0].i = One.i;
   temp_exp[0].r = source_box->mp_expansion[0].r;
   temp_exp[0].i = source_box->mp_expansion[0].i;
   
   /*@;BEGIN(Nest1_1=Nest)@*/for (k=1; k<-1+Expansion_Terms; k+=2) 
     {
        z0_pow_minus_n[k].r = z0_pow_minus_n[-1+k].r*z0_inv.r-z0_pow_minus_n[-1+k].i*z0_inv.i;
        z0_pow_minus_n[k].i = z0_pow_minus_n[-1+k].r*z0_inv.i+z0_pow_minus_n[-1+k].i*z0_inv.r;
        z0_pow_minus_n[1+k].r = z0_pow_minus_n[k].r*z0_inv.r-z0_pow_minus_n[k].i*z0_inv.i;
        z0_pow_minus_n[1+k].i = z0_pow_minus_n[k].r*z0_inv.i+z0_pow_minus_n[k].i*z0_inv.r;
     }
   for (k=k; k<Expansion_Terms; k+=1) 
     {
        z0_pow_minus_n[k].r = z0_pow_minus_n[k-1].r*z0_inv.r-z0_pow_minus_n[k-1].i*z0_inv.i;
        z0_pow_minus_n[k].i = z0_pow_minus_n[k-1].r*z0_inv.i+z0_pow_minus_n[k-1].i*z0_inv.r;
     }
   /*@;BEGIN(Nest1_2=Nest)@*/for (k=1; k<Expansion_Terms; k+=1) 
     {
        /*@;BEGIN(Stmt1=ExpStmt)@*/COMPLEX_MUL(temp_exp[k],z0_pow_minus_n[k],source_box->mp_expansion[k]);
     }
   /*@;BEGIN(Nest2=Nest)@*/for (k=0; k<Expansion_Terms; k+=1) 
     {
        result_exp.r = (real)0.0;
        result_exp.i = (real)0.0;
        /*@;BEGIN(Nest3=Nest)@*/for (j=1; j<-1+Expansion_Terms; j+=2) 
          {
             temp.r = C[-1+(k+j)][-1+j];
             temp.i = (real)0.0;
             COMPLEX_MUL(temp,temp,temp_exp[j]);
             /*@; BEGIN(Stmt2=Stmt)@*/if ((j&0x1)==0x0)  
               {
                  COMPLEX_ADD(result_exp,result_exp,temp);
               }
             /*@; BEGIN(Stmt3=Stmt)@*/else 
               {
                  COMPLEX_SUB(result_exp,result_exp,temp);
               }
             temp.r = C[-1+(k+(1+j))][j];
             temp.i = (real)0.0;
             COMPLEX_MUL(temp,temp,temp_exp[1+j]);
             /*@; BEGIN(Stmt4=Stmt)@*/if ((1+j&0x1)==0x0)  
               {
                  COMPLEX_ADD(result_exp,result_exp,temp);
               }
             /*@; BEGIN(Stmt5=Stmt)@*/else 
               {
                  COMPLEX_SUB(result_exp,result_exp,temp);
               }
          }
        for (j=j; j<Expansion_Terms; j+=1) 
          {
             temp.r = C[k+j-1][j-1];
             temp.i = (real)0.0;
             COMPLEX_MUL(temp,temp,temp_exp[j]);
             if ((j&0x1)==0x0)  
               {
                  COMPLEX_ADD(result_exp,result_exp,temp);
               }
             else 
               {
                  COMPLEX_SUB(result_exp,result_exp,temp);
               }
          }
        COMPLEX_MUL(result_exp,result_exp,z0_pow_minus_n[k]);
        if (k==0)  
          {
             temp.r = log(COMPLEX_ABS(z0));
             temp.i = (real)0.0;
             COMPLEX_MUL(temp,temp,source_box->mp_expansion[0]);
             COMPLEX_ADD(result_exp,result_exp,temp);
          }
        else 
          {
             temp.r = Inv[k];
             temp.i = (real)0.0;
             COMPLEX_MUL(temp,temp,z0_pow_minus_n[k]);
             COMPLEX_MUL(temp,temp,source_box->mp_expansion[0]);
             COMPLEX_SUB(result_exp,result_exp,temp);
          }
        COMPLEX_ADD(dest_box->local_expansion[k],dest_box->local_expansion[k],result_exp);
     }
   dest_box->cost = dest_box->cost+V_LIST_COST(Expansion_Terms);
}
