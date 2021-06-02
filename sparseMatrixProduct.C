#include<bits/stdc++.h>
#define size 10

struct sparse
{
   int nrows;
   int ncols;
   int nz;
   int row[size];
   int col[size];
   int value[size];
};
typedef struct sparse Sparse;
 
void create(Sparse* s){
   printf("Enter the no. of rows and columns respectively\n");
   scanf("%d%d",&s->nrows,&s->ncols);
   printf("Enter number of non zero elements\n");
   scanf("%d",&s->nz);
   printf("Enter all non zero elements\n");
   for (int i = 0; i < s->nz; i++){
      printf("Enter the row column and the value of element\n");  
      scanf("%d%d%d",&s->row[i],&s->col[i],&s->value[i]);
   }
}

void printSparseMatrix(Sparse s){
   int i,j,k=0;

   for (i = 0; i < s.nrows; i++)
   {
      for (j = 0; j < s.ncols; j++)
      {
         if(i==s.row[k] and j==s.col[k]){
            printf("%d ",s.value[k]);
            k++;
         }else{
            printf("0 ");
         }
      }
      printf("\n");
   }
   printf("\n");
}

Sparse Transpose(Sparse a)
{
   Sparse b;
   b.ncols=a.nrows;
   b.nrows=a.ncols;
   b.nz=a.nz;
   int c[a.ncols];
   int t[a.ncols];
   int i;
   for(i=0;i<a.nz;i++)
   {
      c[i]=0;
   }
   for(i=0;i<a.nz;i++)
   {
      c[a.col[i]]=c[a.col[i]]+1;
   }
   t[0]=0;
   for(i=1;i<a.ncols;i++)
   {
      t[i]=t[i-1]+c[i-1];
   }
   for(i=0;i<a.nz;i++)
   {
      b.row[t[a.col[i]]]=a.col[i];
      b.col[t[a.col[i]]]=a.row[i];
      b.value[t[a.col[i]]]=a.value[i];
      t[a.col[i]]=t[a.col[i]]+1;
   }
   return b;
}

Sparse Multiply(Sparse a, Sparse b)
{
   Sparse product;
   if(a.nrows!=b.ncols)
   {
      product.nz=0;
      return product;
   }
   product.nrows=a.nrows;
   product.ncols=b.ncols;
   b=Transpose(b);
   int k=0,i=0,j,sum=0;
   while(i<a.nz)
   {
      int rn = a.row[i];
      j=0;
      while(j<b.nz)
      {
         int cn = b.row[j];
         
         int sa = i;
         int sb = j;
         sum = 0; 
         while(sa<a.nz && a.row[sa]==rn && b.row[sb]==cn)
         {
            if(a.col[sa]<b.col[sb])
            {
               sa++;
            }
            else if(a.col[sa]>b.col[sb])
            {
               sb++;
            }
            else
            {
               sum += a.value[sa] * b.value[sb];
               sa++;
               sb++;
            }
         }
         
         if(sum!=0)
         {
            product.row[k] = rn;
            product.col[k] = cn;
            product.value[k] = sum;
            k++;
         }
         while(j<b.nz && b.row[j]==cn)
         {
            j++;
         }
      }
      while(i<a.nz && a.row[i]==rn)
      {
            i++;
      }
   }
   product.nz = k;
   return product;

}

int main()
{
   Sparse a,b,c;
   printf("For 1st matrix:\n");
   create(&a);
   printf("For 2nd matrix:\n");
   create(&b);
   c=Multiply(a,b);
   printf("Matrix A :\n");
   printSparseMatrix(a);
   printf("Matrix B :\n");
   printSparseMatrix(b);
   printf("Product of A and B :\n");
   printSparseMatrix(c);
   return 0;
}