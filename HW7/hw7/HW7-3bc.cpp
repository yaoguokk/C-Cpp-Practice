#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;
struct MDLL
{ 

int val;   

MDLL* prev;   

MDLL* next;   

MDLL* child;

MDLL* parent;

int mark;

};

struct Save{
    int index;
    int val;
};

class List
{
private:
MDLL *head;
MDLL *tail;
int count;
public:

List();
~List();
void push_back(int var);
void push_front(int var);
void print_List();
void pop_back();
int getNo();
MDLL* getHead();
void setHead(MDLL* temp);
MDLL* getTail();
bool removeByIndex(int index);
bool removeByVal(int val);
};

List::List(){
    head = NULL;
    tail = NULL;
    count = 0;
}
List::~List(){
    // delete head;
    // delete tail;
}
MDLL* List::getHead(){
    return head;
}
void List::setHead(MDLL* temp){
    this->head = temp;
}
MDLL* List::getTail(){
    return tail;
}
void List::pop_back(){
    MDLL *node = tail;
    if(tail==NULL){
        return;
    }else{
        tail = node->prev;
        tail->next = NULL;
        delete node;
    }
}
void List::push_back(int var){
    MDLL *node = new MDLL;
    node->val = var;
    node->mark = 0;
    node->prev=tail;
    node->next=NULL;
    node->child=NULL;
    node->parent=NULL;
    if(tail != NULL){
        tail->next=node;
    }else{
        head = node;
    }
    tail = node;
    count++;

}

void List::push_front(int var){
    MDLL *node = new MDLL;
    node->val = var;
    node->mark = 0;
    node->prev=NULL;
    node->next=head;
    node->child=NULL;
    node->parent=NULL;
    if(head != NULL){
        head->prev=node;
    }else{
        tail = node;
    }
    head = node;
    count++;
}

void List::print_List(){
    MDLL *temp = head;
    if(head==NULL)
        return;
    while(temp->next!=NULL){
        cout<<temp->val<<"<->";
        temp = temp->next;
    }
    
    cout<<temp->val<<endl;
}
int List::getNo(){
    return count;
}
void connectAToB(List *a,int NOa,List *b,int NOb,bool flag){
    int countA=0;
    int countB=0;
    if(NOa>a->getNo()||NOb>b->getNo()){
        cout<<"wrong insert NO"<<endl;
        return;
    }
    MDLL *tempa = a->getHead();
    MDLL *tempb = b->getHead();
    while(tempa!=NULL){
        if(countA == NOa){
            break;
        }
        tempa = tempa->next;
        countA++;
        
    }
    while(tempb!=NULL){
        if(countB == NOb){
            break;
        }
        tempb = tempb->next;
        countB++;
        
    }
    //if flag == 1 connect A No a node to B No b node;
    if(flag){
        tempa->parent = tempb;
        tempb->child = tempa;
    }else{
        tempa->child = tempb;
        tempb->parent = tempa;
    } 
}

MDLL* getHead(MDLL* temp){
    if(temp == NULL)
        return NULL;
    MDLL *temp1= temp;
    while(temp1->prev!=NULL){
        temp1 = temp1->prev;
    }
    return temp1;
}

MDLL* getTail(MDLL* temp){
    if(temp == NULL)
        return NULL;
    MDLL *temp1= temp;
    while(temp1->next!=NULL){
        temp1 = temp1->next;
    }
    return temp1;
}
void printSingle(MDLL *head){
    MDLL *temp = head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
}

void printALL(MDLL *head){
    if(head != NULL){
        cout<<head->val<<"->";
        head->mark = 1;
        if((head->parent!=NULL) && (head->parent->mark==0)){
            MDLL *temp = head;
            temp = getHead(head->parent);
            // printSingle(temp);
            printALL(temp);
        }
        if((head->child!=NULL) && (head->child->mark==0)){
            MDLL *temp = head;
            temp = getHead(head->child);
            // printSingle(temp);
            printALL(temp);
        }
            printALL(head->next);
    }
}
void connectALL(MDLL *head){
    if(head != NULL){
    head->mark = 1;

    if((head->parent!=NULL) && (head->parent->mark==0)){
        
        MDLL *findhead;
        MDLL *findtail;
        findtail = getTail(head->parent);
        findhead = getHead(head->parent);
        if(findhead->mark==0){
            findhead->prev = head;
            // cout<<"findhead->prev"<<findhead->prev->val<<endl;
            // cout<<"findhead->next"<<findhead->next->val<<endl;
            // cout<<"findhead"<<findhead->val<<endl;
            findtail->next = head->next;
            // cout<<"findtail->next"<<findtail->next->val<<endl;
            // cout<<"findtail->prev"<<findtail->prev->val<<endl;
            // cout<<"findtail"<<findtail->val<<endl;
            head->next->prev = findtail;
            // cout<<"head->next->prev"<<head->next->prev->val<<endl;
            head->next = findhead;
            // cout<<"head->next"<<head->next->val<<endl;
            // cout<<"done"<<endl;
            connectALL(findhead);
          
        }
        
    }
    if((head->child!=NULL) && (head->child->mark==0)){
        MDLL *findhead;
        MDLL *findtail;
        findtail = getTail(head->child);
        findhead = getHead(head->child);        

        if(findhead->mark==0){
            findhead->prev = head;
            findtail->next = head->next;
            head->next->prev = findtail;
             head->next = findhead;
            connectALL(findhead);
        }
        
        // printALL(head);
    }
        connectALL(head->next);
    }
}


