## 1046. [Last Stone Weight](https://leetcode.com/problems/last-stone-weight/)

> Easy

We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two **heaviest** stones and smash them together.  Suppose the stones have weights `x` and `y` with `x <= y`.  The result of this smash is:

- If `x == y`, both stones are totally destroyed;
- If `x != y`, the stone of weight `x` is totally destroyed, and the stone of weight `y` has new weight `y-x`.

At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)

 

**Example 1:**

```
Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
```

 

**Note:**

1. `1 <= stones.length <= 30`
2. `1 <= stones[i] <= 1000`



**Solutions:**

Store all stones into `multiset` because `multiset` has an order. Then destroy every two stones until there only exist at most one stone in `multiset`. 

Here is my solution class:

```c++
class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		multiset<int, greater<int>> sets;
		sets.insert(stones.begin(), stones.end());
		while (sets.size() > 1) {
			int heaviest1 = *sets.begin();
			int heaviest2 = *(++sets.begin());
			if (heaviest1 > heaviest2) {
				sets.insert(heaviest1 - heaviest2);
			}
			sets.erase(sets.find(heaviest1));
			sets.erase(sets.find(heaviest2));
		}
		if (sets.empty())
			return 0;
		else
			return *sets.begin();
	}
};
```

