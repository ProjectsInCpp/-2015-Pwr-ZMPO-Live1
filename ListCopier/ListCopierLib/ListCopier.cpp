#include "stdafx.h"
#include "ListCopier.h"
#include <windows.h>

CListCopier::CListCopier()
{
	this->_memory = new vector<int*>();
}

CListCopier::CListCopier(CListCopier& aList)
{
	this->_memory = new vector<int*>();

	for (int i = ZERO;i < aList._memory->size();i++)
	{
		int buffReach = *(aList._memory->at(i));
		_memory->push_back(new int(buffReach));
	}
}

CListCopier& CListCopier::operator+(CListCopier &q)
{
	CListCopier* newListCopier = new CListCopier();

	for (int i = ZERO;i < this->GetVal()->size();i++)
		newListCopier->vAddInt(*(_memory->at(i)));

	for (int i = ZERO;i < q.GetVal()->size();i++)
		newListCopier->vAddInt(*(q._memory->at(i)));

	return *newListCopier;
}

CListCopier& CListCopier::operator=(CListCopier &q)
{
	_memory = q.GetVal();
	return *this;
}

string CListCopier::toString()
{
	string outVal = "";

	for (int i = ZERO;i < _memory->size();i++)
	{
		outVal += ToEqualsChar(*(_memory->at(i)));
		outVal += ",";
	}

	if (outVal.at(outVal.size() - 1) == ',')
		outVal.at(outVal.size() - 1) = ' ';

	return outVal;
}

void CListCopier::vAddInt(int iNewInt)
{
	_memory->push_back(new int(iNewInt));
}

vector<int*>* CListCopier::GetVal()
{
	vector<int*>* retVal = new vector<int*>(*_memory);
	return retVal;
}

CListCopier::~CListCopier()
{
	for (int i = ZERO;i < _memory->size();i++)
	{
		delete _memory->at(i);
		_memory->at(i) = nullptr;
	}

	delete _memory;
	_memory = nullptr;
}

char CListCopier::ToEqualsChar(int aValue0)
{
	char end = ZERO;

	if (aValue0 >= 10 && aValue0 <= 26)
	{
		end = aValue0 + 55;
	}
	else
		if (aValue0 >= 0 && aValue0 <= 9)
		{
			end = aValue0 + 48;
		}
		else
			end = -1;

	return end;
}
