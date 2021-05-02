//Segment tree for sum range-queries and updation
/*
one-based indexing
LIM=N
1. Initialization   -> O(N)
2. Range sum query  -> O(logN)    for each level we only visit not more than four vertices
3. Update query     -> O(logN)
*/

#include<bits/stdc++.h>
#define LIM 1007
using namespace std;


int arr[LIM];           //input array
int seg[4*LIM]={0};     //Seg tree children for index i are 2*i and 2*i+1
int lazy[4*LIM]={0};    //lazy tree children for index i are 2*i and 2*i+1

//initialization of segment tree
void init_tree(int node_indx,int node_lower,int node_upper)
{    
    if(node_lower == node_upper)
    {
        seg[node_indx] = arr[node_upper];
        return ;
    }        
    
    int mid=(node_lower+node_upper)/2;
    
    init_tree(node_indx*2, node_lower, mid);
    init_tree(node_indx*2+1, mid+1, node_upper);
   
    seg[node_indx]=seg[2*node_indx]+seg[2*node_indx+1];
}

// a,b is the range of query node_lower,node_upper is the range for particular node in seg_tree
//a<=b and node_lower<=node_upper
int range_query(int node_indx, int a, int b, int node_lower, int node_upper)
{
    //range is between a,b
    if(a<=node_lower and node_upper<=b)   
        return seg[node_indx];

    //Not in range
    if(b<node_lower or a>node_upper)
        return 0;       //INT_MIN in case of min query

    int mid=(node_lower+node_upper)/2;

    //Intersecting on left side or right side or both  
    return range_query(2*node_indx,a,b,node_lower,mid) +
        range_query(2*node_indx+1,a,b,mid+1,node_upper);   
}


//updatepoint at a
void update_point(int node_indx,int a,int node_lower, int node_upper, int val)
{
    if(node_upper == node_lower)
    {
        seg[node_indx]+=val;
        return;
    }
        
    if(a < node_lower or a>node_upper)
        return ;

    int mid=(node_lower+node_upper)/2;
    
    // if a is between lower and mid
    if(node_lower >= a and a <= mid) 
        update_point(2*node_indx,a,node_lower,mid,val);
    else
        update_point(2*node_indx+1,a,mid+1,node_upper,val);

    seg[node_indx]=seg[2*node_indx]+seg[2*node_indx+1];
}

// a,b is the range of query node_lower,node_upper is the range for particular node in seg_tree
// change values in range[a,b] by +val
// make a copy of seg_tree called lazy and init with 0

/*void update_query(int node_indx,int a, int b, int node_lower, int node_upper, int val)
{
    //we need to update changes in lower levels of this node
    if(lazy[node_indx]!=0)
    {
        seg[node_indx]+=(node_upper-node_lower+1)*val;
        if(node_upper!=node_lower)
        {
            lazy[node_indx*2]+=lazy[node_indx];
            lazy[node_indx*2+1]+=lazy[node_indx];
        }
        lazy[node_indx]=0;
    }

    //out of range
    if(b<node_lower or a>node_upper or node_lower>node_upper ) return;

    //required range is between the range of segtree
    if(node_lower<=a and node_upper<=b)
    {
        seg[node_indx]+=(node_upper-node_lower+1)*val;
        if(node_lower!=node_upper)
        {
            lazy[node_indx*2]+=lazy[node_indx];
            lazy[node_indx*2+1]+=lazy[node_indx];
        }
        return;
    }

    //Intersecting on left side or right side or both
    int mid=(node_lower+node_upper)/2;
    update_query(2*node_indx,a,b,node_lower,mid,val);
    update_query(2*node_indx+1,a,b,mid+1,node_upper,val);

    seg[node_indx]=seg[node_indx*2]+seg[node_indx*2+1];
}*/


int main()
{
    int i;
    //Intializing an array of size 10 with index itself
    //NOTE: We have used 1 based indexing
    for(i=1;i<=10;i++)
    {
        arr[i]=i;
    }
   
    //Initilize the Seg tree
    init_tree(1,1,10);
    
    //Range query[a,b]
    int a,b,val;
    cout<<"SUM: Enter range a,b: ";
    cin>>a>>b;
    cout<<range_query(1,a,b,1,10)<<endl;
    


    //Update query[a,b] with +val
    cout<<"Update: Enter range a,b : ";
    cin>>a>>b;
    cout<<endl<<"Update: Enter val : ";
    cin>>val;
    for(i=a;i<=b;i++)
    {
        update_point(1,i,1,10,val);
    }

    //Range query[a,b]
    cout<<"SUM: Enter range a,b: ";
    cin>>a>>b;
    cout<<range_query(1,a,b,1,10)<<endl;
    
}