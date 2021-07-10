#include <stdio.h>
#include<malloc.h>
#include<string.h>
#define MAX 21 

typedef int ElementType;
typedef int Position;

typedef struct QNode *PtrToQNode;
struct QNode{
	int max;
	ElementType id[MAX];
	Position Head;
	Position Rear;
}; 
typedef PtrToQNode Queue;


Queue CreateQueue(int x)
{
	Queue q;
	q=(Queue)malloc(sizeof(struct QNode));
	q->Head = q->Rear = 0;
	q->max = x+1;//这里采用多使用一个空间作为判断队满条件 
	return q;
} 

void InQueue(Queue q,ElementType s)
{
	//下面的if判断队满,前半段是正常情况,后半段是尾在头前面即后面的数组满了在前面插入了数,感觉前半段是多余的 
	if(q->Rear == q->Head - 1 || (q->Rear - q->Head + q->max) % q->max == q->max - 1){ 
	//if((q->Rear + 1) % q->max == q->Head ){//这段也行,上面的太复杂了
		printf("%d rejected.\n",s);
		return;
	}
	q->id[q->Rear] = s; 
	q->Rear = (q->Rear + 1) % q->max;
	printf("%d joined. Total:%d\n",s,(q->Rear - q->Head + q->max) % q->max); 
}

void OutQueue(Queue q)
{
	if(q->Head == q->Rear){//多用一个空间判断空队比较简单 
		printf("No one!\n");
		return;
	}
	int a; 
	a = q->id[q->Head];//保存被call的id
	q->Head = (q->Head + 1) % q->max;//头往前移
	int length;
	length = (q->Rear - q->Head + q->max) % q->max;
	 
	printf("%d called. Total:%d\n",a,length);
}

int main(){
	Queue q;
	ElementType s;
	int x;
	char n[10];
	scanf("%d",&x);
	q = CreateQueue(x);
	while(strcmp("#",n)){
		scanf("%s",&n);
		if(!strcmp("In",n)){
			scanf("%d",&s);
			InQueue(q,s);	
		}
		if(!strcmp("Calling",n))		
			OutQueue(q);
		if(!strcmp("#",n))
			return 0;
	} 
}


