// 1CE 1AC
// No compilation error again!!!!
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		result.clear();
		
		int i, j, n;
		
		n = numbers.size();
		for(i = 0; i < n; ++i){
			for(j = i + 1; j < n; ++j){
				if(numbers[i] + numbers[j] == target){
					result.push_back(i + 1);
					result.push_back(j + 1);
					break;
				}
			}
			if(j < n){
				break;
			}
		}
		
		return result;
    }
private:
	vector<int> result;
};