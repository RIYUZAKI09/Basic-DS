#include<bits/stdc++.h>

struct node{
	int value;
	struct node* next;
};

struct node* insertAtStart(struct node* s,int k){
	struct node* q;
	q= (struct node*)malloc(sizeof(struct node));
	q->value = k;
	q->next = s;
	s=q;
	return s;
}

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

struct node* insertAtPos(struct node* s,int pos,int k){
	struct node* q;
	struct node* p;
	int count =0;
	q= (struct node*)malloc(sizeof(struct node));
	q->value = k;
	q->next = NULL;
	if(s==NULL){
		s=q;
	}else{
		p=s;
		while(count<pos-1){
			p = p->next;
			count++;
		}
		q->next = p->next;
		p->next = q;
	}
	return s;
}

struct node* InsertAfter(struct node* s, int k,int m){
	struct node* q;
	q = (struct node*)malloc(sizeof(struct node));
	q->value = k;
	q->next = NULL;
	if(s == NULL){
		s = q;
	}
	struct node* p;
	p = s;
	while(p->value != m){
		if(p->next == NULL){
			break;
		}
		p = p->next;
	}
	q->next = p->next;
	p->next = q;
	return s;
}

struct node* deleteAtStart(struct node* s){
	struct node* q;
	if(s==NULL){
		return NULL;
	}
	q = s;
	s= s->next;
	free(q);
	return s; 
}

struct node* deleteAtEnd(struct node* s){
	if(s == NULL or s->next == NULL){
		s = deleteAtStart(s);
		return s;
	}
	struct node* p;
	p = s;
	while(p->next->next != NULL){
		p = p->next;
	}
	free(p->next);
	p->next = NULL;
	return s;
}

struct node* deleteAtK(struct node* s, int k){
	if(s == NULL){
		return NULL;
	}
	int p =0;
	struct node* temp = s;
	if(k==0){
		s=temp->next;
		free(temp);
		return NULL;
	}

	while(p<k-1){
		p++;
		temp = temp->next;
	}

	if(temp == NULL or temp->next== NULL){
		return NULL;
	}

	struct node* toBeDeleted = temp->next;
	struct node* z = temp->next->next;
	temp->next = z;
	free(toBeDeleted);
	return s;
}

struct node* DeleteElement(struct node* s, int k){
	if(s == NULL){
		printf("List is empty.\n");
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

int main(int argc, char const *argv[])
{
	struct node* List;
	List = NULL;
	printf("\t\t\t\t LINKED LIST MENU DRIVEN PROGRAM.\n");
    while (1)
    {	
        printf("1. Insert\n");
        printf("2. Insert at End\n");
        printf("3. Insert After\n");
        printf("4. Delete Node\n");
        printf("5. Search\n");
        printf("6. Display List\n");
        printf("7. Find Maximum\n");
        printf("8. Find Minimum\n");
        printf("9. Count Total Nodes\n");
        printf("10. Exit\n");
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
            List = insertAtStart(List, x);
            break;
        }
        case 2:
        {
            int x;
            printf("Enter the element to be inserted: ");
            scanf("%d", &x);
            List = insertAtEnd(List, x);
            break;
        }
        case 3:
        {
            int x;
            printf("Enter the element to be inserted: ");
            scanf("%d", &x);
            printf("Enter the element after which element is to be inserted: ");
            int y;
            scanf("%d", &y);
            List = InsertAfter(List, x, y);
            break;
        }

        case 4:
        {
            int x;
            printf("Enter the element to be deleted: ");
            scanf("%d", &x);
            List = DeleteElement(List, x);
            break;
        }

        case 5:
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

        case 6:
        {
            printLL(List);
            break;
        }

        case 7:
        {
            printf("Maximum element: %d\n", findMax(List));
            break;
        }
        case 8:
        {
            printf("Minimum element: %d\n", findMin(List));
            break;
        }
        case 9:
        {
            printf("Total number of nodes: %d\n", countNodes(List));
            break;
        }
        case 10:
            exit(0);
            break;

        default:
            break;
        }
        printf("*************************************************\n\n\n\n");
    }
	return 0;
}