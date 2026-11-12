#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>

struct BSTNode {
    int value;
    BSTNode* left;
    BSTNode* right;

    explicit BSTNode(int v = 0)
        : value(v), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST();
    ~BST();

    bool empty() const noexcept;
    std::size_t size() const noexcept;
    bool contains(int value) const;
    bool insert(int value);
    bool remove(int value);
    bool search(int value) const;
    int min() const;
    int max() const;
    int height() const;
    bool isBalanced() const;
    void clear();

    std::vector<int> inorder() const;
    std::vector<int> preorder() const;
    std::vector<int> postorder() const;
    std::vector<int> levelOrder() const;

private:
    BSTNode* root_;
    std::size_t size_;

    BSTNode* insertRecursive(BSTNode* node, int value);
    BSTNode* removeRecursive(BSTNode* node, int value);
    bool containsRecursive(const BSTNode* node, int value) const;
    bool searchRecursive(const BSTNode* node, int value) const;
    BSTNode* minNode(BSTNode* node) const;
    BSTNode* maxNode(BSTNode* node) const;
    int heightRecursive(const BSTNode* node) const;
    bool isBalancedRecursive(const BSTNode* node) const;
    void clearRecursive(BSTNode* node);

    void inorderRecursive(const BSTNode* node, std::vector<int>& values) const;
    void preorderRecursive(const BSTNode* node, std::vector<int>& values) const;
    void postorderRecursive(const BSTNode* node, std::vector<int>& values) const;
    void levelOrderRecursive(const BSTNode* node, std::vector<int>& values) const;
};
