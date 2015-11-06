int evalRPN(const char** tokens, int tokensSize) {
    if(!tokensSize) return 0;
    int num[tokensSize];
    int ln = -1;
    int val = 0;
    
    for(int i=0; i<tokensSize; i++) {
        //+-*/的ASCII码小于48，防止负数 
        if(**(tokens+i) < 48 && !*(*(tokens+i)+1)) {
            ln--;
            switch(**(tokens+i)) {
                case '+':
                    val = num[ln] + num[++ln];
                    break;
                case '-':
                    val = num[ln] - num[++ln];
                    break;
                case '/':
                    val = num[ln] / num[++ln];
                    break;
                case '*':
                    val = num[ln] * num[++ln];
                    break;
            }
            num[--ln] = val;            
        } else {    
            num[++ln] = atoi(*(tokens+i));
        }
    }
    return num[0];
}
