#include <stdlib.h>									
#include <stdio.h>									
#include <math.h>									
							

#define PI 3.14159265358979323846264338327

FILE *output;

int main () 
{
 int Nx=101;															
 int Nt=2000;										
 double dx=1/(Nx-1);
 double dt=0.00005;
 double C[Nx][Nt];									
 double x = 0.0;									
 double t = 0.0;									

 double mu=0.5;							
 double s=1;


 output=fopen("datos.dat", "w");


 C[0][0]=0.0;										
 C[Nx-1][0]=0.0;									
 dx=1.0/(Nx-1.0);																					
 for(int i=0; i<Nx; i++){
  x=i*dx;
  C[i][0]=exp(-pow((x-mu),2.0)/(2.0*pow(s,2.0)))/pow((2.0*PI*pow(s,2.0)),0.5);
  C[0][0]=0.0;										
  C[Nx-1][0]=0.0;									
 }




 for(int j=0;j<Nt;j++){
   t+=dt;
	for(int i=1; i<Nx-1; i++){
	 x=i*dx;
	 C[i][j+1] = C[i][j] + (dt/pow(dx,2))*(C[i+1][j] - 2*C[i][j] + C[i-1][j]);
	}
   C[0][j]=0.0;											
   C[Nx-1][j]=0.0;									
 }


 C[10][0]=0.0;											


 for(int i=0; i<Nx; i++){							
   x=i*dx;
   fprintf(output, "%e\t", x);
	for(int j=0; j<Nt; j++){
	 fprintf(output, "%e\t", C[i][j]);
	} 
	 fprintf(output, "\n");
  }


   fflush(output);
   fclose(output);

  return 0;
}