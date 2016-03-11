#include "stdafx.h"
#include "stdlib.h"
#include "./../src/BSTTransversals.cpp"
using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class BSTTransversalsSpec
	{
		;
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
		void Transversals_Nullcheck()
		{
			struct node *root= new_node_spec(5);
			int arr1[10];
			int ans[6];
			inorder(NULL, NULL);
			preorder(NULL, NULL);
			postorder(NULL, NULL);;
			postorder(root, NULL);
			inorder(root, NULL);
			preorder(root, NULL);
		};

		[TestMethod,Timeout(2000)]
		void Transversals_ThreeNums()
		{
			struct node *root = NULL;
			int nums[10] = { 2, 1, 3 };
			int elements = 3;
			for (int i = 0; i < 3; i++){
				root = add_node_spec(root, nums[i]);
			}

			int ans[3][3] = {
								{1,2,3},
								{2,1,3},
								{1,3,2}
			};
			int results[3][3];
			inorder(root, &results[0][0]);
			preorder(root, &results[1][0]);
			postorder(root, &results[2][0]);

			for (int i = 0; i < 3; i++){
				for (int j = 0; j < elements; j++){

					Assert::AreEqual(ans[i][j],results[i][j], L"TestCase Failed for 3", 1, 2);
				}
			}
		};

		[TestMethod, Timeout(2000)]
		void Transversals_FiveNums()
		{
			struct node *root = NULL;
			int nums[10] = {5,2,10,7,12 };
			int elements = 5;
			for (int i = 0; i < elements; i++){
				root = add_node_spec(root, nums[i]);
			}

			int ans[3][5] = {
				{ 2,5,7,10,12 },
				{ 5,2,10,7,12 },
				{ 2,7,12,10,5}
			};
			int results[3][5];
			int temp_inorder[5];
			inorder(root, results[0]);
			preorder(root, results[1]);
			postorder(root, results[2]);

			for (int i = 0; i < 1; i++){
				for (int j = 0; j < 4; j++){

					Assert::AreEqual(ans[i][j], results[i][j], L"TestCase Failed for FiveElems", 1, 2);
				}
			}

		};

		[TestMethod, Timeout(2000)]
		void Transversals_TenNums()
		{
			struct node *root = NULL;
			int nums[10] = { 30,10,60,40,70,65,80,67,90,85};
			int elements = 10;
			for (int i = 0; i < elements; i++){
				root = add_node_spec(root, nums[i]);
			}

			int ans[3][10] = {
				{ 10,30,40,60,65,67,70,80,85,90 },
				{ 30,10,60,40,70,65,67,80,90,85 },
				{ 10,40,67,65,85,90,80,70,60,30 }
			};
			int results[3][10];
			inorder(root, results[0]);
			preorder(root, results[1]);
			postorder(root, results[2]);

			for (int i = 0; i < 1; i++){
				for (int j = 0; j < 4; j++){

					Assert::AreEqual(ans[i][j], results[i][j], L"TestCase Failed for TenElems", 1, 2);
				}
			}

		};
		[TestMethod, Timeout(2000)]
		void Transversals_CustomTestCase()
		{
			struct node *root = NULL;
			int nums[10] = { 40,65,89,4,6,8,12,16,67,72};
			int elements = 10;
			for (int i = 0; i < elements; i++){
				root = add_node_spec(root, nums[i]);
			}
			/*
			int ans[3][10] = {
				{ Expected Inorder Array },
				{ Expected PreOrder Array },
				{ Expected PostOrder Array }
			};
			int results[3][10];
			inorder(root, results[0]);
			preorder(root, results[1]);
			postorder(root, results[2]);

			//Assert compares the First 2 parameters ,and raises Error if they are not equal
			for (int i = 0; i < 1; i++){
				for (int j = 0; j < 4; j++){
					Assert::AreEqual(ans[i][j], results[i][j], L"TestCase Failed for TenElems", 1, 2);
				}
			}
			*/

		};

	};
}
