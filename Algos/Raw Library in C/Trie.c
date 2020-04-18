#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
typedef struct Trie //If we use typedef than we can use 'Trie' as type instead of writing the whole 'struct Trie'
{
    int endmark;
    struct Trie *next[26];

} Trie;

//Returns concatenated string a+b with a new reference
char* Concate(char* a, char* b)
{
    int len_a= 0, len_b= 0,i;
    for(i= 0; a[i]; i++) len_a++;
    for(i= 0; b[i]; i++) len_b++;
    char* s= (char*) malloc(sizeof(char)*(len_a+len_b+1));
    for(i= 0; i<len_a; i++) s[i]= a[i];
    for(int j= 0; j<len_b; j++, i++)
    {
        s[i]= b[j];
    }
    s[i]= '\0';
    return s;
}

//returns string of a single character char ch input
char* charToStr(char ch)
{
    char* s= (char*) malloc(sizeof(char)*2);
    s[0]= ch;
    s[1]= '\0';
    return s;
}
/** Initialize your data structure here. */

Trie *trieCreate()
{
    Trie *root= (Trie*) malloc(sizeof(Trie));
    root->endmark= 0;
    for(int i= 0; i<26; i++)
    {
        root->next[i]= NULL;
    }
    return root;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word)
{
    Trie *cur= obj;
    for(int i= 0; word[i]; i++)
    {

        int id= word[i]-'a';
        if(cur->next[id]== NULL)
        {
            cur->next[id]= trieCreate();
        }
        cur= cur->next[id];
    }
    cur->endmark= 1;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word)
{
    Trie *cur= obj;

    for(int i= 0; word[i]; i++)
    {
        int id= word[i]-'a';
        if(cur->next[id]== NULL) return 0;
        cur= cur->next[id];
    }

    return cur->endmark;

}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix)
{
    Trie *cur= obj;
    for(int i= 0; prefix[i]; i++)
    {
        int id= prefix[i]-'a';
        if(cur->next[id]== NULL) return 0;
        cur= cur->next[id];
    }
    return 1;
}

void trieFree(Trie* obj)
{
    for(int i= 0; i<26; i++)
    {
        if(obj->next[i]!= NULL) trieFree(obj->next[i]);
    }
    free(obj);
}

//Prints all the words saved in Trie in dictionary order taking Trie *root and empty string as input
void triePrint(Trie* obj, char* s)
{
    if(obj== NULL) return;
    if(obj->endmark)
    {
        puts(s);
    }
    for(int i= 0; i<26; i++)
    {
        char ch= i+'a';
        triePrint(obj->next[i], Concate(s, charToStr(ch)));
    }
}
int main()
{
    Trie* root= trieCreate();
    trieInsert(root, "mahin");
    trieInsert(root, "abdullah");
    trieInsert(root, "abd");
    trieInsert(root, "mahi");

    triePrint(root, "");

    return 0;
}
