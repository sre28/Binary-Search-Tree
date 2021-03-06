#include <iostream>

struct tree
{
    tree *l,*r;
    int data;
};

tree* insert(tree *root, int data)
{
    if(root == NULL)
    {
        root = new tree;
        root->l=NULL;
        root->r=NULL;
        root->data = data;
    }
    else if(data > root->data)
    {
        root->r = insert(root->r, data);
    }
    else
    {
        root->l = insert(root->l, data);
    }
    return root;
}

void display(tree *root)//Inorder(LDR)
{
    if(root != NULL)//Inorder
    {
        display(root->l);
        std::cout<<root->data<<" ";
        display(root->r);
    }
}

int main() {
    tree *root= NULL;
    int ch,data;

    while(1)
        {
        std::cout<<"1.Insert\n2.Display\n3.Exit";
        std::cin>>ch;
        switch(ch) {
           		 case 1: std::cout<<"Enter data\n";
                   	 std::cin>>data;
                   	 std::cout<<"\n";
              	         root = insert(root,data);
                	 break;
            		 case 2: display(root);
                    	 std::cout<<"\n";
               	         break;
            		 case 3: exit(0);
        	    }
        }
    return 0;
}
