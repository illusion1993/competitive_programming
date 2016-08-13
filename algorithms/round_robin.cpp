/*
    Mini Project On Round Robin
    Submitted By:
                    Vikram Singh Rathore
                    and
                    Jaishree Pandey

                    CS-D Section
                    3rd Year
*/
#include<iostream>
#include<vector>
#include<ctime>
#include<windows.h>
using namespace std;

struct process{
    int process_number, remaining_time;
};
struct execution{
    int process_number, start_time, end_time;
};

vector<process> ready_queue;
vector<execution> gantt_chart;

int n, system_time=0, time_quantum;

int enqueue_next_process(int*, int*, int*);  //function to add next process in ready queue
process generate_process(int, int); //function to generate a process structure to enqueue
execution generate_execution(int, int, int); //function to generate an execution and push it in gantt chart
int execute(int*, int*, int*);  //function to execute processes from ready queue
int execution_complete(int*);   //function to check if all the processes are executed
void refragment_gantt_chart();  //function to finalize gantt chart for display
void display_gantt_chart(); //function to display gantt chart
void simulate_execution(); //function to simulate the process execution in real time
void gotoxy(int, int);

int main(){

    cout<<" C++ PROGRAM TO ILLUSTRATE THE WORKING OF ROUND-ROBIN SCHEDULING ALGORITHM"<<endl<<endl<<endl;
    cout<<" Enter the total number of processes: ";
    cin>>n;
    cout<<" Enter the time quantum: ";
    cin>>time_quantum;

    int arrival_times[n], burst_times[n], status[n];

    for(int i=0; i<n; i++){
        system("cls");
        cout<<" C++ PROGRAM TO ILLUSTRATE THE WORKING OF ROUND-ROBIN SCHEDULING ALGORITHM"<<endl<<endl<<endl;
        cout<<endl<<" ____Process "<<i+1<<"____"<<endl<<endl<<" Enter Arrival Time: ";
        cin>>arrival_times[i];
        cout<<" Enter Burst Time: ";
        cin>>burst_times[i];
        status[i]=0;
    }
    system("cls");
    cout<<" C++ PROGRAM TO ILLUSTRATE THE WORKING OF ROUND-ROBIN SCHEDULING ALGORITHM"<<endl<<endl<<endl;

    while(enqueue_next_process(arrival_times, burst_times, status)==0) system_time++;

    if(ready_queue.size()!=0) execute(arrival_times, burst_times, status);
    else cout<<endl<<endl<<" __Result__No process executed";

    refragment_gantt_chart();

    int ch;
    cout<<endl<<endl<<" Make a choice: "<<endl<<endl<<" 1. View Gantt Chart"<<endl<<" 2. Simulate process execution in real time"<<endl<<endl<<" Your choice: ";
    cin>>ch;

    if(ch==1) display_gantt_chart();
    else if(ch==2) simulate_execution();
    else cout<<endl<<endl<<" Bad request"<<endl;
    return 0;
}

