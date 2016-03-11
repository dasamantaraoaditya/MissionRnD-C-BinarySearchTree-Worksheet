#include "stdafx.h"
#include "./../src/BSTRows.cpp"


using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;


namespace spec
{
	[TestClass]
	public ref class BSTRowsSpec
	{
	private:
		TestContext^ testContextInstance;

	public:
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

#pragma region Additional test attributes
		//
		//You can use the following additional attributes as you write your tests:
		//
		//Use ClassInitialize to run code before running the first test in the class
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//Use ClassCleanup to run code after all tests in a class have run
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//Use TestInitialize to run code before running each test
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//Use TestCleanup to run code after each test has run
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
#pragma endregion 

		struct node * new_node_spec(int data){
			struct node *temp = (struct node *)malloc(sizeof(struct node));
			temp->data = data;
			temp->left = NULL;
			temp->right = NULL;
			return temp;
		}
		struct node * add_node_spec(struct node *root, int data){
			if (root == NULL) return new_node_spec(data);

			if (data < root->data)
				root->left = add_node_spec(root->left, data);
			else if (data > root->data)
				root->right = add_node_spec(root->right, data);

			return root;
		}
		
		[TestMethod]
		void Rows_NullCheck()
		{
			int *arr = BSTRighttoLeftRows(NULL);
			//Assert::IsNull(arr);
			if (arr != NULL){
				Assert::AreEqual(1, 2, L"Rows Null CheckFailed", 1, 2);
			}
			
		};
		[TestMethod,Timeout(1000)]
		void Rows_OneElement()
		{
			struct node *root = (struct node *)malloc(sizeof(struct node));
			root->data = 6;
			root->left = NULL;
			root->right = NULL;
			int *arr = BSTRighttoLeftRows(root);
			int ans[1] = { 6 };
			int len = 1;
			for (int i = 0; i < len; i++){
				Assert::AreEqual(ans[i], arr[i], L"Rows Fail One element", 1, 2);
			}
		};
		[TestMethod, Timeout(2000)]
		void Rows_ThreeElement()
		{
			struct node *root = NULL;
			int nums[10] = { 10, 5, 12, 12, 15 };

			for (int i = 0; i < 3; i++){
				root = add_node_spec(root, nums[i]);
			}


			int *arr = BSTRighttoLeftRows(root);
			int ans[5] = { 10, 12, 5};
			int len = 3;
			for (int i = 0; i < len; i++){
				Assert::AreEqual(ans[i], arr[i], L"Rows Fail Three element", 1, 2);
			}
		};
		[TestMethod, Timeout(2000)]
		void Rows_FiveElements2()
		{
			struct node *root = new_node_spec(6);
			root->left = new_node_spec(5);
			root->left->left= new_node_spec(4);
			root->left->left->left = new_node_spec(3);
			root->left->left->left->left = new_node_spec(-10);

			int *arr= BSTRighttoLeftRows(root);
			int ans[5] = { 6,5,4,3,-10};
			int len = 5;
			for (int i = 0; i < len; i++){
				Assert::AreEqual(ans[i], arr[i], L"Rows Fail Five element", 1, 2);
			}

		};
		[TestMethod, Timeout(2000)]
		void Rows_MediumCase2()
		{
			struct node *root = NULL;
			int nums[10] = { 100,200,300,400,500 };

			for (int i = 0; i < 5; i++){
				root = add_node_spec(root, nums[i]);
			}


			int *arr = BSTRighttoLeftRows(root);
			int ans[5] = { 100,200,300,400,500 };
			int len = 5;
			for (int i = 0; i < len; i++){
				Assert::AreEqual(ans[i], arr[i], L"Rows Fail Five element", 1, 2);
			}

		};

		[TestMethod, Timeout(2000)]
		void Rows_MediumCase3()
		{
			struct node *root=NULL;
			int nums[10] = { 10, 5, 7, 12, 15 };

			for (int i = 0; i < 5; i++){
				root = add_node_spec(root, nums[i]);
			}


			int *arr = BSTRighttoLeftRows(root);
			int ans[5] = { 10,12,5,15,7 };
			int len = 5;
			for (int i = 0; i < len; i++){
				Assert::AreEqual(ans[i], arr[i], L"Rows Fail Five element", 1, 2);
			}

		};
		[TestMethod, Timeout(2000)]
		void Rows_LargeCase()
		{
			struct node *root = NULL;
			int nums[10] = { 50,25,75,30,27,60,99,53,51,57};

			for (int i = 0; i < 10; i++){
				root = add_node_spec(root, nums[i]);
			}


			int *arr = BSTRighttoLeftRows(root);
			int ans[10] = { 50,75,25,99,60,30,53,27,57,51 };
			int len = 10;
			for (int i = 0; i < len; i++){
				Assert::AreEqual(ans[i], arr[i], L"Rows Fail Large case ", 1, 2);
			}

		};
	};
}
