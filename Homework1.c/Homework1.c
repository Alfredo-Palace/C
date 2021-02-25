#include<stdio.h>
int main(){
    int c, i = 0;
    char strong[13]={"strong/strong"}; //this char keep the characters (13 total characters) to identificate if it is a strong
    char scrip[13]={"script/script"};  //this char keep the characters (13 total characters) to identificate if it is a script
	//the 1st while is to start the cycle
        while((c = getchar()) != EOF){
//this part eliminate and classificate strongs and strings 
//(here I recieved important help from my partner Angel Soria because her code and explanation permits me watch the problem in other view, so thnx a lot :) )*/

        if(c == '<')
	{
            while((c = getchar()) == strong[i]){
                i = i + 1; }
		
            if(c == scrip[1]){ //this part read letter c
                c = getchar();
                if(c == scrip[2]){ //this part read letter r
                    c = getchar();
                    if (c == scrip[3]){ //this part read letter i
                        while ((c = getchar()) != '>'){
                            NULL;}
                        while((c = getchar()) != '>'){
                            NULL;}
                    }
                }
            }
		//this part permits write the text that are not strongs, strings or "</>"
            if(i == 13){
                i = 0;}
             while(c != EOF && c != '>'){
                c = getchar();}
        }
		//spaces
        else if (i == 6 && i < 13){
                if(c == ' '){
                    printf("_");}
            putchar(c);}
            if ((i != 6 && c != '<' && c != '>') || c == '\n'){
            putchar(c);
            i = 0;
            }
    }
}
     
    
