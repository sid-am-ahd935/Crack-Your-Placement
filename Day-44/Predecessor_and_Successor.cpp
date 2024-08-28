/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution {
public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        if(root==NULL)return;
        
        if(root->key > key){
            if(!suc || suc && suc->key>root->key){
                suc=root;
            }
        }
        else if(root->key < key){
            if(!pre || pre && pre->key<root->key){
                pre=root;
            }
        }
        
        findPreSuc(root->left,pre,suc,key);
        findPreSuc(root->right,pre,suc,key);
        
    }
};
