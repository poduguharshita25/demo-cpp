#include<iostream>

#include<stack>

#include<CCtype>

using namespace std;

//function to return precedence of operators
int precedence(char op){
	if(op=='+'|| op=='-')return 1;
	if(op=='*'|| op=='/')return 2;
    
}

//function to apply an operator of two operators
int applyoperator(int a, int b,char op){
	switch(op){
		case'+':return a+b;
		case'-':return a-b;
		case'*':return a*b;
		case'/':return a/b;
	}
	
	return 0;
	
}

//function to evaluate infix expression
int evaluateExpression(string exp){
	stack<int>values; //stack for operands
	stack<char>operators;//stack for operands
	
	for(int i=0;i<exp.length();i++){
		
		//skip spaces
		if(isdigit(exp[i])){
			int val=0;
			while(i<exp.length()&&isdigit(exp[i])){
				val=val*10+(exp[i]-'0');
				i++;
			}
			values.push(val);
			
			i--;
		}
		
		//if opening parenthesis
		else if(exp[i]=='('){
			operators.push(exp[i]);
		}
		
		//is closing parenthesis
		else if(exp[i]==')'){
			operators.push(exp[i]);
		}
		
		//if closing parenthesis
		else if(exp[i]==')'){
			while(!operators.empty()&&operators.top()!='('){
				int b=values.top();values.pop();
				int a=values.top();values.pop();
				char op=operators.top();operators.pop();
				values.push((a,b,op));
			}
			
			operators.pop();//Remove'('
		}
		
		//if operator
		else{
			
			while(!operators.empty()&&
			precedence(operators.top())>=(exp[i])){
				
				int b=values.top();values.pop();
				int a=values.top();values.pop();
				char op=operators.top();operators.pop();
				values.push((a,b,op));
				
			}
			
			operators.push(exp[i]);
		}
	}
	
	//Apply remaining operators
	while(!operators.empty()){
		int b=values.top();values.pop();
		int a=values.top();values.pop();
		char op=operators.top();operators.pop();
		values.push((a,b,op));
	}
	
	return values.top();
	
} 

int main(){
	string expression;
	cout<<"Enter mathematical expression:";
	getline(cin,expression);
	
	cout<<"Result="<<evaluateExpression(expression);\
	
	return 0;
}
