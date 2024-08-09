//using odd indices for one stack even indices for another stack

class twoStacks {
public:
    int top1=-1; 
    int top2=0;
    static const int n=100;
    int arr[n];
    
    twoStacks(){}
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        if(top1<=n){
            top1=top1+2;
        arr[top1]=x;
        
        }
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
        if(top2<=n){
            top2=top2+2;
        arr[top2]=x;
        
        }
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(-1<top1)
        {
            int t1=arr[top1];
            top1=top1-2;
            return t1;
        }
        else{
            return -1;
        }
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
       if(0<top2)
        {
            int t2=arr[top2];
            top2=top2-2;
            return t2;
        }
        else{
            return -1;
        }
    }
};
