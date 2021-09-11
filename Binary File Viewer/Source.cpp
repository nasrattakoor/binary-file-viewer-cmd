#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

#define FIELD_WIDTH 6

using namespace std;

int main()
{
	string filePath;
	cout << "Enter full path of file: ";
	cin >> filePath;

	ifstream file(filePath, ios_base::in | ios_base::binary);
	if (!file.is_open())
	{
		cout << "File could not be opened." << endl;
		cin.get();
		return -1;
	}

	char* contents = new char[1024 * 100];
	file.read(contents, 1024 * 100);
	//contents[file.gcount()] = '\0';
	stringstream ss;
	for (size_t i = 0; i < file.gcount(); i++)
	{
		ss << "[" << to_string(contents[i]) << "] ";
	}
	cout << ss.str();
	cin.get();
}