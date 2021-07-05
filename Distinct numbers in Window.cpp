https://www.interviewbit.com/problems/distinct-numbers-in-window/

struct {
    int ind;
    int num;
    }hhash[100004];
int ssize;
int hash_function(int p){
    return p%100003;
}
void insert(int p){
    int index;
    index=hash_function(p);
    int h=1;
    while(hhash[index].ind!=-1&&hhash[index].ind!=p){
        index=(index+(h*h))%ssize;
        h++;
    }
    hhash[index].ind=p;
    hhash[index].num++;
}
int search(int p){
    int index;
    index=hash_function(p);
    int h=1;
    while(hhash[index].ind!=p&&hhash[index].ind!=-1){
        index=(index+(h*h))%ssize;
        h++;
    }
    if(hhash[index].ind==p&&hhash[index].num>0){
        return index;
    }
    return -1;
}
vector<int> Solution::dNums(vector<int> &A, int B) {
    ssize=100003;
    for(int i=0;i<100004;i++){
        hhash[i].ind=-1;
        hhash[i].num=0;
    }
    vector<int>vv;
    if(A.size()<B){
        return vv;
    }
    int l=0;
    for(int i=0;i<B;i++){
        int o;
        o=search(A[i]);
        //cout<<" "<<o<<" "<<hhash[search(A[i])].num<<" "<<hhash[search(A[i])].ind<<" ";
       
        if(search(A[i])==-1){
        insert(A[i]);
        l++;}
        else{
            insert(A[i]);
        }
    }
    vv.push_back(l);
    
    
    for(int i=B;i<A.size();i++){
       int o;
        o=search(A[i-B]);
        //cout<<" "<<o<<" "<<hhash[search(A[i-B])].num<<" "<<hhash[search(A[i-B])].ind<<" ";
        hhash[search(A[i-B])].num--;
        if(hhash[search(A[i-B])].num==0){
            l--;
        }
         o=search(A[i]);
       // cout<<" "<<o<<" "<<hhash[search(A[i])].num<<" "<<hhash[search(A[i])].ind<<" ";
       
        if(search(A[i])==-1){
            insert(A[i]);
            l++;
        }
        else{
            insert(A[i]);
        }
      vv.push_back(l);
    }
    return vv;
    
    
}
