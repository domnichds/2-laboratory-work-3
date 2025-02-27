#include <iostream>
#include <string>

using namespace std;

class School
{
protected:
	string name;
	unsigned int number_of_student;
public:
	School(const string& name, const unsigned int number_of_student)
	{
		this->name = name;
		this->number_of_student = number_of_student;
	}
	virtual void printInfo()
	{
		cout << "Название школы: " << this->name << endl
			<< "Количество учеников: " << this->number_of_student << endl;
	}
};
class SpecialSchool : public School
{
private:
	string type;
public:
	SpecialSchool(const string& name, const unsigned int number_of_student, const string& type) : School(name, number_of_student)
	{
		this->type = type;
	}
	void printInfo()
	{
		School::printInfo();
		cout << "Название специализации: " << this->type << endl;
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");

	//Статический полиморфизм
	cout << "Статический полиморфизм" << endl;
	School ob1("2109", 2000);
	ob1.printInfo();
	cout << endl;
	SpecialSchool ob2("1580", 3000, "Ingener");
	ob2.printInfo();
	cout << endl;

	//Динамический полиморфизм
	cout << "Динамичекий полиморфизм" << endl;
	School* dynamic_ob1 = &ob1;
	School* dynamic_ob2 = &ob2;
	ob1.printInfo();
	cout << endl;
	ob2.printInfo();
}