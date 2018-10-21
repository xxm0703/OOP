#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <istream>

using namespace std;

class Exception {
    string error_message_;

public:
    Exception(string msg) {
        error_message_ = msg;
    }

    string get_message() {
        return error_message_;
    }
};


int countWords(string sentense)
{

    stringstream s(sentense);
    string word;
    int k = 0;

    int count = 0;
    while (s >> word){
        if(word == "-" || word == "."){
            k+=1;
        }
        count++;
                     }
    return count-k;
}

int main() {



    string sentense;
    string input;
    string strict = "strict";
    string sen = "sentences-up-to:";
    string two = "strict sentences-up-to:";

    int n=0, c=0,count=0;
    int size=0;
    while(cin){
    getline(cin, input);
        if(input == "END"){
            break;
        }

            sentense = sentense + " " + input;



    }
    if(sentense.find(strict) != string::npos && sentense.find(sen) != string::npos){
          try{

         sentense.erase(sentense.find(strict), strict.length());

         sentense.erase(sentense.find(sen), sen.length());



            int k=0;
            string p = "";
            for(int i=2;i<sentense.length();i++){

                if(sentense[i] == ' '){

                    p = sentense.substr(k,i);

                    sentense.erase(0, i);
                    break;
                }
            }



                int j=0;

                for(int i=0;i<sentense.length();i++){

                    string s = "";
                    if(sentense[i] == '.'){

                        s=sentense.substr(j,i+1);

                        int x = atoi(p.c_str());

                        if( countWords(s) <= x){
                            n+=1;

                            count+=countWords(s);
                        for(int i=0;i<s.length();i++){
                             if(s[i] == '('){
                                 c++;
                             }
                             if(c < 0){
                                 throw Exception("ERR: PROVIDE MATCHING PARENTHESES");

                             }
                             if(s[i] == ')'){
                                 c-=1;
                             }

                         }
                         if(c != 0){

                             throw Exception("ERR: PROVIDE MATCHING PARENTHESES");

                          }



                            for(int k=0;k<s.length();k++){
                                if(s[k]>='A' && s[k]<+'Z' || s[k]>='a' && s[k]<='z'){
                                    size+=1;

                                }
                            }


                             s.clear();

                    }
                        j=i+1;

                    }


                }
                if(sentense.empty()){
                    throw Exception("ERR: PROVIDE AT LEAST ONE SENTENCE OR WORD");
                }else{
                int e=0;
                for(int i=0;i<sentense.length();i++){
                    if(sentense[i]>='A' && sentense[i]<+'Z' || sentense[i]>='a' && sentense[i]<='z'){
                        cout << round(count/(float)n)<< " "<< round((float)size/count) << endl;
                        e+=1;
                        break;
                    }

                }
                if(e==0){
                        throw Exception("ERR: PROVIDE AT LEAST ONE SENTENCE OR WORD");
                    }
                }
                }catch (Exception e){
                    cout << e.get_message() << endl;
                }


    }else if(sentense.find(sen) != string::npos && sentense.find(strict) == string::npos){
        sentense.erase(sentense.find(sen), sen.length());
            int k=0;
            string p = "";
            for(int i=1;i<sentense.length();i++){
                if(sentense[i] == ' '){
                    p = sentense.substr(k,i);
                    sentense.erase(0, i);
                    break;
                }
            }

                int j=0;

                for(int i=0;i<sentense.length();i++){

                    string s = "";
                    if(sentense[i] == '.'){

                        s=sentense.substr(j,i+1);

                        int x = atoi(p.c_str());

                        if( countWords(s) <= x){
                            n+=1;

                            count+=countWords(s);


                            for(int k=0;k<s.length();k++){
                                if(s[k]>='A' && s[k]<+'Z' || s[k]>='a' && s[k]<='z'){
                                    size+=1;

                                }
                            }


                             s.clear();

                    }
                        j=i+1;

                    }


                }
                 try{
                if(sentense.empty()){
                    throw Exception("ERR: PROVIDE AT LEAST ONE SENTENCE OR WORD");
                }else{
                int e=0;
                for(int i=0;i<sentense.length();i++){
                    if(sentense[i]>='A' && sentense[i]<+'Z' || sentense[i]>='a' && sentense[i]<='z'){
                        cout << round(count/(float)n)<< " "<< round((float)size/count) << endl;
                        e+=1;
                        break;
                    }

                }
                if(e==0){
                        throw Exception("ERR: PROVIDE AT LEAST ONE SENTENCE OR WORD");
                    }
                }
                }catch(Exception e){
                    cout << e.get_message() << endl;
                }

    }else if(sentense.find(strict) != string::npos && sentense.find(sen) == string::npos){
        sentense.erase(sentense.find(strict), strict.length());
             try{
                int j=0;
                for(int i=0;i<sentense.length();i++){

                    string s = "";
                    if(sentense[i] == '.'){

                        s=sentense.substr(j,i+1);

                        count+=countWords(s);
                        for(int z=0;z<s.length();z++){
                             if(s[z] == ')'){
                                 c--;
                                 if(c < 0){
                                     throw Exception("ERR: PROVIDE MATCHING PARENTHESES");

                                 }
                             }
                             if(s[z] == '('){
                                 c++;
                             }

                         }if(c != 0){
                             throw Exception("ERR: PROVIDE MATCHING PARENTHESES");

                         }


                        for(int k=0;k<s.length();k++){
                            if(s[k]>='A' && s[k]<+'Z' || s[k]>='a' && s[k]<='z'){
                                size+=1;
                            }
                        }
                        s.clear();

                        j=i+1;
                        n+=1;
                    }

                }
                if(sentense.empty()){
                    throw Exception("ERR: PROVIDE AT LEAST ONE SENTENCE OR WORD");
                }else{
                int e=0;
                for(int i=0;i<sentense.length();i++){
                    if(sentense[i]>='A' && sentense[i]<+'Z' || sentense[i]>='a' && sentense[i]<='z'){
                        cout << round(count/(float)n)<< " "<< round((float)size/count) << endl;
                        e+=1;
                        break;
                    }

                }
                if(e==0){
                        throw Exception("ERR: PROVIDE AT LEAST ONE SENTENCE OR WORD");
                    }
                }
                }catch(Exception e){
                    cout << e.get_message() << endl;
                }


    }else{
    int j=0;
    for(int i=0;i<sentense.length();i++){

        string s = "";
        if(sentense[i] == '.'){

            s=sentense.substr(j,i);

            count+=countWords(s);


            for(int k=0;k<s.length();k++){
                if(s[k]>='A' && s[k]<+'Z' || s[k]>='a' && s[k]<='z'){
                    size+=1;
                }
            }
            s.clear();
            j=i;
            n+=1;
        }

    }
    try{
            if(sentense.empty()){
                throw Exception("ERR: PROVIDE AT LEAST ONE SENTENCE OR WORD");
            }else{
                int e=0;
                for(int i=0;i<sentense.length();i++){
                    if(sentense[i]>='A' && sentense[i]<='Z' || sentense[i]>='a' && sentense[i]<='z'){
                        cout << round(count/(float)n)<< " "<< round((float)size/count) << endl;
                        e+=1;
                        break;
                    }

                }
                if(e==0){
                        throw Exception("ERR: PROVIDE AT LEAST ONE SENTENCE OR WORD");
                    }
            }
           }catch(Exception e){
               cout << e.get_message() << endl;
           }
    }




    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
