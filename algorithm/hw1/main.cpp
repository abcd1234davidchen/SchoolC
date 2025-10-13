#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

void recordDistances(map<int,pair<int,int>> &location,double** distanceBetween){
    for(auto loc1 = location.begin();loc1!=location.end();loc1++){
        for(auto loc2 = location.begin();loc2!=location.end();loc2++){
            if(loc1->first==loc2->first) continue;
            int dx = loc1->second.first-loc2->second.first;
            int dy = loc1->second.second-loc2->second.second;
            distanceBetween[loc1->first][loc2->first] = sqrt(dx*dx+dy*dy);
        }
    }
}

double calculateDistance(vector<int>& locationID,double** distanceBetween){
    double distance = distanceBetween[locationID[0]][locationID.back()];
    for(size_t i=0;i<locationID.size()-1;i++){
        distance+=distanceBetween[locationID[i]][locationID[i+1]];
    }
    return distance;
}

void perm(vector<int>& locationID, vector<int>& best, double& bestDistance, double** distanceBetween){
    while(next_permutation(locationID.begin(),locationID.end())){
        double distance = calculateDistance(locationID,distanceBetween);
        if(distance<bestDistance){
            bestDistance = distance;
            best = locationID;
        }
    }
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
        map<int,string> locationIDString;
        vector<int> locationID;
        
        if (inFile.is_open()){
            string ID;
            pair<int,int> coordinate;
            int intID = 0;
            while(inFile >> ID >>coordinate.first>>coordinate.second){
                location[intID] = coordinate;
                locationID.push_back(intID);
                locationIDString[intID] = ID;
                intID++;
            }
            inFile.close();
        }
        else{
            cout<<"No such file";
            continue;
        }

        double** distanceBetween = new double*[locationID.size()];
        for(int i=0;i<locationID.size();i++){
            distanceBetween[i] = new double[locationID.size()];
        }

        recordDistances(location,distanceBetween);
        vector<int> best = locationID;
        double bestDistance = calculateDistance(best,distanceBetween);

        perm(locationID,best,bestDistance,distanceBetween);
        vector<string> bestString;
        for(size_t i=0;i<best.size();i++){
            bestString.push_back(locationIDString[best[i]]);
            cout<<bestString[i]<<" ";
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
                outFile<<bestString[i]<<endl;
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