#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <unordered_set>

int main() {
	std::vector<int> vec{1, 5, 7, 2, 1, 5, 2, 8, 1};
	std::map<int, int> counts;
	for (auto it : vec) {
		if (counts.count(it)) {
			counts[it]++;
		} else {
			counts.insert(std::make_pair(it, 1));
		}
	};
	auto encounter = [](const std::vector<int>& _vec) {
		std::vector<int> new_vec;
		std::unordered_set<int> _set;
		if (!_vec.empty()) {
			for (auto it : _vec) {
				_set.insert(it);
			}
			for (auto it : _set) {
				new_vec.push_back(it);
			}
		} else {
			return std::make_unique<std::vector<int>>(_vec);
		}
		return std::make_unique<std::vector<int>>(new_vec);
	};

	for (auto it : *(encounter(vec))) {
		std::cout << "The number " << it << " has been encountered " << counts[it] << " times" << std::endl;
	}
	std::cout << std::endl;
}
