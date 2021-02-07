#include <vector>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val) {
    value = val;
    left = NULL;
    right = NULL;
  }

  BST &insert(int val) {
    // Write your code here.
    // Do not edit the return statement of this method.
		BST* cur = this; 
		while(true) {
			if(val < cur->value) {
				if(cur->left == NULL) {
					BST *newNode = new BST(val);
					cur->left = newNode;
				  break;	
				}
				else {
					cur = cur->left; 
				}
			}
			else {
				if(cur->right == NULL) {
					BST *newNode = new BST(val);
					cur->right = newNode;
					break; 
				}
				else {
					cur = cur->right; 
				}
			}
		}
		
    return *this;
  }

  bool contains(int val) {
    // Write your code here.
		BST *cur = this; 
		while(cur!=NULL) {
			if(val < cur->value){
				cur = cur->left; 
			}
			else if (val > cur->value) {
				cur = cur->right;
			}
			else {
				return true; 
			}
			
		}
		return false; 
  }
	
	

  BST &remove(int val, BST* parentnode = NULL) {
    // Write your code here.
    // Do not edit the return statement of this method.
		BST *currentnode = this; 
		while(currentnode!= NULL) {
			if(val < currentnode->value){
				parentnode = currentnode; 
				currentnode = currentnode->left; 
			}
			else if(val > currentnode->value){
				parentnode = currentnode; 
				currentnode = currentnode->right; 
			}
			else {
				if(currentnode->left != NULL && currentnode->right!= NULL) { //two child nodes are present
					currentnode->value = currentnode->right->getMin();  //Set current node as min of right subtree
					currentnode->right->remove(currentnode->value,currentnode);  //remove smallest element           
				}
				else if(parentnode == NULL) { //dealing with the root that does not have a parent
					if(currentnode->left != NULL){
						currentnode->value = currentnode->left->value; 
						currentnode->right = currentnode->left->right; 
						currentnode->left = currentnode->left->left; 
				 }
					else if(currentnode->right != NULL){
						 currentnode->value = currentnode->right->value; 
						currentnode->left = currentnode->right->left; 
						currentnode->right = currentnode->right->right; 
						
				 }
					else {
						currentnode->value = 0; 
					}
				}
				else if(parentnode->left == currentnode) //if child is left child
				{ parentnode->left = currentnode->left != NULL ? currentnode->left : currentnode->right; 
					}
			else if (parentnode->right == currentnode) {
				parentnode->right = currentnode->left != NULL ? currentnode->left : currentnode->right; 
			}
		break; 	
		}
		
	}
		
    return *this;
  }
	
	int getMin() {
		if(left == NULL) {
			return value; 
		}
		else {
			return left->getMin();
		}
		
	}
	
};
