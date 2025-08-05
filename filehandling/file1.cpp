#include <fstream>
#include <iostream>
#include <string>
using namespace std;
// #include <filesystem>
int main()
{

    ofstream out("input.txt",ios::out|ios::trunc);
    out<<"rrr pal pardhan";
     ifstream in("input.txt");



     if(!in.is_open())
     {
        cerr << "Failed to open file";
        return 1;
     }
     else{
      cout<<"Open successfully";
        
        char word[100];
        int count=0;
        while(in>>word){
            count++;
        }
        cout<<"Word is this file is:"<<count;
        in.close();
    }
}
