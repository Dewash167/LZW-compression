#include <stdio.h>
#include <stdlib.h>
#include"dict.h"


void dInit() {
    int i;
    node1 *node;
    for (i = 0; i < 256; i++) {
        node = (node1*)malloc(sizeof(node1));
        node->prefix = emptyPrefix;
        node->character = i;
        aNode(node);
    }       
}


void aNode(node1 *node) {
    if (dictionary != NULL) 
	tail->next = node;
    else
	 dictionary = node;
    tail = node;
    node->next = NULL;
}


void dDestroy() {
    while (dictionary != NULL) {
        dictionary = dictionary->next; 
    }
}


int dLookup(int prefix, int character) {
    node1 *node;
    for (node = dictionary; node != NULL; node = node->next) { 
        if (node->prefix == prefix && node->character == character)
	 return node->value;
    }
    return emptyPrefix;
}

int dPrefix(int value) {
    node1 *node;
    for (node = dictionary; node != NULL; node = node->next) { 
        if (node->value == value) 
	return node->prefix;
    }
    return -1;
}

int dCharacter(int value) {
    node1 *node;
    for (node = dictionary; node != NULL; node = node->next) { 
        if (node->value == value) {
            
            return node->character;
        }
    }
    return -1;
}


void dAdd(int prefix, int character, int value) {
    node1 *node;
    node = (node1 *)malloc(sizeof(node1));
    node->value = value;
    node->prefix = prefix;
    node->character = character;
    aNode(node);
}
