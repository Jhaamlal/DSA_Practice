#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

class AllSubArray
{

public:
    void solve(string &s, int &stringLength, int index, vector<string> &ans)
    {
        // edge case
        if (stringLength == 0)
            return;
        // Base case
        if (index > stringLength)
            return;
        // solve for one case
        for (int i = index; i < stringLength; i++)
        {
            /*
            => Very BIG Mistake I made here while calculating the subStr.
            */
            // string subString = s.substr(index, i);
            string subString = s.substr(index, i - index + 1);
            // cout << "sub string => " << subString << endl;
            ans.push_back(subString);
        }
        // recursive call
        solve(s, stringLength, ++index, ans);
    }
    void array(string s)
    {
        int stringLength = s.size();
        int index = 0;
        vector<string> ans = {};
        solve(s, stringLength, index, ans);
        // for (const auto &str : ans)
        //     cout << str << endl;

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    AllSubArray asa;
    cout << "Test Case 1: String = 'abc'" << endl;
    asa.array("abc");
    cout << "-------------------------" << endl;

    cout << "Test Case 2: String = '1234'" << endl;
    asa.array("1234");
    cout << "-------------------------" << endl;

    cout << "Test Case 3: String = 'test'" << endl;
    asa.array("test");
    cout << "-------------------------" << endl;

    return 0;
}
