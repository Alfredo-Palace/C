#include<stdio.h>
int main(){
char c;
int i=0;
int ignore=0;
 while ((c=getchar()) != EOF)
       {
           if (c == '<')
        {
            ignore=1;
        }
        else if (ignore != 1)
        {
            putchar (c);
        }
        else if (c == '>')
        {
            ignore= 0;
        }
       }
       if (i == 0){
        i=1;}
        while (c != EOF && c!= '>'){
            c = getchar ();}
        {
            if(i==0 && i<1){
                if (c == ' ')
                printf('_'); {
                putchar (c);}
                if((i!=0 && c!= '<' && c!= '>') || c == '\n'){
                 putchar (c);
                 i=0;
             }
        putchar(c);  

            }
        }

}   
//this program could not have been developed without the help of Abner Z., Julio B and Cracklitos


    
