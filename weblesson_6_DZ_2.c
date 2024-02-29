#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct tree {
    int key;//datatype 
    struct tree *left, *right;
    struct tree *parent; // необязательное поле
} tree;

int sum = 0;


void preorder(tree *root)
{
	if(root == NULL)
		return;
    printf("%d ",root->key);
    sum = sum + root->key;
	if(root->left)//! NULL
		preorder(root->left);
	if(root->right)//! NULL
		preorder(root->right);
}

//uint32_t sum_find(tree* root)
//{
	//uint32_t number, sum=0;
    //scanf("%u", &number);
    //if(number == 0)
        //return 0;
    //sum = sum+number;
    //return sum;
//}

void sum_print(int s)
{
	printf("\n");
	printf ("sum  = %d", s);
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

	sum_print(sum);

    return 0;
}
