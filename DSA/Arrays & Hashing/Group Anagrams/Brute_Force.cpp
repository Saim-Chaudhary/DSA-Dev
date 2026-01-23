class Solution {
	public:
		vector<vector<string>> groupAnagrams(vector<string>& strs) {
			// Store the number of strings
			int n = strs.size();  
			// Create a vector of pairs to store (sorted string, original string)
			vector<pair<string, string>> arr;
			// Loop over all strings
			for(int i = 0; i < n; i++) {
				// Copy original string
				string sortedStr = strs[i];    
				// Sort characters of the array       
				sort(sortedStr.begin(), sortedStr.end());
				// Store (sorted string, original string) in arr 
				arr.push_back({sortedStr, strs[i]});  
			}
			// Keep track of strings already grouped
			vector<bool> visited(n, false);  
			// Result vector to store groups of anagrams        
			vector<vector<string>> ans;               

			// Outer loop: pick each string as base
			for(int i = 0; i < n; i++) {
				// Skip if already grouped
				if(visited[i]) continue;              
				// Create a new group
				vector<string> group;     
				// Add original string to current group            
				group.push_back(arr[i].second);  
				// Mark this string as grouped     
				visited[i] = true;                    

				// Inner loop: check remaining strings for anagrams
				for(int j = i + 1; j < n; j++) {
					// If not visited and sorted keys match, it is an anagram
					if(!visited[j] && arr[i].first == arr[j].first) {
						// Add matching original string to group
						group.push_back(arr[j].second); 
						// Mark as grouped
						visited[j] = true;              
					}
				}
				// Add current group to answer
				ans.push_back(group);                  
			}
			// Return all groups of anagrams
			return ans;                                 
		}
};
