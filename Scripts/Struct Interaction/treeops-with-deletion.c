// This is a module to define a binary search tree, along with some functions to operate on the struct.
// This module has no main function, so do not compile it. Only use this module to be included to some other module.
// Do note of the treeops header and always be sure the directory points to the correct file.
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "header/treeops.h"

// 1
tree_t *make_empty_tree(int func(void *, void *)) {
    tree_t *tree;
    tree = malloc(sizeof(*tree));
    assert(tree != NULL);

    tree->root = NULL;
    tree->cmp = func;
    return tree;
}

int is_empty_tree(tree_t *tree) {
    assert(tree);
    return tree->root == NULL;
}

static void *recursive_search_tree(node_t *root, void *key, 
int cmp(void *, void *)) {
    int outcome;
    if (!root) return NULL;

    if ((outcome = cmp(key, root->data)) < 0) return 
    recursive_search_tree(root->left, key, cmp);
    
    else if (outcome > 0) return
    
    recursive_search_tree(root->right, key, cmp);
    else return root->data;
}
// 2
void *search_tree(tree_t *tree, void *key) {
    assert(tree != NULL);
    return recursive_search_tree(tree->root, key, tree->cmp);
}

static node_t *recursive_insert(node_t *, node_t *, int(void *, void *));

// 3
static node_t *recursive_insert(node_t *root, node_t *new, 
int cmp(void *, void *)) {
    int outcome;
    if (root == NULL) return new;

    else if (outcome = cmp(new->data, root->data) < 0) return
    root->left = recursive_insert(root->left, new, cmp);

    else return
    root->right = recursive_insert(root->right, new, cmp);

    return root;
}

// 4 
tree_t *insert_tree_in_order(tree_t *tree, void *value) {
    node_t *new;
    new = malloc(sizeof(*new));
    assert(tree != NULL && new != NULL);
    
    new->data = value;
    new->left = new->right = NULL;

    tree->root = recursive_insert(tree->root, new, tree->cmp);

    return tree;
}

static void recursive_traverse(node_t *, void action(void *));
// 5
static void recursive_traverse(node_t *root, void action(void *)) {
    if (root != NULL) {
        recursive_traverse(root->left, action);
        action(root->data);
        recursive_traverse(root->right, action);
    }
}

void traverse_tree(tree_t *tree, void action(void *)) {
    assert(tree != NULL);
    recursive_traverse(tree->root, action);
}

static void recursive_free_tree(node_t *);
// 6
static void recursive_free_tree(node_t *root) {
    if (root != NULL) {
        recursive_free_tree(root->left);
        recursive_free_tree(root->right);
        free(root);
    }
}