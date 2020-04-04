#include<stdio.h>
#include<malloc.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

//Creates new node and returns
struct Node* CreateNode(int data)
{
    struct Node* node= (struct Node*) malloc(sizeof(struct Node));
    node->data= data;
    node->left= NULL;
    node->right= NULL;
    return node;
};

//It will print the BST in Preorder (root, left, right) traversal.
void Print(struct Node* head)
{
    if(head== NULL) return;
    printf("-- %d --\n", head->data);
    Print(head->left);
    Print(head->right);
}

//Root of the BST has to be passed, data will be inserted into the BST
void Insert(struct Node *head, int data)
{
    struct Node* cur= head;
    while(1)
    {
        if(data < cur->data)
        {
            if(cur->left== NULL)
            {
                cur->left= CreateNode(data);
                break;
            }
            else cur= cur->left;
        }
        else
        {
            if(cur->right== NULL)
            {
                cur->right= CreateNode(data);
                break;
            }
            else cur= cur->right;
        }
    }
}

//Returns true if data is available in the BST passed with the head, otherwise false
bool Search(struct Node* head, int data)
{
    if(head== NULL) return 0;
    if(head->data== data) return 1;
    return Search(head->left, data) || Search(head->right, data);
}

//Removes the smallest under the passed head and returns the removed data, used as the helper function of Delete method
int RemoveSmallest(struct Node* par, struct Node* head)
{
    if(head->left== NULL)
    {
        if(par->left== head)
        {
            par->left= head->right;
        }
        else par->right= head->right;

        int ret= head->data;
        free(head);
        return ret;
    }
    return RemoveSmallest(head, head->left);
}

//Deletes the node with the data if available passed with the root
void Delete(struct Node* par, struct Node* head, int data)
{
    if(head== NULL) return;
    if(par== NULL && head->left== NULL && head->right== NULL)//If we want to delete root node having no children
    {
        free(head);
        return;
    }
    if(head->data== data)
    {
        if(head->left== NULL && head->right== NULL) // Leaf node
        {
            if(par->left== head)
            {
                par->left= NULL;
                free(head);
            }
            else
            {
                par->right= NULL;
                free(head);
            }
        }
        else if(head->left!= NULL && head->right== NULL)// Has only left child
        {
            if(par== NULL)// Root node need to be removed
            {
                //head->left should be the new root , return if needed, change code accordingly
                free(head);
                return;
            }
            else if(par->left== head)
            {
                par->left= head->left;
                free(head);
            }
            else
            {
                par->right=head->left;
                free(head);
            }
        }
        else if(head->right!= NULL && head->left== NULL) // has only right child
        {
            if(par== NULL)// Root node need to be removed
            {
                //head->right should be the new root , return if needed, change code accordingly
                free(head);
                return;
            }
            else if(par->left== head)
            {
                par->left= head->right;
                free(head);
            }
            else
            {
                par->right=head->right;
                free(head);
            }
        }
        else // Has both the child
        {
            head->data= RemoveSmallest(head, head->right);
        }
    }
    else
    {
        Delete(head, head->left, data);
        Delete(head, head->right, data);
    }
}
int main()
{
    //Use the functions as you like.
    /*

    struct Node* root= CreateNode(5);
    Insert(root, 1);
    Insert(root, 9);
    Insert(root, 10);
    Insert(root, 7);
    Insert(root, 6);
    Insert(root, 11);
    Print(root);

    Delete(NULL, root, 9);

    printf("After removing: \n");
    Print(root);
    */
    return 0;
}

