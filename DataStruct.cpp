#define MaxSize 50
typedef struct SqList{
    int data[MaxSize];
    int Length;
}SqList;

typedef struct SqStack{
    int data[MaxSize];
    int top;
}SqStack;

typedef struct SqQueue{
    int data[MaxSize];
    int *front, *rear;
}SqQueue;

typedef struct LNODE{
    int data;
    LNODE * next;
}LNODE, *LinkList; //LNODE List 插入元素；

typedef struct LinkStack{
    int data;
    LinkStack *next;
}*LinkStack;

typedef struct LinkQueue{
    int data;
    LinkQueue *next, *front;
} *LinkQueue;     //LinkQueue & LinkStack 输入受限；

typedef struct BiTreeNODE{
    int data;
    BiTreeNODE *lchild, *rchild;
}BiTreeNODE, *LinkBiTree;

#define MaxVertexNum 50
typedef char VertexType;
typedef int EdgeType;
typedef struct Graph{
    VertexType Vex [MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexmun,arcnum;
}Graph;//邻接矩阵

bool ListInit(SqList &S){
    S.Length = 0;
    for(int i = 0; i < S.Length; i ++){
        S.data[i] = 0;
    }
    return true;
}

bool ListGetElem(SqList &S,int locate,int &e){
    if(locate < 0 || locate > MaxSize){
        return false;
    e = S.data[locate - 1];
    return true;
    }
}

bool ListInsert(SqList &S,int locate, int &e){
    if(locate < 0 || locate> MaxSize)
        return false;
    if(S.Length >= MaxSize)
        return false;
    for(int i = S.Length; i >= locate - 1;i --){
        S.data[i+1] = S.data[i];
    }
    S.data[locate - 1] = e;
    return true;
}