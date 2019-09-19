#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Goods{
private:
  string name;
  int nums;
public:
	Goods() : nums(0) { }
	Goods(string name,int nums);
	void show();
	string getName() {
		  return name;
	}
	int getNum() {
		  return nums;
	}
	void addNum(int a) {
		  nums += a;
	}
	~Goods() {
  }
};


class GoodsList{
private:
  struct Node{
    Goods* goods;
    Node* next;
	Node() : goods(NULL), next(NULL) { }
  } *list;

  vector<Node> vec;

public:
  GoodsList();
  void insert(Goods* goods);
  void remove(string name, int nums);
  void show();
  void sort();
  int count();
  void clear();
  ~GoodsList() {

  }
};
