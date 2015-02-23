#include<stdio.h>

double **K, **kt1, **kt2, **kt3;
double I[2][2] = {1,-1,-1,1};

void display(double **a,int row,int col)
{
	int i,j;
	printf("\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%.2lf \t",a[i][j]);
		}
		printf("\n");
	}
}

void ele_conduc_mat(double **a,int cons,double b[2][2],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)	
	{
		for(j=0;j<col;j++)
		{			
			a[i][j] = cons * b[i][j];	
		}		
	}
}

void summation()
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(i == 0)			
			{
				K[i][j] = kt1[i][j];	
			}				
			if(i == 1)
			{
				
			}
			else
				K[i][j] = 0;
		}
	}
}

int main()
{
	int i;
	float k1,k2,k3,l1,l2,l3,h,T;	
	float cons;
	
	K = (double**) malloc(4*sizeof(double *));    
    	for (i = 0; i < 4; i++)
    	{
        	K[i] = (double*) malloc(4*sizeof(double));
    	}
	//display(I,2,2);
			
	printf("\n Enter k1 : ");
	fflush(stdin);
	scanf("%f",&k1);
	printf("\n Enter l1 : ");
	fflush(stdin);
	scanf("%f",&l1);
	
	printf("\n Enter k2 : ");
	fflush(stdin);
	scanf("%f",&k2);
	printf("\n Enter l2 : ");
	fflush(stdin);
	scanf("%f",&l2);
	
	printf("\n Enter k3 : ");
	fflush(stdin);
	scanf("%f",&k3);
	printf("\n Enter l3 : ");
	fflush(stdin);
	scanf("%f",&l3);
	
	printf("\n Enter h : ");
	fflush(stdin);
	scanf("%f",&h);

	printf("\n Enter T : ");	
	fflush(stdin);
	scanf("%f",&T);
	
	cons = k1/l1;
	//printf("%.2f \n",cons);
	kt1 = (double**) malloc(2*sizeof(double *));    
    	for (i = 0; i < 2; i++)
    	{
        	kt1[i] = (double*) malloc(2*sizeof(double));
    	}	
	ele_conduc_mat(kt1,cons,I,2,2);
	display(kt1,2,2);
	
	cons = k2/l2;
	//printf("%.2f \n",cons);
	kt2 = (double**) malloc(2*sizeof(double *));    
    	for (i = 0; i < 2; i++)
    	{
        	kt2[i] = (double*) malloc(2*sizeof(double));
    	}
	ele_conduc_mat(kt2,cons,I,2,2);
	display(kt2,2,2);
	
	cons = k3/l3;
	//printf("%.2f \n",cons);
	kt3 = (double**) malloc(2*sizeof(double *));    
    	for (i = 0; i < 2; i++)
    	{
        	kt3[i] = (double*) malloc(2*sizeof(double));
    	}
	ele_conduc_mat(kt3,cons,I,2,2);
	display(kt3,2,2);
	
	summation();
	display(K,4,4);
	
	return 0;	
}
