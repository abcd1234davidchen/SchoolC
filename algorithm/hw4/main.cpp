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
#include <random>

using namespace std;

struct ACOParams {
    int run_times = 30;
    int iterations = 200;
    int ants = 50; 
    int max_evaluation = -1;
    double alpha = 1.0;
    double beta = 5.0;
    double rho = 0.3;
    double Q = 100.0;
};

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
    if (locationID.size() < 2) return 0.0;
    //Calculate the distance of a whole row of locationID
    //By setting the distance as end to head to form circle
    //Then add distance of every two point in sequence till end
    double distance = distanceBetween[locationID[0]][locationID.back()];
    for(size_t i=0;i<locationID.size()-1;i++){
        distance+=distanceBetween[locationID[i]][locationID[i+1]];
    }
    return distance;
}

static double twoOptImprove(vector<int>& tour, double** distanceBetween){
    int n = tour.size();
    if (n < 2) return 0.0;
    bool improved = true;
    while(improved){
        improved = false;
        for (int i = 0; i < n - 2; i++) {
            for (int k = i + 2; k < n; k++) {
                if (k == n - 1 && i == 0) continue; 

                int A = tour[i];
                int B = tour[(i + 1) % n];
                int C = tour[k];
                int D = tour[(k + 1) % n];

                double currentDist = distanceBetween[A][B] + distanceBetween[C][D];
                double newDist = distanceBetween[A][C] + distanceBetween[B][D];

                if (newDist < currentDist) {
                    reverse(tour.begin() + i + 1, tour.begin() + k + 1);
                    improved = true;
                }
            }
        }
    }
    return calculateDistance(tour, distanceBetween);
}

// each run of ACO
void ACO(vector<int>& locationID, vector<int>& solution, double& solutionDistance, double** distanceBetween, const ACOParams& paramsIn){
    int n = locationID.size();
    solution.clear();
    solutionDistance = 0.0;

    // set ACO parameters
    ACOParams p = paramsIn;
    int ants = p.ants;
    int iterations = p.iterations;
    int max_evaluations = p.max_evaluation > 0 ? p.max_evaluation : 10000*n;
    int eval=0;
    double alpha = p.alpha;
    double beta = p.beta;
    double rho = p.rho;
    double Q = p.Q;

    // reset pheromone matrix to 1.0
    vector<vector<double>> pheromone(n, vector<double>(n, 1.0));
    for(int iter=0;iter<iterations;iter++){
        vector<vector<int>> allTours;
        vector<double> allLengths;
        // each ant constructs a tour
        for(int ant=0;ant<ants;ant++){
            if (eval>=max_evaluations) break;
            vector<int> tour;
            vector<bool> visited(n, false);

            // randomly select starting point
            int current = rand() % n;
            tour.push_back(current);
            visited[current] = true;

            // Construct the tour
            for(int step=0;step<n-1;step++){
                double prob=0.0;
                vector<double> probabilities(n, 0.0);
                vector<int> candidates;

                // Calculate probabilities for each unvisited city
                for(int next=0;next<n;next++){
                    if(!visited[next]){
                        double tau = pow(pheromone[current][next], alpha);
                        double eta = pow(1.0/distanceBetween[current][next], beta);
                        probabilities[next] = tau * eta;
                        prob += probabilities[next];
                        candidates.push_back(next);
                    }
                }

                // Roulette wheel selection
                double random = ((double) rand() / RAND_MAX) * prob;
                int selected = -1;
                for(int c : candidates){
                    random -= probabilities[c];
                    if(random <= 0.0){
                        selected = c;
                        break;
                    }
                }

                if (selected == -1) {
                    selected = candidates.back();
                }

                visited[selected] = true;
                tour.push_back(selected);
                current = selected;
            }
            // Apply 2-opt improvement
            double tourLength = twoOptImprove(tour, distanceBetween);

            allTours.push_back(tour);
            allLengths.push_back(tourLength);
            eval++;

            if (tourLength < solutionDistance || solutionDistance == 0.0) {
                solutionDistance = tourLength;
                solution = tour;
            }
        }
        if (eval>=max_evaluations) break;
        // Update pheromones
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pheromone[i][j] *= (1.0 - rho);
            }
        }
        for(size_t k=0;k<allTours.size();k++){
            double contribution = Q / allLengths[k];
            for(int step=0;step<n;step++){
                int from = allTours[k][step];
                int to = allTours[k][(step+1)%n];
                pheromone[from][to] += contribution;
                pheromone[to][from] += contribution;
            }
        }
    }
}

int main(int argc,char* argv[]){
    
    int fileAmount = 0;
    vector<string> fileNames;
    vector<string> outputFileNames;
    vector<string> numbers;
    ACOParams params;

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
    else{
        for (int i = 1; i < argc; i++) {
            string argStr = string(argv[i]);
            if (argStr.find(".txt") != string::npos) {
                fileAmount++;
                size_t pipePos = argStr.find("-");
                if(pipePos != string::npos){
                    string inputName = argStr.substr(0, pipePos);
                    string outputName = argStr.substr(pipePos + 1);
                    fileNames.push_back(inputName);
                    outputFileNames.push_back(outputName);
                } else {
                    fileNames.push_back(argStr);
                    ostringstream oss;
                    oss<<"ans_dt"<<setw(2)<<setfill('0')<<fileAmount<<".txt";
                    outputFileNames.push_back(oss.str());
                }
            } 
            else {
                numbers.push_back(argStr);
            }
        }
        if(fileAmount==0){
            cout<<"No valid .txt file in arguement. Exiting."<<endl;
            return 0;
        }
        if(numbers.size()==7){
            cout<<"Setting parameters"<<endl;
            params.run_times = stoi(numbers[0]);
            params.max_evaluation = stoi(numbers[1]);
            params.ants = stoi(numbers[2]);
            params.alpha = stod(numbers[3]);
            params.beta = stod(numbers[4]);
            params.rho = stod(numbers[5]);
            params.Q = stod(numbers[6]);
        }
        else{
            cout<<"Using default parameters"<<endl;
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
        
        //Set ACO parameters
        int run=params.run_times;
        
        //Set best loop as inital loop to have something to start from
        vector<vector<int>> allSolution(run);
        vector<double> allSolutionDistance(run);
        vector<int> solution;
        
        double solutionDistance = DBL_MAX;
        double meanDistance = 0.0;

        for(int r=0;r<run;r++){
            ACO(locationID,allSolution[r],allSolutionDistance[r],distanceBetween,params);
            meanDistance += allSolutionDistance[r];
            if(allSolutionDistance[r]<solutionDistance){
                solutionDistance = allSolutionDistance[r];
                solution = allSolution[r];
            }
        }
        meanDistance /= run;
        
        //Revert best loop back to string ID
        vector<string> solutionString;
        for(size_t i=0;i<solution.size();i++){
            solutionString.push_back(locationIDString[solution[i]]);
            cout<<solutionString[i]<<" ";
        }
        cout<<endl<<"best: "<<solutionDistance<<" mean: "<<meanDistance<<endl;

        //Set output file name
        //if multiple file -> ans_dt(x).txt
        //else -> ans.txt
        //and write as format
        string outFileName = outputFileNames[f];
        ofstream outFile(outFileName);
        if(outFile.is_open()){
            outFile<<"mean distance: "<<meanDistance<<endl;
            outFile<<"distance: "<<solutionDistance<<endl;
            for(size_t i=0;i<solution.size();i++){
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