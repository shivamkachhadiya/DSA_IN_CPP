class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
       
        vector<int> start_arr;
        vector<int> end_arr;
        string temp = "";
        for (int i = 0; i < startTime.size(); i++) {
            if (startTime[i] == ':') {
                start_arr.push_back(stoi(temp));
                temp = "";
            } else {
                temp += startTime[i];
            }
        }
        start_arr.push_back(stoi(temp)); 

        string temp2 = "";
        for (int i = 0; i < endTime.size(); i++) {
            if (endTime[i] == ':') {
                end_arr.push_back(stoi(temp2));
                temp2 = "";
            } else {
                temp2 += endTime[i];
            }
        }
        end_arr.push_back(stoi(temp2)); 

        int startH=start_arr[0];
        int startM=start_arr[1];
        int startS=start_arr[2];

        int total_sec_H=startH*60*60;
        int total_sec_M=startM*60;
        int total_sec_S=startS;

        int final_total_start_time_in_seconds=total_sec_H+total_sec_M+total_sec_S;

        int endH=end_arr[0];
        int endM=end_arr[1];
        int endS=end_arr[2];

        int E_total_sec_H=endH*60*60;
        int E_total_sec_M=endM*60;
        int E_total_sec_S=endS;

        int final_total_end_time_in_seconds=E_total_sec_H+E_total_sec_M+E_total_sec_S;

        return final_total_end_time_in_seconds-final_total_start_time_in_seconds;
      
    }
};