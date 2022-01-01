/*
	group : Facebook Coding Competitions - Facebook Hacker Cup 2021 Qualification Round
	name : A1: Consistency - Chapter 1.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A1_Consistency_Chapter_1.cpp
	url : https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/A1
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    string s[t];
    int counta=0, counte=0, counti=0,counto=0,countu=0,sum=0,countb=0,countc=0,countd=0,countf=0,
    countg=0,counth=0,countj=0,
        countk=0,countl=0,countm=0,countn=0,countp=0,countq=0,
        countr=0,counts=0,countt=0,countv=0,countw=0,countx=0,county=0,countz=0;

    
    for(int i=0;i<t;i++){
        cin>>s[i];
    }
    for(auto i:s){
        cout<<" "<<i;
        string::iterator it;
        for(it=i.begin();it!=i.end();it++){
            if(*it=='E'||*it=='I'||*it=='O'||*it=='U'){
                counta=counta+2;
            }
            else if(*it!='A'){
            
                counta++;
                    
                
            }
            if(*it=='A'||*it=='I'||*it=='O'||*it=='U'){
                counte=counte+2;
            }
            else if(*it!='E'){
            
                counte++;
                    
                
            }
            if(*it=='A'||*it=='E'||*it=='O'||*it=='U'){
                counti=counti+2;
            }
            else if(*it!='I'){
            
                counti++;
                    
                
            }
             if(*it=='A'||*it=='E'||*it=='I'||*it=='U'){
                counto=counto+2;
            }
            else if(*it!='O'){
            
                counto++;
                    
                
            }
             if(*it=='A'||*it=='E'||*it=='I'||*it=='O'){
                countu=counte+2;
            }
            else if(*it!='U'){
            
                countu++;
                    
                
            }
            if(*it!='B'){
                 if(*it!='A'||*it!='E'||*it!='I'||*it!='O'||*it!='U'){
                countb=countb+2;
                }
            else{
                countb++;
                 }
            }
            if(*it!='C'){
                 if(*it!='A'||*it!='E'||*it!='I'||*it!='O'||*it!='U'){
                countc=countc+2;
                }
            else{
                countc++;
                 }
            }
            if(*it!='D'){
                 if(*it!='A'||*it!='E'||*it!='I'||*it!='O'||*it!='U'){
                countd=countd+2;
                }
            else{
                countd++;
                 }
            }
            if(*it!='F'){
                 if(*it!='A'||*it!='E'||*it!='I'||*it!='O'||*it!='U'){
                countf=countf+2;
                }
            else{
                countf++;
                 }
            }
            if(*it!='G'){
                 if(*it!='A'||*it!='E'||*it!='I'||*it!='O'||*it!='U'){
                countg=countg+2;
                }
            else{
                countg++;
                 }
            }
            if(*it!='H'){
                 if(*it!='A'||*it!='E'||*it!='I'||*it!='O'||*it!='U'){
                counth=counth+2;
                }
            else{
                counth++;
                 }
            }
            if(*it!='J'){
                 if(*it!='A'||*it!='E'||*it!='I'||*it!='O'||*it!='U'){
                countj=countj+2;
                }
            else{
                countj++;
                 }
            }
            if(*it!='K'){
                 if(*it!='A'||*it!='E'||*it!='I'||*it!='O'||*it!='U'){
                countk=countk+2;
                }
            else{
                countk++;
                 }
            }
            if(*it!='L'){
                 if(*it!='A'||*it!='E'||*it!='I'||*it!='O'||*it!='U'){
                countl=countl+2;
                }
            else{
                countl++;
                 }
            }
             if(*it!='M'){
                 if(*it!='A'||*it!='E'||*it!='I'||*it!='O'||*it!='U'){
                countm=countm+2;
                }
            else{
                countm++;
                 }
            }
             if(*it!='N'){
                 if(*it!='A'||*it!='E'||*it!='I'||*it!='O'||*it!='U'){
                countn=countn+2;
                }
            else{
                countn++;
                 }
            }
            
             if(*it!='P'){
                 if(*it!='A'||*it!='E'||*it!='I'||*it!='O'||*it!='U'){
                countp=countp+2;
                }
            else{
                countp++;
                 }
            }
             if(*it!='Q'){
                 if(*it!='A'||*it!='E'||*it!='I'||*it!='O'||*it!='U'){
                countq=countq+2;
                }
            else{
                countq++;
                 }
            }
             if(*it!='R'){
                 if(*it!='A'||*it!='E'||*it!='I'||*it!='O'||*it!='U'){
                countr=countr+2;
                }
            else{
                countr++;
                 }
            }
             if(*it!='S'){
                 if(*it!='A'||*it!='E'||*it!='I'||*it!='O'||*it!='U'){
                counts=counts+2;
                }
            else{
                counts++;
                 }
            }
             if(*it!='T'){
                 if(*it!='A'||*it!='E'||*it!='I'||*it!='O'||*it!='U'){
                countt=countt+2;
                }
            else{
                countt++;
                 }
            }
             if(*it!='V'){
                 if(*it!='A'||*it!='E'||*it!='I'||*it!='O'||*it!='U'){
                countv=countv+2;
                }
            else{
                countv++;
                 }
            }
             if(*it!='W'){
                 if(*it!='A'||*it!='E'||*it!='I'||*it!='O'||*it!='U'){
                countw=countw+2;
                }
            else{
                countw++;
                 }
            }
             if(*it!='X'){
                 if(*it!='A'||*it!='E'||*it!='I'||*it!='O'||*it!='U'){
                countx=countx+2;
                }
            else{
                countx++;
                 }
            }
             if(*it!='Y'){
                 if(*it!='A'||*it!='E'||*it!='I'||*it!='O'||*it!='U'){
                county=county+2;
                }
            else{
                county++;
                 }
            }
             if(*it!='Z'){
                 if(*it!='A'||*it!='E'||*it!='I'||*it!='O'||*it!='U'){
                countz=countz+2;
                }
            else{
                countz++;
                 }
            }
    }
        cout<<" "<<min({counta,counte,counti,counto,countu,countb,countc,countd,countf,countg,counth,countj,
        countk,countl,countm,countn,countp,countq,countr,counts,countt,countv,countw,countx,county,countz});
        sum=sum+min({counta,counte,counti,counto,countu,countb,countc,countd,countf,countg,counth,countj,
        countk,countl,countm,countn,countp,countq,countr,counts,countt,countv,countw,countx,county,countz});
        counta=0, counte=0, counti=0,counto=0,countu=0;
       countb=0,countc=0,countd=0,countf=0, countg=0,counth=0,countj=0,
        countk=0,countl=0,countm=0,countn=0,countp=0,countq=0,
        countr=0,counts=0,countt=0,countv=0,countw=0,countx=0,county=0,countz=0;

       
    }
     cout<<" "<<sum;
    return 0;
}