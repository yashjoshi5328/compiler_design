#include<bits/stdc++.h>
using namespace std;

int main(){
	string reg;
	cin>>reg;
	int nfa[20][3]={{0}},j=1;
	int max_states=0;
	for(int i=0;i<reg.size();i++){
		if(reg[i]=='a'&&reg[i+1]!='*'&&reg[i+1]!='|'){nfa[j][0]=j+1; j++;}
		if(reg[i]=='b'&&reg[i+1]!='*'&&reg[i+1]!='|'){nfa[j][1]=j+1; j++;}
		if(reg[i]=='a'&&reg[i+1]=='|'&&reg[i+2]=='b'){
			nfa[j][2]=((j+1)*10)+j+3; j++;
			nfa[j][0]=j+1; j++;
			nfa[j][2]=j+3; j++;
			nfa[j][1]=j+1; j++;
			nfa[j][2]=j+1; j++;
			i+=2;
		}
		if(reg[i]=='b'&&reg[i+1]=='|'&&reg[i+2]=='a'){
			nfa[j][2]=((j+1)*10)+j+3; j++;
			nfa[j][1]=j+1; j++;
			nfa[j][2]=j+3; j++;
			nfa[j][0]=j+1; j++;
			nfa[j][2]=j+1; j++;
			i+=2;
		}
		if(reg[i]=='a'&&reg[i+1]=='*'){
			nfa[j][2]=((j+1)*10)+j+3; j++;
			nfa[j][0]=j+1; j++;
			nfa[j][2]=((j+1)*10)+j-1; j++;
		}
		if(reg[i]=='b'&&reg[i+1]=='*'){
			nfa[j][2]=((j+1)*10)+j+3; j++;
			nfa[j][1]=j+1; j++;
			nfa[j][2]=((j+1)*10)+j-1; j++;
		}
		if(reg[i]==')' && reg[i+1]=='*'){
			nfa[0][2]=((j+1)*10)+1;
			nfa[j][2]=((j+1)*10)+1; j++;
		}
	}
	cout<<"current\t"<<"input\t"<<"next state"<<endl;
	for(int i=0;i<=j;i++){
		if(nfa[i][0]!=0){
			cout<<"q["<<i<<"]"<<"\t a\t q["<<nfa[i][0]<<"]"<<endl;
		}
		if(nfa[i][1]!=0){
			cout<<"q["<<i<<"]"<<"\t b\t q["<<nfa[i][1]<<"]"<<endl;
		}
		if(nfa[i][2]!=0){
			if(nfa[i][2]<10) cout<<"q["<<i<<"]"<<"\t e\t q["<<nfa[i][2]<<"]"<<endl;
			else cout<<"q["<<i<<"]"<<"\t e\t q["<<nfa[i][2]%10<<"],q["<<nfa[i][2]/10<<"]"<<endl;
		}
	}
	return 0;
}