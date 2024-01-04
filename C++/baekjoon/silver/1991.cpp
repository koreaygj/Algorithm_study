#include <bits/stdc++.h>
using namespace std;
class Tree{
    char root;
    Tree* left;
    Tree* right;
    public:
        Tree(){
            root = ' ';
            left = NULL;
            right = NULL;
        }
        void setRoot(char root){
            this -> root = root;
        }
        void setLeft(Tree* left){
            this -> left = left;
        }
        void setRight(Tree* right){
            this -> right = right;
        }
	    void static preorder(Tree* r) {
	    	if (r) {
	    		cout << r->root;
	    		preorder(r->left);
	    		preorder(r->right);
	    	}
	    }
    
	    void static inorder(Tree* r) {
	    	if (r) {
	    		inorder(r->left);
	    		cout << r->root;
	    		inorder(r->right);
	    	}
	    }
    
	    void static postorder(Tree* r) {
	    	if (r) {
	    		postorder(r->left);
	    		postorder(r->right);
	    		cout << r->root;
	    	}
	    }
};
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    Tree *tree = new Tree[n];
    for (int i = 0; i < n; ++i) {
        char root,left,right;
        cin >> root >> left >> right;
        if(root!='.')
            tree[(int)(root-'A')].setRoot(root);
        if (left != '.')
            tree[(int)(root - 'A')].setLeft(&tree[(int)(left - 'A')]);
        else
            tree[(int)(root - 'A')].setLeft(NULL);
        if (right != '.')
            tree[(int)(root - 'A')].setRight(&tree[(int)(right - 'A')]);
        else
            tree[(int)(root - 'A')].setRight(NULL);
    }
    Tree *root = &tree[0];
    Tree::preorder(root);
    cout << "\n";
    Tree::inorder(root);
    cout << "\n";
    Tree::postorder(root);
    cout << "\n";
}