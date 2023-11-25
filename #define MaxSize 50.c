#define MaxSize 50
#define true 1
#define false 0

typedef struct{
    int top;
    int data[MaxSize];
}SqStack;

void InitStack(SqStack S){
    S.top = -1;
}

int StackEmpty(SqStack S){
    if (S.top == -1)
        return true;
    else
        return false;
}

int Push(SqStack S,int X){
    if (S.top == MaxSize - 1)
        return false;
    S.top ++ ;
    S.data[S.top] = X;
    return true;
}

int Pop(SqStack S,int X){
    if(S.top == -1)
        return false;
    X = S.data[S.top];
    S.top --;
    return true;
}

int GetTop(SqStack S,int X){
    if(S.top == -1)
        return false;
    X = S.data[S.top];
    return true;
}

