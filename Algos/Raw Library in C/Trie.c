#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
typedef struct Trie //If we use typedef than we can use 'Trie' as type instead of writing the whole 'struct Trie'
{
    int endmark;
    struct Trie *next[26];

} Trie;

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
    for(int i= 0; word[i]!= NULL; i++)
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

int main()
{
    //Written to only work with lowercase letters.
    Trie *root= trieCreate();

    trieInsert(root, "mahi");

    trieInsert(root, "maruf");

    if(trieSearch(root, "mahim")) printf("mahim found\n");
    else printf("Mahim not found\n");
    if(trieSearch(root, "mahi")) printf("mahi found\n");
    else printf("Mahi not found\n");

    if(trieStartsWith(root, "mam")) printf("found\n");
    else printf("not found\n");
    if(trieStartsWith(root, "ma")) printf("found\n");
    else printf("not found\n");

    trieFree(root);
    return 0;
}
