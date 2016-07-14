int abs(int x){
    if(x<0) return -x;
    else return x;
}
struct sample {
    int pp, qq;
};

int exact(int a, int b){
   if(a%b==0) return b;
   int n=a%b;
   if(b%n==0) return n;
   else return exact(b,n);
}

void reduce(sample& r1) {
    int s1 = exact(abs(r1.pp), r1.qq);
    r1.pp = r1.pp/s1;
    r1.qq = r1.qq/s1;
    if(r1.qq < 0) {
         r1.pp= -r1.pp;
         r1.qq= -r1.qq;
    }
}

sample action1(sample d1, sample e1) {
    sample f1;
    f1.pp = d1.pp*e1.qq + e1.pp*d1.qq;
    f1.qq = d1.qq*e1.qq;
    reduce(f1); 
    return f1;
}

sample action2(sample d1, sample e1) {
    sample f1;
    f1.pp = d1.pp*e1.pp;
    f1.qq = d1.qq*e1.qq;
    reduce(f1);
    return f1;
}

int main(){
    sample num1, num2;
    num1.pp=8;
    num1.qq=16;
    num2.pp=4;
    num2.qq=14;
    reduce(num1);
    reduce(num2);
    int output1=action2(num1,num2).pp;
    int output2=action2(num1,num2).qq;
    int output3=action1(num1,num2).pp;
    int output4=action1(num1,num2).qq;
    return 0;
}
