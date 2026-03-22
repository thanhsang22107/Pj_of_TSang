 #include <iostream>
 using namespace std;
 struct node{
   int info;
   node *next;
 };//cấu trúc tự trỏ
 struct list{
     node *head, *tail;
 };
  node* getNode(int x)// tạo ra 1 node (biến động) chứa giá trị của x
  {
     node *p=new node; //đã có biến động
     p->info=x;//Lưu giá trị x vào biến
     p->next=NULL;
     return p;// trả về p
  }
  void addHead(list &L,int x){
     //B1: tao ra 1 node chua x
     node *p=getNode(x);

     if(L.head==NULL)// DANH SACH RONG
        L.head=L.tail=p;

     //B2: sửa liên kết ,đuôi X trỏ tới A , cập nhật Head trỏ tới X
    else
    { p->next=L.head;//chua dia chi node A
     L.head=p;
    }// chua dia chi node X
  }
  void printList(list L){
     node *p=L.head;
     while(p!=NULL){
         cout<<p->info<<" ";
         p=p->next;// dia chi cua node sau, p nhay qua dang sau

     }
  }
  int main()
  {
     list L; // biến cấu trúc
     L.head=L.tail=NULL;
     while(1){
         int sodau, x;
         cin>>sodau;
         if(sodau!=0) break;
         if(sodau==0) {
             cin>>x;
             addHead(L,x);
         }
     }
     printList(L);
  }
