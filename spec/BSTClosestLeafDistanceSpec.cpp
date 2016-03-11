//BSTClosestLeafDistance


#include "stdafx.h"
#include "./../src/BSTClosestLeafDistance.cpp"


using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;


namespace spec
{
	[TestClass]
	public ref class BSTClosestLeafDistanceSpec
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
		
		[TestMethod, Timeout(1000)]
		void BSTclosestNullCheck()
		{
			struct node *root = NULL;
			int nums[10] = { 2, 1, 4, 3 };

			for (int i = 0; i < 4; i++){
				root = add_node_spec(root, nums[i]);
			}
		
				Assert::AreEqual(-1, get_closest_leaf_distance(NULL,NULL), L"CLosest BST Failed Nullcheck", 1, 2);

				Assert::AreEqual(-1, get_closest_leaf_distance(root, NULL), L"CLosest BST Failed Nullcheck", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void BSTclosestSmallCase()
		{
			struct node *root = NULL;
			int nums[10] = { 2,1,4,3};

			for (int i = 0; i < 4; i++){
				root = add_node_spec(root, nums[i]);
			}
			struct node *temp = root->right;
			int ans = 1;
			int dist = get_closest_leaf_distance(root, temp);
			Assert::AreEqual(ans, dist, L"BST Closest Failed Smallcase", 1, 2);

		};

		[TestMethod, Timeout(1000)]
		void BSTclosestMediumCase()
		{
			struct node *root = NULL;
			int nums[10] = { 2, 1, 3, 4,5,6};

			for (int i = 0; i < 6; i++){
				root = add_node_spec(root, nums[i]);
			}
			struct node *temp = root->right;
			int ans = 2;
			int dist = get_closest_leaf_distance(root, temp);
			Assert::AreEqual(ans, dist, L"BST Closest Failed Medium Case", 1, 2);

		};
		[TestMethod, Timeout(2000)]
		void ClosestLeaf_LargeCase1()
		{
			struct node *root = NULL;
			int nums[20] = { 50, 25, 75, 15, 35, 
							 90, 5, 17, 45, 120,
							 1, 7, 19, 39, 49, 
							 100 ,20,21,22,23
							};

			for (int i = 0; i < 20; i++){
				root = add_node_spec(root, nums[i]);
			}
			
			int ans = 3;
			int dist = get_closest_leaf_distance(root, root->left->left->right);
			Assert::AreEqual(ans, dist, L"BST Closest Failed Large Case", 1, 2);
			
		};
		void ClosestLeaf_LargeCase2()
		{
			struct node *root = NULL;
			int nums[20] = { 50, 25, 75, 15, 35,
				90, 5, 17, 45, 120,
				1, 7, 19, 39, 49,
				100, 20, 21, 22, 23
			};

			for (int i = 0; i < 20; i++){
				root = add_node_spec(root, nums[i]);
			}

			int ans = 3;
			int dist = get_closest_leaf_distance(root,root);
			Assert::AreEqual(ans, dist, L"BST Closest Failed Large Case", 1, 2);

		};

		
	};
}
