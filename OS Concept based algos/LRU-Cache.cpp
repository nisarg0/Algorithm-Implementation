// We can use stl container list as a double
// ended queue to store the cache keys, with
// the descending time of reference from front
// to back and a set container to check presence
// of a key. But to fetch the address of the key
// in the list using find(), it takes O(N) time.
// This can be optimized by storing a reference
//	 (iterator) to each key in a hash map.

// Refer : https : // leetcode.com/problems/lru-cache/ my solutions

#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
	int capacity;
	list<pair<int, int>> dq; // key, value pair

	// store references of key in cache
	unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
	LRUCache(int capacity)
	{
		this->capacity = capacity;
	}

	int get(int key)
	{
		if (mp.find(key) == mp.end())
			return -1;

		int value = mp[key]->second;
		dq.erase(mp[key]);
		dq.push_front({key, value});
		mp[key] = dq.begin();

		return value;
	}

	void put(int key, int value)
	{
		if (mp.find(key) == mp.end())
		{
			if (dq.size() == capacity)
			{
				pair<int, int> last = dq.back();
				dq.pop_back();
				mp.erase(last.first);
			}
		}
		else
		{
			dq.erase(mp[key]);
		}
		dq.push_front({key, value});
		mp[key] = dq.begin();
	}
};

// Driver Code
int main()
{
	LRUCache ca(4);

	ca.put(1, 2);
	ca.put(2, 3);
	ca.put(3, 2);
	ca.put(1, 2);
	cout << ca.get(4) << "\n";
	ca.put(4, 1);
	cout << ca.get(4) << "\n";
	ca.put(5, 6);
	return 0;
}