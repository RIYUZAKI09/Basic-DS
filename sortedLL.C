#include<bits/stdc++.h>

struct node{
	int value;
	struct node* next;
};

struct node* insertAtEnd(struct node* s, int k){
	struct node* q;
	struct node* p;
	q= (struct node*)malloc(sizeof(struct node));
	q->value = k;
	q->next = NULL;
	if(s== NULL){
		s=q;
	}else{
		p=s;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = q;
	}
	return s;
}

struct node* DeleteElement(struct node* s, int k){
	if(s == NULL){
		printf("Stack is empty.\n");
		return NULL;
	}
	struct node* q;
	q = s;
	struct node* p;
	p = NULL;
	while(q != NULL and q->value != k){
		p = q;
		q = q->next;
	}
	if(q != NULL){
		if(q == s){
			s = q->next;
		}else{
			p->next = q->next;
		}
		free(q);
	}
	if(q == NULL){
		printf("Element not found.\n");
	}
	return s;
}

void printLL(struct node* s){
	struct node* q;
	q=s;
	printf("Linked List is: \n");
	while(q != NULL){
		printf("%d -> ",q->value);
		q = q->next;
	}
	printf("NULL");
	printf("\n");
}

int searchElement(struct node* s,int k){
	if(s == NULL){
		printf("Element not found.\n");
	}
	if(s->value == k){
		return k;
	}else{
		return searchElement(s->next,k);
	}
	return -1;
}

int countNodes(struct node* s){
	int count = 0;
	struct node* q;
	q = s;
	while(q != NULL){
		count++;
		q = q->next;
	}
	return count;
}

int findMin(struct node* s){
	if(s == NULL){
		return -1;
	}
	int min = s->value;
	struct node* q;
	q = s;
	while(q != NULL){
		if(q->value<min){
			min = q->value;
		}
		q = q->next;
	}
	return min;
}

int findMax(struct node* s){
	if(s == NULL){
		return -1;
	}
	int max = s->value;
	struct node* q;
	q = s;
	while(q != NULL){
		if(q->value>max){
			max = q->value;
		}
		q = q->next;
	}
	return max;
}

void split(struct node* s, struct node** first, struct node** last){
	struct node* fast;
	struct node* slow;
	slow = s;
	fast = s->next;
	while(fast!= NULL){
		fast = fast->next;
		if(fast != NULL){
			fast = fast->next;
			slow = slow->next;
		}
	}
	*first = s;
	*last = slow->next;
	slow->next = NULL;
}

struct node* merge(struct node* a,struct node* b){
	struct node* s = NULL;

	if(a == NULL){
		return b;
	}else if(b == NULL){
		return a;
	}

	if(a->value <= b->value){
		s = a;
		s->next = merge(a->next,b);
	}else{
		s = b;
		s->next = merge(a,b->next);
	}
	return s;
}

void MergeSort(struct node** s){
	struct node* p = *s;
	struct node* a;
	struct node* b;

	if(p == NULL or p->next == NULL){
		return;
	}

	split(p,&a,&b);

	MergeSort(&a);
	MergeSort(&b);

	*s = merge(a,b);
}


int main(int argc, char const *argv[])
{
	struct node* List;
	List = NULL;
	printf("\t\t\t\tSORTED LINKED LIST MENU DRIVEN PROGRAM.\n");
    while (1)
    {	
        printf("1. Insert\n");
        printf("2. Delete Node\n");
        printf("3. Search\n");
        printf("4. Display List\n");
        printf("5. Find Maximum\n");
        printf("6. Find Minimum\n");
        printf("7. Count Total Nodes\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        int k;
        scanf("%d", &k);
        switch (k)
        {

        case 1:
        {
            int x;
            printf("Enter the element to be inserted: ");
            scanf("%d", &x);
            List = insertAtEnd(List, x);
            MergeSort(&List);
            break;
        }

        case 2:
        {
            int x;
            printf("Enter the element to be deleted: ");
            scanf("%d", &x);
            List = DeleteElement(List, x);
            MergeSort(&List);
            break;
        }

        case 3:
        {
            int x;
            printf("Enter the element to be searched: ");
            scanf("%d", &x);
            if (searchElement(List, x) != -1)
            {
                printf("Element found\n");
            }
            else
                printf("Element not present\n");
            break;
        }

        case 4:
        {
            printLL(List);
            break;
        }

        case 5:
        {
            printf("Maximum element: %d\n", findMax(List));
            break;
        }
        case 6:
        {
            printf("Minimum element: %d\n", findMin(List));
            break;
        }
        case 7:
        {
            printf("Total number of nodes: %d\n", countNodes(List));
            break;
        }
        case 8:
            exit(0);
            break;

        default:
            break;
        }
        printf("*************************************************\n\n\n\n");
    }
	return 0;
}