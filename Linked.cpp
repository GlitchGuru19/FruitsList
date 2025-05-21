// We have 5 node a to e and we want to delete c and keep it a linked pointer
// We are going to create a list of fruits where we can add and delete

#include <iostream>

using namespace std;

class Fruit
{
public:
    string data;
    Fruit(string name)
    {
        this->data=name;
    }

};

//Global
Fruit *head = NULL, *rear=NULL;

void push(Fruit *temp)
{
    if(head == NULL)
    {
         head = temp;
         rear = temp;
    }
    else
    {
        rear->next = temp;
        rear= temp;
    }
}

bool pop()
{
    if(head == NULL) return false;
    else if(head == rear)
    {
        delete head;
        head = NULL; rear = NULL;
    }
    else
    {
        Fruit *temp=head;
        while(temp->next!=rear)
        {
            temp=temp->next;
        }
        delete rear;
        rear = temp;
        rear->next=NULL;
        return true;
    }

}

void printList()
{
    cout << "===== Printing List ===== " << endl;
    Fruit *temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }

}

int main()
{
    Fruit *fruit = new Fruit("Mango");
    push(fruit);
    fruit = new Fruit("Banana");
    push(fruit);
    printList();
    fruit = new Fruit("Melon");
    push(fruit);
    printList();
    pop();
    printList();

    return 2;
}
