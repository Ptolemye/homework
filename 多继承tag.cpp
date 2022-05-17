#include <iostream>
#include <string>
#include <list>

using namespace std;

class Entity//Entity接口
{
public:
	virtual int getId() = 0;
	virtual int getKind() = 0;
};
class Taggable//Taggable接口
{
public:
	virtual void addTag(int tagId) = 0;
	virtual string getTags() = 0;
};

class Post :public Entity, public Taggable
{
private:
	int id;
	string title;
	string sql;
	int KIND;
public:
	Post(int id, string title) :id(id), title(title) { KIND = 1001; }
	int getId()
	{
		return id;
	}
	int getKind()
	{
		return KIND;
	}
	void addTag(int tagId)
	{
		int id = getId();
		int kind = getKind();
		sql = to_string(id) + "," + to_string(kind) + "," + to_string(tagId) + "\n";
	}
	string getTags()
	{
		return sql;
	}
};
int main()
{
	Post post1(1, "apple");
	post1.addTag(20);
	Post post2(2, "banana");
	post2.addTag(21);
	string sql = post1.getTags() + post2.getTags();
	cout << sql;
	return 0;
}