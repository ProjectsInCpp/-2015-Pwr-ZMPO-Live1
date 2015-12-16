#include "stdafx.h"
#include "CppUnitTest.h"
#include <windows.h>
#include "ListCopier.h"
//#include <Decimal.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ValuesTests
{
	TEST_CLASS(CListCopier_Test)
	{
	public:

		TEST_METHOD(AliasVsCopy_FalseTest)
		{
			// arrange	
			int a = 3;
			int* aP1 = &a;
			int* aP2 = new int(a);

			bool result = !(aP1 == aP2);

			Assert::IsTrue(result);
		}

		TEST_METHOD(AliasVsCopy_TrueTest)
		{
			// arrange	
			int a = 3;
			int* aP1 = &a;
			int* aP2 = new int();
			aP2 = &a;

			bool result = (aP1 == aP2);

			Assert::IsTrue(result);
		}

		TEST_METHOD(ListyAdd)
		{
			// arrange	
			CListCopier c_list_0, c_list_1, c_list_sum;//na starcie obie listy s¹ puste
			c_list_0.vAddInt(0);
			c_list_0.vAddInt(1);
			c_list_0.vAddInt(2);
			c_list_0.vAddInt(3);

			c_list_1.vAddInt(5);
			c_list_1.vAddInt(6);
			c_list_1.vAddInt(7);

			vector<int>* expected1 = new vector<int>();
			bool reachedBool1 = true;

			expected1->push_back(0);
			expected1->push_back(1);
			expected1->push_back(2);
			expected1->push_back(3);

			int i = 0;
			//DebugBreak();

			// act
			for (int i = 0;i < c_list_0.GetVal()->size();i++)
			{
				int buffReach = *(c_list_0.GetVal()->at(i));
				int buffExpect = expected1->at(i);
				reachedBool1 &= buffReach == buffExpect;
			}

			// assert

			expected1 = nullptr;

			Assert::IsTrue(reachedBool1);
		}

		TEST_METHOD(ListyCopyCTOR)
		{
			// arrange	
			CListCopier c_list_0, c_list_1, c_list_sum;//na starcie obie listy s¹ puste
			c_list_0.vAddInt(0);
			c_list_0.vAddInt(1);
			c_list_0.vAddInt(2);
			c_list_0.vAddInt(3);

			//DebugBreak();
			CListCopier c_list_2(c_list_0);

			vector<int>* expected1 = new vector<int>();
			bool reachedBool1 = true;

			expected1->push_back(0);
			expected1->push_back(1);
			expected1->push_back(2);
			expected1->push_back(3);

			int i = 0;
			// act
			for (int i = 0;i < c_list_0.GetVal()->size();i++)
			{
				int buffReach = *(c_list_0.GetVal()->at(i));
				int buffExpect = expected1->at(i);
				reachedBool1 &= buffReach == buffExpect;
			}

			// assert

			expected1 = nullptr;

			Assert::IsTrue(reachedBool1);
		}

		TEST_METHOD(ListyToString)
		{
			// arrange	
			CListCopier c_list_0, c_list_1, c_list_sum;//na starcie obie listy s¹ puste
			c_list_0.vAddInt(0);
			c_list_0.vAddInt(1);
			c_list_0.vAddInt(2);
			c_list_0.vAddInt(3);

			c_list_1.vAddInt(5);
			c_list_1.vAddInt(6);
			c_list_1.vAddInt(7);

			vector<int>* expected1 = new vector<int>();
			bool reachedBool1 = true;
			string reached = c_list_0.toString();
			string expected = "0,1,2,3";

			int i = 0;
			// act

			for (size_t i = 0; i < expected.size(); i++)
			{
				reachedBool1 &= expected.at(i) == reached.at(i);
			}

			// assert

			Assert::IsTrue(reachedBool1);
		}

		TEST_METHOD(ListyAddOperator)
		{
			// arrange	
			CListCopier c_list_0, c_list_1, c_list_sum;//na starcie obie listy s¹ puste
			c_list_0.vAddInt(0);
			c_list_0.vAddInt(1);
			c_list_0.vAddInt(2);
			c_list_0.vAddInt(3);

			c_list_1.vAddInt(5);
			c_list_1.vAddInt(6);
			c_list_1.vAddInt(7);

			vector<int>* expected1 = new vector<int>();
			expected1->push_back(0);
			expected1->push_back(1);
			expected1->push_back(2);
			expected1->push_back(3);
			expected1->push_back(5);
			expected1->push_back(6);
			expected1->push_back(7);

			bool reachedBool1 = true;
			c_list_sum = c_list_0 + c_list_1;
			// act

			for (size_t i = 0; i < expected1->size(); i++)
			{
				int fst = expected1->at(i);
				int snd = *(c_list_sum.GetVal()->at(i));
				reachedBool1 &= fst == snd;
			}

			// assert

			Assert::IsTrue(reachedBool1);
		}
	};
}