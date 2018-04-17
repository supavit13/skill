#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

struct node
{
    char value;
    struct node *left;
    struct node *right;
}*tree = NULL;

void *printin(struct node *tree,char data)
{
	if(tree==NULL)
	    return tree;
	else
	{
	    if(tree->value == '+' && data == '*')
	        cout<<"(";
	    printin(tree->left,tree->value);
	    cout<<tree->value;
	    printin(tree->right,tree->value);
	    if(tree->value == '+' && data == '*')
	        cout<<")";
	}
}

int main()
{
	string c;
	int i;
	stack<struct node*> s;
	getline(cin, c);
	for(i=c.size() - 1;i>=0;i--)
	{
		if(c[i] != '+' && c[i] != '*')
		{
			tree = new struct node;
			tree->value = c[i];
			tree->left = NULL;
			tree->right = NULL;
			s.push(tree);
		}
		else
		{
			struct node *tmp;
			tmp = new struct node;
			tmp->value = c[i];
			tmp->left = s.top();
			s.pop();
			tmp->right = s.top();
			s.pop();
			s.push(tmp);
		}
	}
    printin(s.top(), 0);
}
