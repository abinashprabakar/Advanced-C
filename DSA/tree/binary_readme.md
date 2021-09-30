## Binary Tree

<p> The Binary tree means that the node can have maximum two children. Here, binary name itself suggests that 'two';
therefore, each node can have either 0, 1 or 2 children. A binary tree has the benefits of both an ordered array and a
linked list as search is as quick as in a sorted array and insertion or deletion operation are as fast as in
linked list.</p>

<img src = "https://www.tutorialspoint.com/data_structures_algorithms/images/binary_tree.jpg">

<h2><b> Binary trees: Terminology </b></h2>

<p> Binary trees are defined by a root node and children nodes, each node being able to have at most two children.
There are a few keywords that we will need to know before we continue.</p>

	 Height  — The height of a node is the maximum number of edges separating that node from a leaf (see leaf).
	 Depth   — The depth of a node is the number of edges separating that node from the root node.
  	 Size    — The size of a tree is the number of nodes it contains.
	 Balance — The balance factor of a node is the difference between the height of its left subtree and the
		   height of its right subtree.
	 Leaf    — A leaf is a node that doesn’t have any children, in other words, an end node.


<h2><b> Order of operations </h2></b>

		There are three types of tree traversal ie, pre-order, post-order, in-order.

		For pre-order traversal, we visit the root node first, then the left subtree, and then the right subtree
		For in-order traversal, we visit the left subtree, then the root node, then the right subtree.
		For post-order traversal, we visit the left subtree first, then the right, and then the root node.

<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/Preorder-from-Inorder-and-Postorder-traversals.jpg">

<h2><b> Height and Depth of the Binary tree </b></h2>

The height of a node in a binary tree is the largest number of edges in a path from a leaf node to a target node. If
the target node doesn’t have any other nodes connected to it, the height of that node would be 0. The height of a 
binary tree is the height of the root node in the whole binary tree. In other words, the height of a binary tree
is equal to the largest number of the edges from the root to the most distant leaf node.

A similar concept in a binary tree is the depth of the tree. The depth of a node in a binary tree is the total number
of edges from the root node to the target node. Similarly, the depth of a binary tree is the total number of edges from
the root node to the most distant leaf node.

<p> For example, let's take a binary tree </p>

<img src = "https://www.baeldung.com/wp-content/uploads/sites/4/2020/11/Capture-2.png">

<p> Firstly, we’re calculating the height of the node C. So, according to the definition, the height of the node C is
the largest number of edges in a path from the leaf node to the node C. We can see for the node C, there are two paths:
C -> E -> G and C -> F. The largest number of edges among these two paths would be 2. Hence the height of node C is 2..

Now, let’s calculate the height of the binary tree. From the root, we can have three different paths leading to the
leaf nodes: A -> C -> F, A -> B -> D, and A -> C -> E -> G. Among these three paths, the path A -> C -> E -> G contains
the most number of edges that is 3. Therefore the height of the tree is 3.

Next, we want to find the depth of the node B. Now we can see that from the root, there is only one path to the node B,
and it has one edge. Hence the depth of the node B is 1. The depth of a binary tree is equal to the height of the tree.
Therefore, the depth of the binary tree is 3. </p>

<h2><b> Types of Binary tree </h2></b>

	The types of binary tree,
		i. Full / proper / strict binary tree
		ii. Complete binary tree
		iii. Perfect binary tree
		iv. Degenerate binary tree
		v. Balanced binary tree

<b> Strict binary tree </b>

<p> The full binary tree is also known as a strict binary tree. The tree can only be considered as the full binary tree
if each node must contain either 0 or 2 children. The full binary tree can also be defined as the tree in which each
node must contain 2 children except the leaf nodes.</p>
<img src = "https://static.javatpoint.com/ds/images/types-of-binary-tree.png">

<b> Complete binary tree </b>

<p> The complete binary tree is a tree in which all the nodes are completely filled except the last level. In the last
level, all the nodes must be as left as possible. In a complete binary tree, the nodes should be added from the left.
</p>
<img src = "https://static.javatpoint.com/ds/images/types-of-binary-tree2.png">

<b> Perfect binary tree </b>

<p> A tree is a perfect binary tree if all the internal nodes have 2 children, and all the leaf nodes are at the same
level.</p>
<img src = "https://static.javatpoint.com/ds/images/types-of-binary-tree3.png">

<b> Degenerate Binary tree </b>

<p> The degenerate binary tree is a tree in which all the internal nodes have only one children.</p>
<img src = "https://static.javatpoint.com/ds/images/types-of-binary-tree5.png">
<p> The above tree is a degenerate binary tree because all the nodes have only one child. It is also known as a
right-skewed tree as all the nodes have a right child only.</p>

<b> Balanced tree </b>

<p> The balanced binary tree is a tree in which both the left and right trees differ by atmost 1. For example, AVL and
Red-Black trees are balanced binary tree.</p>
<img src = "https://static.javatpoint.com/ds/images/types-of-binary-tree7.png">
<p> The above tree is a balanced binary tree because the difference between the left subtree and right subtree is zero.</p>

<h2><b> Properties of binary tree </h2></b>

At each level of i, the maximum number of nodes is 2i.

The height of the tree is defined as the longest path from the root node to the leaf node. The tree which is shown
above has a height equal to 3. Therefore, the maximum number of nodes at height 3 is equal to (1+2+4+8) = 15. In
general, the maximum number of nodes possible at height h is (20 + 21 + 22+….2h) = 2h+1 -1.

The minimum number of nodes possible at height h is equal to h+1.

If the number of nodes is minimum, then the height of the tree would be maximum. Conversely, if the number of nodes is
maximum, then the height of the tree would be minimum.

If there are 'n' number of nodes in the binary tree.

The minimum height can be computed as:

As we know that,

n = 2h+1 -1

n+1 = 2h+1

Taking log on both the sides,

log2(n+1) = log2(2h+1)

log2(n+1) = h+1

h = log2(n+1) - 1

The maximum height can be computed as:

As we know that,

n = h+1

h= n-1
