#include <bits/stdc++.h>
using namespace std;

// int 2 string
string int2string(int i)
{
    return to_string(i);
}

// string 2 int
int string2int(string s)
{
    return stoi(s);
}

class Solution
{
public:
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        map<string, int> m;
        for (auto s : cpdomains)
        {
            int index = s.find(' ');
            int num = stoi(s.substr(0, index));
            string ds = s.substr(index + 1);

            while (index > 0)
            {
                m[ds] += num;
                index = ds.find('.');
                ds = ds.substr(index + 1);
            }
        }
        vector<string> res;
        for (auto &[x, y] : m)
        {
            res.push_back(to_string(y) + " " + x);
        }
    }
};

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int a = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    a++;
                }
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }

        int cnt = 0;
        int dir[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}};
        if (a == 0)
        {
            return 0;
        }
        while (!q.empty())
        {

            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto t = q.front();
                q.pop();
                for (int j = 0; j < 4; j++)
                {
                    int dx = t.first + dir[j][0];
                    int dy = t.second + dir[j][1];
                    if (dx >= 0 && dy >= 0 && dx < n && dy < m && grid[dx][dy] == 1)
                    {
                        a--;
                        grid[dx][dy] = 2;
                        q.push({dx, dy});
                    }
                }
            }
            cnt++;
        }
        if (a == 0)
        {
            return cnt - 1;
        }
        else
        {
            return -1;
        }
    }
}; /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        else if (l2 == nullptr)
            return l1;
        if (l1->val > l2->val)
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        else
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
    }
}; /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *t = nullptr;
        while (head)
        {
            ListNode *p = head->next;
            head->next = t;
            t = head;
            head = p;
        }
        return t;
    }
};