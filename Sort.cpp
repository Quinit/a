#define MaxSize 50
typedef struct {
    int data[MaxSize];
    int length;
}SqList;

int swap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
    return 0;
}

int BubbleSort(SqList &L,SqList &L_Sort){
    L_Sort = L;
    for(int i = 1;i<L_Sort.length ;i++){
        for(int j = 0;j<L_Sort.length - i;j++){
            if(L.data[j] > L.data[j+1])
                swap(L.data[j],L.data[j+1]);
        }
    }
    return 0;
}

int InsertFind(SqList &L,int x);

int InsertSort(SqList &L){
    int j = 0;//已排序的队列长度
    for(int i = 1;i < L.length; i++){
        int min = 0,max = j,mid = (min+max)/2;;
        while(min <= max){
            if(L.data[i] > mid){
                min = mid + 1;
            }
            else{
                max = mid - 1;
            }
        }
        swap(L.data[mid],L.data[i]);
        j ++;
    }
    return 0;
}