bool List::removeByIndex(int index){
    int count = 0;
    //if remove the empty LL or the index is out of range return false
    if(this->head== NULL)
        return false;
    MDLL *temp = head;
    if(index == 0){
        head=head->next ;
        head->prev = NULL;
        delete temp;
        return true;
    }
    
    while (temp->next!=NULL){
        if(index == count){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            return true;
        }
        temp = temp->next;
        count++;
    }
    //if process this, that means the index is the length of the LL
    
    // c"last item deleted";
    if(head->next==NULL){
        head = NULL;
        return true;
    }
    tail = temp->prev;
    temp->prev->next = NULL;
    delete temp;
    return true;
    
}

bool List::removeByVal(int value){
    //if remove the empty LL or the index is out of range return false
    if(this->head== NULL)
        return false;
    MDLL *temp = head;
    //if need to remove the first item
    if(value == head->val){
        head=head->next ;
        head->prev = NULL;
        delete temp;
        return true;
    }
    while (temp->next!=NULL){
        if(value == temp->val){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            return true;
        }
        temp = temp->next;
    }
    //if remove the last item
    if(temp->val == value){
        tail = temp->prev;
        temp->prev->next = NULL;
        delete temp;
        return true;
    }
    return false;
}


int partition(vector<Save> &s,int p,int r){
    int pivot = s[r].val;
    int i=p-1;
    for(int j=p;j<r;j++){
        if(s[j].val<pivot){
            i++;
            swap(s[j],s[i]);
        }
    }
    swap(s[r],s[i+1]);
    return i+1;
}

void quicksort(vector<Save> &s,int p,int r){
    if(p<=r){
        int q= partition(s,p,r);
        quicksort(s,p,q-1);
        quicksort(s,p+1,r);
    }
}



void removeDuplicates(List &list){
    // quicksort(vector<Save> ,int ,int);
    MDLL *temp = list.getHead();
    int count=0;
    vector<Save> newvector;
    //copy the LL with its index and value
    while(temp!=NULL){
        Save s;
        s.val=temp->val;
        s.index=count;
        newvector.push_back(s);
        count++;
        temp=temp->next;
    }
    //sort the vector
    quicksort(newvector,0,newvector.size()-1);
    
    for(int i=1;i<count;i++){
       if(newvector[i].val==newvector[i-1].val){
           list.removeByVal(newvector[i].val);
       }
    }
}

int main(){

    List list[4];
    // initial these DLL
    list[0].push_back(5);

    for(int i=1;i<7;i++){
        list[1].push_back(i);
    }

    list[2].push_back(4);
    list[2].push_back(7);
    list[2].push_back(8);
    list[2].push_back(9);
    list[2].push_back(10);

    list[3].push_back(11);
    list[3].push_back(12);
    
    
    connectAToB(&list[0],0,&list[1],3,0);
    connectAToB(&list[1],1,&list[2],0,0);
    connectAToB(&list[2],4,&list[1],5,1);
    connectAToB(&list[3],1,&list[2],2,1);
    /*

                  head->5---NULL
                        |
          head->1---2---3---4---5---6--NULL
                |               |
      top-head->4---7---8---9---10--NULL
                        |
            head-> 11--12--NULL

    */
    MDLL *temp = list[2].getHead();
    MDLL *temp1 = list[2].getHead();
    connectALL(temp);
    cout<<"after flattern Linked list"<<endl;
    list[2].print_List();
    //4 <-> 1 <-> 2 <-> 3 <-> 5 <-> 4 <-> 5 <-> 6 <-> 7 <-> 8 <-> 11 <-> 12 <-> 9 <-> 10
    removeDuplicates(list[2]);
    cout<<"after remove duplicates"<<endl;
    list[2].print_List();

    // // test for reverse output
    // MDLL *tail = getTail(temp1);
    // while(tail!=NULL){
    //     cout<<tail->val<<"<->";
    //     tail = tail->prev;
    // }


    return 0;
}

/*
void push_back(MDLL)
void 

puseudocode flattern:
start from top-head 
iterate until temp->parent!=NULL
MDLL *newpar = temp->parent;//store the node 
MDLL *newHead = find_head(MDLL *temp->parent);




MDLL* find_head(MDLL *temp){
    if(temp->prev == NULL)
        return temp;
    while(newLL->prev!=NULL){
    newLL = newLL->prev;
    //to get the parent of the LL
    }
    return temp;
}

MDLL* find_tail(MDLL *temp){
    if(temp->next == NULL)
        return temp;
    while(newLL->next!=NULL){
    newLL = newLL->next;
    //to get the parent of the LL
    }

    return temp;
}





to remove the duplicates. 
remove item(MDLL *head, int index)
    count = 0
    //if remove the empty LL or the index is out of range return false
    if(head== NULL)
        return false
    MDLL *temp = head
    count = 0
    
    while (temp->next!=NULL) do
        if(index == 0)
            head = head -> next
            head->prev = NULL
            delete temp
            return true
        temp = temp->next
        count++
        if(index == count)
            temp->prev = temp 
        

Procedure remove duplicates(MDLL *head)


*/
