//HeightofBST
#include "stdafx.h"
#include "./../src/HeightofBST.cpp"


using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;


namespace spec
{
	[TestClass]
	public ref class HeightofBSTSpec
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
		
		[TestMethod,Timeout(2000)]
		void Height_Nullcheck(){
			get_height(NULL);
			get_left_subtree_sum(NULL);
			get_right_subtree_sum(NULL);
		}
		[TestMethod, Timeout(2000)]
		void Height_Small(){
			struct node *root = NULL;
			int nums[20] = {10,5,15};

			for (int i = 0; i < 3; i++){
				root = add_node_spec(root, nums[i]);
			}

			int h=get_height(root);
			int ls=get_left_subtree_sum(root);
			int rs=get_right_subtree_sum(root);
			int ans[3] = { 2, 5, 15 };
			int actualans[3] = { h, ls, rs };

			for (int i = 0; i < 3; i++){
				Assert::AreEqual(ans[i],actualans[i],L"HeightBST Small Failed", 1, 2);
			}
		}
		[TestMethod, Timeout(2000)]
		void Height_Medium(){
			struct node *root = NULL;
			int nums[20] = { 10, 2,1, 15 ,25,100,300};
		
			for (int i = 0; i < 7; i++){
				root = add_node_spec(root, nums[i]);
			}

			int h = get_height(root);
			int ls = get_left_subtree_sum(root);
			int rs = get_right_subtree_sum(root);
			int ans[3] = { 5, 3, 440 };
			int actualans[3] = { h, ls, rs };

			for (int i = 0; i < 3; i++){
				Assert::AreEqual(ans[i], actualans[i], L"HeightBST Medium Failed", 1, 2);
			}
		}
		[TestMethod, Timeout(2000)]
		void Height_Large(){
			struct node *root = NULL;
			int nums[20] = { 1,2,3,4,5,6,7,8,9,10};

			for (int i = 0; i < 10; i++){
				root = add_node_spec(root, nums[i]);
			}

			int h = get_height(root);
			int ls = get_left_subtree_sum(root);
			int rs = get_right_subtree_sum(root);
			//
			int ans[3] = { 10,0,54};

			int actualans[3] = { h, ls, rs };

			for (int i = 0; i < 3; i++){
				Assert::AreEqual(ans[i], actualans[i], L"HeightBST Large Failed", 1, 2);
			}
		}
		
	};
}
