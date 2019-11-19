#include <stdlib.h>									
#include <stdio.h>									
#include <math.h>									

FILE *output;

/*El código en el que me base y modifiqué para el siguiente proceso fue sacado de https://www.dreamincode.net/forums/topic/125770-simulating-diffusion-equation*/
void Funcion(double sigma, double D, int Nx, int Nt);

int main () 
{
	int Nx=30;															
	int Nt=10E3;	/*Para 10E4 no corre*/
	double D = 1;
	double s=1;							
	Funcion(s,D,Nx,Nt);
	
	return 0;
}

void Funcion(double s, double D, int Nx, int Nt)
{
	double x,t;
	double dx = 2/Nx;
	double dt= 1/Nt;
	double C[Nx][Nt];
	
	output=fopen("datos.dat", "w");
	C[0][0]=0.0;										
	C[Nx-1][0]=0.0;									
	dx=2.0/Nx;																					
	for(int i=0; i<Nx; i++)
	{
		x=i*dx;
		C[i][0]=exp(-pow((x),2.0)/(2.0*pow(s,2.0)))/pow((2.0*M_PI*pow(s,2.0)),0.5);
		C[0][0]=0.0;										
		C[Nx-1][0]=0.0;									
	}

	for(int j=0;j<Nt;j++)
	{
		t+=dt;
		for(int i=1; i<Nx-1; i++)
		{
		x=i*dx;
		C[i][j+1] = C[i][j] + (dt/pow(dx,2))*(C[i+1][j] - 2*C[i][j] + C[i-1][j]);
		}
		C[0][j]=0.0;											
		C[Nx-1][j]=0.0;									
	}
	
	C[10][0]=0.0;											

	for(int i=0; i<Nx; i++)
	{							
		x=i*dx;
		fprintf(output, "%e\t", x);
		for(int j=0; j<Nt; j++)
		{
			fprintf(output, "%e\t", C[i][j]);
		} 
		fprintf(output, "\n");
	}

	fflush(output);
	fclose(output);
}