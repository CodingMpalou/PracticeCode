#include <iostream>
#include <vector>

using namespace std;

struct PeakData {
    vector<int> pos, peaks;
};

PeakData pick_peaks(vector<int> v) {
    PeakData result;
    for(int i=1;i<v.size()-1;i++)
    {
        if(v[i]-v[i-1]>0 && v[i+1]-v[i]<0)
        {
            result.pos.push_back(i);
            result.peaks.push_back(v[i]);
        }
    }
    if(v[v.size()-1]-v[v.size()-2]>0)
    {

    }
    return result;
}

int main(){
 PeakData actual = pick_peaks(vector<int> {1, 2, 2, 2, 1});
    for(int i=0;i<actual.pos.size();i++)
        cout << actual.pos[i]<<","<< actual.peaks[i]<<endl;

 return 0;
 }