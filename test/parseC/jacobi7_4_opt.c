#define max(a,b) (((a) < (b))? (b) : (a))
#define min(a,b) (((a) < (b))? (a) : (b))
#include <pthread.h>
#include <stdlib.h>
struct t_WorkGroup_Type {
  pthread_mutex_t mutex;
  pthread_cond_t cond;
  int ready;
} *t_workgroup;
void* t_pipeline(void *input); 
#define Index3D(_nx,_ny,_i,_j,_k) ((_i)+_nx*((_j)+_ny*(_k)))
void jacobi7_4(const int nx,const int ny,int nz,const double alpha,double * A0,const int timesteps,const double * B,const int ldb,double * Anext,const int ldc) 
{
   double fac;
   double * temp_ptr;
   int i,j,k,t;
   fac = 6.0/(A0[0]*A0[0]);
   double * l0,* lnext;
   
     int ___i;
     t_workgroup = (struct t_WorkGroup_Type*)malloc(-1+(nz-1)*sizeof(struct t_WorkGroup_Type));
     for(___i=0;___i<-1+(nz-1); ___i++) {
         struct t_WorkGroup_Type* cur = t_workgroup+___i;
         pthread_mutex_init(&cur->mutex, NULL);
         pthread_cond_init(&cur->cond, NULL);
         cur->ready = -1;
     }
     struct t_Params_Type {
       double* temp_ptr;
       double fac;
       int ldc;
       double* Anext;
       int ldb;
       const double* B;
       int timesteps;
       double* A0;
       double alpha;
       int nz;
       int ny;
       int nx;;
     };
     struct t_WorkBlock_Type {
       struct t_Params_Type* params;
       int begin,end;
     };
   
     struct t_Params_Type t_params;
     t_params.temp_ptr = (double*)temp_ptr;
     t_params.fac = (double)fac;
     t_params.ldc = (int)ldc;
     t_params.Anext = (double*)Anext;
     t_params.ldb = (int)ldb;
     t_params.B = (const double*)B;
     t_params.timesteps = (int)timesteps;
     t_params.A0 = (double*)A0;
     t_params.alpha = (double)alpha;
     t_params.nz = (int)nz;
     t_params.ny = (int)ny;
     t_params.nx = (int)nx;
   
     pthread_t *thread_id = (pthread_t*)malloc(sizeof(pthread_t) * 2);
     unsigned worksize = -1+(nz-1) / 2 + 1;
     for(___i=0; ___i < 2; ___i++) {
        struct t_WorkBlock_Type *cur = (struct t_WorkBlock_Type*)malloc(sizeof(struct t_WorkBlock_Type));
        cur->params = &t_params;
        cur->begin = ___i * worksize; cur->end = cur->begin + worksize;
        pthread_create(&thread_id[___i], NULL, t_pipeline, (void *)cur);
     }
   
     for(___i=0; ___i < 2;___i++) {
        pthread_join(thread_id[___i], NULL);
     }
   
     for(___i=0;___i<-1+(nz-1); ___i++) {
         struct t_WorkGroup_Type* cur = t_workgroup + ___i;
         pthread_mutex_destroy(&cur->mutex);
         pthread_cond_destroy(&cur->cond);
     }
}
void* t_pipeline(void *input) {
  struct t_Params_Type {
    double* temp_ptr;
    double fac;
    int ldc;
    double* Anext;
    int ldb;
    const double* B;
    int timesteps;
    double* A0;
    double alpha;
    int nz;
    int ny;
    int nx;;
  };
  struct t_WorkBlock_Type {
    struct t_Params_Type* params;
    int begin,end;
  };
  struct t_WorkBlock_Type *cur = (struct t_WorkBlock_Type *)input;
  int ___BEGIN=cur->begin; int ___END=cur->end;
  struct t_Params_Type *cur_params = cur->params;
  double* temp_ptr=cur_params->temp_ptr;
  double fac=cur_params->fac;
  int ldc=cur_params->ldc;
  double* Anext=cur_params->Anext;
  int ldb=cur_params->ldb;
  const double* B=cur_params->B;
  int timesteps=cur_params->timesteps;
  double* A0=cur_params->A0;
  double alpha=cur_params->alpha;
  int nz=cur_params->nz;
  int ny=cur_params->ny;
  int nx=cur_params->nx;
  double* lnext;
  double* l0;
  int t;
  int k;
  int j;
  int i;
  /*@;BEGIN(Nest1=Nest)@*/for (t=0; t<timesteps; t+=1) 
    {
       for (k=1+___BEGIN; k<min(1+___END,nz-1); k+=1) 
         {
            if (k<-1+(nz-1))  
              {
                 {
                   struct t_WorkGroup_Type* cur = t_workgroup + 1+k;
                   pthread_mutex_lock(&cur->mutex);
                   while (cur->ready < -1+t)
                      pthread_cond_wait(&cur->cond, &cur->mutex);
                   pthread_mutex_unlock(&cur->mutex);
                 }
              }
            if (k>=2)  
              {
                 {
                   struct t_WorkGroup_Type* cur = t_workgroup + -1+k;
                   pthread_mutex_lock(&cur->mutex);
                   while (cur->ready < -1+t)
                      pthread_cond_wait(&cur->cond, &cur->mutex);
                   pthread_mutex_unlock(&cur->mutex);
                 }
              }
            /*@;BEGIN(Nest3=Nest)@*/for (j=1; j<ny-1; j+=1) 
              {
                 /*@;BEGIN(Nest4=Nest)@*/for (i=1; i<nx-1; i+=1) 
                   {
                      if (t%2==0)  
                        {
                           l0 = A0;
                           lnext = Anext;
                        }
                      else 
                        {
                           lnext = A0;
                           l0 = Anext;
                        }
                      lnext[Index3D(nx,ny,i,j,k)] = l0[Index3D(nx,ny,i,j,(k)+1)]+l0[Index3D(nx,ny,i,j,k-1)]+l0[Index3D(nx,ny,i,j+1,k)]+l0[Index3D(nx,ny,i,j-1,k)]+l0[Index3D(nx,ny,i+1,j,k)]+l0[Index3D(nx,ny,i-1,j,k)]-l0[Index3D(nx,ny,(i),j,k)]*fac;
                   }
              }
            {
              struct t_WorkGroup_Type* cur = t_workgroup + k;
              pthread_mutex_lock(&cur->mutex);
              cur->ready ++;
              pthread_cond_signal(&cur->cond);
              pthread_mutex_unlock(&cur->mutex);
            }
         }
    }
}
