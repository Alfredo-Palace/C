#include<stdio.h>
int main(){
    int c, i = 0;
    char strong[13]={"strong/strong"};
    char scrip[13]={"script/script"};
	
        while((c = getchar()) != EOF)
    {
        if(c == '<')
        {
            while((c = getchar()) == strong[i]){
                i++;
            }
            if(c == scrip[1]){ //c
                c = getchar();
                if(c == scrip[2]){ //r
                    c = getchar();
                    if (c == scrip[3]){ //i
                        while ((c = getchar()) != '>'){
                            NULL;
                        }
                        while((c = getchar()) != '>'){
                            NULL;
                        }
                    }
                }
            }
            if(i == 13){
                i =0;
            }
             while(c != EOF && c != '>'){
                c = getchar();
            }
        }
        else if (i == 6 && i < 13){
                if(c == ' '){
                    printf("_");
                }
            putchar(c);
           }
            if ((i != 6 && c != '<' && c != '>') || c == '\n'){
            putchar(c);
            i = 0;
            }
    }
}
     
    
