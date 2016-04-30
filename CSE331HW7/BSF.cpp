#include <cstdlib>
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <queue>

//function for reading from a text file
 string readfromfile(string filename){
    string line;
    string output="";
    ifstream myfile(filename.c_str());//file name to read from
    if (myfile.is_open()){
        while(myfile>>line){
            //cout<<line<<endl;
            output= output + line.c_str();
        }
        myfile.close();
    }
    else{ cout<< "unable to open input file"<<endl;} //output if file is not present
    return output;
 }
 
struct node{
    int diststartnode;
    bool visited;
    node* parent;
    int m_key;
    vector<node*> adjlist;
    vector<int> nodelist;
    node(int n){
        vector<node*> list1;
        adjlist = list1;
        vector<int> list2;
        nodelist = list2;
        m_key = n;
        diststartnode = 999999;
        parent = NULL;
        visited = false;
    }
};

vector<node*> bfs(node* V0){ //V0 is starting node
      V0->diststartnode=0;
      V0->parent= NULL;  
      queue<node*> Q;
      Q.push(V0);
      vector<node*> D;
      while (!Q.empty()){
        node* v = Q.front();
        Q.pop();
        D.push_back(v);
        v->visited=true;  //visited
      for(int x = 0;x<v->adjlist.size();x++){
          if(v->adjlist[x]->visited == false){
            Q.push(v->adjlist[x]);
            v->adjlist[x]->visited = true;
            v->adjlist[x]->diststartnode = v->diststartnode+1;
            v->adjlist[x]->parent =  v;
          }
      }
      }
         return D;
              
              
}

int main(int argc, char** argv) {
    string in;
    int startingnode;
    char* chartr;
    if (argv[1] != NULL){
        in=argv[1]; //argv[1] is the file name
        chartr=argv[2];
        startingnode = *chartr-48;
    
    
    
    vector<node*> nodes;
    
    string readfile = readfromfile(in);//"BFSinput2.txt"
    int numelements =readfile[0]-48;//converts characters to numbers
    readfile =readfile.substr(1);
    //cout<<readfile<<endl;
    int i=0;
    while(i<readfile.size()){
        //cout<<readfile[i]<<endl;
        if(readfile[i+1] == ':'){
            int key = readfile[i]-48;
            node* newnode = new node(key);
            int k=i+1;
            while((readfile[k+1] != ':') and (readfile.size()>k)){
                if(readfile[k] != ':'){
                    //cout<<" "<<readfile[k]-48;
                    newnode->nodelist.push_back(readfile[k]-48);
                }
                k++;
                i++;
            }
            //cout<<endl;
            nodes.push_back(newnode);
            i++;
        }
        //cout<<endl;
    }
    

//    for(unsigned int i=0;i<nodes.size();i++){     //test nodelist for correct build
//         cout<<nodes[i]->m_key<<":";
//        for(int k=0;k<nodes[i]->nodelist.size();k++){
//            cout<<nodes[i]->nodelist[k];
//        }
//         cout<<endl;
//    }
    
    
    
    for(int i=0;i<nodes.size();i++){ //builds adjlist
        for(int k=0;k<nodes[i]->nodelist.size();k++){
            for(int j=0;j<nodes.size();j++){
            if(nodes[i]->nodelist[k] == nodes[j]->m_key){
                nodes[i]->adjlist.push_back(nodes[j]);
            }
            }
        }
    }


//    for(unsigned int i=0;i<nodes.size();i++){                    //test adjlist for correct build
//         cout<<nodes[i]->m_key<<":";
//        for(int k=0;k<nodes[i]->adjlist.size();k++){
//            cout<<nodes[i]->adjlist[k]->m_key;
//        }
//         cout<<endl;
//    }
    

    node* startnodeptr;
   for(int i=0;i<nodes.size();i++){
       if(nodes[i]->m_key==startingnode){
           startnodeptr=nodes[i];
       }
   }
    
    
    vector<node*> outputD = bfs(startnodeptr);  //,nodes
    
    cout<<"D=";
    for(int i=0;i<outputD.size();i++){
        cout<<outputD[i]->m_key<<" ";
    }
    cout<<endl;
    
    
    for(int i=0;i<nodes.size();i++){
        cout<<nodes[i]->m_key<<".p=";
        if(nodes[i]->parent==NULL){
            cout<<"nil,";
        }
        else{
           cout<<nodes[i]->parent->m_key<<",";
        }
    }
    
    cout<<endl;
    for(int i=0;i<nodes.size();i++){
        if (nodes[i]->diststartnode ==999999){
            cout<<nodes[i]->m_key<<".d="<<" nil,";
        }
        else{cout<<nodes[i]->m_key<<".d="<<nodes[i]->diststartnode<<",";}
    }
    cout<<endl;
    
    
    }
    else{ 
        cout<< "no input file is given"<<endl;
    }
    
    return 0;
}

