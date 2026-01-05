#include <iostream>
using namespace std;

struct slistelem{
    int data;
    slistelem *next;
};

class slist{
    private:
    slistelem *h;
    public:
    slist():h(nullptr){}
    void prepend(int v){
        slistelem *e=new slistelem;
        e->data=v;
        e->next=h;
        h=e;
    }
    ~slist(){
        while(h){
            slistelem *e=h;
            h=h->next;
            delete e;
        }
    }
    void print(){
        slistelem *e=h;
        while(e){
            cout << e->data << " ";
            e=e->next;
        }
        cout << endl;
    }
    void append(int v){
        slistelem *e=new slistelem;
        e->data=v;
        e->next=nullptr;
        slistelem *p=h;
        while(p->next){
            p=p->next;
        }
        p->next=e;
    }
    void remove(int v){
        slistelem *p=h;
        if(p->data==v){
            h=p->next;
            delete p;
            return;
        }
        slistelem *q=h->next;
        while(q){
            if(q->data==v){
                p->next=q->next;
                delete q;
                return;
            }
            p=p->next;
            q=q->next;
        }
    }
};

int main(){
    slist l;
    l.prepend(1);
    l.prepend(2);
    l.prepend(3);
    l.print();
    l.append(4);
    l.append(5);
    l.append(6);
    l.print();
    l.remove(3);
    l.print();
    return 0;
}
    