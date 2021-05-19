#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//CLASS
class tree
{
    public:
    int data=0;
    vector<tree*>child;
    tree()
    {

    }

    tree(int data)
    {
        this->data=data;
    }
};

tree* create_tree(vector<int>&arr)
{
    stack<tree*>st;

    for(int i=0;i<arr.size()-1;i++)
    {
        if(arr[i]!=-1)
        {
            tree* node=new tree(arr[i]);
            st.push(node);
        }

        else
        {
            tree* node=st.top();
            st.pop();
            st.top()->child.push_back(node);    //To reflect any changes to heap use '->' symbol
        }
    }

    return st.top();
}

void display(tree* node)
{
    cout<<node->data<<"->";

    for(tree* children:node->child)
    {
        cout<<children->data<<",";
    }
    cout<<endl;

    for(tree* children:node->child)
    {
        display(children);
    }
}

bool find_in_tree(tree *node,int data)
{
    if(node->data==data)
        return true;

    if(node==NULL)
        return false;

    bool res=false;

    for(tree* children: node->child)
    {
        res=res||find_in_tree(children,data);
    }

    return res;    
}

int max_in_tree(tree* node)
{
    if(node==NULL)
    {
        return 0;
    }

    int m=node->data;

    for(tree* children: node->child)
    {
        m=max(m,max_in_tree(children));
    }

    return m;
}

int min_in_tree(tree* node)
{
    int m=node->data;

    for(tree* children: node->child)
    {
        m=min(m,min_in_tree(children));
    }

    return m;
}

int size_of_tree(tree* node)
{
    int size=0;

    for(tree* children:node->child)
    {
        size+=size_of_tree(children);
    }

    return size+1;
}

int height_of_tree(tree* node) //in terms of edges    //for in terms of node initialize h=0 
{
    int h=-1;

    for(tree* children:node->child)
    {
        h=max(h,height_of_tree(children));
    }

    return h+1;
}

tree* get_tail(tree* node)
{
    if(node->child.size()==0)
    {
        return node;
    }

    return get_tail(node->child[0]);
}

void linearize_tree(tree* node)
{
    for(tree* children:node->child)
    {
        linearize_tree(children);
    }

    for(int i=node->child.size()-2;i>=0;i--)
    {
        tree* tail=get_tail(node->child[i]);
        tail->child.push_back(node->child[i+1]);

        node->child.pop_back();
    }
}

void generic_tree()
{
    vector<int>arr={10,20,50,-1,60,-1,-1,30,70,-1,80,100,-1,110,-1,-1,90,-1,-1,40,-1,-1};
    tree* root=create_tree(arr);
    //display(root);
    //cout<<find_in_tree(root,30)<<endl;
    //cout<<max_in_tree(root)<<endl;
    //cout<<min_in_tree(root)<<endl;
    //cout<<size_of_tree(root)<<endl;
    //cout<<height_of_tree(root)<<endl;
    linearize_tree(root);
    display(root);
}

int main(int argc,char** argv)
{
    generic_tree();
}