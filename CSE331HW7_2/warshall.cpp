#include <cstdlib>
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct node{
    int diststartnode;
    bool state;
    int m_key;
    vector<int> nodelist;
    node(int n){
        m_key = n;
        diststartnode=0;
        state = 0;
    }
};


vector<node*> readfromfile(string filename){
    string line;vector<int> vec;int numtoadd;
    vector<node*> output;
    ifstream myfile(filename.c_str());//file name to read from
    if (myfile.is_open()){
        while(myfile>>line){
             numtoadd = std::atoi(line.c_str());//convert the elements in the text file to integers
             vec.push_back(numtoadd);
        }
        myfile.close();
    }
    else{ cout<< "unable to open input file"<<endl;} //output if file is not present
    
    //builds the nodes without weight values
    int numnodes=vec[0];
    for(int i=1;i<=numnodes;i++){
    node* newnode = new node(i);
    output.push_back(newnode);
    }//builds the nodes without weight values
    
    int nodeindx =0;
    int elemtsinnode =0;
    for(int i=1;i<vec.size();i++){
        if (elemtsinnode < numnodes){
            output[nodeindx]->nodelist.push_back(vec[i]);
            //cout<<elemtsinnode<<vec[i]<<endl;
            elemtsinnode++;
        }
        else{
            elemtsinnode=0;
            nodeindx++;
            output[nodeindx]->nodelist.push_back(vec[i]);
            //cout<<elemtsinnode<<vec[i]<<endl;
            elemtsinnode++;
        }
    }
    
    
    
    return output;
    
 }
void shortest(int i, int j, vector < vector<int> > vec)
{
    int k = vec[i][j];
    if (k > 0 )
    {
        shortest(i, k,vec);
        if(i != k){
        cout<<k+1<<"->";}
        //shortest(k,j,vec);
    }
}

int main(int argc, char** argv) {
    string in;
    if (argv[1] != NULL){
        in=argv[1]; //argv[1] is the file name
    
    
    vector<node*> nodes;
    nodes = readfromfile(in); //"warshallinput1.txt"
    int nodenum = nodes.size();
     int D[nodenum][nodenum];
     int P[nodenum][nodenum];
     for (int i = 0; i < nodenum; i++){
        for (int j = 0; j < nodenum; j++){
            D[i][j]=nodes[i]->nodelist[j];
            if(D[i][j] == 9999 or i==j){
               P[i][j]=9999; 
            }
            else{
            P[i][j]=i+1;}
        }
    }
     
//     for (int i = 0; i < nodenum; i++){
//        for (int j = 0; j < nodenum; j++){
//            cout<<P[i][j]<<"\t";
//        }
//        cout<<endl;
//    }
//     
    
    
    for (int k = 0; k < nodenum; k++){
        for (int i = 0; i < nodenum; i++){
            for (int j = 0; j < nodenum; j++){
                    if ((D[i][k] + D[k][j] < D[i][j]) and (D[i][k] != 9999) and (D[k][j] != 9999)){ 
                        D[i][j] = D[i][k] + D[k][j];
                        P[i][j]= P[k][j];
                    }
            }
        }
    }
    cout<<"D="<<endl;
    for (int i = 0; i < nodenum; i++){
        for (int j = 0; j < nodenum; j++){
            cout<<D[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl<<"P="<<endl;
    for (int i = 0; i < nodenum; i++){
        for (int j = 0; j < nodenum; j++){
            if(P[i][j]== 9999){
                cout<<"-"<<"\t";
            }
            else{
            cout<<P[i][j]<<"\t";}
        }
        cout<<endl;
    }

    vector < vector<int> > vecP;
    for (int i = 0; i < nodenum; i++){
        vector<int> temp;
        for (int j = 0; j < nodenum; j++){
            //cout<<P[i][j]<<"\t";
            if(P[i][j] ==9999){
            temp.push_back(0);}
            else{temp.push_back(P[i][j]-1);}
        }
        vecP.push_back(temp);
        //cout<<endl;
    }
    cout<<endl;
    
//    for (int i = 0; i < nodenum; i++){
//        for (int j = 0; j < nodenum; j++){
//            cout<<vecP[i][j]<<"\t";
//        }
//        cout<<endl;
//        }

    
    cout<<endl<<"path and weight:"<<endl;
   for (int i = 0; i < nodenum; i++){
        for (int j = 0; j < nodenum; j++){
            cout<<"Path from " << i+1 <<" to "<< j+1 << ": ";
            if (D[i][j]  < 9999){
                cout<<i+1<<"->";
                shortest( i, j, vecP );
                cout<<j+1<<"  Weight="<<D[i][j];
            }
           cout<<endl;
       }    
   }  
    
    
   }
    else{ 
        cout<< "no input file is given"<<endl;
    }
     
     
     
     
    return 0;
}

