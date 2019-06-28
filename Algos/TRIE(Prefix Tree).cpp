#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
    int endmark;//Indicates how many strings ends with this node
    node* next[26];//edges with character 'a' to 'z'
    node()
    {
        endmark = 0;
        for (int i = 0; i < 26; i++) next[i] = NULL;
    }
};
node* root;
void insertString(string str)
{
    int len= str.size();
    node* curr = root;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL) curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark++;
}

/*
searchString(string str) returns -1 when there no such prefix or word added,
it returns 0 if there are such prefix but none of them are complete word,
otherwise it returns the number of time the 'str' appears as a complete string.
*/
int searchString(string str)
{
    int len= str.size();
    node* curr = root;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL) return -1;
        curr = curr->next[id];
    }
    return curr->endmark;
}

void del(node* cur)
{
    for (int i = 0; i < 26; i++) if (cur->next[i]) del(cur->next[i]);
    delete (cur);
}
int main()
{

    cout<<"ENTER NUMBER OF WORDS: ";
    root = new node();
    int num_word;
    cin >> num_word;

    for (int i = 1; i <= num_word; i++)
    {
        string s;
        cin>>s;
        insertString(s);
    }
    cout<<"ENTER NUMBER OF QUERY: ";
    int query;
    cin >> query;
    for (int i = 1; i <= query; i++) {
        string s;
        cin>>s;
        int k= searchString(s);
        if (k== -1) cout<<"There's no such prefix\n";
        else if(k== 0) cout<<"There is such prefix but none of them are complete strings\n";
        else cout<<"There are "<<k<<" number of complete strings\n";
    }
    del(root);
    return 0;
}
