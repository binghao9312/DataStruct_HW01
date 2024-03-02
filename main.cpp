#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int ANS;
//ofstream //outfile("output.txt");
bool ANS_ALREADY;
int check_ans(vector<vector<int>>& inputData, vector<int>& visit_vec, vector<int>& elements, int n) {
    int total = 0;
    for (size_t i = 0; i < elements.size(); i++) {
        int index = elements[i];
        //outfile << index << " ";
        for (size_t j = 0; j < n; j++) {
            //outfile << inputData[index][j];
            if (inputData[index][j] == 1) {
                visit_vec[j] = 1;
            } 
        }
        //outfile << endl;
    }
    for (size_t i = 0; i < elements.size(); i++){
        visit_vec[elements[i]] = 1;
    }
    /*
    cout << "visit_vec: " << endl;
    outfile << "\nvisit_vec: " << endl;
    for (size_t i = 0; i < visit_vec.size(); i++){
        cout << visit_vec[i] << " ";
        outfile << visit_vec[i] << " ";
    }
    cout << endl << endl;
    outfile << endl << endl;
    */

    for (size_t i = 0; i < visit_vec.size(); i++){
        if(visit_vec[i] == 1){
            total ++;
        }
    }
    

    if (total == visit_vec.size()) {
        ANS = elements.size();
        ANS_ALREADY = true;
        return 1;
    }

    return 0;
}

void generateCombinations(vector<int>& nums, vector<int>& combination, int start, int k, int n, vector<int>& visit_vec, vector<vector<int>>& inputData) {
    if (k == 0) {
        //outfile << "start clear vec\n";
        //cout << "start clear vec\n";
        for (size_t i = 0; i < n; i++){
            visit_vec[i] = 0;
            //outfile << visit_vec[i] << " ";
        }
        //outfile << endl << endl;
        
        
        if (check_ans(inputData, visit_vec, combination, n)) {
            // if(ANS_ALREADY) exit;
            return;
        }
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        if(ANS_ALREADY){break;}
        combination.push_back(nums[i]);
        generateCombinations(nums, combination, i + 1, k - 1, n, visit_vec, inputData);
        combination.pop_back();
    }
}

int main() {
    while (1) {
        ANS = 0;
        ANS_ALREADY = false;
        vector<vector<int>> inputData;
        vector<int> visit_vec;
        vector<int> nums;
        int n = 0;
        cin >> n;
        if (n == -1) {
            break;
        } 
        else {
            inputData.resize(n, vector<int>(n, 0));
            visit_vec.resize(n, 0);

            for (size_t i = 0; i < n; i++) {
                nums.push_back(i);
            }

            for (size_t i = 0; i < n; i++) {
                for (size_t j = 0; j < n; j++) {
                    cin >> inputData[i][j];
                }
            }

            for (int k = 0; k <= nums.size(); k++) {
                vector<int> combination;
                generateCombinations(nums, combination, 0, k, n, visit_vec, inputData);
            }
            if(ANS_ALREADY)
                cout << ANS << endl;
        }
    }
    return 0;
}
