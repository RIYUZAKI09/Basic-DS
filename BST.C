#include<bits/stdc++.h>

struct tnode{
	int value;
	struct tnode* left;
	struct tnode* right;
};

struct tnode* insert (struct tnode* t, int k){

	if(t == NULL){
		t = (struct tnode*)malloc(sizeof(struct tnode));
		t->value = k;
		t->left = t->right = NULL;
		return t;
	}
	if(k > t->value){
		t->right = insert(t->right,k);
	}
	else if(k < t->value){
		t->left = insert(t->left,k);
	}
	return t;
}

void inorder(struct tnode* t){
	if(t== NULL){
		return;
	}
	inorder(t->left);
	printf("%d ",t->value);
	inorder(t->right);
}

void preorder(struct tnode* t){
	if(t== NULL){
		return;
	}
	printf("%d ",t->value);
	preorder(t->left);
	preorder(t->right);
}

void postorder(struct tnode* t){
	if(t== NULL){
		return;
	}
	postorder(t->left);
	postorder(t->right);
	printf("%d ",t->value);
}

void search(struct tnode* t, int k){
	if(t==NULL){
		printf("Element Not found\n");
		return;
	}
	if(k >t->value){
		search(t->right,k);
	}else if(k<t->value){
		search(t->left,k);
	}else{
		printf("Element %d found\n",k );
	}
}

int height(struct tnode* t){
	if(t == NULL){
		return 0;
	}
	return height(t->left)>height(t->right)?height(t->left)+1:height(t->right)+1;
}

struct tnode* InorderPredecessor(struct tnode* t){
	if(t == NULL){
		return NULL;
	}
	while(t!= NULL and t->right != NULL){
		t = t->right;
	}
	return t;
}

struct tnode* InorderSuccessor(struct tnode* t){
	if(t == NULL){
		return NULL;
	}
	while(t!= NULL and t->left != NULL){
		t = t->left;
	}
	return t;
}


struct tnode* Delete(struct tnode* t, int k){
	if(t == NULL){
		return NULL;
	}
	if(t->left == NULL and t->right == NULL){
		return NULL;
	}
	struct tnode* q;
	if(k>t->value){
		t->right = Delete(t->right,k);
	}else if(k<t->value){
		t->left = Delete(t->left,k);
	}else{
		if(height(t->left)>height(t->right)){
			q = InorderPredecessor(t->left);
			t->value = q->value;
			t->left = Delete(t->left,q->value);
		}else{
			q = InorderSuccessor(t->right);
			t->value = q->value;
			t->right = Delete(t->right,q->value);		
		}
	}

	return t;
}

int countnodes(struct tnode* t){
	if(t == NULL){
		return 0;
	}
	if(t->left == NULL and t->right == NULL){
		return 1;
	}

	return 1+countnodes(t->left)+countnodes(t->right);
}

int main(int argc, char const *argv[])
{
	struct tnode* t;
	t = NULL;
	
	printf("\t\t\t\t BINARY SEARCH TREE MENU DRIVEN PROGRAM.\n");
    while (1)
    {	
        printf("1. Insert\n");
        printf("2. Delete Node\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Count Total Nodes\n");
        printf("8. Height of tree\n");
        printf("9. Exit\n");
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
            t = insert(t, x);
            break;
        }
        case 2:
        {
            int x;
            printf("Enter the element to be deleted: ");
            scanf("%d", &x);
            t = Delete(t, x);
            break;
        }
        case 3:
        {
            int x;
            printf("Enter the element to be searched: ");
            scanf("%d", &x);
            search(t,x);
        }

        case 4:
        {	
        	printf("Inorder Traversal is:\n");
            inorder(t);
            printf("\n");
            break;
        }

        case 5:
        {
        	printf("Preorder Traversal is:\n");
            preorder(t);
            printf("\n");
            break;
        }
        case 6:
        {
        	printf("Postorder Traversal is:\n");
            postorder(t);
            printf("\n");
            break;
        }
        case 7:
        {
            printf("Total number of nodes: %d\n", countnodes(t));
            break;
        }
        case 8:
        {
        	printf("Height of the tree is %d\n", height(t));
        	break;
        }
        case 9:
            exit(0);
            break;

        default:
            break;
        }
        printf("*************************************************\n\n");
    }
	return 0;
}