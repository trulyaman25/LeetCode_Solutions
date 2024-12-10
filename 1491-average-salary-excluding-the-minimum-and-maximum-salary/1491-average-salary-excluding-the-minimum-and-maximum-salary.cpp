class Solution {
public:
    double average(vector<int>& salary) {
        double sum = 0;
        double maximumSalary = INT_MIN;
        double minimumSalary = INT_MAX;
        for(int i = 0; i < salary.size(); i++){
            sum += salary[i];
            if(salary[i] > maximumSalary){
                maximumSalary = salary[i];
            }
            if(salary[i] < minimumSalary){
                minimumSalary = salary[i];
            }
        }
        double difference = maximumSalary + minimumSalary;
        double average = (sum - difference) / (salary.size() - 2);

        return average;
    }
};