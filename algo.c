#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dict.c"
//#include"dict.h"
#include "bwr.c" 
//#include "list.c"
#include "decompress.c" 
#include "algo.h"





void compress(FILE *in, FILE *out) {    
    int prefix = getc(in);
    if (prefix == EOF) {
        return;
    }
    int character;

    int nextCode;
    int index;
    
    
    nextCode = 256; 
    dInit();
    
    
    while ((character = getc(in)) != (unsigned)EOF) { 
         
        
        if ((index = dLookup(prefix, character)) != -1) 
	prefix = index;
        else { 
            writeBinary(out, prefix);
            
            
            if (nextCode < dictionarySize) 
	dAdd(prefix, character, nextCode++);
         
           
            prefix = character;
        }
    }
    
    writeBinary(out, prefix); 
    
    if (leftover > 0) 
	fputc(leftoverBits << 4, out);
    
    
    dDestroy();
}


void decompress(FILE * in, FILE * out) {
    
    int pCode; int Code;
    int nextCode = 256; 

    int firstChar;
    
    
    pCode = readBinary(in);
    if (Code == 0) {
        return;
    }
    fputc(Code, out);
    
   
    while ((Code = readBinary(in)) > 0) { 
    
        if (Code >= nextCode) {
            fputc(firstChar = decode(pCode, out), out); 
            
            
        } else 
	firstChar = decode(Code, out); 
        
        
        if (nextCode < dictionarySize)
	 dArrayAdd(pCode, firstChar, nextCode++);
        
        
        pCode = Code;
    }

}

int decode(int code, FILE * out) {
    int character; int temp;

    if (code > 255) { 
        character = diCharacter(code);
        temp = decode(dArrayPrefix(code), out); 
    } else {
        character = code;
        temp = code;
    }
    fputc(character, out);
    
    
    return temp;
}
