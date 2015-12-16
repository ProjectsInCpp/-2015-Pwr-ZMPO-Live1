#pragma once
#include <vector>
#include <string>

#define ZERO 0
using namespace std;

class CListCopier
{
private:
	vector<int*>* _memory = nullptr;

public:
	void vAddInt(int iNewInt);
	char ToEqualsChar(int aValue0);
	string toString();
	vector<int*>* GetVal();

	CListCopier& operator+ (CListCopier &q);
	CListCopier& operator= (CListCopier &q);

	CListCopier();
	CListCopier(CListCopier& aList);
	~CListCopier();
};

