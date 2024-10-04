#include <bits/stdc++.h>
using namespace std;
int w,m;
vector<long long>weights , all[2];
void rec(int i, long long sum, int end,int subProblem){
    // Exit Case
    if(i == end){
        all[subProblem].push_back(sum);
        return;
    }
    rec(i + 1, sum, end, subProblem);
    rec(i + 1, sum + weights[i], end, subProblem);
    rec(i + 1, sum - weights[i], end, subProblem);

}
int main(){
    scanf("%d %d",&w , &m);
    long cur = 1, sum =0;
    do {
        weights.push_back(cur);
        sum += cur;
        cur *= w;
    } while(sum <= m);
    
    // for(int i=0;i<weights.size();i++)
    //     cout<<weights[i]<<' ';
    // cout<<endl;

    rec(0,0,weights.size()/2,0);
    rec(weights.size()/2,0,weights.size(),1);

    sort(all[0].begin(),all[0].end());

    // for(int i=0;i<all[0].size();i++)
    //     cout<<all[0][i]<<' ';
    // cout<<'\n';
    // for(int i=0;i<all[1].size();i++)
    //     cout<<all[1][i]<<' ';
    // cout<<'\n';

    for(int i = 0;i < all[1].size();i++)
    {
        int target = m + all[1][i];
        int l = 0 , r = all[0].size();
        while(l <= r){
            int mid=(l+r)>>1;
            if(all[0][mid]==target)
            {
                puts("YES");
                return 0;
            }else if(all[0][mid]>target){
                r = mid -1 ;
            }else{
                l = mid + 1;
            }

        }
    }
    puts("NO");

    return 0;
}