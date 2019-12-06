//Sanil Baweja

#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>

using namespace std;

class PrefixBST{
public:
	PrefixBST();
	~PrefixBST();
	bool insert(string mName, double mRating);
	//void printPreOrder() const;
	void printBest(string prefix) const;
private:
	struct Node{
		string name;
		double rating;
		Node *left, *right, * parent;
    	Node(string v = 0, double r = 0, int d = 0) : name(v), rating(r), left(0), right(0), parent(0) { }
	};

	Node* root;

	void clear(Node* n);
	bool insert(const string& mName, const double& mRating, Node *n);
	//void printPreOrder(Node *n) const;
	//Node* findBest(Node* n) const;

};


#endif