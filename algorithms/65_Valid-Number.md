## 65. [Valid Number](https://leetcode.com/problems/valid-number/)

> Hard

Validate if a given string can be interpreted as a decimal number.

Some examples:
`"0"` => `true`
`" 0.1 "` => `true`
`"abc"` => `false`
`"1 a"` => `false`
`"2e10"` => `true`
`" -90e3   "` => `true`
`" 1e"` => `false`
`"e3"` => `false`
`" 6e-1"` => `true`
`" 99e2.5 "` => `false`
`"53.5e93"` => `true`
`" --6 "` => `false`
`"-+3"` => `false`
`"95a54e53"` => `false`

**Note:** It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:

- Numbers 0-9
- Exponent - "e"
- Positive/negative sign - "+"/"-"
- Decimal point - "."

Of course, the context of these characters also matters in the input.

**Update (2015-02-10):**
The signature of the `C++` function had been updated. If you still see your function signature accepts a `const char *` argument, please click the reload button to reset your code definition.



**Solutions:**

It's a terrible problem :( . I even don't know what kind of `s` cannot be interpreted as a decimal number. 

Input cases are as following:

```
Input:
"0"               -> true
"0.1"             -> true
"abc"             -> false
"1 a"             -> false
"2e10"            -> true
"-90e3"           -> true
"1e"              -> false
"e3"              -> false
"6e-1"            -> true
"99e2.5"          -> false
"53.5e93"         -> true
"--6"             -> false
"-+3"             -> false
"95a54e53"        -> false
"+90.2e2.2"       -> false
".0"              -> true
"1."              -> true
"."               -> false
"e"               -> false
"1 "              -> true
". 1"             -> false
"4e+"             -> false
"0e "             -> false
" "               -> false
" -54.53061"      -> true
```

Here is my solution class:

```c++
class Solution {
public:
	bool isNumber(string s) {
		int len = s.size();
		bool exponent = false, decimal = false, number = false;
		int start = 0;
		while (start < len && s[start] == ' ') {
			start++;
		}
		while (len > 0 && s[len - 1] == ' ') {
			len--;
		}
		for (int i = start; i < len; ++i) {
			if (s[i] >= '0'&&s[i] <= '9') {
				number = true;
			}
			else if (s[i] == '+' || s[i] == '-') {
				if ((i != start && s[i - 1] != 'e') || i == len - 1)
					return false;
			}
			else if (s[i] == '.') {
				if (decimal)
					return false;
				else
					decimal = true;
			}
			else if (s[i] == 'e') {
				if (i == len - 1 || !number || exponent)
					return false;
				decimal = true;
				exponent = true;
			}
			else
				return false;
		}
		return number;
	}
};
```

