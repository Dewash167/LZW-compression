#define dictionarySize  4095
#define codeLength 12
#define maxValue dictionarySize - 1

void compress(FILE *in, FILE *out);
void decompress(FILE *in, FILE *out);
int decode(int code, FILE * out);

