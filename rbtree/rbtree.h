#ifndef _RBTREE_H_INCLUDED_
#define _RBTREE_H_INCLUDED_

/* Red-black tree implemenation */
#include <iostream>
#include <string>
//Associate key to value
// key is char, value is int

typedef char Key_t;
typedef int Value_t;
class RBTree {
public:
	RBTree() { // ctor (deafault ctor) creates empty
		root = NULL;
	}
	~RBTree() {
		//TBD
	} // this should destroy entire nodes 
	
	void put(Key_t k, Value_t v) {
		root = put(root, k, v);	
	}

	Value_t get(Key_t k) {
		Node *cur = root;
		while(cur != NULL) {
			if(cur->key == k)
				return cur->value;
			else if (cur-> key < k)
				cur = cur->left;
			else
				cur = cur->right;
		}
		return (int)NULL;	
	}
	
	void delKey(Key_t k) {
	}
	
	Key_t floor(Key_t k) {
		return floor(root, k);
	}
	
	int size() {
		return size(root);
	}
	
	int rank(Key_t k) {
		return rank(root, k);
	}	
	void print() {
		print(root, 0);
	}
	
private:
	// inner class
	struct Node {
		Key_t key;
		Value_t value;
		Node *left; //left subtree
		Node *right; // right subtree
		bool color; // node color: red = true, black = false
		int count = 1; // subtree count
		
		Node(Key_t k, Value_t v) {
			key = k;
			value = v;
			color = false;
			left = NULL;
			right = NULL;
		}
	};
	
	Node *root; // root of the tree
	
	// recursive put function
	// update subtree count
	RBTree::Node *
	put(RBTree::Node *cur, Key_t k, Value_t v) {
		std::cout << "enter: put "
			<< "key " << k
			<< "value " << v
			<< std::endl;
		if(cur == NULL) {
			Node *new_node = new RBTree::Node(k, v);
			return new_node;
		}
		if (k < cur->key) { // put in left subtree
			cur->left = put(cur->left, k, v);
		} else if (k > cur->key) { // put in right subtree 
			cur->right = put(cur->right, k, v);
		} else { // key exists, update value
			cur->value = v;
		}
		cur->count = 1 + size(cur->left) + size(cur->right);
		return cur;
	}
	void
	print(RBTree::Node *cur, int cur_level) {
		if(cur == NULL) {
			return;
		}
		std::cout << std::string((cur_level + 1) * 2, ' ') << (char)cur->value << std::endl; // cast to 'char'
		if (cur->left) {
			std::cout << std::string((cur_level + 1) * 2, 'L') << std::endl;
			print(cur->left, cur_level + 1);
		} if (cur->right) {
			std::cout << std::string((cur_level + 1) * 2, 'R') << std::endl;
			print(cur->right, cur_level + 1);
		}
		
	}

	Key_t
	floor(RBTree::Node *cur, Key_t k) {
		if(cur == NULL) {
			return NULL;
		}
		if(k == cur->key) {
		// found the floor
		return cur->key;
		}
		if(k < cur->key) {
			// floor in left subtree
			return floor(cur->left, k);
		}
		// Check right subtree for floor
		Key_t tmp = floor(cur->right, k);
		if(tmp == NULL) { // no floor found
			return cur->key;
		} 
		return tmp;
	} 

	int
	size(RBTree::Node *cur) {
		if (cur == NULL)
			return 0;
		return cur->count;
	}
	int rank(RBTree::Node *cur, Key_t k) {
		if (cur == NULL) {
			return 0;
		}
		if(k < cur->key) {
			return rank(cur->left, k);
		} else if (k > cur-> key) {
			return 1 + size(cur->left) + rank(cur->right, k);
		} else {
			return 1 + size(cur->left);
		}
	}
};

#endif /* _RBTREE_H_INCLUDED_ */
