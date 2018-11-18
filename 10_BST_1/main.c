#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"BST_tree.h"

int main(){

BST_TREE* tree = create_bst();

int a = 10;
int b = 20;
int c = 30;
int d = 40;
int e = 50;
int f = 60;


BST_insert(tree,c);
BST_insert(tree,e);
BST_insert(tree,b);
BST_insert(tree,a);
BST_insert(tree,f);
BST_insert(tree,d);


T_NODE* k;
k = find_smallest_node(tree->root);
printf("smallest is %d\n",k->data);


k = find_largest_node(tree->root);
printf("largest is %d\n",k->data);

k = search_bst(tree->root, 20);
printf("search is %d\n",k->data);

printf("preorder\n");
traverse_preorder(tree->root);
printf("\n");
printf("inorder\n");
traverse_inorder(tree->root);
printf("\n");
printf("postorder\n");
traverse_postorder(tree->root);
printf("\n");


BST_TREE* copy = copy_tree(tree);
printf("copy preorder\n");
traverse_preorder(copy->root);
printf("\n");

}

