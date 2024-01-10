#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;

void Merge_arrays(int a[], int b[],int c[]);
void sort(int a[]);
void Common(int a[], int b[],int l1,int l2);
bool is_Palindrome(string& user_string);

int main()
{
	srand(time(0));

	int array_1[5];
	int array_2[7];
	int array_3[12];
	string user_string = "";
	
	cout << "\n\n------------------Array 1---------------------\n\n";
	cout << "\n--------------------------------------------------------------------------------------------------------\n";

	for (int i = 0; i < 5; i++)
	{
		array_1[i] = rand() % 20 + 1;
		cout << array_1[i] << "\t";
	}
	cout << "\n--------------------------------------------------------------------------------------------------------\n";

	cout << "\n\n------------------Array 2---------------------\n\n";
	cout << "\n--------------------------------------------------------------------------------------------------------\n";

	for (int i = 0; i < 7; i++)
	{
		array_2[i] = rand() % 20 + 1;
		cout << array_2[i] << "\t";
	}
	cout << "\n--------------------------------------------------------------------------------------------------------\n";

	Merge_arrays(array_1, array_2,array_3);
	

	cout << "\n\n--------------Merged Array in Ascending Order--------------\n\n";
	cout << "--------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < 12; i++)
	{
		cout << array_3[i] << "\t";
	}
	cout << "\n--------------------------------------------------------------------------------------------------------\n";

	Common(array_1, array_2, 5, 7);
	
	cout << "\n\nEnter a sentence(without spaces, enter all the letters in lower or upper case) : ";
	getline(cin, user_string);

	cout << "\n\n------------Palindrome Check---------------\n";

	if (is_Palindrome(user_string))
	{
		cout << "\nEntered sentence is a Palindrome";
	}
	else
	{
		cout << "\nEntered sentence is not a Palindrome";
	}
	
	cout << endl << endl;
	system("pause");
	return 0;
}

void Merge_arrays(int a[], int b[],int c[])
{
	for (int i = 0; i < 5; i++)
	{
		c[i] = a[i];
	}
	for (int j = 5; j < 12; j++)
	{
		c[j] = b[j - 5];
	}
	sort(c);
}

void sort(int a[])
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = i + 1; j < 12; j++)
		{
			if (a[j] < a[i])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void Common(int a[], int b[],int l1,int l2)
{
	bool flag = false;
	
	cout << "\n\n----------------Common Elements of Array 1 & 2------------------\n\n";
	cout << "\n--------------------------------------------------------------------------------------------------------\n";

	for (int i = 0; i < l1 ; i++)
	{
		for (int j = 0; j < l2; j++)
		{
			if (a[i] == b[j])
			{
				cout << a[i] << "\t";
				flag = true;
				break;
			}
		}
	}
	if (flag == false)
	{
		cout << "No common elements found in Array1 and Array2";
	}
	cout << "\n--------------------------------------------------------------------------------------------------------\n";
	
}
bool is_Palindrome(string& user_string)
{
	int j = user_string.length() - 1;

	for (int i = 0; i < j; i++)
	{
		if (user_string[i] != user_string[j])
		{
			return false;
		}
		j--;
	}
	return true;
}