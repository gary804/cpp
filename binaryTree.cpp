#include <iostream>
#include <climits>

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};
int lookup(struct node* tree, int target);
struct node* newNode(int data);
struct node* insert(struct node* tree, int data);
int size(struct node* node);
int maxDepth(struct node* node);
int minValue(struct node* node);
int minValueIterate(struct node* node);
int maxValue(struct node* node);
int maxValueIterate(struct node* node);
void printTree(struct node* node);
void printPostorder(struct node* node);
int hasPathSum(struct node* node, int sum);
void printPaths(struct node* node);
void printPathsHelp(struct node* node, int* data, int datalength);
void mirror(struct node* node);
void doubleTree(struct node*);
int sameTree(struct node* a, struct node* b);
long countTrees(int n);
int isBST1(struct node* node);
int isBST2(struct node* node);
struct node* treeToList(struct node* root);
void printList(struct node* head);

main(){
	struct node* root=NULL;
	int data[] = {4,2,1,3,6,5,0};
	int datasize= ARRAY_SIZE(data);
	for (int i=0; i<datasize; ++i){
		root = insert(root, data[i]);
	}
	cout <<"The tree 1 is ";
	printTree(root);
	cout<<"\b\b."<<endl;
	
	struct node* root1=NULL;
	int data1[] = {4,2,1,3,6,5,0,7};
	int datasize1= ARRAY_SIZE(data1);
	for (int i=0; i<datasize1; ++i){
		root1 = insert(root1, data1[i]);
	}
	cout <<"The tree 2 is ";
	printTree(root1);
	cout<<"\b\b."<<endl;
	
	cout<<((sameTree(root, root1))?"Yes, they are same tree.":"No, they are different tree")<<endl;

	cout <<"The tree size is "<< size(root)<<"."<<endl;
	
	cout <<"The tree maxDepth is "<< maxDepth(root)<<"."<<endl;
	
	cout <<"The tree minvalue is "<< minValue(root)<<"."<<endl;
	cout <<"The tree minvalue is "<< minValueIterate(root)<<"."<<endl;
	
	cout <<"The tree maxvalue is "<< maxValue(root)<<"."<<endl;
	cout <<"The tree maxvalue is "<< maxValueIterate(root)<<"."<<endl;
	
	cout <<"The tree post order is ";
	printPostorder(root);
	cout<<"\b\b."<<endl;
	
	cout<<"Is there 7 of PathSum? "<<(hasPathSum(root, 7)?"yes":"no")<<endl;
	cout<<"Is there 8 of PathSum? "<<(hasPathSum(root, 8)?"yes":"no")<<endl;
	cout<<"Is there 9 of PathSum? "<<(hasPathSum(root, 9)?"yes":"no")<<endl;
	cout<<"Is there 15 of PathSum? "<<(hasPathSum(root, 15)?"yes":"no")<<endl;
	
	cout<<"The tree paths are:"<<endl;
	printPaths(root);

	//cout<<"The tree is BST? "<<isBST1(root)<<endl;
	cout<<"The tree is BST? "<<isBST2(root)<<endl;

	mirror(root);
	cout <<"The mirror tree is ";
	printTree(root);
	cout<<"\b\b."<<endl;

	//cout<<"The mirror tree is BST? "<<isBST1(root)<<endl;
	cout<<"The mirror tree is BST? "<<isBST2(root)<<endl;
	
	cout <<"The tree post order is ";
	printPostorder(root);
	cout<<"\b\b."<<endl;

	doubleTree(root);
	printTree(root);
	cout<<"\b\b."<<endl;
	
	cout<<"For 4 kind of data, the different kind of tree are "<<countTrees(4)<<endl;

	struct node* list = treeToList(root1);
	printList(list);
	
}

