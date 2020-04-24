//#include <iostream>
//#include <iterator>
//#include <algorithm>
//
//using namespace std;
//int main(void){
//        
//    char letter[] = {'A','E','G','I','O','S','Z'};
//    int number[] = {4,3,6,1,0,5,2};
//    
//    string str;
//    cin >> str;
//
//    for(char n : str){
//        
//        bool exists =  std::find(std::begin(letter), std::end(letter), n) != std::end(letter);
//        if(exists){
//            int index = std::find(letter, letter+sizeof(letter), n) - letter;    
//            cout << number[index];
//        } else  {
//            cout << n;
//        }
//    }
//
//    return 0;
//}
