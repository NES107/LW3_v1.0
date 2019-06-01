#include "cpp_3_10_header.h"
#include "cpp_3_10_header.cpp"

int main()
{
    vector <results> studentsv;
    deque <results> studentsd;
    list <results> studentsl;
    results resultss;

    ifstream student_list;
    string fname1;

    cout<<"Enter file name(example: name.txt): ";
    cin>>fname1;
    student_list.open(fname1);
    while(student_list.fail())
        {
            try
            {
                throw runtime_error("Error in input!\n");
            }catch(const runtime_error &e)
            {
                cout<<e.what();
                cin.ignore(256,'\n');
                cout<<"Enter one more time:"<<endl<<"-> ";
                cin>>fname1;
                student_list.open(fname1);
            }
        }
    student_list.ignore( 1000, '\n' );
    int linenumber=-1;
    while(!student_list.eof())
    {
        student_list>>resultss.surname;
        student_list>>resultss.name;
        for(int i=0; i<5; i++)
        {
            float mark;
            student_list>>mark;

            while(cin.fail()==true)
            {
                try
                {
                    throw runtime_error("Error in input!\n");
                }catch(const runtime_error &e)
                {
                    cout<<e.what();
                    cin.ignore(256,'\n');
                    cout<<"Enter one more time"<<endl<<"-> ";
                    cin>>mark;
                }
            }
            resultss.hwm.push_back(mark);
        }
        student_list>>resultss.examm;
        mean(&resultss);
        median(&resultss);
        studentsv.push_back (resultss);
        studentsd.push_back (resultss);
        studentsl.push_back (resultss);
        resultss.hwm.resize(0);
        linenumber++;
    }
    student_list.close();
    string fname2 = "students_passed.txt";
    string fname3 = "students_notpassed.txt";
    cout<<endl<<"FIRST STRATEGY: "<<endl;
    cout<<"Vector parameters: "<<endl;
    vsplittingV(studentsv, resultss, fname1, fname2, fname3, linenumber, 1);
    cout<<"Deque parameters: "<<endl;
    vsplittingD(studentsd, resultss, fname1, fname2, fname3, linenumber, 1);
    cout<<"List parameters: "<<endl;
    vsplittingL(studentsl, resultss, fname1, fname2, fname3, linenumber, 1);
    cout<<endl<<"SECOND STRATEGY: "<<endl;
    cout<<"Vector parameters: "<<endl;
    vsplittingV(studentsv, resultss, fname1, fname2, fname3, linenumber, 2);
    cout<<"Deque parameters: "<<endl;
    vsplittingD(studentsd, resultss, fname1, fname2, fname3, linenumber, 2);
    cout<<"List parameters: "<<endl;
    vsplittingL(studentsl, resultss, fname1, fname2, fname3, linenumber, 2);
    return 0;
}
