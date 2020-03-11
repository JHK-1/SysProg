
#include <stdio.h>
#include <stdlib.h>
#include <string.h>      
#include <stdarg.h>       

// void printPreString(){
//     printf("%s", programPreString);
// }

int main (int argc, char *argv[]) {
    
    char line[256], character;
    char COM[256];
    char COM1[256];
    int n=5;
    int c;
    strcpy(COM,"arecord");
    int k=0;
    c=0;
    printf("This program was based on existing ALSA framework and alsa-lib commnads \n");
    printf("To start recording type 'Start [filename].wav', If you want to stop recording press Ctrl+C. \n");
    printf("If you want to set time 'Start -d [time] [filename].wav' time in seconds \n");
    printf("To listen your recording just type 'Play [filename].wav' \n");
    fgets(line,sizeof(line),stdin);
    
    for(int i=0; i<sizeof(line); i++)
    {
        if(line[i]=='P' && line[i+1]=='l' && line[i+2]=='a' && line[i+3]=='y' && line[i+4]==' ')
        {
            
            strcpy(COM,"aplay");
            n=4;
            
        }
        else if (line[i]=='-' && line[i+1]=='d' && line[i+2]==' ')
        {n=8;
        strcpy(COM,"arecord -d");
        }
        
         
    }

    strncpy(COM1,line+n,sizeof(line)-n);
    strcat(COM,&*COM1);

    system(COM);
}