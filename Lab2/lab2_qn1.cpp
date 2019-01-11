//Implementation of Singly Linked List using C++
#include <iostream>

using namespace std;
class Node{
    public:
    //Data
    int data;
    //Pointer to the next Node
    Node *ptr;
    //Constructor to make ptr to null
    Node()
    {
        ptr=NULL;
    }
};
class LinkedList{
    public:
    
    
    //Head-> circle type ptr
    Node *head;
    Node *tail;
    //Constructor
    LinkedList()
    {
        head=NULL;
        tail=NULL;
    }
    //Circle inside linked with each other
    //Rules how circle will be linked
    //Insertion
    void insert(int value)
    {
        //1st Node is added
        Node *temp=new Node();
        //Insert data in node
        temp->data=value;
        if(head==NULL)
        {
            //1st node only
            this->head=temp;
        }
        else
        {
        //Any other node
        tail->ptr=temp;
        }
        
        this->tail=temp;
        
    }
    //Insert at 
    void InsertAt(int pos,int data)
    {
        //Reach the place before pos
        Node *current=head;
        int i=1;
        while(i<pos-1)
        {
           i++;
           current=current->ptr;
        }
        //Create the node
        Node *raj=new Node();
        raj->data=data;
        raj->ptr=current->ptr;
        current->ptr=raj;
    }
    
    //Deletion of last element
    void del()
    {
        //store tail in temp
        Node *t=tail;
        //before tail has to point to NULL
         Node *current=head;
        while(current->ptr!=tail)
        {
            current=current->ptr;
        }
        current->ptr=NULL;
        //update tail
        tail=current;
        //delete temp
        delete t;
        
    }
    //count items
    int countItems()
    {
        Node *current=head;
        int length=0;
        while(current!=NULL)
        {
            length++;
            current=current->ptr;
        }
        return length;
    }
    //Delete at position
    void deleteAt(int pos)
    {
        //Reach the place before pos
        Node *current=head;
        int i=1;
        while(i<pos-1)
        {
           i++;
           current=current->ptr;
        }
        //copy the node to be deleted
        Node *t=current->ptr;
        //Reach next place after pos 
        Node *next=head;
        int j=0;
        while(j<pos)
        {
           j++;
           next=next->ptr;
        }
        //Pointer of the node before pos will point to the node after pos 
        current->ptr=next;
        delete t;
        
    }
    //Display
    
    void display()
    {
        Node *current=head;
        while(current!=NULL)
        {
            cout<<current->data<<"->";
            current=current->ptr;
            
        }
        cout<<"NULL"<<endl;
    }

};

int main()
{
    //Object of the class
    LinkedList l1;
    //Enter values
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    //show output
    l1.display();
    cout<<"The number of items before deletion="<<l1.countItems()<<endl;
    l1.del();//use of delete
    l1.display();
    cout<<"The number of items after deletion="<<l1.countItems()<<endl;
   l1.InsertAt(2,5);//use of insert at
    l1.display();
    cout<<"The number of items after insertion at position="<<l1.countItems()<<endl;
    l1.deleteAt(3);//use of deleteAt
    l1.display();
    cout<<"The number of items after delete at position="<<l1.countItems()<<endl;
    
    return 0;
}