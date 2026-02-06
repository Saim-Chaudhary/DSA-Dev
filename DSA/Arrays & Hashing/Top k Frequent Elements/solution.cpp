#include <bits/stdc++.h>
using namespace std;
int main() {
    int nums[] = {1, 3, 4, 3, 4, 2, 3, 4, 2, 3, 4, 2, 5, 4, 5, 5};
    int size = sizeof(nums) / sizeof(nums[0]);
    int k = 3;

    //declaring hashmap
    map<int, int> mp;
    
    //inserting values in hashmap
    for(int i = 0; i < size; i++){
        mp[nums[i]]++;
    }

    // priority_queue<Type, Container, Comparison>...(min-heap)
    //use pair becuase hashmap contains two things [elemets, frequency]
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(auto n : mp){
        pq.push({n.second, n.first});

        if(pq.size() > k){
            pq.pop();
        }
    }

    int priority_queue_size = pq.size();
    int ans[priority_queue_size];

    for(int i = 0; i < priority_queue_size; i++){

        //putting top elements in array
        ans[i] = pq.top().second; //.second because in priority_queue second is our actual value
        
        //move to next element
        pq.pop();
    }

    for(int i = 0; i < priority_queue_size; i++){
        cout<<ans[i]<<endl;
    }
    
}