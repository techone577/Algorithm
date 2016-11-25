#include <iostream>
using namespace std;

#include <string>
using namespace std;

int *f;

void FailureFunction(string &pat){
    
    const int  lengthP = static_cast<int>(pat.length());
    f = new int(lengthP);

    
    
    f[0]=-1;
    for(int j=1;j<lengthP;j++){
        
        int i = f[j-1];
        
        while( (pat[j]!=pat[i+1])&&(i>=0) ){
            
            
            i=f[i];
            
        }
        
        
        
        if(pat[j]==pat[i+1]){
            
            
            f[j]=i+1;
        }
        else
            f[j]=-1;
        
        
        
        
    }
    for(int j=1;j<lengthP;j++){
        
        
        if(pat[f[j]+1]==pat[j+1]){
            
            
            f[j]=-1;
        }
        
        
    }

    
    
}

int FastFind(string &s,string &pat){

  FailureFunction(pat);
    int posP=0,posS=0;
    
    int lengthP =static_cast<int>(pat.length());
    int lengthS = static_cast<int>(s.length());
    
    while((posP<lengthP)&&(posS<lengthS)){
        if(pat[posP]==s[posS]){
            posP++;
            posS++;
        }
        else{
            
            if(posP==0)
                posS++;
            
            else
                posP=f[posP-1]+1;
            
        }
        
    
    
    }
    
    
    if(posP<lengthP)
        return -1;
    else
        return posS-lengthP;
    
}

int main(){
    
    
    string a="de";
    string s="abcdefg";
    
    cout<< FastFind(s, a);
    
    
    
  
 }
