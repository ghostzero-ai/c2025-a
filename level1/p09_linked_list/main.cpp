#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *next;
    //node *last;
}head,hail;

node* l(node *dq) {

    if (dq->next->next==NULL) {

        return dq;
    }else{

        return l(dq->next);
    }
}

node* cl(node *dq) {
    if (dq->next->next==NULL) {
        dq->next->next=dq;
        return dq;
    }else {
        cl(dq->next)->next=dq;
        return dq;
    }


}

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
    pt(*dq.next);
}

int main() {
    int n;
    cin >> n;
    //head.last = NULL;
    head.next = &hail;
    hail.next = NULL;
    //hail.last = NULL;

    for (int i = 0; i < n; i++) {
        node* p = (node*)malloc(sizeof(node) * 4);
        cin >> p->data;
        p->next = &hail;
        l(&head)->next=p;




    }
    int gn;
    cin >> gn;
    switch (gn) {
        case 1:
            pt(*head.next);
            break;
        case 2:
            cl(&head);
            head.next=NULL;
            pt(*hail.next);
            break;
        case 3:
            cout<<find(5,0,&head);
            break;
        case 4:
            cout<<find_two(5,0,&head,0);
    }
    return 0;
}