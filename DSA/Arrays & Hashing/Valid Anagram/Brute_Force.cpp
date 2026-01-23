//using STL
class Solution {
public:
    bool isAnagram(string s, string t) {
    	//check if size of both strings match
        if(s.size() != t.size()){
            return false;
        }
        else{
        	//sort the both strings
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            //check if strings match
            if(s == t){
                return true;
            }
            else{
                return false;
            }
        }
    }
};

/*
//without STL 
class Solution {
public:
	//swap function
    void swap(char& a, char& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    //function to sort both strings using bubble sort
    void sort(string &str){
        for(int i = 0; i < str.size(); i++){
            for(int j = i + 1; j < str.size(); j++){
                if(str[i] > str[j]){
                    swap(str[i], str[j]);
                }
            }
        }
    }
    //function to check Anagram or not
    bool isAnagram(string &s, string &t) {
    	//check if size of both strings match
        if(s.size() != t.size()){
            return false;
        }
        //if size matches
        else{
        	//sort them
            sort(s);
            sort(t);
            //compare both sorted strings
            if(s == t){
                return true;
            }
            else{
                return false;
            }
        }
    }
};
*/