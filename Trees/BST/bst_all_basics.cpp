#include<iostream>
#include <queue>
using namespace std;

class TreeNode{
	public:
		int value;
		TreeNode* left;
		TreeNode* right;
		
		TreeNode(){
			value = 0;
			left = NULL;
			right = NULL;
		}
		TreeNode(int v){
			value = v;
			left = NULL;
			right = NULL;
		}
};
class BST{
	//Initialization:
	
	public:
			TreeNode * root;
			
			BST(){
				root = NULL;
			}
			
			bool isTreeEmpty(){
				return root==NULL;
			}
	//Traversals:	
		
			void printPreorder(TreeNode * r) 
			{
				if (r == NULL)
					return;
				
				cout << r -> value << " ";
				printPreorder(r -> left);
				printPreorder(r -> right);
			}

			void printPostorder(TreeNode * r)
			{
				if (r == NULL)
					return;
				
				printPostorder(r -> left);
				printPostorder(r -> right);
				cout << r -> value << " ";
			}

			void printInorder(TreeNode * r)
			{
				if (r == NULL)
					return;
				
				printInorder(r -> left);
				cout << r -> value << " ";
				printInorder(r -> right);
			}
	
	// Breadth First Order BFS , Print in Level Order:
		
			void printLevelOrderBFS(TreeNode * r){
				int h = hieght(r);
				for(int i=0;i<=h;i++){
					printGivenLevel(r,i);
				}
			}
			
			void printGivenLevel(TrreNode * r, int level){
				if(r==NULL)
					return;
				else if(level == 0)
					cout<< r->value << " ";
				else{
					printGivenLevel(r->left , level-1);
					printGvenLevel(r->right, level-1);
				}
			}
	
	// BFS using Queues:
			
			void printBFS(TreeNode* root) {
			    if (root == nullptr) return;
			
			    queue<TreeNode*> q;
			    q.push(root);
			
			    while (!q.empty()) {
			        TreeNode* current = q.front();
			        q.pop();
			
			        cout << current->key << " ";
			
			        if (current->left != nullptr) {
			            q.push(current->left);
			        }
			
			        if (current->right != nullptr) {
			            q.push(current->right);
			        }
			    }
			}
			
	//Insertions:
	
			void insertIteratively(TreeNode * newNode){
				if(root == NULL){
					root == newNode;
					cout<<"Node Inserted as Root"<<endl;
					return;
				}
				else{
					while(temp!=NULL){
						if(temp->value == newNode->value){
							cout<<"VALUE ALREADY EXISTS, DUPLICATES NOT ALLOWED!"<<endl;
							return;
						}
						else if(newNode->value < temp->value){
							if(temp->left == NULL){
								cout<<"Value Inserted to Left!"<<endl;
								temp->left = newNode;
								break;
							}
							else{
								temp=temp->left;
							}
						}
						else{
							if(temp->left == NULL){
								cout<<"Value Inserted to Right!"<<endl;
								temp->right = newNode;
								break;
							}
							else{
								temp=temp->right;
							}
						}
					}
				}
			}
					
			TreeNode* insertRecursively(TreeNode* root, int val) {
			    if (root == NULL) {
			        return new TreeNode(val);
			    }
			    else if (val < root->val) {
			        root->left = insertRecursively(root->left, val);
			    } else if (val > root->val) {
			        root->right = insertRecursively(root->right, val);
			    }
			
			    return root;
			}
			
		//Searching:
			
			TreeNode* iterativeSearch(int v){
				if(root==NULL)
					return root;
				
				else{
					TreeNode* temp = root;
					while(temp!=NULL){
						if(v == temp->value){
							return temp;
						}
						else if(v < temp->value){
							temp = temp->left;
						}
						else if(v> temp->value){
							temp = temp->right;
						}
					}
					return NULL;
				}
			}			
			
			TreeNode * recursiveSearch(TreeNOde * r, int val){
				if(r == NULL || r->value == val){
					return r;
				}
				else if(val < r->value){
					return recursiveSearch(r->left,val);
				}
				else if(val > r->value){
					return recursiveSearch(r->right,val);
				}	
			}
		
		// hieght:
			
			int height(TreeNode * r){
				if(r==NULL)
					return -1;
				else{
					int lheight = height(r->left);
					int rheight = height(r->right);
					
					if(lhieght > rheight)
						return lhieght+1;
					else
						return rhieght+1;
				}
			}
			
		// MIN and MAX Value:
			
			TreeNode* minValue(TreeNode * root){
				TreeNode * temp = root;
				while(temp ->left!=NULL){
					temp = temp->left;
				}
				return temp;
			}
			
			TreeNode* minValue(TreeNode * root){
				TreeNode * temp = root;
				while(temp ->left!=NULL){
					temp = temp->left;
				}
				return temp;
			}
};
