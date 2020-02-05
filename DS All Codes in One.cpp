#include<iostream>
using namespace std;
//Linear Search
void linear_search(int A[],int n,int search)
{
	int c=0;
	for (int i = 0; i < n; i++)
	{
		if (A[i]==search)
		{
			c=1;
			break;
		}
		else
		{
			continue;
		}
	}
	if (c==1)
	{
		cout<<"Data Found"<<endl;
	}
	else
	{
		cout<<"Data Not Found"<<endl;
	}
}

//Binary Search
void binary_search(int A[],int n,int search)
{
	int c=0;
	int f=0,l=(n-1),m;
	for (int i = 0; i < n; i++)
	{
		m=((f+l)/2);
		if (A[m]==search)
		{
			c=1;
			break;
		}
		else if (A[m]<search)
		{
			f=m+1;
		}
		else if (A[m]>search)
		{
			l=m-1;
		}
	}
	if (c==1)
	{
		cout<<"Data Found"<<endl;
	}
	else
	{
		cout<<"Data Not Found"<<endl;
	}
}

//Bubble Sort
void bubble_sort(int A[],int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (n-i-1); j++)
		{
			if (A[j]>A[j+1])
			{
				int temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
	cout<<"The Sorted Array: ";
	for (int i = 0; i < n; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

//Insertion Sort
void insertion_sort(int A[],int n)
{
	for (int i = 0; i < n; i++)
	{
		int temp=A[i];
		int j=i-1;
		while (j>=0 && A[j]>temp)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=temp;
	}
	cout<<"The Sorted Array: ";
	for (int i = 0; i < n; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

//Selection Sort
void selection_sort(int A[],int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = (i+1); j < n; j++)
		{

			if (A[i]>A[j])
			{
				int temp=A[i];
				A[i]=A[j];
				A[j]=temp;
			}
		}
	}
	cout<<"The Sorted Array: ";
	for (int i = 0; i < n; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

//Array as arguments
void printarray1(int *p,int s)
{
	cout<<"Array Is: ";
	for (int i = 0; i < s; i++)
	{
		cout<<*(p+i)<<" ";
	}
	cout<<endl;
}

void printarray2(int A[], int s)
{
	for (int i = 0; i < s; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

//Representation of an array by pointer
void array_by_point(int A[],int n)
{
	int s;
	int *p;
	cout<<"Enter The Index Pointer: ";
	cin>>s;
	p=&A[s];
	cout<<"Entered Array Is: ";
	for (int i = 0; i < n; i++)
	{
		cout<<*(p+i)<<" ";
	}
	cout<<endl;
}

//Logarithms
void logarithm(int n,int b)
{
	int c=0,s=1;
	for (int i = 0; i < n; i++)
	{
		s=s*b;
		c++;
		if (s>=n)
		{
			break;
		}
	}
	cout<<"Logarithm Value Is: "<<c<<endl;
}

//Factorials
void factorial(int n)
{
	int s=1;
	for (int i = 1; i <= n; i++)
	{
		s=s*i;
	}
	cout<<"Factorial Is: "<<s<<endl;
}

//Fibonacci numbers implementation
void fibonacci(int A[],int n)
{
	for (int i = 2; i < n; i++)
	{
		A[i]=A[i-1]+A[i-2];
	}
	cout<<"Fibonacci Series Is: ";
	for (int i = 0; i < n; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

//Singly Linked List
struct node
{
	int data;
	node *nextnode;
};

node *head;

node *getnewnode1(int x)
{
	node *newnode=new node();
	newnode->data=x;
	newnode->nextnode=NULL;
	return newnode;
}

void insertathead(int x)
{
	node *newnode=getnewnode1(x);
	newnode->nextnode=head;
	head=newnode;
}

void insertattail(int x)
{
	node *newnode=getnewnode1(x);
	if (head==NULL)
	{
		head=newnode;
	}
	node *tempnode=head;
	while (tempnode->nextnode!=NULL)
	{
		tempnode=tempnode->nextnode;
	}
	tempnode->nextnode=newnode;
}

void insertatanypos(int x,int pos)
{
	node *newnode=getnewnode1(x);
	node *tempnode=head;
	for (int i = 1; i < pos-1; i++)
	{
		tempnode=tempnode->nextnode;
	}
	newnode->nextnode=tempnode->nextnode;
	tempnode->nextnode=newnode;
}

void traverse()
{
	node *tempnode=head;
	while (tempnode!=NULL)
	{
		cout<<tempnode->data<<"----->";
		tempnode=tempnode->nextnode;
	}
}

void delhead()
{
	node *tempnode=head;
	head=tempnode->nextnode;
	delete tempnode;
}

void deltail()
{
	node *tempnode=head;
	node *tempnode1=head;
	int i=0;
	while (tempnode->nextnode!=NULL)
	{
		tempnode=tempnode->nextnode;
		i++;
	}
	for (int j = 1; j < i; j++)
	{
		tempnode1=tempnode1->nextnode;
	}
	tempnode1->nextnode=NULL;
	delete tempnode;
}

void delfromanypos(int pos)
{
	node *tempnode=head;
	node *tempnode1=head;
	int c=0;
	for (int i = 1; i < pos; i++)
	{
		tempnode=tempnode->nextnode;
		c++;
	}
	for (int j = 1; j < c; j++)
	{
		tempnode1=tempnode1->nextnode;
	}
	tempnode1->nextnode=tempnode->nextnode;
	delete tempnode;
}

void search_s(int item)
{
	node *tempnode=head;
	int c=0,i=0;
	while (tempnode!=NULL)
	{
		i++;
		if (tempnode->data==item)
		{
			c=1;
			break;
		}
		else
		{
			tempnode=tempnode->nextnode;
		}	
	}
	if (c==1)
	{
		cout<<"Data Found At Node No. "<<i<<endl;
	}
	else
	{
		cout<<"Data Not Found"<<endl;
	}
}

//push/pop into/from stack
int S[100];
int n1=5;
int top=-1;
void s_push(int value)
{
	if (top==(n1-1))
	{
		cout<<"Stack Overflow"<<endl;
	}
	else
	{
		top++;
		S[top]=value;
	}
}

void s_pop()
{
	if (top==-1)
	{
		cout<<"Stack Underflow"<<endl;
	}
	else
	{
		S[top]=NULL;
		top--;
	}
}

void s_print()
{
	if (top==-1)
	{
		cout<<"Array Is Empty"<<endl;
	}
	else
	{
		cout<<"Array Is: ";
		for (int i = 0; i <=top; i++)
		{
			cout<<S[i]<<"\t";
		}
		cout<<endl<<endl;
	}
	cout<<"\n\n";
}

//push/pop into/from queue
int Q[100];
int n2=5;
int front1=-1;
int rear1=-1;
void q_push(int value)
{
	if (rear1==(n2-1))
	{
		cout<<"Queue Overflow"<<endl;
	}
	else
	{
		front1=0;
		rear1++;
		Q[rear1]=value;
	}
}

void q_pop()
{
	if (front1==-1 || front1>(n2-1))
	{
		cout<<"Queue Underflow"<<endl;
	}
	else
	{
		Q[front1]=NULL;
		front1++;
	}
}

void q_print()
{
	if (front1==-1 || front1>(n2-1))
	{
		cout<<"Array Is Empty"<<endl;
	}
	else
	{
		cout<<"Array Is: ";
		for (int i = front1; i <=rear1; i++)
		{
			cout<<Q[i]<<"\t";
		}
		cout<<endl<<endl;
	}
	cout<<"\n\n";
}

//push/pop into/from circular queue
int CQ[5],front =-1,rear=-1;
bool empty()
{
	if (front==-1 && rear==-1)
		return true;
	else
		return false;
}

void enqueue(int value)
{
	if((rear+1)%5 == front)
		cout<<"Circular Queue Is Full\n";
	else
	{
		if(front==-1)
			front=0;
		rear=(rear+1)%5;
		CQ[rear]=value;
	}
}

void dequeue()
{
	if(empty())
		cout<<"Circular Queue Is Empty\n";
	else if(front==rear)
		front=rear=-1;
	else
		front=(front+1)%5;
}

void print_queue()
{
	if(empty())
		cout<<"Circular Queue Is Empty\n";
	else
	{
		int i;
		if (front<=rear)
		{
			cout<<"Circular Queue Is: ";
			for (int i = front; i <=rear; i++)
				cout<<CQ[i]<<"\t";
		}
		else
		{
			i=front;
			cout<<"Circular Queue Is: ";
			while (i<5)
			{
				cout<<CQ[i]<<"\t";
				i++;
			}
			i=0;
			cout<<"Circular Queue Is: ";
			while (i<=rear)
			{
				cout<<CQ[i]<<"\t";
				i++;
			}
		}
	}
}

//BST
struct bst
{
	int data;
	bst *left;
	bst *right;
};

bst *root;

bst *getnewnode3(int x)
{
	bst *newnode=new bst();
	newnode->data=x;
	newnode->left=newnode->right=NULL;
	return newnode;
}

bst *insert(bst *root,int x)
{
	if (root==NULL)
	{
		root=getnewnode3(x);
	}
	else if (x<=root->data)
	{
		root->left=insert(root->left,x);
	}
	else
	{
		root->right=insert(root->right,x);
	}
	return root;
}

void search_b(int item)
{
	int c=0;
	bst *temp=root;
	while (temp!=NULL)
	{
		if (temp->data==item)
		{
			c=1;
			break;
		}
		else
		{
			if (item<=temp->data)
					temp=temp->left;
		
			else
				temp=temp->right;                            
		}
	}
	if (c==1)
	{
		cout<<item<<" Is Found in Tree"<<endl;
	}
	else
	{
		cout<<item<<" Is Not Found in Tree"<<endl;
	}
}

void inorder(bst *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<"  ";
        inorder(root->right);
    }
}

void preorder(bst *root)
{
	if (root!=NULL)
	{
		cout<<root->data<<"  ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(bst *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<"  ";
	}
}

//infix to postfix
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};
 
struct Stack* createStack( unsigned capacity )
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
 
    if (!stack) 
        return NULL;
 
    stack->top = -1;
    stack->capacity = capacity;
 
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
 
    if (!stack->array)
        return NULL;
    return stack;
}
int isEmpty(struct Stack* stack)
{
    return stack->top == -1 ;
}
char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}
char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
void push(struct Stack* stack, char op)
{
    stack->array[++stack->top] = op;
}
  
int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
 

int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}
 
 
int infixToPostfix(char* exp)
{
    int i, k;
 
    struct Stack* stack = createStack(sizeof(exp)/sizeof(exp[0]));
    if(!stack) 
        return -1 ;
 
    for (i = 0, k = -1; exp[i]; ++i)
    {
        if (isOperand(exp[i]))
            exp[++k] = exp[i];
        else if (exp[i] == '(')
            push(stack, exp[i]);
        else if (exp[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1;              
            else
                pop(stack);
        }
        else 
        {
            while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
 
    }
    while (!isEmpty(stack))
        exp[++k] = pop(stack );
 
    exp[++k] = '\0';
	cout<<exp;
}

//heap  sort
void heapify(int A[],int n,int i)
{
	int la=i;
	int l=2*i;
	int r=2*i+1;
	if (l<n && A[l]>A[la])
	{
		la=l;
	}
	if (r<n && A[r]>A[la])
	{
		la=r;
	}
	if (la!=i)
	{
		swap(A[i],A[la]);
		heapify(A,n,la);
	}
}

void heapsort(int A[],int n)
{
	for (int i =(n/2)-1; i>=0; i--)
	{
		heapify(A,n,i);
	}
	for (int i = (n-1); i>=0; i--)
	{
		swap(A[0],A[i]);
		heapify(A,i,0);
	}
}

//Doubly Linked List
struct node_d
{
	int value;
	node_d *prev;
	node_d *next;
};
node_d *head_d,*tail,*temp,*temp1,*temp2;

node_d *getnewnode_d(int x)
{
	node_d *newnode_d=new node_d();
	newnode_d->value=x;
	newnode_d->prev=NULL;
	newnode_d->next=NULL;
	return newnode_d;
}

void traverse_d()
{
	temp=head_d;
	while (temp!=NULL)
	{
		cout<<temp->value<<"<----->";
		temp=temp->next;
	}
	cout<<endl;
}

void insertathead_d(int x)
{
	node_d *newnode_d=getnewnode_d(x);
	if (head_d==NULL)
	{
		head_d=newnode_d;
		tail=newnode_d;
	}
	else
	{
		head_d->prev=newnode_d;
		newnode_d->next=head_d;
		head_d=newnode_d;
	}
}

void insertattail_d(int x)
{
	node_d *newnode_d=getnewnode_d(x);
	if (head_d==NULL)
	{
		head_d=newnode_d;
		tail=newnode_d;
	}
	else
	{
		temp=head_d;
		while (temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode_d;
		newnode_d->prev=temp;
		tail=newnode_d;
	}
}

void insertatanypos_d(int x,int pos)
{
	node_d *newnode_d=getnewnode_d(x);
	temp=head_d; 
	for (int i = 1; i < pos-1; i++)
	{
		temp = temp->next;
	}
	newnode_d->next=temp->next;
	newnode_d->prev=temp;
	temp1=temp->next;
	temp1->prev=newnode_d;
	temp->next=newnode_d;

}

void delhead_d()
{
	temp=head_d;
	head_d=temp->next;
	head_d->prev=NULL;
	delete temp;
}

void deltail_d()
{
	temp=head_d;
	temp1=head_d;
	int i=0;
	while (temp->next!=NULL)
	{
		temp=temp->next;
		i++;
	}
	for (int j = 1; j < i; j++)
	{
		temp1=temp1->next;
	}
	temp1->next=NULL;
	delete temp;
}

void delfromanypos_d(int pos)
{
	temp=head_d;
	for (int i = 1; i < pos; i++)
	{
		temp=temp->next;
	}
	temp1=temp->prev;
	temp2=temp->next;
	temp1->next=temp2;
	temp2->prev=temp1;
	delete temp;
}
void search_d(int item)
{
	temp=head_d;
	int cn=0,in=0;
	while (temp!=NULL)
	{
		in++;
		if (temp->value==item)
		{
			cn=1;
			break;
		}
		else
		{
			temp=temp->next;
		}	
	}
	if (cn==1)
	{
		cout<<"Data Found At Node No. "<<in<<endl;
	}
	else
	{
		cout<<"Data Not Found"<<endl;
	}
}

//postfix evaluation
int top_p=-1,s[50];       
void push(int elem)
{                      
    s[++top_p]=elem;
}
int pop()
{                    
	return (s[top_p--]);
} 
void postfix_e(char pofx[50])
{                         
	char ch;
    int i=0,op1,op2,q;
	while( (ch=pofx[i++]) != '\0')
    {
        if(isdigit(ch)) push(ch-'0'); 
        else
        {        
            op2=pop();
            op1=pop();
            switch(ch)
			{
				case '+':push(op1+op2);break;
			    case '-':push(op1-op2);break;
                case '*':push(op1*op2);break;
                case '/':push(op1/op2);break;
            }
        }
    }
    cout<<"\n\nThe Result After Evaluation: "<<s[top_p]<<endl;
}

//bfs
int graph[100][100],label[100];
int queue_bfs[100], front_bfs, rear_bfs;
int vertices, edges;

void initialize_queue_bfs()
{
	front_bfs = 0;
	rear_bfs = 0;
}

void enqueue_bfs(int node_bfs)
{
	queue_bfs[rear_bfs++] = node_bfs;
}

int dequeue_bfs()
{
	return queue_bfs[front_bfs++];
}

bool queue_bfs_empty()
{
	if(front_bfs == rear_bfs)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void BFS(int startnode_bfs, int vertices)
{
	for(int i=0; i<vertices; i++)
	{
		label[i] = -1;
	}
	enqueue_bfs(startnode_bfs);
	label[startnode_bfs] = 0;
	while(!queue_bfs_empty())	
	{
		int vn = dequeue_bfs();
		cout<< vn<< " ";   
		for(int v=0; v<vertices; v++)	
		{
			if(graph[vn][v] == 1)	
			{
				if(label[v] == -1)	
				{
					label[v] = 0;	
					enqueue_bfs(v);			
				}
			}
		}
		label[vn] = 1;	
	}
	cout<<endl;
}

int main()
{
	cout<<"\n\n\n\n\t\t\t\t   WELCOME"<<endl<<endl<<endl<<endl;
	cout<<"\n\n\n\t\t\t   Course: DATA STRUCTURE\n\n\t\t\t\tSECTION:'G'\n\n\n\n";

	cout<<"\t\t\t\tSUBMITTED TO\n\n\t\t\tCOURSE TEACHER: MD. MANZURUL HASAN";
	cout<<"\n\n   ASSISTANT PROFESSOR AT FACULTY OF SCIENCE & INFORMATION TECHNOLOGY(FSIT)";
	cout<<"\n\n\t\tAMERICAN INTERNATIONAL UNIVERSITY-BANGLADESH(AIUB)"<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\tSUBMITTED BY\n\n\t\t   NAME: ADNAN, KHANDAKAR ANIM HASSAN";
	cout<<"\n\n\t\t\t    ID: 17-33956-1";
	cout<<"\n\n\t\tDEPARTMENT: COMPUTER SCIENCE & ENGINEERING(CSE)\n\n\n\n";
	char e;
	cout<<"Enter 'S' For Start Or 'C' For Close\n\nEnter Your Choice: ";
	cin>>e;
	if (e=='S' || e=='s')
	{
		system("cls");
		goto top;
	}
	else if (e=='C' || e=='c')
	{
		goto bottom;
	}
	else
	{
		goto wrong;
	}
top:
	cout<<"Enter [1] For Linear Search\n"<<endl;
	cout<<"Enter [2] For Binary Search\n"<<endl;
	cout<<"Enter [3] For Bubble Sort\n"<<endl;
	cout<<"Enter [4] For Insertion Sort\n"<<endl;
	cout<<"Enter [5] For Selection Sort\n"<<endl;
	cout<<"Enter [6] For Array By Pointer\n"<<endl;
	cout<<"Enter [7] For Array As Argument\n"<<endl;
	cout<<"Enter [8] For Logarithm\n"<<endl;
	cout<<"Enter [9] For Factorial\n"<<endl;
	cout<<"Enter [10] For Fibonaccii\n"<<endl;
	cout<<"Enter [11] For Singly Linked List\n"<<endl;
	cout<<"Enter [12] For PUSH/POP Into/From Stack\n"<<endl;
	cout<<"Enter [13] For PUSH/POP Into/From Queue\n"<<endl;
	cout<<"Enter [14] For PUSH/POP Into/From Circular Queue\n"<<endl;
	cout<<"Enter [15] For Binary Search Tree (BST)\n"<<endl;
	cout<<"Enter [16] For Infix Expression To Postfix Expression\n"<<endl;
	cout<<"Enter [17] For Heap Sort\n"<<endl;
	cout<<"Enter [18] For Doubly Linked List\n"<<endl;
	cout<<"Enter [19] For Postfix Expression Evaluation\n"<<endl;
	cout<<"Enter [20] For Breadth First Search(BFS)\n"<<endl;
	cout<<"Enter [21] For Exit"<<endl;
	cout<<endl<<endl;
	int choice1;
	cout<<"Enter Your Choice: ";
	cin>>choice1;
	switch (choice1)
	{
		case 1:
				//linear search
				int n1;
				cout<<"\n\nEnter The Arrray Size(Highest Range-100): ";
				cin>>n1;
				int B[100],search1;
				cout<<"Enter The Array: ";
				for (int i = 0; i < n1; i++)
				{
					cin>>B[i];
				}
				cout<<"Enter The Search Item: ";
				cin>>search1;
				linear_search(B,n1,search1);
				char c1;
				cout<<"\n\n\nDo You Want to Continue??? Enter 'Y' For Yes Or 'N' for No"<<endl;
				cout<<"Enter Your Choice: ";
				cin>>c1;
				cout<<"\n\n\n";
				if (c1=='Y'||c1=='y')
				{
					system("cls");
					goto top;
				}
				else
				{
					goto bottom;
				}
				
		case 2:
				// binary search
				int n2;
				cout<<"\n\nEnter The Arrray Size(Highest Range-100): ";
				cin>>n2;
				int C[100],search2;
				cout<<"Enter The Array: ";
				for (int i = 0; i < n2; i++)
				{
					cin>>C[i];
				}
				cout<<"Enter The Search Item: ";
				cin>>search2;
				binary_search(C,n2,search2);
				char c2;
				cout<<"\n\n\nDo You Want to Continue??? Enter 'Y' For Yes Or 'N' for No"<<endl;
				cout<<"Enter Your Choice: ";
				cin>>c2;
				cout<<"\n\n\n";
				if (c2=='Y'||c2=='y')
				{
					system("cls");
					goto top;
				}
				else
				{
					goto bottom;
				}
		
		case 3:
				//bubble sort
				int n3;
				cout<<"\n\nEnter The Arrray Size(Highest Range-100): ";
				cin>>n3;
				int D[100];
				cout<<"Enter The Array: ";
				for (int i = 0; i < n3; i++)
				{
					cin>>D[i];
				}
				bubble_sort(D,n3);
				char c3;
				cout<<"\n\n\nDo You Want to Continue??? Enter 'Y' For Yes Or 'N' for No"<<endl;
				cout<<"Enter Your Choice: ";
				cin>>c3;
				cout<<"\n\n\n";
				if (c3=='Y'||c3=='y')
				{
					system("cls");
					goto top;
				}
				else
				{
					goto bottom;
				}

		case 4:
				// insertion sort
				int n4;
				cout<<"\n\nEnter The Arrray Size(Highest Range-100): ";
				cin>>n4;
				int E[100];
				cout<<"Enter The Array: ";
				for (int i = 0; i < n4; i++)
				{
					cin>>E[i];
				}
				insertion_sort(E,n4);
				char c4;
				cout<<"\n\n\nDo You Want to Continue??? Enter 'Y' For Yes Or 'N' for No"<<endl;
				cout<<"Enter Your Choice: ";
				cin>>c4;
				cout<<"\n\n\n";
				if (c4=='Y'||c4=='y')
				{
					system("cls");
					goto top;
				}
				else
				{
					goto bottom;
				}

		case 5:
				//selection sort
				int n5;
				cout<<"\n\nEnter The Arrray Size(Highest Range-100): ";
				cin>>n5;
				int F[100];
				cout<<"Enter The Array: ";
				for (int i = 0; i < n5; i++)
				{
					cin>>F[i];
				}
				selection_sort(F,n5);
				char c5;
				cout<<"\n\n\nDo You Want to Continue??? Enter 'Y' For Yes Or 'N' for No"<<endl;
				cout<<"Enter Your Choice: ";
				cin>>c5;
				cout<<"\n\n\n";
				if (c5=='Y'||c5=='y')
				{
					system("cls");
					goto top;
				}
				else
				{
					goto bottom;
				}

		case 6:
				//arry by pointer
				int n6;
				cout<<"\n\nEnter The Arrray Size(Highest Range-100): ";
				cin>>n6;
				int G[100];
				cout<<"Enter The Array: ";
				for (int i = 0; i < n6; i++)
				{
					cin>>G[i];
				}
				array_by_point(G,n6);
				char c6;
				cout<<"\n\n\nDo You Want to Continue??? Enter 'Y' For Yes Or 'N' for No"<<endl;
				cout<<"Enter Your Choice: ";
				cin>>c6;
				cout<<"\n\n\n";
				if (c6=='Y'||c6=='y')
				{
					system("cls");
					goto top;
				}
				else
				{
					goto bottom;
				}

		case 7:
				//array as argument
				cout<<"\n\nEnter '1' For By Pointer"<<endl;
				cout<<"Enter '2' For By Array"<<endl;
				cout<<endl<<endl;
				int choice2;
				cout<<"Enter Your Choice: ";
				cin>>choice2;
				switch (choice2)
				{
					case 1:
							//by pointer
							int n7;
							cout<<"\n\nEnter The Arrray Size(Highest Range-100): ";
							cin>>n7;
							int H[100];
							cout<<"Enter The Array: ";
							for (int i = 0; i < n7; i++)
							{
								cin>>H[i];
							}
							cout<<"Entered Array Is: ";
							printarray1(H,n7);
							break;


					case 2:
							//by array
							int n8;
							cout<<"\n\nEnter The Arrray Size(Highest Range-100): ";
							cin>>n8;
							int I[100];
							cout<<"Enter The Array: ";
							for (int i = 0; i < n8; i++)
							{
								cin>>I[i];
							}
							cout<<"Entered Array Is: ";
							printarray2(I,n8);
							break;
				}
				char c7;
				cout<<"\n\n\nDo You Want to Continue??? Enter 'Y' For Yes Or 'N' for No"<<endl;
				cout<<"Enter Your Choice: ";
				cin>>c7 ;
				cout<<"\n\n\n";
				if (c7=='Y'||c7=='y')
				{
					system("cls");
					goto top;
				}
				else
				{
					goto bottom;
				}
		case 8:
				//logarithm
				int n9,b;
				cout<<"\n\nEnter The Number: ";
				cin>>n9;
				cout<<"Enter The Base: ";
				cin>>b;
				logarithm(n9,b);
				char c8;
				cout<<"\n\n\nDo You Want to Continue??? Enter 'Y' For Yes Or 'N' for No"<<endl;
				cout<<"Enter Your Choice: ";
				cin>>c8;
				cout<<"\n\n\n";
				if (c8=='Y'||c8=='y')
				{
					system("cls");
					goto top;
				}
				else
				{
					goto bottom;
				}

		case 9:
				//factorial
				int n10;
				cout<<"\n\nEnter The Number To Get Factorial: ";
				cin>>n10;
				factorial(n10);
				char c9;
				cout<<"\n\n\nDo You Want to Continue??? Enter 'Y' For Yes Or 'N' for No"<<endl;
				cout<<"Enter Your Choice: ";
				cin>>c9;
				cout<<"\n\n\n";
				if (c9=='Y'||c9=='y')
				{
					system("cls");
					goto top;
				}
				else
				{
					goto bottom;
				}

		case 10:
				//fibonaccii
				int n11,J[100];
				cout<<"\n\nEnter The First Two Terms: ";
				cin>>J[0]>>J[1];
				cout<<"Enter The Serial Of Last Term Of Fibonacci Series(Highest Range-100): ";
				cin>>n11;
				fibonacci(J,n11);
				char c10;
				cout<<"\n\n\nDo You Want to Continue??? Enter 'Y' For Yes Or 'N' for No"<<endl;
				cout<<"Enter Your Choice: ";
				cin>>c10;
				cout<<"\n\n\n";
				if (c10=='Y'||c10=='y')
				{
					system("cls");
					goto top;
				}
				else
				{
					goto bottom;
				}

		case 11:
				//singly linked list
				int x1,n12;
				cout<<"\n\nEnter Total No. Of Nodes What Do You Want To Insert At Head: ";
				cin>>n12;
				for (int i = 0; i < n12; i++)
				{
					cout<<"Enter The Data Of Node: ";
					cin>>x1;
					insertathead(x1);
				}
				cout<<"Data Entered & The Linked List Is: ";
				traverse();
				cout<<"\n\n\n";
				cout<<"Enter Total No. Of Nodes What Do You Want To Insert At Tail: ";
				cin>>n12;
				for (int i = 0; i < n12; i++)
				{
					cout<<"Enter The Data Of Node: ";
					cin>>x1;
					insertattail(x1);
				}
				cout<<"Data Entered & The Linked List Is: ";
				traverse();
				cout<<"\n\n\n";
				int x2,m1;
				cout<<"Enter The Data To Insert At Any Position: ";
				cin>>x2;
				cout<<"Enter The Position: ";
				cin>>m1;
				insertatanypos(x2,m1);
				cout<<"Data Entered & The Linked List Is: ";
				traverse();
				cout<<"\n\n\n";
				delhead();
				cout<<"Head Is Deleted & The Linked List Is: ";
				traverse();
				cout<<"\n\n\n";
				deltail();
				cout<<"Tail Is Deleted & The Linked List Is: ";
				traverse();
				cout<<"\n\n\n";
				int m2;
				cout<<"Enter The Position To Delete That's Position Node: ";
				cin>>m2;
				delfromanypos(m2);
				cout<<"'"<<m2<<"'"<<" No Position Data Is Deleted & The Linked List Is: ";
				traverse();
				cout<<"\n\n\n";
				int x3;
				cout<<"Enter The Search Item: ";
				cin>>x3;
				search_s(x3);
				cout<<"\n\n\n";
				char c11;
				cout<<"\n\n\nDo You Want to Continue??? Enter 'Y' For Yes Or 'N' for No"<<endl;
				cout<<"Enter Your Choice: ";
				cin>>c11;
				cout<<"\n\n\n";
				if (c11=='Y'||c11=='y')
				{
					system("cls");
					goto top;
				}
				else
				{
					goto bottom;
				}

		case 12:
				//push/pop into/from stack
				cout<<"\n\n#Array size is defined by 5\n\n#Push value 1 to 5\n\n#Push 6 for check 'Overflow'\n\n#Pop value 5 to 1 (LIFO)\n\n# Other one pop for check 'Underflow'\n\n";
				cout<<"##### Push Start #####\n\n";
				s_push(1);
				s_print();
				s_push(2);
				s_print();
				s_push(3);
				s_print();
				s_push(4);
				s_print();
				s_push(5);
				s_print();
				s_push(6);
				s_print();
				cout<<"\n\n##### Pop Start #####\n\n";
				s_pop();
				s_print();
				s_pop();
				s_print();
				s_pop();
				s_print();
				s_pop();
				s_print();
				s_pop();
				s_print();
				s_pop();
				s_print();	
				char c12;
				cout<<"\n\n\nDo You Want to Continue??? Enter 'Y' For Yes Or 'N' for No"<<endl;
				cout<<"Enter Your Choice: ";
				cin>>c12;
				cout<<"\n\n\n";
				if (c12=='Y'||c12=='y')
				{
					system("cls");
					goto top;
				}
				else
				{
					goto bottom;
				}

		case 13:
				//push/pop into/from queue
				cout<<"\n\n#Array size is defined by 5\n\n#push value 1 to 5\n\n#push 6 for check 'Overflow'\n\n#pop value 1 to 5 (FIFO)\n\n# Other one pop for check 'Underflow'\n\n";
				cout<<"##### Push Start #####\n\n";
				q_push(1);
				q_print();
				q_push(2);
				q_print();
				q_push(3);
				q_print();
				q_push(4);
				q_print();
				q_push(5);
				q_print();
				q_push(6);
				q_print();
				cout<<"\n\n##### Pop Start #####\n\n";
				q_pop();
				q_print();
				q_pop();
				q_print();
				q_pop();
				q_print();
				q_pop();
				q_print();
				q_pop();
				q_print();
				q_pop();
				q_print();
				char c13;
				cout<<"\n\n\nDo You Want to Continue??? Enter 'Y' For Yes Or 'N' for No"<<endl;
				cout<<"Enter Your Choice: ";
				cin>>c13;
				cout<<"\n\n\n";
				if (c13=='Y'||c13=='y')
				{
					system("cls");
					goto top;
				}
				else
				{
					goto bottom;
				}

		case 14:
				//push/pop into/from ciecular queue
				cout<<"\n\n#Array size is defined by 5\n\n#push value 1 to 5\n\n#push 6 for check 'Overflow'\n\n#pop value 1 to 5\n\n# Other one pop for check 'Underflow'\n\n";
				cout<<"##### Enqueue Start #####\n\n";
				enqueue(1);
				print_queue();
				cout<<endl<<endl;
				enqueue(2);
				print_queue();
				cout<<endl<<endl;
				enqueue(3);
				print_queue();
				cout<<endl<<endl;
				enqueue(4);
				print_queue();
				cout<<endl<<endl;
				enqueue(5);
				print_queue();
				cout<<endl<<endl;
				enqueue(6);
				print_queue();
				cout<<endl<<endl;
				cout<<"\n\n##### Dequeue Start #####\n\n";
				dequeue();
				print_queue();
				cout<<endl<<endl;
				dequeue();
				print_queue();
				cout<<endl<<endl;
				dequeue();
				print_queue();
				cout<<endl<<endl;
				dequeue();
				print_queue();
				cout<<endl<<endl;
				dequeue();
				print_queue();
				cout<<endl<<endl;
				dequeue();
				print_queue();
				cout<<endl<<endl;
				char c14;
				cout<<"\n\n\nDo You Want to Continue??? Enter 'Y' For Yes Or 'N' for No"<<endl;
				cout<<"Enter Your Choice: ";
				cin>>c14;
				cout<<"\n\n\n";
				if (c14=='Y'||c14=='y')
				{
					system("cls");
					goto top;
				}
				else
				{
					goto bottom;
				}

		case 15:
				//BST
				root=NULL;
				int item, n13;
				cout<<"Enter The No of Nodes: ";
				cin>>n13;
				for (int i = 0; i < n13; i++)
				{
					cout<<"Enter The Value of Node - "<<i+1<<": ";
					cin>>item;
					root=insert(root,item);
				}
				cout<<endl<<endl<<"In Order: ";
				inorder(root);
				cout<<endl<<endl;
				cout<<"Pre Order: ";
				preorder(root);
				cout<<endl<<endl;
				cout<<"Post Order: ";
				postorder(root);
				cout<<endl<<endl;
				int i;
				cout<<"Enter The Search Item: ";
				cin>>i;
				cout<<endl;
				search_b(i);
				cout<<endl<<endl;
				char c15;
				cout<<"\n\n\nDo You Want to Continue??? Enter 'Y' For Yes Or 'N' for No"<<endl;
				cout<<"Enter Your Choice: ";
				cin>>c15;
				cout<<"\n\n\n";
				if (c15=='Y'||c15=='y')
				{
					system("cls");
					goto top;
				}
				else
				{
					goto bottom;
				}

		case 16:
			{
				//infix to postfix
				int v;
				char exp1[] = "((A+B)*D)^(E-F))";
				cout<<"\n\nInput Infix Expression Is: ";
				v=(sizeof(exp1)/sizeof(exp1[0]));
				for (int i = 0; i < v; i++)
				{
					cout<<exp1[i];
				}
				cout<<"\n\nThe Postfix Expression Is: ";
				infixToPostfix(exp1);
			}
				cout<<endl<<endl;
				char c16;
				cout<<"\n\n\nDo You Want to Continue??? Enter 'Y' For Yes Or 'N' for No"<<endl;
				cout<<"Enter Your Choice: ";
				cin>>c16;
				cout<<"\n\n\n";
				if (c16=='Y'||c16=='y')
				{
					system("cls");
					goto top;
				}
				else
				{
					goto bottom;
				}

		case 17:
				//heap sort
				int n14;
				cout<<"\n\nEnter The Arrray Size(Highest Range-100): ";
				cin>>n14;
				int K[100];
				cout<<"Enter The Array: ";
				for (int i = 0; i < n14; i++)
				{
					cin>>K[i];
				}
				heapsort(K,n14);
				cout<<"Sorted Array Is: ";
				for (int i = 0; i < n14; i++)
				{
					cout<<K[i]<<" ";
				}
				cout<<endl<<endl;
				char c17;
				cout<<"\n\n\nDo You Want to Continue??? Enter 'Y' For Yes Or 'N' for No"<<endl;
				cout<<"Enter Your Choice: ";
				cin>>c17;
				cout<<"\n\n\n";
				if (c17=='Y'||c17=='y')
				{
					system("cls");
					goto top;
				}
				else
				{
					goto bottom;
				}

		case 18:
				//Doubly Linked List
				int x4,n15;
				cout<<"\n\nEnter Total No. Of Nodes What Do You Want To Insert At Head: ";
				cin>>n15;
				for (int i = 0; i < n15; i++)
				{
					cout<<"Enter The Data Of Node: ";
					cin>>x4;
					insertathead_d(x4);
				}
				cout<<"Data Entered & The Linked List Is: ";
				traverse_d();
				cout<<"\n\n\n";
				cout<<"Enter Total No. Of Nodes What Do You Want To Insert At Tail: ";
				cin>>n15;
				for (int i = 0; i < n15; i++)
				{
					cout<<"Enter The Data Of Node: ";
					cin>>x4;
					insertattail_d(x4);
				}
				cout<<"Data Entered & The Linked List Is: ";
				traverse_d();
				cout<<"\n\n\n";
				int x5,m3;
				cout<<"Enter The 'Data' To Insert At Any Position: ";
				cin>>x5;
				cout<<"Enter The Position: ";
				cin>>m3;
				insertatanypos_d(x5,m3);
				cout<<"Data Entered & The Linked List Is: ";
				traverse_d();
				cout<<"\n\n\n";
				delhead_d();
				cout<<"Head Is Deleted & The Linked List Is: ";
				traverse_d();
				cout<<"\n\n\n";
				deltail_d();
				cout<<"Tail Is Deleted & The Linked List Is: ";
				traverse_d();
				cout<<"\n\n\n";
				int m4;
				cout<<"Enter The Position To Delete That's Position Node: ";
				cin>>m4;
				delfromanypos_d(m4);
				cout<<"'"<<m4<<"'"<<" No Position Data Is Deleted & The Linked List Is: ";
				traverse_d();
				cout<<"\n\n\n";
				int x6;
				cout<<"Enter The Search Item: ";
				cin>>x6;
				search_d(x6);
				cout<<endl<<endl;
				char c18;
				cout<<"\n\n\nDo You Want to Continue??? Enter 'Y' For Yes Or 'N' for No"<<endl;
				cout<<"Enter Your Choice: ";
				cin>>c18;
				cout<<"\n\n\n";
				if (c18=='Y'||c18=='y')
				{
					system("cls");
					goto top;
				}
				else
				{
					goto bottom;
				}

		case 19:
				//postfix evaluation
				char L[50];
				cout<<"\n\nEnter the Postfix Expression: ";
				cin>>L;
				postfix_e(L);
				cout<<endl<<endl;
				char c19;
				cout<<"\n\n\nDo You Want to Continue??? Enter 'Y' For Yes Or 'N' for No"<<endl;
				cout<<"Enter Your Choice: ";
				cin>>c19;
				cout<<"\n\n\n";
				if (c19=='Y'||c19=='y')
				{
					system("cls");
					goto top;
				}
				else
				{
					goto bottom;
				}

		case 20:
				//bfs
				int from, to, startnode_bfs;
				cout<<"No. of node: ";
				cin>>vertices;
				for(int i=0; i<vertices; i++)
				{
					for(int j=0; j< vertices; j++)
					{
						graph[i][j] = 0;
					}
				}
				cout<<"No. of edges: ";
				cin>>edges;
				for(int i=0; i<edges; i++)
				{
					cout<<"Enter vertes x and y for edge: "<< i+1;
					cout<<"Edge from: ";
					cin>>from;
					cout<<"Edge to: ";
					cin>>to;
					graph[from][to] = 1;
					graph[to][from] = 1;
				}
				initialize_queue_bfs();	
				cout<<"Enter Start node: " ;  
				cin>>startnode_bfs;
				BFS(startnode_bfs, vertices); 
				cout<<endl<<endl;
				char c20;
				cout<<"\n\n\nDo You Want to Continue??? Enter 'Y' For Yes Or 'N' for No"<<endl;
				cout<<"Enter Your Choice: ";
				cin>>c20;
				cout<<"\n\n\n";
				if (c20=='Y'||c20=='y')
				{
					system("cls");
					goto top;
				}
				else
				{
					goto bottom;
				}

	bottom:
		case 21:
				cout<<"\n\n!!!!Thank You!!!!\n*****Good Bye*****\n\n"<<endl;
				exit;
				break;
	
	wrong:
		default:
				cout<<"\n\nWrong Input & Please Try Again\n\n\n";
	}
	
	return 0;
}