#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {

	vector<int> answer(id_list.size(), 0);
	int v[1000][1000] = { 0 };
	unordered_map<string, int> idx;
	unordered_map<string, set<string>> r;

	answer.resize(id_list.size());

	for (int i = 0;i < id_list.size();i++) idx[id_list[i]] = i;

	for (auto rep : report) {
		int flag = 0;
		string f, s;
		for (int i = 0;i < rep.size();i++) {
			if (flag)
				s += rep[i];
			else {
				if (rep[i] == ' ') {
					flag = 1;
					continue;
				}
				f += rep[i];
			}
		}
		r[s].insert(f);
	}

	for (auto rpp : r) {
		if (rpp.second.size() >= k) {
			for (auto rs : rpp.second) {
				answer[idx[rs]]++;
			}
		}
	}

	return answer;
}