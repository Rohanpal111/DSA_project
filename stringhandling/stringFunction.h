#include <stdio.h>
#include<iostream>
using namespace std;
int strlen(char *p)
{

    int i = 0;
    while (p[i] != '\0')
    {
        i++;
    }
    return i;
}
void strcpy(char *p, char *q)
{
    int i = 0;
    while (q[i] != '\0')
    {
        p[i] = q[i];
        i++;
    }

    p[i] = '\0';
}

char *strJoin(char *p, char *q)
{
    int i = 0, j = 0;
    while (p[i] != '\0')
    {
        i++;
    }
    while (q[j] != 0)
    {
        p[i] = q[j];
        j++;
        i++;
    }
    p[i] = '\0';
    return p;
}
int strCmp(char *p, char *q)
{
    int i = 0;
    while (p[i] != 0 || q[i])
    {
        if (p[i] != q[i])
            return 0;
        i++;
    }
    return 1;
}
void lower(char *p)
{
    int i = 0;
    while (p[i] != '\0')
    {
        if (p[i] >= 65 || p[i] <= 91)
            p[i] = p[i] + 32;
        i++;
    }
}
void upper(char *p)
{
    int i = 0;
    while (p[i] != '\0')
    {

        if (p[i] >= 97 || p[i] <= 113)
            p[i] = p[i] - 32;

        i++;
    }
}

int findfirstIndex(char *p, char *n)
{
    int i = 0;
    while (p[i] != '\0')
    {
        if (p[i] == n[0])
            return i;
        i++;
    }
    return -1;
}

char *reverse(char *str)
{
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++)
    {
        char s = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = s;
    }
    return str;
}

// int  palindrome(char *str)
// {
//       char rev[100];
//       strcpy(rev,str);
//     if(reverse(rev)==str)return 1;
//     return 0;

// }
bool isHTMLLink(char *url)
{
    int len = strlen(url);
    if (len >= 4)
    {
        if (strCmp(&url[len - 4], (char*)".pdf") == 0)
            return false;
        if (strCmp(&url[len - 4], (char*)".jpg") == 0)
            return false;
        if (strCmp(&url[len - 4], (char*)".png") == 0)
            return false;
        if (strCmp(&url[len - 4], (char*)".css") == 0)
            return false;
        if (strCmp(&url[len - 3], (char*)".js") == 0)
            return false;
    }
        return true;
}


int countWords(char str[])
{

    int c = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if ((i == 0 && str[i] != ' ') || (str[i] == ' ' && str/*  */[i + 1] != ' ' && str[i + 1] != '\0'))
        {
            c++;
        }
    }
    return c;
}


int my_strcasestr(char *str1,char *str2,bool s1)
{
     if (str1 == NULL || str2 == NULL) return -1;
    if(s1)
    {
        lower(str1);
        lower(str2);

    }
    int count=0;
    if(strlen(str1)>strlen(str2))
    return -1;
    else{
        int i =0,j = 0;
        while(str1[i]!='\0'&&str2[j]!='\0')
        {
            if(str1[i]==str2[j])
            {
                i++;
                j++;
                count++;
                if(count==strlen(str1))
                return  j - count;
            }
            else{
                j=j-count+1;
                i=0;
                count=0;
            }
            
        }

    }
    
     
    return -1;

}


bool startsWith(char str[],const char* prefix)
{
    int i=0;
    while(prefix[i]!='\0')
    {
        if(str[i]!=prefix[i]) return false;
        i++;
    }
    return true;
}




// void csv(char *str)
// {
//     int open = 1;
//     char arr[5][200];
//     char a[7];
//     int i = 0, j = 0, k = 0;
//     while (str[i] != '\0')
//     {
//         if (str[i] != ',')
//         {
//             a[j] = str[i];
//             j++;
//         }
//         else if (str[i] == ',')
//         {
//             a[j] = '\0';
//             int l;
//             for (l = 0; l < strlen(a); l++)
//             {
//                 arr[k][l] = a[l];
//             }
//             arr[k][l] = '\0';
//             k++;
//             a[0] = '\0';
//             j = 0;
//         }
//         i++;
//     }

//     a[j] = '\0';
//     int l;

//     for (l = 0; l < strlen(a); l++)
//     {
//         arr[k][l] = a[l];
//     }

//     arr[k][l] = '\0';
//     k++;

//     for (int i = 0; i < strlen(a); i++)
//     {
//         printf("%s\n", arr[i]);
//     }
// }

// int main()
// {int y,x,as;
// char w;
// 	while(1)
// 	{
//         int q,q1;
// 	    printf("press 1 for find the length of the string\npress 2 for copy the second sting into first \npress 3 for concatenaty the two string\npress 4 for the camparessing the two string\npress 5 for making string lower case\npress 6 for upper case\npress 7 for finding the first awareness of the string\npress 8 for csv \npress 9 for reverse \npress 10 for parindrome  \npress 13 for exit \n    ");
// 		char stri[100],stri2[100];
// 		scanf("%d",&q);

// 		switch(q){
// 		case 1:
// 				scanf("%[^\n]s",stri);
// 			    y=strlen(stri);
// 				printf(" length of string:%d\n",y);
// 				break;
// 		case 2:
// 		       scanf("%s",stri);
// 			   scanf("%s",stri2);
// 			   strcpy(stri,stri2);
// 			   printf("the copyed string is = %s\n",stri);
// 		       break;
// 		case 3:
//                 scanf("%s%s",stri,stri2);
//                 strcpt(stri,stri2);
//                 printf("%s\n",stri);
// 		        break;

// 		case 4:
//                 scanf("%s%s",stri,stri2);
//                 x =strcmp(stri,stri2);
//                 printf("%d\n",x);
// 		        break;

// 		case 5 :
//                 scanf("%s",stri);
//                 strlup(stri);
//                 printf("%s\n",stri);
// 		       break;

//         case 6 :
//                 scanf("%s",stri);
//                 upper(stri);
//                 printf("%s\n",stri);
//                 break;
// 		case 7:
//                 scanf("%s",stri);
//                 scanf("%s",stri2);
//                 as= findfirst(stri,stri2);
//                 printf("find at index no %d\n",as);
//                 break;
//         case 8:
//                 scanf("%s",stri);
//                 find1(stri);
//                 break;
//         case 9:
//                 scanf("%s",stri);
//                 reverse(stri);
//                 printf("%s\n",stri);
//                 break;
//         case 10:
//                 scanf("%s",stri);
//                 int find = palindrome(stri);
//                 printf("%d\n",find);
//                 break;
// 		case 13:
// 			return 0;

// 	}
// }
// }
// int main()
// {
//     char a[] = "rohan";
//     reverse(a);
//     cout<<a;
// }