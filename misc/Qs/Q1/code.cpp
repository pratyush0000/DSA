#include <bits/stdc++.h>
using namespace std;


vector<int> removeDuplicatesPreserveOrder(vector<int> nums){
	unordered_map<int,int> mpp;
	vector<int> ans;

	for(int num: nums){
		if(mpp.find(num)==mpp.end()){
			//put it in map
			mpp[num]=1;
			ans.push_back(num);
		}
	}
	
	return ans;
}

int main() {
    vector<int> nums;
    int sizee;
    cin>>sizee;
    
    int inp;
    for(int i=0; i<sizee; i++){
        cin>>inp;
        nums.push_back(inp);
    }
    vector<int> hello;
    hello=removeDuplicatesPreserveOrder(nums);
    
    for(int h : hello){
        cout<<h<<' ';
    }
    
    return 0;
}