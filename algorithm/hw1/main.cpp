#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <cstdlib>

using namespace std;

void recordDistances(map<int,pair<int,int>> &location,double** distanceBetween){
    //Go through every two point and calculate each distance
    for(auto loc1 = location.begin();loc1!=location.end();loc1++){
        for(auto loc2 = location.begin();loc2!=location.end();loc2++){
            if(loc1->first==loc2->first) distanceBetween[loc1->first][loc2->first] = 0.0;
            int dx = loc1->second.first-loc2->second.first;
            int dy = loc1->second.second-loc2->second.second;
            distanceBetween[loc1->first][loc2->first] = sqrt(dx*dx+dy*dy);
        }
    }
}

double calculateDistance(vector<int>& locationID,double** distanceBetween){
    //Calculate the distance of a whole row of locationID
    //By setting the distance as end to head to form circle
    //Then add distance of every two point in sequence till end
    double distance = distanceBetween[locationID[0]][locationID.back()];
    for(size_t i=0;i<locationID.size()-1;i++){
        distance+=distanceBetween[locationID[i]][locationID[i+1]];
    }
    return distance;
}

void perm(vector<int>& locationID, vector<int>& best, double& bestDistance, double** distanceBetween){
    //Go through all permutation and record the best and best distance
    while(next_permutation(locationID.begin(),locationID.end())){
        double distance = calculateDistance(locationID,distanceBetween);
        if(distance<bestDistance){
            bestDistance = distance;
            best = locationID;
        }
    }
}

int main(int argc,char* argv[]){
    
    int fileAmount = 0;
    vector<string> fileNames;

    //Determine if no/one/multiple file
    if(argc==1){
        cout<<"No file in arguement. Please input file names:"<<endl;
        string fileString;
        getline(cin,fileString);
        istringstream iss(fileString);
        string singleFileName;
        while(iss>>singleFileName){
            fileNames.push_back(singleFileName);
            fileAmount++;
        }
    }
    else if(argc==2){
        cout<<"1 File"<<endl;
        fileAmount = 1;
    }
    else{
        cout<<argc-1<<"File"<<endl;
        fileAmount = argc-1;
        for(int i=1;i<argc;i++){
            fileNames.push_back(argv[i]);
        }
    }

    //For each file
    for(int f=0;f<fileAmount;f++){

        //Take in file
        string inFileName = fileNames[f];
        ifstream inFile(inFileName);

        //Give each location a new ID to :
        //1. condense distance matrix
        //2. eliminate possibility that ID is string
        map<int,pair<int,int>> location;
        map<int,string> locationIDString;
        vector<int> locationID;
        
        //Deal with file & assign new ID & save each location
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

        //2D array to save distance between every two point
        double** distanceBetween = new double*[locationID.size()];
        for(int i=0;i<locationID.size();i++){
            distanceBetween[i] = new double[locationID.size()];
        }
        recordDistances(location,distanceBetween);

        //Set best loop as inital loop to have something to start from
        vector<int> best = locationID;
        double bestDistance = calculateDistance(best,distanceBetween);
        perm(locationID,best,bestDistance,distanceBetween);

        //Revert best loop back to string ID
        vector<string> bestString;
        for(size_t i=0;i<best.size();i++){
            bestString.push_back(locationIDString[best[i]]);
            cout<<bestString[i]<<" ";
        }
        cout<<endl<<bestDistance<<endl;

        //Set output file name
        //if multiple file -> ans_dt(x).txt
        //else -> ans.txt
        //and write as format
        string outFileName = "";
        if(argc==2) outFileName = "ans.txt";
        else{
            ostringstream oss;
            oss<<"ans_dt"<<setw(2)<<setfill('0')<<(f+1)<<".txt";
            outFileName = oss.str();
        }
        ofstream outFile(outFileName);
        if(outFile.is_open()){
            outFile<<"distance: "<<bestDistance<<endl;
            for(size_t i=0;i<best.size();i++){
                outFile<<bestString[i]<<endl;
            }
        }
        
        //Check if python3 exist and if draw.py exist
        int pythonReturn = system("python3 --version");
        if (pythonReturn!=0){
            cout<<"Can't find python3"<<endl;
            continue;
        }
        ifstream drawPy("draw.py");
        if (!drawPy.good()){
            cout<<"Can't find draw.py"<<endl;
        }

        //Set output figure name depend on file amount
        string drawFileName = "";
        if(argc==2) drawFileName = "fig.png";
        else{
            ostringstream oss;
            oss<<"fig_dt"<<setw(2)<<setfill('0')<<(f+1)<<".png";
            drawFileName = oss.str();
        }

        //Run draw.py to get figure
        ostringstream pythonCommandStream;
        pythonCommandStream<<"python3 draw.py "<<inFileName<<" "<<outFileName<<" "<<drawFileName;
        pythonReturn = system(pythonCommandStream.str().c_str());
        if(pythonReturn!=0) cout<<"draw.py return: "<<pythonReturn<<endl;
    }
}