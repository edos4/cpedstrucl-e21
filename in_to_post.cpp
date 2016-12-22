#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

int get_priority(char ch) {
   switch (ch) {
      case '/':
      case '*': return 2;
      case '+':
      case '-': return 1;
      default : return 0;
   }
}

void in_to_post(char infix[], char postfix[], int size) {
   stack<char> s;
   int weight;
   int i = 0;
   int k = 0;
   char ch;
   while (i < size) {
      ch = infix[i];
      if (ch == '(') {
         s.push(ch);
         i++;
         continue;
      }
      if (ch == ')') {
         while (!s.empty() && s.top() != '(') {
            postfix[k++] = s.top();
            s.pop();

         }
         if (!s.empty()) {
            s.pop();
         }
         i++;
         continue;
      }
      weight = get_priority(ch);
      if (weight == 0) {
         postfix[k++] = ch;
      }
      else {
         if (s.empty()) {
            s.push(ch);
         }
         else {
            while (!s.empty() && s.top() != '(' && weight <= get_priority(s.top())) {
               postfix[k++] = s.top();
               s.pop();
            }
            s.push(ch);
         }
      }
      i++;
   }
   while (!s.empty()) {
      postfix[k++] = s.top();
      s.pop();
   }
   postfix[k] = 0;  
}

int main() {
   char infix[] = "A-B+C*D";
   int size = strlen(infix);
   char postfix[size];
   
   in_to_post(infix,postfix,size);
   
   cout<<"Infix Expression: "<<infix<< endl;
   cout<<"Postfix Expression: "<<postfix << endl;
   return 0;
}
