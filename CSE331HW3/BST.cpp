
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;



struct node{
    int m_num;
    node* LL;
    node* RL;
    node(int n){
        m_num = n;
        LL = NULL; 
        RL = NULL;
    }
    node(){
        LL = NULL;
        RL = NULL;
    }
    node* getLL(node* T){
        return T->LL;
    }
    node* getRL(node* T){
        return T->RL;
    }
    void print(){
        cout<<m_num<<endl;
    }
};
void inorder(node* T){
    if (T==NULL){ return;}
    inorder(T->LL);
    T->print();
    inorder(T->RL);
}
void preorder(node* T){
        if (T==NULL){ return; }
        T->print();
        preorder(T->LL);
        preorder(T->RL);
    }
void postorder(node *T){
    if (T==NULL) { return; }
    postorder(T->RL);
    postorder(T->LL);
    T->print();
}
 node insertnode(int num, node*& T){
    if (T == NULL){
        T = new node(num);
    }
    else{
        if (num < (T->m_num)){
            insertnode(num, T->LL);
        }
        if(num > (T->m_num)){
            insertnode(num, T->RL);
        }
    }
 }

 //function for reading from a text file and returning a vector of integers in the file separated by spaces
 vector<int> readfromfile(string filename){
    string line; int i;
    vector <int> vec;
       
   ifstream myfile(filename.c_str());//file name to read from
    //file parsing
    if (myfile.is_open()){
        while( std::getline(myfile, line,' ') ){//elements are separated by spaces
            i = std::atoi(line.c_str());//convert the elements in the text file to integers
            vec.push_back(i); //push elements into a vector
        }
        myfile.close();
    }
    else{ cout<< "unable to open input file"<<endl;} //output if file is not present
    return vec;
 }
 
 
int main(int argc, char *argv[]) {
    node* rootn = NULL; //creates the root node
    string in;
     
    
//    cout<<"what file to read from"<<endl;
//    cin>>in;
    if (argv[1] != NULL){
        in=argv[1]; //argv[1] is the file name
    }
    else{ 
        cout<< "no input file is given"<<endl;
    }
    
    vector <int> vec = readfromfile(in);//read values from file and pass them back in a vector of integers
    for(int num = 0;num < vec.size();num++){
        insertnode(vec[num],rootn); //fills tree with values 
    }
    
    if (rootn != NULL){  ///only output if at least the root is filled
        cout<<"preorder"<<endl;
        preorder(rootn);

        cout<<"inorder"<<endl;
        inorder(rootn);

        cout<<"postorder"<<endl;
        postorder(rootn);
    }
    
    return 0;
}