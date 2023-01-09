class Solution {
public:
   
          int clambStair1(int n){
 25             if(n==0){
 26                 return 0;
 27             }
 28             if(n==1){
 29                 return 1;
 30             }
 31             return recursion(n-1)+recursion(n-2);
 32         }
 33 
34         int clambStair2(int n){
35             if(n==0 || n==1){
36                 return n;
37             }
38             int *array=new int(n+1);
39             array[0]=0;
40             array[1]=1;
41             for(int i=2;i<=n;i++){
42                 array[i]=array[i-1]+array[i-2];
43             }
44 
45             return array[n];
46         }
47 
48         int clambStair3(int n){
49             if(n==0 || n==1){
50                 return n;
51             }
52             int a,b,c;
53             a=0;
54             b=1;
55             for(int i=2;i<=n;i++){
56                 c=a+b;
57                 a=b;
58                 b=c;
59             }

    
};
