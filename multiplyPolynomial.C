#include<bits/stdc++.h>

 struct poly{
 	int coeff;
 	int exp;
 };
 
typedef struct poly polynomial;

 
 
void getPolynomial(polynomial pol[], int size){
	int i;
	for(i=0;i<size;i++){
		printf("Enter the coefficient: ");
		scanf("%d",&(pol[i].coeff));
		printf("Enter the exponent: ");
		scanf("%d",&(pol[i].exp));		
	}
}

void displayPolynomial(const polynomial p[], int size){
	int i;
	for(i=0;i<size;i++){
		if(p[i].exp > 0) 
		printf("%dx^%d + ", p[i].coeff, p[i].exp);
		else 
		printf("%d", p[i].coeff);
	}
	printf("\n");
}

int addPolynomial(const polynomial p1[], const polynomial p2[], polynomial p3[],int n1, int n2){
	int k=0;
	int i=0,j=0;
	while(i<n1 && j<n2){
		if(p1[i].exp > p2[j].exp){
			p3[k].exp=p1[i].exp;
			p3[k++].coeff=p1[i++].coeff;
			
		}
		else if(p1[i].exp < p2[j].exp){
			p3[k].exp=p2[j].exp;
			p3[k++].coeff=p2[j++].coeff;
		}
		else {
			p3[k].exp=p2[j].exp;
			p3[k++].coeff=p2[j++].coeff + p1[i++].coeff;
		}
	}	
	while (i < n1)
	{
		p3[k].exp = p1[i].exp;
		p3[k++].coeff = p1[i++].coeff;
	}
	while (j < n2)
	{
		p3[k].exp = p2[j].exp;
		p3[k++].coeff = p2[j++].coeff;
	}
	return k;
}

void getProduct(const polynomial p1, const polynomial p2[], polynomial p3[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		p3[i].coeff = p2[i].coeff * p1.coeff;
		p3[i].exp = p2[i].exp + p1.exp;
	}
}

void copy(const polynomial p1[], polynomial p2[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		p2[i].coeff = p1[i].coeff;
		p2[i].exp = p1[i].exp;
	}
}
int multiplyPolynomial(const polynomial p1[], const polynomial p2[], polynomial p3[], int n1, int n2)
{
	int i;
	int s = n2;
	for (i = 0; i < n2; i++)
	{
		p3[i].coeff = 0;
		p3[i].exp = 0;
	}

	polynomial *temp = (polynomial *)malloc(n1 * n2 * sizeof(polynomial));
	polynomial *temp1 = (polynomial *)malloc(n1 * n2 * sizeof(polynomial));
	for (i = 0; i < n1; i++)
	{
		getProduct(p1[i], p2, temp, n2);
		s = addPolynomial(p3, temp, temp1, s, n2);
		copy(temp1, p3, s);
	}
	return s;
}

int main()
{
	int n1, n2, n3;
	int k;
	polynomial *p1, *p2, *p3;
	while (1)
	{
		printf("1. Add\n");
		printf("2. Multiply\n");
		printf("Enter your choice: ");
		scanf("%d", &k);
		if (k == 1 or k == 2 )
		{
			printf("Enter the size of first polynomial: ");
			scanf("%d", &n1);
			p1 = (polynomial *)malloc(sizeof(polynomial) * n1);
			getPolynomial(p1, n1);
			printf("Enter the size of second polynomial: ");
			scanf("%d", &n2);
			p2 = (polynomial *)malloc(sizeof(polynomial) * n2);
			getPolynomial(p2, n2);

			switch (k)
			{
			case 1:
			{
				p3 = (polynomial *)malloc(sizeof(polynomial) * (n1 + n2));
				n3 = addPolynomial(p1, p2, p3, n1, n2);
				printf("Polynomial 1:\n");
				displayPolynomial(p1, n1);
				printf("Polynomial 2:\n");
				displayPolynomial(p2, n2);
				printf("Addition Polynomial:\n");
				displayPolynomial(p3, n3);
				break;
			}
			case 2:
			{
				p3 = (polynomial *)malloc(sizeof(polynomial) * (n1 * n2));
				n3 = multiplyPolynomial(p1, p2, p3, n1, n2);
				printf("Polynomial 1:\n");
				displayPolynomial(p1, n1);
				printf("Polynomial 2:\n");
				displayPolynomial(p2, n2);
				printf("Multiplication Polynomial:\n");
				displayPolynomial(p3, n3);
				break;
			}

			default:
				break;
			}

		}
		printf("*******************************************************\n");
	}
}