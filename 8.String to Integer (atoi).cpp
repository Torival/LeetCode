/*
 *1.��Ҫ�����ַ������벻�������� 
 *2.��Ҫ��������������� 
 *
 */
int myAtoi(char* str) {
    int num = 0;
    int flag = 0;
	for(int i=0; str[i]!='\0'; i++) {
	    if(str[i]<='9' && '0'<=str[i]) {
	    	std::cout << 10*num+str[i]-'0'<<"\n";
	    	if(num>=INT_MAX/10 && ((num*10+str[i]-'0')<0 || (INT_MAX-(num*10+str[i]-'0'))/10)) { 
	  			return str[flag]=='-'?INT_MIN:INT_MAX;	
			}
			num = num*10+str[i]-'0';
		}
		else if(!num && str[i]==' ' && (!i || str[i-1]==' ')) ;
		else if(!num && (str[i]=='+' || str[i]=='-') && (!i || str[i-1]==' '))
			 flag = i;
		else break;
	}
	if(str[flag] == '-') num = -num;
	return num;
}

