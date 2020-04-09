## 60. [Permutation Squence](https://leetcode.com/problems/permutation-sequence/)

> Medium

The set `[1,2,3,...,*n*]` contains a total of *n*! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for *n* = 3:

1. `"123"`
2. `"132"`
3. `"213"`
4. `"231"`
5. `"312"`
6. `"321"`

Given *n* and *k*, return the *k*th permutation sequence.

**Note:**

- Given *n* will be between 1 and 9 inclusive.
- Given *k* will be between 1 and *n*! inclusive.

**Example 1:**

```
Input: n = 3, k = 3
Output: "213"
```

**Example 2:**

```
Input: n = 4, k = 9
Output: "2314"
```



**Solutions:**

Use traditional recursion to permutate will cause `Time Limit Exceeded`. 

Here is my recursion solution class:

```c++
class Solution {
public:
	string getPermutation(int n, int k) {
		vector<bool> used(n, false);
		string result, curr;
		getPermutationCore(result, curr, used, k);
		return result;
	}
	void getPermutationCore(string& result, string& curr, vector<bool>& used, int& rest) {
		int n = used.size();
		if (curr.size() == n) {
			if (rest == 1) {
				result = curr;
				return;
			}
			else {
				rest--;
				return;
			}
		}
		else {
			for (int i = 0; i < n; ++i) {
				if (!used[i]) {
					curr.push_back('1' + i);
					used[i] = true;
					getPermutationCore(result, curr, used, rest);
					used[i] = false;
					curr.pop_back();
					if (result != "")
						return;
				}
			}
		}
	}
};
```

Then consider solve this problem from the aspect of some regulations.

Take `n = 8, k = 15198` for example:

$15197 \div 7! = 3 ... ... 77$               3 --> 1 2 3 **4** 5 6 7 8 --> `4`

​      $77 \div 6! = 0 ... ... 77$                0 --> **1** 2 3 **4** 5 6 7 8 --> `41`

​      $77 \div 5! = 0 ... ... 77$                0 --> **1 2** 3 **4** 5 6 7 8 --> `412`

​      $77 \div 4! = 3 ... ... 5$                  3 --> **1 2** 3 **4** 5 6 **7** 8 --> `4127`

​        $5 \div 3! = 0 ... ... 5$                  0 --> **1 2 3 4** 5 6 **7** 8 --> `41273`

​        $5 \div 2! = 2 ... ... 1$                  2 --> **1 2 3 4** 5 6 **7 8** --> `412738`

​        $1 \div 1! = 1 ......0$                   1 --> **1 2 3 4** 5 **6 7 8** --> `4127386`

​                                                           0 --> **1 2 3 4 5 6 7 8** --> `41273865`

The regulation is obvious. 

Here is my final solution class:

```c++
class Solution {
public:
	string getPermutation(int n, int k) {
		vector<bool> used(n, false);
		vector<int> factorial(n, 1);
		for (int i = 2; i < n; ++i) {
			factorial[n - i - 1] = factorial[n - i] * i;
		}
		string result;
		k--;
		for (int i = 0; i < n; ++i) {
			int num = k / factorial[i];
			k %= factorial[i];
			int index = 0;
			while (used[index]) {
				index++;
			}
			while (num) {
				if (!used[index++])
					num--;
			}
			while (used[index]) {
				index++;
			}
			result.push_back('1' + index);
			used[index] = true;
		}
		return result;
	}
};
```