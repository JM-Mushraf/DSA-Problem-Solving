#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main()
{
    //creation
    unordered_map<string,int>u_map;
    map<string,int>o_map;

    //insertion
    // 1
    pair<string,int>p1=make_pair("way1",1);
    u_map.insert(p1);
    //2
    pair<string,int>p2("way2",2);
    u_map.insert(p2);
    //3
    u_map["way3"]=1;
    u_map["way3"]=2;// here value will be updated from 1 to 2

    //search
    cout<<u_map["way2"]<<endl;
    cout<<u_map.at("way2")<<endl;

    // cout<<u_map.at("unknownKey")<<endl;//this gives key not found error
    cout<<u_map["unknownKey"]<<endl; //this creates entry in hash map for key "unknownKey" with val 0
    cout<<u_map.at("unknownKey")<<endl;//this gives 0 since already the above line made entry for key "unknownKey" in hashTable

    //size
    cout<<"Size:"<<u_map.size()<<endl;

    //to check presence of key use .count() func
    if(u_map.count("bro")){
        cout<<"bro key is present in map"<<endl;
    }else{
        cout<<"bro key is not present in map"<<endl;
    }

    //erasing key from map
    if(u_map.count("way3")){
        cout<<"'way3' key is present in map befor erasing and size of map is "<<u_map.size()<<endl;
    }else{
        cout<<"'way3' key is present not in map before erasing and size of map is "<<u_map.size()<<endl;
    }
    u_map.erase("way3");
    if(u_map.count("way3")){
        cout<<"'way3' key is not present in map after erasing and size of map is "<<u_map.size()<<endl;
    }else{
        cout<<"'way3' key is present not in map after erasing and size of map is "<<u_map.size()<<endl;
    }

    //traversing map
    // way1
    for(auto i:u_map){
        cout<<"Key:"<<i.first<<" Value:"<<i.second<<endl;
    }
    //way2
    unordered_map<string,int> :: iterator it=u_map.begin();

    while(it!=u_map.end()){
        cout<<"Key:"<<it->first<<" Value:"<<it->second<<endl;
        it++;
    }
    return 0;
}