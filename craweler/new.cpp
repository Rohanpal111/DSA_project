     #include<stdio.h>
    #include <stdlib.h>
    #include <fstream>
    #include <iostream>
    #include <direct.h>  
    #include <stdbool.h>
    #include <string.h>
    #include <time.h>
    #include "../stringhandling/stringFunction.h"
    #include "../main.h"
    #include"../hashtable/hashtable.h"
    using namespace std;
    // template<typename T,typename V>
    
    class MYmain
    {
    private:
        hashtable<char*, char*>* h1;
        char url[1000];
        char path[1000];
        char file[1000];
        int maxDepth;
        
    public:
        

        MYmain(char *u,char *p,int depth)
        {
            char cd1[265];
            _getcwd(cd1, sizeof(cd1));
            strJoin(cd1,"\\");
            strJoin(cd1,p);
            strcpy(path,cd1);
            strcpy(url,u);
            h1 = new hashtable<char*, char*>(2);
            maxDepth = depth;
            
        };
        void dfs(char *url, int depth)
        {
            char *command = cont(url);
            int i = 9,j=0;
            char fileName[200];


            while(command[i]!='"')
            {
                fileName[j]=command[i];
                j++;i++;               
            }
            fileName[j]='\0';
            
            
           system(command);
           char* keyCopy = strdup(url);        
            char* valueCopy = strdup(fileName);
           h1->insert(valueCopy,keyCopy);
            show(url);
           read(command,depth,url);    
        }


        char* cont(char *url){

        static char command[2000] = "wget -O \"";
        command[0] = '\0';
        strcpy(command, "wget -O \""); 
        strJoin(command, path);

        strJoin(command, "\\"); 
        
        char *s = unique();
        strcpy(file,s);
        strJoin(command,s);

        strJoin(command, "\" ");
        strJoin(command, url); 
        strJoin(command, "\"");
        cout<<command;
        return command;
        

        }


        char* unique()
        {
             time_t t;
             struct tm *tm_info;
             time(&t);
             tm_info = localtime(&t);
             static char timestr[1000];
             int i=0;
             while(t>0)
             {
                int rem = t%10;
                timestr[i] = rem+'0';
                t=t/10;
                i++;
             }
             timestr[i] = '\0'; 
             strJoin(timestr, ".html");
             return timestr;
        }
        void read(char * command,int depth,char *rootUrl)
        {

            int i = 9,j=0;
            char fileName[200];
            while(command[i]!='"')
            {
                fileName[j]=command[i];
                j++;i++;               
            }
            fileName[j]='\0';


            char arr[10000];
            
             FILE* file = fopen(fileName, "r");

            if (file == NULL) {
                printf("File open nahi ho payi: %s\n", fileName);
                return;
            }

            char ch;
            int index=0;

            while ((ch = fgetc(file)) != EOF) {
               arr[index++] = ch;
                
            }
            arr[index] = '\0';
            allUrl(arr,depth,url);
            fclose(file);
        }


        void allUrl(char *arr,int depth,char *rootUrl)
        {
             
            int i = 0; 
            while (arr[i]!='\0')
            {
                if(startsWith(&arr[i],"https://")||startsWith(&arr[i],"/"))
                {
                    int flag= 0;
                    if(startsWith(&arr[i],"/"))
                    {
                        flag = 1;
                    }
                    char url[1000];
                    int j=0;

                    while(arr[i]!='\0'&&!isspace(arr[i]) &&arr[i] != '"' &&arr[i] != '\'' && arr[i] != '<' &&arr[i] != '>')
                    {
                        url[j++]=arr[i++];
                    }
                    url[j]='\0';
                    if(flag==1)
                    {
                        char fullUrl[2000];
                        strcpy(fullUrl, rootUrl);
                        int len = strlen(fullUrl);
                        if(fullUrl[len - 1] == '/')
                            fullUrl[len - 1] = '\0';

                        strJoin(fullUrl, url);  
                         
                        dfs(fullUrl, depth + 1);
                        

                    }else{
                    
                    char* realUrl = (char*)malloc(strlen(url) + 1);
                    
                    strcpy(realUrl,url);
                    dfs(realUrl,depth+1);
                    }
                    
                
                }
                else{
                    i++;
                }
            }
               
            if (depth >= maxDepth) return;
            
        }

        void show(char *url)
        {
            cout<<endl<<endl<<"free"<<endl<<endl;
            // h1->triversing(url);
            h1->printAll();
            cout<<endl<<endl<<"free"<<endl<<endl;
        }

    };




    int main(int arg, char **args){
        if(startsWith(args[1],"http://")||startsWith(args[1],"https://")){
            ifstream in(args[2]);
            if(!in.is_open())
            {
                if (_mkdir(args[2]) == 0) {
                    std::cout << "Folder created successfully.\n";
                }
            }
            MYmain m(args[1],args[2],100);
            m.dfs(args[1],0);
            
            
            
           
        }
        else{
                cout<<"Wrong Url";
        }
}

