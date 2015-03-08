#include<stdio.h>
#include<stdlib.h>

double **K, **kt1, **kt2, **kt3, *R, **A;
double I[2][2] = {{1,-1},{-1,1}};

void swap(double *a,double *b) 
{ 
	double temp;
	temp=*a; 
	*a=*b; 
	*b=temp; 
}

void display(char *prin, double **a,int row,int col)
{
	int i,j;
	printf("\n");
	
	if(prin == "kt1")
		printf("kt1  \n");
	else if(prin == "kt2")
		printf("kt2 \n");
	else if(prin == "kt3")
		printf("kt3 \n");
	else if(prin == "K")
		printf("K \n");
			
	for(i=0;i<row;i++)
	{
		printf("|\t");
		for(j=0;j<col;j++)
		{
			printf("%lf\t",a[i][j]);			
		}
		printf("|");
		printf("\n");
	}
}

void conv_matrix(double **a, double h1)
{
	int i,j;
	double conv_mat[2][2] = {{h1,0},{0,0}};
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
			a[i][j] += conv_mat[i][j];
		}
	}
}

void ele_conduc_mat(double **a,float cons,double b[2][2],int row,int col)
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

double max(double **a,int row,int col)
{
	int i,j;
	double max;	
	max = 0;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)	
		{
			if(a[i][j] > max)
			{
				max = a[i][j];
			}
		}
	}
	return max;
}

void summation(double **a,double **b,double **c,double **d)
{	
	a[0][0] = b[0][0];
	a[0][1] = b[0][1];
	a[1][0] = b[1][0];
	a[1][1] = b[1][1]+c[0][0];
	a[1][2] = c[0][1];
	a[2][1] = c[1][0];
	a[2][2] = c[1][1]+d[0][0];
	a[2][3] = d[0][1];
	a[3][2] = d[1][0];
	a[3][3] = d[1][1];
}

int main()
{
	int i,j;
	float k1,k2,k3,l1,l2,l3;
	double h,t,temp,C;	
	double T[4] = {0,0,0,0};
	float cons;
	double INV[3][3],det=0.0;
	
	K = (double**) calloc(4,sizeof(double *));    
    for (i = 0; i < 4; i++)
    {
        K[i] = (double*) calloc(4,sizeof(double));
    }
    
	A = (double**) calloc(3,sizeof(double *));    
    for (i = 0; i < 3; i++)
    {
        A[i] = (double*) calloc(3,sizeof(double));
    }
	    
    R = (double*) calloc(4,sizeof(double *));    
    
    				
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
	scanf("%lf",&h);

	printf("\n Enter T : ");	
	fflush(stdin);
	scanf("%lf",&t);		
	
	/*printf("\n Enter T1 : ");	
	fflush(stdin);
	scanf("%lf",&T1);
	
	printf("\n Enter T2 : ");	
	fflush(stdin);
	scanf("%lf",&T2);
	
	printf("\n Enter T3 : ");	
	fflush(stdin);
	scanf("%lf",&T3);*/
	
	printf("\n Enter T4 : ");	
	fflush(stdin);
	scanf("%lf",&T[3]);		
	
	cons = k1/l1;	
	kt1 = (double**) malloc(2*sizeof(double *));    
    for (i = 0; i < 2; i++)
    {
        kt1[i] = (double*) malloc(2*sizeof(double));
    }	
	ele_conduc_mat(kt1,cons,I,2,2);
	conv_matrix(kt1,h);
	display("kt1",kt1,2,2);
	
	cons = k2/l2;	
	kt2 = (double**) malloc(2*sizeof(double *));    
    for (i = 0; i < 2; i++)
    {
        kt2[i] = (double*) malloc(2*sizeof(double));
    }
	ele_conduc_mat(kt2,cons,I,2,2);
	display("kt2",kt2,2,2);
	
	cons = k3/l3;	
	kt3 = (double**) malloc(2*sizeof(double *));    
    for (i = 0; i < 2; i++)
    {
        kt3[i] = (double*) malloc(2*sizeof(double));
    }
	ele_conduc_mat(kt3,cons,I,2,2);
	display("kt3",kt3,2,2);
	
	summation(K,kt1,kt2,kt3);
	display("K",K,4,4);
	
	C = max(K,4,4);
	//printf("%lf",C);
		
	temp = h*t;    	
    R[0] = temp;
    R[1] = 0;
    R[2] = 0;
    R[3] = C*T[3];		    	
	
	for(i=0;i<3;i++)
	{	
		for(j=0;j<3;j++)		
 			A[i][j]=(K[(i+1)%3][(j+1)%3]*K[(i+2)%3][(j+2)%3]) - (K[(i+1)%3][(j+2)%3]*K[(i+2)%3][(j+1)%3]); 
	}
	
	for(i=0;i<3;i++)
		det+=K[i][0]*A[i][0];  
	
	printf("\n\n\n"); 
	
	if(det==0) 
	{  
		printf("SINGULAR MATRIX !\nCANNOT FIND THE SOLUTION\n\n\tPress any key to exit.");
		getch(); 
		exit(1); 
	}
	
	for(i=0;i<2;i++)
	{
		for(j=i+1;j<3;j++)
			swap(&A[i][j], &A[j][i]); 
	} 
	for(i=0;i<3;i++)
	{ 
		for(j=0;j<3;j++)
			INV[i][j]=A[i][j]/det; 
	}

	for(i=0;i<3;i++) 
	{ 
		T[i]=0.0;
		for(j=0;j<3;j++)
		{
			T[i]+=INV[i][j]*R[j];
		} 
	}
	
	for(i=0;i<4;i++)
	{
		printf("\n");
		for(j=0;j<4;j++)
		{
			printf(" |\t %lf\t ",K[i][j]);
		}
		printf("|\t |\t T%d\t |\t |\t %lf\t |",i+1,R[i]);
	}
	
	printf("\n\n \tT1=%.2lf \tT2=%.2lf \tT3=%.2lf \tT4=%.2lf",T[0],T[1],T[2],T[3]);
	
	return 0;	
}
