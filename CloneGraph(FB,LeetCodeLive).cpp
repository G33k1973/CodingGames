/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}

	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};
*/

class Solution {
private:
	unordered_map<Node*, Node*> mirror;
	Node * build(Node * root) {
		Node * t = new Node();
		t->val = root->val;
		mirror[root] = t;
		for (Node * x : root->neighbors) {
			if (mirror.count(x) > 0) {
				t->neighbors.push_back(mirror[x]);
			}
			else {
				Node * t2 = build(x);
				t->neighbors.push_back(t2);
			}
		}
		return t;
	}
public:
	Node* cloneGraph(Node* node) {
		if (node == 0)return nullptr;
		return build(node);
	}
};/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
	unordered_map<Node*, Node*> mirror;
	Node * build(Node * root) {
		Node * t = new Node();
		t->val = root->val;
		mirror[root] = t;
		for (Node * x : root->neighbors) {
			if (mirror.count(x) > 0) {
				t->neighbors.push_back(mirror[x]);
			}
			else {
				Node * t2 = build(x);
				t->neighbors.push_back(t2);
			}
		}
		return t;
	}
public:
	Node* cloneGraph(Node* node) {
		if (node == 0)return nullptr;
		return build(node);
	}
};