#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int partition(vector<int>&v, int left, int right);
void quick_sort(vector<int>&v, int left, int right);
void Begin(vector<int> &v, int size);

int main (){
    srand(time(0));
    vector<int>v; // use for store the arrived time.
    int sum_wait=0; // use for sum the number of wait time.
    float Cashiers; // Is the number of cashiers that bank need to open.
    int Mincus, Maxcus; // Min and Max number of customer
    int Numcus; // All number of customers.
    int Minservice; // Minservice time
    int Maxservice; // Maxservice time
    int diff; // the diffirent between Min and Max of service.
    int wait = 0; // Is the wait time of ecah customers.
    float count=0; // use for count the number of customers in one cashier.
    vector<int> wait_time; // use for store each customer wait time.
    queue<int> Q; // use for store the all time of ecah customer.

    //Input
    cout << "Welcome to BANK SIMOLATION" << endl;
    cout << "Please endter number of mincustomers and maxcustomers respectively"<< endl;
    cin >> Mincus >> Maxcus;
    cout << "Please endter number of min and max service time respectively"<< endl;
    cin >> Minservice >> Maxservice;

    Numcus = rand()%Maxcus+Mincus;
    diff=Maxservice - Minservice;
    Begin(v,Numcus);
    quick_sort(v,0,v.size()-1);

    // Output
    cout << endl;
    cout << "Simulation one cashier" << endl;
    for(int j=0; j<v.size(); j++){
        Maxservice = rand()%diff+Minservice; 
        Q.push(v[j] + wait + Maxservice); 
        wait_time.push_back(wait);
        
        if(Q.front()<=240){ // We simulation only 240 minutes.
            sum_wait += wait;
            cout <<"Customer - " << j+1 << " - arrived - " << v[j] << " - service time - "<< Maxservice << " - wait time - " << wait_time[j] << " - left "<< Q.front() <<endl;
            if(v[j+1]<Q.front()){
                wait = abs(Q.front()-v[j+1]);
            }
            Q.pop();
            count++;
        }
    }

    cout << endl;
    cout << "Number of customer is: "<<v.size() << endl;
    cout << "Average wait time: " << sum_wait/count << " minutes." << endl;
    Cashiers = v.size()/count;
    cout << "One cashier can service " << count << " customers that means the bank need to open " << ceil(Cashiers) << " cashiers.";

    cout << endl;
    return 0;
}

int partition(vector<int>&v, int left, int right){
    int piIndex = left + (right - left) / 2;
    int piValues = v[piIndex];
    int i = left, j = right; // left use for hold the value at first index and right use for hold the value at last index  
    int temp; // use for hold a value while sort this vector

    while(i<=j){
        while(v[i] < piValues){
            i++;
        }
        while(v[j] > piValues){
            j--;
        }
        if(i<=j){
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

void quick_sort(vector<int>&v, int left, int right){
    if(left < right){
        int piIndex = partition(v,left,right);
            quick_sort(v,left,piIndex-1);
            quick_sort(v,piIndex,right);
    }
}

void Begin(vector<int> &v, int size){
    int arrived;
    for(int i=0; i<size; i++){
        arrived = rand()%240;
        v.push_back(arrived); 
    }
}