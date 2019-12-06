//Sanil Baweja

#include <iostream>
#include <algorithm>
#include <ctime>
#include "movies.h"
#include "utility.h"

using namespace std;

MovieBST::MovieBST() : root(0) {}

MovieBST::~MovieBST(){
	clear(root);
}

void MovieBST::clear(Node *n) {
    if (n) {
	clear(n->left);
	clear(n->right);
	delete n;
    }
}

bool MovieBST::insert(string value) {
    // handle special case of empty tree first
	string mName;
	double mRating;
	int comma;

	comma = value.rfind(",");
	mName = value.substr(0,comma);
	mName.erase(remove(mName.begin(), mName.end(), '"'), mName.end());
	mRating = stod(value.substr(comma+1));

    if (!root) {
		root = new Node(mName, mRating, 0);
		return true;
    }
    // otherwise use recursive helper
    return insert(mName, mRating, root, 1);
}

// recursive helper for insert (assumes n is never 0)
bool MovieBST::insert(const string& mName, const double& mRating, Node *n, int mDepth) {
    if (mName == n->name)
		return false;
    if (mName < n->name) {
		if (n->left)
	    	return insert(mName, mRating, n->left, mDepth+1);
		else {
		    n->left = new Node(mName, mRating, mDepth);
		    n->left->parent = n;
		    return true;
		}
    }
    else {
		if (n->right)
		    return insert(mName, mRating, n->right, mDepth + 1);
		else {
		    n->right = new Node(mName, mRating, mDepth);
		    n->right->parent = n;
		    return true;
		}
    }
}

void MovieBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void MovieBST::printPreOrder(Node *n) const {
    if (n) {
	cout << n->name << ", " << n->rating << ", " << n->depth << endl;
	printPreOrder(n->left);
	printPreOrder(n->right);
    }
}



bool MovieBST::contains(string s) const{
	return contains(s, root);
}

bool MovieBST::contains(string s, Node* n) const{
	if(n){
		if(n->name == s)
			return true;
		if(s < n->name)
			return contains(s, n->left);
		if(s > n->name)
			return contains(s, n->right);
	}	
	return false;
}

int MovieBST::depth (string s) const{
	return depth(s, root);
}

int MovieBST::depth (string s, Node* n) const{
	if(n){
		if(n->name == s)
			return n->depth;
		if(s < n->name)
			return depth(s, n->left);
		if(s > n->name)
			return depth(s, n->right);
	}	
	return 0;
}
/*void MovieBST::printBestWithPrefix(string prefix) const{

	findBestWithPrefix(Node* root);
}

MovieBST::Node* MovieBST::findBestWithPrefix(string prefix, Node* n) const{
	if(n){
		if (prefix == n->name.substr(0, prefix.size())){
			if (prefix == n->left->name.substr(0, prefix.size()))
		}
	}
} */

