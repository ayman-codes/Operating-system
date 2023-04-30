// Read README file from github.com for full documentation
// https://github.com/ayman-codes/Operating-system/tree/master/hw2

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

// Define a node structure for the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Define a BinaryTree structure that contains a pointer to the root node
struct BinaryTree {
    struct Node* root;
};

// Traverse the binary tree in-order and print each node's data
// Traverse the binary tree in-order and print each node's data
void trav_order(struct Node* node) {
    while (node != NULL) {
        if (node->left == NULL) {
            printf("%d ", node->data);
            node = node->right;
        } 
        else {
            struct Node* pre = node->left;
            while (pre->right != NULL && pre->right != node) {
                pre = pre->right;
            }
            if (pre->right == NULL) {
                pre->right = node;
                node = node->left;
            } else {
                pre->right = NULL;
                printf("%d ", node->data);
                node = node->right;
            }
        }
    }
}

// Insert a new node with the given data into the binary tree
void insert_node(struct BinaryTree* tree, int data) {

    //define the node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    //node's parameters
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    //if root is null then assign the new node to the root
    if (tree->root == NULL) {
        tree->root = new_node;
    } 
    else {
        //Check for each root and if the data are larger than the current
        //assign the current node (to be searched) to the child left node
        //if it's also null then make it a root and assign data to it
        struct Node* current = tree->root;
        struct Node* root = NULL;
        
        while (true) {
            root = current;
            if (data < current->data) {
                current = current->left;
                if (current == NULL) {
                    root->left = new_node;
                    return;
                }
            } 
            else {
                current = current->right;
                if (current == NULL) {
                    root->right = new_node;
                    return;
                }
            }
        }
    }
}

// Search for a node with the given data in the binary tree and return a pointer to that node
struct Node* search(struct BinaryTree* tree, int data) {
    struct Node* current = tree->root;

    //not the target
    for (; current != NULL && current->data != data; ) {
        if (data < current->data) {
            current = current->left; //look in the left node
        } 

        else {
            current = current->right; // look in the right node
        }
    }
    return current; //reached target return
}

// Thread function for inserting random values into the binary tree
void* insert_thread(void* arg) {
    struct BinaryTree* tree = (struct BinaryTree*)arg;

    int i = 0;
    while (i < 10) {
        int value = rand() % 100;
        printf("Inserting node: %d\n", value);

        //assign the new value to the tree
        // by calling the insert method
        insert_node(tree, value);
        printf("Tree after insertion:\n");

        //call traverse printing method
        trav_order(tree->root);
        printf("\n\n");
        i++;
    }
    pthread_exit(NULL);
}


// Thread function for searching random values in the binary tree
void* search_thread(void* arg) 
{
    struct BinaryTree* tree = (struct BinaryTree*)arg;

    int i;
    for (i = 0; i < 10; i++) {

        //create 10 random values range 0-100
        int value = rand() % 100;

        //search for that value using search method
        printf("Searching for %d...\n", value);
        struct Node* result = search(tree, value);

        //if node doesn't exist 
        if (result == NULL) {
            printf("%d not found in tree\n\n", value);
        } 
        else {
            printf("%d found in tree\n\n", value);
        }
    }
    pthread_exit(NULL);//found target 
}

// Helper function to print spaces
void print_spaces(int count) {

    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

// my miserable attempt at Printing binary tree as a tree structure
void print_tree(struct Node* node, int level) {
    if (node != NULL) {
        print_tree(node->right, level + 1);

        int i;
        for (i = 0; i < level; i++) {
            printf("\t");
        }
        printf("%d\n", node->data);

        print_tree(node->left, level + 1);
    }
}

int main() {

    // Initialize the binary tree
    struct BinaryTree tree = {.root = NULL};

    // Initialize the random seed
    srand(time(NULL));

    // Create the threads
    pthread_t threads[2];
    if (pthread_create(&threads[0], NULL, insert_thread, (void*)&tree)) {
        fprintf(stderr, "Error creating insert thread\n");
        return 1;
    }

    //search if exist
    if (pthread_create(&threads[1], NULL, search_thread, (void*)&tree)) {
        fprintf(stderr, "Error creating search thread\n");
        return 1;
    }

    // Wait for the threads to finish
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the tree
    print_tree(tree.root, 0);

    return 0;
}
