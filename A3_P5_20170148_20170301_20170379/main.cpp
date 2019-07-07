#include<iostream>
#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;

const int maxsiz=50;

class Stack  {
private:
  char data[maxsiz],str[maxsiz];
  int top,length,counter;
  void pushData(char);
  char popData();

public:
  Stack() {
    top=-1;
    length=0;
    counter=0;
  }
  void getString();
  void checkPalindrome();
};

int main()
{
  Stack obj;
    cout << endl<< "This Is A Palindrome Checker Program" << endl;
    cout << "Please Enter Anything to Check" << endl;
    obj.getString();
    obj.checkPalindrome();
    return 0;
}

void Stack::getString() {
  cout<<endl<<" Enter a String: "<<endl;
  cin.getline(str,maxsiz);
  length=strlen(str);
}

void Stack::checkPalindrome() {
  for(int i=0; i<length; i++)
    pushData(str[i]);
  for(int i=0; i<length; i++) {
    if(str[i]==popData())
      counter++;
  }

    if(counter==length) cout<<endl<<" Entered string is a Palindrome. "<<endl;
  else  cout<<endl<<" Entered string is *NOT* a Palindrome. "<<endl;
}

void Stack::pushData(char temp) {
  if(top==maxsiz-1)  {
    cout<<"\n Stack Overflow!!!";
    return;
  }
  top++;
  data[top]=temp;
}

char Stack::popData() {
  if(top==-1)  {
    cout<<endl<<" Stack Underflow!!!"<<endl;
    char ch='\n';
    return ch;
  }
  char temp=data[top];
  top--;
  return temp;
}
