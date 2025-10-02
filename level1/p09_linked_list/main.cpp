#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *next;
    //node *last;
}head,hail;

node* l(node *dq);
node* cl(node *dq);
int find(int number,int xh,node *dq);
int find_two(int number,int xh,node *dq,int flag);
void pt(node dq);



//查找末节点的前一个节点
node* l(node *dq) {

    if (dq->next->next==NULL) {

        return dq;
    }else{

        return l(dq->next);
    }
}

//将箭头倒序
node* cl(node *dq) {
    if (dq->next->next==NULL) {
        dq->next->next=dq;
        return dq;
    }else {
        cl(dq->next)->next=dq;
        return dq;
    }


}

//顺节点查找
int find(int number,int xh,node *dq) {
    if (dq->next==NULL) {
        return -1;
    }
    if (dq->data==number) {
        return xh;
    }else {
        return find(number,xh+1,dq->next);
    }
}

//顺节点查找第二次出现的
int find_two(int number,int xh,node *dq,int flag) {
    if (dq->next==NULL) {
        return -1;
    }
    if (dq->data==number) {
        if (flag==1) {
            return xh;
        }else {
            flag++;
            return find_two(number,xh+1,dq->next,flag);
        }

    }else {
        return find_two(number,xh+1,dq->next,flag);
    }
}

void pt(node dq) {
    if (dq.next==NULL) {
        return;
    }
    cout << dq.data << endl;
    pt(*dq.next);//顺着链表查找
}

int main() {
    int n;
    cout<<"请输入要创造链表的长度";
    cin >> n;
    system("cls");
    head.next = &hail;
    hail.next = NULL;
    cout<<"请输入要创造的链表";
    //创建并输入一个链表
    for (int i = 0; i < n; i++) {
        node* p = (node*)malloc(sizeof(node) * 4);
        cin >> p->data;
        p->next = &hail;
        l(&head)->next=p;

    }
    system("cls");
    int gn;//功能
    cout<<"请输入要实现的功能";
    cin >> gn;
    system("cls");
    switch (gn) {
        case 1://遍历该链表，依次现实各节点的 value
            pt(*head.next);
            break;
        case 2://将该链表所有节点反序
            cl(&head);
            head.next=NULL;
            pt(*hail.next);
            break;
        case 3://在该链表中查找第一个值为 5 的节点，如果找到则返回该节点的序号，否则返回－1
            cout<<find(5,0,&head);
            break;
        case 4://查找下一个值为 5 的节点，返回值同上
            cout<<find_two(5,0,&head,0);
    }
    return 0;
}