#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "rdjpeg.h"
#define RBINS 4
#define GBINS 4
#define BBINS 4


int main(int argc, char *argv[])
{
  double h[RBINS*GBINS*BBINS];
  int i,j,n,nx,ny,nb,k,nbImage;
  int ir,ib,ig; //indices
  CIMAGE cim;
  for(nbImage=1;nbImage<argv.lenght;nbImage++){ //vérifier lenght ! 

    for(k=0; k<RBINS*GBINS*BBINS; k++) h[k]=0;
    /*------------------------------------------------*/
    /* lecture d'une image requête                    */
    /*------------------------------------------------*/
    read_cimage(argv[nbImage],&cim);
    /*------------------------------------------------*/
    /* affichage des valeurs pour le premier bloc 8x8 */
    /* comme exemple de traitement                    */
    /*------------------------------------------------*/
    printf("Largeur de l'image : %d\n",cim.nx);
    printf("Heuteur de l'image : %d\n",cim.ny);
    printf("histogramme %dx%dx%d:\n",RBINS,GBINS,BBINS);
    for (j = 0; j < cim.ny; j++) {       /* ligne par ligne */
      for (i = 0; i < cim.nx; i++) {   /* pixel par pixel */
          ir = (cim.r[i][j]*RBINS)/256;
          ib = (cim.b[i][j]*BBINS)/256;
          ig = (cim.g[i][j]*GBINS)/256;
          h[ir + RBINS*ig + RBINS*GBINS*ib]+=1;
      }
    }

    for (k=0;k<RBINS*GBINS*BBINS;k++){ 
      h[k]=h[k]/(cim.nx*cim.ny);
      printf("%f",h[k]);  //Copier dans un fichier
    }
  }  

  /*------------------------------------------------*/

  exit(0);
}
