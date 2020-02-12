struct NodeDetails
{
	int data;
	int min, max;
};
int Solution::solve(vector<int> &A) {
	vector<int> arr(A.begin(), A.end());
	int n = int(A.size());
	// if tree is empty 
	if (n == 0)
		return true;

	// queue to store NodeDetails 
	queue<NodeDetails> q;

	// index variable to access array elements 
	int i = 0;

	// node details for the  
	// root of the BST 
	NodeDetails newNode;
	newNode.data = arr[i++];
	newNode.min = INT_MIN;
	newNode.max = INT_MAX;
	q.push(newNode);

	// until there are no more elements  
	// in arr[] or queue is not empty 
	while (i != n && !q.empty())
	{
		// extracting NodeDetails of a 
		// node from the queue 
		NodeDetails temp = q.front();
		q.pop();

		// check whether there are more elements  
		// in the arr[] and arr[i] can be left child  
		// of 'temp.data' or not  
		if (i < n && (arr[i] < temp.data &&
			arr[i] > temp.min))
		{
			// Create NodeDetails for newNode  
			/// and add it to the queue 
			newNode.data = arr[i++];
			newNode.min = temp.min;
			newNode.max = temp.data;
			q.push(newNode);
		}

		// check whether there are more elements  
		// in the arr[] and arr[i] can be right child  
		// of 'temp.data' or not  
		if (i < n && (arr[i] > temp.data &&
			arr[i] < temp.max))
		{
			// Create NodeDetails for newNode  
			/// and add it to the queue 
			newNode.data = arr[i++];
			newNode.min = temp.data;
			newNode.max = temp.max;
			q.push(newNode);
		}
	}

	// given array represents level 
	// order traversal of BST 
	if (i == n)
		return true;

	// given array do not represent  
	// level order traversal of BST     
	return false;
}
