#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    int t, n;              
    string p, x, arr;      
    deque<int> q;         
    bool err, r;            

    cin >> t;             
    while (t--) {          
        cin >> p >> n >> arr;  

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == '[') continue;   
            if (arr[i] == ']') {          
                if (x.size() == 0) break;  
                q.push_back(stoi(x));     
                x.erase();                 
                break;                    
            }
            if (arr[i] == ',') {           
                q.push_back(stoi(x));     
                x.erase();                
                continue;                
            }
            x += arr[i];                   
        }

        err = false;                       
        r = false;                        
        for (int i = 0; i < p.size(); i++) { 
            if (p[i] == 'R')              
                r = !r;                   
            else {                        
                if (q.empty()) {          
                    err = true;           
                    break;               
                }

                if (r == false)            
                    q.pop_front();        
                else                       
                    q.pop_back();         
            }
        }

        if (err)                           
            cout << "error" << "\n";       
        else {                             
            cout << "[";                 
            while (!q.empty()) {           
                if (r == false) {        
                    cout << q.front();     
                    q.pop_front();         
                }
                else {                     
                    cout << q.back();      
                    q.pop_back();          
                }

                if (q.empty()) break;      
                cout << ",";             
            }
            cout << "]\n";                 
        }
    }
}
