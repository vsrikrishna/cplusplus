nclude <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void strToInt(string s1,int& i1,int& i2){
  cout <<"Inside strToInt"<<endl;
  stringstream ss;
  ss.clear();ss.str("");
  size_t pos = s1.find("-");
  ss << s1.substr(0,pos);
  ss>>i1;
  ss.clear();ss.str("");
  ss << s1.substr(pos+1);
  ss>>i2;
}

string mergeInterval(string s1, string s2,int& i, int& j){
  cout<<"Inside merge interval"<<endl;
  stringstream ss;
  int s1i1,s1i2,s2i1,s2i2;
  strToInt(s1,s1i1,s1i2);
  strToInt(s2,s2i1,s2i2);
  cout<<"s1i1:"<<s1i1<<",s1i2:"<<s1i2<<endl;
  cout<<"s2i1:"<<s2i1<<",s2i2:"<<s2i2<<endl;
  if((s1i1<s2i1) && (s2i2>s1i2)){
    i++;j++;
    ss.clear();ss.str("");
    ss<<s1i1;ss<<"-";ss<<s2i2;
    cout<<ss.str()<<endl;
    return ss.str();
  }
  if((s2i1>s1i1) && (s1i2>s2i2)){
    i++;j++;
    ss.clear();ss.str("");
    ss<<s2i1;ss<<"-";ss<<s1i2;
    cout<<ss.str()<<endl;
    return ss.str();
  }
  if((s1i1<s2i1) && (s1i2<s2i2)){
    i++;
    ss.clear();ss.str("");
    ss<<s1i1;ss<<"-";ss<<s1i2;
    cout<<ss.str()<<endl;
    return ss.str();
  }
  if((s1i1>s2i1) && (s1i2>s2i2)){
    j++;
    ss.clear();ss.str("");
    ss<<s2i1;ss<<"-";ss<<s2i2;
    cout<<ss.str()<<endl;
    return ss.str();
  }
  return "";
}
int main(){
  string int1[]={"3-11", "17-25", "58-73"};
  string int2[]={"6-18", "40-47"};
  vector<string> res;
  int n1,n2,i=0,j=0,k=0;

  n1=sizeof(int1)/sizeof(int1[0]);
  n2=sizeof(int2)/sizeof(int2[0]);

  cout<<"before while"<<endl;
  while((i<n1) || (j<n2)){
    if((i<n1) && (j<n2)){
     res.push_back(mergeInterval(int1[i],int2[j],i,j));
      cout<<"i:"<<i<<",j:"<<j<<endl;
      //k++;
    }
    else if(i<n1){
      res.push_back(int1[i++]);
    }
    else if(j<n2){
      res.push_back(int2[j++]);
    }
    cout<<"i:"<<i<<",j:"<<j<<",k:"<<k<<endl;
  }
  cout<<"result is"<<endl;
  for(int i=0;i<res.size();i++){
    cout<<res[i]<<" ";
  }cout<<endl;
  return 0;
}
