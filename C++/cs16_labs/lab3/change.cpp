#include <iostream> 
#include <string>

using namespace std;
    int quarternum;
    int dimenum;
    int centnum;

void compute_coins(int amount)
{   
    quarternum = amount/25;
    dimenum = (amount - 25 * quarternum)/10;
    centnum = amount - quarternum * 25 - dimenum * 10; 
    int list[] = {quarternum,dimenum,centnum};

}
int amount;
int main(){
    string res = "";
    do {
        cout << "Enter number of cents (or zero to quit): " << endl;
        cin >> amount;
        if(amount==0){
            return 0;
        }
        else if(amount < 0 || amount > 100){
            cout << "Amount is out of bounds. Must be between 1 and 99. " << endl;
        }else{
            compute_coins(amount);
            if(amount ==1){
            res = to_string(amount) + " cent can be given in ";
            // if(amount==1){ 
            //     cout << 
            // }
            }else{
               res = to_string(amount) + " cents can be given in "; 
            }
            if (quarternum) {
                res += to_string(quarternum) + " quarter";
                if (quarternum > 1) {
                    res += "s";
                }
                res += ", ";
            }
            if (dimenum){
                res += to_string(dimenum) + " dime";
                if (dimenum > 1){
                    res += "s";
                }
                res += ", ";
            } 
            if (centnum){
                 res += to_string(centnum);
                 if(centnum==1){
                     res += " penny";
                 }else if(centnum > 1){
                     res += " pennies";
                 }
                 res += ", ";
            }
            res = res.substr(0, res.size() - 2);
            res += ".";
            // cout << dimenum << endl;
            // cout << quarternum << endl;
            // cout << centnum << endl;
            // if(quarternum&!dimenum || dimenum & !centnum || quarternum  & !centnum){
            //     res = res.length()-2;
            //     res += ".";
            // }
            cout << res << endl;
        }
        res = "";
    }while(amount!=0);
    

    return 0;
}