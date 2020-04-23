#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
* 2020-04-22
* Veronica
*/
class Solution {
public:
	int numDistinct(string s, string t) {
		if (s == "" || t == "")
			return 0;
		int lenS = s.size(), lenT = t.size();
		vector<vector<unsigned int>> nums(lenT, vector<unsigned int>(lenS, 0));
		if (t[0] == s[0])
			nums[0][0] = 1;
		for (int i = 1; i < lenS; ++i) {
			if (t[0] == s[i])
				nums[0][i] = nums[0][i - 1] + 1;
			else
				nums[0][i] = nums[0][i - 1];
		}
		for (int j = 1; j < lenT; ++j) {
			for (int i = 1; i < lenS; ++i) {
				if (t[j] == s[i]) {
					nums[j][i] = nums[j - 1][i - 1] + nums[j][i - 1];
				}
				else
					nums[j][i] = nums[j][i - 1];
			}
		}
		return nums[lenT - 1][lenS - 1];
	}
};

int main() {
	Solution solution;

	string s = "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo", t = "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";
	cout << solution.numDistinct(s, t) << endl;

	return 0;
}