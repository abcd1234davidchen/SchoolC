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

struct point{
    double x;
    double y;
};

struct Params {
    int run_times = 30;
    int max_evaluation = -1;
    double dotFactor = 2.5;
    double alpha = 0.375;
    double beta = 0.87;
    double temperature = 0.27;
    double cooling_rate = 0.9995;
};

void recordDistances(vector<point> &location,double** distanceBetween){
    //Go through every two point and calculate each distance
    for(size_t i = 0; i < location.size(); i++){
        for(size_t j = 0; j < location.size(); j++){
            if(i == j) distanceBetween[i][j] = 0.0;
            int dx = location[i].x - location[j].x;
            int dy = location[i].y - location[j].y;
            distanceBetween[i][j] = sqrt(dx*dx+dy*dy);
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

void elasticNet(vector<point>& originLocation,vector<int>& solution,double& solutionDistance,
    double** distanceBetween,const Params& paramsIn, vector<vector<point>>& GIFData){
    
    //Initialize parameters
    int n = originLocation.size();
    int m = static_cast<int>(n * paramsIn.dotFactor);
    int max_evaluation = paramsIn.max_evaluation==-1 ? n * 10000 : paramsIn.max_evaluation;

    double alpha = paramsIn.alpha;
    double beta = paramsIn.beta;
    double K = paramsIn.temperature;
    
    // Normalize locations to [0,1] range
    vector<point> location = originLocation;
    double minX = DBL_MAX, maxX = -DBL_MAX;
    double minY = DBL_MAX, maxY = -DBL_MAX;
    for(const auto& loc : originLocation){
        if(loc.x < minX) minX = loc.x;
        if(loc.x > maxX) maxX = loc.x;
        if(loc.y < minY) minY = loc.y;
        if(loc.y > maxY) maxY = loc.y;
    }
    for(auto& loc : location){
        loc.x = (loc.x - minX) / (maxX - minX);
        loc.y = (loc.y - minY) / (maxY - minY);
    }
    
    // Initialize elastic net
    point centroid = {0.0, 0.0};
    for(auto& loc : location){
        centroid.x += loc.x;
        centroid.y += loc.y;
    }
    centroid.x /= n;
    centroid.y /= n;
    vector<point> net(m);
    double radius = 0.5;
    for(int i = 0; i < m; i++){
        double angle = 2 * M_PI * i / m;
        net[i].x = centroid.x + radius * cos(angle);
        net[i].y = centroid.y + radius * sin(angle);
    }
    vector<double> weights(n * m);

    // each iteration
    for(int iter=0;iter<max_evaluation;iter++){
        // Break if K is too small
        if(K<0.001) break;

        // Calculate weights for each location-node pair
        for(int i=0;i<n;i++){
            double weight_sum = 0.0;
            for(int j=0;j<m;j++){
                double dx = location[i].x - net[j].x;
                double dy = location[i].y - net[j].y;
                double dist_sq = dx*dx + dy*dy;
                weights[i*m+j] = exp(-dist_sq / (2 * K * K));
                weight_sum += weights[i*m+j];
            }
            for(int j=0;j<m;j++){
                weights[i*m+j] /= weight_sum;
            }
        }

        // Update net positions
        vector<point> new_net = net;
        for(int j=0;j<m;j++){
            double change_x = 0.0;
            double change_y = 0.0;

            // Attraction to data points
            for(int i=0;i<n;i++){
                change_x += weights[i*m+j] * (location[i].x - net[j].x);
                change_y += weights[i*m+j] * (location[i].y - net[j].y);
            }
            change_x *= alpha;
            change_y *= alpha;

            // Tension from neighboring nodes
            change_x += beta * (net[(j+1)%m].x + net[(j-1+m)%m].x - 2 * net[j].x) * K;
            change_y += beta * (net[(j+1)%m].y + net[(j-1+m)%m].y - 2 * net[j].y) * K;

            // Update position
            new_net[j].x += change_x;
            new_net[j].y += change_y;
        }
        // set new net as current net and cool down
        swap(net, new_net);
        K *= paramsIn.cooling_rate;
        
        // Store intermediate net for GIF
        if (iter % 100 == 0) {
            vector<point> unnormalized_net = net;
            double rangeX = maxX - minX;
            double rangeY = maxY - minY;
            for (auto &p : unnormalized_net) {
                p.x = p.x * rangeX + minX;
                p.y = p.y * rangeY + minY;
            }
            GIFData.push_back(unnormalized_net);
        }
    }
    // Assign every city to its single closest node on the rubber band
    vector<pair<int, int>> cityAssignment; 
    
    for(int i = 0; i < n; i++){
        double min_dist = DBL_MAX;
        int best_node_idx = 0;
        
        // Look at all nodes to find the winner
        for(int j = 0; j < m; j++){
            double dx = location[i].x - net[j].x;
            double dy = location[i].y - net[j].y;
            double dist_sq = dx*dx + dy*dy; // No need for sqrt to compare
            
            if(dist_sq < min_dist){
                min_dist = dist_sq;
                best_node_idx = j;
            }
        }
        cityAssignment.push_back({best_node_idx, i});
    }

    // Sort cities based on the order of nodes on the ring
    sort(cityAssignment.begin(), cityAssignment.end());

    // Fill the final solution vector
    solution.clear();
    for(const auto& p : cityAssignment){
        solution.push_back(p.second);
    }
    solutionDistance = calculateDistance(solution, distanceBetween);
}

int main(int argc,char* argv[]){
    
    int fileAmount = 0;
    vector<string> fileNames;
    vector<string> outputFileNames;
    vector<string> numbers;
    Params params;

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
            params.dotFactor = stod(numbers[2]);
            params.alpha = stod(numbers[3]);
            params.beta = stod(numbers[4]);
            params.temperature = stod(numbers[5]);
            params.cooling_rate = stod(numbers[6]);
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
        vector<point> location;
        map<int,string> locationIDString;
        vector<int> locationID;
        
        //Deal with file & assign new ID & save each location
        if (inFile.is_open()){
            string ID;
            point coordinate;
            int intID = 0;
            while(inFile >> ID >>coordinate.x>>coordinate.y){
                location.push_back(coordinate);
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

        //Set parameters
        int run=params.run_times;
        
        //Set best loop as inital loop to have something to start from
        vector<int> solution;
        vector<vector<point>> GIFData;
        
        double solutionDistance = DBL_MAX;
        double meanDistance = 0.0;

        for(int r=0;r<run;r++){
            vector<vector<point>> runGIF;
            vector<int> runSolution;
            double runDistance = 0.0;
            elasticNet(location,runSolution,runDistance,distanceBetween,params, runGIF);
            meanDistance += runDistance;
            if(runDistance<solutionDistance){
                solutionDistance = runDistance;
                solution = runSolution;
                GIFData = runGIF;
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
        // GIF generation using python3
        ofstream gifDataFile("gif_data.txt");
        if (gifDataFile.is_open()) {
            for (const auto& p : location) {
                gifDataFile << p.x << " " << p.y << " ";
            }
            gifDataFile << "\n";
            for (const auto& netState : GIFData) {
                for (const auto& p : netState) {
                    gifDataFile << p.x << " " << p.y << " ";
                }
                gifDataFile << "\n";
            }
            for(size_t i=0;i<solution.size();i++){
                gifDataFile<<location[solution[i]].x<<" "<<location[solution[i]].y<<" ";
            }
            gifDataFile << "\n";
            for(size_t i=0;i<solution.size();i++){
                gifDataFile<<location[solution[i]].x<<" "<<location[solution[i]].y<<" ";
            }
            gifDataFile << "\n";
            for(size_t i=0;i<solution.size();i++){
                gifDataFile<<location[solution[i]].x<<" "<<location[solution[i]].y<<" ";
            }
            gifDataFile << "\n";
            gifDataFile.close();
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
        if(fileAmount==1) drawFileName = "fig.gif";
        else{
            ostringstream oss;
            oss<<"fig_dt"<<setw(2)<<setfill('0')<<(f+1)<<".gif";
            drawFileName = oss.str();
        }

        //Run draw.py to get figure
        ostringstream pythonCommandStream;
        pythonCommandStream<<"python3 draw.py gif_data.txt "<<drawFileName;
        pythonReturn = system(pythonCommandStream.str().c_str());
        if(pythonReturn!=0) cout<<"draw.py return: "<<pythonReturn<<endl;
    }
}