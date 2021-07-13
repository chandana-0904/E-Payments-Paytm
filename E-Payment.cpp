#include<iostream>
#include<cstdlib>
#include <limits.h>
#include<string>
#include<cstdio>
#include<math.h>
#include <fstream>
#include<bits/stdc++.h>
using namespace std;
/*global variables*/
string id,fname;
#define V 6
/*-----------------------------------------------STACK------------------------------------------------------------------*/
#define SIZE 100
class Stack
{
	int *arr;
	int top;
	int capacity;

public:
	Stack(int size = SIZE); 	// constructor
	~Stack();   				// destructor

	void push(int);
	int pop();
	int peek();

	int size();
	bool isEmpty();
	bool isFull();
};
Stack::Stack(int size)
{
	arr = new int[size];
	capacity = size;
	top = -1;
	int no;
	ifstream  fobj;
fobj.open (id.c_str(),ios::in);
while(fobj)
{
    fobj>>no;
    arr[++top]=no;
}
fobj.close();
}
Stack::~Stack()
{
	delete arr;
}

void Stack::push(int x)
{
	if (isFull())
	{
		cout << "OverFlow\nProgram Terminated\n";
	}
	ofstream fp;
fp.open(id.c_str(),ios::app);
	arr[++top] = x;
	fp<<x<<" ";
	fp.close();
}
int Stack::peek()
{
map<int,string>hip;
hip[2]="Paid bills";
hip[3]="Sent money ";
hip[41]="Booked tickets";
hip[42]="Canceled tickets";
hip[5]="Shopped ";
int tmp=top;
for(int tmp=top;tmp>=0;tmp--)
{
    cout<<hip[arr[tmp]]<<endl;
}
}
int Stack::size()
{
	return top + 1;
}
bool Stack::isEmpty()
{
	return top == -1;
}
bool Stack::isFull()
{
	return top == capacity - 1;
}
/*global variable*/
Stack ht;
/*------------------------------HASHMAP----------------------------------------------------------------------------- */
const int TABLE_SIZE = 128;

/*
 * HashEntry Class Declaration
 */
class HashEntry
{
    public:
        string key;
        string value;
        HashEntry()
        {
            key="0";
            value="0";
        }
        HashEntry(string key, string value)
        {
            this->key = key;
            this->value = value;
        }
        HashEntry operator=(HashEntry &x)
        {

            key=x.key;
            value=x.value;
        }
};

/*
 * HashMap Class Declaration
 */
bool is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}


class HashMap
{
    private:
        HashEntry *table;
    public:

        /*
         * Hash Function
         */HashMap()
         {

             table=new HashEntry[TABLE_SIZE];
                string k,v;
                char ch;
             	ifstream ifile;
             	ifile.open("inpi.txt",ios::in);
                while(!is_empty(ifile))
	          {
                ifile>>k>>v;
                //cout<<k<<"****"<<v<<endl;
                if(k!="0")
                {
                    int hashn=HashFunc(k);
                    HashEntry pin(k,v);
                    table[hashn]=pin;
                }
	          }
	          ifile.close();
         }
        int HashFunc(string key)
        {
                const int p = 31;
    const int m = TABLE_SIZE;
    int  hash_value = 0;
    long long p_pow = 1;
    for (int i=0;i<key.length();i++) {
        hash_value = (hash_value%m + ((key[i] - 'a' + 1)%m * p_pow%m)%m )% m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value%m;

        }
        /*
         * Insert Element at a key
         */
	int  Insert(string key, string value)
	{
            int hash1 = HashFunc(key);
            //cout<<"hash\n";
            if(table[hash1].key!="0")
            {
                return -1;
            }
             else{
                    // Object to write in file
                 	ofstream fp;
                 		fp.open("inpi.txt",ios::app);
                 		fp<<key<<" "<<value<<" ";
                        fp.close();

             HashEntry l(key,value);
            table[hash1]=l;
            return 1;
             }
	}
        /*
         * Search Element at a key
         */
        string Search(string key)
	    {
	    int  hash1 = HashFunc(key);

	    if (table[hash1].key == "0")
	        return "-1";
	    else
	        return table[hash1].value;
        }

        ~HashMap()
	{
                delete[] table;

        }
};
/*---------------------------------------------------------BUSES-INHERITANCE----------------------------------------------*/
class BUS
{
protected:
int busno;
string starttime;
string  endtime;
int journeytm;
string startpt;
string endpt;
double fare;
};
//child class bus type 1
class A:public BUS{
public:
    A()
    {
        busno=123478;
        starttime="9:30";
        endtime="5:30";
        journeytm=8;
        startpt="Hyderabad";
        endpt="Guntur";
        fare=870.69;
    }
        friend ostream & operator << (ostream &out, const A &c);
};

