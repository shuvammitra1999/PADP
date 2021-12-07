#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#define SEED 35791246
 
void main()
{
	int n = 0, i, count = 0, th;
	double z, pi, x,y, t;


	printf("Enter the number of iterations used to estimate pi: ");
	scanf("%d", &n);
    printf("Enter the number of threads ");
    scanf("%d", &th);
	srand(SEED);
	
    t = omp_get_wtime();
	#pragma omp parallel for num_threads(th)
	for ( i=0; i<n; i++) 
	{
		x = (double)rand()/RAND_MAX;
		y = (double)rand()/RAND_MAX;
		z = x*x+y*y;
		if (z<=1) count++;
	}
	pi=(double)count/n*4;

    t = omp_get_wtime() - t;
	
	printf("# of threads = %d, # of trials= %d , estimate of pi is %g , time = %g \n", th, n,pi, t);
}
