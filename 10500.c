#include <stdlib.h>

char** findWords(char** words, int wordsSize, int* returnSize) {
    static const unsigned char map[256] = {
        ['q']=1,['Q']=1,['w']=1,['W']=1,['e']=1,['E']=1,['r']=1,['R']=1,['t']=1,['T']=1,['y']=1,['Y']=1,['u']=1,['U']=1,['i']=1,['I']=1,['o']=1,['O']=1,['p']=1,['P']=1,
        ['a']=2,['A']=2,['s']=2,['S']=2,['d']=2,['D']=2,['f']=2,['F']=2,['g']=2,['G']=2,['h']=2,['H']=2,['j']=2,['J']=2,['k']=2,['K']=2,['l']=2,['L']=2,
        ['z']=4,['Z']=4,['x']=4,['X']=4,['c']=4,['C']=4,['v']=4,['V']=4,['b']=4,['B']=4,['n']=4,['N']=4,['m']=4,['M']=4
    };
    
    char** result = malloc(wordsSize * sizeof(char*));
    *returnSize = 0;
    
    for (int i = 0; i < wordsSize; i++) {
        unsigned char row = map[(unsigned char)words[i][0]];
        int valid = 1;
        for (int j = 1; words[i][j] != '\0'; j++) {
            if (map[(unsigned char)words[i][j]] != row) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            result[(*returnSize)++] = words[i];
        }
    }
    
    return result;
}