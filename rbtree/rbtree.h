#ifndef _RBTREE_H_INCLUDED_
#define _RBTREE_H_INCLUDED_

/* Red-black tree implemenation */
#include <iostream>
#include <string>
#include <deque>
//Associate key to value
// key is char, value is int

typedef char Key_t;
typedef int Value_t;
class RBTree {
public:
	static const bool RED = true;
	static const bool BLACK = false;
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
	void deleteMin() {
		root = deleteMin(root);
	}

	// red black tree changes
	

	
private:
	// inner class
	struct Node {
		Key_t key;
		Value_t value;
		Node *left; //left subtree
		Node *right; // right subtree
		bool color; // node color: RED or BLACK
		int count = 1; // subtree count
		
		Node(Key_t k, Value_t v) {
			key = k;
			value = v;
			color = RBTree::RED; // default RED
			left = NULL;
			right = NULL;
		}
	};
	
	Node *root; // root of the tree

	//Red Black tree code changes ============== 
	bool isRed(RBTree:: Node *cur) {
		if(cur == NULL) return RBTree::BLACK;
		return cur->color == RBTree::RED;
	}
	RBTree::Node *
	rotateLeft(RBTree::Node *cur) {
		/**
			cur
			/ \
	        cur-left   cur-right
			     /  \
			middleleft  bigright

		to:
			cur-right (new root)
			  /  \
                       cur   bigtright
		       / \
	        cur-left middleleft
		*/
		RBTree::Node *new_root = cur->right; // save new root
		cur->right = new_root->left; // set mid left to currents right
		new_root->left = cur;
		new_root->color = cur->color;
		cur->color = RBTree::RED;
		return new_root;
		
	}
	RBTree::Node *
	rotateRight(RBTree:: Node *cur) {
		/**
			cur
			/ \
		cur-left   cur->right
		  /  \
	 small-left  middle-right

			cur-left
			/    \
		  small-left  cur
			     /  \
                          midright cur-right
		*/
		RBTree::Node *new_root = cur->left; // save new root
		cur->left = new_root->right; //midright
		new_root->right = cur;
		new_root->color = cur->color;
		cur->color = RBTree::RED;
		return new_root;
	}

	void
	flipColors(RBTree::Node *cur) {
		cur->color = RBTree::RED;
		cur->left->color = RBTree::BLACK;
		cur->right->color = RBTree::BLACK;
	}

	class InorderIterator {
	public:
		InorderIterator(RBTree::Node * node) { // ctor
			cur = node;
		}
		~InorderIterator() { //dtor
			// nothing to do
		}
		InorderIterator& operator++() { //called when ++iter
			return * this;	
		} 
		InorderIterator operator++(int)  { //called when iter++
			InorderIterator tmp = *this;
			++*this;
			return tmp;
		}	
		
		bool operator==(const InorderIterator& other) { // comparison
			return this == &other; // compare pointer addresses
		}

		bool operator!=(const InorderIterator& other) {
			return *this == other; // call operator == method above
		}

	private:
		RBTree::Node *cur;
		std::deque<RBTree::Node *> queueOfNodes;
	};
	
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
		// Red-Black tree blance code
		if(isRed(cur->right) && !isRed(cur->left)) {
			cur = rotateLeft(cur);
		}
		if(isRed(cur->left) && isRed(cur->left->left)) {
			cur = rotateRight(cur);
		}
		if(isRed(cur->left) && isRed(cur->right)) {
			flipColors(cur);
		}
		// Red-Black tree blance code
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
	RBTree::Node *
	deleteMin(RBTree::Node * cur) {
		if (cur == NULL)
			return cur;
		if (cur->left !=NULL) { // min value in left subtree
			cur->left = deleteMin(cur->left);
		} else { // current is the minmum, return its right node
			// remvoe current node and return right subtree
			RBTree::Node *saveright = cur->right;
			delete cur;
			return saveright;
		}
		// update subtree count
		cur->count = 1 + size(cur->left) + size(cur->right);
		return cur;	
	
	}
};

#endif /* _RBTREE_H_INCLUDED_ */
