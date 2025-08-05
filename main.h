    #ifndef NODE_H
    #define NODE_H
    #include<stdio.h>
    #include<iostream>
    using namespace std;


    // node generic -> (key , value) of any type
    template<typename T,typename V>
    class node {
        public:
        V value;
        T key;
        node <T,V>* next;
        node(V v,T k)
        {
            value=v;
            key = k;
            next = NULL;
        }

    };


    template<typename T,typename V>
    class linkedlist
    {
    private:
        node <T,V> * head;
    public:
        linkedlist()
        {
            head = NULL;

        };
        node<T,V>* getHead() {
             return head;
        }   
        bool isEmpty(){
             return head == NULL;
        }
        void insertAtfront(T data,V key)
        {
            node <T,V> *newNode = new node<T,V>(data,key);
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
                node <T,V>* temp = head;
                head=head->next;
                delete temp;
            }
        }

        void deleation(int i)
        {
            node <T,V> *previous = head;
            if(i==0)
            {
                head = head->next;
            }
            node <T,V> *newNode = head->next;

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
        //     node <T,V> *newNode = head;
        //     while (newNode!=NULL||newNode->data!=data)
        //     {
        //         c++;
                
        //     }
        //     return c;
        // }
        

        void insertAtend(T data,V key)
        {
            node <T,V> *newNode = new node<T,V>(data,key);
            
            if(head == NULL)
            {
                head = newNode;
            
            }
            else{
                node <T,V> * temp = head;
                while (temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next = newNode;
            }
        }

        
        void show(V key)
        {
            node  <T,V>* newNode = head;
            while(newNode!=NULL)
            {
                if(key==newNode->key)
                cout<<"key: "<< newNode->key <<"  value: "<< newNode->value << endl;
                newNode = newNode->next;
            }
            
        }
        
    };


    #endif
