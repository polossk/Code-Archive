int main(){
	int i=0;BigInt a,b;char op;
	while (cin>>a>>op>>b){
		BigInt c;
		switch (op){
			case '/':{c=a/b;break;}
			case '%':{c=a%b;break;}
			default :break;
		}
		cout<<c<<endl;
	}
    return 0;
}