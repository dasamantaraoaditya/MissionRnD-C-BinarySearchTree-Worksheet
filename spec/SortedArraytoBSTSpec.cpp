#include "stdafx.h"
#include "./../src/SortedArraytoBST.cpp"


using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;


namespace spec
{
	[TestClass]
	public ref class SortedArraytoBSTSpec
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
		int get_height(struct node* node)
		{

			if (node == NULL)
				return 0;

			int lefth = get_height(node->left);
			int righth = get_height(node->right);
			if (lefth > righth){
				return 1 + lefth;
			}

			return 1 + righth;
		}
		int isBalanced(struct node *root)
		{

			if (root == NULL)
				return 1;

			int lefth;
			int righth;
			lefth = get_height(root->left);
			righth = get_height(root->right);

			int diff = lefth - righth;
			if (diff < 0){
				diff = diff*-1;
			}

			if (diff <= 1){
				int leftcheck = isBalanced(root->left);
				int rightcheck = isBalanced(root->right);

				if ((leftcheck == 1) && (rightcheck == 1)){
					return 1;
				}
			}

			return 0;
		}



		[TestMethod]
		void Rows_NullCheck()
		{
			struct node * temp = convert_array_to_bst(NULL, 1);
			
			if (temp != NULL){
				Assert::AreEqual(1, 2, L"Array to BST Null CheckFailed", 1, 2);
			}

		};
		[TestMethod, Timeout(1000)]
		void ArraytoBST_One()
		{
			int arr[10] = { 1, 2, 3, 4, 5 };
			struct node *root = NULL;
			root = convert_array_to_bst(arr, 1);
			int check = isBalanced(root);
			Assert::AreEqual(1, check, L"Array to BSt One failed", 1, 2);
		};

		[TestMethod, Timeout(2000)]
		void ArraytoBST_Three()
		{
			int arr[10] = { 1, 2, 3, 4, 5 };
			struct node *root = NULL;
			root = convert_array_to_bst(arr, 3);
			int check = isBalanced(root);
			Assert::AreEqual(1, check, L"Array to BSt Three failed", 1, 2);
		};

		[TestMethod, Timeout(2000)]
		void ArraytoBST_MediumCase0()
		{
			int arr[10] = { 1, 2, 3, 4, 5 };
			struct node *root = NULL;
			root = convert_array_to_bst(arr, 5);
			int check = isBalanced(root);
			Assert::AreEqual(1, check, L"Array to BST Three failed", 1, 2);
		};

		[TestMethod, Timeout(2000)]
		void ArraytoBST_MediumCase1()
		{
			int arr[10] = { 1,20,30,40,45,60,80,100 };
			struct node *root = NULL;
			root = convert_array_to_bst(arr, 8);
			int check = isBalanced(root);
			Assert::AreEqual(1, check, L"Array to BST Medium case 1 failed", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void ArraytoBST_Large()
		{
			int arr[10] = { -123, 12, 120, 455, 1160, 2100 ,4545,12124};
			struct node *root = NULL;
			root = convert_array_to_bst(arr, 8);
			int check = isBalanced(root);
			Assert::AreEqual(1, check, L"Array to BST Large case 1 failed", 1, 2);
		};

		
	};
}
