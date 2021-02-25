#include<stdio.h>
int main(){
char c;    //stablish variables
int i=0;
int ignore=0;
 char strong[13]={"strong/strong"};
    char scrip[13]={"script/script"};
 
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
            if (i== 6 && i<13){
    	     if (c == ' ')
             printf('_');{
        	 putchar (c);}
	         if((i!=6 && c!= '<' && c!= '>') || c == '\n'){
	         	putchar (c);
	         	i=0;
			 }
        putchar(c);
             }
        }

}   
//this program could not have been developed without the help of Abner Z., Angel S, Julio B and Cracklitos


    
