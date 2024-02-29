#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct tree {
    int key;//datatype 
    struct tree *left, *right;
    struct tree *parent; // необязательное поле
} tree;

int max = 0;
int min = 1;



void preorder(tree *root)
{
	if(root == NULL)
		return;
    printf("%d ",root->key);
	if (max < root->key)
		max = root->key;
	if (min > root->key)
		min = root->key;
	if(root->left)//! NULL
		preorder(root->left);
	if(root->right)//! NULL
		preorder(root->right);
}

//uint32_t max_find(tree* root)
//{
    //uint32_t number, max=0;
    //if(number == 0)
        //return 0;
    //if (max < number)
        //max = number;
    //return max;
//}

void diff_find(int a, int b)\
{
	printf("\n");
	printf ("Difference  = %d - %d = ", a, b);
	printf ("%d", a - b);
}


int main(void)
{
    tree *tr = NULL;
    
    tr = calloc(1,sizeof(tree));
    tr->key = 10;
    
    tr->right = calloc(1,sizeof(tree));
    tr->right->key = 15;

    tr->left = calloc(1,sizeof(tree));
    tr->left->key = 5;

    tr->left->left = calloc(1,sizeof(tree));
    tr->left->left->key=3;

    tr->left->right = calloc(1,sizeof(tree));
    tr->left->right->key=7;

    tr->left->left->left = calloc(1,sizeof(tree));
    tr->left->left->left->key=1;    

    tr->left->right->left = calloc(1,sizeof(tree));
    tr->left->right->left->key=6;

    tr->right->left = calloc(1,sizeof(tree));
    tr->right->left->key = 13;
    
    tr->right->right = calloc(1,sizeof(tree));
    tr->right->right->key = 18;        
    
    printf("Preorder\n");
    preorder(tr);

	diff_find(max, min);

    return 0;
}
