#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure representing a node in the binary tree
typedef struct Node {
    int id;
    struct Node *left;
    struct Node *right;
} Node;

// Create a new node
Node *createNode(int id) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        perror("Failed to allocate memory for node");
        exit(EXIT_FAILURE);
    }
    newNode->id = id;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Add an edge to the binary tree
void addEdge(Node **nodes, int parent, int child) {
    if (!nodes[parent]) {
        nodes[parent] = createNode(parent);
    }
    if (!nodes[child]) {
        nodes[child] = createNode(child);
    }

    if (!nodes[parent]->left) {
        nodes[parent]->left = nodes[child];
    } else if (!nodes[parent]->right) {
        nodes[parent]->right = nodes[child];
    } else {
        fprintf(stderr, "Node %d already has two children!\n", parent);
        exit(EXIT_FAILURE);
    }
}

// Read the tree from the input file
Node *readTree(const char *filename, Node **nodes) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    int parent, child;
    while (fscanf(file, "(%d, %d)\n", &parent, &child) == 2) {
        addEdge(nodes, parent, child);
    }

    fclose(file);
    return nodes[1];  // Assume 1 is the root
}

// Check if the tree is complete
bool isComplete(Node *root, int index, int totalNodes) {
    if (!root) {
        return true;
    }
    if (index >= totalNodes) {
        return false;
    }
    return isComplete(root->left, 2 * index + 1, totalNodes) &&
           isComplete(root->right, 2 * index + 2, totalNodes);
}

// Get the number of nodes in the tree
int countNodes(Node *root) {
    if (!root) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Get the height of the tree
int getHeight(Node *root) {
    if (!root) {
        return -1;  // Height of an empty tree is -1
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Check if the tree is balanced
bool isBalanced(Node *root) {
    if (!root) {
        return true;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}

// Write the results to the output file
void writeResults(const char *filename, bool complete, int height, bool balanced) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open output file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Is the tree complete? %s\n", complete ? "Yes" : "No");
    fprintf(file, "What’s the height of the tree? %d\n", height);
    fprintf(file, "Is it balanced? %s\n", balanced ? "Yes" : "No");

    fclose(file);
}

int main() {
    const char *inputFile = "input.txt";
    const char *outputFile = "tree_properties.txt";

    // Assume node IDs are in the range [1, 100]
    Node *nodes[101] = {NULL};

    Node *root = readTree(inputFile, nodes);
    int totalNodes = countNodes(root);
    int height = getHeight(root);
    bool complete = isComplete(root, 0, totalNodes);
    bool balanced = isBalanced(root);

    writeResults(outputFile, complete, height, balanced);

    // Free memory (optional for this lab)
    for (int i = 1; i <= 100; i++) {
        if (nodes[i]) {
            free(nodes[i]);
        }
    }

    return 0;
}