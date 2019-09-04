struct PetrolStationGap {
	int leftStation;
	int rightStation;
	int numStations; // Gap -> [leftStat, rightStat)
};

class Solution {
public:
	static double minmaxGasDist(vector<int>& stations, int K) {
		auto heapComparison = [](const PetrolStationGap& lhs, const PetrolStationGap& rhs) -> bool {
			double lhsGapSize = static_cast<double>(lhs.rightStation - lhs.leftStation) / lhs.numStations;
			double rhsGapSize = static_cast<double>(rhs.rightStation - rhs.leftStation) / rhs.numStations;

			return lhsGapSize < rhsGapSize;
		};

		priority_queue<PetrolStationGap, vector<PetrolStationGap>, decltype(heapComparison)> heap(heapComparison);

		for (int i = 0; i < stations.size() - 1; ++i) {
			heap.push({ stations[i], stations[i + 1], 1 });
		}

		for (int k = 0; k < K; ++k) {
			auto largestGap = heap.top();
			heap.pop();

			heap.push({ largestGap.leftStation, largestGap.rightStation, largestGap.numStations + 1 });
		}

		auto largestGap = heap.top();

		return (static_cast<double>(largestGap.rightStation - largestGap.leftStation) / largestGap.numStations);
	}
};