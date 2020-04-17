#include"decompress.h"

DictElement dictionaryArray[4095];

void dArrayAdd(int prefix, int character, int value) {
    dictionaryArray[value].prefix = prefix;
    dictionaryArray[value].character = character;
}

int dArrayPrefix(int value) {
    return dictionaryArray[value].prefix;
}

int diCharacter(int value) {
    return dictionaryArray[value].character;
}
