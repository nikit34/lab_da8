#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TSection {
	int left;
	int right;
	int id;
};

bool Compare (TSection &a, TSection &b) {
	return a.id < b.id;
}

void SelectorSection(vector<TSection> &section, int& m) {
	vector<TSection> answer;
	TSection begin;
	begin.left = 0;
	begin.right = 0;
	answer.push_back(begin);
    int max;
    int index;
    int section_size = section.size();
	while (answer.back().right < m) {
	    max = 0;
        index = -1;
		for (int i = 0; i < section_size; ++i) {
			if (section[i].left <= answer.back().right && section[i].right > answer.back().right) {
				if (section[i].right > max) {
					max = section[i].right;
					index = i;
				}
			}
		}
		if (index == -1) {
            cout << "0" << endl;
			return;
		} else {
            answer.push_back(section[index]);
		}
	}

	sort(answer.begin() + 1, answer.end(), Compare);

    int answer_size = answer.size();
	cout << answer_size - 1  << endl;
	for (int i = 1; i < answer_size; ++i) {
		cout << answer[i].left << " " << answer[i].right  << endl;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
    int m;
	cin >> n;
	vector<TSection> section(n);
	for (int i = 0; i < n; ++i) {
		section[i].id = i;
		cin >> section[i].left >> section[i].right;
	}
	cin >> m;

	SelectorSection(section, m);

	return 0;
}