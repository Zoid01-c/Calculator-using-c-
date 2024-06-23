#include <iostream.h>
#include <conio.h>

void main()
 {
  int num1;
  int num2;
  int ch;
  int res;
  clrscr();
  do
{
    cout << "Enter 1st value:";
    cin >> num1;
    cout << "Enter 2nd value:";
    cin >> num2;
    cout << "Enter your choice 1)Addition 2)Substraction 3)Multiplication 4)division 5)Exit:" << endl;
    cin >> ch;
    switch(ch)
{
  case 1:
  res = num1 + num2;
  cout << "Addition=" << res << endl;
  break;

  case 2:
  res = num1 - num2;
  cout << "Substraction=" << res << endl;
  break;

  case 3:
  res = num1 * num2;
  cout << "Multiplication=" << res << endl;
  break;

  case 4:
  if (num2 == 0)
 {
  cout << "Error: Division by zero is not allowed."<< endl;
  break;
 }
else
{
 res = num1 / num2;
 cout << "Division=" << res<<endl;
 break;
 }

 case 5:
 break;

 default:
 cout << "Enter valid choice" << endl;
 break;
 }
 } while(ch != 5);
}