int romanToInt(char* s) {
    int i;
    int num = 0;
    for(i=0 ; s[i]!='\0' ; i++){
        int a=0;
        int b=0;
        if(s[i]=='I')a=1;
        if(s[i]=='V')a=5;
        if(s[i]=='X')a=10;
        if(s[i]=='L')a=50;
        if(s[i]=='C')a=100;
        if(s[i]=='D')a=500;
        if(s[i]=='M')a=1000;
        
        if(s[i+1]=='V')b=5;
        if(s[i+1]=='X')b=10;
        if(s[i+1]=='L')b=50;
        if(s[i+1]=='C')b=100;
        if(s[i+1]=='D')b=500;
        if(s[i+1]=='M')b=1000;

        if(a<b){
            num-=a;
        }else{
            num+=a;
        }

    }
    return num;
}