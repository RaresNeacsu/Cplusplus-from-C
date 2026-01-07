#include <iostream>
using namespace std;

template <class T> class slistelem {
public:
  slistelem(T n = 0, slistelem *next = nullptr) : data(n), next(next) {}
  T data;
  slistelem *next;
};

template <class T>ostream& operator<<(ostream& os, slistelem<T> *e){
    os<<e->data;
    return os;
}

template <class T> class slist {
private:
  slistelem<T> *h;
  slistelem<T> *cursor;

public:
  slist() : h(nullptr), cursor(nullptr) {}
  void prepend(T v) {
    if(h==nullptr){
        h=cursor=new slistelem<T>(v);
        return;
    }
    else{
    slistelem<T> *e = new slistelem<T>(v, h);
    h = e;
    }
  }
  ~slist() {
    while (h) {
      slistelem<T> *e = h;
      h = h->next;
      delete e;
    }
  }
  void print() {
    slistelem<T> *e = h;
    while (e) {
      cout << e << " ";
      e = e->next;
    }
    cout << endl;
  }
  void append(T v) {
    slistelem<T> *e = new slistelem<T>(v, nullptr);
    slistelem<T> *p = h;
    while (p->next) {
      p = p->next;
    }
    p->next = e;
  }
  void remove(T v) {
    slistelem<T> *p = h;
    if (p->data == v) {
      h = p->next;
      delete p;
      return;
    }
    slistelem<T> *q = h->next;
    while (q) {
      if (q->data == v) {
        p->next = q->next;
        delete q;
        return;
      }
      p = p->next;
      q = q->next;
    }
  }
  T getcursor() { return cursor->data; }
  void setcursor(T v) { cursor->data = v; }
  void findcursor(T v) {
    cursor = h;
    while (cursor->data != v) {
      cursor = cursor->next;
    }
  }
  void advance() { cursor = cursor->next; }
};

int main() {
  slist<int> l;
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
  l.findcursor(5);
  l.setcursor(10);
  l.print();
  l.~slist();
  l.print();
  slist<double> l2;
  l2.prepend(1.1);
  l2.prepend(2.2);
  l2.prepend(3.3);
  l2.print();
  l2.append(4.4);
  l2.append(5.5);
  l2.append(6.6);
  l2.print();
  l2.remove(3.3);
  l2.print();
  l2.findcursor(5.5);
  l2.setcursor(10.1);
  l2.print();
  slist<long int> l3;
  for(int i=0;i<40;i++){
    l3.prepend(i*i);
  }
  l3.print();
  return 0;
}
