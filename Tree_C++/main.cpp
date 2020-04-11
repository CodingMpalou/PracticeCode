#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct Node{
    int x;
    Node *left,*right;
};

Node *root;
void init(vector<int> values){
    int i;
    Node **node,*next_node;

    if(root==NULL)
    {
        root = new Node;
        root->x=values[0];
        root->left=NULL;
        root->right=NULL;
    }

    cout<<endl;
    for(i=1;i<values.size();i++)
    {
        node=&root;
        while((*node)!=NULL)
        {
            cout<<(*node)->x<<" ";
            if((*node)->x<values[i])
                node=&((*node)->left);
            else
                node=&((*node)->right);
        }
        (*node)=new Node;
        (*node)->x=values[i];
        (*node)->left=NULL;
        (*node)->right=NULL;
        cout<<values[i]<<endl;
    }

}

int main() {

    vector<int> values;
    int i;
    root=NULL;
    srand (time(NULL));

    cout<<"Ten random values: ";
    for(i=0;i<10;i++)
    {
        values.push_back(10+rand() % 40);
        cout<<values[i]<<" ";
    }

    init(values);

    return 0;
}