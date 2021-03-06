#include <bits/stdc++.h>
using namespace std;
#define MAX 50
 
// A node of ternary search tree
class Node {
	public:
	    char data;
	    unsigned isEndOfString = 1;
	    Node *left, *eq, *right;
};
 
// A utility function to create a new ternary search tree
// node
Node* newNode(char data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->isEndOfString = 0;
    temp->left = temp->eq = temp->right = NULL;
    return temp;
}
 
// Function to insert a new word in a Ternary Search Tree
void insert(Node** root, char* word)
{
    // Base Case: Tree is empty
    if (!(*root))
        *root = newNode(*word);
 
    // If current character of word is smaller than root's
    // character, then insert this word in left subtree of
    // root
    if ((*word) < (*root)->data)
        insert(&((*root)->left), word);
 
    // If current character of word is greater than root's
    // character, then insert this word in right subtree of
    // root
    else if ((*word) > (*root)->data)
        insert(&((*root)->right), word);
 
    // If current character of word is same as root's
    // character,
    else {
        if (*(word + 1))
            insert(&((*root)->eq), word + 1);
 
        // the last character of the word
        else
            (*root)->isEndOfString = 1;
    }
}
 
// A recursive function to traverse Ternary Search Tree
void traverseTSTUtil(Node* root, char* buffer, int depth)
{
    if (root) {
        // First traverse the left subtree
        traverseTSTUtil(root->left, buffer, depth);
 
        // Store the character of this node
        buffer[depth] = root->data;
        if (root->isEndOfString) {
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
 
// The main function to traverse a Ternary Search Tree.
// It mainly uses traverseTSTUtil()
void traverseTST(class Node* root)
{
    char buffer[MAX];
    traverseTSTUtil(root, buffer, 0);
}
 
// Function to search a given word in TST
int searchTST(Node* root, char* word)
{
    if (!root)
        return 0;
 
    if (*word < (root)->data)
        return searchTST(root->left, word);
 
    else if (*word > (root)->data)
        return searchTST(root->right, word);
 
    else {
        if (*(word + 1) == '\0')
            return root->isEndOfString;
 
        return searchTST(root->eq, word + 1);
    }
}

int isFreeNode(class Node *root)
{
    if (root->left ||root->eq ||root->right)
        return 0;
    return 1;
}

int delete_node(class Node *root, char str[], int depth)
{
    if (root == NULL)
        return 0;
 
 
    // CASE 4 Key present in TST, having atleast
    // one other key as prefix key.
    if (str[depth+1] == '\0')
    {
        // Unmark leaf node if present
        if (root->isEndOfString)
        {
            root->isEndOfString = 0;
            return isFreeNode(root);
        }
 
        // else string is not present in TST and
        // return 0
        else
            return 0;
    }
 
    // CASE 3 Key is prefix key of another long
    // key in TST.
    if (str[depth] < root->data)
        return delete_node(root->left, str, depth);
    if (str[depth] > root->data)
        return delete_node(root->right, str, depth);
 
    // CASE 1 data may not be there in TST.
    if (str[depth] == root->data)
    {
        // CASE 2 data present as unique data
        if (delete_node(root->eq, str, depth+1))
        {
            // delete the last node, neither it has
            // any child nor it is part of any other
            // string
            delete(root->eq);
            return !root->isEndOfString && isFreeNode(root);
        }
    }
 
    return 0;
}