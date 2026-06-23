// Last updated: 6/24/2026, 3:30:24 AM
class Solution {
public:
	unordered_map<char, int> hash;
	int v = 0, c = 0;
	
	bool isVowel(char &i){
		return i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u';
	}
	
	void add(char &i){
		if(isVowel(i)){
			hash[i]++;
            if(hash[i] == 1) v++;
		}
		else c++;
	}
	
	void remove(char &i){
		if(isVowel(i)){
			hash[i]--;
			if(hash[i] == 0) v--;
		}
		else c--;
	}
	
	long long solve(string &s, int k) {
        long long count = 0, size = s.size();
		long long i = 0, j = -1;
        while(j < size){
            if(c >= k && v == 5){
                count += size - j;
                remove(s[i++]);
            }
            else {
                j++;
                if(j < size) add(s[j]);
            }
        }
        hash.clear();
        v = c = 0;
        return count;
	}

    long long countOfSubstrings(string s, int k){
        return solve(s, k) - solve(s, k + 1);
    }
};