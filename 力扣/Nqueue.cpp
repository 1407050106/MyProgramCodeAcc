#include <iostream>
#include <vector>
using namespace std;
// �Ȱ�������Ҳ������¼ȫ����������ַ�������!
class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        if (n==1) 
        {
            vector<string> res1;
            res1.push_back("Q");
            vector<vector<string>> res2;
            res2.push_back(res1);
            return res2;
        }
        if (n<4) return{}; 
        vector<string> ans;
        vector<int> record;
        record.resize(n);
        int counts = process1(0, record, n, ans);
        return res;
    }

    int process1(int i, vector<int> record, int n, vector<string>& ans) {  // ��ͼ���������������i��
		if (i == n) {
            res.push_back(ans);
            return 1;
		}
		int resm=0;
		for (int j = 0; j < n; j++) {
			// �����֮ǰ�Ļʺ󲻴�ܣ��ͼ�¼һ�£�Ȼ�����ͳ��ȥ�ɡ������ܣ���һ�У�
			if (isValid(record, i, j)) {
				record[i] = j;
                string temp = recordQ(n, j);
                // cout<<temp<<endl;
                ans.push_back(temp);
				resm+=process1(i + 1, record, n, ans);
                ans.pop_back();
			}
		}
        return resm;
	}

    string recordQ(int n, int j)
    {
        string res="";
        for (int i=0; i<n; i++)
        {
            if (i==j)
            {
                res+="Q";
                continue;
            }
            res+=".";
        }
        return res;
    }

    bool isValid(vector<int> record, int i, int j) { // ��i��j�еĻʺ��֮ǰ����
		// 0..i-1
		for (int k = 0; k < i; k++) {  // ����record��ļ�¼
			// ������ֹ��л��߹�б��
			if (j == record[k] || abs(record[k] - j) == abs(i - k)) {
				return false;
			}
		}
		return true;
	}

    int getnums(int n)
    {
        if (n<1) return 0;
        vector<int> record;
        record.resize(n);
        return process2(0, record, n);
    }

    int process2(int i, vector<int> record, int n) {  // ��ͼ���������������i��
		if (i == n) {
            return 1;
		}
		int resm=0;
		for (int j = 0; j < n; j++) {
			// �����֮ǰ�Ļʺ󲻴�ܣ��ͼ�¼һ�£�Ȼ�����ͳ��ȥ�ɡ������ܣ���һ�У�
			if (isValid(record, i, j)) {
				record[i] = j;
				resm+=process2(i + 1, record, n);
			}
		}
        return resm;
	}
};

int main() {
    vector<vector<string>> res;
    Solution sc;
    res=sc.solveNQueens(5);
    int m=res.size(), n=res[0].size();
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout<<res[i][j]<<" ";
        }
        printf("\n");
    }

    cout<<sc.getnums(5)<<endl;   // no problem
}