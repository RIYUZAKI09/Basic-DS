#include<bits/stdc++.h>

struct Element{
	int row;
	int col;
	int value;
};

struct Sparse{
	int m;
	int n;
	int nz;
	struct Element* e;
};

typedef struct Sparse sparseMatrix; 
typedef struct Element valueMatrix;

void create(sparseMatrix* s){
	printf("Enter the no. of rows and columns respectively\n");
	scanf("%d%d",&s->m,&s->n);
	printf("Enter number of non zero elements\n");
	scanf("%d",&s->nz);
	s->e = (struct Element *)malloc(s->nz*sizeof(valueMatrix));
	printf("Enter all non zero elements\n");
	for (int i = 0; i < s->nz; i++){
		printf("Enter the row column and the value of element\n");	
		scanf("%d%d%d",&s->e[i].row,&s->e[i].col,&s->e[i].value);
	}
}

void printSparseMatrix(sparseMatrix s){
	int i,j,k=0;

	for (i = 0; i < s.m; i++)
	{
		for (j = 0; j < s.n; j++)
		{
			if(i==s.e[k].row and j==s.e[k].col){
				printf("%d ",s.e[k].value);
				k++;
			}else{
				printf("0 ");
			}
		}
		printf("\n");
	}
	printf("\n");
}

sparseMatrix add(sparseMatrix A,sparseMatrix B){
	sparseMatrix sum;
	if(A.m != A.m or A.n != B.n){
		printf("Matrices cannot be added\n");
		return sum;
	}
	sum.m = A.m;
	sum.n = A.n;
	sum.e = (struct Element*)malloc((A.nz + B.nz)*sizeof(struct Element));

	int i=0,j=0,k=0;
	while(i<A.nz and j<B.nz){
		if(A.e[i].row < B.e[j].row){
			sum.e[k] = A.e[i];
			k++;
			i++;
		}else if(A.e[i].row > B.e[j].row){
			sum.e[k] = B.e[j];
			k++;
			j++;
		}else{
			if(A.e[i].col < B.e[j].col){
				sum.e[k] = A.e[i];
				k++;
				i++;
			}else if(A.e[i].col > B.e[j].col){
				sum.e[k] = B.e[j];
				k++;
				j++;
			}else{
				sum.e[k] = A.e[i];
				sum.e[k].value = A.e[i].value + B.e[j].value;
				i++;
				j++;
				k++;
			}
		}
	}

	return sum;
}

sparseMatrix transpose(sparseMatrix A){
	sparseMatrix AT;
	AT.m = A.n;
	AT.n = A.m;
	AT.nz = A.nz;
	int I[A.n ] ;
	for (int i = 0; i < A.n; ++i)
	{
		I[i] = 0;
	}
	int T[(A.n)];
	for (int i = 0; i < A.nz ; i++)
	{
		I[A.e[i].col]++;
	}
	T[0]=0;
	for (int i = 1; i < A.n; i++)
	{
		T[i] = T[i-1]+I[i-1];
	}
	AT.e = (struct Element*)malloc(A.nz*sizeof(struct Element));
	for(int i=0;i<A.nz;i++){
		AT.e[T[A.e[i].col]].row = A.e[i].col;
		AT.e[T[A.e[i].col]].col = A.e[i].row;
		AT.e[T[A.e[i].col]].value = A.e[i].value;				
		T[A.e[i].col]++;
	}

	return AT;

}



int main(int argc, char const *argv[])
{
	sparseMatrix A;
	printf("Enter first Matrix\n");
	create(&A);
	sparseMatrix B;
	printf("Enter Second Matrix\n");
	create(&B);
	sparseMatrix sum;
	sum = add(A,B);
	printf("First Matrix\n");
	printSparseMatrix(A);
	printf("Second Matrix\n");
	printSparseMatrix(B);
	printf("Resultant Matrix\n");
	printSparseMatrix(sum);

	return 0;
}
