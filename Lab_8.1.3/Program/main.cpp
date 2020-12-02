// Lab_8_1_3
// використання стандартних функцій для рядків char[]

#include <iostream>
#include <string>
using namespace std;

int count_strs(char* str) {
	if (strlen(str) < 3)
		return 0;

	int count = 0;
	char* pos = str;
	while (pos = strchr(pos, ',')) 
		if (*(++pos + 1) == '-')
			count++;
	return count;
}

void change_str(char* str)
{
	if (strlen(str) < 3)
		return;

	char *tmp = new char[strlen(str) + 1]{ 0 },
		 *pos = str, 
		 *pos2 = str;
	while (pos = strchr(pos2, ',')) 
		if (*(pos + 2) == '-') {
			strncat(tmp, pos2, pos - pos2);
			strcat(tmp, "**");
			pos2 = pos + 3;
		}
	strcat(tmp, pos2);
	strcpy(str, tmp);
	delete[] tmp;
}

int main()
{
	//char str[101] = "asdasdasd,s-sadsada,s-sfsdfsdfsdf";
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << count_strs(str) << " groups of ', -'" << endl;
	change_str(str);
	cout << "Modified string (param) : " << str << endl;
	return 0;
}