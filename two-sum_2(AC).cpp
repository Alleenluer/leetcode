#include <algorithm>
using namespace std;

vector<int> data;
bool sort_comparator(const int &x, const int &y)
{
	return data[x] < data[y];
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		result.clear();
		index.clear();
		data.clear();
		data = numbers;
		
		int i, j, n;
		
		n = numbers.size();
		if(n < 2){
			return result;
		}
		for(i = 0; i < n; ++i){
			index.push_back(i);
		}
		sort(index.begin(), index.end(), sort_comparator);
		
		int ll, rr, mm;
		for(i = 0; i < n; ++i){
			ll = i + 1;
			rr = n - 1;
			if(ll > rr || target - data[index[i]] < data[index[ll]] || target - data[index[i]] > data[index[rr]]){
				continue;
			}
			while(ll <= rr){
				mm = (ll + rr) / 2;
				if(target - data[index[i]] < data[index[mm]]){
					rr = mm - 1;
				}else if(target - data[index[i]] > data[index[mm]]){
					ll = mm + 1;
				}else{
					if(index[i] < index[mm]){
						result.push_back(index[i] + 1);
						result.push_back(index[mm] + 1);
					}else{
						result.push_back(index[mm] + 1);
						result.push_back(index[i] + 1);
					}
					break;
				}
			}
			if(ll <= rr){
				break;
			}
		}
		
		index.clear();
		data.clear();
		return result;
    }
private:
	vector<int> result;
	vector<int> index;
};