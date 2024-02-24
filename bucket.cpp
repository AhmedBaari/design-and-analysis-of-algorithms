#include<iostream>
using namespace std;


struct node{
	float data;
	node* next;
};
struct head{
	int count;
	node* first;
};


void insert_order(head* h, float d)
{
	node* n = new node;
	n->data = d;
	node* pre = new node;
	pre = NULL;
	node* temp = h->first;
	if(temp==NULL)
	{
		h->first = n;
		n->next = NULL;
	}
	else
	{
		// Finding the correct place
		while(temp!=NULL)
		{
			if(temp->data > d)
			{
				break;
			}
			pre = temp;
			temp = temp->next;
		}
		// Insert at beginning
		if(pre == NULL)
		{
			n->next = temp;
			h->first = n;
		}
		// Normal Insert 
		else
		{
			pre->next = n;
			n->next = temp;
		}
	}
	h->count++;
}

// a is the input array
void bucketsort(float a[], int n)
{
	head** h = new head*[n]; // Array of heads
	for(int i=0;i<n;i++)
	{
		h[i] = new head; // Initialize head
		h[i]->first = NULL;
		h[i]->count = 0;
	}

	/* Elements of A are inserted in order */
	for(int i=0;i<n;i++)
	{
		insert_order(h[int(a[i] * n)], a[i]); // Insert in order 
	}
	int k = 0;

	for(int i=0;i<n;i++)
	{
		node* n =new node;
		n = h[i]->first;
		if(n == NULL)
			continue;
		else
		{
			// Appending all elements of this linked list to a[]
			while(n!=NULL)
			{
				a[k] = n->data;
				k++;
				n = n->next;
			}
		}
	}
}

int main()
{
	float a[5] = {0.1, 0.2, 0.5, 0.3, 0.9};
	bucketsort(a, 5);
	for(int i=0;i<5;i++)
	{
		cout<<a[i]<<endl;
	}
}


