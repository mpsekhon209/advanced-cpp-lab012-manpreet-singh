#include <iostream>
#include <vector>
#include "project/bst.h"

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    std::cout << "Inorder: ";
    for (int value : tree.inorder()) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    std::cout << "Contains 40? " << tree.contains(40) << "\n";
    std::cout << "Height: " << tree.height() << "\n";
    return 0;
}
