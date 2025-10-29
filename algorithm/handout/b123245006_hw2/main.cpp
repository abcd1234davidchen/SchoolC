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
#include <cfloat>

using namespace std;

double calculateDistances(int ID1, int ID2, map<int,pair<int,int>> &location){
    //Calculate distance of any two point
    double dx = location[ID1].first-location[ID2].first;
    double dy = location[ID1].second-location[ID2].second;
    return sqrt(dx*dx+dy*dy);
}


double greedy(vector<int>& solution,vector<int>& locationID,map<int,pair<int,int>> &location){
    //Exit when no left point
    if(locationID.size()==0) return 0;

    //Preset best next as front of locationID, and replace it with nearer point until end
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

    //Push the best point into solution and remove from locationID
    solution.push_back(bestID);
    auto removeLocation = find(locationID.begin(),locationID.end(),bestID);
    if(removeLocation!=locationID.end()) locationID.erase(removeLocation);

    //Use recursion to calculate distance and proceed greedy
    return bestDistance+greedy(solution,locationID,location);
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
    else if(fileAmount==1){
        cout<<"1 File"<<endl;
        fileNames.push_back(argv[1]);
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

        //Set a start for solution
        
        vector<int> bestSolution = locationID;
        double bestSolutionDistance = DBL_MAX;

        for(size_t rot = 0; rot<locationID.size();rot++){
            vector<int> solution;
            vector<int> duplicateLocationID = locationID;
            
            //Set new number to be the head by swap to end and pop to head
            swap(duplicateLocationID[rot],duplicateLocationID[duplicateLocationID.size()-1]);
            solution.push_back(duplicateLocationID.back());
            duplicateLocationID.pop_back();
            //Get the distance and greedy solution
            double solutionDistance = greedy(solution,duplicateLocationID,location);
            //Add the last point to form circle
            solutionDistance+=calculateDistances(solution[0],solution.back(),location);

            if (solutionDistance<bestSolutionDistance){
                bestSolutionDistance = solutionDistance;
                bestSolution = solution;
            }
        }

        //Revert solution loop back to string ID
        vector<string> solutionString;
        for(size_t i=0;i<bestSolution.size();i++){
            solutionString.push_back(locationIDString[bestSolution[i]]);
            cout<<solutionString[i]<<" ";
        }
        cout<<endl<<bestSolutionDistance<<endl;

        //Set output file name
        //if multiple file -> ans_dt(x).txt
        //else -> ans.txt
        //and write as format
        string outFileName = "";
        if(fileAmount==1) outFileName = "ans.txt";
        else{
            ostringstream oss;
            oss<<"ans_dt"<<setw(2)<<setfill('0')<<(f+1)<<".txt";
            outFileName = oss.str();
        }
        ofstream outFile(outFileName);
        if(outFile.is_open()){
            outFile<<"distance: "<<bestSolutionDistance<<endl;
            for(size_t i=0;i<bestSolution.size();i++){
                outFile<<solutionString[i]<<endl;
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
        if(fileAmount==1) drawFileName = "fig.png";
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