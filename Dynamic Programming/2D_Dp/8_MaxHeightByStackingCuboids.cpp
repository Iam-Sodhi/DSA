#include <bits/stdc++.h>
using namespace std;
//****IMP**** similar longest inc subsequence but have greedy approach
// Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). 
// Choose a subset of cuboids and place them on each other.
// You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj.
// You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.
// Return the maximum height of the stacked cuboids.

//condtion
bool condition(vector<int>& base, vector<int>&newBox){
   if(base[0]>=newBox[0] && base[1]>=newBox[1] && base[2]>=newBox[2]){
    return true;
   }
   else return false;
}

int solveSpace(vector<vector<int>>& cuboids){
    int n = cuboids.size();
    vector<int> next(n+1,0);
    vector<int> currR(n+1,0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int excl = next[prev+1]; 
            int incl = 0;
            if (prev == -1 || condition(cuboids[curr],cuboids[prev]))  //only need to *****change the conditon & values***** nothing else
            {
                incl = cuboids[curr][2] + next[curr+1]; //****here add height not the 1
            }
            currR[prev+1]=max(incl,excl);
        }
        next=currR;
    }
    return next[0];
}
 int solve(vector<vector<int>>& cuboids){
    //firstly we will use greedy approach to sort  the dimension in such way that height is the maximum dimension in every cuboid
    for(auto& i: cuboids){
        sort(i.begin(),i.end()); //height is at [2] index as maximum will be there in every cuboid
    }
    //now we will sort the cuboids acc to the width (let be at [0] idx)
    sort(cuboids.begin(),cuboids.end());
    //now we will use the code of LIS with the given condition
    return solveSpace(cuboids);
    
 }
int main()
{	
    return 0;
}