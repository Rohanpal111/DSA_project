#include <stdio.h>
#include "main.h"


//        key->type,key->value
template<typename T,typename V,typename D>
 class hashtable
 {
    public:
    int size;
    int current = 0;
    linkedlist <D>* arr;
    hashtable(int s)
    {
        size = s;
        arr = new linkedlist<D>[size];
    }
    int generateKey(T key)
    {
        return key%size;
    }


    void insert(V value,T key)
    {

        float per = (float)current/size*100;
        if(per>50)
        {
            resize(size,current);
        }
        int newKey = generateKey(key);
        if(arr[newKey].isEmpty())
        {
            current++;
            
        }

        arr[newKey].insertAtend(value, key );
    }
    void triversing(int key)
    {
        int key1=generateKey(key);
        arr[key1].show(key);
    }
    void resize(int s,int current)
    {   

        size=s*2;
        linkedlist <D> *arr2 = arr;
        arr = new linkedlist<D>[size];
        for(int i=0;i<size;i++)
        {

            node <D> * temp =arr2[i].getHead();
            while(temp!=NULL)
            {
                insert(temp->value,temp->key);
                temp = temp->next;
            }
            
        }
        
        

    }

 }
;

 int main(){

    hashtable <int,int,int> h1(4);
    h1.insert(20,0);
    h1.insert(30,6);
    h1.triversing(6);

    
    
    // h1.triversing(20);

 }