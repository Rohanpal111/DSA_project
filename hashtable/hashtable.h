#include <stdio.h>
#include <string>

#include "../main.h"


//        key->type,key->value
template<typename T,typename V>
 class hashtable
 {
    public:
    int size;
    int current = 0;
    linkedlist <T,V>* arr;
    hashtable(int s)
    {
        size = s;
        arr = new linkedlist<T,V>[size];
    }
    int generateKey(int key)
    {
        return key%size;
    }
    int generatekey(char key)
    {
        return key%size;
    }
    long long int generateKey(char* key)
    {
        long long int sum = 0;
        int i = 0;
        while(key[i]!='\0')
        {
            sum+=key[i];
            i++;
        }
        return sum%size;
    }
    void printAll()
{
    for(int i = 0; i < size; i++)
    {
        node<T, V>* temp = arr[i].getHead();
        if(temp != NULL)
        {
            cout << "Index " << i << ":\n";
            while(temp != NULL)
            {
                cout << "  Key: " << temp->key << ", Value: " << temp->value << endl;
                temp = temp->next;
            }
        }
    }
}

   
    void show()
    {
        for(int i = 0; i < size; i++)
    {
        node<T, V>* temp = arr[i].getHead();
        if(temp != NULL)
        {
            cout << "Index " << i << ":\n";
            while(temp != NULL)
            {
                cout << "  Key: " << temp->key << ", Value: " << temp->value << endl;
                temp = temp->next;
            }
        }
    }
    }
    

    void insert(V value,T key)
    {
        

        float per = (float)current/size*100;
        if(per>70)
        {
            resize(size,current);
        }
        int newKey = generateKey(key);
        if(arr[newKey].isEmpty())
        {
            current++;
        }
        arr[newKey].insertAtend(value, key);
        
        
        

    }
    void triversing(T key)
    {
        int key1=generateKey(key);
        arr[key1].show(key);
    }
    void resize(int s,int current)
    {   

        size=s*2;
        linkedlist <T,V> *arr2 = arr;
        arr = new linkedlist<T,V>[size];    
        this->current;
        for(int i=0;i<s;i++)
        {

            node <T,V> * temp =arr2[i].getHead();
            while(temp!=NULL)
            {
                insert(temp->value,temp->key);
                temp = temp->next;
            }
            
        }
        delete[] arr2;
        
            

    }

 }
;

//  int main(){

//     hashtable <char*,char*> h1(4);
//      h1.insert((char*)"Apple", (char*)"A");
//     h1.insert((char*)"Banana", (char*)"B");
//     h1.insert((char*)"Carrot", (char*)"C");

//     h1.triversing((char*)"A");

    
    
//     // h1.triversing(20);

//  }