int enqueue_next_process(int *arrival_times, int *burst_times, int *status){
    int next_index=-1;
    for(int i=0; i<n; i++){
        if(arrival_times[i]<=system_time && status[i]==0 && next_index==-1) next_index=i;
        else if(arrival_times[i]<=system_time && status[i]==0 && burst_times[i]<burst_times[next_index]) next_index=i;
    }
    if(next_index==-1) return 0;
    else{
        ready_queue.push_back(generate_process(next_index, burst_times[next_index]));
        status[next_index]=1;
        enqueue_next_process(arrival_times, burst_times, status);

        return 1;
    }
}
process generate_process(int p_number, int r_time){
    process next_process;
    next_process.process_number=p_number;
    next_process.remaining_time=r_time;

    return next_process;
}
execution generate_execution(int p_number, int s_time, int e_time){
    execution next_execution;
    next_execution.process_number=p_number;
    next_execution.start_time=s_time;
    next_execution.end_time=e_time;

    return next_execution;
}
int execute(int *arrival_times, int *burst_times, int *status){
    process current_process=ready_queue[0];
    ready_queue.erase(ready_queue.begin());

    int execution_duration=(time_quantum>current_process.remaining_time)?current_process.remaining_time:time_quantum;

    execution current_execution;

    current_execution.process_number = current_process.process_number;
    current_execution.start_time=system_time;
    current_execution.end_time=system_time+execution_duration;

    gantt_chart.push_back(current_execution);

    current_process.remaining_time = current_process.remaining_time - execution_duration;
    system_time+=execution_duration;

    enqueue_next_process(arrival_times, burst_times, status);
    if(current_process.remaining_time>0) ready_queue.push_back(current_process);

    if(ready_queue.size()!=0) execute(arrival_times, burst_times, status);
    else{
        if(!execution_complete(status)){
            while(enqueue_next_process(arrival_times, burst_times, status)==0) system_time++;
            if(ready_queue.size()!=0) execute(arrival_times, burst_times, status);
        }
    }
    return 0;
}
int execution_complete(int *status){
    int flag=1;
    for(int i=0; i<n; i++){
        if(status[i]==0){
                flag=0;
                break;
        }
    }
    return flag;
}
void refragment_gantt_chart(){
    if(gantt_chart[0].start_time!=0){
        execution idle;
        idle.process_number=-1;
        idle.start_time=0;
        idle.end_time=gantt_chart[0].start_time;

        gantt_chart.insert(gantt_chart.begin(),idle);
    }
    for(int i=1; i<gantt_chart.size(); i++){
        if(gantt_chart[i].start_time!=gantt_chart[i-1].end_time){
            execution idle;
            idle.process_number=-1;
            idle.start_time=gantt_chart[i-1].end_time;
            idle.end_time=gantt_chart[i].start_time;

            gantt_chart.insert(gantt_chart.begin()+i,idle);
        }
    }
}
void display_gantt_chart(){
    system("cls");
    cout<<" C++ PROGRAM TO ILLUSTRATE THE WORKING OF ROUND-ROBIN SCHEDULING ALGORITHM"<<endl<<endl<<endl;
    cout<<endl<<" __Gantt chart for given processes__"<<endl<<endl;
    cout<<"|";
    for(int i=0; i<gantt_chart.size(); i++){
        cout<<"------|";
    }
    cout<<endl<<"|";
    for(int i=0; i<gantt_chart.size(); i++){
        cout<<"      |";
    }
    cout<<endl<<"|";
    for(int i=0; i<gantt_chart.size(); i++){
        if(gantt_chart[i].process_number!=-1){
            cout<<"  P"<<gantt_chart[i].process_number+1;
            if(gantt_chart[i].process_number+1<=9) cout<<"  |";
            else if(gantt_chart[i].process_number+1<=99 && gantt_chart[i].process_number+1>9) cout<<" |";
            else if(gantt_chart[i].process_number+1<=999 && gantt_chart[i].process_number+1>99) cout<<"|";
        }
        else cout<<" Idle |";
    }
    cout<<endl<<"|";
    for(int i=0; i<gantt_chart.size(); i++){
        cout<<"      |";
    }
    cout<<endl<<"|";
    for(int i=0; i<gantt_chart.size(); i++){
        cout<<"------|";
    }
    cout<<endl<<"0      ";
    for(int i=1; i<gantt_chart.size(); i++){
        cout<<gantt_chart[i].start_time;
        int pow=0;
        for(int j=10; j<100000; j*=10){
            pow++;
            if(gantt_chart[i].start_time/j==0) break;
        }
        pow--;
        for(int j=0; j<6-pow; j++) cout<<" ";
    }
    cout<<gantt_chart[gantt_chart.size()-1].end_time<<endl<<endl;
    int ch;
    cout<<endl<<" Do you want to view a simulation of this schedule in real time?"<<endl<<endl<<" 1. Yes"<<endl<<" 2. No"<<endl<<endl<<" Your choice: ";
    cin>>ch;
    cout<<endl<<endl;
    if(ch==1) simulate_execution();
}
void simulate_execution(){
    system("cls");
    cout<<" C++ PROGRAM TO ILLUSTRATE THE WORKING OF ROUND-ROBIN SCHEDULING ALGORITHM";
    gotoxy(1,3);
    cout<<"Time: ";
    for(int i=0; i<=system_time; i++){
        gotoxy(7,3);
        cout<<i<<"s         ";
        int current;
        for(int j=0; j<gantt_chart.size(); j++){
            if(gantt_chart[j].start_time<=i && gantt_chart[j].end_time>i){
                current=gantt_chart[j].process_number;
                break;
            }
        }
        gotoxy(1,7);
        if(current!=-1) cout<<"Executing Process "<<current+1<<endl<<endl;
        else cout<<"Processor Idle       "<<endl<<endl;
        clock_t start_time = clock();
        clock_t end_time = 1 * 1000 + start_time;
        while(clock() != end_time);
    }
    system("cls");
    cout<<" C++ PROGRAM TO ILLUSTRATE THE WORKING OF ROUND-ROBIN SCHEDULING ALGORITHM"<<endl<<endl<<endl;
    cout<<" Execution completed at time "<<system_time<<"s    "<<endl<<endl;
    int ch;
    cout<<" Do you want to view a Gantt Chart of this schedule?"<<endl<<endl<<" 1. Yes"<<endl<<" 2. No"<<endl<<endl<<" Your choice: ";
    cin>>ch;
    if(ch==1) display_gantt_chart();
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
