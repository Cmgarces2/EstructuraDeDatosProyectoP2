// C++ program to demonstrate deletion in
// Ternary Search Tree (TST)
// For insert and other functions, refer
// https://www.geeksforgeeks.org/ternary-search-tree
 
#include<iostream>
#define MAX 50
using namespace std;
 
// structure of a node in TST
class Node
{
	public:
	    char key;
	    int isleaf;
	    struct Node *left;
	    struct Node *eq;
	    struct Node *right;
};
 
// function to create a node in TST
class Node *createNode(char key)
{
    class Node *temp = new Node;
    temp->key = key;
    temp->isleaf = 0;
    temp->left = NULL;
    temp->eq = NULL;
    temp->right = NULL;
    return temp;
};
 
// function to insert a Node in TST
void insert_node(class Node **root, char *s)
{
    if (!(*root))
    {
        (*root) = createNode(*s);
    }
 
    if ((*s)<(*root)->key)
        insert_node( &(*root)->left, s);
 
    else if ((*s)>(*root)->key)
        insert_node( &(*root)->right, s);
 
    else if ((*s) == (*root)->key)
    {
        if (*(s+1) == '\0')
        {
            (*root)->isleaf = 1;
            return;
        }
        insert_node( &(*root)->eq, s+1);
    }
}
 
// function to display the TST
void display(class Node *root, char* str, int level)
{
    if (!root)
        return;
 
    display(root->left, str, level);
    str[level] = root->key;
 
    if (root->isleaf == 1)
    {
        str[level+1] = '\0';
        cout<< str <<endl;
    }
 
    display(root->eq, str, level+1);
    display(root->right, str, level);
}
 
//to check if current node is leaf node or not
int isLeaf(class Node *root)
{
    return root->isleaf == 1;
}
 
// to check if current node has any child
// node or not
int isFreeNode(class Node *root)
{
    if (root->left ||root->eq ||root->right)
        return 0;
    return 1;
}
 
// function to delete a string in TST
int delete_node(class Node *root, char* str,
                int level, int n)
{
    if (root == NULL)
        return 0;
 
 
    // CASE 4 Key present in TST, having atleast
    // one other key as prefix key.
    if (str[level+1] == '\0')
    {
        // Unmark leaf node if present
        if (isLeaf(root))
        {
            root->isleaf = 0;
            return isFreeNode(root);
        }
 
        // else string is not present in TST and
        // return 0
        else
            return 0;
    }
 
    // CASE 3 Key is prefix key of another long
    // key in TST.
    if (str[level] < root->key)
        return delete_node(root->left, str, level, n);
    if (str[level] > root->key)
        return delete_node(root->right, str, level, n);
 
    // CASE 1 Key may not be there in TST.
    if (str[level] == root->key)
    {
        // CASE 2 Key present as unique key
        if (delete_node(root->eq, str, level+1, n))
        {
            // delete the last node, neither it has
            // any child nor it is part of any other
            // string
            delete(root->eq);
            return !isLeaf(root) && isFreeNode(root);
        }
    }
 
    return 0;
}

void traverseTSTUtil(Node* root, char* buffer, int depth)
{
    if (root) {
        // First traverse the left subtree
        traverseTSTUtil(root->left, buffer, depth);
 
        // Store the character of this node
        buffer[depth] = root->key;
        if (root->isleaf) {
            buffer[depth + 1] = '\0';
            cout << buffer << endl;
        }
 
        // Traverse the subtree using equal pointer (middle
        // subtree)
        traverseTSTUtil(root->eq, buffer, depth + 1);
 
        // Finally Traverse the right subtree
        traverseTSTUtil(root->right, buffer, depth);
    }
}


void traverseTST(struct Node* root)
{
    char buffer[MAX];
    traverseTSTUtil(root, buffer, 0);
}
 
// Function to search a given word in TST
int searchTST(Node* root, char* word)
{
    if (!root)
        return 0;
 
    if (*word < (root)->key)
        return searchTST(root->left, word);
 
    else if (*word > (root)->key)
        return searchTST(root->right, word);
 
    else {
        if (*(word + 1) == '\0')
            return root->isleaf;
 
        return searchTST(root->eq, word + 1);
    }
}