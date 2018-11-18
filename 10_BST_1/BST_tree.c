#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"BST_tree.h"



BST_TREE* create_bst(){

	BST_TREE* new_tree = (BST_TREE*)malloc(sizeof(BST_TREE));
	if(new_tree){
	new_tree -> count = 0;
	new_tree -> root = NULL;

	return new_tree;
	}
	else{
		return NULL;
	}
}


T_NODE* find_smallest_node(T_NODE* root){

	if(root->left == NULL)
		return root;
	else
		return find_smallest_node(root->left);
}

T_NODE* find_largest_node(T_NODE* root){
	
	if(root->right == NULL)
		return root;
	else
		return find_largest_node(root->right);

}

T_NODE* search_bst(T_NODE* root, int data){

	if(root == NULL)
		return NULL;

	if(data>(root->data))
		return search_bst(root->right,data);
	else if(data < (root->data))
		return search_bst(root->left,data);
	else
		return root;
}


void traverse_preorder(T_NODE* root) {
	
	if(root != NULL){
 	  printf("%d ",root->data);
	  traverse_preorder(root->left);
	  traverse_preorder(root->right);
	}
}

void traverse_inorder(T_NODE* root) {
	if(root != NULL) {
	  traverse_inorder(root->left);
	  printf("%d ",root->data);
	  traverse_inorder(root->right);
	}
}

void traverse_postorder(T_NODE* root) {
	if(root != NULL) {
	  traverse_postorder(root->left);
	  traverse_postorder(root->right);
	  printf("%d ",root->data);
	}
}


bool BST_insert(BST_TREE* tree, int data){

	T_NODE* newRoot;
	newRoot = add_bst(tree->root, data);

	if(newRoot == NULL) 
		return false;
	else {
		tree -> root = newRoot;
		(tree->count)++;
		return true;
	}
}


T_NODE* add_bst(T_NODE* root, int data){
	
	if(root == NULL) {
		T_NODE* newNode = 
			(T_NODE*)malloc(sizeof(T_NODE));
		newNode->left = NULL;
		newNode->right = NULL;
		newNode -> data = data;
		return newNode;
	}


	if(data<(root->data)){
		root -> left = add_bst(root->left,data);
		return root;
	}else {
		root -> right = add_bst(root->right, data);
		return root;
	}
}


bool BST_delete(BST_TREE* tree, int data){

	bool success;
	T_NODE* newRoot;
	
	newRoot = delete_bst(tree->root,data,&success);

	if(success){
		tree->root = newRoot;
		(tree->count)--;
		if(tree->count == 0)
			tree->root = NULL;
	}
	return success;
}

T_NODE* delete_bst(T_NODE* root, int data, bool* success) {
	
	T_NODE* delete_node;
	T_NODE* search;
	T_NODE* newRoot;

	if(root == NULL) {
		*success = false;
		return NULL;
	}

	
	if(data < (root->data))
	 root -> left = delete_bst(root->left,data, success);

	else if (data > (root->data))
	 root -> right = delete_bst(root->right,data,success);

	else{
	  delete_node = root;
		if(root->left == NULL) {
		newRoot = root -> right;
		free(delete_node);
		*success = true;
		return newRoot;
		}
		else if(root -> right == NULL) {
		newRoot = root -> left;
		free(delete_node);
		*success = true;
		return newRoot;
		}
		else{
		search = root -> left;
		while(search->right != NULL)
			search = search -> right;
		root -> data = search -> data;
		root -> left = delete_bst(root->left, search->data, success);
		}
	}

	return root;
}


BST_TREE* copy_tree(BST_TREE* tree){

	BST_TREE* newTree;
	newTree = (BST_TREE*)malloc(sizeof(BST_TREE));

	T_NODE* newRoot;
	newRoot = copy_bst(tree->root);

	if(newRoot == NULL)
		return NULL;
	else{

	newTree->root = newRoot;

	return newTree; }

}

T_NODE* copy_bst(T_NODE* root){


	if(root == NULL) 
		return NULL;
	else{
		T_NODE* copy;
		copy = (T_NODE*)malloc(sizeof(T_NODE));
		copy->data = root->data;
		copy->left = copy_bst(root->left);
		copy->right = copy_bst(root->right);

		return copy;
	}
}
