//inlcude almost all the standard libraries
#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {1, 2, 4, 1, 2, 3, 1};
    //find size of array
    int size = sizeof(arr) / sizeof(arr[0]);

    //initialize map
    unordered_map<int, int> mp;
    //store maximum frequency 
    int maxFreq = 0;
    //store answer with maximum frequency
    int maxNum = 0;

    for(int i = 0; i < size; i++){
        //putting values in map and counting its frequency
        mp[arr[i]]++;
    }

    for(auto it : mp){
        //find the maximum frequency number
        if(maxFreq < it.second){
            maxFreq = it.second;
            maxNum = it.first;
        }
    }
    //printing our desired answer
    cout<<"Number with Maximum Frequency: "<<maxNum;
}