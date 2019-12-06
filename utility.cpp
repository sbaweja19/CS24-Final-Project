//Sanil Baweja

#include <iostream>
#include "utility.h"

using namespace std;

PrefixBST::PrefixBST() : root(0) {}

PrefixBST::~PrefixBST(){
	clear(root);
}

void PrefixBST::clear(Node *n) {
    if (n) {
	clear(n->left);
	clear(n->right);
	delete n;
    }
}

bool PrefixBST::insert(string mName, double mRating) {
    // handle special case of empty tree first

    if (!root) {
		root = new Node(mName, mRating);
		return true;
    }
    // otherwise use recursive helper
    return insert(mName, mRating, root);
}

// recursive helper for insert (assumes n is never 0)
bool PrefixBST::insert(const string& mName, const double& mRating, Node *n) {
    if (mRating == n->rating)
		return false;
    if (mRating < n->rating) {
	if (n->left)
	    return insert(mName, mRating, n->left);
	else {
	    n->left = new Node(mName, mRating);
	    n->left->parent = n;
	    return true;
	}
    }
    else {
	if (n->right)
	    return insert(mName, mRating, n->right);
	else {
	    n->right = new Node(mName, mRating);
	    n->right->parent = n;
	    return true;
	}
    }
}

void PrefixBST::printBest(string prefix) const{
	Node* bestRated = root;
	while(bestRated->right){
		bestRated = bestRated->right;
	}
	cout << "Best movie is " << bestRated->name << " with rating " << bestRated->rating << endl;
}

/*PrefixBST::Node* PrefixBST::findBest(Node* n, string prefix) const{
	if(n){
		Node* res = n;
		Node* lres = findBest(n->left);
		Node* rres = findBest(n->right);
		if (lres && lres->rating > res->rating)  
    		res = lres;  
    	if (rres && rres->rating > res->rating)  
    		res = rres;  
    	return res; 

	}
	else return 0;
} */