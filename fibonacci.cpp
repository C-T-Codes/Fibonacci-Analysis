
#include<iostream>
#include <vector>
#include<cmath>
#include<chrono>
#include<ctime>
#include<fstream>
using namespace std;

unsigned long long fib_goldRatio(int num) {
    double goldRatio = ((1 + sqrt(5)) / 2);
    
    double fibgr = 0;
    for (int i = 0; i < num; i++) {
        
        
          fibgr=((pow(goldRatio, num - 1) - pow(1 - goldRatio, num - 1)) / sqrt(5));
          
    }
   return fibgr;
}

 unsigned long long fib_loop(int num) {
     chrono::time_point<chrono::system_clock>start, end;
     start = chrono::system_clock::now();
    unsigned long long fib_current = 0, fib_previous = 1, new_fib = 0;
    ofstream fout;
    fout.open("data.txt");
    for (int i = 0; i < num; i++) {
        cout << fib_current << " ";
        

        new_fib = fib_current + fib_previous;
        fib_current = fib_previous;
        fib_previous = new_fib;
        
      
        end = chrono::system_clock::now();
        chrono::duration<double>elapsed_seconds = end - start;
        time_t end_time = chrono::system_clock::to_time_t(end);
        cout << "\tcompleted in: " << elapsed_seconds.count() << "s\n";
         fout << fib_current << '\t'<<elapsed_seconds.count()<<"\n";

    }return fib_current;
    
    fout.close();
}
 unsigned long long  fib_Recursive(int num) {
    if ((num == 1) || (num == 0)) {
        return num;
    }else{
        return fib_Recursive(num - 1) + fib_Recursive(num -2);
    }
}
  
 int fib(int num) {//dynamic 
     chrono::time_point<chrono::system_clock>on, off;
     on = chrono::system_clock::now();
     ofstream pout;
     pout.open("dynamic.txt");

     if (num<1)
         return num;
     vector<unsigned long long>improve(num); 
     improve[0] = 0;// save recent two fib number
     improve[1] = 1;
     for (int i = 2; i < num; i++) {
         improve[i] = improve[i - 1] + improve[i - 2];
         cout << "\n";
         cout << improve[i];
        

         off = chrono::system_clock::now();
         chrono::duration<double>elapsed_secs = off - on;
         time_t off_time = chrono::system_clock::to_time_t(off);
         cout << "\tcompleted in: " << elapsed_secs.count() << "s";
       
         pout << improve[i] << '\t' << elapsed_secs.count() << "\n";

         
         
     }pout.close();
    
 }
 
int main() {

   
    chrono::time_point<chrono::system_clock>go, stop;
    chrono::time_point<chrono::system_clock>up, down;

    int num,i=0;

    cout << "Enter a positive integer.\n";
    cin >> num;// the Nth Fibonacci we want to find
    cout << "the sreis is \n";

        fib_loop(num);
       
    cout << endl;

   go = chrono::system_clock::now();
        cout << "the way other\n";
        ofstream fout;
        fout.open("fibinacciRecurive.txt");
        while (i < num) {
           
            cout <<  fib_Recursive(i)<<'\t';
            
            stop = chrono::system_clock::now();
            chrono::duration<double>elapsed_second = stop - go;
            time_t stop_time = chrono::system_clock::to_time_t(stop);
            cout << "completed in: " << elapsed_second.count() << "s\n"; // shows us the tine in second it took to find fib

            fout<< "\n"<<fib_Recursive(i)<< '\t'<<elapsed_second.count();
                i++;
           
        } fout.close();
        
        cout << endl;        
   
        cout <<"the dynamic way: ";
        fib(num);
         
        cout << endl;
        ofstream pout;
        pout.open("closed form.txt");

     up = chrono::system_clock::now();

        cout << "the closed way\n";
         cout<< fib_goldRatio(num);

         down = chrono::system_clock::now();
         chrono::duration<double>elapsed_sec = down - up;
         time_t down_time = chrono::system_clock::to_time_t(down);

         cout << "\tcompleted in: " << elapsed_sec.count() << "s\n";
         pout << fib_goldRatio(num) <<'\t'<< elapsed_sec.count();
         pout.close();
         
    return 0;
}
