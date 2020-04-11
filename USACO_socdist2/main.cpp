#include <iostream>
#include <vector>

using namespace std;

int min_sick_cows(vector<int> x, vector<int> z){
    int R;



    return R;
}

int main() {
    
    //Variables
    int N,x,z,R=0;
    vector<int> X,Z;

    //In File
    FILE *fi=fopen("socdist2.in","r");
    fscanf(fi,"%d",&N);
    for(int i=0;i<N;i++)
    {
        fscanf(fi,"%d %d",&x,&z);
        X.push_back(x);
        Z.push_back(z);
    }
    fclose(fi);

    //Main

    //Out File
    FILE *fo=fopen("socdist2.out","w");
    fprintf(fi,"%d",R);
    fclose(fo);

    return 0;
}