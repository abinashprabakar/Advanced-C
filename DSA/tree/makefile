all : avl_tree avl_tree1 binary_search_tree binary_tree 

avl_tree : avl_tree.c
	gcc -g -O0 -o avl_tree avl_tree.c

avl_tree1 : avl_tree1.c
	gcc -g -O0 -o avl_tree1 avl_tree1.c

binary_search_tree : binary_search_tree.c
	gcc -g -O0 -o bst binary_search_tree.c

binary_tree : binary_tree.c
	gcc -g -O0 -o binaryTree binary_tree.c

clean :
	rm -rf *.o avl_tree avl_tree1 binary_search_tree binary_tree  
