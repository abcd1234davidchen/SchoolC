#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

map<pair<int,int>,double> distances;

void recordDistances(map<int,pair<int,int>> &location){
    for(auto loc1 = location.begin();loc1!=location.end();loc1++){
        for(auto loc2 = location.begin();loc2!=location.end();loc2++){
            if(loc1->first==loc2->first) continue;
            int dx = loc1->second.first-loc2->second.first;
            int dy = loc1->second.second-loc2->second.second;
            distances[{loc1->first,loc2->first}] = sqrt(dx*dx+dy*dy);
        }
    }
}

void perm(vector<int>& reserve, vector<int>& remain, vector<int>& best, double& bestDistance, double currentDistance){
    // if(currentDistance>bestDistance) return;
    if(remain.size()==0){
        double finalDistance = currentDistance+distances[{reserve.back(),reserve[0]}];
        if(finalDistance<bestDistance){
            best = reserve;
            bestDistance = finalDistance;
            // cout << "New best: ";
            // for (size_t i = 0; i < best.size(); i++) {
            //     cout << best[i] << " ";
            // }
            // cout << endl << "New best distance: " << bestDistance << endl;
        }
        return;
    }
    for(size_t i=0;i<remain.size();i++){
        reserve.push_back(remain[i]);
        int temp=remain[i];
        double edgeLength = (reserve.size()>=2)?distances[{reserve[reserve.size()-2], temp}]:0;
        // double edgeLength = distances[{reserve[reserve.size()-2], temp}];
        swap(remain.back(),remain[i]);
        remain.pop_back();
        perm(reserve,remain,best,bestDistance,currentDistance+edgeLength);
        remain.push_back(temp);
        swap(remain[i],remain.back());
        reserve.pop_back();
    }
}

int main(int argc,char* argv[]){

    distances.clear();
    
    if(argc==1){
        cout<<"No file in arguement"<<endl;
        return 1;
    }
    else if(argc==2){
        cout<<"1 File"<<endl;
    }
    else{
        cout<<argc-1<<"File"<<endl;
    }
    
    for(int f=1;f<argc;f++){
        string inFileName = argv[f];
        ifstream inFile(inFileName);

        map<int,pair<int,int>> location;
        vector<int> reserve;
        vector<int> locationID;

        if (inFile.is_open()){
            int ID;
            pair<int,int> coordinate;
            while(inFile >> ID >>coordinate.first>>coordinate.second){
                location[ID] = coordinate;
                locationID.push_back(ID);
            }
            inFile.close();
        }
        else{
            cout<<"No such file";
            continue;
        }

        recordDistances(location);
        vector<int> best = locationID;
        double bestDistance = 0;
        for(size_t i=0;i<best.size();i++){
            int destination = ((i==best.size()-1))?best[0]:best[i+1];
            bestDistance+=distances[{best[i],destination}];
        }

        // reserve.push_back(locationID[0]);
        // locationID.erase(locationID.begin());

        perm(reserve,locationID,best,bestDistance,0);
        for(size_t i=0;i<best.size();i++){
            cout<<best[i]<<" ";
        }
        cout<<endl<<bestDistance<<endl;

        string outFileName = "";
        if(argc==2) outFileName = "ans.txt";
        else{
            ostringstream oss;
            oss<<"ans_dt"<<setw(2)<<setfill('0')<<f<<".txt";
            outFileName = oss.str();
        }

        ofstream outFile(outFileName);
        if(outFile.is_open()){
            outFile<<"distance: "<<bestDistance<<endl;
            for(size_t i=0;i<best.size();i++){
                outFile<<best[i]<<endl;
            }
        }

        int pythonReturn = system("python3 --version");
        if (pythonReturn!=0){
            cout<<"Can't find python3"<<endl;
            continue;
        }
        ifstream drawPy("draw.py");
        if (!drawPy.good()){
            cout<<"Can't find draw.py"<<endl;
        }

        string drawFileName = "";
        if(argc==2) drawFileName = "fig.png";
        else{
            ostringstream oss;
            oss<<"fig_dt"<<setw(2)<<setfill('0')<<f<<".png";
            drawFileName = oss.str();
        }

        ostringstream pythonCommandStream;
        pythonCommandStream<<"python3 draw.py "<<inFileName<<" "<<outFileName<<" "<<drawFileName;
        pythonReturn = system(pythonCommandStream.str().c_str());
        if(pythonReturn!=0) cout<<"draw.py return: "<<pythonReturn<<endl;
    }
}