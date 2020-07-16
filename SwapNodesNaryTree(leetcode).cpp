/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};
*/

class Solution {
private:
	Node * parentp = 0;
	Node * parentq = 0;
	bool samesubtree = false;
	//Node * pnode=0;
	//Node * qnode=0;
	bool dfs(Node* root, Node* q) {
		if (!root)return false;
		bool ans = false;
		if (root->val == q->val)return true;
		for (auto& x : root->children) {
			ans = ans || dfs(x, q);
		}
		return ans;
	}
	void dfs(Node*& root, Node* p, Node *q, bool waspfound) {
		if (!root)return;
		bool localval = waspfound || (root->val == p->val);
		/*
		if(root->val==p->val){
			//check if q in subtree of p
			cout<<"start!\n";
			Node* temp=root;
			samesubtree=this->dfs(temp,q);
		}
		*/
		//if(parentq==0&&root->val==q->val)qnode=root;
		//if(parentp==0&&root->val==p->val)pnode=root;
		for (auto& x : root->children) {
			if (x->val == p->val) {
				parentp = root;
				//pnode=x;
				dfs(x, p, q, localval);
			}
			else if (x->val == q->val) {
				//qnode=x;
				if (localval)samesubtree = true;
				parentq = root;
				dfs(x, p, q, localval);
			}
			else
				dfs(x, p, q, localval);
		}
		return;
	}
public:
	Node* moveSubTree(Node* root, Node* p, Node* q) {
		if (!root)return nullptr;
		//Find p and q and possibly find ancestor of both nodes. 
		this->dfs(root, p, q, false);
		if (parentp != 0 && parentp->val == q->val)return root;
		if (parentp == nullptr) {
			//p is root
			std::vector<Node*>::iterator it = parentq->children.begin();
			while (it != parentq->children.end()) {
				if ((*it)->val == q->val)break;
				++it;
			}
			parentq->children.erase(it);
			Node * temp = p;
			root = q;
			root->children.push_back(temp);
			return root;
		}
		if (parentq == nullptr) {
			//q is root
			std::vector<Node*>::iterator it = parentp->children.begin();
			while (it != parentp->children.end()) {
				if ((*it)->val == p->val)break;
				++it;
			}
			parentp->children.erase(it);
			root->children.push_back(p);
			return root;
		}
		int dist = 0;
		std::vector<Node*>::iterator it = parentp->children.begin();
		while (it != parentp->children.end()) {
			if ((*it)->val == p->val)break;
			++it;
			++dist;
		}
		parentp->children.erase(it);
		if (samesubtree) {
			//cout<<"yes!\n" 
			it = parentq->children.begin();
			while (it != parentq->children.end()) {
				if ((*it)->val == q->val)break;
				++it;
			}
			parentq->children.erase(it);
		}
		q->children.push_back(p);
		if (samesubtree) {
			parentp->children.insert(parentp->children.begin() + dist, 1, q);
			//parentp->children.push_back(q);
		}
		return root;
	}
};