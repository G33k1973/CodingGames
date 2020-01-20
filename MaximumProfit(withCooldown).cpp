int maxProfit(const std::vector<int>& prices)
{
	if (prices.size() == 0) return 0;

	std::vector<int> maxProfit(prices.size());

	maxProfit[0] = 0;
	for (int i = 1; i < prices.size(); i++)
	{
		if (i < 3 || maxProfit[i - 1] > maxProfit[i - 2] || maxProfit[i - 2] == maxProfit[i - 3])
		{
			maxProfit[i] = std::max(maxProfit[i - 1], maxProfit[i - 1] + prices[i] - prices[i - 1]);
		}
		else
		{
			maxProfit[i] = std::max
			(
				maxProfit[i - 3] + prices[i] - prices[i - 1],
				maxProfit[i - 2] + (((prices[i] - prices[i - 2]) > 0) ? (prices[i] - prices[i - 2]) : 0)
			);
		}
	}

	return maxProfit.back();
}