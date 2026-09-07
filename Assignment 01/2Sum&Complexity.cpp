#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

pair<int, int> twoSumBruteForce(const vector<int>& nums, int target) {			// function signature
	for (int i = 0; i < nums.size(); i++ ) {									// nested loops, since size is one larger than index, < is used instead of <=
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[i] + nums[j] == target) {
				return { i, j };									// first pair found
			}
		}
	}

	return { 0,0 };																// no pair found
};
pair<int, int> twoSumHash(const vector<int>& nums, int target) {
	unordered_map<int, int> index;
	for (int i = 0; i < nums.size(); i++) {
		int needed = target - nums[i];
		if (index.count(needed)) {
			return { index[needed], i };
		}
		index[nums[i]] = i;
	}
	return {};
};


int main() {
	vector<vector<int>> tests;

	tests.push_back({ 13, 27, 8, 34, 19, 42, 6, 25, 31 });
	tests.push_back({ 51, 16, 29, 7, 38, 22, 63, 14, 45, 33, 11, 26, 57 });
	tests.push_back({ 9, 24, 37, 15, 6, 28, 41 });
	tests.push_back({ 72, 18, 43, 29, 55, 12, 67, 31, 8, 46, 24, 59, 36, 14, 51, 27 });
	tests.push_back({ 21, 48, 13, 35, 62, 17, 44, 9, 53, 28, 39 });
	tests.push_back({ 15, 4, 18, 8, 19, 22, 24, 59, 59, 20, 18, 12, 36, 42, 9 });
	vector<int> targets;
	targets.push_back(40);
	targets.push_back(67);
	targets.push_back(43);
	targets.push_back(79);
	targets.push_back(70);
	targets.push_back(24);
	
	for (int i = 0; i < targets.size(); i++) {
		pair<int, int> answer1 = twoSumBruteForce(tests[i], targets[i]);
		pair<int, int> answer2 = twoSumHash(tests[i], targets[i]);

		cout << "\t Brutefore indecies: " << answer1.first << ", " << answer1.second << "\n \tHash indecies: " << answer2.first << ", " << answer2.second << "\n";
	} 
	

	}