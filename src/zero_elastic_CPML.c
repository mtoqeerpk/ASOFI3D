/* ----------------------------------------------------------------------
 * Initialization of the wave field with zero values (zero wavefield)
 *
 * ----------------------------------------------------------------------*/

#include "data_structures.h"
#include "fd.h"
#include "globvar.h"


void zero_elastic_CPML(int NX, int NY, int NZ, Velocity *v,
                       Tensor3d *s, Tensor3d *r,
                       float *** psi_sxx_x, float *** psi_sxy_x, float *** psi_sxz_x, float *** psi_sxy_y, float *** psi_syy_y, float *** psi_syz_y, float *** psi_sxz_z, float *** psi_syz_z, float *** psi_szz_z, float *** psi_vxx, float *** psi_vyx, float *** psi_vzx, float *** psi_vxy, float *** psi_vyy, float *** psi_vzy, float *** psi_vxz, float *** psi_vyz, float *** psi_vzz,
                       Tensor3d *r_2,
                       Tensor3d *r_3,
                       Tensor3d *r_4) {


    extern int FDORDER, ABS_TYPE, FW, POS[4],L,FDORDER_TIME;
    int nx1, ny1, nz1, nx2, ny2, nz2, a,b,l, i, j, k;

    float *** vx = v->x;
    float *** vy = v->y;
    float *** vz = v->z;

    float ***sxx = s->xx;
    float ***syy = s->yy;
    float ***szz = s->zz;
    float ***sxy = s->xy;
    float ***syz = s->yz;
    float ***sxz = s->xz;

    float ***rxx = r->xx;
    float ***ryy = r->yy;
    float ***rzz = r->zz;
    float ***rxy = r->xy;
    float ***ryz = r->yz;
    float ***rxz = r->xz;

    float ***rxx_2 = r_2->xx;
    float ***ryy_2 = r_2->yy;
    float ***rzz_2 = r_2->zz;
    float ***rxy_2 = r_2->xy;
    float ***ryz_2 = r_2->yz;
    float ***rxz_2 = r_2->xz;

    float ***rxx_3 = r_3->xx;
    float ***ryy_3 = r_3->yy;
    float ***rzz_3 = r_3->zz;
    float ***rxy_3 = r_3->xy;
    float ***ryz_3 = r_3->yz;
    float ***rxz_3 = r_3->xz;

    float ***rxx_4 = r_4->xx;
    float ***ryy_4 = r_4->yy;
    float ***rzz_4 = r_4->zz;
    float ***rxy_4 = r_4->xy;
    float ***ryz_4 = r_4->yz;
    float ***rxz_4 = r_4->xz;

    l=1;
    if(ABS_TYPE==1 && FDORDER==2){l=2;}
	
	if(POS[2]==0){
	  a=0;
	  b=1;}
	else{
	  a=1;
	  b=l;}
	

    ny1=a-b*FDORDER/2;
    ny2=NY+l*FDORDER/2;
    nx1=1-l*FDORDER/2;
    nx2=NX+l*FDORDER/2;
    nz1=1-l*FDORDER/2;
    nz2=NZ+l*FDORDER/2;

	  

    for (j=ny1;j<=ny2;j++){
      for (i=nx1;i<=nx2;i++){
	for (k=nz1;k<=nz2;k++){
	  vx[j][i][k]=0.0;
	  vy[j][i][k]=0.0;
	  vz[j][i][k]=0.0;
	  sxy[j][i][k]=0.0;
	  syz[j][i][k]=0.0;
	}
      }
    }	
	
    ny1=1-l*FDORDER/2;
   
    for (j=ny1;j<=ny2;j++){
      for (i=nx1;i<=nx2;i++){
	for (k=nz1;k<=nz2;k++){	  
	  sxx[j][i][k]=0.0;
	  sxz[j][i][k]=0.0;
	  syy[j][i][k]=0.0;
	  szz[j][i][k]=0.0;
	}
      }
    }		
	
	
	
	
    if(L){	
	for (j=1;j<=NY;j++){
	  for (i=1;i<=NX;i++){
	    for (k=1;k<=NZ;k++){
	      rxx[j][i][k]=0.0;
	      rxy[j][i][k]=0.0;
	      rxz[j][i][k]=0.0;
	      ryy[j][i][k]=0.0;
	      ryz[j][i][k]=0.0;
	      rzz[j][i][k]=0.0;
            if (FDORDER_TIME>2) {
                rxx_2[j][i][k]=0.0;
                ryy_2[j][i][k]=0.0;
                rzz_2[j][i][k]=0.0;
                rxy_2[j][i][k]=0.0;
                ryz_2[j][i][k]=0.0;
                rxz_2[j][i][k]=0.0;
                rxx_3[j][i][k]=0.0;
                ryy_3[j][i][k]=0.0;
                rzz_3[j][i][k]=0.0;
                rxy_3[j][i][k]=0.0;
                ryz_3[j][i][k]=0.0;
                rxz_3[j][i][k]=0.0;
                if (FDORDER_TIME==4) {
                    rxx_4[j][i][k]=0.0;
                    ryy_4[j][i][k]=0.0;
                    rzz_4[j][i][k]=0.0;
                    rxy_4[j][i][k]=0.0;
                    ryz_4[j][i][k]=0.0;
                    rxz_4[j][i][k]=0.0;
                }
            }
	    }
	  }
	}
    }
    
    for (j=1;j<=NY;j++){
      for (i=1;i<=NX;i++){
	for (k=1;k<=2*FW;k++){
	 psi_sxz_z[j][i][k]=0.0;
	 psi_syz_z[j][i][k]=0.0;
	 psi_szz_z[j][i][k]=0.0;
	 psi_vxz[j][i][k]=0.0;
	 psi_vyz[j][i][k]=0.0;
	 psi_vzz[j][i][k]=0.0;
	}
      }
    }

     for (j=1;j<=NY;j++){
      for (i=1;i<=2*FW;i++){
	for (k=1;k<=NZ;k++){
	 psi_sxx_x[j][i][k]=0.0;
	 psi_sxy_x[j][i][k]=0.0;
	 psi_sxz_x[j][i][k]=0.0;
	 psi_vxx[j][i][k]=0.0;
	 psi_vyx[j][i][k]=0.0;
	 psi_vzx[j][i][k]=0.0;
	}
      }
    }   

for (j=1;j<=2*FW;j++){
      for (i=1;i<=NX;i++){
	for (k=1;k<=NZ;k++){
	 psi_sxy_y[j][i][k]=0.0;
	 psi_syy_y[j][i][k]=0.0;
	 psi_syz_y[j][i][k]=0.0;
	 psi_vxy[j][i][k]=0.0;
	 psi_vyy[j][i][k]=0.0;
	 psi_vzy[j][i][k]=0.0;
	}
      }
    }   
}
