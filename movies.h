//Sanil Baweja

#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>

using namespace std;

class MovieBST{
public:
	MovieBST();
	~MovieBST();
	bool insert(string value);
	void printPreOrder() const;
	//void printBest() const;
	//void findBestWithPrefix(string prefix) const;

private:
	struct Node{
		string name;
		double rating;
		int depth;
		Node *left, *right, * parent;
    	Node(string v = 0, double r = 0, int d = 0) : name(v), rating(r), depth(d), left(0), right(0), parent(0) { }
	};

	Node* root;

	void clear(Node* n);
	bool insert(const string& mName, const double& mRating, Node *n, int mDepth);
	void printPreOrder(Node *n) const;
	//Node* findBest(Node* n) const;

};


#endif