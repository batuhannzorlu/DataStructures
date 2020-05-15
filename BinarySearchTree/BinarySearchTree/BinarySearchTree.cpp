
#include<iostream>
#include<queue>
using namespace std;

struct BstNode {
	int data;
	BstNode* left;
	BstNode* right;
};
 
// Function to create a new Node in heap
BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BstNode* FindMin(BstNode*root) {
	while (root->left != NULL) root = root->left;	
		return root;
}
BstNode* FindMax(BstNode*root) {

	if (root->right != NULL)
		return FindMin(root->right);
	else
		return root;
}
int FindHeight(BstNode*root)
{
	if (root == NULL)
		return-1;
	return __max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

// To insert data in BST, returns address of root node 
BstNode* Insert(BstNode* root, int data) {
	if (root == NULL) { // empty tree
		root = GetNewNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree. 
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	// else, insert in right subtree. 
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}
 BstNode* Delete(BstNode *root, int data) {
	if (root == NULL) return root;
	else if (data < root->data) root->left = Delete(root->left, data);
	else if (data > root->data) root->right = Delete(root->right, data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if (root->left == NULL) {
			BstNode *temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			 BstNode *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else {
			BstNode *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

//Function to visit nodes in Inorder
void Inorder( BstNode*root) {
	if (root == NULL) return;

	Inorder(root->left);        //Visit left subtree
	cout<< root->data;			//Print data
	Inorder(root->right);      // Visit right subtree
}
void LevelOrder(BstNode *root) {
	if (root == NULL) return;
	queue<BstNode*> Q;
	Q.push(root);
	while (!Q.empty()) {
		BstNode* current = Q.front();
		Q.pop(); // removing the element at front
		cout << current->data << " ";
		if (current->left != NULL) Q.push(current->left);
		if (current->right != NULL) Q.push(current->right);
	}
}
//Function to visit nodes in Preorder
void Preorder(BstNode *root) {
	if (root == NULL) return;

	cout << root->data; // Print data
	Preorder(root->left);     // Visit left subtree
	Preorder(root->right);    // Visit right subtree
}

//Function to visit nodes in Postorder
void Postorder(BstNode *root) {
	if (root == NULL) return;

	Postorder(root->left);    // Visit left subtree
	Postorder(root->right);   // Visit right subtree
	cout << root->data; // Print data
}
//To search an element in BST, returns true if element is found
bool Search(BstNode* root, int data) {
	if (root == NULL) 
		return false;	
	else if (root->data == data) 
		return true;	
	else if (data < root->data)
		return Search(root->left, data);	
	else 
		return Search(root->right, data);	
}


int main() {
	BstNode* root = NULL;  // Creating an empty tree
	/*Code to test the logic*/
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);
	// Ask user to enter a number.
	cout << "Min number of the tree: " << FindMin(root) << endl;
	cout << "Max number of the tree: " << FindMax(root) << endl;
	cout << "Height of the tree: " << FindHeight(root) << endl;

	cout << "LEVEL ORDER: " << endl;
	LevelOrder(root);
	cout << "INORDER ORDER: " << endl;
	Inorder(root);
	cout << "PREORDER ORDER: " << endl;
	Preorder(root);
	cout << "POSTORDER ORDER: " << endl;
	Postorder(root);


	int number;
	cout << "Enter number be searched\n";
	cin >> number;
	if (Search(root, number) == true) cout << "Found\n";
	else cout << "Not Found\n";
}
