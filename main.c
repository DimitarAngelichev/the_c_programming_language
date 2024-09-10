#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    FILE *filePtr;
    char ch;
    short int retVal = 0;
    char startFlag = 0;

    filePtr = fopen("input.txt","r");

    while ((ch = fgetc(filePtr)) != EOF) {
        //printf("%c", ch);
        if(startFlag > 8){
            //reset start flag
            printf("\nresult: 0x%X\n",retVal);
            retVal = 0;
            startFlag = 0;
        }
        if(startFlag > 0){
            if(ch == '1'){
                retVal = retVal | (0b00000001 << (startFlag - 1) );
            }
            
            //printf(" started\n");
            startFlag++;
        }
        if(ch == '0' && startFlag == 0){ 
            //set start flag
            startFlag = 1;
            //printf(" set start\n");
        }
        
    }
    fclose(filePtr);
    

    return 0;
    
}
