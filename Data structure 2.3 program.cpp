#include<iostream>
#include<stack>
#include<cctype>
using namespace std;

//function to return precendence of operators
int precedence(char ch){
	if(ch=='+'|| ch=='-')return 1;
	if(ch=='*'|| ch=='/')return 2;
	return 0;
}

//recursive funtion to convrert infix to postfix

void infixToPostfix(string infix,int index,stack<char>&st,string&postfix){
	
	//base condition(
	
	if(index==infix.length()){
		while(!st.empty()){
			st.pop();
			
		}
		
		return;
	}


char ch=infix[index];

//if operand,add to postfix

if(isalnum(ch)){
	postfix+=ch;
}

//if opening parenthesis
else if(ch==')'){
	while(!st.empty()&&st.top()!='('){
		postfix+=st.top();
		st.pop();
	}
	
	st.pop();//remove'('
}

//if operator
else{
	while(!st.empty()&&precedence(st.top())>=precedence(ch)){
		postfix+=st.top();
		st.pop();
	}
	
	st.push(ch);
}

//recursive call for next character
infixToPostfix(infix,index+1,st,postfix);

}

//function to evaluate postfix expression
int evalutePostfix(string postfix){
	stack<int>st;
	

			
			for(char ch : postfix){
				
				//if operand
				if(isdigit(ch)){
					st.push(ch - 0);
				}
				
				//if operand
				else{
					
					int b=st.top();st.pop();
					int a=st.top();st.pop();
					
					switch(ch){
						case'+':st.push(a+b);break;
						case'-':st.push(a-b);break;
						case'*':st.push(a*b);break;
						case'/':st.push(a/b);break;
					}
				}
			}
			return st.top();
		}
		
		//main function
		int main(){
			string infix,postfix="";
			stack<char>st;
			
			cout<<"Enter infix expression";
			cin>>infix;
			
			infixToPostfix(infix,0,st,postfix);
			
			cout<<"Postfix Expression:"<<postfix<<endl;
			cout<<"Evaluation Result:"<<evaluatePostfix(postfix);
			
			return 0;
		}

