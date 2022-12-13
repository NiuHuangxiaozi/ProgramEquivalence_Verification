#include<map>
#include <iostream>
#include<vector>
#include<fstream>
#include <ctime>
#include<stdlib.h>
#include <set>

class Val
{
private:
    std::string inputtype;
    int lowint;
    int highint;
public:
    Val(std::string type, int lower, int higher)
    {
        inputtype = type;
        if (inputtype == "int")
        {
            lowint = lower;
            highint = higher;
        }
    }
    std::string Get_type() {
        return inputtype;
    }
    int Get_lowint() {
        return lowint;
    }
    int Get_highint() {
        return highint;
    }

};
class Method
{
	public:
		virtual bool judge(std::string s1,std::string s2){return true;};
        virtual void init(std::string s){};
        virtual void init(std::string s,std::vector<std::string>&files,std::string s1){};
};

class Sample_Test :public Method
{
public:
	bool judge(std::string s1, std::string s2);
    void init(std::string s,std::vector<std::string>&files,std::string s1);
private:
    std::vector<Val> vals;

    void add_vals(std::string s);
    void create_test_data();
    
    char random_char();
    int random_int(int lownum, int highnum);
    std::string random_string(int lowlength, int highlength);


    bool compare_test_result(int one_err_2,int two_err_2);

    void init_exe_file(std::vector<std::string>&files);




    int time_adjust;

    int judge_epoch;
    std::string inputfile;
    std::string outputfile_1;
    std::string outputfile_2;
    std::string exe_files;

    std::vector<std::string> tempfiles;

    std::vector<int>compile_error;

    std::map<std::string,int> filename_to_index;
    
};





class DSU
{
private:
    int* rank;
    int* parent;
    int count;
    std::map<std::string, int>path_to_index;

    int find(int p)
    {
        if (p != parent[p])
            parent[p] = find(parent[p]);
        return parent[p];
    }
public:
    DSU(std::vector<std::string>&files)
    {
        count = files.size();
        rank = new int[count];
        parent = new int[count];
        for (int i = 0; i < count; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        for (int i = 0; i < count; i++)
        {
            path_to_index[files[i]] = i;
        }
    }
    int find(std::string s) 
    {
        int p = path_to_index[s];
        if( p != parent[p] )
           parent[p] = find( parent[p] );
        return parent[p];
    }
   bool isConnected(std::string s1, std::string s2) 
   {
        int p = path_to_index[s1];
        int q = path_to_index[s2];
        return find(p) == find(q);
   }
    void unionElements(std::string s1, std::string s2) 
   {

       int p = path_to_index[s1];
       int q = path_to_index[s2];
       int pRoot = find(p);
       int qRoot = find(q);

       if (pRoot == qRoot)
           return;

       if (rank[pRoot] < rank[qRoot]) {
           parent[pRoot] = qRoot;
       }
       else if (rank[qRoot] < rank[pRoot]) {
           parent[qRoot] = pRoot;
       }
       else { // rank[pRoot] == rank[qRoot]
           parent[pRoot] = qRoot;
           rank[qRoot] += 1;   
       }
   }
};