    ostream & operator << (ostream &out, const A &c)
{
    out <<"\tBus number   : "<<c.busno<<endl;
    out <<"\tStart time   : "<<c.starttime<<"pm"<<endl;
    out<<"\tEnd time      : "<<c.endtime<<"am"<<endl;
    out<<"\tArrival point : "<<c.startpt<<endl;
    out<<"\tDestination   : "<<c.endpt<<endl;
    out<<"\tJourney time  : "<<c.journeytm<<"hours"<<endl;
    out<<"\tFare          : "<<c.fare<<endl;
    return out;
}

class B:public BUS{
public:
    B()
    {
        busno=123498;
        starttime="11:30";
        endtime="7:30";
        journeytm=8;
        startpt="Hyderabad";
        endpt="Vijayawada";
        fare=980.5;
    }
        friend ostream & operator << (ostream &out, const B &c);
};

    ostream & operator << (ostream &out, const B &c)
{
    out <<"\tBus number   : "<<c.busno<<endl;
    out <<"\tStart time   : "<<c.starttime<<"pm"<<endl;
    out<<"\tEnd time      : "<<c.endtime<<"am"<<endl;
    out<<"\tArrival point : "<<c.startpt<<endl;
    out<<"\tDestination   : "<<c.endpt<<endl;
    out<<"\tJourney time  : "<<c.journeytm<<"hours"<<endl;
    out<<"\tFare          : "<<c.fare<<endl;
    return out;
}


class C:public BUS{
public:
    C()
    {
        busno=123458;
        starttime="9:30";
        endtime="8:30";
        journeytm=9;
        startpt="Hyderabad";
        endpt="Vizag";
        fare=1200;
    }
        friend ostream & operator << (ostream &out, const C &c);
};

