/*This is a function problem.You only need to complete the function given below*/
bool IsGoodColor(bool graph[101][101], int color[], int m, int V, int src, int k) {
	for (int j = 0; j < V; ++j) {
		if (j == src)continue;
		if (graph[src][j] && color[j] == k)return false;
	}
	return true;
}
bool ColorUtil(bool graph[101][101], int color[], int m, int V, int src) {
	if (src == V)return true;
	for (int i = 1; i <= m; ++i) {
		int k = i;
		if (IsGoodColor(graph, color, m, V, src, k)) {
			color[src] = i;
			if (ColorUtil(graph, color, m, V, src + 1))return true;
			color[src] = 0;
		}
	}
	return false;
}
bool isPossible(bool graph[101][101], int m, int V) {
	int color[V];
	memset(&color[0], 0, sizeof(color));
	return ColorUtil(graph, color, m, V, 0);
}
bool graphColoring(bool graph[101][101], int m, int V)
{
	// your code here
	if (m >= V) {
		cout << "1\n";
		return 1;
	}
	bool res = isPossible(graph, m, V);
	cout << res << endl;
	return res;
}