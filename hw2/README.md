<h2 style='background:deeppink; border:0; color:white'><center>BinaryTree</center></h2>

<p> <b>Student name: </b>Mohammed Obidou</p>
<p> <b>Student Id: </b> 11920016</p>
<p> <b>Homework: </b>2</p>

---

<br>
<blockquote>
<ul>
<li>Binary tree is data structure in which each node has at most two children</li>
<li>The two nodes are <b>Right child & Left child</b></li>
<li>The topmost node is the root node (the parent)</li>
<li><b>Used for</b> </li>

<ol>
<li>representing hierarchical representations between two data</li>
<li>Searching and sorting data</li>
<li>Construction data compression algorithm</li>
<li>In OS they're often used in the implementation of process scheduling algorithm, Specifically the binary tree data structure can be used to maintain a sorted list of processes</li>
</ol>

<br>
<li> the root of the tree representing the highest priority process in the system. As new processes are created or existing processes are preempted, the binary tree can be updated to maintain the correct ordering of processes. This allows the operating system to efficiently select the next process to run, based on its priority, without having to search through all processes in the system each time a scheduling decision needs to be made.</li>
<li>In addition, binary trees can be used in file systems to represent the hierarchical structure of directories and files. Each node in the tree corresponds to a directory or file, and the left and right children of a node represent its subdirectories and files, respectively. This allows for efficient traversal and searching of the file system.</li>
</ul>
</blockquote>


<h2 style='background:deeppink; border:0; color:white'><center>Code Explanation</center></h2>
Let's separate the code into blocks
<blockquote>

```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a node structure for the binary tree
struct Node { //Root node
    int data;
    struct Node* left; //Left node
    struct Node* right; //Right node
};

// Define a BinaryTree structure that contains a pointer to the root node
struct BinaryTree {
    struct Node* root; //Tree consists of root nodes
};

```
<ol type='i'>
<li>We first start with importing some libraries.</li>
<li>Recall that a a tree consist of a <b>Root node</b> and it has 2 nodes the left node and right node</li>
<li>So let's define a node structure that has a left node and a right node. The right node and left node has to be an extension of the Node structure itself.</li>
<li>Now we can create a BinaryTree structure Recall that A tree consists of a Root node that contains 2 nodes <b>AT MOST</b>.</li>
</ol>
</blockquote>

---
<blockquote>

```c
// Traverse the binary tree in-order and print each node's data
void tra_order(struct Node* node) {
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

```

<ol type='I'>

<li>Think of this as while=True. this will run through each node in order until none</li>
<li>recursively Iterate over the entire tree, and print the data in each node</li>
<li>first we assume that the first node to reach is the left node, so we print it's data and set node to right so on the next iteration we can go through the right node</li>
<li>else we set the node to left note there's multiple ways of approaching im just following the Morris traversal type.</li>
<li>Now while the right node isn't empty and it's not a node well then we've to to set the node to right this is a contingency.</li>
<li>next is the data of the right nodes if iterated over all then we set the pre node which is the priority to the right node else we print the right node data.</li>

</ol>
</blockquote>

---

<blockquote>

```c
// Insert a new node with the given data into the binary tree
void insert_node(struct BinaryTree* tree, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (tree->root == NULL) {
        tree->root = new_node;
    } else {
        struct Node* current = tree->root;
        struct Node* parent = NULL;
        while (1) {
            parent = current;
            if (data < current->data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = new_node;
                    return;
                }
            } 
            else {
                current = current->right;
                if (current == NULL) {
                    parent->right = new_node;
                    return;
                }
            }
        }
    }
}

```
<ul>
<li>Now that we've a method to iterate in order of priority of a process</li>
<li>We've to assume what the binaryTree should do in case of a new process</li>
<li>The function must evaluate the process's priority and insert the new node or process in the correct position. </li>
<li>Now we've to allocate memory for the new node. </li>
<li>but we also have to consider if BT is empty then we set it's pointer to null.</li>
<li> Define the new node's data</li>
<li>Initialize the left and right nodes</li>
<li>if the node 'The root' is empty assign it to an empty new node</li>
<li>The same logic applies we've to search in order to decide the position of the new node</li>
<li>Starting from the beginning we check if the data of the new node is less than the data of the current node if so set the current node to the left node then check if it's null if so then the root node's left node is assigned the new node. In simpler words we check for an empty or a node with less priority </li>
<li>Repeat for the right node as well</li>
</ul>
</blockquote>

---

<blockquote>

```c
// Search for a node with the given data in the binary tree and return a pointer to that node
struct Node* search(struct BinaryTree* tree, int data) {
    struct Node* current = tree->root;
    while (current != NULL && current->data != data) {
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return current;
}

```
<ol type='I'>
<li>Recall earlier in the explanation of binaryTree is that it's also used Searching and sorting data</li>
<li>This is exactly what we're doing in this method</li>
<li>Assuming we need to find a node with the specified data</li>
<li>Ofcourse the dataType of the method will be a Node object</li>
<li>Parameters are a binaryTree and data</li>
<li>Start at Root node. while the node isn't empty & it doesn't contain the data we're looking for in other words it's not the target</li>
<li>If the root data is also bigger then pass to the left node</li>
<li>else pass to the right node</li>
<li>The while loop will terminate and return the target node when it's found</li>
</ol>
</blockquote>

---

<blockquote>

```c
// Thread function for inserting random values into the binary tree
void* insert_thread(void* arg) {
    struct BinaryTree* tree = (struct BinaryTree*)arg;
    int i;
    for (i = 0; i < 10; i++) {
        int value = rand() % 100;
        printf("Inserting process: %d\n", value);
        insert_node(tree, value);
        printf("\n The new BinaryTree:\n");
        tra_order(tree->root);
        printf("\n");
    }
    pthread_exit(NULL);
}
```
<ol type='I'>
<li>In order to simulate your processes, you can insert and search random
values at a time.</li>
<li>So according to the instructions we define a tree</li>
<li>Iterate for 10 times</li>
<li>Define a random value ranging between 0 and 100</li>
<li>Call our insertion function first value since the Tree is empty it will be The first node</li>
<li>Print the new BinaryTree by calling our Morris traversal method</li>
</ol>
</blockquote>