#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct Person
{
	string name; int weight, father;
	Person() {}
	Person(string _name, int _weight, int _father) {
		name = _name; weight = _weight;
		father = _father;
	}
};

struct Group
{
	string head; int numOfPerson;
	int maxWeight, sumWeight;
	Group() {
		numOfPerson = 0; maxWeight = 0;
		sumWeight = 0;
	}
	bool operator<(const Group& that) const {
		return (head < that.head);
	}
};

vector<Person> persons;
// 并查集的两个操作
int getFather(int x)
{
	if (x != persons[x].father) {
		persons[x].father = getFather(persons[x].father);
	}
	return persons[x].father;
}
void unionSet(int x, int y)
{
	x = getFather(x);
	y = getFather(y);
	if (x != y) {
		persons[x].father = y;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	// 读入数据
	int N, K; cin >> N >> K;
	map<string, int> link; vector<Group> groups;
	string first, second; int weight, idx1, idx2;
	while (N--) {
		cin >> first >> second >> weight;
		// 按照first和second是否已经在分组里分成四个情况
		if (link.count(first) && link.count(second)) {
			idx1 = link[first]; idx2 = link[second];
			persons[idx1].weight += weight;
			persons[idx2].weight += weight;
		}
		else if (link.count(first) && !link.count(second)) {
			idx1 = link[first]; idx2 = persons.size();
			link[second] = idx2;
			persons.push_back(Person(second, weight, idx2));
			groups.push_back(Group());
			persons[idx1].weight += weight;
		}
		else if (!link.count(first) && link.count(second)) {
			idx1 = persons.size(); idx2 = link[second];
			link[first] = idx1;
			persons.push_back(Person(first, weight, idx1));
			groups.push_back(Group());
			persons[idx2].weight += weight;
		}
		else {
			idx1 = persons.size(); link[first] = idx1;
			idx2 = idx1 + 1; link[second] = idx2;
			persons.push_back(Person(first, weight, idx1));
			persons.push_back(Person(second, weight, idx2));
			groups.push_back(Group()); groups.push_back(Group());
		}
		unionSet(idx1, idx2);
		groups[idx1].sumWeight += weight;
	}

	// 处理数据：分组并得到结果
	int tf; int num = persons.size();
	set<Group> result;
	// 计算各分组的信息
	for (int i = 0; i < num; i++) {
		tf = getFather(i);
		groups[tf].numOfPerson++;
		if (tf != i) {
			groups[tf].sumWeight += groups[i].sumWeight;
		}
		if (groups[tf].maxWeight < persons[i].weight) {
			groups[tf].maxWeight = persons[i].weight;
			groups[tf].head = persons[i].name;
		}
	}
	// 找出符合要求的分组
	for (int i = 0; i < num; i++) {
		if (groups[i].sumWeight > K && groups[i].numOfPerson > 2) {
			result.insert(groups[i]);
		}
	}

	// 输出结果
	cout << result.size() << endl;
	set<Group>::iterator iter = result.begin();
	for (; iter != result.end(); iter++) {
		cout << (*iter).head << " " << (*iter).numOfPerson << endl;
	}
	return 0;
}