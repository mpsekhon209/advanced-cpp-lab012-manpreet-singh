#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "project/bst.h"

#include <algorithm>
#include <stdexcept>
#include <vector>

TEST_CASE("BST starts empty and reports size") {
    BST tree;
    REQUIRE(tree.empty());
    REQUIRE(tree.size() == 0u);
    REQUIRE(tree.height() == -1);
}

TEST_CASE("BST insert and contains handle standard values") {
    BST tree;
    REQUIRE(tree.insert(50));
    REQUIRE(tree.insert(30));
    REQUIRE(tree.insert(70));
    REQUIRE(tree.insert(20));
    REQUIRE(tree.insert(40));
    REQUIRE(tree.insert(60));
    REQUIRE(tree.insert(80));

    REQUIRE_FALSE(tree.empty());
    REQUIRE(tree.size() == 7u);
    REQUIRE(tree.contains(50));
    REQUIRE(tree.contains(20));
    REQUIRE(tree.contains(80));
    REQUIRE_FALSE(tree.contains(99));
}

TEST_CASE("BST rejects duplicate insertions") {
    BST tree;
    REQUIRE(tree.insert(10));
    REQUIRE_FALSE(tree.insert(10));
    REQUIRE(tree.size() == 1u);
    REQUIRE(tree.search(10));
}

TEST_CASE("BST search returns true for existing nodes and false otherwise") {
    BST tree;
    tree.insert(25);
    tree.insert(15);
    tree.insert(35);
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);

    REQUIRE(tree.search(25));
    REQUIRE(tree.search(10));
    REQUIRE(tree.search(40));
    REQUIRE_FALSE(tree.search(999));
}

TEST_CASE("BST min and max return the correct extrema") {
    BST tree;
    tree.insert(12);
    tree.insert(7);
    tree.insert(19);
    tree.insert(3);
    tree.insert(9);
    tree.insert(18);
    tree.insert(25);

    REQUIRE(tree.min() == 3);
    REQUIRE(tree.max() == 25);
    REQUIRE_THROWS_AS(BST().min(), std::logic_error);
}

TEST_CASE("BST height is computed correctly") {
    BST tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(7);
    tree.insert(12);
    tree.insert(20);
    REQUIRE(tree.height() == 2);

    BST skewed;
    for (int v : {1, 2, 3, 4, 5}) {
        skewed.insert(v);
    }
    REQUIRE(skewed.height() == 4);
}

TEST_CASE("BST traversals return expected values") {
    BST tree;
    for (int v : {50, 30, 70, 20, 40, 60, 80}) {
        tree.insert(v);
    }

    REQUIRE(tree.inorder() == std::vector<int>({20, 30, 40, 50, 60, 70, 80}));
    REQUIRE(tree.preorder() == std::vector<int>({50, 30, 20, 40, 70, 60, 80}));
    REQUIRE(tree.postorder() == std::vector<int>({20, 40, 30, 60, 80, 70, 50}));
    REQUIRE(tree.levelOrder() == std::vector<int>({50, 30, 70, 20, 40, 60, 80}));
}

TEST_CASE("BST remove deletes leaf, root, and internal nodes correctly") {
    BST tree;
    for (int v : {50, 30, 70, 20, 40, 60, 80, 10, 25}) {
        tree.insert(v);
    }

    REQUIRE(tree.remove(10));
    REQUIRE_FALSE(tree.contains(10));
    REQUIRE(tree.remove(50));
    REQUIRE_FALSE(tree.contains(50));
    REQUIRE(tree.remove(30));
    REQUIRE_FALSE(tree.contains(30));
    REQUIRE(tree.size() == 6u);
    REQUIRE_FALSE(tree.remove(999));
}

TEST_CASE("BST clear empties the tree") {
    BST tree;
    for (int v : {5, 3, 8, 2, 4, 7, 9}) {
        tree.insert(v);
    }

    tree.clear();
    REQUIRE(tree.empty());
    REQUIRE(tree.size() == 0u);
    REQUIRE(tree.height() == -1);
    REQUIRE(tree.inorder().empty());
}

