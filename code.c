#include<stdio.h>
#include<stdlib.h>

typedef struct linklist
{
    int elem;
    struct linklist *next;
}linklist;

linklist * initlinklist();//初始化链表
void dispiay(linklist *l);//输出链表
linklist *Getelem(int i,linklist *l);//查找元素
linklist *listinsert(linklist *l,int i,int e);//插入节点
int listdelete(linklist *l,int i);//删除节点

int main(){
    int e1=0, i=0, x=0, e2=0;
    printf("请选择相应操作");
    scanf("%d",&x);
    while (x)
    {
        switch (x)
        {
        case 1:
            printf("初始化链表\n");
            linklist *l=initlinklist();
            //初始化链表
            break;

        case 2:
            dispiay(l);
            //输出链表
            break;

        case 3:
            i=0;
            printf("请输入待输出元素的节点序号\n");
            scanf("%d",&i);
            linklist *e=Getelem(i,l);
            //找出第i元素
            printf("该元素为%d\n",e->elem);
            break;

        case 4:
            i=0;
            printf("请输入待插入元素的节点序号\n");
            scanf("%d",&i);
            e1=0;
            printf("请输入要插入的元素\n");
            scanf("%d",&e1);
            l=listinsert(l,i,e1);
            //在第i节点插入n值，并返回新链表l
            printf("已插入元素%d\n",e1);
            break;

        case 5:
            i=0;
            printf("请输入待删除元素的节点序号\n");
            scanf("%d",&i);
            e2=listdelete(l,i);
            printf("已删除元素%d\n",e2);
            break;
    
        default:
            break;
        }

        x=0;
        printf("请选择相应操作");
        scanf("%d",&x);

    }
    return 0;
}

linklist *initlinklist(){
    linklist *l = (linklist*)malloc(sizeof(linklist));
    //定义头指针l
    linklist *p = l;
    //定义指针p指向l
    printf("请输入数据数量\n");
    int n = 0;
    scanf("%d",&n);
    printf("请输入数据\n");

    for(int i=1;i<=n;i++)
    {
        int e=0;
        linklist *a = (linklist*)malloc(sizeof(linklist));
        //定义指针a指向a节点
        scanf("%d",&e);
        a->elem=e;
        a->next=NULL;
        p->next=a;
        //上一节点的next指针指向a
        p=p->next;//p指向a
    }
    return l;
}

void dispiay(linklist *l){
    printf("输出链表\n");
    linklist *p=l->next;
     while (p)//p非空
    {
        printf("%d\n",p->elem);
        p=p->next;
    }
}

linklist* Getelem(int i,linklist *l){
    linklist *p=l->next;
    int j=1;
    linklist *e=NULL;

    while (p&&j<i){
        //入循环时j=1，p指向第1个元素
        p=p->next;
        ++j;
    }
    //出循环时j=i，p指向i

    if(!p||j>i){
        //如果i大于列表长或i<1
        printf("ERROR");
        return 0;
    }
    else{
        e=p;
        //让e也指向i
        return e;
    }
}

linklist *listinsert(linklist *l,int i,int e){
    linklist *p=l;
    int j=0;

    while (p&&j<i-1){
        //入循环时p指向头指针和j=0
        p=p->next;
        ++j;
    }
    //出循环是i-1的指针和j=i-1

    if(!p||j>i-1){
        //如果i大于表长或者i小于1
        printf("ERROR");
        return 0;
    }
    else {
        linklist *s=(linklist*)malloc(sizeof(linklist));
        s->elem=e;
        s->next=p->next;
        //s的next指针指向原第i个元素
        p->next=s;
        //i-1的尾指针指向s
        return l;
    }
}

int listdelete(linklist *l,int i){
    linklist *p=l;
    int j=0,e=0;

    while (p&&j<i-1){
        //入循环时p指向头指针和j=0
        p=p->next;
        ++j;
    }
    //出循环是i-1的指针和j=i-1

     if(!p||j>i-1){
        //如果i大于表长或者i小于1
        printf("ERROR");
        return 0;
    }
    else {
        linklist *s=p->next;
        p->next=s->next;
        e=s->elem;
        free(s);
        //删除并释放节点
        return e;
    }
}
