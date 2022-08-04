#include <iostream>
#include <string>

using namespace std;

class comp
{
private:
int img, allreals;


public:

comp(int _allreals, int _img)
{
allreals = _allreals;
img = _img;
}
comp operator+(comp const& other)
{
int allreals = this->allreals + other.allreals;
int img = this->img + other.img;
comp res(allreals, img);
return res;
}
comp operator-(comp const& other)
{
int allreals = this->allreals - other.allreals;
int img = this->img - other.img;
comp res(allreals, img);
return res;
}
comp operator*(comp const& other)
{
int allreals = this->allreals * other.allreals + (-1) * (this->img * other.img);
int img = this->allreals * other.img + other.allreals * this->img;
comp res(allreals, img);
return res;
}
comp operator/(comp const& other)
{
comp temp(this->allreals, this->img);
comp res1 = temp * other;
int div = other.allreals * other.allreals + other.img * other.img;
int allreals = res1.allreals / div;
int img = res1.img / div;
comp res(allreals, img);
return res;
}
friend ostream& operator << (ostream& os, const comp& other);
};

ostream& operator << (ostream& os, const comp& other)
{
os << other.allreals;
if (other.img > 0)
{
os << " + " << other.img << "i";
}
else if (other.img < 0)
{
os << " + " << other.img << "i";
}
os << endl;
return os;
};

comp readNum()
{
string img;
int allreals;
cin >> img;
cin >> allreals;

comp res(allreals, stoi(img.substr(0, img.size() - 1)));
return res;
}
int main()
{

string x;
string options;
cout << "Please enter ADD, SUB, MUL, DIV, followed by your four inputs(ADD 5i 2 3i 1)" << endl;
cin >> options;

if (options == "ADD")
{
comp one = readNum();
comp two = readNum();
comp ans1 = (one + two);

cout << ans1 << endl;
cout << "Enter PRI to repeat answer" << endl;
cin >> x;
if (x == "PRI")
{
cout << ans1 << endl;
}
}
else if (options == "SUB")
{
comp one = readNum();
comp two = readNum();
comp ans2 = (one - two);

cout << ans2 << endl;
cout << "Enter PRI to repeat answer" << endl;
cin >> x;
if (x == "PRI")
{
cout << ans2 << endl;
}

}
else if (options == "MUL")
{
comp one = readNum();
comp two = readNum();
comp ans3 = (one * two);

cout << ans3 << endl;
cout << "Enter PRI to repeat answer" << endl;
cin >> x;
if (x == "PRI")
{
cout << ans3 << endl;
}
}
else if (options == "DIV")
{
comp one = readNum();
comp two = readNum();
comp ans4 = (one / two);

cout << ans4 << endl;
cout << "Enter PRI to repeat answer" << endl;
cin >> x;
if (x == "PRI")
{
cout << ans4 << endl;
}
}
else if (options == "PRI")
{
	comp one = readNum();
	cout << one << endl;
}
else
{
cout << "Invaild Option Pick again!" << endl;
}


return 0;
}