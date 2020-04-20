//check if the sum of left and right child equals the parent node, all leaf nodes obey this rule. if any child is missing we assume its data value is 0


#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
void insert(Node *root,int a1,int a2,char lr){
	if(root==NULL){
		return;
	}
	if(root->data==a1){
		switch(lr){
			case 'L':root->left=new Node(a2);
			break;
			case 'R':root->right=new Node(a2);
			break;
		}
	}
	else{
		insert(root->left,a1,a2,lr);
		insert(root->right,a1,a2,lr);
	}
}
void inorder(Node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int isSumProperty(Node *node);
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t-->0)
	{
		int n;
		cin>>n;
		int m=n;
		Node *root1=NULL;
		while(n-->0){
			int a1,a2;
			cin>>a1>>a2;
			char lr;
			scanf(" %c",&lr);
			if(root1==NULL){
				root1=new Node(a1);
				switch(lr){
					case 'L':root1->left=new Node(a2);
					break;
					case 'R':root1->right=new Node(a2);
					break;
				}
			}
			else{
				insert(root1,a1,a2,lr);
			}
		}
			cout<<isSumProperty(root1)<<endl;
	}
}


/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
int isSumProperty(Node *node)
{  
	 static int index=0;
    cout<<"level: "<<index++<<" value: "<<node->data<<endl;
    
    if(node==NULL)
    return 1;
    
    if(node->left==NULL&&node->right==NULL)
    {
            //leaf node
           return 1;
            
    }
    int sum=0;
     if(node->right==NULL)
        {
            //right child is absent
            sum=node->left->data;
        }
        else if(node->left==NULL)
        {
            //left child is absent
            sum=node->right->data;
        }
        else
        {
            sum=node->right->data+node->left->data;
        }
        
        
        return (node->data==sum)&&isSumProperty(node->right)&&isSumProperty(node->left);
       
       
    }

