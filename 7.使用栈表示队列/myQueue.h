class MyQueue {
public:
    stack<int> stIn;        //输入栈
    stack<int> stOut;        //输出栈

    //入栈无返回，有参数
    void push(int x){
        stIn.push(x);//先加入输入栈
    }
    //出栈有返回，返回出栈的元素
    int pop(){
        //只有当stOut为空的时候，再从stIn里面导入全部数
        if(stOut.empty()){
            //从stIn导入数据直到stIn为空
            while(!stIn.empty()){
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        //出栈的有元素，可以出栈，临时保存栈顶
        int front = stOut.top();
        stOut.pop();
        return front;
    }

    int peek(){
        int res = this->pop();  //直接使用已有的pop函数
        stOut.push(res);    //因为pop函数弹出了元素res，所以在添加回去
        return res;
    }


    bool empty(){
        return stOut.empty()&&stIn.empty();
    }
};