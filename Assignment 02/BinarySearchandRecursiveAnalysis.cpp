#include <iostream>;
#include <vector>;


using namespace std;

int iterativeBinarySearch(const vector<int>& vect, int target) {

	int top = vect.size();
	int bottom = 0;
	int mid = (top + bottom) / 2;
		
	while (!(top < bottom)) {
		if (vect[mid] < target) {
			bottom = mid + 1;
		}
		else if (vect[mid] > target) {
			top = mid - 1;
		}
		else
		{
			return mid;
		}
		mid = (top + bottom) / 2;
	};

	return -1;
};

int recursiveBinarySearch(const vector<int>& vect, int top, int bottom, int mid, int target) {
	if (vect[mid] == target) {
		return mid;
	}
	else if (top < bottom) {
		return -1;
	}
	else if (vect[mid] < target) {
		recursiveBinarySearch(vect, top, mid + 1, (mid + 1 + top) / 2, target);
	}
	else {
		recursiveBinarySearch(vect, mid - 1, bottom, (mid - 1 + bottom) / 2, target);
	}
};

int main() {

	vector<int> testVector = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10, 11 , 12 , 13, 17 , 18 , 19 , 20 , 21 , 22 , 23 , 24};
	vector<int> targets = { 1 /* index 0 */, 24 /* index 20 */, 11 /* index 10 */, 0 /* out of range */, 16 /* inside of range, but missing*/ };

	for (int i = 0; i < targets.size(); i++) {
		cout << "Iterary Binary Result: " << iterativeBinarySearch(testVector, targets[i]) << endl;
		cout << "Recursvie Binary Result: " << recursiveBinarySearch(testVector, testVector.size(), 0, testVector.size() / 2, targets[i]) << endl;
	}



};