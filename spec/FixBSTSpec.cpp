#include "stdafx.h"
#include "./../src/FixBST.cpp"


using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;


namespace spec
{
	[TestClass]
	public ref class FixBSTSpec
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
		void swap_nodes(struct node *a, struct node *b){
			int temp = a->data;
			a->data = b->data;
			b->data = temp;
		}
		[TestMethod]
		void FixBST_NullCheck()
		{
			fix_bst(NULL);

		};
		[TestMethod, Timeout(1000)]
		void FixBST_SmallCase()
		{
			struct node *root = NULL;
			int nums[10] = { 2,1,3};

			for (int i = 0; i < 3; i++){
				root = add_node_spec(root, nums[i]);
			}
			struct node *swaplist[2];
			int originaldata[2];
			swaplist[0] = root->left;
			swaplist[1] = root->right;
			originaldata[0] = swaplist[0]->data;
			originaldata[1] = swaplist[1]->data;

			swap_nodes(swaplist[0],swaplist[1]);

			fix_bst(root);

			for (int i = 0; i < 1; i++){
				Assert::AreEqual(originaldata[i],swaplist[i]->data, L"Fix BST Failed Smallcase", 1, 2);
			}
		};

		[TestMethod, Timeout(2000)]
		void FixBST_SmallCase2()
		{
			struct node *root = NULL;
			int nums[10] = { 2, 1, 3};

			for (int i = 0; i < 3; i++){
				root = add_node_spec(root, nums[i]);
			}
			struct node *swaplist[2];
			int originaldata[2];
			swaplist[0] = root;
			swaplist[1] = root->right;
			originaldata[0] = swaplist[0]->data;
			originaldata[1] = swaplist[1]->data;

			swap_nodes(swaplist[0], swaplist[1]);

			fix_bst(root);

			for (int i = 0; i < 1; i++){
				Assert::AreEqual(originaldata[i], swaplist[i]->data, L"Fix BST Failed Smallcase", 1, 2);
			}
		};
		
		[TestMethod, Timeout(2000)]
		void FixBST_SmallCase3()
		{
			struct node *root = NULL;
			int nums[10] = { 2, 1, 3 };

			for (int i = 0; i < 3; i++){
				root = add_node_spec(root, nums[i]);
			}
			struct node *swaplist[2];
			int originaldata[2];
			swaplist[0] = root->left;
			swaplist[1] = root;
			originaldata[0] = swaplist[0]->data;
			originaldata[1] = swaplist[1]->data;

			swap_nodes(swaplist[0], swaplist[1]);

			fix_bst(root);

			for (int i = 0; i < 1; i++){
				Assert::AreEqual(originaldata[i], swaplist[i]->data, L"Fix BST Failed Smallcase", 1, 2);
			}
		};
		[TestMethod, Timeout(2000)]
		void FixBST_MediumCase()
		{
			struct node *root = NULL;
			int nums[10] = { 7,5,10,8,6,4,1};

			for (int i = 0; i < 7; i++){
				root = add_node_spec(root, nums[i]);
			}
			struct node *swaplist[2];
			int originaldata[2];
			swaplist[0] = root->left->left->left;
			swaplist[1] = root->right;
			originaldata[0] = swaplist[0]->data;
			originaldata[1] = swaplist[1]->data;

			swap_nodes(swaplist[0], swaplist[1]);

			fix_bst(root);

			for (int i = 0; i < 1; i++){
				Assert::AreEqual(originaldata[i], swaplist[i]->data, L"Fix BST Failed Mediumcase", 1, 2);
			}
		};
		[TestMethod, Timeout(2000)]
		void FixBST_MediumCase2()
		{
			struct node *root = NULL;
			int nums[10] = { 8, 5, 10, 9, 6, 4, 1,7 };

			for (int i = 0; i < 8; i++){
				root = add_node_spec(root, nums[i]);
			}
			struct node *swaplist[2];
			int originaldata[2];
			swaplist[0] = root->left->left->left;
			swaplist[1] = root->left->right->right;
			originaldata[0] = swaplist[0]->data;
			originaldata[1] = swaplist[1]->data;

			swap_nodes(swaplist[0], swaplist[1]);

			fix_bst(root);

			for (int i = 0; i < 1; i++){
				Assert::AreEqual(originaldata[i], swaplist[i]->data, L"Fix BST Failed Mediumcase", 1, 2);
			}
		};
		[TestMethod, Timeout(2000)]
		void FixBST_LargeCase()
		{
			struct node *root = NULL;
			int nums[20] = { 50,25,75,15,35,90,5,17,45,120,1,2,19,39,49,100};

			for (int i = 0; i < 16; i++){
				root = add_node_spec(root, nums[i]);
			}
			struct node *swaplist[2];
			int originaldata[2];
			swaplist[0] = root->left->right->right->left;
			swaplist[1] = root->right->right->right->left;
			originaldata[0] = swaplist[0]->data;
			originaldata[1] = swaplist[1]->data;

			swap_nodes(swaplist[0], swaplist[1]);

			fix_bst(root);

			for (int i = 0; i < 1; i++){
				Assert::AreEqual(originaldata[i], swaplist[i]->data, L"Fix BST Failed Largecase", 1, 2);
			}
		};
		[TestMethod, Timeout(2000)]
		void FixBST_LargeCase2()
		{
			struct node *root = NULL;
			int nums[20] = { 50, 25, 75, 15, 35, 90, 5, 17, 45, 120, 1, 2, 19, 39, 49, 100 };

			for (int i = 0; i < 16; i++){
				root = add_node_spec(root, nums[i]);
			}
			struct node *swaplist[2];
			int originaldata[2];
			swaplist[0] = root->left->left->right->right;
			swaplist[1] = root;
			originaldata[0] = swaplist[0]->data;
			originaldata[1] = swaplist[1]->data;

			swap_nodes(swaplist[0], swaplist[1]);

			fix_bst(root);

			for (int i = 0; i < 1; i++){
				Assert::AreEqual(originaldata[i], swaplist[i]->data, L"Fix BST Failed Largecase 2", 1, 2);
			}
		};
	};
}
