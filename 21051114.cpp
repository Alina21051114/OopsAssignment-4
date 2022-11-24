#include <iostream>
#include<fstream>
using namespace std;

class Student{     
	
	protected:
		char name[40];
		int roll;
		int sec;
		
	public:
		
		void getData();
		
		friend ostream &operator <<(ostream &, Student &);
		
		~Student(){
    	cout<<endl<<"Destructor is called"<<endl;
	}		
};

void Student::getData(){
	cout<<"Enter name: ";
	cin>>name;
	cout<<"Enter Roll No & Sec: ";
	cin>>roll>>sec;
	
	try{
		if(roll <0){
			throw roll;
		}
	}
	
	catch(int x){
		cout<<"Exception Handle carried out"<<endl<<"Invalid Roll Number."<<endl<<endl;
	}
}

ostream & operator <<(ostream &os, Student &s){
	os<<"Name of student is "<<s.name<<endl;
	os<<"Roll No is "<<s.roll<<" & Sec "<<s.sec<<endl;
	return os;
}

class Marks: virtual public Student{
	
	protected:
		int mark_sub1;
		int mark_sub2;
		
	public:
		Marks(){
			mark_sub1 = 0;
			mark_sub2 = 0;
		}
		
		Marks(int x, int y){
			mark_sub1 = x;
			mark_sub2 = y;
		}
};

class Sports: virtual public Student{
	protected:
		int s_mark;
		
	public:
		Sports(){
			s_mark = 0;
		}
		
		Sports(int x){
			s_mark = x;
		}
};

class Total: public Marks, public Sports{
	protected:
		int total;
		
	public:
		int mark_total(int x, int y, int z){
			mark_sub1 = x;
			mark_sub2 = y;
			s_mark = z;
			total = s_mark + mark_sub1 + mark_sub2;
			return total;
		}
};

template <class T>
class Template{
 	
 	protected:
 		T scholarship;
 		
 	public:
 		void scholar(T x){
 		    scholarship = x;
 			cout<<"How many times did you get scholarship?"<<endl<<scholarship<<endl;
		 }
 };

int main(){
	int x1, x2, x3;
	Student s;
	s.getData();
	cout<<"Enter marks obtained by student in sub1: ";
	cin>>x1;
	cout<<"Enter marks obtained by student in sub2: ";
	cin>>x2;
	cout<<"Enter marks obtained by student in sports: ";
	cin>>x3;
	Marks(x1, x2);

	Total t;
	cout<<endl<<"Total marks obtained is "<<t.mark_total(x1, x2 , x3)<<endl;
	cout<<endl;
	Template <int> sc;
	sc.scholar(2);
	ifstream fin("d:/student.doc");
	fin>>x1>>x2;
	fin.close();
	cout<<endl<<"File handling carried out"<<endl;
	cout<<endl<<s;
}