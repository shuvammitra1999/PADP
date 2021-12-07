#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
    int r , c, i, j, count=0, sum =0, k, t;
    printf("Enter the no of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("enter the number of threads: ");
    scanf("%d", &t);

	//dynamically allocate arrays
    int **arr1 = (int **)malloc(r * sizeof(int *));
    for (i=0; i<r; i++)
         arr1[i] = (int *)malloc(c * sizeof(int));

    int **arr2 = (int **)malloc(r * sizeof(int *));
    for (i=0; i<r; i++)
         arr2[i] = (int *)malloc(c * sizeof(int));
    
    int **arr3 = (int **)malloc(r * sizeof(int *));
    for (i=0; i<r; i++)
         arr3[i] = (int *)malloc(c * sizeof(int));	


	for(i = 0;i < r; i++)  
		for(j = 0;j < c; j++)
			arr1[i][j] = count++;
	
	for(i = 0;i < r; i++)  
		for(j = 0;j < c; j++)
			arr2[i][j] = count++;

	double x = omp_get_wtime();
	omp_set_num_threads(t);
	#pragma omp parallel for private(j, k) 
	for(i = 0; i < r; i++)  
		for(j = 0; j < c; j++)
			for(k = 0;k < r; k++)
				arr3[i][j] += arr1[i][k] * arr2[k][j];

	double y = omp_get_wtime();
	
	printf("time: %lf\n", y-x);
		
   return 0;
}
