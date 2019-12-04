class TrafficLight {
protected:
	int tla, tlb;
	std::queue<int> q23, q24, q11, q12;
public:
	TrafficLight() {
		tla = 1, tlb = 0;
	}

	void carArrived(
		int carId,                   // ID of the car
		int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
		int direction,               // Direction of the car
		function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
		function<void()> crossCar    // Use crossCar() to make car cross the intersection
	) {
		if (roadId == 1) {
			if (q23.empty() && q24.empty() && tlb == 1) {
				turnGreen();
				tlb = 0, tla = 1;
			}
			if (direction == 1) {
				q11.push(carId);
			}
			else if (direction == 2) {
				q12.push(carId);
			}
			if (tla == 1) {
				if (direction == 1 && q11.size() > 0) {
					q11.pop();
					crossCar();
				}
				if (direction == 2 && q12.size() > 0) {
					q12.pop();
					crossCar();
				}
			}
		}
		else if (roadId == 2) {
			if (q11.empty() && q12.empty() && tla == 1) {
				turnGreen();
				tlb = 1, tla = 0;
			}
			if (direction == 3) {
				q23.push(roadId);
			}
			else if (direction == 4) {
				q24.push(roadId);
			}
			if (tlb == 1) {
				if (direction == 3 && q23.size() > 0) {
					q23.pop();
					crossCar();
				}
				if (direction == 4 && q24.size() > 0) {
					q24.pop();
					crossCar();
				}
			}
		}
	}
};