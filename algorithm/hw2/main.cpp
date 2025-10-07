#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

double calculateDistances(int ID1, int ID2, map<int,pair<int,int>> &location){
    double dx = location[ID1].first-location[ID2].first;
    double dy = location[ID1].second-location[ID2].second;
    return sqrt(dx*dx+dy*dy);
}

double greedy(vector<int>& solution,vector<int>& locationID,map<int,pair<int,int>> &location){
    if(locationID.size()==0) return 0;
    int lastID = solution.back();
    int bestID = locationID.front();
    double bestDistance = calculateDistances(lastID,bestID,location);
    for(auto loc:locationID){
        double locDistance = calculateDistances(lastID,loc,location);
        if(locDistance<bestDistance){
            bestDistance = locDistance;
            bestID = loc;
        }
    }
    solution.push_back(bestID);
    auto removeLocation = find(locationID.begin(),locationID.end(),bestID);
    if(removeLocation!=locationID.end()) locationID.erase(removeLocation);
    return bestDistance+greedy(solution,locationID,location);
}

int main(int argc,char* argv[]){
    
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

        vector<int> solution;
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
        
        solution.push_back(locationID[0]);
        locationID.erase(locationID.begin());
        
        double solutionDistance = greedy(solution,locationID,location);
        solutionDistance+=calculateDistances(solution[0],solution.back(),location);
        
        for(size_t i=0;i<solution.size();i++){
            cout<<solution[i]<<" ";
        }
        cout<<endl<<solutionDistance<<endl;

        string outFileName = "";
        if(argc==2) outFileName = "ans.txt";
        else{
            ostringstream oss;
            oss<<"ans_dt"<<setw(2)<<setfill('0')<<f<<".txt";
            outFileName = oss.str();
        }

        ofstream outFile(outFileName);
        if(outFile.is_open()){
            outFile<<"distance: "<<solutionDistance<<endl;
            for(size_t i=0;i<solution.size();i++){
                outFile<<solution[i]<<endl;
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