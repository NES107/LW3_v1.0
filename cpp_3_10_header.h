#ifndef CPP_3_10_HEADER_H_INCLUDED
#define CPP_3_10_HEADER_H_INCLUDED

#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <iterator>
#include <string.h>
#include <numeric>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <chrono>


using namespace std;

struct results
{
    vector <float> hwm;
    string surname;
    string name;
    float examm;
    float average;
    float fpointsa;
    float fpointsm;
};

void mean(struct results *resultss);
void median(struct results *resultss);
bool sortfm(const results &a, const results &b);
void filegenV(string fname,vector <results> &students,struct results resultss);
void filegenD(string fname,deque <results> &students,struct results resultss);
void filegenL(string fname,list <results> &students,struct results resultss);
int firstntpV(vector <results> &students);
int firstntpD(deque <results> &students);
int firstntpL(list <results> &students);
void vsplittingV(vector <results> &students,struct results &resultss,string &fname1,string &fname2,string &fname3,int linenumber, int par);
void vsplittingD(deque <results> &students,struct results &resultss,string &fname1,string &fname2,string &fname3,int linenumber, int par);
void vsplittingL(list <results> &students,struct results &resultss,string &fname1,string &fname2,string &fname3,int linenumber, int par);

#endif // CPP_3_10_HEADER_H_INCLUDED
