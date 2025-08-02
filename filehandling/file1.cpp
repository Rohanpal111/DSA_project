#include <fstream>
#include <iostream>
#include <string>
using namespace std;
// #include <filesystem>
int main()
{
     ifstream in("input.txt");
     if(!in.is_open())
     {
        cerr << "Failed to open file";
     }
     else{
        cout<<"sucess";
     }
}