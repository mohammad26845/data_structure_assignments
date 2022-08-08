#include <iostream>

using namespace std;


// Create node struct
struct node
{
    int data;
    struct node *next;
};

struct node* start = NULL;
    
     
// Insert at the begin of the list:
void insert_begin(int number)
{
    struct node *n, *p;

    // Create new node and Set number
    n = new(struct node); 
    n->data = number;
    n->next = NULL;  


    // If it was first node >> (Start = First node)
    if (start == NULL)
    {
        start = n;
        start->next = NULL;          
    } 

    // If it wasn't first node >> (Update start)
    else
    {
        p = start;
        start = n;
        start->next = p;
    }
}
    

// Show list values
void display()
{
    struct node *t;

    // If list wasn't made (thus it isn't anything for display)
    if (start == NULL)
    {
        cout<<"Empty"<<endl;
        return;
    }

    // Show list (print)
    t = start;

    while (t != NULL)
    {
        cout << t -> data << "   ";
        t = t->next;
    }

    cout<<endl;
}

// Do Bubble sort
void bubble_sort(int count){

    struct node **h;
    struct node *temp = NULL;

	for (int i = 0; i <= count; i++)
	{
        // Reset h and swapped
        h = &start;

		for (int j = 0; j < count - i - 1; j++)
		{

            // Compare p1 and p2 (p2 == p1->next)
            struct node* p1 = *h;
			struct node* p2 = p1->next;
            
            if (p1->data > p2->data)
			{
				temp = p2->next;
                p2->next = p1;
                p1->next = temp;

                *h = p2;          
			}

            // Next step
            h = &(*h)->next;
        }
    }
}


// Main
int main()
{

    int my_array[] = {20, 1, 30, 3, 60, 1 , 1 , 2 , 100, 52, 12 , 2, 10, 20, 2, 40};
    int list_size;

    // Calc size of the list (Total array size / int size)
    // (Total array size / 4 bytes)
    list_size = sizeof(my_array) / sizeof(my_array[0]);

    // Insert array to list
    for (int i = 0; i < list_size; i++){
        insert_begin(my_array[i]);
    }

    // Show default list
    cout<<"Elements: "<<endl;
    display();

    // Sort
    bubble_sort(list_size);

    // Show sorted list
    cout<<"Linked list after bubble sort: "<<endl;
    display();
}
