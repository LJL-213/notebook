//洛谷8306
#include<bits/stdc++.h>
using namespace std;
#define N 3000005
#define M 62
// N 树的最大深度
// M 下一级可能的字符数，这里为 大写字母+小写字母+数字
int tree[N][M];
//记录前缀个数
int pass[N];
// 节点总数
int cnt;
// 清空tree,pass
void del(){
    for(int i=0;i<cnt;i++){
        memset(tree[i],0,sizeof(tree[i]));
         pass[i]=0; 
    }
}
// 插入新 word
void ins(string word){
    int cur=1;
    for(int i=0,path;i<word.size();i++){
        if(word[i]>='0'&&word[i]<='9')
            path=word[i]-'0';
        else if(word[i]>='A'&&word[i]<='Z')
            path=word[i]-'A'+10;
        else path=word[i]-'a'+36;
        if(tree[cur][path]==0){
            tree[cur][path]=++cnt;
        }
        cur=tree[cur][path];
        pass[cur]++;
    }
}
// 前缀个数
int prefixnumber(string pre){
     int cur=1;
    
    for(int i=0,path;i<pre.size();i++){
        if(pre[i]>='0'&&pre[i]<='9')
            path=pre[i]-'0';
        else if(pre[i]>='A'&&pre[i]<='Z')
            path=pre[i]-'A'+10;
        else path=pre[i]-'a'+36;
        cur=tree[cur][path];
        if(pass[cur]==0)return 0;
    }
    return pass[cur];
}
void fun(){
    int n,q;
    cin>>n>>q;
    //  每一个样例重置cnt 
    cnt=1;
    string word;
    string pre;
    while(n--){
        cin>>word;
        ins(word);
    }
    int ans;
    while(q--){
        cin>>pre;
        ans=prefixnumber(pre);
        cout<<ans<<'\n';
    }
    del();
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        fun();
    return 0;
}