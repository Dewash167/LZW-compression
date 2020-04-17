#define emptyPrefix -1


typedef struct DictNode {
    int value; 
    int prefix;
    int character; 
    struct DictNode *next;
}node1;
node1 *dictionary, *tail;




void dInit();
void aNode(node1 *node);
void dDestroy();
int dLookup(int prefix, int character);
int dPrefix(int value);
int dCharacter(int value);
void dAdd(int prefix, int character, int value);


