// String comapre Algo with O(m+n) m,n being lenghts of string to compare

/* 
* IDEA - Is prefix of pattern again apperaring somewhere again in the pattern. 
* Ref Link --> https://www.youtube.com/watch?v=V5-7GzOfADQ
*/

/*
* Indices : 0 1 2 3 4 5 6 7 8 9
* Pattern : a b c d a b e a b c
* Lps     : - - -   1 2   1 2 3     Rest all the values are 0

* Each index in lps represents the index the pointer has to move once once the char in text doesn't match with char in pattern
*/

#include<bits/stdc++.h>

using namespace std;

// pietable
// Longest proper Prefix which is also Suffix
void computeLPSArray(char* pat, int M, int* lps)
{
	// length of the previous longest prefix suffix
	int len = 0;

	lps[0] = 0; // lps[0] is always 0

	// the loop calculates lps[i] for i = 1 to M-1
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			// This is tricky. Consider the example.
			// AAACAAAA and i = 7. The idea is similar
			// to search step.
			if (len != 0) {
				len = lps[len - 1];

				// Also, note that we do not increment
				// i here
			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}


// Prints occurrences of txt[] in pat[]
vector<int> KMPSearch(char* pat, char* txt)
{
    vector<int> ans;
	int M = strlen(pat);
	int N = strlen(txt);

	// create lps[] that will hold the longest prefix suffix
	// values for pattern
	int lps[M];

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray(pat, M, lps);

	int i = 0; // index for txt[]
	int j = 0; // index for pat[]
	while (i < N) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			ans.push_back(i-j);
			j = lps[j - 1];
		}

		// mismatch after j matches
		else if (i < N && pat[j] != txt[i]) {
			// Do not match lps[0..lps[j-1]] characters,
			// they will match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
    return ans;
}



int main(){
    // 0 based indexing
    char txt[] = "ABABDABACDABABCABAB";
	char pat[] = "ABABCABAB";
	vector<int> matched_indx = KMPSearch(pat, txt);
    
    cout << "pattern appears from following indices: ";
    for(auto indx : matched_indx)
        cout << indx << " ";
}