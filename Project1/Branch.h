#pragma once
class Branch
{
	int value;
	int weight;
	Branch *left;
	Branch *right;
public:
	Branch();
	Branch(const int &x) {
		value = x;
		Branch();
	}
	virtual ~Branch();
	void Add(const int &x);
	Branch* FindPlace(const int &x);


};