TEST_CASE("BST balanced check works on balanced and unbalanced trees") {
    BST balanced;
    for (int v : {10, 5, 15, 2, 7, 12, 20}) {
        balanced.insert(v);
    }
    REQUIRE(balanced.isBalanced());

    BST unbalanced;
    for (int v : {1, 2, 3, 4, 5}) {
        unbalanced.insert(v);
    }
    REQUIRE_FALSE(unbalanced.isBalanced());
}

TEST_CASE("BST handles negative numbers and repeated operations") {
    BST tree;
    for (int v : {-5, 10, -2, 8, -9, 0, 6}) {
        tree.insert(v);
    }

    REQUIRE(tree.contains(-9));
    REQUIRE(tree.min() == -9);
    REQUIRE(tree.max() == 10);
    REQUIRE(tree.remove(-2));
    REQUIRE_FALSE(tree.contains(-2));
    REQUIRE(tree.search(0));
}

TEST_CASE("BST handles empty tree edge cases") {
    BST empty;
    REQUIRE(empty.empty());
    REQUIRE(empty.size() == 0u);
    REQUIRE_FALSE(empty.contains(42));
    REQUIRE_FALSE(empty.search(42));
    REQUIRE_THROWS_AS(empty.min(), std::logic_error);
    REQUIRE_THROWS_AS(empty.max(), std::logic_error);
    REQUIRE(empty.inorder().empty());
    REQUIRE(empty.preorder().empty());
    REQUIRE(empty.postorder().empty());
    REQUIRE(empty.levelOrder().empty());
    REQUIRE(empty.isBalanced());
}

TEST_CASE("BST remove handles root replacement with two children") {
    BST tree;
    for (int v : {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15}) {
        tree.insert(v);
    }

    REQUIRE(tree.remove(8));
    REQUIRE_FALSE(tree.contains(8));
    REQUIRE(tree.size() == 14u);
    REQUIRE(tree.min() == 1);
    REQUIRE(tree.max() == 15);
    REQUIRE(tree.inorder() == std::vector<int>({1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15}));
}

TEST_CASE("BST height and balance update after deletions") {
    BST tree;
    for (int v : {50, 30, 70, 20, 40, 60, 80, 10, 25}) {
        tree.insert(v);
    }

    REQUIRE(tree.height() == 3);
    REQUIRE(tree.isBalanced());

    REQUIRE(tree.remove(20));
    REQUIRE(tree.remove(30));
    REQUIRE(tree.remove(40));
    REQUIRE(tree.height() == 2);
    REQUIRE(tree.isBalanced());
}

TEST_CASE("BST repeated insert and remove cycles remain consistent") {
    BST tree;
    for (int v : {6, 2, 8, 1, 4, 7, 9, 3, 5}) {
        tree.insert(v);
    }

    REQUIRE(tree.size() == 9u);
    for (int v : {1, 2, 3, 4, 5, 6, 7, 8, 9}) {
        REQUIRE(tree.contains(v));
    }

    REQUIRE(tree.remove(2));
    REQUIRE_FALSE(tree.contains(2));
    REQUIRE(tree.remove(8));
    REQUIRE_FALSE(tree.contains(8));
    REQUIRE(tree.remove(6));
    REQUIRE_FALSE(tree.contains(6));
    REQUIRE(tree.size() == 6u);
    REQUIRE(tree.search(7));
    REQUIRE(tree.search(3));
    REQUIRE_FALSE(tree.search(99));
}

TEST_CASE("BST supports descending input and maintains sorted traversal") {
    BST tree;
    for (int v : {9, 8, 7, 6, 5, 4, 3, 2, 1}) {
        tree.insert(v);
    }

    REQUIRE(tree.height() == 8);
    REQUIRE(tree.inorder() == std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
    REQUIRE(tree.preorder().size() == 9u);
    REQUIRE(tree.postorder().size() == 9u);
    REQUIRE(tree.levelOrder().size() == 9u);
    REQUIRE(tree.isBalanced() == false);
}
