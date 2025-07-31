#include<stdio.h>
#include<iostream>
using namespace std;
template<typename T >
class node {
    public:
    T data;
    node<T>* next;
    node(T d)
    {
        data=d;
        next = NULL;
    }

};

template<typename T>
class linkedlist
{
private:
    node <T> * head;
public:
    linkedlist()
    {
        head = NULL;

    };
    void insertAtend(T data)
    {
        node <T> *newNode = new node<T>(data);
          
        if(head == NULL)
        {
            head = newNode;
           
        }
        else{
            node <T> * temp = head;
            while (temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next = newNode;

             
        }


    }
    void show()
    {
        node  <T>* newNode = head;
        while(newNode!=NULL)
        {
            cout<<newNode->data<<"->";
            newNode = newNode->next;
        }
    }
    
};





int main(){
    linkedlist <int> l1;
    l1.insertAtend(10);
    l1.insertAtend(20);
    l1.insertAtend(30);
    l1.show();

    linkedlist <string> l2;
    l2.insertAtend("rohan");
    l2.insertAtend("pal");
    l2.insertAtend("manjeet");
    l2.show();
    return 0;

}