    ostream & operator << (ostream &out, const C &c)
{
    out <<"\tBus number   : "<<c.busno<<endl;
    out <<"\tStart time   : "<<c.starttime<<"pm"<<endl;
    out<<"\tEnd time      : "<<c.endtime<<"am"<<endl;
    out<<"\tArrival point : "<<c.startpt<<endl;
    out<<"\tDestination   : "<<c.endpt<<endl;
    out<<"\tJourney time  : "<<c.journeytm<<"hours"<<endl;
    out<<"\tFare          : "<<c.fare<<endl;
    return out;
}
/*-------------------------------------------------LINKED LIST--------------------------------*/

template<class T>
class node
{
 public:
 T data;
 int seatno;
 char stat;
node<T> *link;
};
template<class T>
class llist
{
private:
node<T> *first;
public:
llist();
~llist();
void createlist();
void cancel();
void book();
node<T>* bsearch(int);
void status();
void operations();
void display();
};
template<class T>
llist<T>::llist()
{
first=NULL;
}
template<class T>
llist<T>::~llist()
{
   node<T> *next;
     while(first)
     {
next=first->link;
delete first;
first=next;
      }
}
template<class T>
void llist<T>::createlist()
{
T a;
int x=1;
node<T> *cur,*ptr;
map<int,int>mp;
int no;
ifstream  fobj;
fobj.open (fname.c_str(),ios::in);
while(fobj)
{
    fobj>>no;
    mp[no]++;
}
fobj.close();
do
 {
   cur=new node<T>;
   cur->seatno=x;
   if(mp[x])
   cur->stat='N';
   else
    cur->stat='A';
cur->link=NULL;
if(first==NULL){
first=cur;
ptr=cur;
}
 else{
ptr->link=cur;
ptr=cur;
 }
 x++;
 }while(x<25);
}
template<class T>
void llist<T>::book()
{
    ht.push(41);
node<T> *ptr,*tmp;
ptr=first;
 while(ptr!=NULL)
         {
             //if(mp[ptr->data])
                //ptr->stat='Y';
     cout<<ptr->seatno<<"."<<ptr->stat<<"\t";
             ptr=ptr->link;
         }

  cout<<"\nSelect the number of seats to book\n";
  int pnum,snum;
  cin>>pnum;
  ofstream fp;
fp.open(fname.c_str(),ios::app);
while(pnum--)
{
    cout<<"Enter seat number\n";
    cin>>snum;
    fp<<snum<<" ";
    tmp=bsearch(snum);
    tmp->stat='N';
}
fp.close();

}
template<class T>
void llist<T>::cancel()
{
int num;
ht.push(42);
node<T>*pat;
cout<<"Enter seat number to cancel\n";
cin>>num;
pat=bsearch(num);
pat->stat='A';
//reading file content into map1
map<int,int>mp1;
map<int, int>::iterator it;
int no;
ifstream  fobj;
fobj.open (fname.c_str(),ios::in);
while(fobj)
{
    fobj>>no;
    mp1[no]++;
}
fobj.close();
//erasing file content
fstream ofs;
ofs.open(fname.c_str(), ios::out | ios::trunc);
ofs.close();
//writing content into file excluding deleted seat
ofstream fp;
fp.open(fname.c_str(),ios::app);
for( it=mp1.begin();it!=mp1.end();it++)
{
    if(it->first!=num)
        fp<<it->first<<" ";
}
fp.close();
}
template<class T>
node<T>* llist<T>::bsearch(int num)
{
     node<T> *ptr;
         ptr=first;
         while(ptr!=NULL)
         {
if(ptr->seatno==num)
    break;
ptr=ptr->link;
         }
     return ptr;
}
template<class T>
void llist<T>::status()
{
    int snum;
    cout<<"Enter seat number\n";
    cin>>snum;
    node<T>*ptr;
    ptr=bsearch(snum);
    cout<<ptr->data<<endl;
    if(ptr->stat=='N')
        cout<<"Seat booked\n";
    else
        cout<<"Seat available\n";
}
template<class T>
void llist<T>::operations()
{
int choice;
createlist();
do
{
printf("1.Details of bus\n2.Book\n3.Cancel\n");
printf("4.Check status of seat\n");
printf("5.Exit\n");
printf("Enter choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
    display();
    break;
case 2:
     book();
break;
case 3:
cancel();
break;
case 4:
    status();
break;
case 5:printf("Exit\n");
break;
}
}while(choice!=5);

}
template<class T>
void llist<T>::display()
{

  T ob;
  cout<<ob;
}
/*----------------------------------------------------------------------------NET BANKING----------------------------------------------------------------------------------*/
class WRONGACNO{};
class WRONGAC{};
class WRONGPIN{};
class NOBAL{};
class Paytm
{
    int acno;
    float bal;
    int pin;
    public:
    Paytm(int ano,int pn)
    {
        bal=5000;
        acno=ano;
        pin=pn;
    }
    void addToWallet()throw(WRONGAC);
    void transfer()throw(WRONGAC,WRONGPIN,NOBAL);
};
void Paytm::addToWallet()throw(WRONGAC)
{
    int anum;
    float amt;
    reenter:
    cout<<"enter your account number and amount needed to be added to your wallet= "<<endl;
    cin>>anum>>amt;
    try
    {
        if(anum!=acno)
        throw WRONGAC();
        else{
        bal=bal+amt;
        ht.push(2);
        }
    }
    catch(WRONGAC)
    {
        cout<<"the account number entered is invalid!!please re enter"<<endl;
        goto reenter;
    }
}
void Paytm::transfer()throw(WRONGAC,WRONGPIN,NOBAL)
{
    try
    {
        int ano,pn;
        float amt;
        cout<<"enter your account number= "<<endl;
        cin>>ano;
        if(ano!=acno)
        throw WRONGAC();
        cout<<"enter PIN!!= "<<endl;
        cin>>pn;
        if(pn!=pin)
        throw WRONGPIN();
        cout<<"enter amount to be transferred"<<endl;
        cin>>amt;
        if(bal<amt)
            throw NOBAL();
        else
        {
            cout<<"Amount is successfuly transferred"<<endl;
            cout<<"current balance="<<bal-amt<<endl;
            ht.push(3);
        }
    }
    catch(WRONGAC)
    {
        cout<<"the account number entered is invalid!!please re enter"<<endl;
    }
    catch(WRONGPIN)
    {
        cout<<"you entered wrong PIN!!please check"<<endl;
    }
    catch(NOBAL)
    {
        cout<<"Insufficient balance :("<<endl;
    }
}
/*------------------------------------------------------------------SORTPRICES---------------------------------------------*/

void heapify(int prices[], int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && prices[l] < prices[smallest])
        smallest = l;
    if (r < n && prices[r] < prices[smallest])
        smallest = r;
    if (smallest != i) {
        swap(prices[i], prices[smallest]);
        heapify(prices, n, smallest);
    }
}
void Sort(int prices[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(prices, n, i);
    for (int i = n - 1; i >= 0; i--)
	{
        swap(prices[0], prices[i]);
        heapify(prices, i, 0);
    }
}
void printPrices(int prices[], int n)
{
    for (int i = 0; i < n; ++i)
        cout <<"Model "<<char(65+i)<<"-"<<prices[i] << "\n ";
    cout << "\n";
}
/*-----------------------------------------------------------FILTER-----------------------------------------------------*/

class MinHeap {
    int* harr;
    int capacity;
    int heap_size; // Current no. of elements.
public:
    // Constructor
    MinHeap(int capacity);
    void MinHeapify(int);

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

    // Inserts a new key 'k'
    void insertKey(int k);

    void printSmallerThan(int k, int pos);
};

// Function to print all elements smaller than k
void MinHeap::printSmallerThan(int x, int pos = 0)
{
    /* Make sure item exists */
    if (pos >= heap_size)
        return;

    if (harr[pos] >= x) {
        return;
    }

    cout << harr[pos] << " ";

    printSmallerThan(x, left(pos));
    printSmallerThan(x, right(pos));
}
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
    if (heap_size == capacity) {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}



/*-------------------------------------------------LOGIN-----------------------------------------------------------*/
void login()
{
    cout<<"1.Login\n2.Register\n";
    int ch,done;
    HashMap h;
    string userid,passwd;
    cout<<"Enter choice\n";
    cin>>ch;
    if(ch==1)
    {
    string pass;
    do{
    cout<<"Enter User id\n";
    cin>>userid;
    id=userid;
    cout<<"Enter Password\n";
    cin>>passwd;
    pass=h.Search(userid);
    if(pass!=passwd)
    {
        cout<<"Password is wrong.Enter correct details\n";
        done=-1;
    }
    else
        done=1;
    }while(done==-1);

    }

    else
    {
    do{
    cout<<"Enter User id\n";
    cin>>userid;
    id=userid;
    cout<<"Enter Password\n";
    cin>>passwd;
    done=h.Insert(userid,passwd);
    if(done==-1)
    {
        cout<<"User already exist.Enter again\n";
    }
    }while(done==-1);

    }

}
/*---------------------------------------------HISTORY-----------------------------------------------------------*/
void showhistory()
{
ht.peek();
}
/*------------------------------------------------------TICKET BOOKING--------------------------------------------------------------*/
void bookticket()
{
    int ch;
    do{
    cout<<"\t\tAVAILABLE BUSES\n";
    cout<<"1.A\n2.B\n3.C\n";
    cout<<"Enter 4 to exit\n";
    cout<<"Enter choice\n";
    cin>>ch;
   switch(ch)
    {
    case 1:{llist<A>bus;
    fname="A";
    bus.operations();
    break;}
    case 2:{llist<B>bus;
    fname="B";
    bus.operations();
    break;}
    case 3:{llist<C>bus;
    fname="C";
    bus.operations();
    break;}
    }

    }while(ch!=4);
}

/*---------------------------------------------------------MONEY TRANSFER-------------------------------------------------------*/
void moneytransfer()
{
	int acno,pn;
    float b;
    char ch;
    cout<<"enter account number=";
    cin>>acno;
    cout<<"enter PIN=";
    cin>>pn;
    Paytm ob(acno,pn);
    ob.addToWallet();
    cout<<"do you want to transfer money!!";
    cin>>ch;
    if(ch='y')
    ob.transfer();
}
/*--------------------------------------------------SORT PRICES------------------------------------------------------------*/
void sortprices()
{
	int prices[]={10000,8000,5000,3000,2000,1000,500};
    int n = sizeof(prices) / sizeof(prices[0]);
    Sort(prices, n);
    cout << "Sorted prices list is \n";
    printPrices(prices, n);
    cout<<endl;
}
/*----------------------------------------------------FILTER--------------------------------------------------------------------*/
void filter()
{
	MinHeap h(5000);
    h.insertKey(10000);
    h.insertKey(8000);
    h.insertKey(5000);
    h.insertKey(3000);
    h.insertKey(2000);
    h.insertKey(1000);
    h.insertKey(500);
    h.insertKey(1500);
    h.insertKey(350);
    h.insertKey(700);
    h.insertKey(120);

    // Print all nodes smaller than 100.
    int x;
	cout<<"Enter range upto which you want to purchase";
	cin>>x;
    h.printSmallerThan(x);
    cout<<"\n";
}
/*-----------------------------------------------------------Delivery time --------------------------------------------------*/

int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance array

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
int  dijkstra(int graph[V][V], int src,int des)
{

    int dist[V],tmp; // The output array.  dist[i] will hold the shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int cot = 0; cot < V; cot++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;
        if(u==des){
        tmp=dist[u];
        break;
        }

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    return tmp;
}

void time()
{

 int graph[V][V] = { { 0, 5,9,8,0,70 },
                        { 5,0,10,3,10,30 },
                        { 9,10,0,8,11,75 },
                        { 8,3,8,0,8,30 },
                        { 0,10,11,8,0,30},
                        { 70,30,75,30,30,0},
                         };
  cout<<"Place where product has to be delivered\n";
  cout<<"1.Pragathi Nagar\n2.Miyapur\n3.Kukatpally\n4.Hitech city\n5.Nagole\n";
  int n,x;
  cout<<"Enter your choice\n";
  cin>>n;
 x= dijkstra(graph,0,n);
 x=x*5;
 cout<<"Product will be delivered in 2 days "<<(x/60)<<" hours "<<x%60<<" minutes\n";
  }

/*-----------------------------------------------------------BUYITEM--------------------------------------------------*/
void buy()
{
cout<<"Select model you want to buy\n";
cout<<"1.A\n2.B\n3.C\n4.D\n5.E\n6.F\n7.G\n8.H\n9.I\n10.J\n11.I\n";
cout<<"Enter your choice\n";
int x;
cin>>x;
time();
ht.push(5);
}
/*-----------------------------------------------------------SHOPPING--------------------------------------------------*/
void shopping()
{
	int choice,x,y;
	cout<<"Select a category\n";
	cout<<"1:Accessories\n2:Men's Wear\n3:Women's Wear\n4:Footwear"<<endl;
	cout<<"Press 5 to exit"<<endl;
	do
	{
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Models available\n";
				cout<<"1:Earrings\n2:bracelets\n3:chains\n";
				cout<<"Enter your choice\n";
				cin>>x;
				if(x==1||x==2||x==3)
				{
					do{
					cout<<"1:Sort prices\n2:Filter\n3:buy\nPress 4 to exit\n";

						cin>>y;
					switch(y)
					{
						case 1:
							sortprices();break;
						case 2:
							filter();break;
						case 3:
						    buy();
							cout<<"Order placed successfuly :)";break;
					}}while(y!=4);
				}
				else
				cout<<"Couldn't place the order :(\n";
				break;
			case 2:
				cout<<"Models available\n";
				cout<<"1:Louis Phillipe\n2:Buffalo\n3:Levis\n";
				cout<<"Enter your choice\n";
				cin>>x;
				if(x==1||x==2||x==3)
				{
					do{
						cout<<"1:Sort prices\n2:Filter\n3:buy\nPress 4 to exit\n";

						cin>>y;
					switch(y)
					{
						case 1:
							sortprices();break;
						case 2:
							filter();break;
						case 3:
						    buy();
							cout<<"Order placed successfuly :)";break;
					}}while(y!=4);
				}
				else
				cout<<"Couldn't place the order :(\n";
				break;
			case 3:
				cout<<"Models available\n";
				cout<<"1:A\n2:B\n3:C\n";
				cout<<"Enter your choice\n";
				cin>>x;
				if(x==1||x==2||x==3)
				{
					do{
						cout<<"1:Sort prices\n2:Filter\n3:buy\nPress 4 to exit\n";

						cin>>y;
					switch(y)
					{
						case 1:
							sortprices();break;
						case 2:
							filter();break;
						case 3:
						    buy();
							cout<<"Order placed successfuly :)";break;
					}}while(y!=4);
				}
				else
				cout<<"Couldn't place the order :(\n";
				break;
			case 4:
				cout<<"Models available\n";
				cout<<"1:Puma\n2:Skechers\n3:Fila\n";
				cout<<"Enter your choice\n";
				cin>>x;
				if(x==1||x==2||x==3)
				{
					do{
						cout<<"1:Sort prices\n2:Filter\n3:buy\nPress 4 to exit\n";
						cin>>y;
					switch(y)
					{
						case 1:
							sortprices();break;
						case 2:
							filter();break;
						case 3:
						    buy();
							cout<<"Order placed successfuly :)";break;
					}}while(y!=4);
				}
				else
				cout<<"Couldn't place the order :(\n";
				break;
		}
	}while(choice!=5);
}

/*-----------------------------------------------------------HOMEPAGE-------------------------------------------------------------*/

void homepage()
{
    int choice,x;
    do
    {

        cout<<"\t\tHOMEPAGE\n";
        cout<<"\t1.Login\n";
        cout<<"\t2.Money transfer\n";
        cout<<"\t3.Bus Ticket booking\n";
        cout<<"\t4.Shopping\n";
        cout<<"\t5.View history\n";
        cout<<"\t6.Log out\n";
        cout<<"Enter your choice\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            login();
            break;
        case 2:
        	moneytransfer();
            break;
        case 3:
            bookticket();
            break;
        case 4:
        	shopping();
           break;
        case 5:
            showhistory();
            break;
        case 6:
            printf("Logging you out\n");

        }
    }while(choice!=6);


}
/*----------------------------------------------------MAIN----------------------------------------------*/
int main()
{

    homepage();
    return 0;
}
