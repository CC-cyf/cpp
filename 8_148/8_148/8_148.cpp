#include<iostream>
using namespace std;

class User
{
private:
	char name[10][11];
	char pass[10][11];
public:
	User(const char * name1,const char * pass1);
	int login(char * name1, char * pass1);
	int AddUser(char * name1, char * pass1);
};
User::User(const char * name1, const char * pass1)
{
	for (int i = 0; i < 10; i++)
	{
		name[0][i] = name1[i];
		pass[0][i] = pass1[i];
	}
};
int User::login(char * name1, char * pass1)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		if (strcmp(name[i], name1) == 0) break;
	}
	if (strcmp(pass[i], pass1) == 0)return i;
	else return -1;
}
int User::AddUser(char * name1, char * pass1)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		if (name[i][0] <= 0)
		{
			for (int j = 0; j < 10; j++)
			{
				name[i][j] = name1[j];
				pass[i][j] = pass1[j];
				name[i][j + 1] = '\0';
				pass[i][j + 1] = '\0';
			}
			return i;
		}
	}
	return -1;
}

int main()
{
	char name[10], name1[10], pass[10], pass1[10];
	cin >> name >> pass >> name1 >> pass1;
	User user("LiWei", "liwei101");
	user.AddUser(name, pass);
	if (user.login(name1, pass1) >= 0)
	{
		cout << "Success Login!" << endl;
	}
	else
	{
		cout << "Login failed!" << endl;
	}
	return 0;
}