int lookup(struct node* tree, int target){
	if(tree==NULL) return 0;
	if(tree->data==target) return 1;
	if(target<tree->data){
		return lookup(tree->left, target);
	} else {
		return lookup(tree->right, target);
	}
}
struct node* newNode(int data){
	struct node* anode = new (struct node);
	anode->data = data;
	anode->left = NULL;
	anode->right = NULL;
}
struct node* insert(struct node* node, int data){
	//cout<<"insertok0?"<<endl;
	if(node==NULL) return newNode(data);
	//cout<<"insertok1?"<<endl;
	if(data<=node->data) {
	//cout<<"insertok2?"<<endl;
		node->left = insert(node->left, data);
	//cout<<"insertok3?"<<endl;
	} else {
	//cout<<"insertok4?"<<endl;
		node->right = insert(node->right, data);
	//cout<<"insertok5?"<<endl;
	}
	//cout<<"insertok6?"<<endl;
	return node;
}
int size(struct node* node) {
	int nodes=0;
	if (node==NULL) return 0;
	nodes = 1 + size(node->left) + size(node->right);
	return nodes;
}
int maxDepth(struct node* node) {
	if (node==NULL) return 0;
	int lnodes=maxDepth(node->left);
	int rnodes=maxDepth(node->right);
	if (lnodes>=rnodes) return lnodes+1;
	else return rnodes+1;
}
int minValue(struct node* node) {
	if(node->left==NULL) return node->data;
	else return minValue(node->left);
}
int minValueIterate(struct node* node) {
	while(node->left!=NULL) node= node->left;
	return node->data;
}
int maxValue(struct node* node) {
	if(node->right==NULL) return node->data;
	else return maxValue(node->right);
}
int maxValueIterate(struct node* node) {
	while(node->right!=NULL) node= node->right;
	return node->data;
}
void printTree(struct node* node) {
	if (node==NULL) return;
	printTree(node->left);
	cout << node->data<<", ";
	printTree(node->right);
}
void printPostorder(struct node* node) {
	if (node==NULL) return;
	printTree(node->left);
	printTree(node->right);
	cout << node->data<<", ";
}
int hasPathSum(struct node* node, int sum){
	if (node==NULL) {
		return false;
	}
	//cout<<"sum="<<sum<<", "<<"node->data="<<node->data<<", ";
	sum = sum - node->data;
	if (node->left==NULL&&node->right==NULL) {
		if (sum==0) {
	//		cout<<"NodeData="<<node->data<<"Yes"<<endl;
			return true;
		} else return false;
	}
	//cout<<"new sum="<<sum<<endl;
	return (hasPathSum(node->left,sum)||hasPathSum(node->right,sum));
//	int left = hasPathSum(node->left,sum);
//	cout <<node->data<<"lefy="<<left<<endl;
//	int right = hasPathSum(node->right,sum);
//	cout <<node->data<<"right="<<right<<endl;
//	return left ||right;
}
void printPaths(struct node* node){
	int maxdepth = maxDepth(node);
	int* data = new int[maxdepth];
	int datalength = 0;
	if(node==NULL) return;
	printPathsHelp(node, data, datalength);
	if(maxdepth==1) delete data; else delete[] data;
}
void printPathsHelp(struct node* node, int* data, int datalength){
	data[datalength++]=node->data;
	if(node->left==NULL&&node->right==NULL){
		for (int i=0; i<datalength;++i){
			cout<<data[i]<<", ";
		}
		cout<<endl;
	} else {
		if (node->left!=NULL){
			printPathsHelp(node->left, data, datalength);
		} 
		if (node->right!=NULL){
			printPathsHelp(node->right, data, datalength);
		} 
	}

}
void mirror(struct node* node){
	if (node==NULL) return;
	struct node* temp = node->left;
	node->left=node->right;
	node->right=temp;
	mirror(node->left);
	mirror(node->right);
}
void doubleTree(struct node* node) {
	if(node==NULL){
		return;
	}
	struct node* temp = new (struct node);
	temp->data = node->data;
	temp->left = node->left;
	node->left = temp;
	temp->right = NULL;
	doubleTree(temp->left);
	doubleTree(node->right);
}
int sameTree(struct node* a, struct node* b){
	if (a==NULL&&b==NULL) return true;
	if (a==NULL) return false;
	if (b==NULL) return false;
	if (a->data!=b->data) return false;
	return (sameTree(a->left, b->left)&&sameTree(a->right,b->right));
}
long countTrees(int numKeys){
	if (numKeys==1) return 1;
	else return numKeys * countTrees(numKeys-1);	//take one from n candidates, there are n options.
}
int minValueBinaryPlainTreeHelp(struct node* node, int minvalue){
	if(node->left==NULL&&node->right==NULL){
		return min(node->data,minvalue);
	} else if(node->left!=NULL&&node->right!=NULL){
		return min( minValueBinaryPlainTreeHelp(node->left, min(node->data,minvalue) ), minValueBinaryPlainTreeHelp(node->right,min(node->data,minvalue)));
	} else if(node->left!=NULL){
		return minValueBinaryPlainTreeHelp(node->left,min(node->data,minvalue));
	} else if(node->right!=NULL){
		return minValueBinaryPlainTreeHelp(node->right,min(node->data,minvalue));
	}
	
}
int minValueBinaryPlainTree(struct node* node) {
	if(node->left==NULL&&node->right==NULL){
		return node->data;
	} else if(node->left!=NULL&&node->right!=NULL){
		return min(minValueBinaryPlainTreeHelp(node->left, node->data),minValueBinaryPlainTreeHelp(node->right, node->data));
	} else if(node->left!=NULL){
		return minValueBinaryPlainTreeHelp(node->left, node->data);
	} else if(node->right!=NULL){
		return minValueBinaryPlainTreeHelp(node->right, node->data);
	}
}
int maxValueBinaryPlainTreeHelp(struct node* node, int maxvalue) {
	if(node->left==NULL && node->right==NULL){
		return max(node->data, maxvalue);
	} else if(node->left!=NULL && node->right!=NULL){
		return max( maxValueBinaryPlainTreeHelp(node->left, max(node->data, maxvalue)),maxValueBinaryPlainTreeHelp(node->right, max(node->data, maxvalue)) );
	} else if(node->left!=NULL){
		return maxValueBinaryPlainTreeHelp(node->left, max(node->data, maxvalue));
	}else if(node->right!=NULL){
		return maxValueBinaryPlainTreeHelp(node->right, max(node->data, maxvalue));
	}
}
int maxValueBinaryPlainTree(struct node* node) {
	if(node->left==NULL && node->right==NULL){
		return node->data;
	} else if(node->left!=NULL && node->right!=NULL){
		return max( maxValueBinaryPlainTreeHelp(node->left, node->data),maxValueBinaryPlainTreeHelp(node->right, node->data) );
	} else if(node->left!=NULL){
		return maxValueBinaryPlainTreeHelp(node->left, node->data);
	}else if(node->right!=NULL){
		return maxValueBinaryPlainTreeHelp(node->right, node->data);
	}
}
int isBST1(struct node* node) {
	if (node==NULL) {
		cout<<"node is null\n";
		return false;
	}
	if (node->left==NULL&&node->right==NULL) {
		cout<<node->data<<" node is a leaf\n";
		return true;	
	} 
	if (node->left!=NULL&&node->right!=NULL) {
		if (node->data < maxValueBinaryPlainTree(node->left)){
			cout<<node->data<<" node is less than maxvalue of leftTree: "<< maxValueBinaryPlainTree(node->left)<<endl;
			return false;	
		} 
		if (node->data >= minValueBinaryPlainTree(node->right)){
			cout<<node->data<<" node <= minvalue of right subtree: "<<minValueBinaryPlainTree(node->right)<<endl;
			return false;
		} 
		cout <<node->data <<" node: check the left and right subtrees: " << (int)( isBST1(node->left) && isBST1(node->right) ) <<endl;
		return ( isBST1(node->left) && isBST1(node->right) );
	} else if ( node->left != NULL ) {
		if (node->data < maxValueBinaryPlainTree(node->left)){
			cout<<node->data<<" node < maxvalue of left subtree: "<<maxValueBinaryPlainTree(node->left)<<endl;
			return false;
		} 
		cout<<node->data<<" node, check the left subtree: "<<isBST1(node->left)<<endl;
		return isBST1(node->left);
	} else if (node->right) {
		if (node->data >= minValueBinaryPlainTree(node->right)){
			cout<<node->data<<" node < minvalue of right subtree: "<<minValueBinaryPlainTree(node->right)<<endl;
			return false;
		} 
		cout<<node->data<<" node, check the right subtree: "<<isBST1(node->right)<<endl;
		return isBST1(node->right);
	}
}
/*
Returns true if the given tree is a BST and its
values are >= min and <= max.
*/
int isBSTRecur(struct node* node, int min, int max) {
	if (node->left==NULL && node->right==NULL){
		if(node->data>=min &&node->data<=max){
			return true;
		} else {
			return false;
		}
	} else if(node->left!=NULL && node->right!=NULL){
		if(node->data< min || node->data>max){
			return false;
		} 
		return ( isBSTRecur(node->left, min, node->data) && isBSTRecur(node->right, node->data, max) );
	} else if (node->left!=NULL){
		return ( isBSTRecur(node->left, min, node->data) );
	} else if (node->right!=NULL) {
		return ( isBSTRecur(node->right, node->data, max) );
	}
}
/*
Returns true if the given tree is a binary search tree
(efficient version).
*/
int isBST2(struct node* node) {
	return(isBSTRecur(node, INT_MIN, INT_MAX));
}
//-----------------------------------------------------
//tree to list process:

//the node is treated as a list's node.
void join(struct node* a, struct node* b){
	// new list: ...a,b...
	a->right = b;	//here right is next in double link list
	b->left = a;	//here left is previous in double link list
}
//Here node is treated as a double link list.
struct node* append(struct node* a, struct node* b){
	if (a==NULL) return b;
	if (b==NULL) return a;

	struct node* aLast = a->left;
	struct node* bLast = b->left;
	//join the two together to make it connected and circular
	join(aLast, b); 
	join(bLast, a);
	return a;
}
struct node* treeToList(struct node* root){
	if (root==NULL) {
		return NULL;
	}
	struct node* leftList = treeToList(root->left);
	struct node* rightList = treeToList(root->right);
	//make root as a single node list
	root->left=root;
	root->right=root;
	leftList = append(leftList, root);
	leftList = append(leftList, rightList);
	return leftList;
}
void printList(struct node* head){
	if(head==NULL) cout <<"Null list"<<endl;
	struct node* current = head;
	do{
		cout<<current->data<<", ";
		current= current->right;
	} while(current != head);
	cout<<endl;
}