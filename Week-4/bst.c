#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct node* find_min(struct node* root)
{
    while(root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct node* insert(struct node* root, int x)
{
    if(root == NULL)
    {
        return create_node(x);
    }
    if(x < root->data)
    {
        root->left = insert(root->left,x);

    }
    else if(x > root->data)
    {
        root->right = insert(root->right,x);
    }

    return root;
}

struct node* search(struct node*root, int x)
{
    if(root == NULL || root->data == x)
    {
        return root;
    }
    if(root->data < x)
    {
        return search(root->right, x);
    }
    return search(root->left, x);
}

struct node* delete_node(struct node* root, int x)
{

    if (root == NULL)
    return root;

    else if(x < root->data)
    {
        root->left = delete_node(root->left, x);
        
    }

    else if(x > root->data)
    {
        root->right = delete_node(root->right, x);
    }
    else
    {
        if(root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }

    return root;
}

void inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postorder(struct node* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void preorder(struct node* root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    struct node* root = NULL;
    int ch, val;
    struct node* found = NULL;

    while(1)
    {
        printf("\nBST MENU\n1.Insert\n2.Search\n3.Delete\n4.Traversal\n5.Exit\nEnter your choice:\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter value to insert :\n");
                scanf("%d",&val);

                root = insert(root,val);
                printf("Inserted %d\n", val);

                break;

            case 2:
                printf("Enter value to search :\n");
                scanf("%d",&val);

                found = search(root,val);
                if(found != NULL)
                {
                    printf("Element %d found ", val);
                }
                else
                {
                    printf("Element %d not found ", val);
                }
                break;

            case 3:
                printf("Enter value to delete :\n");
                scanf("%d",&val);

                root = delete_node(root,val);
                printf("Deleted %d\n", val);

                break;

            case 4:
                if(root ==NULL)
                {
                    printf("Tree is empty\n");
                }
                else
                {
                    printf("Preorder Traversal:\n");
                    preorder(root);
                    printf("\n");

                    printf("Inorder Traversal:\n");
                    inorder(root);
                    printf("\n");

                    printf("Postorder Traversal:\n");
                    postorder(root);
                    printf("\n");
                }
                break;

            case 5:
                printf("Exitting...\n");
                exit(0);

            default:
                printf("Invalied input\n");
        }
    }
    return 0;
}
