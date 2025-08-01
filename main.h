    #ifndef NODE_H
    #define NODE_H
    #include<stdio.h>
    #include<iostream>
    using namespace std;


    // node generic -> (key , value) of any type
    template<typename T>
    class node {
        public:
        T value;
        int key;
        node <T>* next;
        node(T d,int k)
        {
            value=d;
            key = k;
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
        node<T>* getHead() {
             return head;
        }   
        bool isEmpty(){
             return head == NULL;
        }
        void insertAtfront(T data,int key)
        {
            node <T> *newNode = new node<T>(data,key);
            if(head == NULL)
            {
                head = newNode;
            
            }
            else{
                newNode->next = head;
                head = newNode;
            }
        }
        void deleationAtfirst()
        {
            if(head!=NULL)
            {
                head=head->next;
            }
        }

        void deleation(int i)
        {
            node <T> *previous = head;
            if(i==0)
            {
                head = head->next;
            }
            node <T> *newNode = head->next;

            int c=1;
            while (newNode!=NULL&&c<i)
            {   
                previous = newNode; 
                newNode=newNode->next;
                c++;
            }
            if(newNode!=NULL){
                previous->next = newNode->next;
            }
            

        }
        // int findIndex(T data)
        // {
        //     int c=-1;
        //     node <T> *newNode = head;
        //     while (newNode!=NULL||newNode->data!=data)
        //     {
        //         c++;
                
        //     }
        //     return c;
        // }
        

        void insertAtend(T data,int key)
        {
            node <T> *newNode = new node<T>(data,key);
            
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

        
        void show(int key)
        {
            node  <T>* newNode = head;
            while(newNode!=NULL)
            {
                if(key==newNode->key)
                cout<<"key: "<< newNode->key <<"  value: "<< newNode->value << endl;
                newNode = newNode->next;
            }
            
        }
        
    };


    #endif
