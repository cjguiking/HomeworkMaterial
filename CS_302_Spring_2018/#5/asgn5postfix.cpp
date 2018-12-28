// Ceejay Guiking
// Assignment 4
// CS 302 - 1003
// 2/22/18

// This program will evaluate a postfix expression
// This program will treat every number as a single digit number.
// The program will not work if there are left over numbers with no more operands left.
#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
#include <string.h>

using namespace std;

// function returns value when a specific operator
// is found. The operator will be performed and a value
// will be returned after operator is performed.
int evalOperand(int op1, int op2, char operation){
	switch (operation) {
		case '*': return op2 * op1;
		case '/': return op2 / op1;
		case '+': return op2 + op1;
		case '-': return op2 - op1;
		default : return 0;
	}
}

//  value returns final value of the postfix expression
int Postfix(char post[]){
	stack<int> elem;
	int i = 0;
	char ch; 
	int final;
	while (post[i] != '$') {
		ch = post[i];
		if (isdigit(ch)){
			elem.push(ch - '0');
		}
		else {
			int op1 = elem.top();
			elem.pop();
			int op2 = elem.top();
			elem.pop();
			final = evalOperand(op1, op2, ch);
			elem.push(final);
		}
		i++;
	}
	return final;
}

int main(){
	int sizecheck;
	int finalval;
	string input;
	cout << "Enter a postfix expression ended with the char '$'" << endl;
	cin >> input;
	sizecheck = input.length();


	//	if input doesn't end with a '$' sign
	//	end the program		
	if (input[sizecheck-1] != '$') {
		cout << "postfix expression must end with a '$'" << endl;
		return 0;
	}
//	check if there are letters and return invalid statement	
	for (int i= 0; i < sizecheck; i++){
		if (input[i] >= 'A' && input[i] <= 'z'){
			cout << "This is not a valid postfix expression" << endl;
			return 0;
		}
		
	}
	
//	else 
//	start the program to evaluate postfix expression
//	must enter valid postfix expression
		char *post_array = new char[input.size() + 1];
		strcpy(post_array, input.c_str());
		finalval = Postfix(post_array);
		cout << "The value of this postfix expression is ";	
		cout << finalval << endl;
		delete[] post_array;
		return 0;
		
}