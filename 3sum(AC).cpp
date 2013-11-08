// 1CE, 1RE, 1WA, 1AC, foolish mistakes all over...
#include <algorithm>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int i, j, k;
        for(i = 0; i < result.size(); ++i){
            result[i].clear();
        }
        result.clear();
        mm.clear();
        
        if(num.size() <= 0){
            return result;
        }
        
        string str;
        vector<int> vt;
        
        // 1CE here, declaration of $n missing
        int n;
        
        sort(num.begin(), num.end());
        n = num.size();
        for(i = 0; i < n; ++i){
            for(j = i + 1; j < n; ++j){
                k = binary_search(num, j + 1, n - 1, -(num[i] + num[j]));
                if(k > j && k < n){
                    sprintf(buf, "%d_%d_%d", num[i], num[j], num[k]);
                    str = string(buf);
                    if(mm.find(str) == mm.end()){
                        mm[str] = 1;
                        vt.clear();
                        vt.push_back(num[i]);
                        vt.push_back(num[j]);
                        vt.push_back(num[k]);
                        result.push_back(vt);
                    }
                }
            }
        }
        
        // 1WA, forgot to return the result...
        return result;
    }
private:
    vector<vector<int>> result;
    map<string, int> mm;
    char buf[100];
    
    int binary_search(vector<int> &num, int left, int right, int target) {
        int lp, mp, rp;
        
        if(left < 0 || left >= num.size() || right < 0 || right >= num.size()){
            return -1;
        }
        
        if(left > right){
            return -1;
        }
        
        // 1RE here, use of $lp, $rp without initialization
        if(target < num[left] || target > num[right]){
            return -1;
        }
        
        lp = left;
        rp = right;
        while(lp <= rp){
            mp = (lp + rp) / 2;
            if(target < num[mp]){
                rp = mp - 1;
            }else if(target > num[mp]){
                lp = mp + 1;
            }else{
                return mp;
            }
        }
        
        return -1;
    }
};