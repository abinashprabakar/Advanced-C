**binary_tree.c** - <a href = https://github.com/abinashprabakar/Advanced-C/blob/main/DSA/tree/binary_tree.c">code</a>

		A tree whose elements have at most 2 children is called a binary tree. Since each element in a binary
		tree can have only 2 children, we typically name them the left and right child. 

		Binary Tree Representation in C: A tree is represented by a pointer to the topmost node in tree. If the
		tree is empty, then value of root is NULL. 
		A Tree node contains following parts. 
			1. Data 
			2. Pointer to left child 
			3. Pointer to right child

**binary_search_tree.c** - <a href = "https://github.com/abinashprabakar/Advanced-C/blob/main/DSA/tree/binary_search_tree.c">code</a>

		Binary Search tree can be defined as a class of binary trees, in which the nodes are arranged in a 
		specific order. This is also called ordered binary tree.
	
		In a binary search tree, the value of all the nodes in the left sub-tree is less than the value of 
		the root.

		Similarly, value of all the nodes in the right sub-tree is greater than or equal to the value of 
		the root.This rule will be recursively applied to all the left and right sub-trees of the root.


**avl_tree.c** - <a href = "https://github.com/abinashprabakar/Advanced-C/blob/main/DSA/tree/avl_tree.c">code</a>

		AVL Tree is invented by GM Adelson - Velsky and EM Landis in 1962. The tree is named AVL in honour 
		of its inventors.

		AVL Tree can be defined as height balanced binary search tree in which each node is associated with
		a balance factor which is calculated by subtracting the height of its right sub-tree from that of 
		its left sub-tree.

		Tree is said to be balanced if balance factor of each node is in between -1 to 1, otherwise, 
		the tree will be unbalanced and need to be balanced.

				Balance Factor (k) = height (left(k)) - height (right(k))

		If balance factor of any node is 1, it means that the left sub-tree is one level higher than the 
		right sub-tree.

		If balance factor of any node is 0, it means that the left sub-tree and right sub-tree contain equal
		height.

		If balance factor of any node is -1, it means that the left sub-tree is one level lower than the 
		right sub-tree.
