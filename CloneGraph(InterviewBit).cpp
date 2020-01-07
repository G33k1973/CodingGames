/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mirror;
UndirectedGraphNode * build(UndirectedGraphNode *node) {
	UndirectedGraphNode * temp = new UndirectedGraphNode(node->label);
	mirror.insert(make_pair(node, temp));
	for (auto& x : node->neighbors) {
		if (mirror.count(x)) {
			temp->neighbors.push_back(mirror[x]);
		}
		else {
			UndirectedGraphNode * current = build(x);
			temp->neighbors.push_back(current);
		}
	}
	return temp;
}
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
	if (node == NULL)return NULL;
	if (mirror.size())mirror.clear();
	return build(node);
}
