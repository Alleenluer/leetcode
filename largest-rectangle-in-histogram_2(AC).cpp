// 1WA, 1AC, the more optimized O(n) solution with stack.
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		int i;
		int n;
		
		n = (int)height.size();
		if (n == 0) {
			return 0;
		}
		
		int max_area = 0;
		int area;
		stack<int> st;
		int top;
		
		for (i = 0; i < n; ++i) {
			if (st.empty() || height[st.top()] <= height[i]) {
				st.push(i);
			} else {
				while (!st.empty() && height[st.top()] > height[i]) {
					top = st.top();
					st.pop();
					if (st.empty()) {
						area = i * height[top];
					} else {
						area = (i - st.top() - 1) * height[top];
					}
					if (area > max_area) {
						max_area = area;
					}
				}
				st.push(i);
			}
		}
		while (!st.empty()) {
			top = st.top();
			st.pop();
			if (st.empty()) {
				area = i * height[top];
			} else {
				area = (i - st.top() - 1) * height[top];
			}
			if (area > max_area) {
				max_area = area;
			}
		}
		
		return max_area;
	}
};