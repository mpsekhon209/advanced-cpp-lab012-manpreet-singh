# Binary Search Tree Analysis Laboratory

## Core goal
Students must implement a binary search tree storing integer values and supporting insertion, search, removal, height, traversal, and balancing checks.

## Required operations
Students must implement and analyze:

- `insert(value)`
- `remove(value)`
- `contains(value)`
- `search(value)`
- `min()` and `max()`
- `height()`
- `isBalanced()`
- `clear()`
- traversal methods: inorder, preorder, postorder, and level-order

## Analysis expectations
Students should explain:

- average-case and worst-case complexity of insertion, search, and deletion;
- how tree shape affects cost;
- why balanced trees improve performance;
- traversal behavior and the ordering guarantees of different traversals;
- what happens when the tree becomes skewed.

## Big-O focus
Students should describe Big-O for:

- insert
- search
- remove
- min/max traversal
- height
- inorder/preorder/postorder
- level-order traversal

A rigorous answer should include both average and worst-case behavior.

## Chosen design and complexity
The tree is an ordinary, unbalanced BST. Each node stores one integer and pointers to its left and right children. Values smaller than a node go left, larger values go right, and equal values are rejected. Let `n` be the number of nodes and `h` the tree height, measured in edges (`-1` for an empty tree).

| Operation | Average case | Worst case | Notes |
| --- | --- | --- | --- |
| `insert`, `contains`, `search`, `remove` | O(log n) | O(n) | Each follows one root-to-leaf path; a skewed tree has height `n - 1`. |
| `min`, `max` | O(log n) | O(n) | Follow the leftmost or rightmost path. |
| `height` | O(n) | O(n) | Visits every node to compute the maximum depth; recursion uses O(h) stack space. |
| `isBalanced` | O(n) | O(n) | A post-order pass computes subtree heights and stops when it finds an imbalance; recursion uses O(h) stack space. |
| `inorder`, `preorder`, `postorder` | O(n) | O(n) | Visit every node; results use O(n) space and recursion uses O(h) stack space. |
| `levelOrder` | O(n) | O(n) | Visits every node with a queue whose maximum size is the tree's maximum width. |
| `clear` | O(n) | O(n) | Deletes every node; recursion uses O(h) stack space. |

When insertion order is reasonably distributed, the tree is often close to balanced and root-to-leaf operations take O(log n). Sorted or nearly sorted insertion can produce a chain, making those operations O(n) and increasing recursive stack depth to O(n). A self-balancing tree (such as an AVL or red-black tree) keeps height logarithmic, but adds rotations and balancing rules that this lab's plain BST intentionally does not implement.

Inorder traversal visits left subtree, node, then right subtree, so it returns the values in ascending order. Preorder visits node before its subtrees, postorder visits node after them, and level-order visits nodes breadth-first from the root. The latter three expose tree shape rather than sorting the values.
