#include "project/bst.h"

#include <algorithm>
#include <queue>
#include <stdexcept>

BST::BST() : root_(nullptr), size_(0) {}

BST::~BST() {
    clear();
}

bool BST::empty() const noexcept {
    return size_ == 0;
}

std::size_t BST::size() const noexcept {
    return size_;
}

bool BST::contains(int value) const {
    (void)value;
    throw std::logic_error("Student implementation required: contains");
}

bool BST::insert(int value) {
    (void)value;
    throw std::logic_error("Student implementation required: insert");
}

bool BST::remove(int value) {
    (void)value;
    throw std::logic_error("Student implementation required: remove");
}

bool BST::search(int value) const {
    (void)value;
    throw std::logic_error("Student implementation required: search");
}

int BST::min() const {
    if (empty()) {
        throw std::logic_error("BST is empty");
    }
    return minNode(root_)->value;
}

int BST::max() const {
    if (empty()) {
        throw std::logic_error("BST is empty");
    }
    return maxNode(root_)->value;
}

int BST::height() const {
    return heightRecursive(root_);
}

bool BST::isBalanced() const {
    return isBalancedRecursive(root_);
}

void BST::clear() {
    clearRecursive(root_);
    root_ = nullptr;
    size_ = 0;
}

std::vector<int> BST::inorder() const {
    std::vector<int> values;
    inorderRecursive(root_, values);
    return values;
}

std::vector<int> BST::preorder() const {
    std::vector<int> values;
    preorderRecursive(root_, values);
    return values;
}

std::vector<int> BST::postorder() const {
    std::vector<int> values;
    postorderRecursive(root_, values);
    return values;
}

std::vector<int> BST::levelOrder() const {
    std::vector<int> values;
    levelOrderRecursive(root_, values);
    return values;
}

BSTNode* BST::insertRecursive(BSTNode* node, int value) {
    (void)node;
    (void)value;
    throw std::logic_error("Student implementation required: insertRecursive");
}

BSTNode* BST::removeRecursive(BSTNode* node, int value) {
    (void)node;
    (void)value;
    throw std::logic_error("Student implementation required: removeRecursive");
}

bool BST::containsRecursive(const BSTNode* node, int value) const {
    (void)node;
    (void)value;
    throw std::logic_error("Student implementation required: containsRecursive");
}

bool BST::searchRecursive(const BSTNode* node, int value) const {
    (void)node;
    (void)value;
    throw std::logic_error("Student implementation required: searchRecursive");
}

BSTNode* BST::minNode(BSTNode* node) const {
    while (node != nullptr && node->left != nullptr) {
        node = node->left;
    }
    return node;
}

BSTNode* BST::maxNode(BSTNode* node) const {
    while (node != nullptr && node->right != nullptr) {
        node = node->right;
    }
    return node;
}

int BST::heightRecursive(const BSTNode* node) const {
    if (node == nullptr) {
        return -1;
    }
    return 1 + std::max(heightRecursive(node->left), heightRecursive(node->right));
}

bool BST::isBalancedRecursive(const BSTNode* node) const {
    if (node == nullptr) {
        return true;
    }
    int leftHeight = heightRecursive(node->left);
    int rightHeight = heightRecursive(node->right);
    if (std::abs(leftHeight - rightHeight) > 1) {
        return false;
    }
    return isBalancedRecursive(node->left) && isBalancedRecursive(node->right);
}

void BST::clearRecursive(BSTNode* node) {
    if (node == nullptr) {
        return;
    }
    clearRecursive(node->left);
    clearRecursive(node->right);
    delete node;
}

void BST::inorderRecursive(const BSTNode* node, std::vector<int>& values) const {
    if (node == nullptr) {
        return;
    }
    inorderRecursive(node->left, values);
    values.push_back(node->value);
    inorderRecursive(node->right, values);
}

void BST::preorderRecursive(const BSTNode* node, std::vector<int>& values) const {
    if (node == nullptr) {
        return;
    }
    values.push_back(node->value);
    preorderRecursive(node->left, values);
    preorderRecursive(node->right, values);
}

void BST::postorderRecursive(const BSTNode* node, std::vector<int>& values) const {
    if (node == nullptr) {
        return;
    }
    postorderRecursive(node->left, values);
    postorderRecursive(node->right, values);
    values.push_back(node->value);
}

void BST::levelOrderRecursive(const BSTNode* node, std::vector<int>& values) const {
    if (node == nullptr) {
        return;
    }
    std::queue<const BSTNode*> q;
    q.push(node);
    while (!q.empty()) {
        const BSTNode* current = q.front();
        q.pop();
        values.push_back(current->value);
        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}
