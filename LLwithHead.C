#include <bits/stdc++.h>
struct node
{
    int value;
    struct node *next;
};

typedef struct node node;
struct linkedList
{
    node *head;
    node *tail;
    int numberOfNodes;
    int minimum;
    int maximum;
};

typedef struct linkedList ll;
ll *insert(ll *s, int x)
{
    node *q = (node *)malloc(sizeof(node));
    q->value = x;
    q->next = s->head;
    if (s->head == NULL)
    {
        s->tail = q;
        s->minimum = x;
        s->maximum = x;
    }
    s->head = q;

    s->numberOfNodes++;
    if (x > s->maximum)
        s->maximum = x;
    else if (x < s->minimum)
        s->minimum = x;
    return s;
}

ll *insertAtEnd(ll *s, int x)
{
    node *q = (node *)malloc(sizeof(node));
    q->value = x;
    q->next = NULL;
    if (s->head == NULL)
    {
        s->head = s->tail = q;
        s->minimum = x;
        s->maximum = x;
    }
    else
    {
        s->tail->next = q;
        s->tail = q;
        if (x > s->maximum)
            s->maximum = x;
        else if (x < s->minimum)
            s->minimum = x;
    }

    s->numberOfNodes++;

    return s;
}

ll *insertAfter(ll *s, int x, int y)
{
    node *q = (node *)malloc(sizeof(node));
    q->value = x;
    if (s == NULL)
    {
        s->minimum = x;
        s->maximum = x;
        q->next = NULL;
        s->head = s->tail = q;
    }
    else
    {
        node *p = s->head;
        while (p->value != y)
        {
            if (p->next == NULL)
                break;
            p = p->next;
        }
        q->next = p->next;
        p->next = q;
        if (x > s->maximum)
            s->maximum = x;
        else if (x < s->minimum)
            s->minimum = x;
    }
    s->numberOfNodes++;

    return s;
}

node *searchNode(ll *s, int x)
{
    if (s->head == NULL)
        return s->head;
    node *q = s->head;

    while (q != NULL && q->value != x)
    {
        q = q->next;
    }

    return q;
}

int findMaximum(ll *s)
{
    if (s->head == NULL)
        return -1;
    int max = s->head->value;
    node *p = s->head;
    while (p != NULL)
    {
        if (p->value > max)
            max = p->value;
        p = p->next;
    }
    return max;
}

int findMinimum(ll *s)
{
    if (s->head == NULL)
        return -1;
    int min = s->head->value;
    node *p = s->head;
    while (p != NULL)
    {
        if (p->value < min)
            min = p->value;
        p = p->next;
    }
    return min;
}

ll *deleteNode(ll *s, int x)
{
    if (s == NULL)
        return s;

    node *q = s->head;
    node *p = NULL;

    while (q != NULL && q->value != x)
    {
        p = q;
        q = q->next;
    }

    if (q != NULL)
    {
        if (q == s->head)
        {
            s->head = q->next;
        }
        else if (q == s->tail)
        {
            s->tail = p;
            p->next = NULL;
        }
        else
        {
            p->next = q->next;
        }
        free(q);
    }
    s->numberOfNodes--;
    if (x == s->maximum)
    {
        s->maximum = findMaximum(s);
    }
    else if (x == s->minimum)
    {
        s->minimum = findMinimum(s);
    }
    return s;
}

int countNodes(ll *s)
{
    return s->numberOfNodes;
}

void displayList(ll *s)
{
    if (s->head == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    node *p = s->head;
    printf("The contents of list: ");
    while (p != NULL)
    {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int ch;
    ll *s = (ll *)malloc(sizeof(ll));
    s->head = NULL;
    s->tail = NULL;
    s->numberOfNodes = s->minimum = s->maximum = 0;
    printf("\t\t\t\t\tLinked List with head Program\n");
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
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            int x;
            printf("Enter the element to be inserted: ");
            scanf("%d", &x);
            s = insert(s, x);
            break;
        }
        case 2:
        {
            int x;
            printf("Enter the element to be inserted: ");
            scanf("%d", &x);
            s = insertAtEnd(s, x);
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
            s = insertAfter(s, x, y);
            break;
        }

        case 4:
        {
            int x;
            printf("Enter the element to be deleted: ");
            scanf("%d", &x);
            s = deleteNode(s, x);
            break;
        }

        case 5:
        {
            int x;
            printf("Enter the element to be searched: ");
            scanf("%d", &x);
            if (searchNode(s, x) != NULL)
            {
                printf("Element found\n");
            }
            else
                printf("Element not present\n");
            break;
        }

        case 6:
        {
            displayList(s);
            break;
        }

        case 7:
        {
            printf("Maximum element: %d\n", s->maximum);
            break;
        }
        case 8:
        {
            printf("Minimum element: %d\n", s->minimum);
            break;
        }
        case 9:
        {
            printf("Total number of nodes: %d\n", countNodes(s));
            break;
        }
        case 10:
            exit(0);
            break;

        default:
            break;
        }
        printf("*****************************************************\n\n\n\n");
    }
}